#include "quick_sort.h"

static void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
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
