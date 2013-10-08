#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarray_record {
   int capacity;
   int item_count;
   int *items;
};

static void merge(int *array, int *workspace, int length) {

   /* initialise indices to point to the beginning of */
   /* the left and right halves of array */
   int i = 0;
   int j = length / 2;
   int w = 0;
   
   /* while there are elements in both halves of array { */
   while (i < (length / 2) && j < length) {
   
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
   while (i < (length / 2)) {
      workspace[w++] = array[i++];
   }
   
   /* add any remaining elements from right half of array to workspace */
   while (j < length) {
      workspace[w++] = array[j++];
   }
}

static void merge_sort(int *a, int *ws, int n) {
   int i;
   
   /* take care of stopping condition first */
   /* if the array to be sorted has fewer than two elements then return */
   if (n < 2) return;
   
   /* call merge_sort on the first half of array a */
   merge_sort(a, ws, n / 2);
   
   /* call merge_sort on the second half of array a */
   merge_sort(a + (n / 2), ws, n - (n / 2));
   
   /* merge the two halves of array a into array w */
   merge(a, w, n);
   
   /* copy array w back into array a */
   for (i = 0; i < n; i++) { 
      a[i] = ws[i];
   }
}

flexarray flexarray_new() {
   flexarray f = emalloc(sizeof *f);
   f->capacity = 2;
   f->item_count = 0;
   f->items = emalloc(sizeof f->items[0] * f->capacity);
   return f;
}

void flexarray_append(flexarray f, int item) {

   if (f->item_count == f->capacity) {
   
      /* do the old "double the capacity" trick */
      f->capacity += f->capacity;
      f->items = erealloc(f->items, sizeof f->items[0] * f->capacity);
   }
   
   /* insert the item in the last free space */
   f->items[f->item_count++] = item;
   
}

void flexarray_print(flexarray f) {
   int i;
   
   /* a "for" loop to print out each cell of f->items */
   for (i = 0; i < f->item_count; i++) {
      printf("%d\n", f->items[i]);
   }
   fprintf(stderr, "%d Items\n", f->item_count);
}

void flexarray_sort(flexarray f) {

   /* mergesort would be good */
   void *workspace = emalloc(sizeof f->items[0] * f->item_count);
   merge_sort(f->items, workspace, f->item_count);
   free(workspace);
}

void flexarray_free(flexarray f) {

   /* free the memory associated with the flexarray */
   free(f->items);
   free(f);
}
