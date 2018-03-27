extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern int atoi(char const * __nptr);

extern int printf(char const * __format, ...);

int fib(int n)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:fib.c:6");
  if (n < 2) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:fib.c:7");
    return 1;
  } else {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:fib.c:9");
    return fib(n - 1) + fib(n - 2);
  }
}

int main(int argc, char * * argv)
{
  int n;
  int r;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fib.c:14");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fib.c:15");
  if (argc >= 2) {
    __builtin_debug(6, "", 1);
    n = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    n = 40;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fib.c:16");
  r = fib(n);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fib.c:17");
  printf("fib(%d) = %d\n", n, r);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fib.c:18");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


