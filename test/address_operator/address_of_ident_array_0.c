
int  main(){
  int *arr1;
  int *arr2;
  int max;
  int i;
  int value;

  max = 4;
  i = 0;
  value = 1;
  arr1 = malloc(max * 4);

  while(i < max){
    *(arr1 + i) = value;
    value = value + 1;
    i = i + 1;
  }

  i = 0;

  while(i < max){
    arr2 =  &*(arr1 + i);
    i = i + 1;
  }

  return *arr2 + 4; //4

}
