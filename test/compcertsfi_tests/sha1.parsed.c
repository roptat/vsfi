extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern void * memcpy(void * __dest, void const * __src, size_t __n);

extern void * memset(void * __s, int __c, size_t __n);

extern int memcmp(void const * __s1, void const * __s2, size_t __n);

extern size_t strlen(char const * __s);

extern int printf(char const * __format, ...);

typedef unsigned int u32;

struct SHA1Context;

struct SHA1Context {
  u32 state[5];
  u32 length[2];
  int numbytes;
  unsigned char buffer[64];
};

static int arch_big_endian_664;

static void SHA1_copy_and_swap_668(void * src, void * dst, int numwords)
{
  unsigned char * s;
  unsigned char * d;
  unsigned char a;
  unsigned char b;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:25");
  if (arch_big_endian_664) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:sha1.c:26");
    memcpy(dst, src, numwords * sizeof(u32));
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:28");
    __builtin_debug(6, "", 1);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:29");
    __builtin_debug(6, "", 1);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:30");
    for (__builtin_debug(6, "", 1), (s = src, d = dst);
         numwords > 0;
         __builtin_debug(6, "", 1), (s += 4, d += 4, numwords--)) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:31");
      a = s[0];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:32");
      b = s[1];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:33");
      d[0] = s[3];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:34");
      d[1] = s[2];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:35");
      d[2] = b;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:36");
      d[3] = a;
    }
  }
}

static void SHA1_transform_675(struct SHA1Context * ctx)
{
  int i;
  register u32 a;
  register u32 b;
  register u32 c;
  register u32 d;
  register u32 e;
  register u32 t;
  u32 data[80];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:52");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:53");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:54");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:57");
  SHA1_copy_and_swap_668(ctx->buffer, data, 16);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:60");
  for (__builtin_debug(6, "", 1), i = 16;
       i < 80;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:61");
    t = data[i - 3] ^ data[i - 8] ^ data[i - 14] ^ data[i - 16];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:62");
    data[i] = t << 1 | t >> 31;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:66");
  a = ctx->state[0];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:67");
  b = ctx->state[1];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:68");
  c = ctx->state[2];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:69");
  d = ctx->state[3];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:70");
  e = ctx->state[4];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:73");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 20;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:74");
    t = (d ^ b & (c ^ d)) + 0x5A827999U + (a << 5 | a >> 27) + e + data[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:75");
    e = d;
    __builtin_debug(6, "", 1);
    d = c;
    __builtin_debug(6, "", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6, "", 1);
    b = a;
    __builtin_debug(6, "", 1);
    a = t;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:77");
  for (/*nothing*/; i < 40; __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:78");
    t = (b ^ c ^ d) + 0x6ED9EBA1U + (a << 5 | a >> 27) + e + data[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:79");
    e = d;
    __builtin_debug(6, "", 1);
    d = c;
    __builtin_debug(6, "", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6, "", 1);
    b = a;
    __builtin_debug(6, "", 1);
    a = t;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:81");
  for (/*nothing*/; i < 60; __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:82");
    t =
      (b & c | d & (b | c)) + 0x8F1BBCDCU + (a << 5 | a >> 27) + e + data[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:83");
    e = d;
    __builtin_debug(6, "", 1);
    d = c;
    __builtin_debug(6, "", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6, "", 1);
    b = a;
    __builtin_debug(6, "", 1);
    a = t;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:85");
  for (/*nothing*/; i < 80; __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:86");
    t = (b ^ c ^ d) + 0xCA62C1D6U + (a << 5 | a >> 27) + e + data[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:87");
    e = d;
    __builtin_debug(6, "", 1);
    d = c;
    __builtin_debug(6, "", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6, "", 1);
    b = a;
    __builtin_debug(6, "", 1);
    a = t;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:91");
  ctx->state[0] += a;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:92");
  ctx->state[1] += b;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:93");
  ctx->state[2] += c;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:94");
  ctx->state[3] += d;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:95");
  ctx->state[4] += e;
}

void SHA1_init(struct SHA1Context * ctx)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:100");
  ctx->state[0] = 0x67452301U;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:101");
  ctx->state[1] = 0xEFCDAB89U;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:102");
  ctx->state[2] = 0x98BADCFEU;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:103");
  ctx->state[3] = 0x10325476U;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:104");
  ctx->state[4] = 0xC3D2E1F0U;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:105");
  ctx->numbytes = 0;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:106");
  ctx->length[0] = 0;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:sha1.c:107");
  ctx->length[1] = 0;
}

void SHA1_add_data(struct SHA1Context * ctx, unsigned char * data,
                   unsigned long len)
{
  u32 t;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:113");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:116");
  t = ctx->length[1];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:117");
  if ((ctx->length[1] = t + (u32) (len << 3)) < t) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:118");
    ctx->length[0]++;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:119");
  ctx->length[0] += (u32) (len >> 29);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:122");
  if (ctx->numbytes != 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:123");
    t = 64 - ctx->numbytes;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:124");
    if (len < t) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:125");
      memcpy(ctx->buffer + ctx->numbytes, data, len);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:126");
      ctx->numbytes += len;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:sha1.c:127");
      return;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:129");
    memcpy(ctx->buffer + ctx->numbytes, data, t);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:130");
    SHA1_transform_675(ctx);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:131");
    data += t;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:132");
    len -= t;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:135");
  while (len >= 64) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:136");
    memcpy(ctx->buffer, data, 64);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:137");
    SHA1_transform_675(ctx);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:138");
    data += 64;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:139");
    len -= 64;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:142");
  memcpy(ctx->buffer, data, len);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:143");
  ctx->numbytes = len;
}

void SHA1_finish(struct SHA1Context * ctx, unsigned char * output)
{
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:148");
  i = ctx->numbytes;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:151");
  ctx->buffer[i++] = 0x80;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:154");
  if (i > 56) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:155");
    memset(ctx->buffer + i, 0, 64 - i);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:156");
    SHA1_transform_675(ctx);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:157");
    i = 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:160");
  memset(ctx->buffer + i, 0, 56 - i);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:162");
  SHA1_copy_and_swap_668(ctx->length, ctx->buffer + 56, 2);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:164");
  SHA1_transform_675(ctx);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:166");
  SHA1_copy_and_swap_668(ctx->state, output, 5);
}

static void do_test_701(unsigned char * txt, unsigned char * expected_output)
{
  struct SHA1Context ctx;
  unsigned char output[20];
  int ok;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:173");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:174");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:175");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:177");
  SHA1_init(&ctx);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:178");
  SHA1_add_data(&ctx, txt, strlen((char *) txt));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:179");
  SHA1_finish(&ctx, output);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:180");
  ok = memcmp(output, expected_output, 20) == 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:181");
  printf("Test `%s': %s\n", (char *) txt, ok ? "passed" : "FAILED");
}

unsigned char test_input_1[4] = {97, 98, 99, 0, };

unsigned char test_output_1[20] =
  {0xA9, 0x99, 0x3E, 0x36, 0x47, 0x06, 0x81, 0x6A, 0xBA, 0x3E, 0x25, 
   0x71, 0x78, 0x50, 0xC2, 0x6C, 0x9C, 0xD0, 0xD8, 0x9D, };

unsigned char test_input_2[57] =
  {97, 98, 99, 100, 98, 99, 100, 101, 99, 100, 101, 102, 100, 101, 102, 
   103, 101, 102, 103, 104, 102, 103, 104, 105, 103, 104, 105, 106, 104, 
   105, 106, 107, 105, 106, 107, 108, 106, 107, 108, 109, 107, 108, 109, 
   110, 108, 109, 110, 111, 109, 110, 111, 112, 110, 111, 112, 113, 0, };

unsigned char test_output_2[20] =
  {0x84, 0x98, 0x3E, 0x44, 0x1C, 0x3B, 0xD2, 0x6E, 0xBA, 0xAE, 0x4A, 
   0xA1, 0xF9, 0x51, 0x29, 0xE5, 0xE5, 0x46, 0x70, 0xF1, };

static void do_bench_711(int nblocks)
{
  struct SHA1Context ctx;
  unsigned char output[20];
  unsigned char data[64];
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:210");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:211");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:212");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:213");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:215");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 64;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    data[i] = i;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:216");
  SHA1_init(&ctx);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:217");
  for (/*nothing*/; nblocks > 0; __builtin_debug(6, "", 1), nblocks--) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:218");
    SHA1_add_data(&ctx, data, 64);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:219");
  SHA1_finish(&ctx, output);
}

union _u35ba321634bad00d12b34420f9d36e22;

union _u35ba321634bad00d12b34420f9d36e22 {
  int i;
  unsigned char b[4];
};

int main(int argc, char * * argv)
{
  union _u35ba321634bad00d12b34420f9d36e22 u;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:225");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:226");
  u.i = 0x12345678;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:228");
  switch (u.b[0]) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:229");
    case 0x12:
    __builtin_debug(6, "", 1);
    arch_big_endian_664 = 1;
    break;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:230");
    case 0x78:
    __builtin_debug(6, "", 1);
    arch_big_endian_664 = 0;
    break;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:sha1.c:231");
    default:
    __builtin_debug(6, "", 1);
    printf("Cannot determine endianness\n");
    __builtin_debug(6, "", 1);
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:233");
  do_test_701(test_input_1, test_output_1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:234");
  do_test_701(test_input_2, test_output_2);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:235");
  do_bench_711(2000000);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:sha1.c:236");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


