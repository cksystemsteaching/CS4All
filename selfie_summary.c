/***** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

Soll eine Uebersicht darstellen, welche Methoden zu welchem Teil von Selfie gehoeren. 
E.g. methode "findNextCharacter()" gehoert zum Scanner oder "int runUntilExitWithoutExceptionHandling(int toID)"
gehoert zum Kernel, etc.

Im selfie code kommen die untenstehenden Methoden mindestens 2 mal vor: bei der declaration und der 
Implementierung. Mehr als die ersten 1000 Zeilen sind ausschließlich declarations.

***** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ---------------------     L I B R A R Y     ---------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ----------------------- BUILTIN PROCEDURES ----------------------
// -----------------------------------------------------------------
void exit(int code);
int read(int fd, int* buffer, int bytesToRead);
int write(int fd, int* buffer, int bytesToWrite);
int open(int* filename, int flags, int mode);
int* malloc(int size);

// -----------------------------------------------------------------
// ----------------------- LIBRARY PROCEDURES ----------------------
// -----------------------------------------------------------------
void initLibrary();
void resetLibrary();
int twoToThePowerOf(int p);
int leftShift(int n, int b);
int rightShift(int n, int b);
int  loadCharacter(int* s, int i);
int* storeCharacter(int* s, int i, int c);
int  stringLength(int* s);
void stringReverse(int* s);
int  stringCompare(int* s, int* t);
int  atoi(int* s);
int* itoa(int n, int* s, int b, int a, int p);
int fixedPointRatio(int a, int b);
void putCharacter(int c);
void print(int* s);
void println();
void printCharacter(int c);
void printString(int* s);
void printInteger(int n);
void printFixedPointPercentage(int a, int b);
void printFixedPointRatio(int a, int b);
void printHexadecimal(int n, int a);
void printOctal(int n, int a);
void printBinary(int n, int a);
int roundUp(int n, int m);
int* zalloc(int size);

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ---------------------    C O M P I L E R    ---------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ---------------------------- SCANNER ----------------------------
// -----------------------------------------------------------------
void initScanner();
void resetScanner();
void printSymbol(int symbol);
void printLineNumber(int* message, int line);
void syntaxErrorMessage(int* message);
void syntaxErrorCharacter(int character);
void getCharacter();
int isCharacterNewLine();
int isCharacterWhitespace();
int findNextCharacter();
int isCharacterLetter();
int isCharacterDigit();
int isCharacterLetterOrDigitOrUnderscore();
int isCharacterNotDoubleQuoteOrNewLineOrEOF();
int identifierStringMatch(int stringIndex);
int identifierOrKeyword();
void getSymbol();

// -----------------------------------------------------------------
// ------------------------- SYMBOL TABLE --------------------------
// -----------------------------------------------------------------
void resetSymbolTables();
void createSymbolTableEntry(int which, int* string, int line, int class, int type, int value, int address);
int* searchSymbolTable(int* entry, int* string, int class);
int* getScopedSymbolTableEntry(int* string, int class);
int isUndefinedProcedure(int* entry);
int reportUndefinedProcedures();

// symbol table entry:
// +----+---------+
// |  0 | next    | pointer to next entry
// |  1 | string  | identifier string, string literal
// |  2 | line#   | source line number
// |  3 | class   | VARIABLE, PROCEDURE, STRING
// |  4 | type    | INT_T, INTSTAR_T, VOID_T
// |  5 | value   | VARIABLE: initial value
// |  6 | address | VARIABLE: offset, PROCEDURE: address, STRING: offset
// |  7 | scope   | REG_GP, REG_FP
// +----+---------+

int* getNextEntry(int* entry)  { return (int*) *entry; }
int* getString(int* entry)     { return (int*) *(entry + 1); }
int  getLineNumber(int* entry) { return        *(entry + 2); }
int  getClass(int* entry)      { return        *(entry + 3); }
int  getType(int* entry)       { return        *(entry + 4); }
int  getValue(int* entry)      { return        *(entry + 5); }
int  getAddress(int* entry)    { return        *(entry + 6); }
int  getScope(int* entry)      { return        *(entry + 7); }
void setNextEntry(int* entry, int* next)    { *entry       = (int) next; }
void setString(int* entry, int* identifier) { *(entry + 1) = (int) identifier; }
void setLineNumber(int* entry, int line)    { *(entry + 2) = line; }
void setClass(int* entry, int class)        { *(entry + 3) = class; }
void setType(int* entry, int type)          { *(entry + 4) = type; }
void setValue(int* entry, int value)        { *(entry + 5) = value; }
void setAddress(int* entry, int address)    { *(entry + 6) = address; }
void setScope(int* entry, int scope)        { *(entry + 7) = scope; }

// -----------------------------------------------------------------
// ---------------------------- PARSER -----------------------------
// -----------------------------------------------------------------

void resetParser();
int isNotRbraceOrEOF();
int isExpression();
int isLiteral();
int isStarOrDivOrModulo();
int isPlusOrMinus();
int isComparison();
int lookForFactor();
int lookForStatement();
int lookForType();
void save_temporaries();
void restore_temporaries(int numberOfTemporaries);
void syntaxErrorSymbol(int expected);
void syntaxErrorUnexpected();
void printType(int type);
void typeWarning(int expected, int found);
int* getVariable(int* variable);
int  load_variable(int* variable);
void load_integer(int value);
void load_string(int* string);
int  help_call_codegen(int* entry, int* procedure);
void help_procedure_prologue(int localVariables);
void help_procedure_epilogue(int parameters);
int  gr_call(int* procedure);
int  gr_factor();
int  gr_term();
int  gr_simpleExpression();
int  gr_expression();
void gr_while();
void gr_if();
void gr_return();
void gr_statement();
int  gr_type();
void gr_variable(int offset);
int  gr_initialization(int type);
void gr_procedure(int* procedure, int type);
void gr_cstar();

// -----------------------------------------------------------------
// ---------------------- MACHINE CODE LIBRARY ---------------------
// -----------------------------------------------------------------
void emitLeftShiftBy(int b);
void emitMainEntry();
void bootstrapCode();

// -----------------------------------------------------------------
// --------------------------- COMPILER ----------------------------
// -----------------------------------------------------------------
void selfie_compile();

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -------------------     I N T E R F A C E     -------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ---------------------------- REGISTER ---------------------------
// -----------------------------------------------------------------
void initRegister();
void printRegister(int reg);

// -----------------------------------------------------------------
// ---------------------------- ENCODER ----------------------------
// -----------------------------------------------------------------
int encodeRFormat(int opcode, int rs, int rt, int rd, int function);
int encodeIFormat(int opcode, int rs, int rt, int immediate);
int encodeJFormat(int opcode, int instr_index);
int getOpcode(int instruction);
int getRS(int instruction);
int getRT(int instruction);
int getRD(int instruction);
int getFunction(int instruction);
int getImmediate(int instruction);
int getInstrIndex(int instruction);
int signExtend(int immediate);

// -----------------------------------------------------------------
// ---------------------------- DECODER ----------------------------
// -----------------------------------------------------------------
void initDecoder();
void printOpcode(int opcode);
void printFunction(int function);
void decode();
void decodeRFormat();
void decodeIFormat();
void decodeJFormat();

// -----------------------------------------------------------------
// ----------------------------- CODE ------------------------------
// -----------------------------------------------------------------
int  loadBinary(int baddr);
void storeBinary(int baddr, int instruction);
void emitInstruction(int instruction);
void emitRFormat(int opcode, int rs, int rt, int rd, int function);
void emitIFormat(int opcode, int rs, int rt, int immediate);
void emitJFormat(int opcode, int instr_index);
void fixup_relative(int fromAddress);
void fixup_absolute(int fromAddress, int toAddress);
void fixlink_absolute(int fromAddress, int toAddress);
int copyStringToBinary(int* s, int a);
void emitGlobalsStrings();
int openWriteOnly(int* name);
void selfie_output();
int* touch(int* memory, int length);
void selfie_load();

// -----------------------------------------------------------------
// ----------------------- MIPSTER SYSCALLS ------------------------
// -----------------------------------------------------------------
void emitExit();
void implementExit();
void emitRead();
void implementRead();
void emitWrite();
void implementWrite();
void emitOpen();
int  down_loadString(int* table, int vaddr, int* s);
void implementOpen();
void emitMalloc();
void implementMalloc();

// -----------------------------------------------------------------
// ----------------------- HYPSTER SYSCALLS ------------------------
// -----------------------------------------------------------------
void emitID();
void implementID();
int selfie_ID();
void emitCreate();
int  doCreate(int parentID);
void implementCreate();
int selfie_create();
void emitSwitch();
int  doSwitch(int toID);
void implementSwitch();
int  mipster_switch(int toID);
int selfie_switch(int toID);
void emitStatus();
void implementStatus();
int selfie_status();
void emitDelete();
void doDelete(int ID);
void implementDelete();
void selfie_delete(int ID);
void emitMap();
void doMap(int ID, int page, int frame);
void implementMap();
void selfie_map(int ID, int page, int frame);

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ---------------------    E M U L A T O R    ---------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ---------------------------- MEMORY -----------------------------
// -----------------------------------------------------------------
void initMemory(int megabytes);
int  loadPhysicalMemory(int* paddr);
void storePhysicalMemory(int* paddr, int data);
int getFrameForPage(int* table, int page);
int isPageMapped(int* table, int page);
int isValidVirtualAddress(int vaddr);
int getPageOfVirtualAddress(int vaddr);
int isVirtualAddressMapped(int* table, int vaddr);
int* tlb(int* table, int vaddr);
int  loadVirtualMemory(int* table, int vaddr);
void storeVirtualMemory(int* table, int vaddr, int data);
void mapAndStoreVirtualMemory(int* table, int vaddr, int data);

// -----------------------------------------------------------------
// ------------------------- INSTRUCTIONS --------------------------
// -----------------------------------------------------------------
void fct_syscall();
void fct_nop();
void op_jal();
void op_j();
void op_beq();
void op_bne();
void op_addiu();
void fct_jr();
void fct_mfhi();
void fct_mflo();
void fct_multu();
void fct_divu();
void fct_addu();
void fct_subu();
void op_lw();
void fct_slt();
void op_sw();

// -----------------------------------------------------------------
// -------------------------- INTERPRETER --------------------------
// -----------------------------------------------------------------
void initInterpreter();
void resetInterpreter();
void printException(int exception);
int encodeException(int exception, int parameter);
int decodeExceptionNumber(int status);
int decodeExceptionParameter(int status);
void printStatus(int status);
void throwException(int exception, int parameter);
void fetch();
void execute();
void interrupt();
void runUntilException();
int addressWithMaxCounter(int* counters, int max);
int  printCounters(int total, int* counters, int max);
void printProfile(int* message, int total, int* counters);
void selfie_disassemble();

// -----------------------------------------------------------------
// ---------------------------- CONTEXTS ---------------------------
// -----------------------------------------------------------------
int createID(int seed);
int* allocateContext(int ID, int parentID);
int* createContext(int ID, int parentID, int* in);
int* findContext(int ID, int* in);
void switchContext(int* from, int* to);
void freeContext(int* context);
int* deleteContext(int* context, int* from);
void mapPage(int* table, int page, int frame);

// context struct:
// +---+--------+
// | 0 | next   | pointer to next context
// | 1 | prev   | pointer to previous context
// | 2 | id     | unique identifier
// | 3 | pc     | program counter
// | 4 | regs   | pointer to general purpose registers
// | 5 | reg_hi | hi register
// | 6 | reg_lo | lo register
// | 7 | pt     | pointer to page table
// | 8 | brk    | break between code, data, and heap
// | 9 | parent | ID of context that created this context
// +---+--------+

int* getNextContext(int* context) { return (int*) *context; }
int* getPrevContext(int* context) { return (int*) *(context + 1); }
int  getID(int* context)          { return        *(context + 2); }
int  getPC(int* context)          { return        *(context + 3); }
int* getRegs(int* context)        { return (int*) *(context + 4); }
int  getRegHi(int* context)       { return        *(context + 5); }
int  getRegLo(int* context)       { return        *(context + 6); }
int* getPT(int* context)          { return (int*) *(context + 7); }
int  getBreak(int* context)       { return        *(context + 8); }
int  getParent(int* context)      { return        *(context + 9); }
void setNextContext(int* context, int* next) { *context       = (int) next; }
void setPrevContext(int* context, int* prev) { *(context + 1) = (int) prev; }
void setID(int* context, int id)             { *(context + 2) = id; }
void setPC(int* context, int pc)             { *(context + 3) = pc; }
void setRegs(int* context, int* regs)        { *(context + 4) = (int) regs; }
void setRegHi(int* context, int reg_hi)      { *(context + 5) = reg_hi; }
void setRegLo(int* context, int reg_lo)      { *(context + 6) = reg_lo; }
void setPT(int* context, int* pt)            { *(context + 7) = (int) pt; }
void setBreak(int* context, int brk)         { *(context + 8) = brk; }
void setParent(int* context, int id)         { *(context + 9) = id; }

// -----------------------------------------------------------------
// -------------------------- MICROKERNEL --------------------------
// -----------------------------------------------------------------
void resetMicrokernel();

// -----------------------------------------------------------------
// ---------------------------- KERNEL -----------------------------
// -----------------------------------------------------------------
int pavailable();
int pused();
int* palloc();
void pfree(int* frame);
void up_loadBinary(int* table);
int  up_loadString(int* table, int* s, int SP);
void up_loadArguments(int* table, int argc, int* argv);
void mapUnmappedPages(int* table);
void down_mapPageTable(int* context);
int runUntilExitWithoutExceptionHandling(int toID);
int runOrHostUntilExitWithPageFaultHandling(int toID);
int bootminmob(int argc, int* argv, int machine);
int boot(int argc, int* argv);
int selfie_run(int engine, int machine, int debugger);

// -----------------------------------------------------------------
// ----------------------------- MAIN ------------------------------
// -----------------------------------------------------------------
void initSelfie(int argc, int* argv);
int numberOfRemainingArguments();
int* remainingArguments();
int* peekArgument();
int* getArgument();
void setArgument(int* argv);