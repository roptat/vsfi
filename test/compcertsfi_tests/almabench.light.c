double anpm(double);

void planetpv(double *, int, double (*)[3]);

void radecdist(double (*)[3], double *);

void test_1589(void);

void bench_1596(int);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_5a9458300102cdc942cb55e6e94987d51[44] = "p = %d  position[0] = %g  position[1] = %g\012";

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

extern double asin(double);

extern double atan2(double, double);

extern double cos(double);

extern double sin(double);

extern double sqrt(double);

extern double fabs(double);

extern double fmod(double, double);

 double const amas[8] = { 6023600., 408523.5, 328900.5, 3098710., 1047.355,
  3498.5, 22869., 19314., };

 double const a[8][3] = { 0.3870983098, 0., 0., 0.72332982, 0., 0.,
  1.0000010178, 0., 0., 1.5236793419, 3e-10, 0., 5.2026032092, 1.9132e-06,
  -3.9e-09, 9.5549091915, -2.13896e-05, 4.44e-08, 19.2184460618, -3.716e-07,
  9.79e-08, 30.1103868694, -1.6635e-06, 6.86e-08, };

 double const dlm[8][3] = { 252.25090552, 5381016286.89, -1.92789,
  181.97980085, 2106641364.34, 0.59381, 100.46645683, 1295977422.83,
  -2.04411, 355.43299958, 689050774.94, 0.94264, 34.35151874, 109256603.78,
  -30.60378, 50.0774443, 43996098.5573, 75.61614, 314.05500511,
  15424811.9393, -1.75083, 304.34866548, 7865503.20744, 0.21103, };

 double const e[8][3] = { 0.2056317526, 0.0002040653, -2.8349e-06,
  0.0067719164, -0.0004776521, 9.8127e-06, 0.0167086342, -0.0004203654,
  -1.26734e-05, 0.0934006477, 0.0009048438, -8.0641e-06, 0.0484979255,
  0.0016322542, -4.71366e-05, 0.0555481426, -0.0034664062, -6.43639e-05,
  0.0463812221, -0.0002729293, 7.8913e-06, 0.009455747, 6.03263e-05, 0., };

 double const pi[8][3] = { 77.45611904, 5719.1159, -4.83016, 131.563703,
  175.4864, -498.48184, 102.93734808, 11612.3529, 53.27577, 336.06023395,
  15980.45908, -62.328, 14.33120687, 7758.75163, 259.95938, 93.05723748,
  20395.49439, 190.25952, 173.00529106, 3215.56238, -34.09288, 48.12027554,
  1050.71912, 27.39717, };

 double const dinc[8][3] = { 7.00498625, -214.25629, 0.28977, 3.39466189,
  -30.84437, -11.67836, 0., 469.97289, -3.35053, 1.84972648, -293.31722,
  -8.1183, 1.30326698, -71.5589, 11.95297, 2.48887878, 91.85195, -17.66225,
  0.77319689, -60.72723, 1.25759, 1.76995259, 8.12333, 0.08135, };

 double const omega[8][3] = { 48.33089304, -4515.21727, -31.79892,
  76.67992019, -10008.48154, -51.32614, 174.87317577, -8679.27034, 15.34191,
  49.55809321, -10620.90088, -230.57416, 100.46440702, 6362.03561, 326.52178,
  113.66550252, -9240.19942, -66.23743, 74.00595701, 2669.15033, 145.93964,
  131.78405702, -221.94322, -0.78728, };

 double const kp[8][9] = { 69613., 75645., 88306., 59899., 15746., 71087.,
  142173., 3086., 0., 21863., 32794., 26934., 10931., 26250., 43725., 53867.,
  28939., 0., 16002., 21863., 32004., 10931., 14529., 16368., 15318., 32794.,
  0., 6345., 7818., 15636., 7077., 8184., 14163., 1107., 4872., 0., 1760.,
  1454., 1167., 880., 287., 2640., 19., 2047., 1454., 574., 0., 880., 287.,
  19., 1760., 1167., 306., 574., 204., 0., 177., 1265., 4., 385., 200., 208.,
  204., 0., 102., 106., 4., 98., 1367., 487., 204., 0., };

 double const ca[8][9] = { 4., -13., 11., -9., -9., -3., -1., 4., 0., -156.,
  59., -42., 6., 19., -20., -10., -12., 0., 64., -152., 62., -8., 32., -41.,
  19., -11., 0., 124., 621., -145., 208., 54., -57., 30., 15., 0., -23437.,
  -2634., 6601., 6259., -1507., -1821., 2620., -2115., -1489., 62911.,
  -119919., 79336., 17814., -24241., 12068., 8306., -4893., 8902., 389061.,
  -262125., -44088., 8387., -22976., -2093., -615., -9720., 6633., -412235.,
  -157046., -31430., 37817., -9740., -13., -7449., 9644., 0., };

 double const sa[8][9] = { -29., -1., 9., 6., -6., 5., 4., 0., 0., -48.,
  -125., -26., -37., 18., -13., -20., -2., 0., -150., -46., 68., 54., 14.,
  24., -28., 22., 0., -621., 532., -694., -20., 192., -94., 71., -73., 0.,
  -14614., -19828., -5869., 1881., -4372., -2255., 782., 930., 913., 139737.,
  0., 24667., 51123., -5102., 7429., -4095., -1976., -9566., -138081., 0.,
  37205., -49039., -41901., -33872., -27037., -12474., 18797., 0., 28492.,
  133236., 69654., 52322., -49577., -26430., -3593., 0., };

 double const kq[8][10] = { 3086., 15746., 69613., 59899., 75645., 88306.,
  12661., 2658., 0., 0., 21863., 32794., 10931., 73., 4387., 26934., 1473.,
  2157., 0., 0., 10., 16002., 21863., 10931., 1473., 32004., 4387., 73., 0.,
  0., 10., 6345., 7818., 1107., 15636., 7077., 8184., 532., 10., 0., 19.,
  1760., 1454., 287., 1167., 880., 574., 2640., 19., 1454., 19., 574., 287.,
  306., 1760., 12., 31., 38., 19., 574., 4., 204., 177., 8., 31., 200.,
  1265., 102., 4., 204., 4., 102., 106., 8., 98., 1367., 487., 204., 4.,
  102., };

 double const cl[8][10] = { 21., -95., -157., 41., -5., 42., 23., 30., 0.,
  0., -160., -313., -235., 60., -74., -76., -27., 34., 0., 0., -325., -322.,
  -79., 232., -52., 97., 55., -41., 0., 0., 2268., -979., 802., 602., -668.,
  -33., 345., 201., -55., 0., 7610., -4997., -7689., -5841., -2617., 1115.,
  -748., -607., 6074., 354., -18549., 30125., 20012., -730., 824., 23.,
  1289., -352., -14767., -2062., -135245., -14594., 4197., -4030., -5630.,
  -2898., 2540., -306., 2939., 1986., 89948., 2103., 8963., 2695., 3682.,
  1648., 866., -154., -1963., -283., };

 double const sl[8][10] = { -342., 136., -23., 62., 66., -52., -33., 17., 0.,
  0., 524., -149., -35., 117., 151., 122., -71., -62., 0., 0., -105., -137.,
  258., 35., -116., -88., -112., -80., 0., 0., 854., -205., -936., -240.,
  140., -341., -97., -232., 536., 0., -56980., 8016., 1012., 1448., -3024.,
  -3710., 318., 503., 3767., 577., 138606., -13478., -4964., 1441., -1319.,
  -1482., 427., 1236., -9167., -1918., 71234., -41116., 5334., -4935.,
  -1848., 66., 434., -1748., 3780., -701., -47645., 11647., 2166., 3194.,
  679., 0., -244., -419., -2531., 48., };

double anpm(double a__1)
{
  double w;
  register double $299;
  register double $298;
  register double $297;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:175"();
  $297 = fmod(a__1, 2 * 3.14159265358979312);
  w = $297;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:177"();
  $299 = fabs(w);
  if ($299 >= 3.14159265358979312) {
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:178"();
    if (a__1 < 0) {
      $298 = (double) -(2 * 3.14159265358979312);
    } else {
      $298 = (double) (2 * 3.14159265358979312);
    }
    w = w - $298;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:180"();
  return w;
}

void planetpv(double *epoch, int np, double (*pv)[3])
{
  int k;
  double t;
  double da;
  double dl;
  double de;
  double dp;
  double di;
  double doh;
  double dmu;
  double arga;
  double argl;
  double am;
  double ae;
  double dae;
  double ae2;
  double at;
  double r;
  double v;
  double si2;
  double xq;
  double xp;
  double tl;
  double xsw;
  double xcw;
  double xm2;
  double xf;
  double ci2;
  double xms;
  double xmc;
  double xpxq2;
  double x;
  double y;
  double z;
  register double $327;
  register double $326;
  register double $325;
  register double $324;
  register double $323;
  register double $322;
  register double $321;
  register double $320;
  register double $319;
  register double $318;
  register double $317;
  register double $316;
  register double $315;
  register double $314;
  register double $313;
  register double $312;
  register int $311;
  register double $310;
  register double $309;
  register double $308;
  register double $307;
  register double $306;
  register double $305;
  register double $304;
  register double $303;
  register double $302;
  register double $301;
  register double $300;
  register double $299;
  register double $298;
  register double $297;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:189"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:190"();
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
  builtin debug1 "#line:almabench.c:191"();
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
  builtin debug1 "#line:almabench.c:192"();
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
  builtin debug1 "#line:almabench.c:195"();
  t = (*(epoch + 0) - 2451545 + *(epoch + 1)) / 365250;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:198"();
  da = *(*(a + np) + 0) + (*(*(a + np) + 1) + *(*(a + np) + 2) * t) * t;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:199"();
  dl =
    (3600 * *(*(dlm + np) + 0)
      + (*(*(dlm + np) + 1) + *(*(dlm + np) + 2) * t) * t)
      * (3.14159265358979312 / 648000);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:200"();
  de = *(*(e + np) + 0) + (*(*(e + np) + 1) + *(*(e + np) + 2) * t) * t;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:201"();
  $297 =
    anpm
    ((3600 * *(*(pi + np) + 0)
       + (*(*(pi + np) + 1) + *(*(pi + np) + 2) * t) * t)
       * (3.14159265358979312 / 648000));
  dp = $297;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:202"();
  di =
    (3600 * *(*(dinc + np) + 0)
      + (*(*(dinc + np) + 1) + *(*(dinc + np) + 2) * t) * t)
      * (3.14159265358979312 / 648000);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:203"();
  $298 =
    anpm
    ((3600 * *(*(omega + np) + 0)
       + (*(*(omega + np) + 1) + *(*(omega + np) + 2) * t) * t)
       * (3.14159265358979312 / 648000));
  doh = $298;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:206"();
  dmu = 0.359536199999999972 * t;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:208"();
  builtin debug6 ""(1);
  k = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k < 8)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:210"();
    arga = *(*(kp + np) + k) * dmu;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:211"();
    argl = *(*(kq + np) + k) * dmu;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:212"();
    $299 = cos(arga);
    $300 = sin(arga);
    da =
      da
        + (*(*(ca + np) + k) * $299 + *(*(sa + np) + k) * $300)
            * 9.99999999999999955e-08;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:213"();
    $301 = cos(argl);
    $302 = sin(argl);
    dl =
      dl
        + (*(*(cl + np) + k) * $301 + *(*(sl + np) + k) * $302)
            * 9.99999999999999955e-08;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:216"();
  arga = *(*(kp + np) + 8) * dmu;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:217"();
  $303 = cos(arga);
  $304 = sin(arga);
  da =
    da
      + t * (*(*(ca + np) + 8) * $303 + *(*(sa + np) + 8) * $304)
          * 9.99999999999999955e-08;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:219"();
  builtin debug6 ""(1);
  k = 8;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k <= 9)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:221"();
    argl = *(*(kq + np) + k) * dmu;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:222"();
    $305 = cos(argl);
    $306 = sin(argl);
    dl =
      dl
        + t * (*(*(cl + np) + k) * $305 + *(*(sl + np) + k) * $306)
            * 9.99999999999999955e-08;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:225"();
  $307 = fmod(dl, 2 * 3.14159265358979312);
  dl = $307;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:228"();
  am = dl - dp;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:229"();
  $308 = sin(am);
  ae = am + de * $308;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:230"();
  k = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:232"();
  while (1) {
    (void)0 /*skip*/;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:234"();
    $309 = sin(ae);
    $310 = cos(ae);
    dae = (am - ae + de * $309) / (1 - de * $310);
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:235"();
    ae = ae + dae;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:236"();
    k = k + 1;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:238"();
    if (k >= 10) {
      $311 = 1;
    } else {
      $312 = fabs(dae);
      $311 = (_Bool) ($312 < 9.9999999999999998e-13);
    }
    if ($311) {
      break;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:243"();
  ae2 = ae / 2;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:244"();
  $313 = sqrt((1 + de) / (1 - de));
  $314 = sin(ae2);
  $315 = cos(ae2);
  $316 = atan2($313 * $314, $315);
  at = 2 * $316;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:247"();
  $317 = cos(ae);
  r = da * (1 - de * $317);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:248"();
  $318 = sqrt((1 + 1 / *(amas + np)) / (da * da * da));
  v = 0.0172020989500000013 * $318;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:250"();
  $319 = sin(di / 2);
  si2 = $319;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:251"();
  $320 = cos(doh);
  xq = si2 * $320;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:252"();
  $321 = sin(doh);
  xp = si2 * $321;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:253"();
  tl = at + dp;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:254"();
  $322 = sin(tl);
  xsw = $322;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:255"();
  $323 = cos(tl);
  xcw = $323;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:256"();
  xm2 = 2 * (xp * xcw - xq * xsw);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:257"();
  $324 = sqrt(1 - de * de);
  xf = da / $324;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:258"();
  $325 = cos(di / 2);
  ci2 = $325;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:259"();
  $326 = sin(dp);
  xms = (de * $326 + xsw) * xf;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:260"();
  $327 = cos(dp);
  xmc = (de * $327 + xcw) * xf;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:261"();
  xpxq2 = 2 * xp * xq;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:264"();
  x = r * (xcw - xm2 * xp);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:265"();
  y = r * (xsw + xm2 * xq);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:266"();
  z = r * (-xm2 * ci2);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:269"();
  *(*(pv + 0) + 0) = x;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:270"();
  *(*(pv + 0) + 1) = y * 0.917482062069181814 - z * 0.397777155931913706;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:271"();
  *(*(pv + 0) + 2) = y * 0.397777155931913706 + z * 0.917482062069181814;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:274"();
  x = v * ((-1 + 2 * xp * xp) * xms + xpxq2 * xmc);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:275"();
  y = v * ((1 - 2 * xq * xq) * xmc - xpxq2 * xms);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:276"();
  z = v * (2 * ci2 * (xp * xms + xq * xmc));
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:279"();
  *(*(pv + 1) + 0) = x;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:280"();
  *(*(pv + 1) + 1) = y * 0.917482062069181814 - z * 0.397777155931913706;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:281"();
  *(*(pv + 1) + 2) = y * 0.397777155931913706 + z * 0.917482062069181814;
}

void radecdist(double (*state)[3], double *rdd)
{
  register double $299;
  register double $298;
  register double $297;
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:290"();
  $297 =
    sqrt
    (*(*(state + 0) + 0) * *(*(state + 0) + 0)
       + *(*(state + 0) + 1) * *(*(state + 0) + 1)
       + *(*(state + 0) + 2) * *(*(state + 0) + 2));
  *(rdd + 2) = $297;
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:293"();
  $298 = atan2(*(*(state + 0) + 1), *(*(state + 0) + 0));
  *(rdd + 0) = $298 * (12 / 3.14159265358979312);
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:294"();
  if (*(rdd + 0) < 0) {
    builtin debug6 ""();
    *(rdd + 0) = *(rdd + 0) + 24;
  }
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:297"();
  $299 = asin(*(*(state + 0) + 2) / *(rdd + 2));
  *(rdd + 1) = $299 * (180 / 3.14159265358979312);
}

void test_1589(void)
{
  int p;
  double jd[2];
  double pv[2][3];
  double position[3];
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:304"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:305"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:306"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:307"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:309"();
  *(jd + 0) = 2451545;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:310"();
  *(jd + 1) = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:311"();
  builtin debug6 ""(1);
  p = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       p = p + 1) {
    if (! (p < 8)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:313"();
    planetpv(jd, p, pv);
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:314"();
    radecdist(pv, position);
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:315"();
    printf
      (__stringlit_5a9458300102cdc942cb55e6e94987d51, p, *(position + 0),
       *(position + 1));
  }
}

void bench_1596(int nloops)
{
  int i;
  int n;
  int p;
  double jd[2];
  double pv[2][3];
  double position[3];
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:323"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:324"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:325"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:326"();
  builtin debug6 ""(1);
  builtin debug1 "#line:almabench.c:328"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < nloops)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:330"();
    *(jd + 0) = 2451545;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:331"();
    *(jd + 1) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:almabench.c:333"();
    builtin debug6 ""(1);
    n = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         n = n + 1) {
      if (! (n < 36525)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:almabench.c:335"();
      *(jd + 0) = *(jd + 0) + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:almabench.c:337"();
      builtin debug6 ""(1);
      p = 0;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           p = p + 1) {
        if (! (p < 8)) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:almabench.c:339"();
        planetpv(jd, p, pv);
        builtin debug6 ""(1);
        builtin debug1 "#line:almabench.c:340"();
        radecdist(pv, position);
      }
    }
  }
}

int main(int argc, /*signed*/ char **argv)
{
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:348"();
  test_1589();
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:349"();
  bench_1596(1);
  builtin debug6 ""();
  builtin debug1 "#line:almabench.c:350"();
  return 0;
  builtin debug6 ""();
  return 0;
}


