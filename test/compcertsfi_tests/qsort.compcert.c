static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14092[19];

static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14093[4];

static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14091[6];

extern unsigned int keep[2];

extern void quicksort(int, int, int *);

extern int cmpint(void *, void *);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14092[19] = "a[%d]=%d\012b[%d]=%d\012";

static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14093[4] = "OK\012";

static /*signed*/ char const __stringlit_caa6e68e51e46e8b28174370a34e14091[6] = "Bug!\012";

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

extern int rand(void);

extern void *malloc(unsigned int);

extern void qsort(void *, unsigned int, unsigned int, int (*)(void *, void *));

extern int printf(/*signed*/ char *, ...);

void quicksort(int lo, int hi, int *base)
{
  int i;
  int j;
  int pivot;
  int temp;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:7");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:8");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:10");
  if (lo < hi) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:11");
    for (__builtin_debug(6,"", 1), i = lo, j = hi, pivot = *(base + hi);
         i < j;
         /*nothing*/) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:12");
      while (i < hi && *(base + i) <= pivot) {
        __builtin_debug(6,"", 1);
        i++;
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:13");
      while (j > lo && *(base + j) >= pivot) {
        __builtin_debug(6,"", 1);
        j--;
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:14");
      if (i < j) {
        __builtin_debug(6,"", 1);
        temp = *(base + i);
        __builtin_debug(6,"", 1);
        *(base + i) = *(base + j);
        __builtin_debug(6,"", 1);
        *(base + j) = temp;
      }
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:16");
    temp = *(base + i);
    __builtin_debug(6,"", 1);
    *(base + i) = *(base + hi);
    __builtin_debug(6,"", 1);
    *(base + hi) = temp;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:17");
    quicksort(lo, i - 1, base);
    __builtin_debug(6,"", 1);
    quicksort(i + 1, hi, base);
  }
}

int cmpint(void *i, void *j)
{
  int vi;
  int vj;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:23");
  vi = *((int *) i);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:24");
  vj = *((int *) j);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:25");
  if (vi == vj) {
    __builtin_debug(6,"", 1);
    return 0;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:26");
  if (vi < vj) {
    __builtin_debug(6,"", 1);
    return -1;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:27");
  return 1;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int i;
  int j;
  int *a;
  int *b;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:34");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:35");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:37");
  if (argc >= 2) {
    __builtin_debug(6,"", 1);
    n = atoi(*(argv + 1));
  } else {
    __builtin_debug(6,"", 1);
    n = 100000;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:38");
  a = malloc(n * sizeof(int));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:39");
  b = malloc(n * sizeof(int));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:40");
  for (__builtin_debug(6,"", 1), j = 0;
       j < 100;
       __builtin_debug(6,"", 1), j++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:41");
    for (__builtin_debug(6,"", 1), i = 0;
         i < n;
         __builtin_debug(6,"", 1), i++) {
      __builtin_debug(6,"", 1);
      *(b + i) = *(a + i) = rand() & 65535;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:42");
    quicksort(0, n - 1, a);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:44");
  qsort(b, n, sizeof(int), cmpint);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:45");
  for (__builtin_debug(6,"", 1), i = 0;
       i < n;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:qsort.c:46");
    if (*(a + i) != *(b + i)) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:47");
      printf(__stringlit_caa6e68e51e46e8b28174370a34e14091);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:48");
      printf(__stringlit_caa6e68e51e46e8b28174370a34e14092, i, *(a + i), 
             i, *(b + i));
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:qsort.c:49");
      return 2;
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:52");
  printf(__stringlit_caa6e68e51e46e8b28174370a34e14093);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:qsort.c:53");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


