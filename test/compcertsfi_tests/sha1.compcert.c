struct SHA1Context;
union _u35ba321634bad00d12b34420f9d36e22;
struct SHA1Context {
  unsigned int state[5];
  unsigned int length[2];
  int numbytes;
  unsigned char buffer[64];
};

union _u35ba321634bad00d12b34420f9d36e22 {
  int i;
  unsigned char b[4];
};

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c2[7];

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c4[29];

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c3[15];

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c1[7];

extern unsigned int keep[2];

static int arch_big_endian_664;

static void SHA1_copy_and_swap_668(void *, void *, int);

static void SHA1_transform_675(struct SHA1Context *);

extern void SHA1_init(struct SHA1Context *);

extern void SHA1_add_data(struct SHA1Context *, unsigned char *, unsigned int);

extern void SHA1_finish(struct SHA1Context *, unsigned char *);

static void do_test_701(unsigned char *, unsigned char *);

extern unsigned char test_input_1[4];

extern unsigned char test_output_1[20];

extern unsigned char test_input_2[57];

extern unsigned char test_output_2[20];

static void do_bench_711(int);

extern int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c2[7] = "passed";

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c4[29] = "Cannot determine endianness\012";

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c3[15] = "Test `%s': %s\012";

static /*signed*/ char const __stringlit_f10ceaae9a2551145b2c54ac2a4f053c1[7] = "FAILED";

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

extern void *memcpy(void *, void *, unsigned int);

extern void *memset(void *, int, unsigned int);

extern int memcmp(void *, void *, unsigned int);

extern unsigned int strlen(/*signed*/ char *);

extern int printf(/*signed*/ char *, ...);

int arch_big_endian_664;

void SHA1_copy_and_swap_668(void *src, void *dst, int numwords)
{
  unsigned char *s;
  unsigned char *d;
  unsigned char a;
  unsigned char b;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:25");
  if (arch_big_endian_664) {
    __builtin_debug(6,"");
    __builtin_debug(1,"#line:sha1.c:26");
    memcpy(dst, src, numwords * sizeof(unsigned int));
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:28");
    __builtin_debug(6,"", 1);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:29");
    __builtin_debug(6,"", 1);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:30");
    for (__builtin_debug(6,"", 1), s = src, d = dst;
         numwords > 0;
         __builtin_debug(6,"", 1), s += 4, d += 4, numwords--) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:31");
      a = *(s + 0);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:32");
      b = *(s + 1);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:33");
      *(d + 0) = *(s + 3);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:34");
      *(d + 1) = *(s + 2);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:35");
      *(d + 2) = b;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:36");
      *(d + 3) = a;
    }
  }
}

void SHA1_transform_675(struct SHA1Context *ctx)
{
  int i;
  unsigned int a;
  unsigned int b;
  unsigned int c;
  unsigned int d;
  unsigned int e;
  unsigned int t;
  unsigned int data[80];
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:52");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:53");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:54");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:57");
  SHA1_copy_and_swap_668(((*ctx)).buffer, data, 16);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:60");
  for (__builtin_debug(6,"", 1), i = 16;
       i < 80;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:61");
    t =
      *(data + (i - 3)) ^ *(data + (i - 8)) ^ *(data + (i - 14))
        ^ *(data + (i - 16));
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:62");
    *(data + i) = t << 1 | t >> 31;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:66");
  a = *(((*ctx)).state + 0);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:67");
  b = *(((*ctx)).state + 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:68");
  c = *(((*ctx)).state + 2);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:69");
  d = *(((*ctx)).state + 3);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:70");
  e = *(((*ctx)).state + 4);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:73");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 20;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:74");
    t =
      (d ^ b & (c ^ d)) + 1518500249U + (a << 5 | a >> 27) + e + *(data + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:75");
    e = d;
    __builtin_debug(6,"", 1);
    d = c;
    __builtin_debug(6,"", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6,"", 1);
    b = a;
    __builtin_debug(6,"", 1);
    a = t;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:77");
  for (/*nothing*/; i < 40; __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:78");
    t = (b ^ c ^ d) + 1859775393U + (a << 5 | a >> 27) + e + *(data + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:79");
    e = d;
    __builtin_debug(6,"", 1);
    d = c;
    __builtin_debug(6,"", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6,"", 1);
    b = a;
    __builtin_debug(6,"", 1);
    a = t;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:81");
  for (/*nothing*/; i < 60; __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:82");
    t =
      (b & c | d & (b | c)) + 2400959708U + (a << 5 | a >> 27) + e
        + *(data + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:83");
    e = d;
    __builtin_debug(6,"", 1);
    d = c;
    __builtin_debug(6,"", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6,"", 1);
    b = a;
    __builtin_debug(6,"", 1);
    a = t;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:85");
  for (/*nothing*/; i < 80; __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:86");
    t = (b ^ c ^ d) + 3395469782U + (a << 5 | a >> 27) + e + *(data + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:87");
    e = d;
    __builtin_debug(6,"", 1);
    d = c;
    __builtin_debug(6,"", 1);
    c = b << 30 | b >> 2;
    __builtin_debug(6,"", 1);
    b = a;
    __builtin_debug(6,"", 1);
    a = t;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:91");
  *(((*ctx)).state + 0) += a;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:92");
  *(((*ctx)).state + 1) += b;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:93");
  *(((*ctx)).state + 2) += c;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:94");
  *(((*ctx)).state + 3) += d;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:95");
  *(((*ctx)).state + 4) += e;
}

void SHA1_init(struct SHA1Context *ctx)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:100");
  *(((*ctx)).state + 0) = 1732584193U;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:101");
  *(((*ctx)).state + 1) = 4023233417U;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:102");
  *(((*ctx)).state + 2) = 2562383102U;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:103");
  *(((*ctx)).state + 3) = 271733878U;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:104");
  *(((*ctx)).state + 4) = 3285377520U;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:105");
  ((*ctx)).numbytes = 0;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:106");
  *(((*ctx)).length + 0) = 0;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:sha1.c:107");
  *(((*ctx)).length + 1) = 0;
}

void SHA1_add_data(struct SHA1Context *ctx, unsigned char *data, unsigned int len)
{
  unsigned int t;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:113");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:116");
  t = *(((*ctx)).length + 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:117");
  if ((*(((*ctx)).length + 1) = t + (unsigned int) (len << 3)) < t) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:118");
    (*(((*ctx)).length + 0))++;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:119");
  *(((*ctx)).length + 0) += (unsigned int) (len >> 29);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:122");
  if (((*ctx)).numbytes != 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:123");
    t = 64 - ((*ctx)).numbytes;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:124");
    if (len < t) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:125");
      memcpy(((*ctx)).buffer + ((*ctx)).numbytes, data, len);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:126");
      ((*ctx)).numbytes += len;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:127");
      return;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:129");
    memcpy(((*ctx)).buffer + ((*ctx)).numbytes, data, t);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:130");
    SHA1_transform_675(ctx);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:131");
    data += t;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:132");
    len -= t;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:135");
  while (len >= 64) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:136");
    memcpy(((*ctx)).buffer, data, 64);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:137");
    SHA1_transform_675(ctx);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:138");
    data += 64;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:139");
    len -= 64;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:142");
  memcpy(((*ctx)).buffer, data, len);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:143");
  ((*ctx)).numbytes = len;
}

void SHA1_finish(struct SHA1Context *ctx, unsigned char *output)
{
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:148");
  i = ((*ctx)).numbytes;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:151");
  *(((*ctx)).buffer + i++) = 128;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:154");
  if (i > 56) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:155");
    memset(((*ctx)).buffer + i, 0, 64 - i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:156");
    SHA1_transform_675(ctx);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:157");
    i = 0;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:160");
  memset(((*ctx)).buffer + i, 0, 56 - i);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:162");
  SHA1_copy_and_swap_668(((*ctx)).length, ((*ctx)).buffer + 56, 2);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:164");
  SHA1_transform_675(ctx);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:166");
  SHA1_copy_and_swap_668(((*ctx)).state, output, 5);
}

void do_test_701(unsigned char *txt, unsigned char *expected_output)
{
  struct SHA1Context ctx;
  unsigned char output[20];
  int ok;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:173");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:174");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:175");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:177");
  SHA1_init(&ctx);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:178");
  SHA1_add_data(&ctx, txt, strlen((/*signed*/ char *) txt));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:179");
  SHA1_finish(&ctx, output);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:180");
  ok = memcmp(output, expected_output, 20) == 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:181");
  printf(__stringlit_f10ceaae9a2551145b2c54ac2a4f053c3,
         (/*signed*/ char *) txt,
         ok ? __stringlit_f10ceaae9a2551145b2c54ac2a4f053c2
           : __stringlit_f10ceaae9a2551145b2c54ac2a4f053c1);
}

 unsigned char test_input_1[4] = { 97, 98, 99, 0, };

 unsigned char test_output_1[20] = { 169, 153, 62, 54, 71, 6, 129, 106, 186,
  62, 37, 113, 120, 80, 194, 108, 156, 208, 216, 157, };

 unsigned char test_input_2[57] = { 97, 98, 99, 100, 98, 99, 100, 101, 99,
  100, 101, 102, 100, 101, 102, 103, 101, 102, 103, 104, 102, 103, 104, 105,
  103, 104, 105, 106, 104, 105, 106, 107, 105, 106, 107, 108, 106, 107, 108,
  109, 107, 108, 109, 110, 108, 109, 110, 111, 109, 110, 111, 112, 110, 111,
  112, 113, 0, };

 unsigned char test_output_2[20] = { 132, 152, 62, 68, 28, 59, 210, 110, 186,
  174, 74, 161, 249, 81, 41, 229, 229, 70, 112, 241, };

void do_bench_711(int nblocks)
{
  struct SHA1Context ctx;
  unsigned char output[20];
  unsigned char data[64];
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:210");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:211");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:212");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:213");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:215");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 64;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    *(data + i) = i;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:216");
  SHA1_init(&ctx);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:217");
  for (/*nothing*/; nblocks > 0; __builtin_debug(6,"", 1), nblocks--) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:sha1.c:218");
    SHA1_add_data(&ctx, data, 64);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:219");
  SHA1_finish(&ctx, output);
}

int main(int argc, /*signed*/ char **argv)
{
  union _u35ba321634bad00d12b34420f9d36e22 u;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:225");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:226");
  u.i = 305419896;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:228");
  switch (*(u.b + 0)) {
    case 18:
      __builtin_debug(6,"", 1);
      arch_big_endian_664 = 1;
      break;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:230");
    case 120:
      __builtin_debug(6,"", 1);
      arch_big_endian_664 = 0;
      break;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:sha1.c:231");
    default:
      __builtin_debug(6,"", 1);
      printf(__stringlit_f10ceaae9a2551145b2c54ac2a4f053c4);
      __builtin_debug(6,"", 1);
      return 2;
    
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:233");
  do_test_701(test_input_1, test_output_1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:234");
  do_test_701(test_input_2, test_output_2);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:235");
  do_bench_711(2000000);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:sha1.c:236");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


