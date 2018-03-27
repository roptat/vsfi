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

int f(int *e) {
  int d[2];
  for(int i = 0; i <= 4; i++) {
    d[i] = sandbox((int)e + i*sizeof(int), 4);
  }
  return d[1];
}

int main(unsigned int i) {
    int *a = (int *)sfi$id + 150;
    int *b = (int *)sfi$id + 50;
    a[0] = 50;
    a[1] = 10;
    a[2] = 53;
    a[3] = 12;
    cpy(a, b, 4);
    return f(a);
}
