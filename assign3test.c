//used for simple integer output in range [0 - 99];
void dumbITOA(int number);

void dumbITOA(int number) {
    int i;
    int *buff;
    int tmp;
    int ptr;
    int div;
    ptr = 0;
    div = 100;
    tmp = number;
    buff = malloc(50);

    while (div != 0) {
        *(buff + ptr) = (tmp / div) + 48;
        tmp = tmp % div;
        div = div / 10;
        ptr = ptr + 1;
    }
    *(buff + ptr) = ' ';
    write(1, buff, 20);
}

int main(int argc, int *argv) {
    int *buff;
    int id;
    int size;
    int *start;
    int *ptr;
    int i;


    buff = malloc(200);
    *buff = 20;

    id = shm_open("/smem");

    size = shm_size(id, 4096);

    start = (int*) shm_map((int*) 0, id);

    *start = 0;

    *ptr = malloc(20);
    *ptr = 42;
    i = 0;
    while (i < hypster_ID() * 500000) {
        i = i + 1;
    }

    *start = *start + 1;
    *ptr = *ptr + 1;
    write(1,"start",5);
    dumbITOA(*start);
    write(1,"heap",4);
    dumbITOA(*ptr);

    //id = shm_open("/smem");

    //size = shm_size(409);

    //start = (int*) shm_map((int*) 0, id);

}