struct list;
struct list {
  int hd;
  struct list *tl;
};

static /*signed*/ char const __stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32[4];

static /*signed*/ char const __stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31[6];

extern unsigned int keep[2];

extern struct list *buildlist(int);

extern struct list *reverselist(struct list *);

extern struct list *reverse_inplace(struct list *);

extern int checklist(int, struct list *);

extern int main(int, /*signed*/ char **);

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
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:11");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:12");
  if (n < 0) {
    __builtin_debug(6,"", 1);
    return (void *) 0;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:13");
  r = malloc(sizeof(struct list));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:14");
  ((*r)).hd = n;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:15");
  ((*r)).tl = buildlist(n - 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:16");
  return r;
}

struct list *reverselist(struct list *l)
{
  struct list *r;
  struct list *r2;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:21");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:22");
  for (__builtin_debug(6,"", 1), r = (void *) 0;
       l != (void *) 0;
       __builtin_debug(6,"", 1), l = ((*l)).tl) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:23");
    r2 = malloc(sizeof(struct list));
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:24");
    ((*r2)).hd = ((*l)).hd;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:25");
    ((*r2)).tl = r;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:26");
    r = r2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:28");
  return r;
}

struct list *reverse_inplace(struct list *l)
{
  struct list *prev;
  struct list *next;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:33");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:35");
  prev = (void *) 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:36");
  while (l != (void *) 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:37");
    next = ((*l)).tl;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:38");
    ((*l)).tl = prev;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:39");
    prev = l;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:40");
    l = next;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:42");
  return prev;
}

int checklist(int n, struct list *l)
{
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:47");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:48");
  for (__builtin_debug(6,"", 1), i = 0;
       i <= n;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:49");
    if (l == (void *) 0) {
      __builtin_debug(6,"", 1);
      return 0;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:50");
    if (((*l)).hd != i) {
      __builtin_debug(6,"", 1);
      return 0;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:51");
    l = ((*l)).tl;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:53");
  return l == (void *) 0;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int niter;
  int i;
  struct list *l;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:58");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:59");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:61");
  if (argc >= 2) {
    __builtin_debug(6,"", 1);
    n = atoi(*(argv + 1));
  } else {
    __builtin_debug(6,"", 1);
    n = 1000;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:62");
  if (argc >= 3) {
    __builtin_debug(6,"", 1);
    niter = atoi(*(argv + 1));
  } else {
    __builtin_debug(6,"", 1);
    niter = 200000;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:63");
  l = buildlist(n);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:64");
  if (checklist(n, reverselist(l))) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:65");
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32);
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:67");
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:68");
    return 2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:70");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 2 * niter + 1;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:71");
    l = reverse_inplace(l);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:73");
  if (checklist(n, l)) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:74");
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb32);
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:76");
    printf(__stringlit_d68c8d42f45fa3fbb7d4722bfd48deb31);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:lists.c:77");
    return 2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:lists.c:79");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


