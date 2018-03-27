int fannkuch_586(int);

int main(int, /*signed*/ char **);

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
  register int $203;
  register int $202;
  register void *$201;
  register void *$200;
  register void *$199;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:19"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:20"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:21"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:22"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:23"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:24"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:25"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:26"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:27"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:28"();
  n1 = n - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:30"();
  if (n < 1) {
    builtin debug6 ""(1);
    return 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:32"();
  $199 = calloc(n, sizeof(int));
  perm = $199;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:33"();
  $200 = calloc(n, sizeof(int));
  perm1 = $200;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:34"();
  $201 = calloc(n, sizeof(int));
  count = $201;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:36"();
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
    *(perm1 + i) = i;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:38"();
  r = n;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:39"();
  didpr = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:40"();
  flipsMax = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:41"();
  while (1) {
    (void)0 /*skip*/;
    builtin debug6 ""(1);
    builtin debug1 "#line:fannkuch.c:42"();
    if (didpr < 30) {
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:43"();
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
        printf
          (__stringlit_b6c7088c50a688cd58de916d65eebc1e1,
           (int) (1 + *(perm1 + i)));
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:44"();
      printf(__stringlit_b6c7088c50a688cd58de916d65eebc1e2);
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:45"();
      didpr = didpr + 1;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fannkuch.c:47"();
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         r = r - 1) {
      if (! (r != 1)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:48"();
      *(count + (r - 1)) = r;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fannkuch.c:53"();
    if (*(perm1 + 0) == 0) {
      $202 = 1;
    } else {
      $202 = (_Bool) (*(perm1 + n1) == n1);
    }
    if (!$202) {
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:54"();
      flips = 0;
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:55"();
      builtin debug6 ""(1);
      i = 1;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           i = i + 1) {
        if (! (i < n)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:fannkuch.c:56"();
        *(perm + i) = *(perm1 + i);
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:58"();
      k = *(perm1 + 0);
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:59"();
      for (; 1; (void)0 /*nothing*/, ({ if (! k) {
                                          break;
                                        } })) {
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:fannkuch.c:60"();
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:fannkuch.c:61"();
        builtin debug6 ""(1, 3);
        i = 1;
        j = k - 1;
        for (;
             1;
             (void)0 /*nothing*/, builtin debug6 ""(1, 3);, (void)0 /*nothing*/, 
             i = i + 1, j = j - 1) {
          if (! (i < j)) {
            break;
          }
          builtin debug6 ""(1, 3, 4);
          builtin debug1 "#line:fannkuch.c:62"();
          builtin debug6 ""(1, 3, 4);
          t_mp = *(perm + i);
          builtin debug6 ""(1, 3, 4);
          *(perm + i) = *(perm + j);
          builtin debug6 ""(1, 3, 4);
          *(perm + j) = t_mp;
        }
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:fannkuch.c:64"();
        flips = flips + 1;
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:fannkuch.c:69"();
        j = *(perm + k);
        builtin debug6 ""(1, 3);
        *(perm + k) = k;
        builtin debug6 ""(1, 3);
        k = j;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:71"();
      if (flipsMax < flips) {
        builtin debug6 ""(1);
        builtin debug1 "#line:fannkuch.c:72"();
        flipsMax = flips;
      }
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fannkuch.c:76"();
    while (1) {
      (void)0 /*skip*/;
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:77"();
      if (r == n) {
        builtin debug6 ""(1);
        builtin debug1 "#line:fannkuch.c:78"();
        return flipsMax;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:fannkuch.c:82"();
      perm0 = *(perm1 + 0);
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:fannkuch.c:83"();
      i = 0;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:fannkuch.c:84"();
      while (1) {
        if (! (i < r)) {
          break;
        }
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:fannkuch.c:85"();
        k = i + 1;
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:fannkuch.c:86"();
        *(perm1 + i) = *(perm1 + k);
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:fannkuch.c:87"();
        i = k;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:fannkuch.c:89"();
      *(perm1 + r) = perm0;
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:91"();
      $203 = (int) (*(count + r) - 1);
      *(count + r) = $203;
      if ($203 > 0) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fannkuch.c:94"();
      r = r + 1;
    }
  }
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  register int $201;
  register int $200;
  register int $199;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:101"();
  if (argc > 1) {
    $200 = atoi(*(argv + 1));
    $199 = (int) $200;
  } else {
    $199 = (int) 11;
  }
  n = $199;
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:102"();
  $201 = fannkuch_586(n);
  printf(__stringlit_b6c7088c50a688cd58de916d65eebc1e3, n, $201);
  builtin debug6 ""(1);
  builtin debug1 "#line:fannkuch.c:103"();
  return 0;
  builtin debug6 ""();
  return 0;
}


