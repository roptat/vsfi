extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int memcmp(void const * __s1, void const * __s2, size_t __n);

typedef unsigned long long u64;

typedef unsigned long u32;

typedef unsigned char u8;

int crypto_auth(unsigned char * out, unsigned char const * in,
                unsigned long long inlen, unsigned char const * k)
{
  u64 v0;
  u64 v1;
  u64 v2;
  u64 v3;
  u64 b;
  u64 k0;
  u64 k1;
  u64 m;
  u8 const * end;
  int left;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:54");
  v0 = 0x736f6d6570736575ULL;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:55");
  v1 = 0x646f72616e646f6dULL;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:56");
  v2 = 0x6c7967656e657261ULL;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:57");
  v3 = 0x7465646279746573ULL;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:58");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:59");
  k0 =
    (u64) k[0] | (u64) k[1] << 8 | (u64) k[2] << 16 | (u64) k[3] << 24
      | (u64) k[4] << 32 | (u64) k[5] << 40 | (u64) k[6] << 48
      | (u64) k[7] << 56;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:60");
  k1 =
    (u64) (k + 8)[0] | (u64) (k + 8)[1] << 8 | (u64) (k + 8)[2] << 16
      | (u64) (k + 8)[3] << 24 | (u64) (k + 8)[4] << 32
      | (u64) (k + 8)[5] << 40 | (u64) (k + 8)[6] << 48
      | (u64) (k + 8)[7] << 56;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:61");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:62");
  end = in + inlen - inlen % sizeof(u64);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:63");
  left = inlen & 7;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:64");
  b = (u64) inlen << 56;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:65");
  v3 ^= k1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:66");
  v2 ^= k0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:67");
  v1 ^= k1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:68");
  v0 ^= k0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:70");
  for (/*nothing*/; in != end; __builtin_debug(6, "", 1), in += 8) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:72");
    m =
      (u64) in[0] | (u64) in[1] << 8 | (u64) in[2] << 16 | (u64) in[3] << 24
        | (u64) in[4] << 32 | (u64) in[5] << 40 | (u64) in[6] << 48
        | (u64) in[7] << 56;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:80");
    v3 ^= m;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:81");
    do {
      __builtin_debug(6, "", 1);
      v0 += v1;
      __builtin_debug(6, "", 1);
      v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
      __builtin_debug(6, "", 1);
      v1 ^= v0;
      __builtin_debug(6, "", 1);
      v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
      __builtin_debug(6, "", 1);
      v2 += v3;
      __builtin_debug(6, "", 1);
      v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
      __builtin_debug(6, "", 1);
      v3 ^= v2;
      __builtin_debug(6, "", 1);
      v0 += v3;
      __builtin_debug(6, "", 1);
      v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
      __builtin_debug(6, "", 1);
      v3 ^= v0;
      __builtin_debug(6, "", 1);
      v2 += v1;
      __builtin_debug(6, "", 1);
      v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
      __builtin_debug(6, "", 1);
      v1 ^= v2;
      __builtin_debug(6, "", 1);
      v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
    } while(0);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:82");
    do {
      __builtin_debug(6, "", 1);
      v0 += v1;
      __builtin_debug(6, "", 1);
      v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
      __builtin_debug(6, "", 1);
      v1 ^= v0;
      __builtin_debug(6, "", 1);
      v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
      __builtin_debug(6, "", 1);
      v2 += v3;
      __builtin_debug(6, "", 1);
      v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
      __builtin_debug(6, "", 1);
      v3 ^= v2;
      __builtin_debug(6, "", 1);
      v0 += v3;
      __builtin_debug(6, "", 1);
      v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
      __builtin_debug(6, "", 1);
      v3 ^= v0;
      __builtin_debug(6, "", 1);
      v2 += v1;
      __builtin_debug(6, "", 1);
      v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
      __builtin_debug(6, "", 1);
      v1 ^= v2;
      __builtin_debug(6, "", 1);
      v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
    } while(0);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:83");
    v0 ^= m;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:86");
  switch (left) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:88");
    case 7:
    __builtin_debug(6, "", 1);
    b |= (u64) in[6] << 48;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:90");
    case 6:
    __builtin_debug(6, "", 1);
    b |= (u64) in[5] << 40;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:92");
    case 5:
    __builtin_debug(6, "", 1);
    b |= (u64) in[4] << 32;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:94");
    case 4:
    __builtin_debug(6, "", 1);
    b |= (u64) in[3] << 24;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:96");
    case 3:
    __builtin_debug(6, "", 1);
    b |= (u64) in[2] << 16;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:98");
    case 2:
    __builtin_debug(6, "", 1);
    b |= (u64) in[1] << 8;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:100");
    case 1:
    __builtin_debug(6, "", 1);
    b |= (u64) in[0];
    break;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:102");
    case 0:
    break;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:112");
  v3 ^= b;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:113");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:114");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:115");
  v0 ^= b;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:122");
  v2 ^= 0xff;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:123");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:124");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:125");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:126");
  do {
    __builtin_debug(6, "", 1);
    v0 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6, "", 1);
    v1 ^= v0;
    __builtin_debug(6, "", 1);
    v0 = (u64) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6, "", 1);
    v2 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6, "", 1);
    v3 ^= v2;
    __builtin_debug(6, "", 1);
    v0 += v3;
    __builtin_debug(6, "", 1);
    v3 = (u64) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6, "", 1);
    v3 ^= v0;
    __builtin_debug(6, "", 1);
    v2 += v1;
    __builtin_debug(6, "", 1);
    v1 = (u64) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6, "", 1);
    v1 ^= v2;
    __builtin_debug(6, "", 1);
    v2 = (u64) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:127");
  b = v0 ^ v1 ^ v2 ^ v3;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:128");
  out[0] = (u8) (u32) b;
  __builtin_debug(6, "", 1);
  out[1] = (u8) ((u32) b >> 8);
  __builtin_debug(6, "", 1);
  out[2] = (u8) ((u32) b >> 16);
  __builtin_debug(6, "", 1);
  out[3] = (u8) ((u32) b >> 24);
  __builtin_debug(6, "", 1);
  (out + 4)[0] = (u8) (u32) (b >> 32);
  __builtin_debug(6, "", 1);
  (out + 4)[1] = (u8) ((u32) (b >> 32) >> 8);
  __builtin_debug(6, "", 1);
  (out + 4)[2] = (u8) ((u32) (b >> 32) >> 16);
  __builtin_debug(6, "", 1);
  (out + 4)[3] = (u8) ((u32) (b >> 32) >> 24);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:129");
  return 0;
}

u8 vectors[64][8] =
  {{0x31, 0x0e, 0x0e, 0xdd, 0x47, 0xdb, 0x6f, 0x72, },
   {0xfd, 0x67, 0xdc, 0x93, 0xc5, 0x39, 0xf8, 0x74, },
   {0x5a, 0x4f, 0xa9, 0xd9, 0x09, 0x80, 0x6c, 0x0d, },
   {0x2d, 0x7e, 0xfb, 0xd7, 0x96, 0x66, 0x67, 0x85, },
   {0xb7, 0x87, 0x71, 0x27, 0xe0, 0x94, 0x27, 0xcf, },
   {0x8d, 0xa6, 0x99, 0xcd, 0x64, 0x55, 0x76, 0x18, },
   {0xce, 0xe3, 0xfe, 0x58, 0x6e, 0x46, 0xc9, 0xcb, },
   {0x37, 0xd1, 0x01, 0x8b, 0xf5, 0x00, 0x02, 0xab, },
   {0x62, 0x24, 0x93, 0x9a, 0x79, 0xf5, 0xf5, 0x93, },
   {0xb0, 0xe4, 0xa9, 0x0b, 0xdf, 0x82, 0x00, 0x9e, },
   {0xf3, 0xb9, 0xdd, 0x94, 0xc5, 0xbb, 0x5d, 0x7a, },
   {0xa7, 0xad, 0x6b, 0x22, 0x46, 0x2f, 0xb3, 0xf4, },
   {0xfb, 0xe5, 0x0e, 0x86, 0xbc, 0x8f, 0x1e, 0x75, },
   {0x90, 0x3d, 0x84, 0xc0, 0x27, 0x56, 0xea, 0x14, },
   {0xee, 0xf2, 0x7a, 0x8e, 0x90, 0xca, 0x23, 0xf7, },
   {0xe5, 0x45, 0xbe, 0x49, 0x61, 0xca, 0x29, 0xa1, },
   {0xdb, 0x9b, 0xc2, 0x57, 0x7f, 0xcc, 0x2a, 0x3f, },
   {0x94, 0x47, 0xbe, 0x2c, 0xf5, 0xe9, 0x9a, 0x69, },
   {0x9c, 0xd3, 0x8d, 0x96, 0xf0, 0xb3, 0xc1, 0x4b, },
   {0xbd, 0x61, 0x79, 0xa7, 0x1d, 0xc9, 0x6d, 0xbb, },
   {0x98, 0xee, 0xa2, 0x1a, 0xf2, 0x5c, 0xd6, 0xbe, },
   {0xc7, 0x67, 0x3b, 0x2e, 0xb0, 0xcb, 0xf2, 0xd0, },
   {0x88, 0x3e, 0xa3, 0xe3, 0x95, 0x67, 0x53, 0x93, },
   {0xc8, 0xce, 0x5c, 0xcd, 0x8c, 0x03, 0x0c, 0xa8, },
   {0x94, 0xaf, 0x49, 0xf6, 0xc6, 0x50, 0xad, 0xb8, },
   {0xea, 0xb8, 0x85, 0x8a, 0xde, 0x92, 0xe1, 0xbc, },
   {0xf3, 0x15, 0xbb, 0x5b, 0xb8, 0x35, 0xd8, 0x17, },
   {0xad, 0xcf, 0x6b, 0x07, 0x63, 0x61, 0x2e, 0x2f, },
   {0xa5, 0xc9, 0x1d, 0xa7, 0xac, 0xaa, 0x4d, 0xde, },
   {0x71, 0x65, 0x95, 0x87, 0x66, 0x50, 0xa2, 0xa6, },
   {0x28, 0xef, 0x49, 0x5c, 0x53, 0xa3, 0x87, 0xad, },
   {0x42, 0xc3, 0x41, 0xd8, 0xfa, 0x92, 0xd8, 0x32, },
   {0xce, 0x7c, 0xf2, 0x72, 0x2f, 0x51, 0x27, 0x71, },
   {0xe3, 0x78, 0x59, 0xf9, 0x46, 0x23, 0xf3, 0xa7, },
   {0x38, 0x12, 0x05, 0xbb, 0x1a, 0xb0, 0xe0, 0x12, },
   {0xae, 0x97, 0xa1, 0x0f, 0xd4, 0x34, 0xe0, 0x15, },
   {0xb4, 0xa3, 0x15, 0x08, 0xbe, 0xff, 0x4d, 0x31, },
   {0x81, 0x39, 0x62, 0x29, 0xf0, 0x90, 0x79, 0x02, },
   {0x4d, 0x0c, 0xf4, 0x9e, 0xe5, 0xd4, 0xdc, 0xca, },
   {0x5c, 0x73, 0x33, 0x6a, 0x76, 0xd8, 0xbf, 0x9a, },
   {0xd0, 0xa7, 0x04, 0x53, 0x6b, 0xa9, 0x3e, 0x0e, },
   {0x92, 0x59, 0x58, 0xfc, 0xd6, 0x42, 0x0c, 0xad, },
   {0xa9, 0x15, 0xc2, 0x9b, 0xc8, 0x06, 0x73, 0x18, },
   {0x95, 0x2b, 0x79, 0xf3, 0xbc, 0x0a, 0xa6, 0xd4, },
   {0xf2, 0x1d, 0xf2, 0xe4, 0x1d, 0x45, 0x35, 0xf9, },
   {0x87, 0x57, 0x75, 0x19, 0x04, 0x8f, 0x53, 0xa9, },
   {0x10, 0xa5, 0x6c, 0xf5, 0xdf, 0xcd, 0x9a, 0xdb, },
   {0xeb, 0x75, 0x09, 0x5c, 0xcd, 0x98, 0x6c, 0xd0, },
   {0x51, 0xa9, 0xcb, 0x9e, 0xcb, 0xa3, 0x12, 0xe6, },
   {0x96, 0xaf, 0xad, 0xfc, 0x2c, 0xe6, 0x66, 0xc7, },
   {0x72, 0xfe, 0x52, 0x97, 0x5a, 0x43, 0x64, 0xee, },
   {0x5a, 0x16, 0x45, 0xb2, 0x76, 0xd5, 0x92, 0xa1, },
   {0xb2, 0x74, 0xcb, 0x8e, 0xbf, 0x87, 0x87, 0x0a, },
   {0x6f, 0x9b, 0xb4, 0x20, 0x3d, 0xe7, 0xb3, 0x81, },
   {0xea, 0xec, 0xb2, 0xa3, 0x0b, 0x22, 0xa8, 0x7f, },
   {0x99, 0x24, 0xa4, 0x3c, 0xc1, 0x31, 0x57, 0x24, },
   {0xbd, 0x83, 0x8d, 0x3a, 0xaf, 0xbf, 0x8d, 0xb7, },
   {0x0b, 0x1a, 0x2a, 0x32, 0x65, 0xd5, 0x1a, 0xea, },
   {0x13, 0x50, 0x79, 0xa3, 0x23, 0x1c, 0xe6, 0x60, },
   {0x93, 0x2b, 0x28, 0x46, 0xe4, 0xd7, 0x06, 0x66, },
   {0xe1, 0x91, 0x5f, 0x5c, 0xb1, 0xec, 0xa4, 0x6c, },
   {0xf3, 0x25, 0x96, 0x5c, 0xa1, 0x6d, 0x62, 0x9f, },
   {0x57, 0x5f, 0xf2, 0x8e, 0x60, 0x38, 0x1b, 0xe5, },
   {0x72, 0x45, 0x06, 0xeb, 0x4c, 0x32, 0x8a, 0x95, }, };

int test_vectors(void)
{
  u8 in[64];
  u8 out[8];
  u8 k[16];
  int i;
  int ok;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:215");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:216");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:217");
  ok = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:219");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 16;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    k[i] = i;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:221");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 64;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:223");
    in[i] = i;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:224");
    crypto_auth(out, in, i, k);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:226");
    if (memcmp(out, vectors[i], 8)) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:siphash24.c:228");
      printf("test vector failed for %d bytes\n", i);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:siphash24.c:229");
      ok = 0;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:233");
  return ok;
}

u8 testdata[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 12, 34, 56, 78, 90, };

int speed_test(void)
{
  u8 out[8];
  u8 k[16];
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:240");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:241");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:243");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 16;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    k[i] = i;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:244");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 10000000;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:245");
    testdata[99] = (u8) i;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:siphash24.c:246");
    crypto_auth(out, testdata, 100, k);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:siphash24.c:248");
  return out[0];
}

int main(void)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:siphash24.c:253");
  if (test_vectors()) {
    __builtin_debug(6, "");
    printf("test vectors ok\n");
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:siphash24.c:254");
  (void) speed_test();
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:siphash24.c:255");
  return 0;
  __builtin_debug(6, "");
  return 0;
}

