double square_586(double);

double integr_593(double (*)(double), double, double, int);

double test(int);

int main(int, /*signed*/ char **);

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
  builtin debug6 ""();
  builtin debug1 "#line:integr.c:6"();
  return x * x;
}

double integr_593(double (*f)(double), double low, double high, int n)
{
  double h;
  double x;
  double s;
  int i;
  register double $162;
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:11"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:12"();
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:14"();
  h = (high - low) / n;
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:15"();
  s = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:16"();
  builtin debug6 ""(1);
  i = n;
  x = low;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i - 1, x = x + h) {
    if (! (i > 0)) {
      break;
    }
    builtin debug6 ""(1);
    $162 = f(x);
    s = s + $162;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:17"();
  return s * h;
}

double test(int n)
{
  register double $162;
  builtin debug6 ""();
  builtin debug1 "#line:integr.c:22"();
  $162 = integr_593(square_586, 0, 1, n);
  return $162;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  double r;
  register double $163;
  register int $162;
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:27"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:28"();
  if (argc >= 2) {
    builtin debug6 ""(1);
    $162 = atoi(*(argv + 1));
    n = $162;
  } else {
    builtin debug6 ""(1);
    n = 10000000;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:29"();
  $163 = test(n);
  r = $163;
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:30"();
  printf(__stringlit_4e3c8041658920df6c3fd8483c0d5b921, n, r);
  builtin debug6 ""(1);
  builtin debug1 "#line:integr.c:31"();
  return 0;
  builtin debug6 ""();
  return 0;
}


