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

int getword(char *string, int limit, FILE *stream) {
   int character;
   char *word = string;
   assert(limit > 0 && NULL != string && NULL != stream);
   
   /* skip to the start of the word */
   while (!isalnum(character = getc(stream)) && EOF != character)
      ;
   if (EOF == character) {
      return EOF;
      
   /* reduce limit by 1 to allow for the \0 */
   } else if (--limit > 0) { 
      *word++ = tolower(character);
   }
   
   while (--limit > 0) {
      if (isalnum(character = getc(stream))) {
         *word++ = tolower(character);
      } else if ('\'' == character) {
         limit++;
      } else {
         break;
      }
   }
   
   *word = '\0';
   return word - string;
}
