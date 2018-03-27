int dfft(float *, float *, int);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_b49096b4fda467f566c72e63915f4b502[22] = "%d points, result OK\012";

static /*signed*/ char const __stringlit_b49096b4fda467f566c72e63915f4b501[28] = "%d points, WRONG result %e\012";

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

extern float cosf(float);

extern float sinf(float);

extern float fabsf(float);

extern int atoi(/*signed*/ char *);

extern void *calloc(unsigned int, unsigned int);

extern int printf(/*signed*/ char *, ...);

int dfft(float *x, float *y, int np)
{
  float *px;
  float *py;
  int i;
  int j;
  int k;
  int m;
  int n;
  int i0;
  int i1;
  int i2;
  int i3;
  int is;
  int id;
  int n1;
  int n2;
  int n4;
  float a;
  float e;
  float a3;
  float cc1;
  float ss1;
  float cc3;
  float ss3;
  float r1;
  float r2;
  float s1;
  float s2;
  float s3;
  float xt;
  float tpi;
  register float $313;
  register float $312;
  register float $311;
  register float $310;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:25"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:26"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:27"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:29"();
  px = x - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:30"();
  py = y - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:31"();
  i = 2;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:32"();
  m = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:34"();
  while (1) {
    if (! (i < np)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:36"();
    i = i + i;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:37"();
    m = m + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:40"();
  n = i;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:42"();
  if (n != np) {
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:43"();
    builtin debug6 ""(1);
    i = np + 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         i = i + 1) {
      if (! (i <= n)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:44"();
      *(px + i) = 0;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:45"();
      *(py + i) = 0;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:50"();
  n2 = n + n;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:51"();
  tpi = 2 * 3.14159265358979312;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:52"();
  builtin debug6 ""(1);
  k = 1;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k <= m - 1)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:53"();
    n2 = n2 / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:54"();
    n4 = n2 / 4;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:55"();
    e = tpi / (float) n2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:56"();
    a = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:58"();
    builtin debug6 ""(1);
    j = 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j <= n4)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:59"();
      a3 = 3 * a;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:60"();
      $310 = cosf(a);
      cc1 = $310;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:61"();
      $311 = sinf(a);
      ss1 = $311;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:63"();
      $312 = cosf(a3);
      cc3 = $312;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:64"();
      $313 = sinf(a3);
      ss3 = $313;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:65"();
      a = e * (float) j;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:66"();
      is = j;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:67"();
      id = 2 * n2;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:69"();
      while (1) {
        if (! (is < n)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:fftsp.c:70"();
        builtin debug6 ""(1);
        i0 = is;
        for (;
             1;
             (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
             i0 = i0 + id) {
          if (! (i0 <= n - 1)) {
            break;
          }
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:71"();
          i1 = i0 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:72"();
          i2 = i1 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:73"();
          i3 = i2 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:74"();
          r1 = *(px + i0) - *(px + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:75"();
          *(px + i0) = *(px + i0) + *(px + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:76"();
          r2 = *(px + i1) - *(px + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:77"();
          *(px + i1) = *(px + i1) + *(px + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:78"();
          s1 = *(py + i0) - *(py + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:79"();
          *(py + i0) = *(py + i0) + *(py + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:80"();
          s2 = *(py + i1) - *(py + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:81"();
          *(py + i1) = *(py + i1) + *(py + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:82"();
          s3 = r1 - s2;
          builtin debug6 ""(1);
          r1 = r1 + s2;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:83"();
          s2 = r2 - s1;
          builtin debug6 ""(1);
          r2 = r2 + s1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:84"();
          *(px + i2) = r1 * cc1 - s2 * ss1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:85"();
          *(py + i2) = -s2 * cc1 - r1 * ss1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:86"();
          *(px + i3) = s3 * cc3 + r2 * ss3;
          builtin debug6 ""(1);
          builtin debug1 "#line:fftsp.c:87"();
          *(py + i3) = r2 * cc3 - s3 * ss3;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:fftsp.c:89"();
        is = 2 * id - n2 + j;
        builtin debug6 ""(1);
        builtin debug1 "#line:fftsp.c:90"();
        id = 4 * id;
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:98"();
  is = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:99"();
  id = 4;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:101"();
  while (1) {
    if (! (is < n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:102"();
    builtin debug6 ""(1);
    i0 = is;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         i0 = i0 + id) {
      if (! (i0 <= n)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:103"();
      i1 = i0 + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:104"();
      r1 = *(px + i0);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:105"();
      *(px + i0) = r1 + *(px + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:106"();
      *(px + i1) = r1 - *(px + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:107"();
      r1 = *(py + i0);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:108"();
      *(py + i0) = r1 + *(py + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:109"();
      *(py + i1) = r1 - *(py + i1);
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:111"();
    is = 2 * id - 1;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:112"();
    id = 4 * id;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:118"();
  j = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:119"();
  n1 = n - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:121"();
  builtin debug6 ""(1);
  i = 1;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i <= n1)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:122"();
    if (i < j) {
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:123"();
      xt = *(px + j);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:124"();
      *(px + j) = *(px + i);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:125"();
      *(px + i) = xt;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:126"();
      xt = *(py + j);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:127"();
      *(py + j) = *(py + i);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:128"();
      *(py + i) = xt;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:131"();
    k = n / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:132"();
    while (1) {
      if (! (k < j)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:133"();
      j = j - k;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:134"();
      k = k / 2;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:136"();
    j = j + k;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:143"();
  return n;
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int np;
  int npm;
  int n2;
  int i;
  int j;
  int nruns;
  float enp;
  float t;
  float y;
  float z;
  float zr;
  float zi;
  float zm;
  float a;
  float *xr;
  float *xi;
  float *pxr;
  float *pxi;
  register float $316;
  register float $315;
  register float $314;
  register float $313;
  register void *$312;
  register void *$311;
  register int $310;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:152"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:153"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:154"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:156"();
  if (argc >= 2) {
    builtin debug6 ""(1);
    $310 = atoi(*(argv + 1));
    n = $310;
  } else {
    builtin debug6 ""(1);
    n = 12;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:157"();
  np = 1 << n;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:158"();
  enp = np;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:159"();
  npm = np / 2 - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:160"();
  t = 3.14159265358979312 / enp;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:161"();
  $311 = calloc(np, sizeof(float));
  xr = $311;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:162"();
  $312 = calloc(np, sizeof(float));
  xi = $312;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:163"();
  pxr = xr;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:164"();
  pxi = xi;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:165"();
  builtin debug6 ""(1);
  nruns = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       nruns = nruns + 1) {
    if (! (nruns < 3000)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:166"();
    *pxr = (enp - 1) * 0.5;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:167"();
    *pxi = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:168"();
    n2 = np / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:169"();
    *(pxr + n2) = -0.5;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:170"();
    *(pxi + n2) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:171"();
    builtin debug6 ""(1);
    i = 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         i = i + 1) {
      if (! (i <= npm)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:172"();
      j = np - i;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:173"();
      *(pxr + i) = -0.5;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:174"();
      *(pxr + j) = -0.5;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:175"();
      z = t * (float) i;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:176"();
      $313 = cosf(z);
      $314 = sinf(z);
      y = -0.5 * ($313 / $314);
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:177"();
      *(pxi + i) = y;
      builtin debug6 ""(1);
      builtin debug1 "#line:fftsp.c:178"();
      *(pxi + j) = -y;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:180"();
    dfft(xr, xi, np);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:182"();
  zr = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:183"();
  zi = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:184"();
  npm = np - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:185"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i <= npm)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:186"();
    $315 = fabsf(*(pxr + i) - i);
    a = $315;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:187"();
    if (zr < a) {
      builtin debug6 ""(1);
      zr = a;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:188"();
    $316 = fabsf(*(pxi + i));
    a = $316;
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:189"();
    if (zi < a) {
      builtin debug6 ""(1);
      zi = a;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:191"();
  zm = zr;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:192"();
  if (zr < zi) {
    builtin debug6 ""(1);
    zm = zi;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:193"();
  if (zm < 0.00100000000000000002) {
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:194"();
    printf(__stringlit_b49096b4fda467f566c72e63915f4b502, np);
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:fftsp.c:196"();
    printf(__stringlit_b49096b4fda467f566c72e63915f4b501, np, zm);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftsp.c:197"();
  return 0;
  builtin debug6 ""();
  return 0;
}


