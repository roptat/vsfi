int wordcode_interp(unsigned int *);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_c6a1b728958c59fc8d72aa561e6818b61[22] = "Partial application.\012";

static /*signed*/ char const __stringlit_c6a1b728958c59fc8d72aa561e6818b63[15] = "fib(30) = %ld\012";

static /*signed*/ char const __stringlit_c6a1b728958c59fc8d72aa561e6818b62[19] = "Over-application.\012";

static /*signed*/ char const __stringlit_c6a1b728958c59fc8d72aa561e6818b64[22] = "tak(18, 12, 6) = %ld\012";

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

extern void exit(int);

int stack[256];

int wordcode_interp(unsigned int *code)
{
  int *sp;
  unsigned int *pc;
  unsigned int instr;
  int extra_args;
  int arg;
  int arg__1;
  unsigned int ext;
  int arg1;
  int arg2;
  int arg3;
  int res;
  int arg1__1;
  int arg2__1;
  int arg1__2;
  int arg2__2;
  int arg__2;
  int arg__3;
  int required;
  int res__1;
  register unsigned int *$224;
  register unsigned int *$223;
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:57"();
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:58"();
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:59"();
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:60"();
  extra_args = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:62"();
  sp = stack + 256;
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:63"();
  pc = code;
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:64"();
  while (1) {
    (void)0 /*skip*/;
    builtin debug6 ""(1);
    builtin debug1 "#line:vmach.c:65"();
    $223 = pc;
    pc = $223 + 1;
    instr = *$223;
    builtin debug6 ""(1);
    builtin debug1 "#line:vmach.c:66"();
    switch (instr & 255) {
      case 0:
        builtin debug6 ""(1);
      case 1:
        builtin debug6 ""(1, 11);
        builtin debug1 "#line:vmach.c:69"();
        arg = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 11);
        builtin debug1 "#line:vmach.c:70"();
        sp = sp + (instr & 1);
        builtin debug6 ""(1, 11);
        builtin debug1 "#line:vmach.c:71"();
        sp = sp - 3;
        *(sp + 2) = (int) pc;
        *(sp + 1) = extra_args;
        *(sp + 0) = arg;
        builtin debug6 ""(1, 11);
        builtin debug1 "#line:vmach.c:72"();
        pc = pc + ((int) instr >> 16);
        builtin debug6 ""(1, 11);
        builtin debug1 "#line:vmach.c:73"();
        extra_args = 0;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:76"();
      case 2:
        builtin debug6 ""(1);
      case 3:
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:77"();
        sp = sp + (instr & 1);
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:78"();
        sp = sp - 1;
        *(sp + 0) = (int) instr >> 8;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:81"();
      case 4:
        builtin debug6 ""(1);
      case 5:
        builtin debug6 ""(1, 10);
        builtin debug1 "#line:vmach.c:82"();
        arg__1 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 10);
        builtin debug1 "#line:vmach.c:83"();
        sp = sp + (instr & 1);
        builtin debug6 ""(1, 10);
        builtin debug1 "#line:vmach.c:84"();
        if (arg__1) {
          builtin debug6 ""(1, 10);
          pc = pc + ((int) instr >> 16);
        }
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:87"();
      case 6:
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:88"();
        $224 = pc;
        pc = $224 + 1;
        ext = *$224;
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:89"();
        arg1 = *(sp + (ext & 255));
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:90"();
        arg2 = *(sp + (ext >> 8 & 255));
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:91"();
        arg3 = *(sp + (ext >> 16 & 255));
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:92"();
        sp = sp + (instr >> 8 & 255);
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:93"();
        sp = sp - 5;
        *(sp + 4) = (int) pc;
        *(sp + 3) = extra_args;
        *(sp + 2) = arg3;
        *(sp + 1) = arg2;
        *(sp + 0) = arg1;
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:94"();
        pc = pc + ((int) instr >> 16);
        builtin debug6 ""(1, 9);
        builtin debug1 "#line:vmach.c:95"();
        extra_args = 2;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:98"();
      case 7:
        builtin debug6 ""(1, 8);
        builtin debug1 "#line:vmach.c:99"();
        res = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 8);
        builtin debug1 "#line:vmach.c:100"();
        sp = sp + (instr >> 16 & 255);
        builtin debug6 ""(1, 8);
        builtin debug1 "#line:vmach.c:101"();
        if (extra_args > 0) {
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:102"();
          printf(__stringlit_c6a1b728958c59fc8d72aa561e6818b62);
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:103"();
          exit(2);
        } else {
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:105"();
          extra_args = *(sp + 0);
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:106"();
          pc = (unsigned int *) *(sp + 1);
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:107"();
          sp = sp + 1;
          builtin debug6 ""(1, 8);
          builtin debug1 "#line:vmach.c:108"();
          *sp = res;
        }
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:112"();
      case 8:
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:113"();
        sp = sp + (instr >> 8 & 255);
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:114"();
        pc = pc + ((int) instr >> 16);
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:117"();
      case 9:
        builtin debug6 ""(1, 7);
        builtin debug1 "#line:vmach.c:118"();
        arg1__1 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 7);
        arg2__1 = *(sp + (instr >> 16 & 255));
        builtin debug6 ""(1, 7);
        builtin debug1 "#line:vmach.c:119"();
        sp = sp + (instr >> 24);
        builtin debug6 ""(1, 7);
        builtin debug1 "#line:vmach.c:120"();
        sp = sp - 1;
        *(sp + 0) = arg1__1 < arg2__1;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:123"();
      case 10:
        builtin debug6 ""(1, 6);
        builtin debug1 "#line:vmach.c:124"();
        arg1__2 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 6);
        arg2__2 = *(sp + (instr >> 16 & 255));
        builtin debug6 ""(1, 6);
        builtin debug1 "#line:vmach.c:125"();
        sp = sp + (instr >> 24);
        builtin debug6 ""(1, 6);
        builtin debug1 "#line:vmach.c:126"();
        sp = sp - 1;
        *(sp + 0) = arg1__2 + arg2__2;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:129"();
      case 11:
        builtin debug6 ""(1, 5);
        builtin debug1 "#line:vmach.c:130"();
        arg__2 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 5);
        builtin debug1 "#line:vmach.c:131"();
        sp = sp + (instr >> 16 & 255);
        builtin debug6 ""(1, 5);
        builtin debug1 "#line:vmach.c:132"();
        sp = sp - 1;
        *(sp + 0) = arg__2 + ((int) instr >> 24);
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:135"();
      case 12:
        builtin debug6 ""(1, 4);
        builtin debug1 "#line:vmach.c:136"();
        arg__3 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 4);
        builtin debug1 "#line:vmach.c:137"();
        sp = sp - 1;
        *(sp + 0) = arg__3;
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:140"();
      case 13:
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:vmach.c:141"();
        required = instr >> 8 & 255;
        builtin debug6 ""(1, 3);
        builtin debug1 "#line:vmach.c:142"();
        if (extra_args >= required) {
          builtin debug6 ""(1, 3);
          builtin debug1 "#line:vmach.c:143"();
          extra_args = extra_args - required;
        } else {
          builtin debug6 ""(1, 3);
          builtin debug1 "#line:vmach.c:145"();
          printf(__stringlit_c6a1b728958c59fc8d72aa561e6818b61);
          builtin debug6 ""(1, 3);
          builtin debug1 "#line:vmach.c:146"();
          exit(2);
        }
        break;
        builtin debug6 ""(1);
        builtin debug1 "#line:vmach.c:150"();
      case 14:
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:vmach.c:151"();
        res__1 = *(sp + (instr >> 8 & 255));
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:vmach.c:152"();
        sp = sp + (instr >> 16 & 255);
        builtin debug6 ""(1, 2);
        builtin debug1 "#line:vmach.c:153"();
        return res__1;
        break;
      
    }
  }
}

 unsigned int wordcode_fib[14] = { 7682, 65537, 65550, 514, 16777481, 393221,
  -16777205, -327679, -33554165, -458751, 33619978, 131079, 258, 131079, };

 unsigned int wordcode_tak[23] = { 1538, 3074, 4610, 66310, 131328, 65550,
  525, 265, 131077, 524, 262151, -16777205, -524026, 197120, -16776693,
  -720634, 132096, -16776181, -917242, 262912, -1047802, 258, 262151, };

int main(int argc, /*signed*/ char **argv)
{
  int i;
  register int $226;
  register int $225;
  register int $224;
  register int $223;
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:206"();
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:208"();
  $223 = wordcode_interp(wordcode_fib);
  printf(__stringlit_c6a1b728958c59fc8d72aa561e6818b63, $223);
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:209"();
  $224 = wordcode_interp(wordcode_tak);
  printf(__stringlit_c6a1b728958c59fc8d72aa561e6818b64, $224);
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:210"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 10)) {
      break;
    }
    builtin debug6 ""(1);
    $225 = wordcode_interp(wordcode_fib);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:211"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 500)) {
      break;
    }
    builtin debug6 ""(1);
    $226 = wordcode_interp(wordcode_tak);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:vmach.c:213"();
  return 0;
  builtin debug6 ""();
  return 0;
}


