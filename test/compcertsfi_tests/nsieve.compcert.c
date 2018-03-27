static /*signed*/ char const __stringlit_b28c8655e524e38bf7d1c70b2d134d3c1[22];

extern unsigned int keep[2];

static unsigned int nsieve_664(int);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_b28c8655e524e38bf7d1c70b2d134d3c1[22] = "Primes up to %8d %8u\012";

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

extern void *memset(void *, int, unsigned int);

unsigned int nsieve_664(int m)
{
  unsigned int count;
  unsigned int i;
  unsigned int j;
  unsigned char *flags;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:14");
  count = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:15");
  flags = (unsigned char *) malloc(m * sizeof(unsigned char));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:16");
  memset(flags, 1, m);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:18");
  for (__builtin_debug(6,"", 1), i = 2;
       i < m;
       __builtin_debug(6,"", 1), i += 1) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:nsieve.c:19");
    if (*(flags + i)) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:nsieve.c:20");
      count += 1;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:nsieve.c:21");
      for (__builtin_debug(6,"", 1), j = i << 1;
           j < m;
           __builtin_debug(6,"", 1), j += i) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:nsieve.c:22");
        if (*(flags + j)) {
          __builtin_debug(6,"", 1);
          *(flags + j) = 0;
        }
      }
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:25");
  free(flags);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:26");
  return count;
}

int main(int argc, /*signed*/ char **argv)
{
  int m;
  int i;
  int j;
  int n;
  unsigned int count;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:32");
  m = argc < 2 ? 9 : atoi(*(argv + 1));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:33");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:34");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 3;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:nsieve.c:35");
    n = 10000 << m - i;
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:nsieve.c:36");
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:nsieve.c:37");
    for (__builtin_debug(6,"", 1, 2), j = 0;
         j < 1;
         __builtin_debug(6,"", 1, 2), j++) {
      __builtin_debug(6,"", 1, 2);
      count = nsieve_664(n);
    }
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:nsieve.c:38");
    printf(__stringlit_b28c8655e524e38bf7d1c70b2d134d3c1, n, count);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:nsieve.c:40");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


