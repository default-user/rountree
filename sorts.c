#include "mylib.h"
#include "sorts.h"

static void merge(int *array, int *workspace, int length) {

   /* initialise indices to point to the beginning of */
   /* the left and right halves of array */
   int i = 0;
   int left_i = 0;
   int right_i = length / 2;
   
   /* while there are elements in both halves of array { */
   while (left_i < (length / 2) && right_i < length) {
   
      /* compare the elements at the current left and right indices */
      if (array[left_i] < array[right_i]) {   
      
         /* put the smallest into workspace and increment both the index */
         /* it was taken from, and the index in workspace */
         workspace[i++] = array[left_i++];
      } else {
         workspace[i++] = array[right_i++];
      }
   }
   
   /* add any remaining elements from left half of array to workspace */
   while (left_i < (length / 2)) {
      workspace[i++] = array[left_i++];
   }
   
   /* add any remaining elements from right half of array to workspace */
   while (j < length) {
      workspace[i++] = array[right_i++];
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
   int greater;
   int key;
   int position;
   
   /* for each position in array a except the first */
   for (position = 1; position < n; position++) {
   
      /* pull out the item at pos and store it in variable 'key' */
      key = a[position];
      
      /* move each item that is to the left of position pos,
         and is greater than key, one place to the right */
      greater = position - 1;
      while (greater >= 0 && a[greater] > key) {
         a[greater + 1] = a[greater];
         greater--;
      }
      
      /* put key in the leftmost position */
      a[greater + 1] = key;
   }
}

void merge_sort(int *a, int n) {
   void *workspace = emalloc(sizeof a[0] * n);
   
   sort(a, workspace, n);
   
   free(workspace);
}

void quick_sort(int *a, int n) {
   int left;
   int pivot;
   int right;
   
   /* if there are less than two items in the array then stop */
   if (n < 2) return;
   
   /* let pivot hold a copy of the array’s first element */
   pivot = a[0];
   
   /* let left_i be an index one to the left of the array’s left-most position */
   left_i = -1;
   
   /* let right_i be an index one to the right of the array’s right-most position */
   right_i = n;
   
   /* loop forever { */
   for (;;) {
   
      /*  increment i (at least once) while the value at position i < pivot */
      do {
         left_i++;
      } while (a[left_i] < pivot); 
      
      /*  decrement j (at least once) while the value at position j > pivot */
      do {
         right_i--;
      } while (a[right_i] > pivot);
      
      /*  if i is to the left of j, then swap the values at their positions */
      if (left_i < right_i) {
         swap(&a[left_i], &a[right_i]);
         
         /*  else break out of the loop */
      } else {
         break;
      }
   }
   
   /* quicksort the left sub-array */
   quick_sort(a, right_i + 1);
   
   /* quicksort the right sub-array */
   quick_sort(a + right_i + 1, n - right_i - 1);
}

void selection_sort(int *a, int n) {
   int inner_i;
   int outer_i; 
   int sml_pos;
   
   /* for each position outer_i in the array a except the last one */
   for (outer_i = 0; outer_i < n - 1; outer_i++) {
   
      /* find the smallest item from position outer_i to position (n - 1) */
      sml_pos = i;
      for (inner_i = outer_i + 1; inner_i < n; inner_i++) {
	     if (a[j] < a[sml_pos]) sml_pos = inner_i;
      }
   
      /* swap the item you find with whatever is a position outer_i right now */ 
      swap(&a[outer_i], &a[sml_pos]);
   }
}

