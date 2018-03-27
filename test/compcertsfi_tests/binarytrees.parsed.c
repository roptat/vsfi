extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern double pow(double __x, double __y);

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern long atol(char const * __nptr);

extern void * malloc(size_t __size);

extern void free(void * __ptr);

struct tn;

struct tn {
  struct tn * left;
  struct tn * right;
  long item;
};

typedef struct tn treeNode;

treeNode * NewTreeNode(treeNode * left, treeNode * right, long item)
{
  treeNode * new;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:24");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:26");
  new = (treeNode *) malloc(sizeof(treeNode));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:28");
  new->left = left;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:29");
  new->right = right;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:30");
  new->item = item;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:32");
  return new;
}

long ItemCheck(treeNode * tree)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:binarytrees.c:38");
  if (tree->left == (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:39");
    return tree->item;
  } else {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:41");
    return tree->item + ItemCheck(tree->left) - ItemCheck(tree->right);
  }
}

treeNode * BottomUpTree(long item, unsigned int depth)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:binarytrees.c:47");
  if (depth > 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:48");
    return NewTreeNode(BottomUpTree(2 * item - 1, depth - 1),
                       BottomUpTree(2 * item, depth - 1), item);
  } else {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:55");
    return NewTreeNode((void *) 0, (void *) 0, item);
  }
}

void DeleteTree(treeNode * tree)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:binarytrees.c:61");
  if (tree->left != (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:63");
    DeleteTree(tree->left);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:binarytrees.c:64");
    DeleteTree(tree->right);
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:binarytrees.c:67");
  free(tree);
}

int main(int argc, char * * argv)
{
  unsigned int N;
  unsigned int depth;
  unsigned int minDepth;
  unsigned int maxDepth;
  unsigned int stretchDepth;
  treeNode * stretchTree;
  treeNode * longLivedTree;
  treeNode * tempTree;
  long i;
  long iterations;
  long check;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:73");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:74");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:76");
  N = argc < 2 ? 16 : atol(argv[1]);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:78");
  minDepth = 4;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:80");
  if (minDepth + 2 > N) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:binarytrees.c:81");
    maxDepth = minDepth + 2;
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:binarytrees.c:83");
    maxDepth = N;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:85");
  stretchDepth = maxDepth + 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:87");
  stretchTree = BottomUpTree(0, stretchDepth);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:88");
  printf("stretch tree of depth %u\t check: %li\n", stretchDepth,
         ItemCheck(stretchTree));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:95");
  DeleteTree(stretchTree);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:97");
  longLivedTree = BottomUpTree(0, maxDepth);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:99");
  for (__builtin_debug(6, "", 1), depth = minDepth;
       depth <= maxDepth;
       __builtin_debug(6, "", 1), depth += 2) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:binarytrees.c:101");
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:binarytrees.c:103");
    iterations = pow(2, maxDepth - depth + minDepth);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:binarytrees.c:105");
    check = 0;
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:binarytrees.c:107");
    for (__builtin_debug(6, "", 1, 2), i = 1;
         i <= iterations;
         __builtin_debug(6, "", 1, 2), i++) {
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:109");
      tempTree = BottomUpTree(i, depth);
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:110");
      check += ItemCheck(tempTree);
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:111");
      DeleteTree(tempTree);
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:113");
      tempTree = BottomUpTree(-i, depth);
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:114");
      check += ItemCheck(tempTree);
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:binarytrees.c:115");
      DeleteTree(tempTree);
    }
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:binarytrees.c:118");
    printf("%li\t trees of depth %u\t check: %li\n", iterations * 2, 
           depth, check);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:127");
  printf("long lived tree of depth %u\t check: %li\n", maxDepth,
         ItemCheck(longLivedTree));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:binarytrees.c:134");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


