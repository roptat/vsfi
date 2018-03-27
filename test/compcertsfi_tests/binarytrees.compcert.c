struct tn;
struct tn {
  struct tn *left;
  struct tn *right;
  int item;
};

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e3[41];

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e1[38];

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e2[36];

extern unsigned int keep[2];

extern struct tn *NewTreeNode(struct tn *, struct tn *, int);

extern int ItemCheck(struct tn *);

extern struct tn *BottomUpTree(int, unsigned int);

extern void DeleteTree(struct tn *);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e3[41] = "long lived tree of depth %u\011 check: %li\012";

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e1[38] = "stretch tree of depth %u\011 check: %li\012";

static /*signed*/ char const __stringlit_72c9c24e98c1b3111062265c67e28e2e2[36] = "%li\011 trees of depth %u\011 check: %li\012";

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

extern double pow(double, double);

extern int printf(/*signed*/ char *, ...);

extern int atol(/*signed*/ char *);

extern void *malloc(unsigned int);

extern void free(void *);

struct tn *NewTreeNode(struct tn *left, struct tn *right, int item)
{
  struct tn *new;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:24");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:26");
  new = (struct tn *) malloc(sizeof(struct tn));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:28");
  ((*new)).left = left;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:29");
  ((*new)).right = right;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:30");
  ((*new)).item = item;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:32");
  return new;
}

int ItemCheck(struct tn *tree)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:binarytrees.c:38");
  if (((*tree)).left == (void *) 0) {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:39");
    return ((*tree)).item;
  } else {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:41");
    return ((*tree)).item + ItemCheck(((*tree)).left)
             - ItemCheck(((*tree)).right);
  }
}

struct tn *BottomUpTree(int item, unsigned int depth)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:binarytrees.c:47");
  if (depth > 0) {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:48");
    return NewTreeNode(BottomUpTree(2 * item - 1, depth - 1),
                       BottomUpTree(2 * item, depth - 1), item);
  } else {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:55");
    return NewTreeNode((void *) 0, (void *) 0, item);
  }
}

void DeleteTree(struct tn *tree)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:binarytrees.c:61");
  if (((*tree)).left != (void *) 0) {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:63");
    DeleteTree(((*tree)).left);
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:binarytrees.c:64");
    DeleteTree(((*tree)).right);
  }
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:binarytrees.c:67");
  free(tree);
}

int main(int argc, /*signed*/ char **argv)
{
  unsigned int N;
  unsigned int depth;
  unsigned int minDepth;
  unsigned int maxDepth;
  unsigned int stretchDepth;
  struct tn *stretchTree;
  struct tn *longLivedTree;
  struct tn *tempTree;
  int i;
  int iterations;
  int check;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:73");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:74");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:76");
  N = argc < 2 ? 16 : atol(*(argv + 1));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:78");
  minDepth = 4;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:80");
  if (minDepth + 2 > N) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:binarytrees.c:81");
    maxDepth = minDepth + 2;
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:binarytrees.c:83");
    maxDepth = N;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:85");
  stretchDepth = maxDepth + 1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:87");
  stretchTree = BottomUpTree(0, stretchDepth);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:88");
  printf(__stringlit_72c9c24e98c1b3111062265c67e28e2e1, stretchDepth,
         ItemCheck(stretchTree));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:95");
  DeleteTree(stretchTree);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:97");
  longLivedTree = BottomUpTree(0, maxDepth);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:99");
  for (__builtin_debug(6,"", 1), depth = minDepth;
       depth <= maxDepth;
       __builtin_debug(6,"", 1), depth += 2) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:binarytrees.c:101");
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:binarytrees.c:103");
    iterations = pow(2, maxDepth - depth + minDepth);
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:binarytrees.c:105");
    check = 0;
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:binarytrees.c:107");
    for (__builtin_debug(6,"", 1, 2), i = 1;
         i <= iterations;
         __builtin_debug(6,"", 1, 2), i++) {
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:109");
      tempTree = BottomUpTree(i, depth);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:110");
      check += ItemCheck(tempTree);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:111");
      DeleteTree(tempTree);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:113");
      tempTree = BottomUpTree(-i, depth);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:114");
      check += ItemCheck(tempTree);
      __builtin_debug(6,"", 1, 2);
      __builtin_debug(1,"#line:binarytrees.c:115");
      DeleteTree(tempTree);
    }
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:binarytrees.c:118");
    printf(__stringlit_72c9c24e98c1b3111062265c67e28e2e2, iterations * 2,
           depth, check);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:127");
  printf(__stringlit_72c9c24e98c1b3111062265c67e28e2e3, maxDepth,
         ItemCheck(longLivedTree));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:binarytrees.c:134");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


