
//int test(int* func);
int doIt(int number);
int doSthElse(int number);

int* x;

int main(){
  int* bla;
  int a;
  bla = &doIt;
  a = 20000;
  x = &doSthElse;
  a = $bla(9999);

  $bla(55);
  //test($bla);


}

//int test(int* func){
//  $func(9999);
//}

int doSthElse(int number){
  return number - 1;
}


int doIt(int number){
  int a;
  a = 5000;
  a = number;
  a = $x(number + 1);
  return a + 2;

}
