struct _IO_marker;
struct _IO_FILE;
struct ht_node;
struct ht_ht;
struct ssorter;
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

struct ht_node {
  /*signed*/ char *key;
  int val;
  struct ht_node *next;
};

struct ht_ht {
  int size;
  struct ht_node **tbl;
  int iter_index;
  struct ht_node *iter_next;
  int items;
};

struct ssorter {
  /*signed*/ char *string;
  int num;
};

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53286[2];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532812[19];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53288[4];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53287[30];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532810[7];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53282[14];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53284[2];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53285[7];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53283[9];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53289[5];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532811[13];

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53281[15];

extern unsigned int keep[2];

static unsigned int ht_prime_list_711[28];

static int ht_hashcode_722(struct ht_ht *, /*signed*/ char *);

extern struct ht_node *ht_node_create(/*signed*/ char *);

extern struct ht_ht *ht_create(int);

extern void ht_destroy(struct ht_ht *);

extern struct ht_node *ht_find(struct ht_ht *, /*signed*/ char *);

extern struct ht_node *ht_find_new(struct ht_ht *, /*signed*/ char *);

extern struct ht_node *ht_next(struct ht_ht *);

extern struct ht_node *ht_first(struct ht_ht *);

extern int hash_table_size(int, int);

extern struct ht_ht *generate_frequencies(int, /*signed*/ char *, int);

extern void write_frequencies(int, /*signed*/ char *, int);

extern void write_count(/*signed*/ char *, /*signed*/ char *, int);

extern int main(void);

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53286[2] = "r";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532812[19] = "GGTATTTTAATTTATAGT";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53288[4] = "GGT";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53287[30] = "Results/knucleotide-input.txt";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532810[7] = "GGTATT";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53282[14] = "strdup newkey";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53284[2] = "\012";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53285[7] = "%d\011%s\012";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53283[9] = "%s %.3f\012";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53289[5] = "GGTA";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b532811[13] = "GGTATTTTAATT";

static /*signed*/ char const __stringlit_c1fb19aa9292ad6c0c40bc46e02b53281[15] = "malloc ht_node";

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

extern int fclose(struct _IO_FILE *);

extern struct _IO_FILE *fopen(/*signed*/ char *, /*signed*/ char *);

extern int printf(/*signed*/ char *, ...);

extern /*signed*/ char *fgets(/*signed*/ char *, int, struct _IO_FILE *);

extern void perror(/*signed*/ char *);

extern void *memcpy(void *, void *, unsigned int);

extern /*signed*/ char *strcpy(/*signed*/ char *, /*signed*/ char *);

extern int strcmp(/*signed*/ char *, /*signed*/ char *);

extern unsigned int strlen(/*signed*/ char *);

extern int toupper(int);

extern void *malloc(unsigned int);

extern void *calloc(unsigned int, unsigned int);

extern void *realloc(void *, unsigned int);

extern void free(void *);

extern void exit(int);

static unsigned int ht_prime_list_711[28] = { 53, 97, 193, 389, 769, 1543,
  3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869,
  3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611,
  402653189, 805306457, 1610612741, -1073741823, -5, };

int ht_hashcode_722(struct ht_ht *ht, /*signed*/ char *key)
{
  unsigned int val;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:53");
  val = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:54");
  for (/*nothing*/; *key; __builtin_debug(6,"", 1), key += 1) {
    __builtin_debug(6,"", 1);
    val = 5 * val + *key;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:55");
  return val % ((*ht)).size;
}

struct ht_node *ht_node_create(/*signed*/ char *key)
{
  /*signed*/ char *newkey;
  struct ht_node *node;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:59");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:60");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:61");
  if ((node = (struct ht_node *) malloc(sizeof(struct ht_node)))
        == (void *) 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:62");
    perror(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53281);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:63");
    exit(1);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:65");
  if ((newkey = malloc(strlen(key) + 1)) == (void *) 0) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:66");
    perror(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53282);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:67");
    exit(1);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:69");
  strcpy(newkey, key);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:70");
  ((*node)).key = newkey;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:71");
  ((*node)).val = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:72");
  ((*node)).next = (struct ht_node *) (void *) 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:73");
  return node;
}

struct ht_ht *ht_create(int size)
{
  int i;
  struct ht_ht *ht;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:77");
  i = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:78");
  ht = (struct ht_ht *) malloc(sizeof(struct ht_ht));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:79");
  while (*(ht_prime_list_711 + i) < size) {
    __builtin_debug(6,"", 1);
    i++;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:80");
  ((*ht)).size = *(ht_prime_list_711 + i);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:81");
  ((*ht)).tbl =
    (struct ht_node **) calloc(((*ht)).size, sizeof(struct ht_node *));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:82");
  ((*ht)).iter_index = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:83");
  ((*ht)).iter_next = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:84");
  ((*ht)).items = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:88");
  return ht;
}

void ht_destroy(struct ht_ht *ht)
{
  struct ht_node *cur;
  struct ht_node *next;
  int i;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:92");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:93");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:102");
  for (__builtin_debug(6,"", 1), i = 0;
       i < ((*ht)).size;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:103");
    next = *(((*ht)).tbl + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:110");
    while (next) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:111");
      cur = next;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:112");
      next = ((*next)).next;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:113");
      free(((*cur)).key);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:114");
      free(cur);
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:124");
  free(((*ht)).tbl);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:125");
  free(ht);
}

struct ht_node *ht_find(struct ht_ht *ht, /*signed*/ char *key)
{
  int hash_code;
  struct ht_node *node;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:133");
  hash_code = ht_hashcode_722(ht, key);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:134");
  node = *(((*ht)).tbl + hash_code);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:135");
  while (node) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:136");
    if (strcmp(key, ((*node)).key) == 0) {
      __builtin_debug(6,"", 1);
      return node;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:137");
    node = ((*node)).next;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:139");
  return (struct ht_node *) (void *) 0;
}

struct ht_node *ht_find_new(struct ht_ht *ht, /*signed*/ char *key)
{
  int hash_code;
  struct ht_node *prev;
  struct ht_node *node;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:143");
  hash_code = ht_hashcode_722(ht, key);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:144");
  prev = 0;
  __builtin_debug(6,"", 1);
  node = *(((*ht)).tbl + hash_code);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:145");
  while (node) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:146");
    if (strcmp(key, ((*node)).key) == 0) {
      __builtin_debug(6,"", 1);
      return node;
    }
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:147");
    prev = node;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:148");
    node = ((*node)).next;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:153");
  ((*ht)).items++;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:154");
  if (prev) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:155");
    return ((*prev)).next = ht_node_create(key);
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:157");
    return *(((*ht)).tbl + hash_code) = ht_node_create(key);
  }
}

struct ht_node *ht_next(struct ht_ht *ht)
{
  unsigned int index;
  struct ht_node *node;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:165");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:166");
  node = ((*ht)).iter_next;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:167");
  if (node) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:168");
    ((*ht)).iter_next = ((*node)).next;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:169");
    return node;
  } else {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:171");
    while (((*ht)).iter_index < ((*ht)).size) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:172");
      index = ((*ht)).iter_index++;
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:173");
      if (*(((*ht)).tbl + index)) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:174");
        ((*ht)).iter_next = ((**(((*ht)).tbl + index))).next;
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:175");
        return *(((*ht)).tbl + index);
      }
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:179");
  return (struct ht_node *) (void *) 0;
}

struct ht_node *ht_first(struct ht_ht *ht)
{
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:knucleotide.c:183");
  ((*ht)).iter_index = 0;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:knucleotide.c:184");
  ((*ht)).iter_next = (struct ht_node *) (void *) 0;
  __builtin_debug(6,"");
  __builtin_debug(1,"#line:knucleotide.c:185");
  return ht_next(ht);
}

int hash_table_size(int fl, int buflen)
{
  int maxsize1;
  int maxsize2;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:195");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:197");
  maxsize1 = buflen - fl;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:198");
  maxsize2 = 4;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:199");
  while ((fl -= 1) > 0 && maxsize2 < maxsize1) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:200");
    maxsize2 = maxsize2 * 4;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:201");
  if (maxsize1 < maxsize2) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:202");
    return maxsize1;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:203");
  return maxsize2;
}

struct ht_ht *generate_frequencies(int fl, /*signed*/ char *buffer, int buflen)
{
  struct ht_ht *ht;
  /*signed*/ char *reader;
  int i;
  /*signed*/ char nulled;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:209");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:210");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:211");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:212");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:214");
  if (fl > buflen) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:215");
    return (void *) 0;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:217");
  ht = ht_create(hash_table_size(fl, buflen));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:218");
  for (__builtin_debug(6,"", 1), i = 0;
       i < buflen - fl + 1;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:220");
    reader = &*(buffer + i);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:221");
    nulled = *(reader + fl);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:222");
    *(reader + fl) = 0;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:223");
    ((*ht_find_new(ht, reader))).val++;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:224");
    *(reader + fl) = nulled;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:226");
  return ht;
}

void write_frequencies(int fl, /*signed*/ char *buffer, int buflen)
{
  struct ht_ht *ht;
  int total;
  int i;
  int j;
  int size;
  struct ht_node *nd;
  struct ssorter *s;
  struct ssorter tmp;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:238");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:239");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:240");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:241");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:242");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:244");
  ht = generate_frequencies(fl, buffer, buflen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:245");
  total = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:246");
  size = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:247");
  for (__builtin_debug(6,"", 1), nd = ht_first(ht);
       nd != (void *) 0;
       __builtin_debug(6,"", 1), nd = ht_next(ht)) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:249");
    total = total + ((*nd)).val;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:250");
    size++;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:252");
  s = calloc(size, sizeof(struct ssorter));
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:253");
  i = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:254");
  for (__builtin_debug(6,"", 1), nd = ht_first(ht);
       nd != (void *) 0;
       __builtin_debug(6,"", 1), nd = ht_next(ht)) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:256");
    ((*(s + i))).string = ((*nd)).key;
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:257");
    ((*(s + i++))).num = ((*nd)).val;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:259");
  for (__builtin_debug(6,"", 1), i = 0;
       i < size - 1;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:260");
    for (__builtin_debug(6,"", 1), j = i + 1;
         j < size;
         __builtin_debug(6,"", 1), j++) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:261");
      if (((*(s + i))).num < ((*(s + j))).num) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:263");
        memcpy(&tmp, &*(s + i), sizeof(struct ssorter));
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:264");
        memcpy(&*(s + i), &*(s + j), sizeof(struct ssorter));
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:265");
        memcpy(&*(s + j), &tmp, sizeof(struct ssorter));
      }
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:267");
  for (__builtin_debug(6,"", 1), i = 0;
       i < size;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:268");
    printf(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53283,
           ((*(s + i))).string, 100 * (float) ((*(s + i))).num / total);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:269");
  printf(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53284);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:270");
  ht_destroy(ht);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:271");
  free(s);
}

void write_count(/*signed*/ char *searchFor, /*signed*/ char *buffer, int buflen)
{
  struct ht_ht *ht;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:277");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:279");
  ht = generate_frequencies(strlen(searchFor), buffer, buflen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:280");
  printf(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53285,
         ((*ht_find_new(ht, searchFor))).val, searchFor);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:281");
  ht_destroy(ht);
}

int main(void)
{
  /*signed*/ char c;
  /*signed*/ char *line;
  /*signed*/ char *buffer;
  /*signed*/ char *tmp;
  /*signed*/ char *x;
  int i;
  int linelen;
  int nothree;
  int buflen;
  int seqlen;
  struct _IO_FILE *f;
  struct ht_ht *ht;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:289");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:290");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:291");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:292");
  __builtin_debug(6,"", 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:293");
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:295");
  line = malloc(256);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:296");
  if (!line) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:297");
    return 2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:298");
  seqlen = 0;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:299");
  nothree = 1;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:301");
  f =
    fopen(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53287,
          __stringlit_c1fb19aa9292ad6c0c40bc46e02b53286);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:302");
  if (f == (void *) 0) {
    __builtin_debug(6,"", 1);
    return 2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:304");
  while (nothree && fgets(line, 255, f)) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:305");
    if (*(line + 0) == 62 && *(line + 1) == 84 && *(line + 2) == 72) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:306");
      nothree = 0;
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:307");
  free(line);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:309");
  buflen = 10240;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:310");
  buffer = malloc(buflen + 1);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:311");
  if (!buffer) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:312");
    return 2;
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:313");
  x = buffer;
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:315");
  while (fgets(x, 255, f)) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:317");
    linelen = strlen(x);
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:318");
    if (linelen) {
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:320");
      if (*(x + (linelen - 1)) == 10) {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:321");
        linelen--;
      }
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:322");
      c = *(x + 0);
      __builtin_debug(6,"", 1);
      __builtin_debug(1,"#line:knucleotide.c:323");
      if (c == 62) {
        break;
      } else {
        __builtin_debug(6,"", 1);
        __builtin_debug(1,"#line:knucleotide.c:325");
        if (c != 59) {
          __builtin_debug(6,"", 1);
          __builtin_debug(1,"#line:knucleotide.c:327");
          seqlen = seqlen + linelen;
          __builtin_debug(6,"", 1);
          __builtin_debug(1,"#line:knucleotide.c:328");
          if (seqlen + 512 >= buflen) {
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:330");
            buflen = buflen + 10240;
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:331");
            tmp = realloc(buffer, buflen + 1);
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:332");
            if (tmp == (void *) 0) {
              __builtin_debug(6,"", 1);
              __builtin_debug(1,"#line:knucleotide.c:333");
              return 2;
            }
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:334");
            buffer = tmp;
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:335");
            x = &*(buffer + seqlen);
          } else {
            __builtin_debug(6,"", 1);
            __builtin_debug(1,"#line:knucleotide.c:338");
            x = &*(x + linelen);
          }
          __builtin_debug(6,"", 1);
          __builtin_debug(1,"#line:knucleotide.c:339");
          *(x + 0) = 0;
        }
      }
    }
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:343");
  for (__builtin_debug(6,"", 1), i = 0;
       i < seqlen;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1);
    __builtin_debug(1,"#line:knucleotide.c:344");
    *(buffer + i) = toupper(*(buffer + i));
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:345");
  write_frequencies(1, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:346");
  write_frequencies(2, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:347");
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53288, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:348");
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53289, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:349");
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b532810, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:350");
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b532811, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:351");
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b532812, buffer, seqlen);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:352");
  for (__builtin_debug(6,"", 1), i = 0;
       i < 500;
       __builtin_debug(6,"", 1), i++) {
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:knucleotide.c:353");
    ht = generate_frequencies(6, buffer, seqlen);
    __builtin_debug(6,"", 1, 2);
    __builtin_debug(1,"#line:knucleotide.c:354");
    ht_destroy(ht);
  }
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:356");
  free(buffer);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:357");
  fclose(f);
  __builtin_debug(6,"", 1);
  __builtin_debug(1,"#line:knucleotide.c:358");
  return 0;
  __builtin_debug(6,"");
  return 0;
}


