extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern int printf(char const * __format, ...);

extern double asin(double __x);

extern double atan2(double __y, double __x);

extern double cos(double __x);

extern double sin(double __x);

extern double sqrt(double __x);

extern double fabs(double __x);

extern double fmod(double __x, double __y);

double const amas[8] =
  {6023600.0E0, 408523.5E0, 328900.5E0, 3098710.0E0, 1047.355E0, 3498.5E0,
   22869.0E0, 19314.0E0, };

double const a[8][3] =
  {{0.3870983098E0, 0, 0, }, {0.7233298200E0, 0, 0, },
   {1.0000010178E0, 0, 0, }, {1.5236793419E0, 3.0E-10, 0, },
   {5.2026032092E0, 19132.0E-10, -39.0E-10, },
   {9.5549091915E0, -0.0000213896E0, 444.0E-10, },
   {19.2184460618E0, -3716.0E-10, 979.0E-10, },
   {30.1103868694E0, -16635.0E-10, 686.0E-10, }, };

double const dlm[8][3] =
  {{252.25090552E0, 5381016286.88982E0, -1.92789E0, },
   {181.97980085E0, 2106641364.33548E0, 0.59381E0, },
   {100.46645683E0, 1295977422.83429E0, -2.04411E0, },
   {355.43299958E0, 689050774.93988E0, 0.94264E0, },
   {34.35151874E0, 109256603.77991E0, -30.60378E0, },
   {50.07744430E0, 43996098.55732E0, 75.61614E0, },
   {314.05500511E0, 15424811.93933E0, -1.75083E0, },
   {304.34866548E0, 7865503.20744E0, 0.21103E0, }, };

double const e[8][3] =
  {{0.2056317526E0, 0.0002040653E0, -28349.0E-10, },
   {0.0067719164E0, -0.0004776521E0, 98127.0E-10, },
   {0.0167086342E0, -0.0004203654E0, -0.0000126734E0, },
   {0.0934006477E0, 0.0009048438E0, -80641.0E-10, },
   {0.0484979255E0, 0.0016322542E0, -0.0000471366E0, },
   {0.0555481426E0, -0.0034664062E0, -0.0000643639E0, },
   {0.0463812221E0, -0.0002729293E0, 0.0000078913E0, },
   {0.0094557470E0, 0.0000603263E0, 0, }, };

double const pi[8][3] =
  {{77.45611904E0, 5719.11590E0, -4.83016E0, },
   {131.56370300E0, 175.48640E0, -498.48184E0, },
   {102.93734808E0, 11612.35290E0, 53.27577E0, },
   {336.06023395E0, 15980.45908E0, -62.32800E0, },
   {14.33120687E0, 7758.75163E0, 259.95938E0, },
   {93.05723748E0, 20395.49439E0, 190.25952E0, },
   {173.00529106E0, 3215.56238E0, -34.09288E0, },
   {48.12027554E0, 1050.71912E0, 27.39717E0, }, };

double const dinc[8][3] =
  {{7.00498625E0, -214.25629E0, 0.28977E0, },
   {3.39466189E0, -30.84437E0, -11.67836E0, },
   {0, 469.97289E0, -3.35053E0, },
   {1.84972648E0, -293.31722E0, -8.11830E0, },
   {1.30326698E0, -71.55890E0, 11.95297E0, },
   {2.48887878E0, 91.85195E0, -17.66225E0, },
   {0.77319689E0, -60.72723E0, 1.25759E0, },
   {1.76995259E0, 8.12333E0, 0.08135E0, }, };

double const omega[8][3] =
  {{48.33089304E0, -4515.21727E0, -31.79892E0, },
   {76.67992019E0, -10008.48154E0, -51.32614E0, },
   {174.87317577E0, -8679.27034E0, 15.34191E0, },
   {49.55809321E0, -10620.90088E0, -230.57416E0, },
   {100.46440702E0, 6362.03561E0, 326.52178E0, },
   {113.66550252E0, -9240.19942E0, -66.23743E0, },
   {74.00595701E0, 2669.15033E0, 145.93964E0, },
   {131.78405702E0, -221.94322E0, -0.78728E0, }, };

double const kp[8][9] =
  {{69613.0E0, 75645.0E0, 88306.0E0, 59899.0E0, 15746.0E0, 71087.0E0,
    142173.0E0, 3086.0E0, 0.0E0, },
   {21863.0E0, 32794.0E0, 26934.0E0, 10931.0E0, 26250.0E0, 43725.0E0,
    53867.0E0, 28939.0E0, 0.0E0, },
   {16002.0E0, 21863.0E0, 32004.0E0, 10931.0E0, 14529.0E0, 16368.0E0,
    15318.0E0, 32794.0E0, 0.0E0, },
   {6345.0E0, 7818.0E0, 15636.0E0, 7077.0E0, 8184.0E0, 14163.0E0, 1107.0E0,
    4872.0E0, 0.0E0, },
   {1760.0E0, 1454.0E0, 1167.0E0, 880.0E0, 287.0E0, 2640.0E0, 19.0E0,
    2047.0E0, 1454.0E0, },
   {574.0E0, 0.0E0, 880.0E0, 287.0E0, 19.0E0, 1760.0E0, 1167.0E0, 306.0E0,
    574.0E0, },
   {204.0E0, 0.0E0, 177.0E0, 1265.0E0, 4.0E0, 385.0E0, 200.0E0, 208.0E0,
    204.0E0, },
   {0.0E0, 102.0E0, 106.0E0, 4.0E0, 98.0E0, 1367.0E0, 487.0E0, 204.0E0,
    0.0E0, }, };

double const ca[8][9] =
  {{4.0E0, -13.0E0, 11.0E0, -9.0E0, -9.0E0, -3.0E0, -1.0E0, 4.0E0, 0.0E0, },
   {-156.0E0, 59.0E0, -42.0E0, 6.0E0, 19.0E0, -20.0E0, -10.0E0, -12.0E0,
    0.0E0, },
   {64.0E0, -152.0E0, 62.0E0, -8.0E0, 32.0E0, -41.0E0, 19.0E0, -11.0E0,
    0.0E0, },
   {124.0E0, 621.0E0, -145.0E0, 208.0E0, 54.0E0, -57.0E0, 30.0E0, 15.0E0,
    0.0E0, },
   {-23437.0E0, -2634.0E0, 6601.0E0, 6259.0E0, -1507.0E0, -1821.0E0,
    2620.0E0, -2115.0E0, -1489.0E0, },
   {62911.0E0, -119919.0E0, 79336.0E0, 17814.0E0, -24241.0E0, 12068.0E0,
    8306.0E0, -4893.0E0, 8902.0E0, },
   {389061.0E0, -262125.0E0, -44088.0E0, 8387.0E0, -22976.0E0, -2093.0E0,
    -615.0E0, -9720.0E0, 6633.0E0, },
   {-412235.0E0, -157046.0E0, -31430.0E0, 37817.0E0, -9740.0E0, -13.0E0,
    -7449.0E0, 9644.0E0, 0.0E0, }, };

double const sa[8][9] =
  {{-29.0E0, -1.0E0, 9.0E0, 6.0E0, -6.0E0, 5.0E0, 4.0E0, 0.0E0, 0.0E0, },
   {-48.0E0, -125.0E0, -26.0E0, -37.0E0, 18.0E0, -13.0E0, -20.0E0, -2.0E0,
    0.0E0, },
   {-150.0E0, -46.0E0, 68.0E0, 54.0E0, 14.0E0, 24.0E0, -28.0E0, 22.0E0,
    0.0E0, },
   {-621.0E0, 532.0E0, -694.0E0, -20.0E0, 192.0E0, -94.0E0, 71.0E0, -73.0E0,
    0.0E0, },
   {-14614.0E0, -19828.0E0, -5869.0E0, 1881.0E0, -4372.0E0, -2255.0E0,
    782.0E0, 930.0E0, 913.0E0, },
   {139737.0E0, 0.0E0, 24667.0E0, 51123.0E0, -5102.0E0, 7429.0E0, -4095.0E0,
    -1976.0E0, -9566.0E0, },
   {-138081.0E0, 0.0E0, 37205.0E0, -49039.0E0, -41901.0E0, -33872.0E0,
    -27037.0E0, -12474.0E0, 18797.0E0, },
   {0.0E0, 28492.0E0, 133236.0E0, 69654.0E0, 52322.0E0, -49577.0E0,
    -26430.0E0, -3593.0E0, 0.0E0, }, };

double const kq[8][10] =
  {{3086.0E0, 15746.0E0, 69613.0E0, 59899.0E0, 75645.0E0, 88306.0E0,
    12661.0E0, 2658.0E0, 0.0E0, 0.0E0, },
   {21863.0E0, 32794.0E0, 10931.0E0, 73.0E0, 4387.0E0, 26934.0E0, 1473.0E0,
    2157.0E0, 0.0E0, 0.0E0, },
   {10.0E0, 16002.0E0, 21863.0E0, 10931.0E0, 1473.0E0, 32004.0E0, 4387.0E0,
    73.0E0, 0.0E0, 0.0E0, },
   {10.0E0, 6345.0E0, 7818.0E0, 1107.0E0, 15636.0E0, 7077.0E0, 8184.0E0,
    532.0E0, 10.0E0, 0.0E0, },
   {19.0E0, 1760.0E0, 1454.0E0, 287.0E0, 1167.0E0, 880.0E0, 574.0E0,
    2640.0E0, 19.0E0, 1454.0E0, },
   {19.0E0, 574.0E0, 287.0E0, 306.0E0, 1760.0E0, 12.0E0, 31.0E0, 38.0E0,
    19.0E0, 574.0E0, },
   {4.0E0, 204.0E0, 177.0E0, 8.0E0, 31.0E0, 200.0E0, 1265.0E0, 102.0E0,
    4.0E0, 204.0E0, },
   {4.0E0, 102.0E0, 106.0E0, 8.0E0, 98.0E0, 1367.0E0, 487.0E0, 204.0E0,
    4.0E0, 102.0E0, }, };

double const cl[8][10] =
  {{21.0E0, -95.0E0, -157.0E0, 41.0E0, -5.0E0, 42.0E0, 23.0E0, 30.0E0, 
    0.0E0, 0.0E0, },
   {-160.0E0, -313.0E0, -235.0E0, 60.0E0, -74.0E0, -76.0E0, -27.0E0, 
    34.0E0, 0.0E0, 0.0E0, },
   {-325.0E0, -322.0E0, -79.0E0, 232.0E0, -52.0E0, 97.0E0, 55.0E0, -41.0E0,
    0.0E0, 0.0E0, },
   {2268.0E0, -979.0E0, 802.0E0, 602.0E0, -668.0E0, -33.0E0, 345.0E0,
    201.0E0, -55.0E0, 0.0E0, },
   {7610.0E0, -4997.0E0, -7689.0E0, -5841.0E0, -2617.0E0, 1115.0E0, -748.0E0,
    -607.0E0, 6074.0E0, 354.0E0, },
   {-18549.0E0, 30125.0E0, 20012.0E0, -730.0E0, 824.0E0, 23.0E0, 1289.0E0,
    -352.0E0, -14767.0E0, -2062.0E0, },
   {-135245.0E0, -14594.0E0, 4197.0E0, -4030.0E0, -5630.0E0, -2898.0E0,
    2540.0E0, -306.0E0, 2939.0E0, 1986.0E0, },
   {89948.0E0, 2103.0E0, 8963.0E0, 2695.0E0, 3682.0E0, 1648.0E0, 866.0E0,
    -154.0E0, -1963.0E0, -283.0E0, }, };

double const sl[8][10] =
  {{-342.0E0, 136.0E0, -23.0E0, 62.0E0, 66.0E0, -52.0E0, -33.0E0, 17.0E0,
    0.0E0, 0.0E0, },
   {524.0E0, -149.0E0, -35.0E0, 117.0E0, 151.0E0, 122.0E0, -71.0E0, -62.0E0,
    0.0E0, 0.0E0, },
   {-105.0E0, -137.0E0, 258.0E0, 35.0E0, -116.0E0, -88.0E0, -112.0E0,
    -80.0E0, 0.0E0, 0.0E0, },
   {854.0E0, -205.0E0, -936.0E0, -240.0E0, 140.0E0, -341.0E0, -97.0E0,
    -232.0E0, 536.0E0, 0.0E0, },
   {-56980.0E0, 8016.0E0, 1012.0E0, 1448.0E0, -3024.0E0, -3710.0E0, 318.0E0,
    503.0E0, 3767.0E0, 577.0E0, },
   {138606.0E0, -13478.0E0, -4964.0E0, 1441.0E0, -1319.0E0, -1482.0E0,
    427.0E0, 1236.0E0, -9167.0E0, -1918.0E0, },
   {71234.0E0, -41116.0E0, 5334.0E0, -4935.0E0, -1848.0E0, 66.0E0, 434.0E0,
    -1748.0E0, 3780.0E0, -701.0E0, },
   {-47645.0E0, 11647.0E0, 2166.0E0, 3194.0E0, 679.0E0, 0.0E0, -244.0E0,
    -419.0E0, -2531.0E0, 48.0E0, }, };

double anpm(double a__1)
{
  double w;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:175");
  w = fmod(a__1, 2.0E0 * 3.14159265358979323846E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:177");
  if (fabs(w) >= 3.14159265358979323846E0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:178");
    w =
      w
        - (a__1 < 0 ? -(2.0E0 * 3.14159265358979323846E0)
            : 2.0E0 * 3.14159265358979323846E0);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:180");
  return w;
}

void planetpv(double * epoch, int np, double (* pv)[3])
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
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:189");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:190");
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
  __builtin_debug(1, "#line:almabench.c:191");
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
  __builtin_debug(1, "#line:almabench.c:192");
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
  __builtin_debug(1, "#line:almabench.c:195");
  t = (epoch[0] - 2451545.0E0 + epoch[1]) / 365250.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:198");
  da = a[np][0] + (a[np][1] + a[np][2] * t) * t;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:199");
  dl =
    (3600.0E0 * dlm[np][0] + (dlm[np][1] + dlm[np][2] * t) * t)
      * (3.14159265358979323846E0 / 648000.0E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:200");
  de = e[np][0] + (e[np][1] + e[np][2] * t) * t;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:201");
  dp =
    anpm((3600.0E0 * pi[np][0] + (pi[np][1] + pi[np][2] * t) * t)
           * (3.14159265358979323846E0 / 648000.0E0));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:202");
  di =
    (3600.0E0 * dinc[np][0] + (dinc[np][1] + dinc[np][2] * t) * t)
      * (3.14159265358979323846E0 / 648000.0E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:203");
  doh =
    anpm((3600.0E0 * omega[np][0] + (omega[np][1] + omega[np][2] * t) * t)
           * (3.14159265358979323846E0 / 648000.0E0));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:206");
  dmu = 0.35953620E0 * t;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:208");
  for (__builtin_debug(6, "", 1), k = 0;
       k < 8;
       __builtin_debug(6, "", 1), ++k) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:210");
    arga = kp[np][k] * dmu;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:211");
    argl = kq[np][k] * dmu;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:212");
    da = da + (ca[np][k] * cos(arga) + sa[np][k] * sin(arga)) * 0.0000001E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:213");
    dl = dl + (cl[np][k] * cos(argl) + sl[np][k] * sin(argl)) * 0.0000001E0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:216");
  arga = kp[np][8] * dmu;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:217");
  da = da + t * (ca[np][8] * cos(arga) + sa[np][8] * sin(arga)) * 0.0000001E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:219");
  for (__builtin_debug(6, "", 1), k = 8;
       k <= 9;
       __builtin_debug(6, "", 1), ++k) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:221");
    argl = kq[np][k] * dmu;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:222");
    dl =
      dl + t * (cl[np][k] * cos(argl) + sl[np][k] * sin(argl)) * 0.0000001E0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:225");
  dl = fmod(dl, 2.0E0 * 3.14159265358979323846E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:228");
  am = dl - dp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:229");
  ae = am + de * sin(am);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:230");
  k = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:232");
  while (1) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:234");
    dae = (am - ae + de * sin(ae)) / (1.0E0 - de * cos(ae));
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:235");
    ae = ae + dae;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:236");
    k = k + 1;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:238");
    if (k >= 10 || fabs(dae) < 1.0E-12) {
      break;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:243");
  ae2 = ae / 2.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:244");
  at = 2.0E0 * atan2(sqrt((1.0E0 + de) / (1.0E0 - de)) * sin(ae2), cos(ae2));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:247");
  r = da * (1.0E0 - de * cos(ae));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:248");
  v = 0.01720209895E0 * sqrt((1.0E0 + 1.0E0 / amas[np]) / (da * da * da));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:250");
  si2 = sin(di / 2.0E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:251");
  xq = si2 * cos(doh);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:252");
  xp = si2 * sin(doh);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:253");
  tl = at + dp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:254");
  xsw = sin(tl);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:255");
  xcw = cos(tl);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:256");
  xm2 = 2.0E0 * (xp * xcw - xq * xsw);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:257");
  xf = da / sqrt(1.0E0 - de * de);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:258");
  ci2 = cos(di / 2.0E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:259");
  xms = (de * sin(dp) + xsw) * xf;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:260");
  xmc = (de * cos(dp) + xcw) * xf;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:261");
  xpxq2 = 2.0E0 * xp * xq;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:264");
  x = r * (xcw - xm2 * xp);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:265");
  y = r * (xsw + xm2 * xq);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:266");
  z = r * (-xm2 * ci2);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:269");
  pv[0][0] = x;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:270");
  pv[0][1] = y * 0.9174820620691818E0 - z * 0.3977771559319137E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:271");
  pv[0][2] = y * 0.3977771559319137E0 + z * 0.9174820620691818E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:274");
  x = v * ((-1.0E0 + 2.0E0 * xp * xp) * xms + xpxq2 * xmc);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:275");
  y = v * ((1.0E0 - 2.0E0 * xq * xq) * xmc - xpxq2 * xms);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:276");
  z = v * (2.0E0 * ci2 * (xp * xms + xq * xmc));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:279");
  pv[1][0] = x;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:280");
  pv[1][1] = y * 0.9174820620691818E0 - z * 0.3977771559319137E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:281");
  pv[1][2] = y * 0.3977771559319137E0 + z * 0.9174820620691818E0;
}

void radecdist(double (* state)[3], double * rdd)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:290");
  rdd[2] =
    sqrt(state[0][0] * state[0][0] + state[0][1] * state[0][1]
           + state[0][2] * state[0][2]);
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:293");
  rdd[0] =
    atan2(state[0][1], state[0][0]) * (12.0E0 / 3.14159265358979323846E0);
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:294");
  if (rdd[0] < 0.0E0) {
    __builtin_debug(6, "");
    rdd[0] += 24.0E0;
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:297");
  rdd[1] = asin(state[0][2] / rdd[2]) * (180.0E0 / 3.14159265358979323846E0);
}

static void test_1589(void)
{
  int p;
  double jd[2];
  double pv[2][3];
  double position[3];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:304");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:305");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:306");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:307");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:309");
  jd[0] = 2451545.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:310");
  jd[1] = 0.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:311");
  for (__builtin_debug(6, "", 1), p = 0;
       p < 8;
       __builtin_debug(6, "", 1), ++p) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:313");
    planetpv(jd, p, pv);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:314");
    radecdist(pv, position);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:315");
    printf("p = %d  position[0] = %g  position[1] = %g\n", p, position[0],
           position[1]);
  }
}

static void bench_1596(int nloops)
{
  int i;
  int n;
  int p;
  double jd[2];
  double pv[2][3];
  double position[3];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:323");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:324");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:325");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:326");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:almabench.c:328");
  for (__builtin_debug(6, "", 1), i = 0;
       i < nloops;
       __builtin_debug(6, "", 1), ++i) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:330");
    jd[0] = 2451545.0E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:331");
    jd[1] = 0.0E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:almabench.c:333");
    for (__builtin_debug(6, "", 1), n = 0;
         n < 36525;
         __builtin_debug(6, "", 1), ++n) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:almabench.c:335");
      jd[0] += 1.0E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:almabench.c:337");
      for (__builtin_debug(6, "", 1), p = 0;
           p < 8;
           __builtin_debug(6, "", 1), ++p) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:almabench.c:339");
        planetpv(jd, p, pv);
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:almabench.c:340");
        radecdist(pv, position);
      }
    }
  }
}

int main(int argc, char * * argv)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:348");
  test_1589();
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:349");
  bench_1596(1);
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:almabench.c:350");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


