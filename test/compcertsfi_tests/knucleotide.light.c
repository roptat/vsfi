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

int ht_hashcode_722(struct ht_ht *, /*signed*/ char *);

struct ht_node *ht_node_create(/*signed*/ char *);

struct ht_ht *ht_create(int);

void ht_destroy(struct ht_ht *);

struct ht_node *ht_find(struct ht_ht *, /*signed*/ char *);

struct ht_node *ht_find_new(struct ht_ht *, /*signed*/ char *);

struct ht_node *ht_next(struct ht_ht *);

struct ht_node *ht_first(struct ht_ht *);

int hash_table_size(int, int);

struct ht_ht *generate_frequencies(int, /*signed*/ char *, int);

void write_frequencies(int, /*signed*/ char *, int);

void write_count(/*signed*/ char *, /*signed*/ char *, int);

int main(void);

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
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:53"();
  val = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:54"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       key = key + 1) {
    if (! *key) {
      break;
    }
    builtin debug6 ""(1);
    val = 5 * val + *key;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:55"();
  return val % (*ht).size;
}

struct ht_node *ht_node_create(/*signed*/ char *key)
{
  /*signed*/ char *newkey;
  struct ht_node *node;
  register /*signed*/ char *$424;
  register void *$423;
  register unsigned int $422;
  register struct ht_node *$421;
  register void *$420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:59"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:60"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:61"();
  $420 = malloc(sizeof(struct ht_node));
  $421 = (struct ht_node *) (struct ht_node *) $420;
  node = $421;
  if ($421 == (void *) 0) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:62"();
    perror(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53281);
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:63"();
    exit(1);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:65"();
  $422 = strlen(key);
  $423 = malloc($422 + 1);
  $424 = (/*signed*/ char *) $423;
  newkey = $424;
  if ($424 == (void *) 0) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:66"();
    perror(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53282);
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:67"();
    exit(1);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:69"();
  strcpy(newkey, key);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:70"();
  (*node).key = newkey;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:71"();
  (*node).val = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:72"();
  (*node).next = (struct ht_node *) (void *) 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:73"();
  return node;
}

struct ht_ht *ht_create(int size)
{
  int i;
  struct ht_ht *ht;
  register void *$421;
  register void *$420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:77"();
  i = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:78"();
  $420 = malloc(sizeof(struct ht_ht));
  ht = (struct ht_ht *) $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:79"();
  while (1) {
    if (! (*(ht_prime_list_711 + i) < size)) {
      break;
    }
    builtin debug6 ""(1);
    i = i + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:80"();
  (*ht).size = *(ht_prime_list_711 + i);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:81"();
  $421 = calloc((*ht).size, sizeof(struct ht_node *));
  (*ht).tbl = (struct ht_node **) $421;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:82"();
  (*ht).iter_index = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:83"();
  (*ht).iter_next = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:84"();
  (*ht).items = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:88"();
  return ht;
}

void ht_destroy(struct ht_ht *ht)
{
  struct ht_node *cur;
  struct ht_node *next;
  int i;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:92"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:93"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:102"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < (*ht).size)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:103"();
    next = *((*ht).tbl + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:110"();
    while (1) {
      if (! next) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:111"();
      cur = next;
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:112"();
      next = (*next).next;
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:113"();
      free((*cur).key);
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:114"();
      free(cur);
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:124"();
  free((*ht).tbl);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:125"();
  free(ht);
}

struct ht_node *ht_find(struct ht_ht *ht, /*signed*/ char *key)
{
  int hash_code;
  struct ht_node *node;
  register int $421;
  register int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:133"();
  $420 = ht_hashcode_722(ht, key);
  hash_code = $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:134"();
  node = *((*ht).tbl + hash_code);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:135"();
  while (1) {
    if (! node) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:136"();
    $421 = strcmp(key, (*node).key);
    if ($421 == 0) {
      builtin debug6 ""(1);
      return node;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:137"();
    node = (*node).next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:139"();
  return (struct ht_node *) (void *) 0;
}

struct ht_node *ht_find_new(struct ht_ht *ht, /*signed*/ char *key)
{
  int hash_code;
  struct ht_node *prev;
  struct ht_node *node;
  register struct ht_node *$425;
  register struct ht_node *$424;
  register struct ht_node *$423;
  register struct ht_node *$422;
  register int $421;
  register int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:143"();
  $420 = ht_hashcode_722(ht, key);
  hash_code = $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:144"();
  prev = 0;
  builtin debug6 ""(1);
  node = *((*ht).tbl + hash_code);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:145"();
  while (1) {
    if (! node) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:146"();
    $421 = strcmp(key, (*node).key);
    if ($421 == 0) {
      builtin debug6 ""(1);
      return node;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:147"();
    prev = node;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:148"();
    node = (*node).next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:153"();
  (*ht).items = (*ht).items + 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:154"();
  if (prev) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:155"();
    $422 = ht_node_create(key);
    $423 = (struct ht_node *) $422;
    (*prev).next = $423;
    return $423;
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:157"();
    $424 = ht_node_create(key);
    $425 = (struct ht_node *) $424;
    *((*ht).tbl + hash_code) = $425;
    return $425;
  }
}

struct ht_node *ht_next(struct ht_ht *ht)
{
  unsigned int index;
  struct ht_node *node;
  register int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:165"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:166"();
  node = (*ht).iter_next;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:167"();
  if (node) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:168"();
    (*ht).iter_next = (*node).next;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:169"();
    return node;
  } else {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:171"();
    while (1) {
      if (! ((*ht).iter_index < (*ht).size)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:172"();
      $420 = (*ht).iter_index;
      (*ht).iter_index = $420 + 1;
      index = $420;
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:173"();
      if (*((*ht).tbl + index)) {
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:174"();
        (*ht).iter_next = (**((*ht).tbl + index)).next;
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:175"();
        return *((*ht).tbl + index);
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:179"();
  return (struct ht_node *) (void *) 0;
}

struct ht_node *ht_first(struct ht_ht *ht)
{
  register struct ht_node *$420;
  builtin debug6 ""();
  builtin debug1 "#line:knucleotide.c:183"();
  (*ht).iter_index = 0;
  builtin debug6 ""();
  builtin debug1 "#line:knucleotide.c:184"();
  (*ht).iter_next = (struct ht_node *) (void *) 0;
  builtin debug6 ""();
  builtin debug1 "#line:knucleotide.c:185"();
  $420 = ht_next(ht);
  return $420;
}

int hash_table_size(int fl, int buflen)
{
  int maxsize1;
  int maxsize2;
  register int $421;
  register int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:195"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:197"();
  maxsize1 = buflen - fl;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:198"();
  maxsize2 = 4;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:199"();
  while (1) {
    $420 = (int) (fl - 1);
    fl = $420;
    if ($420 > 0) {
      $421 = (_Bool) (maxsize2 < maxsize1);
    } else {
      $421 = 0;
    }
    if (! $421) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:200"();
    maxsize2 = maxsize2 * 4;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:201"();
  if (maxsize1 < maxsize2) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:202"();
    return maxsize1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:203"();
  return maxsize2;
}

struct ht_ht *generate_frequencies(int fl, /*signed*/ char *buffer, int buflen)
{
  struct ht_ht *ht;
  /*signed*/ char *reader;
  int i;
  /*signed*/ char nulled;
  register struct ht_node *$422;
  register struct ht_ht *$421;
  register int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:209"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:210"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:211"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:212"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:214"();
  if (fl > buflen) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:215"();
    return (void *) 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:217"();
  $420 = hash_table_size(fl, buflen);
  $421 = ht_create($420);
  ht = $421;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:218"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < buflen - fl + 1)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:220"();
    reader = &*(buffer + i);
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:221"();
    nulled = *(reader + fl);
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:222"();
    *(reader + fl) = 0;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:223"();
    $422 = ht_find_new(ht, reader);
    (*$422).val = (*$422).val + 1;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:224"();
    *(reader + fl) = nulled;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:226"();
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
  register int $426;
  register struct ht_node *$425;
  register struct ht_node *$424;
  register void *$423;
  register struct ht_node *$422;
  register struct ht_node *$421;
  register struct ht_ht *$420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:238"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:239"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:240"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:241"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:242"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:244"();
  $420 = generate_frequencies(fl, buffer, buflen);
  ht = $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:245"();
  total = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:246"();
  size = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:247"();
  builtin debug6 ""(1);
  $421 = ht_first(ht);
  nd = $421;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       $422 =
         ht_next
         (ht), nd = $422) {
    if (! (nd != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:249"();
    total = total + (*nd).val;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:250"();
    size = size + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:252"();
  $423 = calloc(size, sizeof(struct ssorter));
  s = $423;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:253"();
  i = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:254"();
  builtin debug6 ""(1);
  $424 = ht_first(ht);
  nd = $424;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       $425 =
         ht_next
         (ht), nd = $425) {
    if (! (nd != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:256"();
    (*(s + i)).string = (*nd).key;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:257"();
    $426 = i;
    i = $426 + 1;
    (*(s + $426)).num = (*nd).val;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:259"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < size - 1)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:260"();
    builtin debug6 ""(1);
    j = i + 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < size)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:261"();
      if ((*(s + i)).num < (*(s + j)).num) {
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:263"();
        memcpy(&tmp, &*(s + i), sizeof(struct ssorter));
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:264"();
        memcpy(&*(s + i), &*(s + j), sizeof(struct ssorter));
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:265"();
        memcpy(&*(s + j), &tmp, sizeof(struct ssorter));
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:267"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < size)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:268"();
    printf
      (__stringlit_c1fb19aa9292ad6c0c40bc46e02b53283, (*(s + i)).string,
       100 * (float) (*(s + i)).num / total);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:269"();
  printf(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53284);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:270"();
  ht_destroy(ht);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:271"();
  free(s);
}

void write_count(/*signed*/ char *searchFor, /*signed*/ char *buffer, int buflen)
{
  struct ht_ht *ht;
  register struct ht_node *$422;
  register struct ht_ht *$421;
  register unsigned int $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:277"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:279"();
  $420 = strlen(searchFor);
  $421 = generate_frequencies($420, buffer, buflen);
  ht = $421;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:280"();
  $422 = ht_find_new(ht, searchFor);
  printf
    (__stringlit_c1fb19aa9292ad6c0c40bc46e02b53285, (*$422).val, searchFor);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:281"();
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
  register struct ht_ht *$431;
  register int $430;
  register void *$429;
  register unsigned int $428;
  register /*signed*/ char *$427;
  register void *$426;
  register int $425;
  register int $424;
  register /*signed*/ char *$423;
  register int $422;
  register struct _IO_FILE *$421;
  register void *$420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:289"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:290"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:291"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:292"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:293"();
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:295"();
  $420 = malloc(256);
  line = $420;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:296"();
  if (!line) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:297"();
    return 2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:298"();
  seqlen = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:299"();
  nothree = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:301"();
  $421 =
    fopen
    (__stringlit_c1fb19aa9292ad6c0c40bc46e02b53287,
     __stringlit_c1fb19aa9292ad6c0c40bc46e02b53286);
  f = $421;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:302"();
  if (f == (void *) 0) {
    builtin debug6 ""(1);
    return 2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:304"();
  while (1) {
    if (nothree) {
      $423 = fgets(line, 255, f);
      $422 = (_Bool) $423;
    } else {
      $422 = 0;
    }
    if (! $422) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:305"();
    if (*(line + 0) == 62) {
      $424 = (_Bool) (*(line + 1) == 84);
    } else {
      $424 = 0;
    }
    if ($424) {
      $425 = (_Bool) (*(line + 2) == 72);
    } else {
      $425 = 0;
    }
    if ($425) {
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:306"();
      nothree = 0;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:307"();
  free(line);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:309"();
  buflen = 10240;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:310"();
  $426 = malloc(buflen + 1);
  buffer = $426;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:311"();
  if (!buffer) {
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:312"();
    return 2;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:313"();
  x = buffer;
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:315"();
  while (1) {
    $427 = fgets(x, 255, f);
    if (! $427) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:317"();
    $428 = strlen(x);
    linelen = $428;
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:318"();
    if (linelen) {
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:320"();
      if (*(x + (linelen - 1)) == 10) {
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:321"();
        linelen = linelen - 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:322"();
      c = *(x + 0);
      builtin debug6 ""(1);
      builtin debug1 "#line:knucleotide.c:323"();
      if (c == 62) {
        break;
      } else {
        builtin debug6 ""(1);
        builtin debug1 "#line:knucleotide.c:325"();
        if (c != 59) {
          builtin debug6 ""(1);
          builtin debug1 "#line:knucleotide.c:327"();
          seqlen = seqlen + linelen;
          builtin debug6 ""(1);
          builtin debug1 "#line:knucleotide.c:328"();
          if (seqlen + 512 >= buflen) {
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:330"();
            buflen = buflen + 10240;
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:331"();
            $429 = realloc(buffer, buflen + 1);
            tmp = $429;
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:332"();
            if (tmp == (void *) 0) {
              builtin debug6 ""(1);
              builtin debug1 "#line:knucleotide.c:333"();
              return 2;
            }
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:334"();
            buffer = tmp;
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:335"();
            x = &*(buffer + seqlen);
          } else {
            builtin debug6 ""(1);
            builtin debug1 "#line:knucleotide.c:338"();
            x = &*(x + linelen);
          }
          builtin debug6 ""(1);
          builtin debug1 "#line:knucleotide.c:339"();
          *(x + 0) = 0;
        }
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:343"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < seqlen)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:knucleotide.c:344"();
    $430 = toupper(*(buffer + i));
    *(buffer + i) = $430;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:345"();
  write_frequencies(1, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:346"();
  write_frequencies(2, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:347"();
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53288, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:348"();
  write_count(__stringlit_c1fb19aa9292ad6c0c40bc46e02b53289, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:349"();
  write_count
    (__stringlit_c1fb19aa9292ad6c0c40bc46e02b532810, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:350"();
  write_count
    (__stringlit_c1fb19aa9292ad6c0c40bc46e02b532811, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:351"();
  write_count
    (__stringlit_c1fb19aa9292ad6c0c40bc46e02b532812, buffer, seqlen);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:352"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 500)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:knucleotide.c:353"();
    $431 = generate_frequencies(6, buffer, seqlen);
    ht = $431;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:knucleotide.c:354"();
    ht_destroy(ht);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:356"();
  free(buffer);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:357"();
  fclose(f);
  builtin debug6 ""(1);
  builtin debug1 "#line:knucleotide.c:358"();
  return 0;
  builtin debug6 ""();
  return 0;
}


