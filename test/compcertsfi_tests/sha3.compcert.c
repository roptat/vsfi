struct _s6d5441d9a540c41662b165018d076b82;
struct _s6d5441d9a540c41662b165018d076b82 {
  int mdlen;
  /*signed*/ char *msgstr;
  unsigned char md[64];
};

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe864[21];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe866[7];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe861[21];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe867[13];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe863[21];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe862[21];

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe865[7];

extern unsigned int keep[2];

extern unsigned long long const keccakf_rndc[24];

extern int const keccakf_rotc[24];

extern int const keccakf_piln[24];

extern void keccakf(unsigned long long *);

static unsigned long long get64le_559(unsigned char *);

static void set64le_565(unsigned char *, unsigned long long);

extern void keccak(unsigned char *, int, unsigned char *, int);

extern struct _s6d5441d9a540c41662b165018d076b82 testvec[4];

static unsigned char data_583[100000];

extern int main(void);

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe864[21] = "Keccak-224 Test Hash";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe866[7] = "passed";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe861[21] = "Keccak-512 Test Hash";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe867[13] = "SHA-3 %d %s\012";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe863[21] = "Keccak-256 Test Hash";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe862[21] = "Keccak-384 Test Hash";

static /*signed*/ char const __stringlit_afbf45d2e089328b5dcb67d5f24dbe865[7] = "FAILED";

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

extern void *memcpy(void *, void *, unsigned int);

extern void *memset(void *, int, unsigned int);

extern int memcmp(void *, void *, unsigned int);

extern unsigned int strlen(/*signed*/ char *);

 unsigned long long const keccakf_rndc[24] = { 1LL, 32898LL,
  -9223372036854742902LL, -9223372034707259392LL, 32907LL, 2147483649LL,
  -9223372034707259263LL, -9223372036854743031LL, 138LL, 136LL, 2147516425LL,
  2147483658LL, 2147516555LL, -9223372036854775669LL, -9223372036854742903LL,
  -9223372036854743037LL, -9223372036854743038LL, -9223372036854775680LL,
  32778LL, -9223372034707292150LL, -9223372034707259263LL,
  -9223372036854742912LL, 2147483649LL, -9223372034707259384LL, };

 int const keccakf_rotc[24] = { 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14,
  27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44, };

 int const keccakf_piln[24] = { 10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4,
  15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1, };

void keccakf(unsigned long long *st)
{
  int j;
  int round;
  unsigned long long t;
  unsigned long long bc[5];
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:43");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:44");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:46");
  for (__builtin_debug(6,"", 1), round = 0;
       round < 24;
       __builtin_debug(6,"", 1), round++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:52");
    *(bc + 0) =
      *(st + 0) ^ *(st + (0 + 5)) ^ *(st + (0 + 10)) ^ *(st + (0 + 15))
        ^ *(st + (0 + 20));
    __builtin_debug(6,"", 1);
    *(bc + 1) =
      *(st + 1) ^ *(st + (1 + 5)) ^ *(st + (1 + 10)) ^ *(st + (1 + 15))
        ^ *(st + (1 + 20));
    __builtin_debug(6,"", 1);
    *(bc + 2) =
      *(st + 2) ^ *(st + (2 + 5)) ^ *(st + (2 + 10)) ^ *(st + (2 + 15))
        ^ *(st + (2 + 20));
    __builtin_debug(6,"", 1);
    *(bc + 3) =
      *(st + 3) ^ *(st + (3 + 5)) ^ *(st + (3 + 10)) ^ *(st + (3 + 15))
        ^ *(st + (3 + 20));
    __builtin_debug(6,"", 1);
    *(bc + 4) =
      *(st + 4) ^ *(st + (4 + 5)) ^ *(st + (4 + 10)) ^ *(st + (4 + 15))
        ^ *(st + (4 + 20));
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:62");
    t =
      *(bc + (0 + 4) % 5)
        ^ (*(bc + (0 + 1) % 5) << 1 | *(bc + (0 + 1) % 5) >> 64 - 1);
    __builtin_debug(6,"", 1);
    *(st + (0 + 0)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (5 + 0)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (10 + 0)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (15 + 0)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (20 + 0)) ^= t;
    __builtin_debug(6,"", 1);
    t =
      *(bc + (1 + 4) % 5)
        ^ (*(bc + (1 + 1) % 5) << 1 | *(bc + (1 + 1) % 5) >> 64 - 1);
    __builtin_debug(6,"", 1);
    *(st + (0 + 1)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (5 + 1)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (10 + 1)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (15 + 1)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (20 + 1)) ^= t;
    __builtin_debug(6,"", 1);
    t =
      *(bc + (2 + 4) % 5)
        ^ (*(bc + (2 + 1) % 5) << 1 | *(bc + (2 + 1) % 5) >> 64 - 1);
    __builtin_debug(6,"", 1);
    *(st + (0 + 2)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (5 + 2)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (10 + 2)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (15 + 2)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (20 + 2)) ^= t;
    __builtin_debug(6,"", 1);
    t =
      *(bc + (3 + 4) % 5)
        ^ (*(bc + (3 + 1) % 5) << 1 | *(bc + (3 + 1) % 5) >> 64 - 1);
    __builtin_debug(6,"", 1);
    *(st + (0 + 3)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (5 + 3)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (10 + 3)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (15 + 3)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (20 + 3)) ^= t;
    __builtin_debug(6,"", 1);
    t =
      *(bc + (4 + 4) % 5)
        ^ (*(bc + (4 + 1) % 5) << 1 | *(bc + (4 + 1) % 5) >> 64 - 1);
    __builtin_debug(6,"", 1);
    *(st + (0 + 4)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (5 + 4)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (10 + 4)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (15 + 4)) ^= t;
    __builtin_debug(6,"", 1);
    *(st + (20 + 4)) ^= t;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:73");
    t = *(st + 1);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:74");
    j = *(keccakf_piln + 0);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 1 | t >> 64 - 1;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 1);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 3 | t >> 64 - 3;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 2);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 6 | t >> 64 - 6;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 3);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 10 | t >> 64 - 10;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:75");
    j = *(keccakf_piln + 4);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 15 | t >> 64 - 15;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 5);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 21 | t >> 64 - 21;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 6);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 28 | t >> 64 - 28;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 7);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 36 | t >> 64 - 36;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:76");
    j = *(keccakf_piln + 8);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 45 | t >> 64 - 45;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 9);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 55 | t >> 64 - 55;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 10);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 2 | t >> 64 - 2;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 11);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 14 | t >> 64 - 14;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:77");
    j = *(keccakf_piln + 12);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 27 | t >> 64 - 27;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 13);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 41 | t >> 64 - 41;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 14);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 56 | t >> 64 - 56;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 15);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 8 | t >> 64 - 8;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:78");
    j = *(keccakf_piln + 16);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 25 | t >> 64 - 25;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 17);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 43 | t >> 64 - 43;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 18);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 62 | t >> 64 - 62;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 19);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 18 | t >> 64 - 18;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:79");
    j = *(keccakf_piln + 20);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 39 | t >> 64 - 39;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 21);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 61 | t >> 64 - 61;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 22);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 20 | t >> 64 - 20;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    j = *(keccakf_piln + 23);
    __builtin_debug(6,"", 1);
    *(bc + 0) = *(st + j);
    __builtin_debug(6,"", 1);
    *(st + j) = t << 44 | t >> 64 - 44;
    __builtin_debug(6,"", 1);
    t = *(bc + 0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:88");
    for (__builtin_debug(6,"", 1), j = 0;
         j < 25;
         __builtin_debug(6,"", 1), j += 5) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha3.c:89");
      *(bc + 0) = *(st + (j + 0));
      __builtin_debug(6,"", 1);
      *(bc + 1) = *(st + (j + 1));
      __builtin_debug(6,"", 1);
      *(bc + 2) = *(st + (j + 2));
      __builtin_debug(6,"", 1);
      *(bc + 3) = *(st + (j + 3));
      __builtin_debug(6,"", 1);
      *(bc + 4) = *(st + (j + 4));
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha3.c:90");
      *(st + (j + 0)) ^= ~*(bc + (0 + 1) % 5) & *(bc + (0 + 2) % 5);
      __builtin_debug(6,"", 1);
      *(st + (j + 1)) ^= ~*(bc + (1 + 1) % 5) & *(bc + (1 + 2) % 5);
      __builtin_debug(6,"", 1);
      *(st + (j + 2)) ^= ~*(bc + (2 + 1) % 5) & *(bc + (2 + 2) % 5);
      __builtin_debug(6,"", 1);
      *(st + (j + 3)) ^= ~*(bc + (3 + 1) % 5) & *(bc + (3 + 2) % 5);
      __builtin_debug(6,"", 1);
      *(st + (j + 4)) ^= ~*(bc + (4 + 1) % 5) & *(bc + (4 + 2) % 5);
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:94");
    *(st + 0) ^= *(keccakf_rndc + round);
  }
}

unsigned long long get64le_559(unsigned char *p)
{
  unsigned int l;
  unsigned int h;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:102");
  l = *(p + 0) | *(p + 1) << 8 | *(p + 2) << 16 | *(p + 3) << 24;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:103");
  h = *(p + 4) | *(p + 5) << 8 | *(p + 6) << 16 | *(p + 7) << 24;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:104");
  return l | (unsigned long long) h << 32;
}

void set64le_565(unsigned char *p, unsigned long long x)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha3.c:111");
  *(p + 0) = x;
  __builtin_debug(6,"");
  *(p + 1) = x >> 8;
  __builtin_debug(6,"");
  *(p + 2) = x >> 16;
  __builtin_debug(6,"");
  *(p + 3) = x >> 24;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha3.c:112");
  *(p + 4) = x >> 32;
  __builtin_debug(6,"");
  *(p + 5) = x >> 40;
  __builtin_debug(6,"");
  *(p + 6) = x >> 48;
  __builtin_debug(6,"");
  *(p + 7) = x >> 56;
}

void keccak(unsigned char *in, int inlen, unsigned char *md, int mdlen)
{
  unsigned long long st[25];
  unsigned char temp[144];
  int i;
  int rsiz;
  int rsizw;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:119");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:120");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:121");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:123");
  rsiz = 200 - 2 * mdlen;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:124");
  rsizw = rsiz / 8;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:126");
  memset(st, 0, sizeof(unsigned long long [25]));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:128");
  for (/*nothing*/;
       inlen >= rsiz;
       __builtin_debug(6,"", 1), inlen -= rsiz, in += rsiz) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:129");
    for (__builtin_debug(6,"", 1), i = 0;
         i < rsizw;
         __builtin_debug(6,"", 1), i++) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha3.c:130");
      *(st + i) ^= get64le_559(in + i * 8);
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:131");
    keccakf(st);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:135");
  memcpy(temp, in, inlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:136");
  *(temp + inlen++) = 1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:137");
  memset(temp + inlen, 0, rsiz - inlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:138");
  *(temp + (rsiz - 1)) |= 128;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:140");
  for (__builtin_debug(6,"", 1), i = 0;
       i < rsizw;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:141");
    *(st + i) ^= get64le_559(temp + i * 8);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:143");
  keccakf(st);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:145");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 8;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:146");
    set64le_565(temp + i * 8, *(st + i));
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:148");
  memcpy(md, temp, mdlen);
}

 struct _s6d5441d9a540c41662b165018d076b82 testvec[4] = { 28,
  &__stringlit_afbf45d2e089328b5dcb67d5f24dbe864, 48, 4, 91, 52, 148, 110,
  27, 46, 9, 22, 19, 54, 47, 210, 42, 160, 142, 43, 234, 254, 197, 232, 218,
  238, 66, 194, 230, 101, /* skip 36 */ 32,
  &__stringlit_afbf45d2e089328b5dcb67d5f24dbe863, 168, 215, 27, 7, 244, 175,
  38, 164, 255, 33, 2, 127, 98, 255, 96, 38, 127, 249, 85, 201, 99, 240, 66,
  196, 109, 165, 46, 227, 207, 175, 61, 60, /* skip 32 */ 48,
  &__stringlit_afbf45d2e089328b5dcb67d5f24dbe862, 226, 19, 253, 116, 175, 12,
  95, 249, 27, 66, 60, 139, 206, 236, 215, 1, 248, 221, 100, 236, 24, 253,
  111, 146, 96, 252, 158, 193, 237, 189, 34, 48, 166, 144, 134, 101, 188,
  217, 251, 244, 26, 153, 161, 138, 125, 158, 68, 110, /* skip 16 */ 64,
  &__stringlit_afbf45d2e089328b5dcb67d5f24dbe861, 150, 238, 71, 24, 220, 186,
  60, 116, 97, 155, 161, 250, 127, 87, 223, 231, 118, 157, 63, 102, 152, 168,
  179, 63, 161, 1, 131, 137, 112, 161, 49, 230, 33, 204, 253, 5, 254, 255,
  188, 17, 128, 242, 99, 194, 127, 26, 218, 180, 96, 149, 214, 241, 37, 51,
  20, 114, 75, 92, 191, 120, 40, 101, 142, 106, };

unsigned char data_583[100000];

int main(void)
{
  int i;
  unsigned char md[64];
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:199");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:200");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:204");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 4;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:206");
    keccak((unsigned char *) ((*(testvec + i))).msgstr,
           strlen(((*(testvec + i))).msgstr), md, ((*(testvec + i))).mdlen);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:210");
    printf(__stringlit_afbf45d2e089328b5dcb67d5f24dbe867,
           ((*(testvec + i))).mdlen * 8,
           memcmp(md, ((*(testvec + i))).md, ((*(testvec + i))).mdlen) == 0
             ? __stringlit_afbf45d2e089328b5dcb67d5f24dbe866
             : __stringlit_afbf45d2e089328b5dcb67d5f24dbe865);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:217");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 100000;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    *(data_583 + i) = i;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:218");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 250;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha3.c:219");
    keccak(data_583, 100000, md, 64);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha3.c:221");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


