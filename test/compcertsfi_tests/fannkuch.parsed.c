extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

extern void * calloc(size_t __nmemb, size_t __size);

static long fannkuch_586(int n)
{
  int * perm;
  int * perm1;
  int * count;
  long flips;
  long flipsMax;
  int r;
  int i;
  int k;
  int didpr;
  int n1;
  int j;
  int t_mp;
  int perm0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:19");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:20");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:21");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:22");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:23");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:24");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:25");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:26");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:27");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:28");
  n1 = n - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:30");
  if (n < 1) {
    __builtin_debug(6, "", 1);
    return 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:32");
  perm = calloc(n, sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:33");
  perm1 = calloc(n, sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:34");
  count = calloc(n, sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:36");
  for (__builtin_debug(6, "", 1), i = 0;
       i < n;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    perm1[i] = i;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:38");
  r = n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:39");
  didpr = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:40");
  flipsMax = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:41");
  for (/*nothing*/; 1; /*nothing*/) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fannkuch.c:42");
    if (didpr < 30) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:43");
      for (__builtin_debug(6, "", 1), i = 0;
           i < n;
           __builtin_debug(6, "", 1), ++i) {
        __builtin_debug(6, "", 1);
        printf("%d", (int) (1 + perm1[i]));
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:44");
      printf("\n");
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:45");
      ++didpr;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fannkuch.c:47");
    for (/*nothing*/; r != 1; __builtin_debug(6, "", 1), --r) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:48");
      count[r - 1] = r;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fannkuch.c:53");
    if (!(perm1[0] == 0 || perm1[n1] == n1)) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:54");
      flips = 0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:55");
      for (__builtin_debug(6, "", 1), i = 1;
           i < n;
           __builtin_debug(6, "", 1), ++i) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fannkuch.c:56");
        perm[i] = perm1[i];
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:58");
      k = perm1[0];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:59");
      do {
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:fannkuch.c:60");
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:fannkuch.c:61");
        for (__builtin_debug(6, "", 1, 3), (i = 1, j = k - 1);
             i < j;
             __builtin_debug(6, "", 1, 3), (++i, --j)) {
          __builtin_debug(6, "", 1, 3, 4);
          __builtin_debug(1, "#line:fannkuch.c:62");
          __builtin_debug(6, "", 1, 3, 4);
          t_mp = perm[i];
          __builtin_debug(6, "", 1, 3, 4);
          perm[i] = perm[j];
          __builtin_debug(6, "", 1, 3, 4);
          perm[j] = t_mp;
        }
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:fannkuch.c:64");
        ++flips;
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:fannkuch.c:69");
        j = perm[k];
        __builtin_debug(6, "", 1, 3);
        perm[k] = k;
        __builtin_debug(6, "", 1, 3);
        k = j;
      } while(k);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:71");
      if (flipsMax < flips) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fannkuch.c:72");
        flipsMax = flips;
      }
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fannkuch.c:76");
    for (/*nothing*/; 1; /*nothing*/) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:77");
      if (r == n) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fannkuch.c:78");
        return flipsMax;
      }
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:fannkuch.c:82");
      perm0 = perm1[0];
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:fannkuch.c:83");
      i = 0;
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:fannkuch.c:84");
      while (i < r) {
        __builtin_debug(6, "", 1, 2);
        __builtin_debug(1, "#line:fannkuch.c:85");
        k = i + 1;
        __builtin_debug(6, "", 1, 2);
        __builtin_debug(1, "#line:fannkuch.c:86");
        perm1[i] = perm1[k];
        __builtin_debug(6, "", 1, 2);
        __builtin_debug(1, "#line:fannkuch.c:87");
        i = k;
      }
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:fannkuch.c:89");
      perm1[r] = perm0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:91");
      if ((count[r] -= 1) > 0) {
        break;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fannkuch.c:94");
      ++r;
    }
  }
}

int main(int argc, char * * argv)
{
  int n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:101");
  n = argc > 1 ? atoi(argv[1]) : 11;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:102");
  printf("Pfannkuchen(%d) = %ld\n", n, fannkuch_586(n));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fannkuch.c:103");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


