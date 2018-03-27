char sfi$id[0x200000] __attribute__ ((aligned (0x1000000)));

static inline int sandbox(int ptr, int sz) {
  return (ptr & (0x1000000 - sz)) + (int)sfi$id;
}

int f(int *e) {
  int i;
  asm("push $main\n\t"
      "mov %1, %%ebp\n\t" 
      "add %%ebp, (%%esp)\n\t" 
      "ret"
      : "=r"(i)
      : "r"(*((int *)(sandbox(e, 4))))
      : "%ebp");
  return i+5;
}

int main(unsigned int i) {
    int *a = sfi$id + 440;
    a[0] = 20;
    return f(a);
}
