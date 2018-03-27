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

typedef struct _IO_FILE FILE;

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

extern int fclose(FILE * __stream);

extern FILE * fopen(char const * __filename, char const * __modes);

extern int printf(char const * __format, ...);

extern char * fgets(char * __s, int __n, FILE * __stream);

extern void perror(char const * __s);

extern void * memcpy(void * __dest, void const * __src, size_t __n);

extern char * strcpy(char * __dest, char const * __src);

extern int strcmp(char const * __s1, char const * __s2);

extern size_t strlen(char const * __s);

extern int toupper(int __c);

extern void * malloc(size_t __size);

extern void * calloc(size_t __nmemb, size_t __size);

extern void * realloc(void * __ptr, size_t __size);

extern void free(void * __ptr);

extern void exit(int __status);

static unsigned long ht_prime_list_711[28] =
  {53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul, 6151ul, 12289ul, 
   24593ul, 49157ul, 98317ul, 196613ul, 393241ul, 786433ul, 1572869ul,
   3145739ul, 6291469ul, 12582917ul, 25165843ul, 50331653ul, 100663319ul,
   201326611ul, 402653189ul, 805306457ul, 1610612741ul, 3221225473ul,
   4294967291ul, };

struct ht_node;

struct ht_node {
  char * key;
  int val;
  struct ht_node * next;
};

struct ht_ht;

struct ht_ht {
  int size;
  struct ht_node * * tbl;
  int iter_index;
  struct ht_node * iter_next;
  int items;
};

inline static int ht_hashcode_722(struct ht_ht * ht, char * key)
{
  unsigned long val;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:53");
  val = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:54");
  for (/*nothing*/; *key; __builtin_debug(6, "", 1), ++key) {
    __builtin_debug(6, "", 1);
    val = 5 * val + *key;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:55");
  return val % ht->size;
}

struct ht_node * ht_node_create(char * key)
{
  char * newkey;
  struct ht_node * node;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:59");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:60");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:61");
  if ((node = (struct ht_node *) malloc(sizeof(struct ht_node)))
        == (void *) 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:62");
    perror("malloc ht_node");
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:63");
    exit(1);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:65");
  if ((newkey = malloc(strlen(key) + 1)) == (void *) 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:66");
    perror("strdup newkey");
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:67");
    exit(1);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:69");
  strcpy(newkey, key);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:70");
  node->key = newkey;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:71");
  node->val = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:72");
  node->next = (struct ht_node *) (void *) 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:73");
  return node;
}

struct ht_ht * ht_create(int size)
{
  int i;
  struct ht_ht * ht;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:77");
  i = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:78");
  ht = (struct ht_ht *) malloc(sizeof(struct ht_ht));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:79");
  while (ht_prime_list_711[i] < size) {
    __builtin_debug(6, "", 1);
    i++;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:80");
  ht->size = ht_prime_list_711[i];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:81");
  ht->tbl = (struct ht_node * *) calloc(ht->size, sizeof(struct ht_node *));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:82");
  ht->iter_index = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:83");
  ht->iter_next = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:84");
  ht->items = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:88");
  return ht;
}

void ht_destroy(struct ht_ht * ht)
{
  struct ht_node * cur;
  struct ht_node * next;
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:92");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:93");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:102");
  for (__builtin_debug(6, "", 1), i = 0;
       i < ht->size;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:103");
    next = ht->tbl[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:110");
    while (next) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:111");
      cur = next;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:112");
      next = next->next;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:113");
      free(cur->key);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:114");
      free(cur);
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:124");
  free(ht->tbl);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:125");
  free(ht);
}

struct ht_node * ht_find(struct ht_ht * ht, char * key)
{
  int hash_code;
  struct ht_node * node;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:133");
  hash_code = ht_hashcode_722(ht, key);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:134");
  node = ht->tbl[hash_code];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:135");
  while (node) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:136");
    if (strcmp(key, node->key) == 0) {
      __builtin_debug(6, "", 1);
      return node;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:137");
    node = node->next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:139");
  return (struct ht_node *) (void *) 0;
}

struct ht_node * ht_find_new(struct ht_ht * ht, char * key)
{
  int hash_code;
  struct ht_node * prev;
  struct ht_node * node;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:143");
  hash_code = ht_hashcode_722(ht, key);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:144");
  prev = 0;
  __builtin_debug(6, "", 1);
  node = ht->tbl[hash_code];
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:145");
  while (node) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:146");
    if (strcmp(key, node->key) == 0) {
      __builtin_debug(6, "", 1);
      return node;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:147");
    prev = node;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:148");
    node = node->next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:153");
  ht->items++;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:154");
  if (prev) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:155");
    return prev->next = ht_node_create(key);
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:157");
    return ht->tbl[hash_code] = ht_node_create(key);
  }
}

struct ht_node * ht_next(struct ht_ht * ht)
{
  unsigned long index;
  struct ht_node * node;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:165");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:166");
  node = ht->iter_next;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:167");
  if (node) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:168");
    ht->iter_next = node->next;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:169");
    return node;
  } else {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:171");
    while (ht->iter_index < ht->size) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:172");
      index = ht->iter_index++;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:173");
      if (ht->tbl[index]) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:174");
        ht->iter_next = ht->tbl[index]->next;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:175");
        return ht->tbl[index];
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:179");
  return (struct ht_node *) (void *) 0;
}

struct ht_node * ht_first(struct ht_ht * ht)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:knucleotide.c:183");
  ht->iter_index = 0;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:knucleotide.c:184");
  ht->iter_next = (struct ht_node *) (void *) 0;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:knucleotide.c:185");
  return ht_next(ht);
}

long hash_table_size(int fl, long buflen)
{
  long maxsize1;
  long maxsize2;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:195");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:197");
  maxsize1 = buflen - fl;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:198");
  maxsize2 = 4;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:199");
  while (--fl > 0 && maxsize2 < maxsize1) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:200");
    maxsize2 = maxsize2 * 4;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:201");
  if (maxsize1 < maxsize2) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:202");
    return maxsize1;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:203");
  return maxsize2;
}

struct ht_ht * generate_frequencies(int fl, char * buffer, long buflen)
{
  struct ht_ht * ht;
  char * reader;
  long i;
  char nulled;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:209");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:210");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:211");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:212");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:214");
  if (fl > buflen) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:215");
    return (void *) 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:217");
  ht = ht_create(hash_table_size(fl, buflen));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:218");
  for (__builtin_debug(6, "", 1), i = 0;
       i < buflen - fl + 1;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:220");
    reader = &buffer[i];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:221");
    nulled = reader[fl];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:222");
    reader[fl] = 0x00;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:223");
    ht_find_new(ht, reader)->val++;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:224");
    reader[fl] = nulled;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:226");
  return ht;
}

struct ssorter;

struct ssorter {
  char * string;
  int num;
};

typedef struct ssorter sorter;

void write_frequencies(int fl, char * buffer, long buflen)
{
  struct ht_ht * ht;
  long total;
  long i;
  long j;
  long size;
  struct ht_node * nd;
  sorter * s;
  sorter tmp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:238");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:239");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:240");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:241");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:242");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:244");
  ht = generate_frequencies(fl, buffer, buflen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:245");
  total = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:246");
  size = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:247");
  for (__builtin_debug(6, "", 1), nd = ht_first(ht);
       nd != (void *) 0;
       __builtin_debug(6, "", 1), nd = ht_next(ht)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:249");
    total = total + nd->val;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:250");
    size++;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:252");
  s = calloc(size, sizeof(sorter));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:253");
  i = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:254");
  for (__builtin_debug(6, "", 1), nd = ht_first(ht);
       nd != (void *) 0;
       __builtin_debug(6, "", 1), nd = ht_next(ht)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:256");
    s[i].string = nd->key;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:257");
    s[i++].num = nd->val;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:259");
  for (__builtin_debug(6, "", 1), i = 0;
       i < size - 1;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:260");
    for (__builtin_debug(6, "", 1), j = i + 1;
         j < size;
         __builtin_debug(6, "", 1), j++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:261");
      if (s[i].num < s[j].num) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:263");
        memcpy(&tmp, &s[i], sizeof(sorter));
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:264");
        memcpy(&s[i], &s[j], sizeof(sorter));
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:265");
        memcpy(&s[j], &tmp, sizeof(sorter));
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:267");
  for (__builtin_debug(6, "", 1), i = 0;
       i < size;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:268");
    printf("%s %.3f\n", s[i].string, 100 * (float) s[i].num / total);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:269");
  printf("\n");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:270");
  ht_destroy(ht);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:271");
  free(s);
}

void write_count(char * searchFor, char * buffer, long buflen)
{
  struct ht_ht * ht;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:277");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:279");
  ht = generate_frequencies(strlen(searchFor), buffer, buflen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:280");
  printf("%d\t%s\n", ht_find_new(ht, searchFor)->val, searchFor);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:281");
  ht_destroy(ht);
}

int main(void)
{
  char c;
  char * line;
  char * buffer;
  char * tmp;
  char * x;
  int i;
  int linelen;
  int nothree;
  long buflen;
  long seqlen;
  FILE * f;
  struct ht_ht * ht;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:289");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:290");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:291");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:292");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:293");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:295");
  line = malloc(256);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:296");
  if (!line) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:297");
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:298");
  seqlen = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:299");
  nothree = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:301");
  f = fopen("Results/knucleotide-input.txt", "r");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:302");
  if (f == (void *) 0) {
    __builtin_debug(6, "", 1);
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:304");
  while (nothree && fgets(line, 255, f)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:305");
    if (line[0] == 62 && line[1] == 84 && line[2] == 72) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:306");
      nothree = 0;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:307");
  free(line);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:309");
  buflen = 10240;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:310");
  buffer = malloc(buflen + 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:311");
  if (!buffer) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:312");
    return 2;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:313");
  x = buffer;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:315");
  while (fgets(x, 255, f)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:317");
    linelen = strlen(x);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:318");
    if (linelen) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:320");
      if (x[linelen - 1] == 10) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:321");
        linelen--;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:322");
      c = x[0];
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:knucleotide.c:323");
      if (c == 62) {
        break;
      } else {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:knucleotide.c:325");
        if (c != 59) {
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:knucleotide.c:327");
          seqlen = seqlen + linelen;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:knucleotide.c:328");
          if (seqlen + 512 >= buflen) {
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:330");
            buflen = buflen + 10240;
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:331");
            tmp = realloc(buffer, buflen + 1);
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:332");
            if (tmp == (void *) 0) {
              __builtin_debug(6, "", 1);
              __builtin_debug(1, "#line:knucleotide.c:333");
              return 2;
            }
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:334");
            buffer = tmp;
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:335");
            x = &buffer[seqlen];
          } else {
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:knucleotide.c:338");
            x = &x[linelen];
          }
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:knucleotide.c:339");
          x[0] = 0;
        }
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:343");
  for (__builtin_debug(6, "", 1), i = 0;
       i < seqlen;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:knucleotide.c:344");
    buffer[i] = toupper(buffer[i]);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:345");
  write_frequencies(1, buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:346");
  write_frequencies(2, buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:347");
  write_count("GGT", buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:348");
  write_count("GGTA", buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:349");
  write_count("GGTATT", buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:350");
  write_count("GGTATTTTAATT", buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:351");
  write_count("GGTATTTTAATTTATAGT", buffer, seqlen);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:352");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 500;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:knucleotide.c:353");
    ht = generate_frequencies(6, buffer, seqlen);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:knucleotide.c:354");
    ht_destroy(ht);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:356");
  free(buffer);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:357");
  fclose(f);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:knucleotide.c:358");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


