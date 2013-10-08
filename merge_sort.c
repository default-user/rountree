#include <stdlib.h>
#include "merge_sort.h"

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

static void sort(int *a, int *ws, int n) {
   int i;
   
   /* take care of stopping condition first */
   /* if the array to be sorted has fewer than two elements then return */
   if (n < 2) return;
   
   /* call merge_sort on the first half of array a */
   sort(a, ws, n / 2);
   
   /* call sort on the second half of array a */
   sort(a + (n / 2), ws, n - (n / 2));
   
   /* merge the two halves of array a into array w */
   merge(a, w, n);
   
   /* copy array w back into array a */
   for (i = 0; i < n; i++) { 
      a[i] = ws[i];
   }
}

void merge_sort(int *a, int n) {
   void *workspace = malloc(sizeof f->items[0] * n);
   sort(a, workspace, n);
   free(workspace);
}
