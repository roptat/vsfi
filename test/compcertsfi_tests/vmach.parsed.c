extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern int printf(char const * __format, ...);

extern void exit(int __status);

enum wordcode_instruct {
  WCALL1,
  WCALL1_pop1,
  WCONST,
  WCONST_pop1,
  WBRANCHIF,
  WBRANCHIF_pop1,
  WCALL3,
  WRETURN,
  WBRANCH,
  WLTINT,
  WADDINT,
  WOFFSETINT,
  WDUP,
  WGRAB,
  WSTOP,
};

long stack[256];

long wordcode_interp(unsigned int * code)
{
  long * sp;
  unsigned int * pc;
  unsigned int instr;
  int extra_args;
  long arg;
  long arg__1;
  unsigned int ext;
  long arg1;
  long arg2;
  long arg3;
  long res;
  long arg1__1;
  long arg2__1;
  long arg1__2;
  long arg2__2;
  long arg__2;
  long arg__3;
  int required;
  long res__1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:57");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:58");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:59");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:60");
  extra_args = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:62");
  sp = stack + 256;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:63");
  pc = code;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:64");
  while (1) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:vmach.c:65");
    instr = *pc++;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:vmach.c:66");
    switch (instr & 0xFF) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:68");
      case WCALL1:
      __builtin_debug(6, "", 1);
      case WCALL1_pop1:
      __builtin_debug(6, "", 1, 11);
      __builtin_debug(1, "#line:vmach.c:69");
      arg = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 11);
      __builtin_debug(1, "#line:vmach.c:70");
      sp += instr & 1;
      __builtin_debug(6, "", 1, 11);
      __builtin_debug(1, "#line:vmach.c:71");
      sp -= 3, sp[2] = (long) pc, sp[1] = extra_args, sp[0] = arg;
      __builtin_debug(6, "", 1, 11);
      __builtin_debug(1, "#line:vmach.c:72");
      pc += (int) instr >> 16;
      __builtin_debug(6, "", 1, 11);
      __builtin_debug(1, "#line:vmach.c:73");
      extra_args = 0;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:76");
      case WCONST:
      __builtin_debug(6, "", 1);
      case WCONST_pop1:
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:77");
      sp += instr & 1;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:78");
      sp -= 1, sp[0] = (int) instr >> 8;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:81");
      case WBRANCHIF:
      __builtin_debug(6, "", 1);
      case WBRANCHIF_pop1:
      __builtin_debug(6, "", 1, 10);
      __builtin_debug(1, "#line:vmach.c:82");
      arg__1 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 10);
      __builtin_debug(1, "#line:vmach.c:83");
      sp += instr & 1;
      __builtin_debug(6, "", 1, 10);
      __builtin_debug(1, "#line:vmach.c:84");
      if (arg__1) {
        __builtin_debug(6, "", 1, 10);
        pc += (int) instr >> 16;
      }
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:87");
      case WCALL3:
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:88");
      ext = *pc++;
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:89");
      arg1 = sp[ext & 0xFF];
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:90");
      arg2 = sp[ext >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:91");
      arg3 = sp[ext >> 16 & 0xFF];
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:92");
      sp += instr >> 8 & 0xFF;
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:93");
      sp -= 5, sp[4] = (long) pc, sp[3] = extra_args, sp[2] = arg3,
        sp[1] = arg2, sp[0] = arg1;
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:94");
      pc += (int) instr >> 16;
      __builtin_debug(6, "", 1, 9);
      __builtin_debug(1, "#line:vmach.c:95");
      extra_args = 2;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:98");
      case WRETURN:
      __builtin_debug(6, "", 1, 8);
      __builtin_debug(1, "#line:vmach.c:99");
      res = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 8);
      __builtin_debug(1, "#line:vmach.c:100");
      sp += instr >> 16 & 0xFF;
      __builtin_debug(6, "", 1, 8);
      __builtin_debug(1, "#line:vmach.c:101");
      if (extra_args > 0) {
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:102");
        printf("Over-application.\n");
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:103");
        exit(2);
      } else {
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:105");
        extra_args = sp[0];
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:106");
        pc = (unsigned int *) sp[1];
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:107");
        sp += 1;
        __builtin_debug(6, "", 1, 8);
        __builtin_debug(1, "#line:vmach.c:108");
        *sp = res;
      }
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:112");
      case WBRANCH:
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:113");
      sp += instr >> 8 & 0xFF;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:114");
      pc += (int) instr >> 16;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:117");
      case WLTINT:
      __builtin_debug(6, "", 1, 7);
      __builtin_debug(1, "#line:vmach.c:118");
      arg1__1 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 7);
      arg2__1 = sp[instr >> 16 & 0xFF];
      __builtin_debug(6, "", 1, 7);
      __builtin_debug(1, "#line:vmach.c:119");
      sp += instr >> 24;
      __builtin_debug(6, "", 1, 7);
      __builtin_debug(1, "#line:vmach.c:120");
      sp -= 1, sp[0] = arg1__1 < arg2__1;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:123");
      case WADDINT:
      __builtin_debug(6, "", 1, 6);
      __builtin_debug(1, "#line:vmach.c:124");
      arg1__2 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 6);
      arg2__2 = sp[instr >> 16 & 0xFF];
      __builtin_debug(6, "", 1, 6);
      __builtin_debug(1, "#line:vmach.c:125");
      sp += instr >> 24;
      __builtin_debug(6, "", 1, 6);
      __builtin_debug(1, "#line:vmach.c:126");
      sp -= 1, sp[0] = arg1__2 + arg2__2;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:129");
      case WOFFSETINT:
      __builtin_debug(6, "", 1, 5);
      __builtin_debug(1, "#line:vmach.c:130");
      arg__2 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 5);
      __builtin_debug(1, "#line:vmach.c:131");
      sp += instr >> 16 & 0xFF;
      __builtin_debug(6, "", 1, 5);
      __builtin_debug(1, "#line:vmach.c:132");
      sp -= 1, sp[0] = arg__2 + ((int) instr >> 24);
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:135");
      case WDUP:
      __builtin_debug(6, "", 1, 4);
      __builtin_debug(1, "#line:vmach.c:136");
      arg__3 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 4);
      __builtin_debug(1, "#line:vmach.c:137");
      sp -= 1, sp[0] = arg__3;
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:140");
      case WGRAB:
      __builtin_debug(6, "", 1, 3);
      __builtin_debug(1, "#line:vmach.c:141");
      required = instr >> 8 & 0xFF;
      __builtin_debug(6, "", 1, 3);
      __builtin_debug(1, "#line:vmach.c:142");
      if (extra_args >= required) {
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:vmach.c:143");
        extra_args -= required;
      } else {
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:vmach.c:145");
        printf("Partial application.\n");
        __builtin_debug(6, "", 1, 3);
        __builtin_debug(1, "#line:vmach.c:146");
        exit(2);
      }
      break;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:vmach.c:150");
      case WSTOP:
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:vmach.c:151");
      res__1 = sp[instr >> 8 & 0xFF];
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:vmach.c:152");
      sp += instr >> 16 & 0xFF;
      __builtin_debug(6, "", 1, 2);
      __builtin_debug(1, "#line:vmach.c:153");
      return res__1;
      break;
    }
  }
}

unsigned int wordcode_fib[14] =
  {WCONST + (30 << 8) + (0 << 16) + (0 << 24),
   WCALL1_pop1 + (0 << 8) + (3 - 1 - 1 << 16) + (0 << 24),
   WSTOP + (0 << 8) + (1 << 16) + (0 << 24),
   WCONST + (2 << 8) + (0 << 16) + (0 << 24),
   WLTINT + (1 << 8) + (0 << 16) + (1 << 24),
   WBRANCHIF_pop1 + (0 << 8) + (12 - 5 - 1 << 16) + (0 << 24),
   WOFFSETINT + (0 << 8) + (0 << 16) + (-1 << 24),
   WCALL1_pop1 + (0 << 8) + (3 - 7 - 1 << 16) + (0 << 24),
   WOFFSETINT + (1 << 8) + (0 << 16) + (-2 << 24),
   WCALL1_pop1 + (0 << 8) + (3 - 9 - 1 << 16) + (0 << 24),
   WADDINT + (0 << 8) + (1 << 16) + (2 << 24),
   WRETURN + (0 << 8) + (2 << 16) + (0 << 24),
   WCONST + (1 << 8) + (0 << 16) + (0 << 24),
   WRETURN + (0 << 8) + (2 << 16) + (0 << 24), };

unsigned int wordcode_tak[23] =
  {WCONST + (6 << 8) + (0 << 16) + (0 << 24),
   WCONST + (12 << 8) + (0 << 16) + (0 << 24),
   WCONST + (18 << 8) + (0 << 16) + (0 << 24),
   WCALL3 + (3 << 8) + (6 - 3 - 2 << 16) + (0 << 24),
   0 + (1 << 8) + (2 << 16) + (0 << 24),
   WSTOP + (0 << 8) + (1 << 16) + (0 << 24),
   WGRAB + (2 << 8) + (0 << 16) + (0 << 24),
   WLTINT + (1 << 8) + (0 << 16) + (0 << 24),
   WBRANCHIF_pop1 + (0 << 8) + (11 - 8 - 1 << 16) + (0 << 24),
   WDUP + (2 << 8) + (0 << 16) + (0 << 24),
   WRETURN + (0 << 8) + (4 << 16) + (0 << 24),
   WOFFSETINT + (0 << 8) + (0 << 16) + (-1 << 24),
   WCALL3 + (1 << 8) + (6 - 12 - 2 << 16) + (0 << 24),
   0 + (2 << 8) + (3 << 16) + (0 << 24),
   WOFFSETINT + (2 << 8) + (0 << 16) + (-1 << 24),
   WCALL3 + (1 << 8) + (6 - 15 - 2 << 16) + (0 << 24),
   0 + (4 << 8) + (2 << 16) + (0 << 24),
   WOFFSETINT + (4 << 8) + (0 << 16) + (-1 << 24),
   WCALL3 + (1 << 8) + (6 - 18 - 2 << 16) + (0 << 24),
   0 + (3 << 8) + (4 << 16) + (0 << 24),
   WCALL3 + (3 << 8) + (6 - 20 - 2 << 16) + (0 << 24),
   2 + (1 << 8) + (0 << 16) + (0 << 24),
   WRETURN + (0 << 8) + (4 << 16) + (0 << 24), };

int main(int argc, char * * argv)
{
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:206");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:208");
  printf("fib(30) = %ld\n", wordcode_interp(wordcode_fib));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:209");
  printf("tak(18, 12, 6) = %ld\n", wordcode_interp(wordcode_tak));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:210");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 10;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    (void) wordcode_interp(wordcode_fib);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:211");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 500;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    (void) wordcode_interp(wordcode_tak);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:vmach.c:213");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


