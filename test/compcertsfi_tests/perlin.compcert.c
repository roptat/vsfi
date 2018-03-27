static /*signed*/ char const __stringlit_e958bf2e20037033863cab7581578e811[6];

extern unsigned int keep[2];

static int p_1336[512];

static int permutation_1337[256];

static double fade_1339(double);

static double lerp_1344(double, double, double);

static double grad_1350(int, double, double, double);

static double noise_1358(double, double, double);

static void init_1373(void);

extern int main(int, /*signed*/ char **);

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
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:perlin.c:24");
  return t * t * t * (t * (t * 6 - 15) + 10);
}

double lerp_1344(double t, double a, double b)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:perlin.c:26");
  return a + t * (b - a);
}

double grad_1350(int hash, double x, double y, double z)
{
  int h;
  double u;
  double v;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:29");
  h = hash & 15;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:30");
  u = h < 8 ? x : y;
  __builtin_debug(6,"", 1);
  v = h < 4 ? y : (h == 12 || h == 14 ? x : z);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:32");
  return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
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
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:36");
  X = (int) floor(x) & 255;
  __builtin_debug(6,"", 1);
  Y = (int) floor(y) & 255;
  __builtin_debug(6,"", 1);
  Z = (int) floor(z) & 255;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:39");
  x -= floor(x);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:40");
  y -= floor(y);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:41");
  z -= floor(z);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:42");
  u = fade_1339(x);
  __builtin_debug(6,"", 1);
  v = fade_1339(y);
  __builtin_debug(6,"", 1);
  w = fade_1339(z);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:45");
  A = *(p_1336 + X) + Y;
  __builtin_debug(6,"", 1);
  AA = *(p_1336 + A) + Z;
  __builtin_debug(6,"", 1);
  AB = *(p_1336 + (A + 1)) + Z;
  __builtin_debug(6,"", 1);
  B = *(p_1336 + (X + 1)) + Y;
  __builtin_debug(6,"", 1);
  BA = *(p_1336 + B) + Z;
  __builtin_debug(6,"", 1);
  BB = *(p_1336 + (B + 1)) + Z;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:48");
  return lerp_1344(w,
                   lerp_1344(v,
                             lerp_1344(u, grad_1350(*(p_1336 + AA), x, y, z),
                                       grad_1350(*(p_1336 + BA), x - 1, y, z)),
                             lerp_1344(u,
                                       grad_1350(*(p_1336 + AB), x, y - 1, z),
                                       grad_1350(*(p_1336 + BB), x - 1,
                                                 y - 1, z))),
                   lerp_1344(v,
                             lerp_1344(u,
                                       grad_1350(*(p_1336 + (AA + 1)), 
                                                 x, y, z - 1),
                                       grad_1350(*(p_1336 + (BA + 1)), 
                                                 x - 1, y, z - 1)),
                             lerp_1344(u,
                                       grad_1350(*(p_1336 + (AB + 1)), 
                                                 x, y - 1, z - 1),
                                       grad_1350(*(p_1336 + (BB + 1)), 
                                                 x - 1, y - 1, z - 1))));
}

void init_1373(void)
{
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:59");
  i = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:60");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 256;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:perlin.c:61");
    *(p_1336 + (256 + i)) = *(p_1336 + i) = *(permutation_1337 + i);
  }
}

int main(int argc, /*signed*/ char **argv)
{
  double x;
  double y;
  double z;
  double sum;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:65");
  init_1373();
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:67");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  sum = 0.;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:68");
  for (__builtin_debug(6,"", 1), x = -11352.57;
       x < 23561.57;
       __builtin_debug(6,"", 1), x += 0.1235) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:perlin.c:69");
    for (__builtin_debug(6,"", 1), y = -346.1235;
         y < 124.124;
         __builtin_debug(6,"", 1), y += 1.4325) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:perlin.c:70");
      for (__builtin_debug(6,"", 1), z = -156.235;
           y < 23.2345;
           __builtin_debug(6,"", 1), y += 2.45) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:perlin.c:71");
        sum += noise_1358(x, y, z);
      }
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:73");
  printf(__stringlit_e958bf2e20037033863cab7581578e811, sum);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:perlin.c:74");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


