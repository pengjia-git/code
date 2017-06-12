#ifndef __HLIST_H__
#define __HLIST_H__
#include <linux/list.h>

struct search{
  char * searched_file;
  int file_len;
  char  * pos;
  struct hlist_head head[256];
};

struct search_node{
  struct hlist_node node;
  char *str;
};

char * split(int *strlen);
int get_hash_of_string(const char *p);
#endif
