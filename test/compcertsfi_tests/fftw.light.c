void e01_8(double *, double *, int *, int *, int, int, int);

int main(void);

static /*signed*/ char const __stringlit_6157a67d3fc59efa50dbcd1f9bf8a50f1[14] = "o[%d] = %.6e\012";

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

void e01_8(double *I, double *O, int *is, int *os, int v, int ivs, int ovs)
{
  double KP1_662939224;
  double KP1_111140466;
  double KP390180644;
  double KP1_961570560;
  double KP707106781;
  double KP1_414213562;
  double KP765366864;
  double KP1_847759065;
  int i;
  double T7;
  double Tl;
  double T4;
  double Tk;
  double Td;
  double To;
  double Tg;
  double Tn;
  double T5;
  double T6;
  double T1;
  double T3;
  double T2;
  double T9;
  double Tf;
  double Tc;
  double Te;
  double Ta;
  double Tb;
  double T8;
  double Th;
  double Tq;
  double Tr;
  double Ti;
  double Tj;
  double Tm;
  double Tp;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:14"();
  KP1_662939224 = (double) 1.66293922460509047;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:15"();
  KP1_111140466 = (double) 1.11114046603920436;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:16"();
  KP390180644 = (double) 0.390180644032256552;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:17"();
  KP1_961570560 = (double) 1.96157056080646086;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:18"();
  KP707106781 = (double) 0.707106781186547573;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:19"();
  KP1_414213562 = (double) 1.41421356237309515;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:20"();
  KP765366864 = (double) 0.765366864730179564;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:21"();
  KP1_847759065 = (double) 1.84775906502257348;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:22"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:23"();
  builtin debug6 ""(1);
  i = v;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i - 1, I = I + ivs, O = O + ovs) {
    if (! (i > 0)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:fftw.c:24"();
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2);
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:26"();
    builtin debug6 ""(1, 2, 5);
    builtin debug6 ""(1, 2, 5);
    builtin debug6 ""(1, 2, 5);
    builtin debug6 ""(1, 2, 5);
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:27"();
    T5 = *(I + *(is + 2));
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:28"();
    T6 = *(I + *(is + 6));
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:29"();
    T7 = KP1_847759065 * T5 + KP765366864 * T6;
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:30"();
    Tl = KP765366864 * T5 - KP1_847759065 * T6;
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:31"();
    T1 = *(I + 0);
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:32"();
    T2 = *(I + *(is + 4));
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:33"();
    T3 = KP1_414213562 * T2;
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:34"();
    T4 = T1 + T3;
    builtin debug6 ""(1, 2, 5);
    builtin debug1 "#line:fftw.c:35"();
    Tk = T1 - T3;
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:37"();
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:38"();
    T9 = *(I + *(is + 1));
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:39"();
    Tf = *(I + *(is + 7));
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:40"();
    Ta = *(I + *(is + 5));
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:41"();
    Tb = *(I + *(is + 3));
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:42"();
    Tc = KP707106781 * (Ta + Tb);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:43"();
    Te = KP707106781 * (Ta - Tb);
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:44"();
    Td = T9 + Tc;
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:45"();
    To = Te + Tf;
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:46"();
    Tg = Te - Tf;
    builtin debug6 ""(1, 2, 5, 6);
    builtin debug1 "#line:fftw.c:47"();
    Tn = T9 - Tc;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:51"();
    builtin debug6 ""(1, 2, 4);
    builtin debug6 ""(1, 2, 4);
    builtin debug6 ""(1, 2, 4);
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:52"();
    T8 = T4 + T7;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:53"();
    Th = KP1_961570560 * Td - KP390180644 * Tg;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:54"();
    *(O + *(os + 7)) = T8 - Th;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:55"();
    *(O + 0) = T8 + Th;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:56"();
    Tq = Tk - Tl;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:57"();
    Tr = KP1_111140466 * Tn + KP1_662939224 * To;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:58"();
    *(O + *(os + 5)) = Tq - Tr;
    builtin debug6 ""(1, 2, 4);
    builtin debug1 "#line:fftw.c:59"();
    *(O + *(os + 2)) = Tq + Tr;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:62"();
    builtin debug6 ""(1, 2, 3);
    builtin debug6 ""(1, 2, 3);
    builtin debug6 ""(1, 2, 3);
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:63"();
    Ti = T4 - T7;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:64"();
    Tj = KP390180644 * Td + KP1_961570560 * Tg;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:65"();
    *(O + *(os + 4)) = Ti - Tj;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:66"();
    *(O + *(os + 3)) = Ti + Tj;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:67"();
    Tm = Tk + Tl;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:68"();
    Tp = KP1_662939224 * Tn - KP1_111140466 * To;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:69"();
    *(O + *(os + 6)) = Tm - Tp;
    builtin debug6 ""(1, 2, 3);
    builtin debug1 "#line:fftw.c:70"();
    *(O + *(os + 1)) = Tm + Tp;
  }
}

static int s_520[8] = { 0, 1, 2, 3, 4, 5, 6, 7, };

double i_521[1024];

double o_522[1024];

int main(void)
{
  int k;
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:84"();
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:85"();
  builtin debug6 ""(1);
  k = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k < 1024)) {
      break;
    }
    builtin debug6 ""(1);
    *(i_521 + k) = k;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:86"();
  builtin debug6 ""(1);
  k = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k < 1024 * 1024)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftw.c:87"();
    e01_8(i_521, o_522, s_520, s_520, 64, 8, 8);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:88"();
  builtin debug6 ""(1);
  k = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       k = k + 1) {
    if (! (k < 16)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:fftw.c:89"();
    printf(__stringlit_6157a67d3fc59efa50dbcd1f9bf8a50f1, k, *(o_522 + k));
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:fftw.c:90"();
  return 0;
  builtin debug6 ""();
  return 0;
}


