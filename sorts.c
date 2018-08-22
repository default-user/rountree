/**
   sorts.c
   @author TURNER. Ande,
   @comments ROUNTREE et al.
   Implements a Selection of Sorting Algorithms.
**/   

#include "mylib.h"
#include "sorts.h"

static void mergesort_merge(int *array, int *workspace, int length) {
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
   while (right_i < length) {
      workspace[i++] = array[right_i++];
   }
}

static void mergesort_sort(int *array, int *workspace, int elements) {
   int i;
   /* take care of stopping condition first */
   /* if the array to be sorted has fewer than two elements then return */
   if (elements < 2) return;
   /* call merge_sort on the first half of the main array */
   mergesort_sort(array, workspace, elements / 2);
   /* call sort on the second half of the main array */
   mergesort_sort(array + (elements / 2), workspace, elements - (elements / 2));
   /* merge the two halves of the workspace array into the main array */
   mergesort_merge(array, workspace, elements);
   /* copy the workspace array back into the main array */
   for (i = 0; i < elements; i++) { 
      array[i] = workspace[i];
   }
}

static void swap_ints(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void insertion_sort(int *array, int elements) {
   int greater_i;
   int key;
   int i;
   /* for each position in array a except the first */
   for (i = 1; i < elements; i++) {
      /* pull out the item at that position and store it in variable 'key' */
      key = array[i];
      /* move each item that is to the left of that position,
         and is greater than key, one place to the right */
      greater_i = i - 1;
      while (greater_i >= 0 && array[greater_i] > key) {
         array[greater_i + 1] = array[greater_i];
         greater_i--;
      }
      /* put key in the leftmost position */
      array[greater_i + 1] = key;
   }
}

void merge_sort(int *array, int elements) {
   void *workspace = emalloc(sizeof array[0] * elements);
   mergessort_sort(array, workspace, elements);
   free(workspace);
}

void quick_sort(int *array, int elements) {
   int left_i;
   int pivot;
   int right_i;
   /* if there are less than two items in the array then stop */
   if (elements < 2) return;
   /* let pivot hold a copy of the array’s first element */
   pivot = array[0];
   /* let left_i be an index one to the left of the array’s left-most position */
   left_i = -1;
   /* let right_i be an index one to the right of the array’s right-most position */
   right_i = elements;
   /* loop forever { */
   for (;;) {
      /*  increment left_i (at least once) while the value at left_i < pivot */
      do {
         left_i++;
      } while (array[left_i] < pivot); 
      /*  decrement right_i (at least once) while the value at right_i > pivot */
      do {
         right_i--;
      } while (array[right_i] > pivot);
      /*  if left_i is to the left of right_i, then swap the values at their positions */
      if (left_i < right_i) {
         swap_ints(&a[left_i], &a[right_i]);
         /*  else break out of the loop */
      } else {
         break;
      }
   }
   /* quicksort the left sub-array */
   quick_sort(array, right_i + 1);
   /* quicksort the right sub-array */
   quick_sort(array + right_i + 1, elements - right_i - 1);
}

void selection_sort(int *array, int elements) {
   int inner_i;
   int outer_i; 
   int smallest_position;
   /* for each position outer_i in the array a except the last one */
   for (outer_i = 0; outer_i < elements - 1; outer_i++) {
      /* find the smallest item from position outer_i to position (elements - 1) */
      smallest_position = outer_i;
      for (inner_i = outer_i + 1; inner_i < elements; inner_i++) {
	     if (array[inner_i] < array[smallest_position]) smallest_position = inner_i;
      }
      /* swap the item you find with whatever is a position outer_i right now */ 
      swap_ints(&array[outer_i], &array[smallest_position]);
   }
}
