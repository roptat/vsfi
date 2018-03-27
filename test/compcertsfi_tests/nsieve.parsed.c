extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

extern void * malloc(size_t __size);

extern void free(void * __ptr);

extern void * memset(void * __s, int __c, size_t __n);

typedef unsigned char boolean;

static unsigned int nsieve_664(int m)
{
  unsigned int count;
  unsigned int i;
  unsigned int j;
  boolean * flags;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:14");
  count = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:15");
  flags = (boolean *) malloc(m * sizeof(boolean));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:16");
  memset(flags, 1, m);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:18");
  for (__builtin_debug(6, "", 1), i = 2;
       i < m;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nsieve.c:19");
    if (flags[i]) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:nsieve.c:20");
      ++count;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:nsieve.c:21");
      for (__builtin_debug(6, "", 1), j = i << 1;
           j < m;
           __builtin_debug(6, "", 1), j += i) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:nsieve.c:22");
        if (flags[j]) {
          __builtin_debug(6, "", 1);
          flags[j] = 0;
        }
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:25");
  free(flags);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:26");
  return count;
}

int main(int argc, char * * argv)
{
  int m;
  int i;
  int j;
  int n;
  unsigned int count;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:32");
  m = argc < 2 ? 9 : atoi(argv[1]);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:33");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:34");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 3;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nsieve.c:35");
    n = 10000 << m - i;
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nsieve.c:36");
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nsieve.c:37");
    for (__builtin_debug(6, "", 1, 2), j = 0;
         j < 1;
         __builtin_debug(6, "", 1, 2), j++) {
      __builtin_debug(6, "", 1, 2);
      count = nsieve_664(n);
    }
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nsieve.c:38");
    printf("Primes up to %8d %8u\n", n, count);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nsieve.c:40");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


