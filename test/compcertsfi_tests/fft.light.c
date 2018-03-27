int dfft(double *, double *, int);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_edfbf49d0af608112e2c0c9e43cd14682[10] = "result OK";

static /*signed*/ char const __stringlit_edfbf49d0af608112e2c0c9e43cd14683[15] = "%d points, %s\012";

static /*signed*/ char const __stringlit_edfbf49d0af608112e2c0c9e43cd14681[13] = "WRONG result";

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

extern double cos(double);

extern double sin(double);

extern double fabs(double);

extern int atoi(/*signed*/ char *);

extern void *calloc(unsigned int, unsigned int);

extern int printf(/*signed*/ char *, ...);

int dfft(double *x, double *y, int np)
{
  double *px;
  double *py;
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
  double a;
  double e;
  double a3;
  double cc1;
  double ss1;
  double cc3;
  double ss3;
  double r1;
  double r2;
  double s1;
  double s2;
  double s3;
  double xt;
  double tpi;
  register double $303;
  register double $302;
  register double $301;
  register double $300;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:23"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:24"();
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
  builtin debug1 "#line:fft.c:25"();
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
  builtin debug1 "#line:fft.c:27"();
  px = x - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:28"();
  py = y - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:29"();
  i = 2;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:30"();
  m = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:32"();
  while (1) {
    if (! (i < np)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:34"();
    i = i + i;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:35"();
    m = m + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:38"();
  n = i;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:40"();
  if (n != np) {
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:41"();
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
      builtin debug1 "#line:fft.c:42"();
      *(px + i) = 0;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:43"();
      *(py + i) = 0;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:48"();
  n2 = n + n;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:49"();
  tpi = 2 * 3.14159265358979312;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:50"();
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
    builtin debug1 "#line:fft.c:51"();
    n2 = n2 / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:52"();
    n4 = n2 / 4;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:53"();
    e = tpi / (double) n2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:54"();
    a = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:56"();
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
      builtin debug1 "#line:fft.c:57"();
      a3 = 3 * a;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:58"();
      $300 = cos(a);
      cc1 = $300;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:59"();
      $301 = sin(a);
      ss1 = $301;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:61"();
      $302 = cos(a3);
      cc3 = $302;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:62"();
      $303 = sin(a3);
      ss3 = $303;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:63"();
      a = e * (double) j;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:64"();
      is = j;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:65"();
      id = 2 * n2;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:67"();
      while (1) {
        if (! (is < n)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:fft.c:68"();
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
          builtin debug1 "#line:fft.c:69"();
          i1 = i0 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:70"();
          i2 = i1 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:71"();
          i3 = i2 + n4;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:72"();
          r1 = *(px + i0) - *(px + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:73"();
          *(px + i0) = *(px + i0) + *(px + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:74"();
          r2 = *(px + i1) - *(px + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:75"();
          *(px + i1) = *(px + i1) + *(px + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:76"();
          s1 = *(py + i0) - *(py + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:77"();
          *(py + i0) = *(py + i0) + *(py + i2);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:78"();
          s2 = *(py + i1) - *(py + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:79"();
          *(py + i1) = *(py + i1) + *(py + i3);
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:80"();
          s3 = r1 - s2;
          builtin debug6 ""(1);
          r1 = r1 + s2;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:81"();
          s2 = r2 - s1;
          builtin debug6 ""(1);
          r2 = r2 + s1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:82"();
          *(px + i2) = r1 * cc1 - s2 * ss1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:83"();
          *(py + i2) = -s2 * cc1 - r1 * ss1;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:84"();
          *(px + i3) = s3 * cc3 + r2 * ss3;
          builtin debug6 ""(1);
          builtin debug1 "#line:fft.c:85"();
          *(py + i3) = r2 * cc3 - s3 * ss3;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:fft.c:87"();
        is = 2 * id - n2 + j;
        builtin debug6 ""(1);
        builtin debug1 "#line:fft.c:88"();
        id = 4 * id;
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:96"();
  is = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:97"();
  id = 4;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:99"();
  while (1) {
    if (! (is < n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:100"();
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
      builtin debug1 "#line:fft.c:101"();
      i1 = i0 + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:102"();
      r1 = *(px + i0);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:103"();
      *(px + i0) = r1 + *(px + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:104"();
      *(px + i1) = r1 - *(px + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:105"();
      r1 = *(py + i0);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:106"();
      *(py + i0) = r1 + *(py + i1);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:107"();
      *(py + i1) = r1 - *(py + i1);
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:109"();
    is = 2 * id - 1;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:110"();
    id = 4 * id;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:116"();
  j = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:117"();
  n1 = n - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:119"();
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
    builtin debug1 "#line:fft.c:120"();
    if (i < j) {
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:121"();
      xt = *(px + j);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:122"();
      *(px + j) = *(px + i);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:123"();
      *(px + i) = xt;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:124"();
      xt = *(py + j);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:125"();
      *(py + j) = *(py + i);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:126"();
      *(py + i) = xt;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:129"();
    k = n / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:130"();
    while (1) {
      if (! (k < j)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:131"();
      j = j - k;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:132"();
      k = k / 2;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:134"();
    j = j + k;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:141"();
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
  double enp;
  double t;
  double y;
  double z;
  double zr;
  double zi;
  double zm;
  double a;
  double *xr;
  double *xi;
  double *pxr;
  double *pxi;
  register /*signed*/ char *$307;
  register double $306;
  register double $305;
  register double $304;
  register double $303;
  register void *$302;
  register void *$301;
  register int $300;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:150"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:151"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:152"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:154"();
  if (argc >= 2) {
    builtin debug6 ""(1);
    $300 = atoi(*(argv + 1));
    n = $300;
  } else {
    builtin debug6 ""(1);
    n = 18;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:155"();
  np = 1 << n;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:156"();
  enp = np;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:157"();
  npm = np / 2 - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:158"();
  t = 3.14159265358979312 / enp;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:159"();
  $301 = calloc(np, sizeof(double));
  xr = $301;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:160"();
  $302 = calloc(np, sizeof(double));
  xi = $302;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:161"();
  pxr = xr;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:162"();
  pxi = xi;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:163"();
  builtin debug6 ""(1);
  nruns = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       nruns = nruns + 1) {
    if (! (nruns < 20)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:164"();
    *pxr = (enp - 1) * 0.5;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:165"();
    *pxi = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:166"();
    n2 = np / 2;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:167"();
    *(pxr + n2) = -0.5;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:168"();
    *(pxi + n2) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:169"();
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
      builtin debug1 "#line:fft.c:170"();
      j = np - i;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:171"();
      *(pxr + i) = -0.5;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:172"();
      *(pxr + j) = -0.5;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:173"();
      z = t * (double) i;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:174"();
      $303 = cos(z);
      $304 = sin(z);
      y = -0.5 * ($303 / $304);
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:175"();
      *(pxi + i) = y;
      builtin debug6 ""(1);
      builtin debug1 "#line:fft.c:176"();
      *(pxi + j) = -y;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:178"();
    dfft(xr, xi, np);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:180"();
  zr = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:181"();
  zi = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:182"();
  npm = np - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:183"();
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
    builtin debug1 "#line:fft.c:184"();
    $305 = fabs(*(pxr + i) - i);
    a = $305;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:185"();
    if (zr < a) {
      builtin debug6 ""(1);
      zr = a;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:186"();
    $306 = fabs(*(pxi + i));
    a = $306;
    builtin debug6 ""(1);
    builtin debug1 "#line:fft.c:187"();
    if (zi < a) {
      builtin debug6 ""(1);
      zi = a;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:189"();
  zm = zr;
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:190"();
  if (zr < zi) {
    builtin debug6 ""(1);
    zm = zi;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:191"();
  if (zm < 1.00000000000000006e-09) {
    $307 = (/*signed*/ char *) __stringlit_edfbf49d0af608112e2c0c9e43cd14682;
  } else {
    $307 = (/*signed*/ char *) __stringlit_edfbf49d0af608112e2c0c9e43cd14681;
  }
  printf(__stringlit_edfbf49d0af608112e2c0c9e43cd14683, np, $307);
  builtin debug6 ""(1);
  builtin debug1 "#line:fft.c:192"();
  return 0;
  builtin debug6 ""();
  return 0;
}


