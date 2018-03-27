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

void SHA1_copy_and_swap_668(void *, void *, int);

void SHA1_transform_675(struct SHA1Context *);

void SHA1_init(struct SHA1Context *);

void SHA1_add_data(struct SHA1Context *, unsigned char *, unsigned int);

void SHA1_finish(struct SHA1Context *, unsigned char *);

void do_test_701(unsigned char *, unsigned char *);

void do_bench_711(int);

int main(int, /*signed*/ char **);

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
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:25"();
  if (arch_big_endian_664) {
    builtin debug6 ""();
    builtin debug1 "#line:sha1.c:26"();
    memcpy(dst, src, numwords * sizeof(unsigned int));
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:28"();
    builtin debug6 ""(1);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:29"();
    builtin debug6 ""(1);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:30"();
    builtin debug6 ""(1);
    s = src;
    d = dst;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         s = s + 4, d = d + 4, numwords = numwords - 1) {
      if (! (numwords > 0)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:31"();
      a = *(s + 0);
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:32"();
      b = *(s + 1);
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:33"();
      *(d + 0) = *(s + 3);
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:34"();
      *(d + 1) = *(s + 2);
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:35"();
      *(d + 2) = b;
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:36"();
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
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:52"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:53"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:54"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:57"();
  SHA1_copy_and_swap_668((*ctx).buffer, data, 16);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:60"();
  builtin debug6 ""(1);
  i = 16;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 80)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:61"();
    t =
      *(data + (i - 3)) ^ *(data + (i - 8)) ^ *(data + (i - 14))
        ^ *(data + (i - 16));
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:62"();
    *(data + i) = t << 1 | t >> 31;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:66"();
  a = *((*ctx).state + 0);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:67"();
  b = *((*ctx).state + 1);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:68"();
  c = *((*ctx).state + 2);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:69"();
  d = *((*ctx).state + 3);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:70"();
  e = *((*ctx).state + 4);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:73"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 20)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:74"();
    t =
      (d ^ b & (c ^ d)) + 1518500249U + (a << 5 | a >> 27) + e + *(data + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:75"();
    e = d;
    builtin debug6 ""(1);
    d = c;
    builtin debug6 ""(1);
    c = b << 30 | b >> 2;
    builtin debug6 ""(1);
    b = a;
    builtin debug6 ""(1);
    a = t;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:77"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 40)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:78"();
    t = (b ^ c ^ d) + 1859775393U + (a << 5 | a >> 27) + e + *(data + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:79"();
    e = d;
    builtin debug6 ""(1);
    d = c;
    builtin debug6 ""(1);
    c = b << 30 | b >> 2;
    builtin debug6 ""(1);
    b = a;
    builtin debug6 ""(1);
    a = t;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:81"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 60)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:82"();
    t =
      (b & c | d & (b | c)) + 2400959708U + (a << 5 | a >> 27) + e
        + *(data + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:83"();
    e = d;
    builtin debug6 ""(1);
    d = c;
    builtin debug6 ""(1);
    c = b << 30 | b >> 2;
    builtin debug6 ""(1);
    b = a;
    builtin debug6 ""(1);
    a = t;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:85"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 80)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:86"();
    t = (b ^ c ^ d) + 3395469782U + (a << 5 | a >> 27) + e + *(data + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:87"();
    e = d;
    builtin debug6 ""(1);
    d = c;
    builtin debug6 ""(1);
    c = b << 30 | b >> 2;
    builtin debug6 ""(1);
    b = a;
    builtin debug6 ""(1);
    a = t;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:91"();
  *((*ctx).state + 0) = *((*ctx).state + 0) + a;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:92"();
  *((*ctx).state + 1) = *((*ctx).state + 1) + b;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:93"();
  *((*ctx).state + 2) = *((*ctx).state + 2) + c;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:94"();
  *((*ctx).state + 3) = *((*ctx).state + 3) + d;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:95"();
  *((*ctx).state + 4) = *((*ctx).state + 4) + e;
}

void SHA1_init(struct SHA1Context *ctx)
{
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:100"();
  *((*ctx).state + 0) = 1732584193U;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:101"();
  *((*ctx).state + 1) = 4023233417U;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:102"();
  *((*ctx).state + 2) = 2562383102U;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:103"();
  *((*ctx).state + 3) = 271733878U;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:104"();
  *((*ctx).state + 4) = 3285377520U;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:105"();
  (*ctx).numbytes = 0;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:106"();
  *((*ctx).length + 0) = 0;
  builtin debug6 ""();
  builtin debug1 "#line:sha1.c:107"();
  *((*ctx).length + 1) = 0;
}

void SHA1_add_data(struct SHA1Context *ctx, unsigned char *data, unsigned int len)
{
  unsigned int t;
  register unsigned int $278;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:113"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:116"();
  t = *((*ctx).length + 1);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:117"();
  $278 = (unsigned int) (t + (unsigned int) (len << 3));
  *((*ctx).length + 1) = $278;
  if ($278 < t) {
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:118"();
    *((*ctx).length + 0) = *((*ctx).length + 0) + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:119"();
  *((*ctx).length + 0) = *((*ctx).length + 0) + (unsigned int) (len >> 29);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:122"();
  if ((*ctx).numbytes != 0) {
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:123"();
    t = 64 - (*ctx).numbytes;
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:124"();
    if (len < t) {
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:125"();
      memcpy((*ctx).buffer + (*ctx).numbytes, data, len);
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:126"();
      (*ctx).numbytes = (*ctx).numbytes + len;
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:127"();
      return;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:129"();
    memcpy((*ctx).buffer + (*ctx).numbytes, data, t);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:130"();
    SHA1_transform_675(ctx);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:131"();
    data = data + t;
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:132"();
    len = len - t;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:135"();
  while (1) {
    if (! (len >= 64)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:136"();
    memcpy((*ctx).buffer, data, 64);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:137"();
    SHA1_transform_675(ctx);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:138"();
    data = data + 64;
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:139"();
    len = len - 64;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:142"();
  memcpy((*ctx).buffer, data, len);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:143"();
  (*ctx).numbytes = len;
}

void SHA1_finish(struct SHA1Context *ctx, unsigned char *output)
{
  int i;
  register int $278;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:148"();
  i = (*ctx).numbytes;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:151"();
  $278 = i;
  i = $278 + 1;
  *((*ctx).buffer + $278) = 128;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:154"();
  if (i > 56) {
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:155"();
    memset((*ctx).buffer + i, 0, 64 - i);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:156"();
    SHA1_transform_675(ctx);
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:157"();
    i = 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:160"();
  memset((*ctx).buffer + i, 0, 56 - i);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:162"();
  SHA1_copy_and_swap_668((*ctx).length, (*ctx).buffer + 56, 2);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:164"();
  SHA1_transform_675(ctx);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:166"();
  SHA1_copy_and_swap_668((*ctx).state, output, 5);
}

void do_test_701(unsigned char *txt, unsigned char *expected_output)
{
  struct SHA1Context ctx;
  unsigned char output[20];
  int ok;
  register /*signed*/ char *$280;
  register int $279;
  register unsigned int $278;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:173"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:174"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:175"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:177"();
  SHA1_init(&ctx);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:178"();
  $278 = strlen((/*signed*/ char *) txt);
  SHA1_add_data(&ctx, txt, $278);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:179"();
  SHA1_finish(&ctx, output);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:180"();
  $279 = memcmp(output, expected_output, 20);
  ok = $279 == 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:181"();
  if (ok) {
    $280 = (/*signed*/ char *) __stringlit_f10ceaae9a2551145b2c54ac2a4f053c2;
  } else {
    $280 = (/*signed*/ char *) __stringlit_f10ceaae9a2551145b2c54ac2a4f053c1;
  }
  printf
    (__stringlit_f10ceaae9a2551145b2c54ac2a4f053c3, (/*signed*/ char *) txt,
     $280);
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
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:210"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:211"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:212"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:213"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:215"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 64)) {
      break;
    }
    builtin debug6 ""(1);
    *(data + i) = i;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:216"();
  SHA1_init(&ctx);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:217"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       nblocks = nblocks - 1) {
    if (! (nblocks > 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:sha1.c:218"();
    SHA1_add_data(&ctx, data, 64);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:219"();
  SHA1_finish(&ctx, output);
}

int main(int argc, /*signed*/ char **argv)
{
  union _u35ba321634bad00d12b34420f9d36e22 u;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:225"();
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:226"();
  u.i = 305419896;
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:228"();
  switch (*(u.b + 0)) {
    case 18:
      builtin debug6 ""(1);
      arch_big_endian_664 = 1;
      break;
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:230"();
    case 120:
      builtin debug6 ""(1);
      arch_big_endian_664 = 0;
      break;
      builtin debug6 ""(1);
      builtin debug1 "#line:sha1.c:231"();
    default:
      builtin debug6 ""(1);
      printf(__stringlit_f10ceaae9a2551145b2c54ac2a4f053c4);
      builtin debug6 ""(1);
      return 2;
    
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:233"();
  do_test_701(test_input_1, test_output_1);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:234"();
  do_test_701(test_input_2, test_output_2);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:235"();
  do_bench_711(2000000);
  builtin debug6 ""(1);
  builtin debug1 "#line:sha1.c:236"();
  return 0;
  builtin debug6 ""();
  return 0;
}


