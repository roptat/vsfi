static /*signed*/ char const __stringlit_f95d6caf60ade5f214b9557ac4ce37141[14];

extern unsigned int keep[2];

extern int fib(int);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_f95d6caf60ade5f214b9557ac4ce37141[14] = "fib(%d) = %d\012";

extern unsigned int __compcert_va_int32(void *);

extern unsigned long long __compcert_va_int64(void *);

extern double __compcert_va_float64(void *);

extern void *__compcert_va_composite(void *, unsigned int);

extern long long __i64_dtos(double);

extern unsigned long long __i64_dtou(double);

extern double __i64_stod(long long);

extern double __i64_utod(unsigned long long);

extern float __i64_stof(long long);

extern float __i64_utof(unsigned long long);

extern long long __i64_sdiv(long long, long long);

extern unsigned long long __i64_udiv(unsigned long long, unsigned long long);

extern long long __i64_smod(long long, long long);

extern unsigned long long __i64_umod(unsigned long long, unsigned long long);

extern long long __i64_shl(long long, int);

extern unsigned long long __i64_shr(unsigned long long, int);

extern long long __i64_sar(long long, int);

extern long long __i64_smulh(long long, long long);

extern unsigned long long __i64_umulh(unsigned long long, unsigned long long);

extern void __builtin_debug(int, ...);

extern int dummy$compare(unsigned int, unsigned int);

extern void dummy$doit(void);

 unsigned int keep[2] = { &dummy$compare, &dummy$doit, };

extern int atoi(/*signed*/ char *);

extern int printf(/*signed*/ char *, ...);

int fib(int n)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:fib.c:6");
  if (n < 2) {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:fib.c:7");
    return 1;
  } else {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:fib.c:9");
    return fib(n - 1) + fib(n - 2);
  }
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int r;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fib.c:14");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fib.c:15");
  if (argc >= 2) {
    __builtin_debug(6,"", 1);
    n = atoi(*(argv + 1));
  } else {
    __builtin_debug(6,"", 1);
    n = 40;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fib.c:16");
  r = fib(n);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fib.c:17");
  printf(__stringlit_f95d6caf60ade5f214b9557ac4ce37141, n, r);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fib.c:18");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


