unsigned int nsieve_664(unsigned int);

void test_671(unsigned int);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_ee02e0e7debf7080d27dbfa74246cc661[22] = "Primes up to %8u %8u\012";

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

extern void exit(int);

extern void *memset(void *, int, unsigned int);

unsigned int nsieve_664(unsigned int m)
{
  unsigned int count;
  unsigned int i;
  unsigned int j;
  unsigned int *a;
  register void *$163;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:19"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:20"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:21"();
  $163 = malloc(m / (8 * sizeof(unsigned int)) * sizeof(unsigned int));
  a = $163;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:22"();
  memset
    (a, (1 << 8) - 1, m / (8 * sizeof(unsigned int)) * sizeof(unsigned int));
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:23"();
  count = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:24"();
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
    builtin debug1 "#line:nsievebits.c:25"();
    if (*(a + i / (8 * sizeof(unsigned int)))
          & 1 << i % (8 * sizeof(unsigned int))) {
      builtin debug6 ""(1);
      builtin debug1 "#line:nsievebits.c:26"();
      builtin debug6 ""(1);
      j = i + i;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           j = j + i) {
        if (! (j < m)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:nsievebits.c:27"();
        *(a + j / (8 * sizeof(unsigned int))) =
          *(a + j / (8 * sizeof(unsigned int)))
            & ~(1 << j % (8 * sizeof(unsigned int)));
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:nsievebits.c:28"();
      count = count + 1;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:30"();
  return count;
}

void test_671(unsigned int n)
{
  unsigned int count;
  unsigned int m;
  int i;
  register unsigned int $163;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:38"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:39"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:41"();
  m = (1 << n) * 10000;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:42"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 10)) {
      break;
    }
    builtin debug6 ""(1);
    $163 = nsieve_664(m);
    count = $163;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:43"();
  printf(__stringlit_ee02e0e7debf7080d27dbfa74246cc661, m, count);
}

int main(int ac, /*signed*/ char **av)
{
  unsigned int n;
  register int $164;
  register int $163;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:49"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:51"();
  if (ac < 2) {
    $163 = (int) 9;
  } else {
    $164 = atoi(*(av + 1));
    $163 = (int) $164;
  }
  n = $163;
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:52"();
  test_671(n);
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:53"();
  if (n >= 1) {
    builtin debug6 ""(1);
    builtin debug1 "#line:nsievebits.c:54"();
    test_671(n - 1);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:55"();
  if (n >= 2) {
    builtin debug6 ""(1);
    builtin debug1 "#line:nsievebits.c:56"();
    test_671(n - 2);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nsievebits.c:57"();
  exit(0);
  builtin debug6 ""();
  return 0;
}


