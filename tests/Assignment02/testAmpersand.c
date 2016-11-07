int main(){

  	//testvariables:
  	int a;
	int b;
	int* c;
  	int* d;
   	c = malloc(4);
   	d = malloc(4);

	//tests:
  	a = 555555;
  	b = 333333;
  	a = &b; //-> a = 3

 	*c = 222222;
  	*d = 77777;
  	c = *&d; //-> *c = 7;
 
	// tests worked -> checked in debug
}


