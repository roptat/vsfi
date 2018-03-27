extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

extern void * malloc(size_t __size);

struct list;

struct list {
  int hd;
  struct list * tl;
};

struct list * buildlist(int n)
{
  struct list * r;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:11");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:12");
  if (n < 0) {
    __builtin_debug(6, "", 1);
    return (void *) 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:13");
  r = malloc(sizeof(struct list));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:14");
  r->hd = n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:15");
  r->tl = buildlist(n - 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:16");
  return r;
}

struct list * reverselist(struct list * l)
{
  struct list * r;
  struct list * r2;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:21");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:22");
  for (__builtin_debug(6, "", 1), r = (void *) 0;
       l != (void *) 0;
       __builtin_debug(6, "", 1), l = l->tl) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:23");
    r2 = malloc(sizeof(struct list));
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:24");
    r2->hd = l->hd;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:25");
    r2->tl = r;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:26");
    r = r2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:28");
  return r;
}

struct list * reverse_inplace(struct list * l)
{
  struct list * prev;
  struct list * next;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:33");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:35");
  prev = (void *) 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:36");
  while (l != (void *) 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:37");
    next = l->tl;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:38");
    l->tl = prev;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:39");
    prev = l;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:40");
    l = next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:42");
  return prev;
}

int checklist(int n, struct list * l)
{
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:47");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:48");
  for (__builtin_debug(6, "", 1), i = 0;
       i <= n;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:49");
    if (l == (void *) 0) {
      __builtin_debug(6, "", 1);
      return 0;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:50");
    if (l->hd != i) {
      __builtin_debug(6, "", 1);
      return 0;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:51");
    l = l->tl;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:53");
  return l == (void *) 0;
}

int main(int argc, char * * argv)
{
  int n;
  int niter;
  int i;
  struct list * l;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:58");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:59");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:61");
  if (argc >= 2) {
    __builtin_debug(6, "", 1);
    n = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    n = 1000;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:62");
  if (argc >= 3) {
    __builtin_debug(6, "", 1);
    niter = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    niter = 200000;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:63");
  l = buildlist(n);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:64");
  if (checklist(n, reverselist(l))) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:65");
    printf("OK\n");
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:67");
    printf("Bug!\n");
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:68");
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:70");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 2 * niter + 1;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:71");
    l = reverse_inplace(l);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:73");
  if (checklist(n, l)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:74");
    printf("OK\n");
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:76");
    printf("Bug!\n");
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:lists.c:77");
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:lists.c:79");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


