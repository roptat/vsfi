extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

extern void * malloc(size_t __size);

extern void exit(int __status);

extern void * memset(void * __s, int __c, size_t __n);

typedef unsigned int bits;

static unsigned int nsieve_664(unsigned int m)
{
  unsigned int count;
  unsigned int i;
  unsigned int j;
  bits * a;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:19");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:20");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:21");
  a = malloc(m / (8 * sizeof(bits)) * sizeof(bits));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:22");
  memset(a, (1 << 8) - 1, m / (8 * sizeof(bits)) * sizeof(bits));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:23");
  count = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:24");
  for (__builtin_debug(6, "", 1), i = 2;
       i < m;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nsievebits.c:25");
    if (a[i / (8 * sizeof(bits))] & 1 << i % (8 * sizeof(bits))) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:nsievebits.c:26");
      for (__builtin_debug(6, "", 1), j = i + i;
           j < m;
           __builtin_debug(6, "", 1), j += i) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:nsievebits.c:27");
        a[j / (8 * sizeof(bits))] &= ~(1 << j % (8 * sizeof(bits)));
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:nsievebits.c:28");
      ++count;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:30");
  return count;
}

static void test_671(unsigned int n)
{
  unsigned int count;
  unsigned int m;
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:38");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:39");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:41");
  m = (1 << n) * 10000;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:42");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 10;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    count = nsieve_664(m);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:43");
  printf("Primes up to %8u %8u\n", m, count);
}

int main(int ac, char * * av)
{
  unsigned int n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:49");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:51");
  n = ac < 2 ? 9 : atoi(av[1]);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:52");
  test_671(n);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:53");
  if (n >= 1) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nsievebits.c:54");
    test_671(n - 1);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:55");
  if (n >= 2) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nsievebits.c:56");
    test_671(n - 2);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsievebits.c:57");
  exit(0);
  __builtin_debug(6, "");
  return 0;
}


