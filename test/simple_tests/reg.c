char sfi$id[0x200000] __attribute__ ((aligned (0x1000000)));

static inline int sandbox(int ptr, int sz) {
  return (ptr & (0x1000000 - sz)) + (int)sfi$id;
}

void cpy(int* from, int* to, unsigned int len) {
    int *toi;
    for(int i=0; i<len; i++) {
        toi = sandbox((int)to + i*sizeof(int), 4);
        *toi = from[i];
    }
}

int main(unsigned int i) {
    int c[10];
    int *a = sfi$id + 440;
    int *b = sfi$id + 480;

    a[0] = 0;
    a[1] = 50;
    a[2] = 5;
    a[3] = 70;
    a[4] = -50000;
    a[5] = 70;

    cpy(a, b, 6);

    asm("sub $5000000, %esp\n\t"
        "push $1");

    return c[0]+b[1];
}
