#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>

typedef struct htable_record *htable;

extern htable htable_new(int);

extern int htable_insert(htable, char *);

extern void htable_free(htable);

extern void htable_print(htable, FILE *);

#endif
