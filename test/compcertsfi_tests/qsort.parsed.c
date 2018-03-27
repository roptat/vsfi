extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int atoi(char const * __nptr);

extern int rand(void);

extern void * malloc(size_t __size);

typedef int (* __compar_fn_t)(void const * , void const * );

extern void qsort(void * __base, size_t __nmemb, size_t __size,
                  __compar_fn_t __compar);

extern int printf(char const * __format, ...);

void quicksort(int lo, int hi, int * base)
{
  int i;
  int j;
  int pivot;
  int temp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:7");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:8");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:10");
  if (lo < hi) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:11");
    for (__builtin_debug(6, "", 1), (i = lo, j = hi, pivot = base[hi]);
         i < j;
         /*nothing*/) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:12");
      while (i < hi && base[i] <= pivot) {
        __builtin_debug(6, "", 1);
        i++;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:13");
      while (j > lo && base[j] >= pivot) {
        __builtin_debug(6, "", 1);
        j--;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:14");
      if (i < j) {
        __builtin_debug(6, "", 1);
        temp = base[i];
        __builtin_debug(6, "", 1);
        base[i] = base[j];
        __builtin_debug(6, "", 1);
        base[j] = temp;
      }
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:16");
    temp = base[i];
    __builtin_debug(6, "", 1);
    base[i] = base[hi];
    __builtin_debug(6, "", 1);
    base[hi] = temp;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:17");
    quicksort(lo, i - 1, base);
    __builtin_debug(6, "", 1);
    quicksort(i + 1, hi, base);
  }
}

int cmpint(void const * i, void const * j)
{
  int vi;
  int vj;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:23");
  vi = *((int *) i);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:24");
  vj = *((int *) j);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:25");
  if (vi == vj) {
    __builtin_debug(6, "", 1);
    return 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:26");
  if (vi < vj) {
    __builtin_debug(6, "", 1);
    return -1;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:27");
  return 1;
}

int main(int argc, char * * argv)
{
  int n;
  int i;
  int j;
  int * a;
  int * b;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:34");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:35");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:37");
  if (argc >= 2) {
    __builtin_debug(6, "", 1);
    n = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    n = 100000;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:38");
  a = malloc(n * sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:39");
  b = malloc(n * sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:40");
  for (__builtin_debug(6, "", 1), j = 0;
       j < 100;
       __builtin_debug(6, "", 1), j++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:41");
    for (__builtin_debug(6, "", 1), i = 0;
         i < n;
         __builtin_debug(6, "", 1), i++) {
      __builtin_debug(6, "", 1);
      b[i] = a[i] = rand() & 0xFFFF;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:42");
    quicksort(0, n - 1, a);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:44");
  qsort(b, n, sizeof(int), cmpint);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:45");
  for (__builtin_debug(6, "", 1), i = 0;
       i < n;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:qsort.c:46");
    if (a[i] != b[i]) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:47");
      printf("Bug!\n");
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:48");
      printf("a[%d]=%d\nb[%d]=%d\n", i, a[i], i, b[i]);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:qsort.c:49");
      return 2;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:52");
  printf("OK\n");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:qsort.c:53");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


