extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern int printf(char const * __format, ...);

typedef long INT;

typedef double R;

typedef R E;

typedef INT * stride;

void e01_8(R const * I, R * O, stride is, stride os, INT v, INT ivs, INT ovs)
{
  double KP1_662939224;
  double KP1_111140466;
  double KP390180644;
  double KP1_961570560;
  double KP707106781;
  double KP1_414213562;
  double KP765366864;
  double KP1_847759065;
  INT i;
  E T7;
  E Tl;
  E T4;
  E Tk;
  E Td;
  E To;
  E Tg;
  E Tn;
  E T5;
  E T6;
  E T1;
  E T3;
  E T2;
  E T9;
  E Tf;
  E Tc;
  E Te;
  E Ta;
  E Tb;
  E T8;
  E Th;
  E Tq;
  E Tr;
  E Ti;
  E Tj;
  E Tm;
  E Tp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:14");
  KP1_662939224 = (E) +1.662939224605090474157576755235811513477121624E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:15");
  KP1_111140466 = (E) +1.111140466039204449485661627897065748749874382E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:16");
  KP390180644 = (E) +0.390180644032256535696569736954044481855383236E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:17");
  KP1_961570560 = (E) +1.961570560806460898252364472268478073947867462E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:18");
  KP707106781 = (E) +0.707106781186547524400844362104849039284835938E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:19");
  KP1_414213562 = (E) +1.414213562373095048801688724209698078569671875E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:20");
  KP765366864 = (E) +0.765366864730179543456919968060797733522689125E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:21");
  KP1_847759065 = (E) +1.847759065022573512256366378793576573644833252E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:22");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:23");
  for (__builtin_debug(6, "", 1), i = v;
       i > 0;
       __builtin_debug(6, "", 1), (i = i - 1, I = I + ivs, O = O + ovs)) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:fftw.c:24");
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:26");
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:27");
    T5 = I[is[2]];
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:28");
    T6 = I[is[6]];
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:29");
    T7 = KP1_847759065 * T5 + KP765366864 * T6;
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:30");
    Tl = KP765366864 * T5 - KP1_847759065 * T6;
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:31");
    T1 = I[0];
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:32");
    T2 = I[is[4]];
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:33");
    T3 = KP1_414213562 * T2;
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:34");
    T4 = T1 + T3;
    __builtin_debug(6, "", 1, 2, 5);
    __builtin_debug(1, "#line:fftw.c:35");
    Tk = T1 - T3;
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:37");
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:38");
    T9 = I[is[1]];
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:39");
    Tf = I[is[7]];
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:40");
    Ta = I[is[5]];
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:41");
    Tb = I[is[3]];
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:42");
    Tc = KP707106781 * (Ta + Tb);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:43");
    Te = KP707106781 * (Ta - Tb);
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:44");
    Td = T9 + Tc;
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:45");
    To = Te + Tf;
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:46");
    Tg = Te - Tf;
    __builtin_debug(6, "", 1, 2, 5, 6);
    __builtin_debug(1, "#line:fftw.c:47");
    Tn = T9 - Tc;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:51");
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:52");
    T8 = T4 + T7;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:53");
    Th = KP1_961570560 * Td - KP390180644 * Tg;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:54");
    O[os[7]] = T8 - Th;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:55");
    O[0] = T8 + Th;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:56");
    Tq = Tk - Tl;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:57");
    Tr = KP1_111140466 * Tn + KP1_662939224 * To;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:58");
    O[os[5]] = Tq - Tr;
    __builtin_debug(6, "", 1, 2, 4);
    __builtin_debug(1, "#line:fftw.c:59");
    O[os[2]] = Tq + Tr;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:62");
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:63");
    Ti = T4 - T7;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:64");
    Tj = KP390180644 * Td + KP1_961570560 * Tg;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:65");
    O[os[4]] = Ti - Tj;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:66");
    O[os[3]] = Ti + Tj;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:67");
    Tm = Tk + Tl;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:68");
    Tp = KP1_662939224 * Tn - KP1_111140466 * To;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:69");
    O[os[6]] = Tm - Tp;
    __builtin_debug(6, "", 1, 2, 3);
    __builtin_debug(1, "#line:fftw.c:70");
    O[os[1]] = Tm + Tp;
  }
}

static INT s_520[8] = {0, 1, 2, 3, 4, 5, 6, 7, };

static R i_521[1024];

static R o_522[1024];

int main(void)
{
  int k;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:84");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:85");
  for (__builtin_debug(6, "", 1), k = 0;
       k < 1024;
       __builtin_debug(6, "", 1), ++k) {
    __builtin_debug(6, "", 1);
    i_521[k] = k;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:86");
  for (__builtin_debug(6, "", 1), k = 0;
       k < 1024 * 1024;
       __builtin_debug(6, "", 1), ++k) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fftw.c:87");
    e01_8(i_521, o_522, s_520, s_520, 64, 8, 8);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:88");
  for (__builtin_debug(6, "", 1), k = 0;
       k < 16;
       __builtin_debug(6, "", 1), ++k) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:fftw.c:89");
    printf("o[%d] = %.6e\n", k, o_522[k]);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:fftw.c:90");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


