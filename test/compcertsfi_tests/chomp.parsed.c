extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

typedef unsigned int size_t;

extern int printf(char const * __format, ...);

extern int putchar(int __c);

extern void * malloc(size_t __size);

extern void free(void * __ptr);

struct _list;

struct _list {
  int * data;
  struct _list * next;
};

struct _list * wanted;

struct _play;

struct _play {
  int value;
  int * state;
  struct _list * first;
  struct _play * next;
};

struct _play * game_tree;

int nrow;

int ncol;

int * copy_data(int * data)
{
  int * new;
  int counter;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:26");
  new = (int *) malloc(ncol * sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:27");
  counter = ncol;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:28");
  while (counter--) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:29");
    new[counter] = data[counter];
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:30");
  return new;
}

int next_data(int * data)
{
  int counter;
  int valid;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:36");
  counter = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:37");
  valid = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:38");
  while (counter != ncol && !valid) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:40");
    if (data[counter] == nrow) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:42");
      data[counter] = 0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:43");
      counter++;
    } else {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:47");
      data[counter]++;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:48");
      valid = 1;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:51");
  return valid;
}

void melt_data(int * data1, int * data2)
{
  int counter;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:56");
  counter = ncol;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:57");
  while (counter--) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:59");
    if (data1[counter] > data2[counter]) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:60");
      data1[counter] = data2[counter];
    }
  }
}

int equal_data(int * data1, int * data2)
{
  int counter;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:66");
  counter = ncol;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:67");
  while (counter-- && data1[counter] == data2[counter]) {
    /*skip*/;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:68");
  return counter < 0;
}

int valid_data(int * data)
{
  int low;
  int counter;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:73");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:74");
  counter = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:75");
  low = nrow;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:76");
  while (counter != ncol) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:78");
    if (data[counter] > low) {
      break;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:79");
    low = data[counter];
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:80");
    counter++;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:82");
  return counter == ncol;
}

void dump_list(struct _list * list)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:87");
  if (list != (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:89");
    dump_list(list->next);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:90");
    free(list->data);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:91");
    free(list);
  }
}

void dump_play(struct _play * play)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:97");
  if (play != (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:99");
    dump_play(play->next);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:100");
    dump_list(play->first);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:101");
    free(play->state);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:102");
    free(play);
  }
}

int get_value(int * data)
{
  struct _play * search;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:108");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:109");
  search = game_tree;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:110");
  while (!equal_data(search->state, data)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:111");
    search = search->next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:112");
  return search->value;
}

void show_data(int * data)
{
  int counter;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:117");
  counter = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:118");
  while (counter != ncol) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:120");
    printf("%d", data[counter++]);
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:121");
    if (counter != ncol) {
      __builtin_debug(6, "", 1);
      putchar(44);
    }
  }
}

void show_move(int * data)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:127");
  putchar(40);
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:128");
  show_data(data);
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:129");
  printf(")\n");
}

void show_list(struct _list * list)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:134");
  while (list != (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:136");
    show_move(list->data);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:137");
    list = list->next;
  }
}

void show_play(struct _play * play)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:143");
  while (play != (void *) 0) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:145");
    printf("For state :\n");
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:146");
    show_data(play->state);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:147");
    printf("  value = %d\n", play->value);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:148");
    printf("We get, in order :\n");
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:149");
    show_list(play->first);
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:150");
    play = play->next;
  }
}

int in_wanted(int * data)
{
  struct _list * current;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:156");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:157");
  current = wanted;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:158");
  while (current != (void *) 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:160");
    if (equal_data(current->data, data)) {
      break;
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:161");
    current = current->next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:163");
  if (current == (void *) 0) {
    __builtin_debug(6, "", 1);
    return 0;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:164");
  return 1;
}

int * make_data(int row, int col)
{
  int count;
  int * new;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:170");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:171");
  new = (int *) malloc(ncol * sizeof(int));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:172");
  for (__builtin_debug(6, "", 1), count = 0;
       count != col;
       __builtin_debug(6, "", 1), count++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:173");
    new[count] = nrow;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:174");
  for (/*nothing*/; count != ncol; __builtin_debug(6, "", 1), count++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:175");
    new[count] = row;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:176");
  return new;
}

struct _list * make_list(int * data, int * value, int * all)
{
  int row;
  int col;
  int * temp;
  struct _list * head;
  struct _list * current;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:182");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:183");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:184");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:185");
  *value = 1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:186");
  head = (struct _list *) malloc(sizeof(struct _list));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:187");
  head->next = (void *) 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:188");
  current = head;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:189");
  for (__builtin_debug(6, "", 1), row = 0;
       row != nrow;
       __builtin_debug(6, "", 1), row++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:191");
    for (__builtin_debug(6, "", 1), col = 0;
         col != ncol;
         __builtin_debug(6, "", 1), col++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:193");
      temp = make_data(row, col);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:194");
      melt_data(temp, data);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:195");
      if (!equal_data(temp, data)) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:197");
        current->next = (struct _list *) malloc(sizeof(struct _list));
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:198");
        current->next->data = copy_data(temp);
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:199");
        current->next->next = (void *) 0;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:200");
        current = current->next;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:201");
        if (*value == 1) {
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:chomp.c:202");
          *value = get_value(temp);
        }
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:203");
        if (!*all && *value == 0) {
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:chomp.c:205");
          col = ncol - 1;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:chomp.c:206");
          row = nrow - 1;
          __builtin_debug(6, "", 1);
          __builtin_debug(1, "#line:chomp.c:207");
          if (in_wanted(temp)) {
            __builtin_debug(6, "", 1);
            __builtin_debug(1, "#line:chomp.c:208");
            *all = 2;
          }
        }
      } else {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:213");
        if (col == 0) {
          __builtin_debug(6, "", 1);
          row = nrow - 1;
        }
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:214");
        col = ncol - 1;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:216");
      free(temp);
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:219");
  current = head->next;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:220");
  free(head);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:221");
  if (current != (void *) 0) {
    __builtin_debug(6, "", 1);
    *value = 1 - *value;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:222");
  return current;
}

struct _play * make_play(int all)
{
  int val;
  int * temp;
  struct _play * head;
  struct _play * current;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:227");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:228");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:229");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:230");
  head = (struct _play *) malloc(sizeof(struct _play));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:231");
  current = head;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:232");
  game_tree = (void *) 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:233");
  temp = make_data(0, 0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:234");
  temp[0]--;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:235");
  while (next_data(temp)) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:237");
    if (valid_data(temp)) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:239");
      current->next = (struct _play *) malloc(sizeof(struct _play));
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:240");
      if (game_tree == (void *) 0) {
        __builtin_debug(6, "", 1);
        game_tree = current->next;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:242");
      current->next->state = copy_data(temp);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:243");
      current->next->first = make_list(temp, &val, &all);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:245");
      current->next->value = val;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:246");
      current->next->next = (void *) 0;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:247");
      current = current->next;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:248");
      if (all == 2) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:250");
        free(temp);
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:251");
        temp = make_data(nrow, ncol);
      }
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:255");
  current = head->next;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:256");
  free(head);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:257");
  return current;
}

void make_wanted(int * data)
{
  int row;
  int col;
  int * temp;
  struct _list * head;
  struct _list * current;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:267");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:268");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:269");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:270");
  head = (struct _list *) malloc(sizeof(struct _list));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:271");
  head->next = (void *) 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:272");
  current = head;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:273");
  for (__builtin_debug(6, "", 1), row = 0;
       row != nrow;
       __builtin_debug(6, "", 1), row++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:275");
    for (__builtin_debug(6, "", 1), col = 0;
         col != ncol;
         __builtin_debug(6, "", 1), col++) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:277");
      temp = make_data(row, col);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:278");
      melt_data(temp, data);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:279");
      if (!equal_data(temp, data)) {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:281");
        current->next = (struct _list *) malloc(sizeof(struct _list));
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:282");
        current->next->data = copy_data(temp);
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:283");
        current->next->next = (void *) 0;
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:284");
        current = current->next;
      } else {
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:288");
        if (col == 0) {
          __builtin_debug(6, "", 1);
          row = nrow - 1;
        }
        __builtin_debug(6, "", 1);
        __builtin_debug(1, "#line:chomp.c:289");
        col = ncol - 1;
      }
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:291");
      free(temp);
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:294");
  current = head->next;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:295");
  free(head);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:296");
  wanted = current;
}

int * get_good_move(struct _list * list)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:301");
  if (list == (void *) 0) {
    __builtin_debug(6, "");
    return (void *) 0;
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:304");
  while (list->next != (void *) 0 && get_value(list->data)) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:305");
    list = list->next;
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:306");
  return copy_data(list->data);
}

int * get_winning_move(struct _play * play)
{
  int * temp;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:312");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:313");
  while (play->next != (void *) 0) {
    __builtin_debug(6, "", 1);
    play = play->next;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:314");
  temp = get_good_move(play->first);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:315");
  return temp;
}

struct _list * where(int * data, struct _play * play)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:320");
  while (!equal_data(play->state, data)) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:321");
    play = play->next;
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:322");
  return play->first;
}

void get_real_move(int * data1, int * data2, int * row, int * col)
{
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:328");
  *col = 0;
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:329");
  while (data1[*col] == data2[*col]) {
    __builtin_debug(6, "");
    __builtin_debug(1, "#line:chomp.c:330");
    (*col)++;
  }
  __builtin_debug(6, "");
  __builtin_debug(1, "#line:chomp.c:331");
  *row = data1[*col];
}

int main(void)
{
  int row;
  int col;
  int player;
  int * current;
  int * temp;
  struct _play * tree;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:336");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:337");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:338");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:341");
  ncol = 7;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:345");
  nrow = 8;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:347");
  tree = make_play(1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:348");
  player = 0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:349");
  current = make_data(nrow, ncol);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:350");
  while (current != (void *) 0) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:352");
    temp = get_good_move(where(current, tree));
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:353");
    if (temp != (void *) 0) {
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:355");
      get_real_move(temp, current, &row, &col);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:357");
      printf("player %d plays at (%d,%d)\n", player, row, col);
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:358");
      player = 1 - player;
      __builtin_debug(6, "", 1);
      __builtin_debug(1, "#line:chomp.c:359");
      free(current);
    }
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:chomp.c:361");
    current = temp;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:363");
  dump_play(tree);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:364");
  printf("player %d loses\n", 1 - player);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:chomp.c:365");
  return 0;
  __builtin_debug(6, "");
  return 0;
}


