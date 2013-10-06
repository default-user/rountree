/**
   int_queue.h
   @author TURNER. Ande,
   Defines the usage of the Queue ADT.
**/

#ifndef INT_QUEUE_H_
#define INT_QUEUE_H_

typedef struct int_queue_record *int_queue;

extern int int_dequeue(int_queue);

extern int int_queue_size(int_queue);

extern int_queue int_queue_new();

extern void int_enqueue(int_queue, int);

extern void int_queue_free(int_queue);

extern void int_queue_print(int_queue);

#endif
