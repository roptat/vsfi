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

extern double sqrt(double __x);

inline static double eval_A_1454(int i, int j)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:spectral.c:13");
  return 1.0E0 / ((i + j) * (i + j + 1) / 2 + i + 1);
}

void eval_A_times_u(int N, double const * u, double * Au)
{
  int i;
  int j;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:17");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:18");
  for (__builtin_debug(6, "", 1), i = 0;
       i < N;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:20");
    Au[i] = 0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:21");
    for (__builtin_debug(6, "", 1), j = 0;
         j < N;
         __builtin_debug(6, "", 1), j++) {
      __builtin_debug(6, "", 1);
      Au[i] += eval_A_1454(i, j) * u[j];
    }
  }
}

void eval_At_times_u(int N, double const * u, double * Au)
{
  int i;
  int j;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:27");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:28");
  for (__builtin_debug(6, "", 1), i = 0;
       i < N;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:30");
    Au[i] = 0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:31");
    for (__builtin_debug(6, "", 1), j = 0;
         j < N;
         __builtin_debug(6, "", 1), j++) {
      __builtin_debug(6, "", 1);
      Au[i] += eval_A_1454(j, i) * u[j];
    }
  }
}

void eval_AtA_times_u(int N, double const * u, double * AtAu)
{
  double * v;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:37");
  v = malloc(N * sizeof(double));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:38");
  eval_A_times_u(N, u, v);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:39");
  eval_At_times_u(N, v, AtAu);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:40");
  free(v);
}

int main(int argc, char * * argv)
{
  int i;
  int N;
  double * u;
  double * v;
  double vBv;
  double vv;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:45");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:46");
  N = argc == 2 ? atoi(argv[1]) : 2500;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:47");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:48");
  u = malloc(N * sizeof(double));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:49");
  v = malloc(N * sizeof(double));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:50");
  for (__builtin_debug(6, "", 1), i = 0;
       i < N;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    u[i] = 1;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:51");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 10;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:53");
    eval_AtA_times_u(N, u, v);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:spectral.c:54");
    eval_AtA_times_u(N, v, u);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:56");
  vBv = vv = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:57");
  for (__builtin_debug(6, "", 1), i = 0;
       i < N;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    vBv += u[i] * v[i];
    __builtin_debug(6, "", 1);
    vv += v[i] * v[i];
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:58");
  printf("%0.9f\n", sqrt(vBv / vv));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:spectral.c:59");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


