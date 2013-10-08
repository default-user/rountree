#include "mylib.h"
#include "mysorts.h"

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

static void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void insertion_sort(int *a, int n) {
   int i
   int j
   int key;
   
   /* for each position p in array a except the first */
   for (i = 1; i < n; i++) {
   
      /* pull out the item at p and store it in variable 'key' */
      key = a[i];
      
      /* move each item that is to the left of position p,
         and is greater than key, one place to the right */
      j = i - 1;
      while (j >= 0 && a[j] > key) {
         a[j + 1] = a[j];
         j--;
      }
      
      /* put key in the leftmost position */
      a[j + 1] = key;
   }
}

void merge_sort(int *a, int n) {
   void *workspace = emalloc(sizeof a[0] * n);
   
   sort(a, workspace, n);
   
   free(workspace);
}

void quick_sort(int *a, int n) {
   int pivot;
   int i;
   int j;
   
   /* if there are less than two items in the array then stop */
   if (n < 2) return;
   
   /* let pivot hold a copy of the array’s first element */
   pivot = a[0];
   
   /* let i be an index one to the left of the array’s left-most position */
   i = -1;
   
   /* let j be an index one to the right of the array’s right-most position */
   j = n;
   
   /* loop forever { */
   for (;;) {
   
      /*  increment i (at least once) while the value at position i < pivot */
      do {
         i++;
      } while (a[i] < pivot); 
      
      /*  decrement j (at least once) while the value at position j > pivot */
      do {
         j--;
      } while (a[j] > pivot);
      
      /*  if i is to the left of j, then swap the values at their positions */
      if (i < j) {
         swap(&a[i], &a[j]);
         
         /*  else break out of the loop */
      } else {
         break;
      }
   }
   
   /* quicksort the left sub-array */
   quick_sort(a, j + 1);
   
   /* quicksort the right sub-array */
   quick_sort(a + j + 1, n - j - 1);
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

