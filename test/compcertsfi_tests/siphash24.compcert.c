static /*signed*/ char const __stringlit_e080a4cd0de5f6c8783947b1a4554ec21[33];

static /*signed*/ char const __stringlit_e080a4cd0de5f6c8783947b1a4554ec22[17];

extern unsigned int keep[2];

extern int crypto_auth(unsigned char *, unsigned char *, unsigned long long, unsigned char *);

extern unsigned char vectors[64][8];

extern int test_vectors(void);

extern unsigned char testdata[100];

extern int speed_test(void);

extern int main(void);

static /*signed*/ char const __stringlit_e080a4cd0de5f6c8783947b1a4554ec21[33] = "test vector failed for %d bytes\012";

static /*signed*/ char const __stringlit_e080a4cd0de5f6c8783947b1a4554ec22[17] = "test vectors ok\012";

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

extern int memcmp(void *, void *, unsigned int);

int crypto_auth(unsigned char *out, unsigned char *in, unsigned long long inlen, unsigned char *k)
{
  unsigned long long v0;
  unsigned long long v1;
  unsigned long long v2;
  unsigned long long v3;
  unsigned long long b;
  unsigned long long k0;
  unsigned long long k1;
  unsigned long long m;
  unsigned char *end;
  int left;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:54");
  v0 = 8317987319222330741LLU;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:55");
  v1 = 7237128888997146477LLU;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:56");
  v2 = 7816392313619706465LLU;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:57");
  v3 = 8387220255154660723LLU;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:58");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:59");
  k0 =
    (unsigned long long) *(k + 0) | (unsigned long long) *(k + 1) << 8
      | (unsigned long long) *(k + 2) << 16
      | (unsigned long long) *(k + 3) << 24
      | (unsigned long long) *(k + 4) << 32
      | (unsigned long long) *(k + 5) << 40
      | (unsigned long long) *(k + 6) << 48
      | (unsigned long long) *(k + 7) << 56;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:60");
  k1 =
    (unsigned long long) *(k + 8 + 0)
      | (unsigned long long) *(k + 8 + 1) << 8
      | (unsigned long long) *(k + 8 + 2) << 16
      | (unsigned long long) *(k + 8 + 3) << 24
      | (unsigned long long) *(k + 8 + 4) << 32
      | (unsigned long long) *(k + 8 + 5) << 40
      | (unsigned long long) *(k + 8 + 6) << 48
      | (unsigned long long) *(k + 8 + 7) << 56;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:61");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:62");
  end = in + inlen - inlen % sizeof(unsigned long long);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:63");
  left = inlen & 7;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:64");
  b = (unsigned long long) inlen << 56;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:65");
  v3 ^= k1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:66");
  v2 ^= k0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:67");
  v1 ^= k1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:68");
  v0 ^= k0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:70");
  for (/*nothing*/; in != end; __builtin_debug(6,"", 1), in += 8) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:72");
    m =
      (unsigned long long) *(in + 0) | (unsigned long long) *(in + 1) << 8
        | (unsigned long long) *(in + 2) << 16
        | (unsigned long long) *(in + 3) << 24
        | (unsigned long long) *(in + 4) << 32
        | (unsigned long long) *(in + 5) << 40
        | (unsigned long long) *(in + 6) << 48
        | (unsigned long long) *(in + 7) << 56;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:80");
    v3 ^= m;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:81");
    do {
      __builtin_debug(6,"", 1);
      v0 += v1;
      __builtin_debug(6,"", 1);
      v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
      __builtin_debug(6,"", 1);
      v1 ^= v0;
      __builtin_debug(6,"", 1);
      v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
      __builtin_debug(6,"", 1);
      v2 += v3;
      __builtin_debug(6,"", 1);
      v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
      __builtin_debug(6,"", 1);
      v3 ^= v2;
      __builtin_debug(6,"", 1);
      v0 += v3;
      __builtin_debug(6,"", 1);
      v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
      __builtin_debug(6,"", 1);
      v3 ^= v0;
      __builtin_debug(6,"", 1);
      v2 += v1;
      __builtin_debug(6,"", 1);
      v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
      __builtin_debug(6,"", 1);
      v1 ^= v2;
      __builtin_debug(6,"", 1);
      v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
    } while(0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:82");
    do {
      __builtin_debug(6,"", 1);
      v0 += v1;
      __builtin_debug(6,"", 1);
      v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
      __builtin_debug(6,"", 1);
      v1 ^= v0;
      __builtin_debug(6,"", 1);
      v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
      __builtin_debug(6,"", 1);
      v2 += v3;
      __builtin_debug(6,"", 1);
      v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
      __builtin_debug(6,"", 1);
      v3 ^= v2;
      __builtin_debug(6,"", 1);
      v0 += v3;
      __builtin_debug(6,"", 1);
      v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
      __builtin_debug(6,"", 1);
      v3 ^= v0;
      __builtin_debug(6,"", 1);
      v2 += v1;
      __builtin_debug(6,"", 1);
      v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
      __builtin_debug(6,"", 1);
      v1 ^= v2;
      __builtin_debug(6,"", 1);
      v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
    } while(0);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:83");
    v0 ^= m;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:86");
  switch (left) {
    case 7:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 6) << 48;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:90");
    case 6:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 5) << 40;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:92");
    case 5:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 4) << 32;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:94");
    case 4:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 3) << 24;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:96");
    case 3:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 2) << 16;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:98");
    case 2:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 1) << 8;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:100");
    case 1:
      __builtin_debug(6,"", 1);
      b |= (unsigned long long) *(in + 0);
      break;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:102");
    case 0:
      break;
    
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:112");
  v3 ^= b;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:113");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:114");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:115");
  v0 ^= b;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:122");
  v2 ^= 255;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:123");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:124");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:125");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:126");
  do {
    __builtin_debug(6,"", 1);
    v0 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 13 | v1 >> 64 - 13);
    __builtin_debug(6,"", 1);
    v1 ^= v0;
    __builtin_debug(6,"", 1);
    v0 = (unsigned long long) (v0 << 32 | v0 >> 64 - 32);
    __builtin_debug(6,"", 1);
    v2 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 16 | v3 >> 64 - 16);
    __builtin_debug(6,"", 1);
    v3 ^= v2;
    __builtin_debug(6,"", 1);
    v0 += v3;
    __builtin_debug(6,"", 1);
    v3 = (unsigned long long) (v3 << 21 | v3 >> 64 - 21);
    __builtin_debug(6,"", 1);
    v3 ^= v0;
    __builtin_debug(6,"", 1);
    v2 += v1;
    __builtin_debug(6,"", 1);
    v1 = (unsigned long long) (v1 << 17 | v1 >> 64 - 17);
    __builtin_debug(6,"", 1);
    v1 ^= v2;
    __builtin_debug(6,"", 1);
    v2 = (unsigned long long) (v2 << 32 | v2 >> 64 - 32);
  } while(0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:127");
  b = v0 ^ v1 ^ v2 ^ v3;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:128");
  *(out + 0) = (unsigned char) (unsigned int) b;
  __builtin_debug(6,"", 1);
  *(out + 1) = (unsigned char) ((unsigned int) b >> 8);
  __builtin_debug(6,"", 1);
  *(out + 2) = (unsigned char) ((unsigned int) b >> 16);
  __builtin_debug(6,"", 1);
  *(out + 3) = (unsigned char) ((unsigned int) b >> 24);
  __builtin_debug(6,"", 1);
  *(out + 4 + 0) = (unsigned char) (unsigned int) (b >> 32);
  __builtin_debug(6,"", 1);
  *(out + 4 + 1) = (unsigned char) ((unsigned int) (b >> 32) >> 8);
  __builtin_debug(6,"", 1);
  *(out + 4 + 2) = (unsigned char) ((unsigned int) (b >> 32) >> 16);
  __builtin_debug(6,"", 1);
  *(out + 4 + 3) = (unsigned char) ((unsigned int) (b >> 32) >> 24);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:129");
  return 0;
}

 unsigned char vectors[64][8] = { 49, 14, 14, 221, 71, 219, 111, 114, 253,
  103, 220, 147, 197, 57, 248, 116, 90, 79, 169, 217, 9, 128, 108, 13, 45,
  126, 251, 215, 150, 102, 103, 133, 183, 135, 113, 39, 224, 148, 39, 207,
  141, 166, 153, 205, 100, 85, 118, 24, 206, 227, 254, 88, 110, 70, 201, 203,
  55, 209, 1, 139, 245, 0, 2, 171, 98, 36, 147, 154, 121, 245, 245, 147, 176,
  228, 169, 11, 223, 130, 0, 158, 243, 185, 221, 148, 197, 187, 93, 122, 167,
  173, 107, 34, 70, 47, 179, 244, 251, 229, 14, 134, 188, 143, 30, 117, 144,
  61, 132, 192, 39, 86, 234, 20, 238, 242, 122, 142, 144, 202, 35, 247, 229,
  69, 190, 73, 97, 202, 41, 161, 219, 155, 194, 87, 127, 204, 42, 63, 148,
  71, 190, 44, 245, 233, 154, 105, 156, 211, 141, 150, 240, 179, 193, 75,
  189, 97, 121, 167, 29, 201, 109, 187, 152, 238, 162, 26, 242, 92, 214, 190,
  199, 103, 59, 46, 176, 203, 242, 208, 136, 62, 163, 227, 149, 103, 83, 147,
  200, 206, 92, 205, 140, 3, 12, 168, 148, 175, 73, 246, 198, 80, 173, 184,
  234, 184, 133, 138, 222, 146, 225, 188, 243, 21, 187, 91, 184, 53, 216, 23,
  173, 207, 107, 7, 99, 97, 46, 47, 165, 201, 29, 167, 172, 170, 77, 222,
  113, 101, 149, 135, 102, 80, 162, 166, 40, 239, 73, 92, 83, 163, 135, 173,
  66, 195, 65, 216, 250, 146, 216, 50, 206, 124, 242, 114, 47, 81, 39, 113,
  227, 120, 89, 249, 70, 35, 243, 167, 56, 18, 5, 187, 26, 176, 224, 18, 174,
  151, 161, 15, 212, 52, 224, 21, 180, 163, 21, 8, 190, 255, 77, 49, 129, 57,
  98, 41, 240, 144, 121, 2, 77, 12, 244, 158, 229, 212, 220, 202, 92, 115,
  51, 106, 118, 216, 191, 154, 208, 167, 4, 83, 107, 169, 62, 14, 146, 89,
  88, 252, 214, 66, 12, 173, 169, 21, 194, 155, 200, 6, 115, 24, 149, 43,
  121, 243, 188, 10, 166, 212, 242, 29, 242, 228, 29, 69, 53, 249, 135, 87,
  117, 25, 4, 143, 83, 169, 16, 165, 108, 245, 223, 205, 154, 219, 235, 117,
  9, 92, 205, 152, 108, 208, 81, 169, 203, 158, 203, 163, 18, 230, 150, 175,
  173, 252, 44, 230, 102, 199, 114, 254, 82, 151, 90, 67, 100, 238, 90, 22,
  69, 178, 118, 213, 146, 161, 178, 116, 203, 142, 191, 135, 135, 10, 111,
  155, 180, 32, 61, 231, 179, 129, 234, 236, 178, 163, 11, 34, 168, 127, 153,
  36, 164, 60, 193, 49, 87, 36, 189, 131, 141, 58, 175, 191, 141, 183, 11,
  26, 42, 50, 101, 213, 26, 234, 19, 80, 121, 163, 35, 28, 230, 96, 147, 43,
  40, 70, 228, 215, 6, 102, 225, 145, 95, 92, 177, 236, 164, 108, 243, 37,
  150, 92, 161, 109, 98, 159, 87, 95, 242, 142, 96, 56, 27, 229, 114, 69, 6,
  235, 76, 50, 138, 149, };

int test_vectors(void)
{
  unsigned char in[64];
  unsigned char out[8];
  unsigned char k[16];
  int i;
  int ok;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:215");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:216");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:217");
  ok = 1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:219");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 16;
       __builtin_debug(6,"", 1), i += 1) {
    __builtin_debug(6,"", 1);
    *(k + i) = i;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:221");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 64;
       __builtin_debug(6,"", 1), i += 1) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:223");
    *(in + i) = i;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:224");
    crypto_auth(out, in, i, k);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:226");
    if (memcmp(out, *(vectors + i), 8)) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:228");
      printf(__stringlit_e080a4cd0de5f6c8783947b1a4554ec21, i);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:siphash24.c:229");
      ok = 0;
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:233");
  return ok;
}

 unsigned char testdata[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 12, 34, 56,
  78, 90, /* skip 85 */ };

int speed_test(void)
{
  unsigned char out[8];
  unsigned char k[16];
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:240");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:241");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:243");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 16;
       __builtin_debug(6,"", 1), i += 1) {
    __builtin_debug(6,"", 1);
    *(k + i) = i;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:244");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 10000000;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:245");
    *(testdata + 99) = (unsigned char) i;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:siphash24.c:246");
    crypto_auth(out, testdata, 100, k);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:siphash24.c:248");
  return *(out + 0);
}

int main(void)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:siphash24.c:253");
  if (test_vectors()) {
    __builtin_debug(6,"");
    printf(__stringlit_e080a4cd0de5f6c8783947b1a4554ec22);
  }
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:siphash24.c:254");
  (void) speed_test();
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:siphash24.c:255");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


