extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern int atoi(char const * __nptr);

extern int printf(char const * __format, ...);

static double square_586(double x)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:integr.c:6");
  return x * x;
}

static double integr_593(double (* f)(double ), double low, double high,
                         int n)
{
  double h;
  double x;
  double s;
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:11");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:12");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:14");
  h = (high - low) / n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:15");
  s = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:16");
  for (__builtin_debug(6, "", 1), (i = n, x = low);
       i > 0;
       __builtin_debug(6, "", 1), (i--, x += h)) {
    __builtin_debug(6, "", 1);
    s += f(x);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:17");
  return s * h;
}

double test(int n)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:integr.c:22");
  return integr_593(square_586, 0.0E0, 1.0E0, n);
}

int main(int argc, char * * argv)
{
  int n;
  double r;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:27");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:28");
  if (argc >= 2) {
    __builtin_debug(6, "", 1);
    n = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    n = 10000000;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:29");
  r = test(n);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:30");
  printf("integr(square, 0.0, 1.0, %d) = %g\n", n, r);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:integr.c:31");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


