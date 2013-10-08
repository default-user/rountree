#include "selection_sort.h"

static void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void selection_sort(int *a, int n) {
   int i; 
   int j;
   int sml_pos;
   
   /* for each position i in the array a except the last one */
   for (i = 0; i < n - 1; i++) {
   
      /* find the smallest item from position i to position (n - 1) */
      sml_pos = i;
      for (j = i + 1; j < n; j++) {
	     if (a[j] < a[sml_pos]) sml_pos = j;
      }
   
      /* swap the item you find with whatever is a position i right now */ 
      swap(&a[i], &a[sml_pos]);
   }
}
