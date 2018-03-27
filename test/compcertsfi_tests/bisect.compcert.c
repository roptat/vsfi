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

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7271[44];

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7272[40];

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7273[10];

static /*signed*/ char const __stringlit_b7e1beaced567299ebb74005c5cdb7274[22];

extern unsigned int keep[2];

extern struct _IO_FILE *stderr;

extern void *allocvector(unsigned int);

extern void dallocvector(int, double **);

extern int sturm(int, double *, double *, double *, double);

extern void dbisect(double *, double *, double *, int, int, int, double, double *, int *, double *);

extern void test_matrix(int, double *, double *);

extern int main(int, /*signed*/ char **);

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
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:24");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:26");
  if ((V = (void *) malloc((unsigned int) size)) == (void *) 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:27");
    fprintf(stderr, __stringlit_b7e1beaced567299ebb74005c5cdb7271);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:28");
    exit(2);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:30");
  memset(V, 0, size);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:31");
  return V;
}

void dallocvector(int n, double **V)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:bisect.c:36");
  *V = (double *) allocvector((unsigned int) n * sizeof(double));
}

int sturm(int n, double *c, double *b, double *beta, double x)
{
  int i;
  int a;
  double q;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:98");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:99");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:100");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:102");
  a = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:103");
  q = 1.;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:105");
  for (__builtin_debug(6,"", 1), i = 0;
       i < n;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:109");
    if (q != 0.) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:bisect.c:112");
      q = *(c + i) - x - *(beta + i) / q;
    } else {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:bisect.c:126");
      q = *(c + i) - x - fabs(*(b + i)) / 2.22044604925e-16;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:129");
    if (q < 0) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:bisect.c:130");
      a = a + 1;
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:175");
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
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:242");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:243");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:244");
  *(beta + 0) = *(b + 0) = 0.;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:248");
  xmin = *(c + (n - 1)) - (double) 1.01 * fabs(*(b + (n - 1)));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:249");
  xmax = *(c + (n - 1)) + (double) 1.01 * fabs(*(b + (n - 1)));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:250");
  for (__builtin_debug(6,"", 1), i = n - 2;
       i >= 0;
       __builtin_debug(6,"", 1), i--) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:251");
    h = (double) 1.01 * (fabs(*(b + i)) + fabs(*(b + (i + 1))));
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:252");
    if (*(c + i) + h > xmax) {
      __builtin_debug(6,"", 1);
      xmax = *(c + i) + h;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:253");
    if (*(c + i) - h < xmin) {
      __builtin_debug(6,"", 1);
      xmin = *(c + i) - h;
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:259");
  *eps2 = 2.22044604925e-16 * (xmin + xmax > 0 ? xmax : -xmin);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:260");
  if (eps1 <= 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:261");
    eps1 = *eps2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:262");
  *eps2 = 0.5 * eps1 + 7 * *eps2;
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:263");
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:264");
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:265");
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:267");
  if ((wu = (double *) calloc(n + 1, sizeof(double))) == (void *) 0) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:268");
    fputs(__stringlit_b7e1beaced567299ebb74005c5cdb7272, stderr);
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:269");
    exit(1);
  }
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:273");
  x0 = xmax;
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:274");
  for (__builtin_debug(6,"", 1, 2), i = m2;
       i >= m1;
       __builtin_debug(6,"", 1, 2), i--) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:275");
    *(x + i) = xmax;
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:276");
    *(wu + i) = xmin;
  }
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:278");
  *z = 0;
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:280");
  for (__builtin_debug(6,"", 1, 2), k = m2;
       k >= m1;
       __builtin_debug(6,"", 1, 2), k--) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:281");
    xu = xmin;
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:282");
    for (__builtin_debug(6,"", 1, 2), i = k;
         i >= m1;
         __builtin_debug(6,"", 1, 2), i--) {
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:283");
      if (xu < *(wu + i)) {
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:bisect.c:284");
        xu = *(wu + i);
        break;
      }
    }
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:288");
    if (x0 > *(x + k)) {
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:289");
      x0 = *(x + k);
    }
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:291");
    x1 = (xu + x0) / 2;
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:292");
    while (x0 - xu > 2 * 2.22044604925e-16 * (fabs(xu) + fabs(x0)) + eps1) {
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:293");
      *z = *z + 1;
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:297");
      a = sturm(n, c, b, beta, x1);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:300");
      if (a < k) {
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:bisect.c:301");
        if (a < m1) {
          __builtin_debug(6,"", 1, 2);
          __builtin_debug(1,"#line:bisect.c:302");
          xu = *(wu + m1) = x1;
        } else {
          __builtin_debug(6,"", 1, 2);
          __builtin_debug(1,"#line:bisect.c:304");
          xu = *(wu + (a + 1)) = x1;
          __builtin_debug(6,"", 1, 2);
          __builtin_debug(1,"#line:bisect.c:305");
          if (*(x + a) > x1) {
            __builtin_debug(6,"", 1, 2);
            *(x + a) = x1;
          }
        }
      } else {
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:bisect.c:309");
        x0 = x1;
      }
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:bisect.c:311");
      x1 = (xu + x0) / 2;
    }
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:bisect.c:313");
    *(x + k) = (xu + x0) / 2;
  }
  __builtin_debug(6,"", 1, 2);
  __builtin_debug(1,"#line:bisect.c:315");
  free(wu);
}

void test_matrix(int n, double *C, double *B)
{
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:331");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:333");
  for (__builtin_debug(6,"", 1), i = 0;
       i < n;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:334");
    *(B + i) = (double) i;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:335");
    *(C + i) = (double) (i + 1) * (i + 1);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:336");
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
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:343");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:344");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:345");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:347");
  rep = 50;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:348");
  n = 500;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:349");
  eps = 2.22044604925e-16;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:351");
  dallocvector(n, &D);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:352");
  dallocvector(n, &E);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:353");
  dallocvector(n, &beta);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:354");
  dallocvector(n, &S);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:356");
  for (__builtin_debug(6,"", 1), j = 0;
       j < rep;
       __builtin_debug(6,"", 1), j++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:357");
    test_matrix(n, D, E);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:359");
    for (__builtin_debug(6,"", 1), i = 0;
         i < n;
         __builtin_debug(6,"", 1), i++) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:bisect.c:360");
      *(beta + i) = *(E + i) * *(E + i);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:bisect.c:361");
      *(S + i) = 0.;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:364");
    *(E + 0) = *(beta + 0) = 0;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:365");
    dbisect(D, E, beta, n, 1, n, eps, &eps2, &k, &*(S + -1));
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:369");
  for (__builtin_debug(6,"", 1), i = 1;
       i < 20;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:bisect.c:370");
    printf(__stringlit_b7e1beaced567299ebb74005c5cdb7273, i + 1, *(S + i));
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:372");
  printf(__stringlit_b7e1beaced567299ebb74005c5cdb7274, eps2, k);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:bisect.c:374");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


