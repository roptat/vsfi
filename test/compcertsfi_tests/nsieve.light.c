unsigned int nsieve_664(int);

int main(int, /*signed*/ char **);

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
  register void *$156;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:14"();
  count = 0;
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:15"();
  $156 = malloc(m * sizeof(unsigned char));
  flags = (unsigned char *) $156;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:16"();
  memset(flags, 1, m);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:18"();
  builtin debug6 ""(1);
  i = 2;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < m)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:nsieve.c:19"();
    if (*(flags + i)) {
      builtin debug6 ""(1);
      builtin debug1 "#line:nsieve.c:20"();
      count = count + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:nsieve.c:21"();
      builtin debug6 ""(1);
      j = i << 1;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           j = j + i) {
        if (! (j < m)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:nsieve.c:22"();
        if (*(flags + j)) {
          builtin debug6 ""(1);
          *(flags + j) = 0;
        }
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:25"();
  free(flags);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:26"();
  return count;
}

int main(int argc, /*signed*/ char **argv)
{
  int m;
  int i;
  int j;
  int n;
  unsigned int count;
  register unsigned int $158;
  register int $157;
  register int $156;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:32"();
  if (argc < 2) {
    $156 = (int) 9;
  } else {
    $157 = atoi(*(argv + 1));
    $156 = (int) $157;
  }
  m = $156;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:33"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:34"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 3)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nsieve.c:35"();
    n = 10000 << m - i;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nsieve.c:36"();
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nsieve.c:37"();
    builtin debug6 ""(1, 2);
    j = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < 1)) {
        break;
      }
      builtin debug6 ""(1, 2);
      $158 = nsieve_664(n);
      count = $158;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nsieve.c:38"();
    printf(__stringlit_b28c8655e524e38bf7d1c70b2d134d3c1, n, count);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsieve.c:40"();
  return 0;
  builtin debug6 ""();
  return 0;
}


