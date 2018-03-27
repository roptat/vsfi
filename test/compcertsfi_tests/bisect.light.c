struct _IO_marker;
struct _IO_FILE;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};

struct _IO_FILE {
  int _flags;
  /*signed*/ char *_IO_read_ptr;
  /*signed*/ char *_IO_read_end;
  /*signed*/ char *_IO_read_base;
  /*signed*/ char *_IO_write_base;
  /*signed*/ char *_IO_write_ptr;
  /*signed*/ char *_IO_write_end;
  /*signed*/ char *_IO_buf_base;
  /*signed*/ char *_IO_buf_end;
  /*signed*/ char *_IO_save_base;
  /*signed*/ char *_IO_backup_base;
  /*signed*/ char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  int _old_offset;
  unsigned short _cur_column;
  /*signed*/ char _vtable_offset;
  /*signed*/ char _shortbuf[1];
  void *_lock;
  long long _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  unsigned int __pad5;
  int _mode;
  /*signed*/ char _unused2[40];
};

void *allocvector(unsigned int);

void dallocvector(int, double **);

int sturm(int, double *, double *, double *, double);

void dbisect(double *, double *, double *, int, int, int, double, double *, int *, double *);

void test_matrix(int, double *, double *);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7271[44] = "Error: couldn't allocate V in allocvector.\012";

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7272[40] = "bisect: Couldn't allocate memory for wu";

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7273[10] = "%5d %.5e\012";

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7274[22] = "eps2 = %.5e,  k = %d\012";

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

extern struct _IO_FILE *stderr;

extern int fprintf(struct _IO_FILE *, /*signed*/ char *, ...);

extern int printf(/*signed*/ char *, ...);

extern int fputs(/*signed*/ char *, struct _IO_FILE *);

extern void *malloc(unsigned int);

extern void *calloc(unsigned int, unsigned int);

extern void free(void *);

extern void exit(int);

extern void *memset(void *, int, unsigned int);

extern double fabs(double);

void *allocvector(unsigned int size)
{
  void *V;
  register void *$333;
  register void *$332;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:24"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:26"();
  $332 = malloc((unsigned int) size);
  $333 = (void *) (void *) $332;
  V = $333;
  if ($333 == (void *) 0) {
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:27"();
    fprintf(stderr, __stringlit_b7e1beaced567299ebb74005c5cdb7271);
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:28"();
    exit(2);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:30"();
  memset(V, 0, size);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:31"();
  return V;
}

void dallocvector(int n, double **V)
{
  register void *$332;
  builtin debug6 ""();
  builtin debug1 "#line:bisect.c:36"();
  $332 = allocvector((unsigned int) n * sizeof(double));
  *V = (double *) $332;
}

int sturm(int n, double *c, double *b, double *beta, double x)
{
  int i;
  int a;
  double q;
  register double $332;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:98"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:99"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:100"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:102"();
  a = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:103"();
  q = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:105"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:109"();
    if (q != 0) {
      builtin debug6 ""(1);
      builtin debug1 "#line:bisect.c:112"();
      q = *(c + i) - x - *(beta + i) / q;
    } else {
      builtin debug6 ""(1);
      builtin debug1 "#line:bisect.c:126"();
      $332 = fabs(*(b + i));
      q = *(c + i) - x - $332 / 2.22044604925031308e-16;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:129"();
    if (q < 0) {
      builtin debug6 ""(1);
      builtin debug1 "#line:bisect.c:130"();
      a = a + 1;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:175"();
  return a;
}

void dbisect(double *c, double *b, double *beta, int n, int m1, int m2, double eps1, double *eps2, int *z, double *x)
{
  int i;
  double h;
  double xmin;
  double xmax;
  int a;
  int k;
  double x1;
  double xu;
  double x0;
  double *wu;
  register double $344;
  register double $343;
  register int $342;
  register double $341;
  register double $340;
  register double *$339;
  register void *$338;
  register double $337;
  register double $336;
  register double $335;
  register double $334;
  register double $333;
  register double $332;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:242"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:243"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:244"();
  $332 = (double) 0;
  *(b + 0) = $332;
  *(beta + 0) = $332;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:248"();
  $333 = fabs(*(b + (n - 1)));
  xmin = *(c + (n - 1)) - (double) 1.01000000000000001 * $333;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:249"();
  $334 = fabs(*(b + (n - 1)));
  xmax = *(c + (n - 1)) + (double) 1.01000000000000001 * $334;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:250"();
  builtin debug6 ""(1);
  i = n - 2;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i - 1) {
    if (! (i >= 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:251"();
    $335 = fabs(*(b + i));
    $336 = fabs(*(b + (i + 1)));
    h = (double) 1.01000000000000001 * ($335 + $336);
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:252"();
    if (*(c + i) + h > xmax) {
      builtin debug6 ""(1);
      xmax = *(c + i) + h;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:253"();
    if (*(c + i) - h < xmin) {
      builtin debug6 ""(1);
      xmin = *(c + i) - h;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:259"();
  if (xmin + xmax > 0) {
    $337 = (double) xmax;
  } else {
    $337 = (double) -xmin;
  }
  *eps2 = 2.22044604925031308e-16 * $337;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:260"();
  if (eps1 <= 0) {
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:261"();
    eps1 = *eps2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:262"();
  *eps2 = 0.5 * eps1 + 7 * *eps2;
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:263"();
  builtin debug6 ""(1, 2);
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:264"();
  builtin debug6 ""(1, 2);
  builtin debug6 ""(1, 2);
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:265"();
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:267"();
  $338 = calloc(n + 1, sizeof(double));
  $339 = (double *) (double *) $338;
  wu = $339;
  if ($339 == (void *) 0) {
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:268"();
    fputs(__stringlit_b7e1beaced567299ebb74005c5cdb7272, stderr);
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:269"();
    exit(1);
  }
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:273"();
  x0 = xmax;
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:274"();
  builtin debug6 ""(1, 2);
  i = m2;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
       i = i - 1) {
    if (! (i >= m1)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:275"();
    *(x + i) = xmax;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:276"();
    *(wu + i) = xmin;
  }
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:278"();
  *z = 0;
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:280"();
  builtin debug6 ""(1, 2);
  k = m2;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
       k = k - 1) {
    if (! (k >= m1)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:281"();
    xu = xmin;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:282"();
    builtin debug6 ""(1, 2);
    i = k;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
         i = i - 1) {
      if (! (i >= m1)) {
        break;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:283"();
      if (xu < *(wu + i)) {
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:bisect.c:284"();
        xu = *(wu + i);
        break;
      }
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:288"();
    if (x0 > *(x + k)) {
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:289"();
      x0 = *(x + k);
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:291"();
    x1 = (xu + x0) / 2;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:292"();
    while (1) {
      $340 = fabs(xu);
      $341 = fabs(x0);
      if (! (x0 - xu > 2 * 2.22044604925031308e-16 * ($340 + $341) + eps1)) {
        break;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:293"();
      *z = *z + 1;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:297"();
      $342 = sturm(n, c, b, beta, x1);
      a = $342;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:300"();
      if (a < k) {
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:bisect.c:301"();
        if (a < m1) {
          builtin debug6 ""(1, 2);
          builtin debug1 "#line:bisect.c:302"();
          $343 = (double) x1;
          *(wu + m1) = $343;
          xu = $343;
        } else {
          builtin debug6 ""(1, 2);
          builtin debug1 "#line:bisect.c:304"();
          $344 = (double) x1;
          *(wu + (a + 1)) = $344;
          xu = $344;
          builtin debug6 ""(1, 2);
          builtin debug1 "#line:bisect.c:305"();
          if (*(x + a) > x1) {
            builtin debug6 ""(1, 2);
            *(x + a) = x1;
          }
        }
      } else {
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:bisect.c:309"();
        x0 = x1;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:bisect.c:311"();
      x1 = (xu + x0) / 2;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:bisect.c:313"();
    *(x + k) = (xu + x0) / 2;
  }
  builtin debug6 ""(1, 2);
  builtin debug1 "#line:bisect.c:315"();
  free(wu);
}

void test_matrix(int n, double *C, double *B)
{
  int i;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:331"();
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:333"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:334"();
    *(B + i) = (double) i;
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:335"();
    *(C + i) = (double) (i + 1) * (i + 1);
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:336"();
    *(C + i) = *(C + i) * *(C + i);
  }
}

int main(int argc, /*signed*/ char **argv)
{
  int rep;
  int n;
  int k;
  int i;
  int j;
  double eps;
  double eps2;
  double *D;
  double *E;
  double *beta;
  double *S;
  register double $332;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:343"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:344"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:345"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:347"();
  rep = 50;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:348"();
  n = 500;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:349"();
  eps = 2.22044604925031308e-16;
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:351"();
  dallocvector(n, &D);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:352"();
  dallocvector(n, &E);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:353"();
  dallocvector(n, &beta);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:354"();
  dallocvector(n, &S);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:356"();
  builtin debug6 ""(1);
  j = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       j = j + 1) {
    if (! (j < rep)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:357"();
    test_matrix(n, D, E);
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:359"();
    builtin debug6 ""(1);
    i = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         i = i + 1) {
      if (! (i < n)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:bisect.c:360"();
      *(beta + i) = *(E + i) * *(E + i);
      builtin debug6 ""(1);
      builtin debug1 "#line:bisect.c:361"();
      *(S + i) = 0;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:364"();
    $332 = (double) 0;
    *(beta + 0) = $332;
    *(E + 0) = $332;
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:365"();
    dbisect(D, E, beta, n, 1, n, eps, &eps2, &k, &*(S + -1));
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:369"();
  builtin debug6 ""(1);
  i = 1;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 20)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:bisect.c:370"();
    printf(__stringlit_b7e1beaced567299ebb74005c5cdb7273, i + 1, *(S + i));
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:372"();
  printf(__stringlit_b7e1beaced567299ebb74005c5cdb7274, eps2, k);
  builtin debug6 ""(1);
  builtin debug1 "#line:bisect.c:374"();
  return 0;
  builtin debug6 ""();
  return 0;
}


