static /*signed*/ char const __stringlit_4e3c8041658920df6c3fd8483c0d5b921[35];

extern unsigned int keep[2];

static double square_586(double);

static double integr_593(double (*)(double), double, double, int);

extern double test(int);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_4e3c8041658920df6c3fd8483c0d5b921[35] = "integr(square, 0.0, 1.0, %d) = %g\012";

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

double square_586(double x)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:integr.c:6");
  return x * x;
}

double integr_593(double (*f)(double), double low, double high, int n)
{
  double h;
  double x;
  double s;
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:11");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:12");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:14");
  h = (high - low) / n;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:15");
  s = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:16");
  for (__builtin_debug(6,"", 1), i = n, x = low;
       i > 0;
       __builtin_debug(6,"", 1), i--, x += h) {
    __builtin_debug(6,"", 1);
    s += f(x);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:17");
  return s * h;
}

double test(int n)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:integr.c:22");
  return integr_593(square_586, 0., 1., n);
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  double r;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:27");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:28");
  if (argc >= 2) {
    __builtin_debug(6,"", 1);
    n = atoi(*(argv + 1));
  } else {
    __builtin_debug(6,"", 1);
    n = 10000000;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:29");
  r = test(n);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:30");
  printf(__stringlit_4e3c8041658920df6c3fd8483c0d5b921, n, r);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:integr.c:31");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


