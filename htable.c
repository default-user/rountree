#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
   int capacity;
   int num_keys;
   char **keys;
};

static unsigned int htable_word_to_int(char *word) {
   unsigned int result = 0;
   while (*word != '\0') {
      result = (*word++ + 31 * result);
   }
   return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
   return i_key % h->capacity;
}

htable htable_new(int capacity) {
   int i;
   htable h = emalloc(sizeof *h);
   h->keys = emalloc(capacity * sizeof h->keys[0]);
   h->capacity = capacity;
   h->num_keys = 0;
   for (i = 0; i < h->capacity; i++) {
      h->keys[i] = NULL;
   }
   return h;
}
void htable_free(htable h) {
   int i;
   for (i = 0; i < h->capacity; i++) {
      free(h->keys[i]);
   }
   free(h->keys);
   free(h);
}
int htable_insert(htable h, char *key) {
   int collisions;
   int position = htable_word_to_int(key) % h->capacity;

   if (NULL == h->keys[position]) {
      h->keys[position] = emalloc(strlen(key) + 1);
      strcpy(h->keys[position], key);
      h->num_keys++;
      return 1;
   }

   while (NULL != h->keys[position] && strcmp(key, h->keys[position]) != 0) {
      position = (position + 1) % h->capacity;

      if (NULL == h->keys[position]) {
         h->keys[position] = emalloc(strlen(key) + 1);
         strcpy(h->keys[position], key);
         h->num_keys++;
         return 1;
      }

      if (++collisions > h->capacity) return 0;
   }
   return 0;
}
void htable_print(htable h, FILE *stream) {
   int i;
   for (i = 0; i < h->capacity; i++) {
      fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
   }
}
