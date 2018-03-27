void quicksort(int, int, int *);

int cmpint(void *, void *);

int main(int, /*signed*/ char **);

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
  register int $187;
  register int $186;
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:7"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:8"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:10"();
  if (lo < hi) {
    builtin debug6 ""(1);
    builtin debug1 "#line:qsort.c:11"();
    builtin debug6 ""(1);
    i = lo;
    j = hi;
    pivot = *(base + hi);
    while (1) {
      if (! (i < j)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:12"();
      while (1) {
        if (i < hi) {
          $186 = (_Bool) (*(base + i) <= pivot);
        } else {
          $186 = 0;
        }
        if (! $186) {
          break;
        }
        builtin debug6 ""(1);
        i = i + 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:13"();
      while (1) {
        if (j > lo) {
          $187 = (_Bool) (*(base + j) >= pivot);
        } else {
          $187 = 0;
        }
        if (! $187) {
          break;
        }
        builtin debug6 ""(1);
        j = j - 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:14"();
      if (i < j) {
        builtin debug6 ""(1);
        temp = *(base + i);
        builtin debug6 ""(1);
        *(base + i) = *(base + j);
        builtin debug6 ""(1);
        *(base + j) = temp;
      }
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:qsort.c:16"();
    temp = *(base + i);
    builtin debug6 ""(1);
    *(base + i) = *(base + hi);
    builtin debug6 ""(1);
    *(base + hi) = temp;
    builtin debug6 ""(1);
    builtin debug1 "#line:qsort.c:17"();
    quicksort(lo, i - 1, base);
    builtin debug6 ""(1);
    quicksort(i + 1, hi, base);
  }
}

int cmpint(void *i, void *j)
{
  int vi;
  int vj;
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:23"();
  vi = *((int *) i);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:24"();
  vj = *((int *) j);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:25"();
  if (vi == vj) {
    builtin debug6 ""(1);
    return 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:26"();
  if (vi < vj) {
    builtin debug6 ""(1);
    return -1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:27"();
  return 1;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int i;
  int j;
  int *a;
  int *b;
  register int $190;
  register int $189;
  register void *$188;
  register void *$187;
  register int $186;
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:34"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:35"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:37"();
  if (argc >= 2) {
    builtin debug6 ""(1);
    $186 = atoi(*(argv + 1));
    n = $186;
  } else {
    builtin debug6 ""(1);
    n = 100000;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:38"();
  $187 = malloc(n * sizeof(int));
  a = $187;
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:39"();
  $188 = malloc(n * sizeof(int));
  b = $188;
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:40"();
  builtin debug6 ""(1);
  j = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       j = j + 1) {
    if (! (j < 100)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:qsort.c:41"();
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
      $189 = rand();
      $190 = (int) ($189 & 65535);
      *(a + i) = $190;
      *(b + i) = $190;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:qsort.c:42"();
    quicksort(0, n - 1, a);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:44"();
  qsort(b, n, sizeof(int), cmpint);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:45"();
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
    builtin debug1 "#line:qsort.c:46"();
    if (*(a + i) != *(b + i)) {
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:47"();
      printf(__stringlit_caa6e68e51e46e8b28174370a34e14091);
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:48"();
      printf
        (__stringlit_caa6e68e51e46e8b28174370a34e14092, i, *(a + i), 
         i, *(b + i));
      builtin debug6 ""(1);
      builtin debug1 "#line:qsort.c:49"();
      return 2;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:52"();
  printf(__stringlit_caa6e68e51e46e8b28174370a34e14093);
  builtin debug6 ""(1);
  builtin debug1 "#line:qsort.c:53"();
  return 0;
  builtin debug6 ""();
  return 0;
}


