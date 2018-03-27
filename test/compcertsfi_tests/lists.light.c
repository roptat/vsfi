struct list;
struct list {
  int hd;
  struct list *tl;
};

struct list *buildlist(int);

struct list *reverselist(struct list *);

struct list *reverse_inplace(struct list *);

int checklist(int, struct list *);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32[4] = "OK\012";

static /*signed*/ char const __stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31[6] = "Bug!\012";

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

struct list *buildlist(int n)
{
  struct list *r;
  register struct list *$182;
  register void *$181;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:11"();
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:12"();
  if (n < 0) {
    builtin debug6 ""(1);
    return (void *) 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:13"();
  $181 = malloc(sizeof(struct list));
  r = $181;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:14"();
  (*r).hd = n;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:15"();
  $182 = buildlist(n - 1);
  (*r).tl = $182;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:16"();
  return r;
}

struct list *reverselist(struct list *l)
{
  struct list *r;
  struct list *r2;
  register void *$181;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:21"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:22"();
  builtin debug6 ""(1);
  r = (void *) 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       l = (*l).tl) {
    if (! (l != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:23"();
    $181 = malloc(sizeof(struct list));
    r2 = $181;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:24"();
    (*r2).hd = (*l).hd;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:25"();
    (*r2).tl = r;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:26"();
    r = r2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:28"();
  return r;
}

struct list *reverse_inplace(struct list *l)
{
  struct list *prev;
  struct list *next;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:33"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:35"();
  prev = (void *) 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:36"();
  while (1) {
    if (! (l != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:37"();
    next = (*l).tl;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:38"();
    (*l).tl = prev;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:39"();
    prev = l;
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:40"();
    l = next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:42"();
  return prev;
}

int checklist(int n, struct list *l)
{
  int i;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:47"();
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:48"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i <= n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:49"();
    if (l == (void *) 0) {
      builtin debug6 ""(1);
      return 0;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:50"();
    if ((*l).hd != i) {
      builtin debug6 ""(1);
      return 0;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:51"();
    l = (*l).tl;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:53"();
  return l == (void *) 0;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int niter;
  int i;
  struct list *l;
  register int $187;
  register struct list *$186;
  register int $185;
  register struct list *$184;
  register struct list *$183;
  register int $182;
  register int $181;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:58"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:59"();
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:61"();
  if (argc >= 2) {
    builtin debug6 ""(1);
    $181 = atoi(*(argv + 1));
    n = $181;
  } else {
    builtin debug6 ""(1);
    n = 1000;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:62"();
  if (argc >= 3) {
    builtin debug6 ""(1);
    $182 = atoi(*(argv + 1));
    niter = $182;
  } else {
    builtin debug6 ""(1);
    niter = 200000;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:63"();
  $183 = buildlist(n);
  l = $183;
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:64"();
  $184 = reverselist(l);
  $185 = checklist(n, $184);
  if ($185) {
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:65"();
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32);
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:67"();
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31);
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:68"();
    return 2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:70"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 2 * niter + 1)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:71"();
    $186 = reverse_inplace(l);
    l = $186;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:73"();
  $187 = checklist(n, l);
  if ($187) {
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:74"();
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32);
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:76"();
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31);
    builtin debug6 ""(1);
    builtin debug1 "#line:lists.c:77"();
    return 2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:lists.c:79"();
  return 0;
  builtin debug6 ""();
  return 0;
}


