#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include <assert.h>
#include <ctype.h>

#include "mylib.h"

void *emalloc(size_t memory_requirement) {
   void *memory_allocation = malloc(memory_requirement);
   if (NULL == memory_allocation) {
      fprintf(stderr, "!!! MEMORY ALLOCATION FAILURE !!!");
      exit(EXIT_FAILURE);
   }
   return memory_allocation;
}

void *erealloc(void *memory_allocation, size_t memory_requirement) {
   void *memory_reallocation = realloc(memory_allocation, memory_requirement);
   if (NULL == memory_reallocation) {
      fprintf(stderr, "!!! MEMORY REALLOCATION FAILURE !!!");
      exit(EXIT_FAILURE);
   }
   return memory_reallocation;
}

int getword(char *s, int limit, FILE *stream) {
   int c;
   char *w = s;
   assert(limit > 0 && s != NULL && stream != NULL);
   /* skip to the start of the word */
   while (!isalnum(c = getc(stream)) && EOF != c)
      ;
   if (EOF == c) {
      return EOF;
   } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
      *w++ = tolower(c);
   }
   while (--limit > 0) {
      if (isalnum(c = getc(stream))) {
         *w++ = tolower(c);
      } else if ('\'' == c) {
         limit++;
      } else {
         break;
      }
   }
   *w = '\0';
   return w - s;
}
