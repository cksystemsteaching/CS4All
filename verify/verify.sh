#!/bin/bash

# BNEU: currently this is basically a copy i took from last semester course: compiler
#       i intend to fully rewrite this in a proper programming language

# The goal of this script is to verify that changes did not break a selfie feature
# todo: maybe we should pull kirschs latest bugfix (will get rid of the gcc warnng "n set but not used")
#       bernhard: not sure about the implications, because this bugfix is not part of our forks origin

# grep regex syntax used:
# \s whitespace \S non-whitespace
# ng\K[ok]* will not include ng in output
# (?=ng)ok(?=ng) will only include ok in output

TEAM_MSG="This is TheExtendables Selfie"

# print commands
DEBUG_CMD="DISABLED"
# disabled per default to avoid speed impact
GCC_CHECK="DISABLED"

if [[ -n $1 ]]; then C_SELFIE_REPO=${1%*/}; else C_SELFIE_REPO=".."; fi
C_SELFIE=${C_SELFIE_REPO}/selfie.c

function cleanup {
	rm v_* 2> /dev/null
	rm **/v_* 2> /dev/null
}

function red {
  echo -e ${2} "\e[31m$1\e[0m"
}
function green {
  echo -e ${2} "\e[32m$1\e[0m"
}
green "test" -n
function blue {
  echo -e ${2} "\e[1;34m$1\e[0m"
}
function gray {
  echo -e ${2} "\e[1;90m$1\e[0m"
}

# arguments: $1 = key
# effects: ${value}
function parseConfigFlag {
	if [ -f ${C_SELFIE_REPO}/verify.config ]; then
		value=$(cat ${C_SELFIE_REPO}/verify.config | grep -Po "^$1:\s*\K[\S]*")
	else
		unset value
	fi
}

# arguments: ${file} ${dir}
# effects: ${enabled}
function parseEnabled {
	enabled="ENABLED"
	if [ -f ${C_SELFIE_REPO}/verify.config ]; then
		# match dir/file: xxx
		parseConfigFlag ${file%*/}
		if [ "${value^^}" == "EXIT" ]; then red "verify.config: exit"; exit;
		elif [[ -n ${value} ]]; then enabled="${value^^}"; return; fi

		# match dir: xxx
		parseConfigFlag ${dir%*/}
		if [ "${value^^}" == "EXIT" ]; then red "verify.config: exit"; exit;
		elif [[ -n ${value} ]]; then enabled="${value^^}"; return; fi
		
		# match ALL: xxx
		parseConfigFlag "ALL"
		if [ "${value^^}" == "EXIT" ]; then red "verify.config: exit"; exit;
		elif [[ -n ${value} ]]; then enabled="${value^^}"; return; fi
	fi

	local value=$(cat ${file} | grep -Po "enabled:\s*\K[\S]*")
	if [ "${value^^}" == "TRUE" ]; then enabled="ENABLED"; else enabled="DISABLED"; fi
}

function parseGccCheck {
	parseConfigFlag "GCC_CHECK"
	if [[ -n ${value} ]]; then GCC_CHECK="${value^^}"; return; fi
}

function parseDebugCmd {
	parseConfigFlag "DEBUG_CMD"
	if [[ -n ${value} ]]; then DEBUG_CMD="${value^^}"; return; fi
}

# arguments: ${file}
# effects: ${expected}
function parseExpected {
	expected=$(cat ${file} | grep -Po "expected:\s*\K[\S]*")
	if [[ -z ${expected} ]]; then expected=0; fi
}

# arguments: ${file}
# effects: ${assemblyOk}
function parseAssemblyOk {
	assemblyOk=$(cat ${file} | grep -Po "assemblyOk:\s*\K[\S]*")
}

# arguments: ${file}
# effects: ${assemblyNg}
function parseAssemblyNg {
	assemblyNg=$(cat ${file} | grep -Po "assemblyNg:\s*\K[\S]*")
}

# arguments: ${file}
# effects: ${msg}
function parseMsg {
	msg=$(cat ${file} | grep -Po "^\s*\K.*(?=\s*//\s*msg)" | sed ':a;N;$!ba;s/\n//g' )
}

# arguments: ${file}
# effects: ${disabledMsg}
function parseDisabledMsg {
	disabledMsg=$(cat ${file} | grep -Po "enabled:\s*\S*\s*\K\S*")	
}

# arguments $1 = logfilename
# effects: prints warnings/errors
function printLogErrorWarnings {
	# some tests supress warnings - fast exit
	local value=$(cat ${file} | grep -Po "suppressWarning:\s*\K[\S]*")
	if [ "${value^^}" == "TRUE" ]; then local pattern="error"; else	local pattern="warning\|error";	fi

	if grep -q ${pattern} $1; then
		echo ""
		red "    $1:" -n
		gray " (only first 5 errors)"
		grep --color=always ${pattern} $1 | tail -5 | sed -e 's/^/   /'
	fi
}

# arguments: ${file}, ${outname}
# effects: ${gccOk}, ${outname}, ${outname}.gcc.log
gccOk=1
function gccFile {
	local cmd="gcc -Wall -m32 -D'main(a, b)=main(int argc, char **argv)' ${file} -o ${outname} 2>${outname}.gcc.log"
	if [[ ${DEBUG_CMD} == "ENABLED" ]]; then gray "$cmd"; fi
	eval ${cmd}
	if [ $? == 0 ]; then gccOk=1; else gccOk=0; fi;
	if grep -q "error" ${outname}.gcc.log; then
		gccOk=0
	fi
}

# arguments: ${outname}
# effects: ${runExitcode}, ${outname}.run.log
function gccFileRun {
	local cmd="${outname} > ${outname}.gcc.run.log"
	if [[ ${DEBUG_CMD} == "ENABLED" ]]; then gray "$cmd"; fi
	eval ${cmd}
	runExitcode=$?
}

# arguments: ${file}, ${outname}
# effects: ${outname}.s and ${outname}.s.log created
function selfieAssembly {
	local cmd="./v_selfie -c ${file} -s ${outname}.s > ${outname}.s.log"
	if [[ ${DEBUG_CMD} == "ENABLED" ]]; then gray "    $cmd"; fi
	eval ${cmd}
}

# arguments: ${file}, ${outname}
# effects: ${outname}.m and ${outname}.m.log created
function selfieMipster {
	local cmd="./v_selfie -c ${file} -o ${outname}.m > ${outname}.m.log"
	if [[ ${DEBUG_CMD} == "ENABLED" ]]; then gray "    $cmd"; fi
	eval ${cmd}
	printLogErrorWarnings "${outname}.m.log"
}

# arguments: ${outname}
# effects: ${runExitcode}, ${outname}.run.log
function selfieRun {
	local cmd="./v_selfie -l ${outname}.m -m 1 > ${outname}.m.run.log"
	if [[ ${DEBUG_CMD} == "ENABLED" ]]; then gray "    $cmd"; fi
	eval ${cmd}
	runExitcode=$(cat ${outname}.m.run.log | grep -Po "(?<=exiting with exit code )([-]*[[:digit:]]*)")
}

# arguments: ${outname}, $1 = variablename
# effects: ${assemblyContained}
function assemblyContains {
	assemblyContained=0
	if grep -Pq "[,=]${!1}$" ${outname}.s; then assemblyContained=1; fi
}

# arguments: ${testBaseDir}
function runTests {
	for dir in ${testBaseDir%*/}/*/
	do
	    dir=${dir#./}
		blue "- ${dir%*/}"
		for file in ${dir%*/}/*.c
		do
			file=${file#./}
			[ -f "$file" ] || continue
			filename=$(basename $file)
			outname="${dir%*/}/v_${filename%.*}"
			parseEnabled; parseExpected; parseAssemblyOk; parseAssemblyNg; parseMsg;

			if [ ${enabled} == "DISABLED" ]; then
				parseDisabledMsg
				gray "  - ${filename} [${msg}] := ${expected} disabled[${disabledMsg}]"
			elif [ ${enabled} == "ENABLED" ]; then
				blue "  - ${filename} " -n
				if [ ${GCC_CHECK} == "ENABLED" ] || [ ${GCC_CHECK} == "ONLY" ]; then
					gccFile; gccFileRun; # would test work with gcc? (only check on enabled tests)
					if [ ${gccOk} == 1 ] && [ ${expected} == ${runExitcode} ]; then
						gray "[gcc]" -n;
					else
						red "[" -n; if [ ${gccOk} != 1 ]; then red "!" -n; fi
						red "gcc" -n; if [ ${expected} != ${runExitcode} ]; then red "=[${runExitcode}]" -n; fi
						red "]" -n;
					fi
				fi
				echo -n "[${msg}] := ${expected}"
				errors=0

				if [ ${GCC_CHECK} != "ONLY" ]; then
					# assembly first to help debug
					selfieAssembly
					if [ ! -f ${outname}.s ]; then
						red "    - MIPSter assemmbly missing: ${outname}.s"
						gray "      cat ${outname}.s.log"
						errors=1
					else
						if [ -n "${assemblyOk}" ]; then
							assemblyContains assemblyOk
							if [ ${assemblyContained} != 1 ]; then
								if [ ${errors} == 0 ]; then echo ""; fi
								red "    -s (MIPSter assembly): [${assemblyOk}] is missing"
								errors=1
							fi
						fi
						
						if [ -n "${assemblyNg}" ]; then
							assemblyContains assemblyNg
							if [ ${assemblyContained} != 0 ]; then
								if [ ${errors} == 0 ]; then echo ""; fi
								red "    -s (MIPSter assembly): [${assemblyNg}] is present"
								errors=1
							fi
						fi
					fi

					selfieMipster
					if [ ! -f ${outname}.m ]; then
						if [ ${errors} == 0 ]; then echo ""; fi
						red "    - MIPSter code missing: ${outname}.m"
						gray "      cat ${outname}.m.log"
						errors=1
					else
						selfieRun
						if [ ${expected} != ${runExitcode} ]; then
							if [ ${errors} == 0 ]; then echo ""; fi
							red "    -m (run MIPSter): exit code [${runExitcode}] should be [${expected}]"
							errors=1
						fi
					fi
				fi
				
				if [ ${errors} == 0 ]; then
					green " OK"
				else
					red "    NG"
				fi
			fi
		done
	done
}

# START

parseGccCheck
parseDebugCmd

green "pre cleanup"
cleanup

green "gcc: compile selfie"
file=${C_SELFIE}
outname="v_selfie"
gccFile

# line is not stable, so we sanitize it
cat v_selfie.gcc.log | sed -e 's/^.*selfie[.]c/selfie.c/' \
	| sed -e 's/selfie[.]c:\([0-9]\+\):/selfie.c:XLINEX:/' > v_selfie.sanitized.log

diff -Naur expected_warnings.txt v_selfie.sanitized.log > /dev/null
if [[ $? != 0 ]]; then
	red "gcc warnings differed from expectation"
	# diff -Naur expected_warnings.txt v_selfie.sanitized.log
else
	green "OK: warnings matched"
fi


if [ ${C_SELFIE_REPO} != ".." ]; then
	testBaseDir=${C_SELFIE_REPO}/$(basename $(pwd))
	green "run user tests in [${testBaseDir}]"
	runTests
fi
	
testBaseDir=.
green "run tests in [${testBaseDir}]"
runTests

file=${C_SELFIE}
outname="v_selfie"

# green "selfie: to assembly"
# selfieAssembly

green "selfie: compile selfie to MIPSter (${outname}.m can be executed by mipster and hypster)"
selfieMipster
if [ ! -f ${outname}.m ]; then
	red "MIPSter code missing: ${outname}.m"
	red "--- tail ${outname}.m.log:"
	tail ${outname}.m.log
	red "---"
fi

green "mipster: execute v_selfie.m"

./v_selfie -l v_selfie.m -m 1 > v_exec_mipster.txt
# use sed to filters 0 bytes, because selfies output is 4 bytes per ascii char

if ! cat v_exec_mipster.txt | sed 's/[\d0]//g' | grep -Pzq "exiting with exit code 0"; then
	red "exit code != 0"
	red "--- tail v_exec_mipster.txt:"
	tail v_exec_mipster.txt
	red "---"
fi

# FIXME
#green "Assignment 0: check for '${TEAM_MSG}' in selfies output"
#
#if ! cat v_exec_mipster.txt | sed 's/[\d0]//g' | grep -Pzq '%{TEAM_MSG}\nv_selfie.m: usage'; then
#	red "Assignment 0: expected line missing"
#fi

green "hypster: execute v_selfie.m"
./v_selfie -l v_selfie.m -y 1 > v_exec_hypster.txt
if ! grep -Pq "exiting with exit code 0" v_exec_hypster.txt; then
	red "exit code != 0"
	red "--- tail v_exec_hypster.txt:"
	tail v_exec_hypster.txt
	red "---"
fi

## takes several minutes: introduce verify_full? (build server?)
## green "selfie: compile selfie"
## ./v_selfie -c selfie.c -o v_selfie1.m -m 2 -c selfie.c -o v_selfie2.m
## diff -s v_selfie1.m v_selfie2.m

green "post cleanup"
cleanup

green "end"
