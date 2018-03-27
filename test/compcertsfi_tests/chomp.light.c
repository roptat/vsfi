struct _list;
struct _play;
struct _list {
  int *data;
  struct _list *next;
};

struct _play {
  int value;
  int *state;
  struct _list *first;
  struct _play *next;
};

int *copy_data(int *);

int next_data(int *);

void melt_data(int *, int *);

int equal_data(int *, int *);

int valid_data(int *);

void dump_list(struct _list *);

void dump_play(struct _play *);

int get_value(int *);

void show_data(int *);

void show_move(int *);

void show_list(struct _list *);

void show_play(struct _play *);

int in_wanted(int *);

int *make_data(int, int);

struct _list *make_list(int *, int *, int *);

struct _play *make_play(int);

void make_wanted(int *);

int *get_good_move(struct _list *);

int *get_winning_move(struct _play *);

struct _list *where(int *, struct _play *);

void get_real_move(int *, int *, int *, int *);

int main(void);

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68217[17] = "player %d loses\012";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68211[3] = "%d";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68212[3] = ")\012";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68214[14] = "  value = %d\012";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68213[13] = "For state :\012";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68216[28] = "player %d plays at (%d,%d)\012";

static /*signed*/ char const __stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68215[20] = "We get, in order :\012";

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

extern int putchar(int);

extern void *malloc(unsigned int);

extern void free(void *);

struct _list *wanted;

struct _play *game_tree;

int nrow;

int ncol;

int *copy_data(int *data)
{
  int *new;
  int counter;
  register int $370;
  register void *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:26"();
  $369 = malloc(ncol * sizeof(int));
  new = (int *) $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:27"();
  counter = ncol;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:28"();
  while (1) {
    $370 = counter;
    counter = $370 - 1;
    if (! $370) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:29"();
    *(new + counter) = *(data + counter);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:30"();
  return new;
}

int next_data(int *data)
{
  int counter;
  int valid;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:36"();
  counter = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:37"();
  valid = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:38"();
  while (1) {
    if (counter != ncol) {
      $369 = (_Bool) !valid;
    } else {
      $369 = 0;
    }
    if (! $369) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:40"();
    if (*(data + counter) == nrow) {
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:42"();
      *(data + counter) = 0;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:43"();
      counter = counter + 1;
    } else {
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:47"();
      *(data + counter) = *(data + counter) + 1;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:48"();
      valid = 1;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:51"();
  return valid;
}

void melt_data(int *data1, int *data2)
{
  int counter;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:56"();
  counter = ncol;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:57"();
  while (1) {
    $369 = counter;
    counter = $369 - 1;
    if (! $369) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:59"();
    if (*(data1 + counter) > *(data2 + counter)) {
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:60"();
      *(data1 + counter) = *(data2 + counter);
    }
  }
}

int equal_data(int *data1, int *data2)
{
  int counter;
  register int $370;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:66"();
  counter = ncol;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:67"();
  while (1) {
    $369 = counter;
    counter = $369 - 1;
    if ($369) {
      $370 = (_Bool) (*(data1 + counter) == *(data2 + counter));
    } else {
      $370 = 0;
    }
    if (! $370) {
      break;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:68"();
  return counter < 0;
}

int valid_data(int *data)
{
  int low;
  int counter;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:73"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:74"();
  counter = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:75"();
  low = nrow;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:76"();
  while (1) {
    if (! (counter != ncol)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:78"();
    if (*(data + counter) > low) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:79"();
    low = *(data + counter);
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:80"();
    counter = counter + 1;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:82"();
  return counter == ncol;
}

void dump_list(struct _list *list)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:87"();
  if (list != (void *) 0) {
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:89"();
    dump_list((*list).next);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:90"();
    free((*list).data);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:91"();
    free(list);
  }
}

void dump_play(struct _play *play)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:97"();
  if (play != (void *) 0) {
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:99"();
    dump_play((*play).next);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:100"();
    dump_list((*play).first);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:101"();
    free((*play).state);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:102"();
    free(play);
  }
}

int get_value(int *data)
{
  struct _play *search;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:108"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:109"();
  search = game_tree;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:110"();
  while (1) {
    $369 = equal_data((*search).state, data);
    if (! !$369) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:111"();
    search = (*search).next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:112"();
  return (*search).value;
}

void show_data(int *data)
{
  int counter;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:117"();
  counter = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:118"();
  while (1) {
    if (! (counter != ncol)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:120"();
    $369 = counter;
    counter = $369 + 1;
    printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68211, *(data + $369));
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:121"();
    if (counter != ncol) {
      builtin debug6 ""(1);
      putchar(44);
    }
  }
}

void show_move(int *data)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:127"();
  putchar(40);
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:128"();
  show_data(data);
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:129"();
  printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68212);
}

void show_list(struct _list *list)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:134"();
  while (1) {
    if (! (list != (void *) 0)) {
      break;
    }
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:136"();
    show_move((*list).data);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:137"();
    list = (*list).next;
  }
}

void show_play(struct _play *play)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:143"();
  while (1) {
    if (! (play != (void *) 0)) {
      break;
    }
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:145"();
    printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68213);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:146"();
    show_data((*play).state);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:147"();
    printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68214, (*play).value);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:148"();
    printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68215);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:149"();
    show_list((*play).first);
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:150"();
    play = (*play).next;
  }
}

int in_wanted(int *data)
{
  struct _list *current;
  register int $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:156"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:157"();
  current = wanted;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:158"();
  while (1) {
    if (! (current != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:160"();
    $369 = equal_data((*current).data, data);
    if ($369) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:161"();
    current = (*current).next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:163"();
  if (current == (void *) 0) {
    builtin debug6 ""(1);
    return 0;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:164"();
  return 1;
}

int *make_data(int row, int col)
{
  int count;
  int *new;
  register void *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:170"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:171"();
  $369 = malloc(ncol * sizeof(int));
  new = (int *) $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:172"();
  builtin debug6 ""(1);
  count = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       count = count + 1) {
    if (! (count != col)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:173"();
    *(new + count) = nrow;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:174"();
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       count = count + 1) {
    if (! (count != ncol)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:175"();
    *(new + count) = row;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:176"();
  return new;
}

struct _list *make_list(int *data, int *value, int *all)
{
  int row;
  int col;
  int *temp;
  struct _list *head;
  struct _list *current;
  register int $376;
  register int $375;
  register int $374;
  register int $373;
  register int *$372;
  register void *$371;
  register int *$370;
  register void *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:182"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:183"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:184"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:185"();
  *value = 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:186"();
  $369 = malloc(sizeof(struct _list));
  head = (struct _list *) $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:187"();
  (*head).next = (void *) 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:188"();
  current = head;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:189"();
  builtin debug6 ""(1);
  row = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       row = row + 1) {
    if (! (row != nrow)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:191"();
    builtin debug6 ""(1);
    col = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         col = col + 1) {
      if (! (col != ncol)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:193"();
      $370 = make_data(row, col);
      temp = $370;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:194"();
      melt_data(temp, data);
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:195"();
      $376 = equal_data(temp, data);
      if (!$376) {
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:197"();
        $371 = malloc(sizeof(struct _list));
        (*current).next = (struct _list *) $371;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:198"();
        $372 = copy_data(temp);
        (*(*current).next).data = $372;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:199"();
        (*(*current).next).next = (void *) 0;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:200"();
        current = (*current).next;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:201"();
        if (*value == 1) {
          builtin debug6 ""(1);
          builtin debug1 "#line:chomp.c:202"();
          $373 = get_value(temp);
          *value = $373;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:203"();
        if (!*all) {
          $375 = (_Bool) (*value == 0);
        } else {
          $375 = 0;
        }
        if ($375) {
          builtin debug6 ""(1);
          builtin debug1 "#line:chomp.c:205"();
          col = ncol - 1;
          builtin debug6 ""(1);
          builtin debug1 "#line:chomp.c:206"();
          row = nrow - 1;
          builtin debug6 ""(1);
          builtin debug1 "#line:chomp.c:207"();
          $374 = in_wanted(temp);
          if ($374) {
            builtin debug6 ""(1);
            builtin debug1 "#line:chomp.c:208"();
            *all = 2;
          }
        }
      } else {
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:213"();
        if (col == 0) {
          builtin debug6 ""(1);
          row = nrow - 1;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:214"();
        col = ncol - 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:216"();
      free(temp);
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:219"();
  current = (*head).next;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:220"();
  free(head);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:221"();
  if (current != (void *) 0) {
    builtin debug6 ""(1);
    *value = 1 - *value;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:222"();
  return current;
}

struct _play *make_play(int all)
{
  int val;
  int *temp;
  struct _play *head;
  struct _play *current;
  register int $376;
  register int *$375;
  register struct _list *$374;
  register int *$373;
  register void *$372;
  register int $371;
  register int *$370;
  register void *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:227"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:228"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:229"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:230"();
  $369 = malloc(sizeof(struct _play));
  head = (struct _play *) $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:231"();
  current = head;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:232"();
  game_tree = (void *) 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:233"();
  $370 = make_data(0, 0);
  temp = $370;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:234"();
  *(temp + 0) = *(temp + 0) - 1;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:235"();
  while (1) {
    $371 = next_data(temp);
    if (! $371) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:237"();
    $376 = valid_data(temp);
    if ($376) {
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:239"();
      $372 = malloc(sizeof(struct _play));
      (*current).next = (struct _play *) $372;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:240"();
      if (game_tree == (void *) 0) {
        builtin debug6 ""(1);
        game_tree = (*current).next;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:242"();
      $373 = copy_data(temp);
      (*(*current).next).state = $373;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:243"();
      $374 = make_list(temp, &val, &all);
      (*(*current).next).first = $374;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:245"();
      (*(*current).next).value = val;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:246"();
      (*(*current).next).next = (void *) 0;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:247"();
      current = (*current).next;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:248"();
      if (all == 2) {
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:250"();
        free(temp);
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:251"();
        $375 = make_data(nrow, ncol);
        temp = $375;
      }
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:255"();
  current = (*head).next;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:256"();
  free(head);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:257"();
  return current;
}

void make_wanted(int *data)
{
  int row;
  int col;
  int *temp;
  struct _list *head;
  struct _list *current;
  register int $373;
  register int *$372;
  register void *$371;
  register int *$370;
  register void *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:267"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:268"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:269"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:270"();
  $369 = malloc(sizeof(struct _list));
  head = (struct _list *) $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:271"();
  (*head).next = (void *) 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:272"();
  current = head;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:273"();
  builtin debug6 ""(1);
  row = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       row = row + 1) {
    if (! (row != nrow)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:275"();
    builtin debug6 ""(1);
    col = 0;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
         col = col + 1) {
      if (! (col != ncol)) {
        break;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:277"();
      $370 = make_data(row, col);
      temp = $370;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:278"();
      melt_data(temp, data);
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:279"();
      $373 = equal_data(temp, data);
      if (!$373) {
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:281"();
        $371 = malloc(sizeof(struct _list));
        (*current).next = (struct _list *) $371;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:282"();
        $372 = copy_data(temp);
        (*(*current).next).data = $372;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:283"();
        (*(*current).next).next = (void *) 0;
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:284"();
        current = (*current).next;
      } else {
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:288"();
        if (col == 0) {
          builtin debug6 ""(1);
          row = nrow - 1;
        }
        builtin debug6 ""(1);
        builtin debug1 "#line:chomp.c:289"();
        col = ncol - 1;
      }
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:291"();
      free(temp);
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:294"();
  current = (*head).next;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:295"();
  free(head);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:296"();
  wanted = current;
}

int *get_good_move(struct _list *list)
{
  register int *$371;
  register int $370;
  register int $369;
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:301"();
  if (list == (void *) 0) {
    builtin debug6 ""();
    return (void *) 0;
  }
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:304"();
  while (1) {
    if ((*list).next != (void *) 0) {
      $370 = get_value((*list).data);
      $369 = (_Bool) $370;
    } else {
      $369 = 0;
    }
    if (! $369) {
      break;
    }
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:305"();
    list = (*list).next;
  }
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:306"();
  $371 = copy_data((*list).data);
  return $371;
}

int *get_winning_move(struct _play *play)
{
  int *temp;
  register int *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:312"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:313"();
  while (1) {
    if (! ((*play).next != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    play = (*play).next;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:314"();
  $369 = get_good_move((*play).first);
  temp = $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:315"();
  return temp;
}

struct _list *where(int *data, struct _play *play)
{
  register int $369;
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:320"();
  while (1) {
    $369 = equal_data((*play).state, data);
    if (! !$369) {
      break;
    }
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:321"();
    play = (*play).next;
  }
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:322"();
  return (*play).first;
}

void get_real_move(int *data1, int *data2, int *row, int *col)
{
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:328"();
  *col = 0;
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:329"();
  while (1) {
    if (! (*(data1 + *col) == *(data2 + *col))) {
      break;
    }
    builtin debug6 ""();
    builtin debug1 "#line:chomp.c:330"();
    *col = *col + 1;
  }
  builtin debug6 ""();
  builtin debug1 "#line:chomp.c:331"();
  *row = *(data1 + *col);
}

int main(void)
{
  int row;
  int col;
  int player;
  int *current;
  int *temp;
  struct _play *tree;
  register int *$372;
  register struct _list *$371;
  register int *$370;
  register struct _play *$369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:336"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:337"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:338"();
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:341"();
  ncol = 7;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:345"();
  nrow = 8;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:347"();
  $369 = make_play(1);
  tree = $369;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:348"();
  player = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:349"();
  $370 = make_data(nrow, ncol);
  current = $370;
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:350"();
  while (1) {
    if (! (current != (void *) 0)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:352"();
    $371 = where(current, tree);
    $372 = get_good_move($371);
    temp = $372;
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:353"();
    if (temp != (void *) 0) {
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:355"();
      get_real_move(temp, current, &row, &col);
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:357"();
      printf
        (__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68216, player, row, col);
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:358"();
      player = 1 - player;
      builtin debug6 ""(1);
      builtin debug1 "#line:chomp.c:359"();
      free(current);
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:chomp.c:361"();
    current = temp;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:363"();
  dump_play(tree);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:364"();
  printf(__stringlit_d5f18a69ab6ffbdb1296a6e8bf0c68217, 1 - player);
  builtin debug6 ""(1);
  builtin debug1 "#line:chomp.c:365"();
  return 0;
  builtin debug6 ""();
  return 0;
}


