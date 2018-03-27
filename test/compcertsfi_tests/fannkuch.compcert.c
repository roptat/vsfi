static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e3[23];

static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e1[3];

static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e2[2];

extern unsigned int keep[2];

static int fannkuch_586(int);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e3[23] = "Pfannkuchen(%d) = %ld\012";

static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e1[3] = "%d";

static /*signed*/ char const __stringlit_b6c7088c50a688cd58de916d65eebc1e2[2] = "\012";

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

extern void *calloc(unsigned int, unsigned int);

int fannkuch_586(int n)
{
  int *perm;
  int *perm1;
  int *count;
  int flips;
  int flipsMax;
  int r;
  int i;
  int k;
  int didpr;
  int n1;
  int j;
  int t_mp;
  int perm0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:19");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:20");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:21");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:22");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:23");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:24");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:25");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:26");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:27");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:28");
  n1 = n - 1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:30");
  if (n < 1) {
    __builtin_debug(6,"", 1);
    return 0;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:32");
  perm = calloc(n, sizeof(int));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:33");
  perm1 = calloc(n, sizeof(int));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:34");
  count = calloc(n, sizeof(int));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:36");
  for (__builtin_debug(6,"", 1), i = 0;
       i < n;
       __builtin_debug(6,"", 1), i += 1) {
    __builtin_debug(6,"", 1);
    *(perm1 + i) = i;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:38");
  r = n;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:39");
  didpr = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:40");
  flipsMax = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:41");
  for (/*nothing*/; 1; /*nothing*/) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:fannkuch.c:42");
    if (didpr < 30) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:43");
      for (__builtin_debug(6,"", 1), i = 0;
           i < n;
           __builtin_debug(6,"", 1), i += 1) {
        __builtin_debug(6,"", 1);
        printf(__stringlit_b6c7088c50a688cd58de916d65eebc1e1,
               (int) (1 + *(perm1 + i)));
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:44");
      printf(__stringlit_b6c7088c50a688cd58de916d65eebc1e2);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:45");
      didpr += 1;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:fannkuch.c:47");
    for (/*nothing*/; r != 1; __builtin_debug(6,"", 1), r -= 1) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:48");
      *(count + (r - 1)) = r;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:fannkuch.c:53");
    if (!(*(perm1 + 0) == 0 || *(perm1 + n1) == n1)) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:54");
      flips = 0;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:55");
      for (__builtin_debug(6,"", 1), i = 1;
           i < n;
           __builtin_debug(6,"", 1), i += 1) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:fannkuch.c:56");
        *(perm + i) = *(perm1 + i);
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:58");
      k = *(perm1 + 0);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:59");
      do {
        __builtin_debug(6,"", 1, 3);
        __builtin_debug(1,"#line:fannkuch.c:60");
        __builtin_debug(6,"", 1, 3);
        __builtin_debug(1,"#line:fannkuch.c:61");
        for (__builtin_debug(6,"", 1, 3), i = 1, j = k - 1;
             i < j;
             __builtin_debug(6,"", 1, 3), i += 1, j -= 1) {
          __builtin_debug(6,"", 1, 3, 4);
          __builtin_debug(1,"#line:fannkuch.c:62");
          __builtin_debug(6,"", 1, 3, 4);
          t_mp = *(perm + i);
          __builtin_debug(6,"", 1, 3, 4);
          *(perm + i) = *(perm + j);
          __builtin_debug(6,"", 1, 3, 4);
          *(perm + j) = t_mp;
        }
        __builtin_debug(6,"", 1, 3);
        __builtin_debug(1,"#line:fannkuch.c:64");
        flips += 1;
        __builtin_debug(6,"", 1, 3);
        __builtin_debug(1,"#line:fannkuch.c:69");
        j = *(perm + k);
        __builtin_debug(6,"", 1, 3);
        *(perm + k) = k;
        __builtin_debug(6,"", 1, 3);
        k = j;
      } while(k);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:71");
      if (flipsMax < flips) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:fannkuch.c:72");
        flipsMax = flips;
      }
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:fannkuch.c:76");
    for (/*nothing*/; 1; /*nothing*/) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:77");
      if (r == n) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:fannkuch.c:78");
        return flipsMax;
      }
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:fannkuch.c:82");
      perm0 = *(perm1 + 0);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:fannkuch.c:83");
      i = 0;
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:fannkuch.c:84");
      while (i < r) {
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:fannkuch.c:85");
        k = i + 1;
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:fannkuch.c:86");
        *(perm1 + i) = *(perm1 + k);
        __builtin_debug(6,"", 1, 2);
        __builtin_debug(1,"#line:fannkuch.c:87");
        i = k;
      }
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:fannkuch.c:89");
      *(perm1 + r) = perm0;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:91");
      if ((*(count + r) -= 1) > 0) {
        break;
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:fannkuch.c:94");
      r += 1;
    }
  }
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:101");
  n = argc > 1 ? atoi(*(argv + 1)) : 11;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:102");
  printf(__stringlit_b6c7088c50a688cd58de916d65eebc1e3, n, fannkuch_586(n));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:fannkuch.c:103");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


