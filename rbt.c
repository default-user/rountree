#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "rbt.h"

#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node {
   char *key;
   rbt_colour colour;
   rbt left;
   rbt right;
};

static rbt left_rotate(rbt r) {
	rbt tmp_r = r;
	r = r->right;
	tmp_r->right = r->left;
	r->left = tmp_r;
	return r;
}

static rbt right_rotate(rbt r) {
	rbt tmp_r = r;
	r = r->left;
	tmp_r->left = r->right;
	r->right = tmp_r;
	return r;
}

static rbt rbt_fix(rbt r) {
	if (IS_RED(r->left) && IS_RED(r->left->left)) {
		if (IS_RED(r->right)) {
			r->colour = RED;
			r->left->colour = BLACK;
			r->right->colour = BLACK;
			
		} else {
			r = right_rotate(r);
			r->colour = BLACK;
			r->right->colour = RED;
			
		}
	} else if (IS_RED(r->left) && IS_RED(r->left->right)) {
		if (IS_RED(r->right)) {
			r->colour = RED;
			r->left->colour = BLACK;
			r->right->colour = BLACK;
			
		} else {
			r->left = left_rotate(r->left);
			r = right_rotate(r);
			r->colour = BLACK;
			r->right->colour = RED;
			
		}
	} else if (IS_RED(r->right) && IS_RED(r->right->left)) {
		if (IS_RED(r->left)) {
			r->colour = RED;
			r->left->colour = BLACK;
			r->right->colour = BLACK;
			
		} else {
			r->right = right_rotate(r->right);
			r = left_rotate(r);
			r->colour = BLACK;
			r->left->colour = RED;
			
		}
	} else if (IS_RED(r->right) && IS_RED(r->right->right)) {
		if (IS_RED(r->left)) {
			r->colour = RED;
			r->left->colour = BLACK;
			r->right->colour = BLACK;
			
		} else {
			r = left_rotate(r);
			r->colour = BLACK;
			r->left->colour = RED;
			
		}
	}
	
	return r;
}

int rbt_search(rbt r, char *s) {
   if (r == NULL) {
      return 0;
   } else if (strcmp(s, r->key) == 0) {
      return 1;
   } else if (strcmp(s, r->key) < 0) {
      return rbt_search(r->left, s);
   } else {
      return rbt_search(r->right, s); 
   }
}

rbt rbt_delete(rbt r, char *s) {
   rbt tmp_r;
   char *tmp_str;
   
   if (r == NULL) {
      return r;
      
   } else if (strcmp(s, r->key) == 0) {
     
      if (r->left == NULL && r->right == NULL) {
         free(r->key);
         free(r);
         r = NULL;
         return r;
         
      } else if (r->left != NULL && r->right != NULL) {
         /* LEFTMOST = tmp_r */
         tmp_r = r->right;
         
         while (tmp_r->left != NULL) {

            tmp_r = tmp_r->left; 
         }

         tmp_str = tmp_r->key;
         tmp_r->key = r->key;
         r->key = tmp_str;

         r->right = rbt_delete(r->right, s);
         
      } else {
         
         if (r->left != NULL) {
            tmp_r = r;
            r = r->left;
            free(tmp_r->key);
            free(tmp_r);
            
         } else {
            tmp_r = r;
            r = r->right;
            free(tmp_r->key);
            free(tmp_r);
            
         }
      }

   } else if (strcmp(s, r->key) < 0) {
      r->left = rbt_delete(r->left, s);
      
   } else {
      r->right = rbt_delete(r->right, s); 
   }

   return r;
}

rbt rbt_free(rbt r) {
   if (NULL == r) return NULL;
   rbt_free(r->left);
   rbt_free(r->right);
   free(r->key);
   free(r);
   return r;
}

rbt rbt_insert(rbt r, char *s) {
   if (NULL == r) {
      r = emalloc(sizeof *r);
      r->key = emalloc(strlen(s) + 1);
      r->colour = RED;
      r->left = NULL;
      r->right = NULL;
      strcpy(r->key, s);
   } else if (strcmp(s, r->key) == 0) {
      /* do nothing */
   } else if (strcmp(s, r->key) < 0) {
      r->left = rbt_insert(r->left, s);
   } else {
      r->right = rbt_insert(r->right, s);
   }

   return rbt_fix(r);
}

rbt rbt_new() {
   return NULL;
}

void print_key(char *s) {
   printf("%s\n", s);
}

void rbt_inorder(rbt r, void f(char *s)) {
   if (NULL == r) return;
   rbt_inorder(r->left, f);
   f(r->key);
   rbt_inorder(r->right, f);
}

void rbt_preorder(rbt r, void f(char *s)) {
   if (NULL == r) return;
   f(r->key);
   rbt_preorder(r->left, f);
   rbt_preorder(r->right, f);
}
