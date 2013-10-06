/**
   graph.c
   @author TURNER. Ande,
   Implements a Graph ADT.
**/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "int_queue.h"
#include "graph.h"

typedef struct vertex_record vertex;

typedef enum state_e {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;

struct vertex_record {
   int distance;
   int finish;
   int predecessor;
   state_t state;
};


struct graph_record {
   int size;
   int **edges;
   vertex *vertices;
};

static int step;

static void visit(graph g, int source) {
   int i;
   g->vertices[source].state = VISITED_SELF;
   step++;
   g->vertices[source].distance = step;
   for (i = 0; i < g->size; i++) {
      if (g->edges[source][i]) {
         if (g->vertices[i].state == UNVISITED) {
            g->vertices[i].predecessor = source;
            visit(g, i);
         }
      }
   }
   step++;
   g->vertices[source].state = VISITED_DESCENDANTS;
   g->vertices[source].finish = step;
}

graph graph_new(int vertices) {
   int i;
   int j;
   graph g = emalloc(sizeof *g);
   g->edges = emalloc((sizeof (int *)) * vertices);
   for (i = 0; i < vertices; i++) {
      g->edges[i] = emalloc((sizeof (int)) * vertices);
      for (j = 0; j < vertices; j++) {
         g->edges[i][j] = 0;
      }
   }
   g->size = vertices;
   g->vertices = emalloc(sizeof (vertex) * vertices);
   return g;
}


void graph_add_edge(graph g, int u, int v) {
   g->edges[u][v] = 1;
}

void graph_add_2edges(graph g, int u, int v) {
   g->edges[u][v] = g->edges[v][u] = 1;
}

void graph_bfs(graph g, int source) {
   int_queue q = int_queue_new();
   vertex u;
   int i;
   for (i = 0; i < g->size; i++) {
      g->vertices[i].state = UNVISITED;
      g->vertices[i].distance = -1;
      g->vertices[i].predecessor = -1;
   }
   g->vertices[source].state = VISITED_SELF;
   g->vertices[source].distance = 0;
   int_enqueue(q, source);
   while (int_queue_size(q)) {
      source = int_dequeue(q);
      u = g->vertices[source];
      for (i = 0; i < g->size; i++) {
         if (g->edges[source][i]) {
            if (g->vertices[i].state == UNVISITED) {
               g->vertices[i].state = VISITED_SELF;
               g->vertices[i].distance = u.distance + 1;
               g->vertices[i].predecessor = source;
               int_enqueue(q, i);
            }
         }
      }
      u.state = VISITED_DESCENDANTS;
   }
   int_queue_free(q);
}

void graph_dfs(graph g) {
   int i;
   for (i = 0; i < g->size; i++) {
      g->vertices[i].state = UNVISITED;
      g->vertices[i].predecessor = -1;
   }
   step = 0;
   for (i = 0; i < g->size; i++) {
      if (g->vertices[i].state == UNVISITED) {
         visit(g, i);
      }
   }
}

void graph_free(graph g) {
   int i;
   free(g->vertices);
   for (i = 0; i < g->size; i++) {
      free(g->edges[i]);
   }
   free(g->edges);
   free(g);
}

void graph_print(graph g) {
   int flag;
   int i;
   int j;
   printf("adjacency list:\n");
   for (i = 0; i < g->size; i++) {
      printf("%d | ", i);
      flag = 0;
      for (j = 0; j < g->size; j++) {
         if (g->edges[i][j]) {
            if (flag) printf(", ");
            printf("%d", j);
         }
         if (g->edges[i][j]) flag = 1;
      }
      printf("\n");
   }
   printf("\n");
   printf("vertex distance pred finish\n");
   for (i = 0; i < g->size; i++) {
      printf("%5d %5d %5d %5d\n", i, g->vertices[i].distance,
             g->vertices[i].predecessor, g->vertices[i].finish);
   }  
}
