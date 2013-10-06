/**
   graph.h
   @author TURNER. Ande,
   Defines the usage of the Graph ADT.
**/

#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct graph_record *graph;

/**
   graph_new(int)
   @param int  Sets the initial size of the Graph ADT
 **/
extern graph graph_new(int);

/**
   graph_add_edge(graph, int, int);
   @param graph  The Graph to have an edge added to the adjacency matrix
   @param int    The Vertex to create an edge from
   @param int    The Vertex to create an edge to
 **/
extern void graph_add_edge(graph, int, int);

/**
   graph_add_2edges(graph, int, int);
   @param graph  The Graph to have an edge added to the adjacency matrix
   @param int    The Vertex to create an edge between
   @param int    The Vertex to create an edge between
**/
extern void graph_add_2edges(graph, int, int);

/**
   graph_bfs(graph);
   @param graph  The Graph to perform a Breadth First Search upon
   @param int    The source Vertex of the BFS
**/
extern void graph_bfs(graph, int);

/**
   graph_dfs(graph);
   @param graph  The Graph to perform a Depth First Search upon
 **/
extern void graph_dfs(graph);

/**
   graph_free(graph);
   @param graph  The Graph to free the memory allocation of
 **/
extern void graph_free(graph);

/**
   graph_print(graph);
   @param graph  The Graph to print details of
 **/
extern void graph_print(graph);

#endif 
