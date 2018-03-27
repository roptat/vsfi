extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern double cos(double __x);

extern double sin(double __x);

extern double fabs(double __x);

typedef unsigned int size_t;

extern int atoi(char const * __nptr);

extern void * calloc(size_t __nmemb, size_t __size);

extern int printf(char const * __format, ...);

int dfft(double * x, double * y, int np)
{
  double * px;
  double * py;
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
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:23");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:24");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:25");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:27");
  px = x - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:28");
  py = y - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:29");
  i = 2;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:30");
  m = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:32");
  while (i < np) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:34");
    i = i + i;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:35");
    m = m + 1;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:38");
  n = i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:40");
  if (n != np) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:41");
    for (__builtin_debug(6, "", 1), i = np + 1;
         i <= n;
         __builtin_debug(6, "", 1), i++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:42");
      px[i] = 0.0E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:43");
      py[i] = 0.0E0;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:48");
  n2 = n + n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:49");
  tpi = 2.0E0 * 3.14159265358979323846E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:50");
  for (__builtin_debug(6, "", 1), k = 1;
       k <= m - 1;
       __builtin_debug(6, "", 1), k++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:51");
    n2 = n2 / 2;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:52");
    n4 = n2 / 4;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:53");
    e = tpi / (double) n2;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:54");
    a = 0.0E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:56");
    for (__builtin_debug(6, "", 1), j = 1;
         j <= n4;
         __builtin_debug(6, "", 1), j++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:57");
      a3 = 3.0E0 * a;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:58");
      cc1 = cos(a);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:59");
      ss1 = sin(a);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:61");
      cc3 = cos(a3);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:62");
      ss3 = sin(a3);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:63");
      a = e * (double) j;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:64");
      is = j;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:65");
      id = 2 * n2;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:67");
      while (is < n) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fft.c:68");
        for (__builtin_debug(6, "", 1), i0 = is;
             i0 <= n - 1;
             __builtin_debug(6, "", 1), i0 = i0 + id) {
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:69");
          i1 = i0 + n4;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:70");
          i2 = i1 + n4;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:71");
          i3 = i2 + n4;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:72");
          r1 = px[i0] - px[i2];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:73");
          px[i0] = px[i0] + px[i2];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:74");
          r2 = px[i1] - px[i3];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:75");
          px[i1] = px[i1] + px[i3];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:76");
          s1 = py[i0] - py[i2];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:77");
          py[i0] = py[i0] + py[i2];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:78");
          s2 = py[i1] - py[i3];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:79");
          py[i1] = py[i1] + py[i3];
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:80");
          s3 = r1 - s2;
          __builtin_debug(6, "", 1);
          r1 = r1 + s2;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:81");
          s2 = r2 - s1;
          __builtin_debug(6, "", 1);
          r2 = r2 + s1;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:82");
          px[i2] = r1 * cc1 - s2 * ss1;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:83");
          py[i2] = -s2 * cc1 - r1 * ss1;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:84");
          px[i3] = s3 * cc3 + r2 * ss3;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:fft.c:85");
          py[i3] = r2 * cc3 - s3 * ss3;
        }
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fft.c:87");
        is = 2 * id - n2 + j;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:fft.c:88");
        id = 4 * id;
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:96");
  is = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:97");
  id = 4;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:99");
  while (is < n) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:100");
    for (__builtin_debug(6, "", 1), i0 = is;
         i0 <= n;
         __builtin_debug(6, "", 1), i0 = i0 + id) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:101");
      i1 = i0 + 1;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:102");
      r1 = px[i0];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:103");
      px[i0] = r1 + px[i1];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:104");
      px[i1] = r1 - px[i1];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:105");
      r1 = py[i0];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:106");
      py[i0] = r1 + py[i1];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:107");
      py[i1] = r1 - py[i1];
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:109");
    is = 2 * id - 1;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:110");
    id = 4 * id;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:116");
  j = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:117");
  n1 = n - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:119");
  for (__builtin_debug(6, "", 1), i = 1;
       i <= n1;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:120");
    if (i < j) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:121");
      xt = px[j];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:122");
      px[j] = px[i];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:123");
      px[i] = xt;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:124");
      xt = py[j];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:125");
      py[j] = py[i];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:126");
      py[i] = xt;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:129");
    k = n / 2;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:130");
    while (k < j) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:131");
      j = j - k;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:132");
      k = k / 2;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:134");
    j = j + k;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:141");
  return n;
}

int main(int argc, char * * argv)
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
  double * xr;
  double * xi;
  double * pxr;
  double * pxi;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:150");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:151");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:152");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:154");
  if (argc >= 2) {
    __builtin_debug(6, "", 1);
    n = atoi(argv[1]);
  } else {
    __builtin_debug(6, "", 1);
    n = 18;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:155");
  np = 1 << n;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:156");
  enp = np;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:157");
  npm = np / 2 - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:158");
  t = 3.14159265358979323846E0 / enp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:159");
  xr = calloc(np, sizeof(double));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:160");
  xi = calloc(np, sizeof(double));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:161");
  pxr = xr;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:162");
  pxi = xi;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:163");
  for (__builtin_debug(6, "", 1), nruns = 0;
       nruns < 20;
       __builtin_debug(6, "", 1), nruns++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:164");
    *pxr = (enp - 1.0E0) * 0.5E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:165");
    *pxi = 0.0E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:166");
    n2 = np / 2;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:167");
    *(pxr + n2) = -0.5E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:168");
    *(pxi + n2) = 0.0E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:169");
    for (__builtin_debug(6, "", 1), i = 1;
         i <= npm;
         __builtin_debug(6, "", 1), i++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:170");
      j = np - i;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:171");
      *(pxr + i) = -0.5E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:172");
      *(pxr + j) = -0.5E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:173");
      z = t * (double) i;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:174");
      y = -0.5E0 * (cos(z) / sin(z));
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:175");
      *(pxi + i) = y;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:fft.c:176");
      *(pxi + j) = -y;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:178");
    dfft(xr, xi, np);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:180");
  zr = 0.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:181");
  zi = 0.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:182");
  npm = np - 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:183");
  for (__builtin_debug(6, "", 1), i = 0;
       i <= npm;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:184");
    a = fabs(pxr[i] - i);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:185");
    if (zr < a) {
      __builtin_debug(6, "", 1);
      zr = a;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:186");
    a = fabs(pxi[i]);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fft.c:187");
    if (zi < a) {
      __builtin_debug(6, "", 1);
      zi = a;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:189");
  zm = zr;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:190");
  if (zr < zi) {
    __builtin_debug(6, "", 1);
    zm = zi;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:191");
  printf("%d points, %s\n", np, zm < 1.0E-9 ? "result OK" : "WRONG result");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fft.c:192");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


