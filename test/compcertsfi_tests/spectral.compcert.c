static /*signed*/ char const __stringlit_bcec3188dd5a9993cf6b12fd4576666d1[7];

extern unsigned int keep[2];

static double eval_A_1454(int, int);

extern void eval_A_times_u(int, double *, double *);

extern void eval_At_times_u(int, double *, double *);

extern void eval_AtA_times_u(int, double *, double *);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_bcec3188dd5a9993cf6b12fd4576666d1[7] = "%0.9f\012";

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

extern int printf(/*signed*/ char *, ...);

extern int atoi(/*signed*/ char *);

extern void *malloc(unsigned int);

extern void free(void *);

extern double sqrt(double);

double eval_A_1454(int i, int j)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:spectral.c:13");
  return 1. / ((i + j) * (i + j + 1) / 2 + i + 1);
}

void eval_A_times_u(int N, double *u, double *Au)
{
  int i;
  int j;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:17");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:18");
  for (__builtin_debug(6,"", 1), i = 0;
       i < N;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:20");
    *(Au + i) = 0;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:21");
    for (__builtin_debug(6,"", 1), j = 0;
         j < N;
         __builtin_debug(6,"", 1), j++) {
      __builtin_debug(6,"", 1);
      *(Au + i) += eval_A_1454(i, j) * *(u + j);
    }
  }
}

void eval_At_times_u(int N, double *u, double *Au)
{
  int i;
  int j;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:27");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:28");
  for (__builtin_debug(6,"", 1), i = 0;
       i < N;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:30");
    *(Au + i) = 0;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:31");
    for (__builtin_debug(6,"", 1), j = 0;
         j < N;
         __builtin_debug(6,"", 1), j++) {
      __builtin_debug(6,"", 1);
      *(Au + i) += eval_A_1454(j, i) * *(u + j);
    }
  }
}

void eval_AtA_times_u(int N, double *u, double *AtAu)
{
  double *v;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:37");
  v = malloc(N * sizeof(double));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:38");
  eval_A_times_u(N, u, v);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:39");
  eval_At_times_u(N, v, AtAu);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:40");
  free(v);
}

int main(int argc, /*signed*/ char **argv)
{
  int i;
  int N;
  double *u;
  double *v;
  double vBv;
  double vv;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:45");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:46");
  N = argc == 2 ? atoi(*(argv + 1)) : 2500;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:47");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:48");
  u = malloc(N * sizeof(double));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:49");
  v = malloc(N * sizeof(double));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:50");
  for (__builtin_debug(6,"", 1), i = 0;
       i < N;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    *(u + i) = 1;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:51");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 10;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:53");
    eval_AtA_times_u(N, u, v);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:spectral.c:54");
    eval_AtA_times_u(N, v, u);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:56");
  vBv = vv = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:57");
  for (__builtin_debug(6,"", 1), i = 0;
       i < N;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    vBv += *(u + i) * *(v + i);
    __builtin_debug(6,"", 1);
    vv += *(v + i) * *(v + i);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:58");
  printf(__stringlit_bcec3188dd5a9993cf6b12fd4576666d1, sqrt(vBv / vv));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:spectral.c:59");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


