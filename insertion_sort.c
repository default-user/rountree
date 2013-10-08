#include "insertion_sort.h

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
