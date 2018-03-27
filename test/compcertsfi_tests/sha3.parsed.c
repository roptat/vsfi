extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern void * memcpy(void * __dest, void const * __src, size_t __n);

extern void * memset(void * __s, int __c, size_t __n);

extern int memcmp(void const * __s1, void const * __s2, size_t __n);

extern size_t strlen(char const * __s);

typedef unsigned long long uint64;

typedef unsigned char uint8;

uint64 const keccakf_rndc[24] =
  {0x0000000000000001, 0x0000000000008082, 0x800000000000808a,
   0x8000000080008000, 0x000000000000808b, 0x0000000080000001,
   0x8000000080008081, 0x8000000000008009, 0x000000000000008a,
   0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
   0x000000008000808b, 0x800000000000008b, 0x8000000000008089,
   0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
   0x000000000000800a, 0x800000008000000a, 0x8000000080008081,
   0x8000000000008080, 0x0000000080000001, 0x8000000080008008, };

int const keccakf_rotc[24] =
  {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 
   62, 18, 39, 61, 20, 44, };

int const keccakf_piln[24] =
  {10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 
   20, 14, 22, 9, 6, 1, };

void keccakf(uint64 * st)
{
  int j;
  int round;
  uint64 t;
  uint64 bc[5];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:43");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:44");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:46");
  for (__builtin_debug(6, "", 1), round = 0;
       round < 24;
       __builtin_debug(6, "", 1), round++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:52");
    bc[0] = st[0] ^ st[0 + 5] ^ st[0 + 10] ^ st[0 + 15] ^ st[0 + 20];
    __builtin_debug(6, "", 1);
    bc[1] = st[1] ^ st[1 + 5] ^ st[1 + 10] ^ st[1 + 15] ^ st[1 + 20];
    __builtin_debug(6, "", 1);
    bc[2] = st[2] ^ st[2 + 5] ^ st[2 + 10] ^ st[2 + 15] ^ st[2 + 20];
    __builtin_debug(6, "", 1);
    bc[3] = st[3] ^ st[3 + 5] ^ st[3 + 10] ^ st[3 + 15] ^ st[3 + 20];
    __builtin_debug(6, "", 1);
    bc[4] = st[4] ^ st[4 + 5] ^ st[4 + 10] ^ st[4 + 15] ^ st[4 + 20];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:62");
    t = bc[(0 + 4) % 5] ^ (bc[(0 + 1) % 5] << 1 | bc[(0 + 1) % 5] >> 64 - 1);
    __builtin_debug(6, "", 1);
    st[0 + 0] ^= t;
    __builtin_debug(6, "", 1);
    st[5 + 0] ^= t;
    __builtin_debug(6, "", 1);
    st[10 + 0] ^= t;
    __builtin_debug(6, "", 1);
    st[15 + 0] ^= t;
    __builtin_debug(6, "", 1);
    st[20 + 0] ^= t;
    __builtin_debug(6, "", 1);
    t = bc[(1 + 4) % 5] ^ (bc[(1 + 1) % 5] << 1 | bc[(1 + 1) % 5] >> 64 - 1);
    __builtin_debug(6, "", 1);
    st[0 + 1] ^= t;
    __builtin_debug(6, "", 1);
    st[5 + 1] ^= t;
    __builtin_debug(6, "", 1);
    st[10 + 1] ^= t;
    __builtin_debug(6, "", 1);
    st[15 + 1] ^= t;
    __builtin_debug(6, "", 1);
    st[20 + 1] ^= t;
    __builtin_debug(6, "", 1);
    t = bc[(2 + 4) % 5] ^ (bc[(2 + 1) % 5] << 1 | bc[(2 + 1) % 5] >> 64 - 1);
    __builtin_debug(6, "", 1);
    st[0 + 2] ^= t;
    __builtin_debug(6, "", 1);
    st[5 + 2] ^= t;
    __builtin_debug(6, "", 1);
    st[10 + 2] ^= t;
    __builtin_debug(6, "", 1);
    st[15 + 2] ^= t;
    __builtin_debug(6, "", 1);
    st[20 + 2] ^= t;
    __builtin_debug(6, "", 1);
    t = bc[(3 + 4) % 5] ^ (bc[(3 + 1) % 5] << 1 | bc[(3 + 1) % 5] >> 64 - 1);
    __builtin_debug(6, "", 1);
    st[0 + 3] ^= t;
    __builtin_debug(6, "", 1);
    st[5 + 3] ^= t;
    __builtin_debug(6, "", 1);
    st[10 + 3] ^= t;
    __builtin_debug(6, "", 1);
    st[15 + 3] ^= t;
    __builtin_debug(6, "", 1);
    st[20 + 3] ^= t;
    __builtin_debug(6, "", 1);
    t = bc[(4 + 4) % 5] ^ (bc[(4 + 1) % 5] << 1 | bc[(4 + 1) % 5] >> 64 - 1);
    __builtin_debug(6, "", 1);
    st[0 + 4] ^= t;
    __builtin_debug(6, "", 1);
    st[5 + 4] ^= t;
    __builtin_debug(6, "", 1);
    st[10 + 4] ^= t;
    __builtin_debug(6, "", 1);
    st[15 + 4] ^= t;
    __builtin_debug(6, "", 1);
    st[20 + 4] ^= t;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:73");
    t = st[1];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:74");
    j = keccakf_piln[0];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 1 | t >> 64 - 1;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[1];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 3 | t >> 64 - 3;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[2];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 6 | t >> 64 - 6;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[3];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 10 | t >> 64 - 10;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:75");
    j = keccakf_piln[4];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 15 | t >> 64 - 15;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[5];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 21 | t >> 64 - 21;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[6];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 28 | t >> 64 - 28;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[7];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 36 | t >> 64 - 36;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:76");
    j = keccakf_piln[8];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 45 | t >> 64 - 45;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[9];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 55 | t >> 64 - 55;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[10];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 2 | t >> 64 - 2;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[11];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 14 | t >> 64 - 14;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:77");
    j = keccakf_piln[12];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 27 | t >> 64 - 27;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[13];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 41 | t >> 64 - 41;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[14];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 56 | t >> 64 - 56;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[15];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 8 | t >> 64 - 8;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:78");
    j = keccakf_piln[16];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 25 | t >> 64 - 25;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[17];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 43 | t >> 64 - 43;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[18];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 62 | t >> 64 - 62;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[19];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 18 | t >> 64 - 18;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:79");
    j = keccakf_piln[20];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 39 | t >> 64 - 39;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[21];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 61 | t >> 64 - 61;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[22];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 20 | t >> 64 - 20;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    j = keccakf_piln[23];
    __builtin_debug(6, "", 1);
    bc[0] = st[j];
    __builtin_debug(6, "", 1);
    st[j] = t << 44 | t >> 64 - 44;
    __builtin_debug(6, "", 1);
    t = bc[0];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:88");
    for (__builtin_debug(6, "", 1), j = 0;
         j < 25;
         __builtin_debug(6, "", 1), j += 5) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha3.c:89");
      bc[0] = st[j + 0];
      __builtin_debug(6, "", 1);
      bc[1] = st[j + 1];
      __builtin_debug(6, "", 1);
      bc[2] = st[j + 2];
      __builtin_debug(6, "", 1);
      bc[3] = st[j + 3];
      __builtin_debug(6, "", 1);
      bc[4] = st[j + 4];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha3.c:90");
      st[j + 0] ^= ~bc[(0 + 1) % 5] & bc[(0 + 2) % 5];
      __builtin_debug(6, "", 1);
      st[j + 1] ^= ~bc[(1 + 1) % 5] & bc[(1 + 2) % 5];
      __builtin_debug(6, "", 1);
      st[j + 2] ^= ~bc[(2 + 1) % 5] & bc[(2 + 2) % 5];
      __builtin_debug(6, "", 1);
      st[j + 3] ^= ~bc[(3 + 1) % 5] & bc[(3 + 2) % 5];
      __builtin_debug(6, "", 1);
      st[j + 4] ^= ~bc[(4 + 1) % 5] & bc[(4 + 2) % 5];
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:94");
    st[0] ^= keccakf_rndc[round];
  }
}

inline static uint64 get64le_559(uint8 const * p)
{
  unsigned int l;
  unsigned int h;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:102");
  l = p[0] | p[1] << 8 | p[2] << 16 | p[3] << 24;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:103");
  h = p[4] | p[5] << 8 | p[6] << 16 | p[7] << 24;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:104");
  return l | (uint64) h << 32;
}

inline static void set64le_565(uint8 * p, uint64 x)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha3.c:111");
  p[0] = x;
  __builtin_debug(6, "");
  p[1] = x >> 8;
  __builtin_debug(6, "");
  p[2] = x >> 16;
  __builtin_debug(6, "");
  p[3] = x >> 24;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha3.c:112");
  p[4] = x >> 32;
  __builtin_debug(6, "");
  p[5] = x >> 40;
  __builtin_debug(6, "");
  p[6] = x >> 48;
  __builtin_debug(6, "");
  p[7] = x >> 56;
}

void keccak(uint8 const * in, int inlen, uint8 * md, int mdlen)
{
  uint64 st[25];
  uint8 temp[144];
  int i;
  int rsiz;
  int rsizw;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:119");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:120");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:121");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:123");
  rsiz = 200 - 2 * mdlen;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:124");
  rsizw = rsiz / 8;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:126");
  memset(st, 0, sizeof(uint64[25]));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:128");
  for (/*nothing*/;
       inlen >= rsiz;
       __builtin_debug(6, "", 1), (inlen -= rsiz, in += rsiz)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:129");
    for (__builtin_debug(6, "", 1), i = 0;
         i < rsizw;
         __builtin_debug(6, "", 1), i++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha3.c:130");
      st[i] ^= get64le_559(in + i * 8);
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:131");
    keccakf(st);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:135");
  memcpy(temp, in, inlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:136");
  temp[inlen++] = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:137");
  memset(temp + inlen, 0, rsiz - inlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:138");
  temp[rsiz - 1] |= 0x80;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:140");
  for (__builtin_debug(6, "", 1), i = 0;
       i < rsizw;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:141");
    st[i] ^= get64le_559(temp + i * 8);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:143");
  keccakf(st);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:145");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 8;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:146");
    set64le_565(temp + i * 8, st[i]);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:148");
  memcpy(md, temp, mdlen);
}

struct _s6d5441d9a540c41662b165018d076b82;

struct _s6d5441d9a540c41662b165018d076b82 {
  int mdlen;
  char * msgstr;
  uint8 md[64];
};

typedef struct _s6d5441d9a540c41662b165018d076b82 test_triplet_t;

test_triplet_t testvec[4] =
  {{28, "Keccak-224 Test Hash",
    {0x30, 0x04, 0x5B, 0x34, 0x94, 0x6E, 0x1B, 0x2E, 0x09, 0x16, 0x13, 
     0x36, 0x2F, 0xD2, 0x2A, 0xA0, 0x8E, 0x2B, 0xEA, 0xFE, 0xC5, 0xE8, 
     0xDA, 0xEE, 0x42, 0xC2, 0xE6, 0x65, }, },
   {32, "Keccak-256 Test Hash",
    {0xA8, 0xD7, 0x1B, 0x07, 0xF4, 0xAF, 0x26, 0xA4, 0xFF, 0x21, 0x02, 
     0x7F, 0x62, 0xFF, 0x60, 0x26, 0x7F, 0xF9, 0x55, 0xC9, 0x63, 0xF0, 
     0x42, 0xC4, 0x6D, 0xA5, 0x2E, 0xE3, 0xCF, 0xAF, 0x3D, 0x3C, }, },
   {48, "Keccak-384 Test Hash",
    {0xE2, 0x13, 0xFD, 0x74, 0xAF, 0x0C, 0x5F, 0xF9, 0x1B, 0x42, 0x3C, 
     0x8B, 0xCE, 0xEC, 0xD7, 0x01, 0xF8, 0xDD, 0x64, 0xEC, 0x18, 0xFD, 
     0x6F, 0x92, 0x60, 0xFC, 0x9E, 0xC1, 0xED, 0xBD, 0x22, 0x30, 0xA6, 
     0x90, 0x86, 0x65, 0xBC, 0xD9, 0xFB, 0xF4, 0x1A, 0x99, 0xA1, 0x8A, 
     0x7D, 0x9E, 0x44, 0x6E, }, },
   {64, "Keccak-512 Test Hash",
    {0x96, 0xEE, 0x47, 0x18, 0xDC, 0xBA, 0x3C, 0x74, 0x61, 0x9B, 0xA1, 
     0xFA, 0x7F, 0x57, 0xDF, 0xE7, 0x76, 0x9D, 0x3F, 0x66, 0x98, 0xA8, 
     0xB3, 0x3F, 0xA1, 0x01, 0x83, 0x89, 0x70, 0xA1, 0x31, 0xE6, 0x21, 
     0xCC, 0xFD, 0x05, 0xFE, 0xFF, 0xBC, 0x11, 0x80, 0xF2, 0x63, 0xC2, 
     0x7F, 0x1A, 0xDA, 0xB4, 0x60, 0x95, 0xD6, 0xF1, 0x25, 0x33, 0x14, 
     0x72, 0x4B, 0x5C, 0xBF, 0x78, 0x28, 0x65, 0x8E, 0x6A, }, }, };

static uint8 data_583[100000];

int main(void)
{
  int i;
  uint8 md[64];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:199");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:200");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:204");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 4;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:206");
    keccak((uint8 *) testvec[i].msgstr, strlen(testvec[i].msgstr), md,
           testvec[i].mdlen);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:210");
    printf("SHA-3 %d %s\n", testvec[i].mdlen * 8,
           memcmp(md, testvec[i].md, testvec[i].mdlen) == 0 ? "passed"
             : "FAILED");
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:217");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 100000;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    data_583[i] = i;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:218");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 250;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha3.c:219");
    keccak(data_583, 100000, md, 64);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha3.c:221");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


