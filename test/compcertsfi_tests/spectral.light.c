double eval_A_1454(int, int);

void eval_A_times_u(int, double *, double *);

void eval_At_times_u(int, double *, double *);

void eval_AtA_times_u(int, double *, double *);

int main(int, /*signed*/ char **);

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
  builtin debug6 ""();
  builtin debug1 "#line:spectral.c:13"();
  return 1 / ((i + j) * (i + j + 1) / 2 + i + 1);
}

void eval_A_times_u(int N, double *u, double *Au)
{
  int i;
  int j;
  register double $179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:17"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:18"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < N)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:20"();
    *(Au + i) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:21"();
    builtin debug6 ""(1);
    j = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < N)) {
        break;
      }
      builtin debug6 ""(1);
      $179 = eval_A_1454(i, j);
      *(Au + i) = *(Au + i) + $179 * *(u + j);
    }
  }
}

void eval_At_times_u(int N, double *u, double *Au)
{
  int i;
  int j;
  register double $179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:27"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:28"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < N)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:30"();
    *(Au + i) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:31"();
    builtin debug6 ""(1);
    j = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < N)) {
        break;
      }
      builtin debug6 ""(1);
      $179 = eval_A_1454(j, i);
      *(Au + i) = *(Au + i) + $179 * *(u + j);
    }
  }
}

void eval_AtA_times_u(int N, double *u, double *AtAu)
{
  double *v;
  register void *$179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:37"();
  $179 = malloc(N * sizeof(double));
  v = $179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:38"();
  eval_A_times_u(N, u, v);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:39"();
  eval_At_times_u(N, v, AtAu);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:40"();
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
  register double $184;
  register double $183;
  register void *$182;
  register void *$181;
  register int $180;
  register int $179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:45"();
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:46"();
  if (argc == 2) {
    $180 = atoi(*(argv + 1));
    $179 = (int) $180;
  } else {
    $179 = (int) 2500;
  }
  N = $179;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:47"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:48"();
  $181 = malloc(N * sizeof(double));
  u = $181;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:49"();
  $182 = malloc(N * sizeof(double));
  v = $182;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:50"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < N)) {
      break;
    }
    builtin debug6 ""(1);
    *(u + i) = 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:51"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 10)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:53"();
    eval_AtA_times_u(N, u, v);
    builtin debug6 ""(1);
    builtin debug1 "#line:spectral.c:54"();
    eval_AtA_times_u(N, v, u);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:56"();
  $183 = (double) 0;
  vv = $183;
  vBv = $183;
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:57"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < N)) {
      break;
    }
    builtin debug6 ""(1);
    vBv = vBv + *(u + i) * *(v + i);
    builtin debug6 ""(1);
    vv = vv + *(v + i) * *(v + i);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:58"();
  $184 = sqrt(vBv / vv);
  printf(__stringlit_bcec3188dd5a9993cf6b12fd4576666d1, $184);
  builtin debug6 ""(1);
  builtin debug1 "#line:spectral.c:59"();
  return 0;
  builtin debug6 ""();
  return 0;
}


