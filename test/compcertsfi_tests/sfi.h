// sfi header file

#ifndef __SFI__
#define __SFI__
#include <stdint.h>
// Dummy comparison function to be used by i.e., qsort, bsearch
extern int dummy$compare(uintptr_t i,uintptr_t j);

// Dummy doit function to be used by i.e., atexit
extern void dummy$doit(void);

// To keep the previous definitions
uintptr_t keep[2]={(uintptr_t)&dummy$compare,(uintptr_t)&dummy$doit};

#endif
