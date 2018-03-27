struct _IO_marker;
struct _IO_FILE;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};

struct _IO_FILE {
  int _flags;
  /*signed*/ char *_IO_read_ptr;
  /*signed*/ char *_IO_read_end;
  /*signed*/ char *_IO_read_base;
  /*signed*/ char *_IO_write_base;
  /*signed*/ char *_IO_write_ptr;
  /*signed*/ char *_IO_write_end;
  /*signed*/ char *_IO_buf_base;
  /*signed*/ char *_IO_buf_end;
  /*signed*/ char *_IO_save_base;
  /*signed*/ char *_IO_backup_base;
  /*signed*/ char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  int _old_offset;
  unsigned short _cur_column;
  /*signed*/ char _vtable_offset;
  /*signed*/ char _shortbuf[1];
  void *_lock;
  long long _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  unsigned int __pad5;
  int _mode;
  /*signed*/ char _unused2[40];
};

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_2891eb5868a6bbbae1d96db9a16e696d1[10] = "P4\012%d %d\012";

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

extern int _IO_putc(int, struct _IO_FILE *);

extern struct _IO_FILE *stdout;

extern int printf(/*signed*/ char *, ...);

extern int atoi(/*signed*/ char *);

int main(int argc, /*signed*/ char **argv)
{
  int w;
  int h;
  int bit_num;
  /*signed*/ char byte_acc;
  int i;
  int iter;
  double x;
  double y;
  double limit;
  double Zr;
  double Zi;
  double Cr;
  double Ci;
  double Tr;
  double Ti;
  register int $216;
  register double $215;
  register double $214;
  register double $213;
  register int $212;
  register int $211;
  register int $210;
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:18"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  bit_num = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:19"();
  byte_acc = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:20"();
  builtin debug6 ""(1);
  iter = 50;
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:21"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  limit = 2;
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:22"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:24"();
  if (argc < 2) {
    builtin debug6 ""(1);
    builtin debug1 "#line:mandelbrot.c:25"();
    $210 = (int) 3000;
    h = $210;
    w = $210;
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:mandelbrot.c:27"();
    $211 = atoi(*(argv + 1));
    $212 = (int) $211;
    h = $212;
    w = $212;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:30"();
  printf(__stringlit_2891eb5868a6bbbae1d96db9a16e696d1, w, h);
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:32"();
  builtin debug6 ""(1);
  y = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       y = y + 1) {
    if (! (y < h)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:mandelbrot.c:34"();
    builtin debug6 ""(1);
    x = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         x = x + 1) {
      if (! (x < w)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:36"();
      $213 = (double) 0;
      Ti = $213;
      $214 = (double) $213;
      Tr = $214;
      $215 = (double) $214;
      Zi = $215;
      Zr = $215;
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:37"();
      Cr = 2 * x / w - 1.5;
      builtin debug6 ""(1);
      Ci = 2 * y / h - 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:39"();
      builtin debug6 ""(1);
      i = 0;
      for (;
           1;
           (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
           i = i + 1) {
        if (i < iter) {
          $216 = (_Bool) (Tr + Ti <= limit * limit);
        } else {
          $216 = 0;
        }
        if (! $216) {
          break;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:41"();
        Zi = 2 * Zr * Zi + Ci;
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:42"();
        Zr = Tr - Ti + Cr;
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:43"();
        Tr = Zr * Zr;
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:44"();
        Ti = Zi * Zi;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:47"();
      byte_acc = byte_acc << 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:48"();
      if (Tr + Ti <= limit * limit) {
        builtin debug6 ""(1);
        byte_acc = byte_acc | 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:50"();
      bit_num = bit_num + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:mandelbrot.c:52"();
      if (bit_num == 8) {
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:54"();
        _IO_putc(byte_acc, stdout);
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:55"();
        byte_acc = 0;
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:56"();
        bit_num = 0;
      } else {
        builtin debug6 ""(1);
        builtin debug1 "#line:mandelbrot.c:58"();
        if (x == w - 1) {
          builtin debug6 ""(1);
          builtin debug1 "#line:mandelbrot.c:60"();
          byte_acc = byte_acc << 8 - w % 8;
          builtin debug6 ""(1);
          builtin debug1 "#line:mandelbrot.c:61"();
          _IO_putc(byte_acc, stdout);
          builtin debug6 ""(1);
          builtin debug1 "#line:mandelbrot.c:62"();
          byte_acc = 0;
          builtin debug6 ""(1);
          builtin debug1 "#line:mandelbrot.c:63"();
          bit_num = 0;
        }
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:mandelbrot.c:67"();
  return 0;
  builtin debug6 ""();
  return 0;
}


