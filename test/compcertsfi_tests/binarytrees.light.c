struct tn;
struct tn {
  struct tn *left;
  struct tn *right;
  int item;
};

struct tn *NewTreeNode(struct tn *, struct tn *, int);

int ItemCheck(struct tn *);

struct tn *BottomUpTree(int, unsigned int);

void DeleteTree(struct tn *);

int main(int, /*signed*/ char **);

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
  register void *$198;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:24"();
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:26"();
  $198 = malloc(sizeof(struct tn));
  new = (struct tn *) $198;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:28"();
  (*new).left = left;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:29"();
  (*new).right = right;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:30"();
  (*new).item = item;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:32"();
  return new;
}

int ItemCheck(struct tn *tree)
{
  register int $199;
  register int $198;
  builtin debug6 ""();
  builtin debug1 "#line:binarytrees.c:38"();
  if ((*tree).left == (void *) 0) {
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:39"();
    return (*tree).item;
  } else {
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:41"();
    $198 = ItemCheck((*tree).left);
    $199 = ItemCheck((*tree).right);
    return (*tree).item + $198 - $199;
  }
}

struct tn *BottomUpTree(int item, unsigned int depth)
{
  register struct tn *$201;
  register struct tn *$200;
  register struct tn *$199;
  register struct tn *$198;
  builtin debug6 ""();
  builtin debug1 "#line:binarytrees.c:47"();
  if (depth > 0) {
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:48"();
    $198 = BottomUpTree(2 * item - 1, depth - 1);
    $199 = BottomUpTree(2 * item, depth - 1);
    $200 = NewTreeNode($198, $199, item);
    return $200;
  } else {
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:55"();
    $201 = NewTreeNode((void *) 0, (void *) 0, item);
    return $201;
  }
}

void DeleteTree(struct tn *tree)
{
  builtin debug6 ""();
  builtin debug1 "#line:binarytrees.c:61"();
  if ((*tree).left != (void *) 0) {
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:63"();
    DeleteTree((*tree).left);
    builtin debug6 ""();
    builtin debug1 "#line:binarytrees.c:64"();
    DeleteTree((*tree).right);
  }
  builtin debug6 ""();
  builtin debug1 "#line:binarytrees.c:67"();
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
  register int $208;
  register int $207;
  register struct tn *$206;
  register int $205;
  register struct tn *$204;
  register double $203;
  register struct tn *$202;
  register int $201;
  register struct tn *$200;
  register int $199;
  register int $198;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:73"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:74"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:76"();
  if (argc < 2) {
    $198 = (int) 16;
  } else {
    $199 = atol(*(argv + 1));
    $198 = (int) $199;
  }
  N = $198;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:78"();
  minDepth = 4;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:80"();
  if (minDepth + 2 > N) {
    builtin debug6 ""(1);
    builtin debug1 "#line:binarytrees.c:81"();
    maxDepth = minDepth + 2;
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:binarytrees.c:83"();
    maxDepth = N;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:85"();
  stretchDepth = maxDepth + 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:87"();
  $200 = BottomUpTree(0, stretchDepth);
  stretchTree = $200;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:88"();
  $201 = ItemCheck(stretchTree);
  printf(__stringlit_72c9c24e98c1b3111062265c67e28e2e1, stretchDepth, $201);
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:95"();
  DeleteTree(stretchTree);
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:97"();
  $202 = BottomUpTree(0, maxDepth);
  longLivedTree = $202;
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:99"();
  builtin debug6 ""(1);
  depth = minDepth;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       depth = depth + 2) {
    if (! (depth <= maxDepth)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:binarytrees.c:101"();
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:binarytrees.c:103"();
    $203 = pow(2, maxDepth - depth + minDepth);
    iterations = $203;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:binarytrees.c:105"();
    check = 0;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:binarytrees.c:107"();
    builtin debug6 ""(1, 2);
    i = 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
         i = i + 1) {
      if (! (i <= iterations)) {
        break;
      }
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:109"();
      $204 = BottomUpTree(i, depth);
      tempTree = $204;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:110"();
      $205 = ItemCheck(tempTree);
      check = check + $205;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:111"();
      DeleteTree(tempTree);
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:113"();
      $206 = BottomUpTree(-i, depth);
      tempTree = $206;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:114"();
      $207 = ItemCheck(tempTree);
      check = check + $207;
      builtin debug6 ""(1, 2);
      builtin debug1 "#line:binarytrees.c:115"();
      DeleteTree(tempTree);
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:binarytrees.c:118"();
    printf
      (__stringlit_72c9c24e98c1b3111062265c67e28e2e2, iterations * 2, 
       depth, check);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:127"();
  $208 = ItemCheck(longLivedTree);
  printf(__stringlit_72c9c24e98c1b3111062265c67e28e2e3, maxDepth, $208);
  builtin debug6 ""(1);
  builtin debug1 "#line:binarytrees.c:134"();
  return 0;
  builtin debug6 ""();
  return 0;
}


