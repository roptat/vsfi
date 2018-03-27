double fade_1339(double);

double lerp_1344(double, double, double);

double grad_1350(int, double, double, double);

double noise_1358(double, double, double);

void init_1373(void);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_e958bf2e20037033863cab7581578e811[6] = "%.4e\012";

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

extern double floor(double);

extern int printf(/*signed*/ char *, ...);

int p_1336[512];

static int permutation_1337[256] = { 151, 160, 137, 91, 90, 15, 131, 13, 201,
  95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240,
  21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219,
  203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136,
  171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231,
  83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40,
  244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208,
  89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198,
  173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126,
  255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 223,
  183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167,
  43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178,
  185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193, 238, 210, 144, 12,
  191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31,
  181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
  138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66,
  215, 61, 156, 180, };

double fade_1339(double t)
{
  builtin debug6 ""();
  builtin debug1 "#line:perlin.c:24"();
  return t * t * t * (t * (t * 6 - 15) + 10);
}

double lerp_1344(double t, double a, double b)
{
  builtin debug6 ""();
  builtin debug1 "#line:perlin.c:26"();
  return a + t * (b - a);
}

double grad_1350(int hash, double x, double y, double z)
{
  int h;
  double u;
  double v;
  register double $194;
  register double $193;
  register double $192;
  register int $191;
  register double $190;
  register double $189;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:29"();
  h = hash & 15;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:30"();
  if (h < 8) {
    $189 = (double) x;
  } else {
    $189 = (double) y;
  }
  u = $189;
  builtin debug6 ""(1);
  if (h < 4) {
    $190 = (double) y;
  } else {
    if (h == 12) {
      $191 = 1;
    } else {
      $191 = (_Bool) (h == 14);
    }
    if ($191) {
      $192 = (double) x;
      $190 = (double) $192;
    } else {
      $192 = (double) z;
      $190 = (double) $192;
    }
  }
  v = $190;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:32"();
  if ((h & 1) == 0) {
    $193 = (double) u;
  } else {
    $193 = (double) -u;
  }
  if ((h & 2) == 0) {
    $194 = (double) v;
  } else {
    $194 = (double) -v;
  }
  return $193 + $194;
}

double noise_1358(double x, double y, double z)
{
  int X;
  int Y;
  int Z;
  double u;
  double v;
  double w;
  int A;
  int AA;
  int AB;
  int B;
  int BA;
  int BB;
  register double $212;
  register double $211;
  register double $210;
  register double $209;
  register double $208;
  register double $207;
  register double $206;
  register double $205;
  register double $204;
  register double $203;
  register double $202;
  register double $201;
  register double $200;
  register double $199;
  register double $198;
  register double $197;
  register double $196;
  register double $195;
  register double $194;
  register double $193;
  register double $192;
  register double $191;
  register double $190;
  register double $189;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:36"();
  $189 = floor(x);
  X = (int) $189 & 255;
  builtin debug6 ""(1);
  $190 = floor(y);
  Y = (int) $190 & 255;
  builtin debug6 ""(1);
  $191 = floor(z);
  Z = (int) $191 & 255;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:39"();
  $192 = floor(x);
  x = x - $192;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:40"();
  $193 = floor(y);
  y = y - $193;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:41"();
  $194 = floor(z);
  z = z - $194;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:42"();
  $195 = fade_1339(x);
  u = $195;
  builtin debug6 ""(1);
  $196 = fade_1339(y);
  v = $196;
  builtin debug6 ""(1);
  $197 = fade_1339(z);
  w = $197;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:45"();
  A = *(p_1336 + X) + Y;
  builtin debug6 ""(1);
  AA = *(p_1336 + A) + Z;
  builtin debug6 ""(1);
  AB = *(p_1336 + (A + 1)) + Z;
  builtin debug6 ""(1);
  B = *(p_1336 + (X + 1)) + Y;
  builtin debug6 ""(1);
  BA = *(p_1336 + B) + Z;
  builtin debug6 ""(1);
  BB = *(p_1336 + (B + 1)) + Z;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:48"();
  $198 = grad_1350(*(p_1336 + AA), x, y, z);
  $199 = grad_1350(*(p_1336 + BA), x - 1, y, z);
  $200 = lerp_1344(u, $198, $199);
  $201 = grad_1350(*(p_1336 + AB), x, y - 1, z);
  $202 = grad_1350(*(p_1336 + BB), x - 1, y - 1, z);
  $203 = lerp_1344(u, $201, $202);
  $204 = lerp_1344(v, $200, $203);
  $205 = grad_1350(*(p_1336 + (AA + 1)), x, y, z - 1);
  $206 = grad_1350(*(p_1336 + (BA + 1)), x - 1, y, z - 1);
  $207 = lerp_1344(u, $205, $206);
  $208 = grad_1350(*(p_1336 + (AB + 1)), x, y - 1, z - 1);
  $209 = grad_1350(*(p_1336 + (BB + 1)), x - 1, y - 1, z - 1);
  $210 = lerp_1344(u, $208, $209);
  $211 = lerp_1344(v, $207, $210);
  $212 = lerp_1344(w, $204, $211);
  return $212;
}

void init_1373(void)
{
  int i;
  register int $189;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:59"();
  i = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:60"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 256)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:perlin.c:61"();
    $189 = (int) *(permutation_1337 + i);
    *(p_1336 + i) = $189;
    *(p_1336 + (256 + i)) = $189;
  }
}

int main(int argc, /*signed*/ char **argv)
{
  double x;
  double y;
  double z;
  double sum;
  register double $189;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:65"();
  init_1373();
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:67"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  sum = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:68"();
  builtin debug6 ""(1);
  x = -11352.5699999999997;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       x = x + 0.123499999999999999) {
    if (! (x < 23561.5699999999997)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:perlin.c:69"();
    builtin debug6 ""(1);
    y = -346.123499999999979;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         y = y + 1.43250000000000011) {
      if (! (y < 124.123999999999995)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:perlin.c:70"();
      builtin debug6 ""(1);
      z = -156.235000000000014;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           y = y + 2.45000000000000018) {
        if (! (y < 23.2345000000000006)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:perlin.c:71"();
        $189 = noise_1358(x, y, z);
        sum = sum + $189;
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:73"();
  printf(__stringlit_e958bf2e20037033863cab7581578e811, sum);
  builtin debug6 ""(1);
  builtin debug1 "#line:perlin.c:74"();
  return 0;
  builtin debug6 ""();
  return 0;
}


