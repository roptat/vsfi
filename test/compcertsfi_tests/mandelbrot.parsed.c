extern void __builtin_debug(int kind, ...);

typedef long long __quad_t;

typedef long __off_t;

typedef __quad_t __off64_t;

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

struct _IO_FILE;

typedef void _IO_lock_t;

struct _IO_marker;

struct _IO_marker {
  struct _IO_marker * _next;
  struct _IO_FILE * _sbuf;
  int _pos;
};

struct _IO_FILE {
  int _flags;
  char * _IO_read_ptr;
  char * _IO_read_end;
  char * _IO_read_base;
  char * _IO_write_base;
  char * _IO_write_ptr;
  char * _IO_write_end;
  char * _IO_buf_base;
  char * _IO_buf_end;
  char * _IO_save_base;
  char * _IO_backup_base;
  char * _IO_save_end;
  struct _IO_marker * _markers;
  struct _IO_FILE * _chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t * _lock;
  __off64_t _offset;
  void * __pad1;
  void * __pad2;
  void * __pad3;
  void * __pad4;
  size_t __pad5;
  int _mode;
  char _unused2[40];
};

typedef struct _IO_FILE _IO_FILE__1;

extern int _IO_putc(int __c, _IO_FILE__1 * __fp);

extern struct _IO_FILE * stdout;

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

int main(int argc, char * * argv)
{
  int w;
  int h;
  int bit_num;
  char byte_acc;
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
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:18");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  bit_num = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:19");
  byte_acc = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:20");
  __builtin_debug(6, "", 1);
  iter = 50;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:21");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  limit = 2.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:22");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:24");
  if (argc < 2) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:mandelbrot.c:25");
    w = h = 3000;
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:mandelbrot.c:27");
    w = h = atoi(argv[1]);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:30");
  printf("P4\n%d %d\n", w, h);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:32");
  for (__builtin_debug(6, "", 1), y = 0;
       y < h;
       __builtin_debug(6, "", 1), ++y) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:mandelbrot.c:34");
    for (__builtin_debug(6, "", 1), x = 0;
         x < w;
         __builtin_debug(6, "", 1), ++x) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:36");
      Zr = Zi = Tr = Ti = 0.0E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:37");
      Cr = 2.0E0 * x / w - 1.5E0;
      __builtin_debug(6, "", 1);
      Ci = 2.0E0 * y / h - 1.0E0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:39");
      for (__builtin_debug(6, "", 1), i = 0;
           i < iter && Tr + Ti <= limit * limit;
           __builtin_debug(6, "", 1), ++i) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:41");
        Zi = 2.0E0 * Zr * Zi + Ci;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:42");
        Zr = Tr - Ti + Cr;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:43");
        Tr = Zr * Zr;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:44");
        Ti = Zi * Zi;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:47");
      byte_acc <<= 1;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:48");
      if (Tr + Ti <= limit * limit) {
        __builtin_debug(6, "", 1);
        byte_acc |= 0x01;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:50");
      ++bit_num;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:mandelbrot.c:52");
      if (bit_num == 8) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:54");
        _IO_putc(byte_acc, stdout);
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:55");
        byte_acc = 0;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:56");
        bit_num = 0;
      } else {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:mandelbrot.c:58");
        if (x == w - 1) {
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:mandelbrot.c:60");
          byte_acc <<= 8 - w % 8;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:mandelbrot.c:61");
          _IO_putc(byte_acc, stdout);
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:mandelbrot.c:62");
          byte_acc = 0;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:mandelbrot.c:63");
          bit_num = 0;
        }
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:mandelbrot.c:67");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


