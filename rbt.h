#ifndef RBT_H_
#define RBT_H_

typedef struct rbt_node *rbt;

extern int rbt_search(rbt, char *);

extern rbt rbt_delete(rbt, char *);

extern rbt rbt_insert(rbt, char *);

extern rbt rbt_free(rbt);

extern rbt rbt_new();

extern void print_key(char *s);

extern void rbt_inorder(rbt, void f(char *));

extern void rbt_preorder(rbt, void f(char *));

#endif
