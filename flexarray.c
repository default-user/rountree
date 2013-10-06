#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarray_record {
   int capacity;
   int itemcount;
   int *items;
};

static void merge(int *array, int *workspace, int len) {

   /* initialise indices to point to the beginning of */
   /* the left and right halves of array */
   int i = 0;
   int j = (len / 2);
   int w = 0;
   
   /* while there are elements in both halves of array { */
   while (i < (len / 2) && j < len) {
   
      /* compare the elements at the current left and right indices */
      if (array[i] < array[j]) {   
      
         /* put the smallest into workspace and increment both the index */
         /* it was taken from, and the index in workspace */
         workspace[w++] = array[i++];
      } else {
         workspace[w++] = array[j++];
      }
   }
   
   /* add any remaining elements from left half of array to workspace */
   while (i < (len / 2)) {
      workspace[w++] = array[i++];
   }
   
   /* add any remaining elements from right half of array to workspace */
   while (j < len) {
      workspace[w++] = array[j++];
   }
}

static void merge_sort(int *a, int *w, int n) {
   int i;
   
   /* take care of stopping condition first */
   /* if the array to be sorted has fewer than two elements then return */
   if (n < 2) return;
   
   /* call merge_sort on the first half of array a */
   merge_sort(a, w, n / 2);
   
   /* call merge_sort on the second half of array a */
   merge_sort((a + (n / 2)), w, (n - (n / 2)));
   
   /* merge the two halves of array a into array w */
   merge(a, w, n);
   
   /* copy array w back into array a */
   for (i = 0; i < n; i++) { 
      a[i] = w[i];
   }
}

flexarray flexarray_new() {
   flexarray result = emalloc(sizeof *result);
   result->capacity = 2;
   result->itemcount = 0;
   result->items = emalloc(result->capacity * sizeof result->items[0]);
   return result;
}

void flexarray_append(flexarray f, int num) {

   if (f->itemcount == f->capacity) {
   
      /* do the old "double the capacity" trick */
      f->capacity += f->capacity;
      f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
   }
   
   /* insert the item in the last free space */
   f->items[f->itemcount++] = num;
   
}

void flexarray_print(flexarray f) {
   int i;
   
   /* a "for" loop to print out each cell of f->items */
   for (i = 0; i < f->itemcount; i++) {
      printf("%d\n", f->items[i]);
   }
   fprintf(stderr, "%d Items\n", f->itemcount);
}

void flexarray_sort(flexarray f) {

   /* mergesort would be good */
   void *workspace = emalloc(f->itemcount * sizeof f->items[0]);
   merge_sort(f->items, workspace, f->itemcount);
   free(workspace);
}

void flexarray_free(flexarray f) {

   /* free the memory associated with the flexarray */
   free(f->items);
   free(f);
}
