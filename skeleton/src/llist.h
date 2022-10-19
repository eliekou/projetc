#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
struct llist {
    /* Your code here */
    struct lcell* head;
};

struct lcell {
    /* Your code here */



    char MAJ;

    struct list* prop;//liste imbriquée

    struct lcell* next;

};

/* Your signatures here */

void new_free_llists(struct llist* lst);

void new_free_lcell(struct lcell* lc);

void new_free_llist(struct llist* lst);

struct llist* new_llist();

struct lcell* make_lcell(char MAJ, struct list* prop);


void print_lcell(struct lcell *lc);

void print_lcells(struct llist *llst);

void print_llist(struct llist *llst);

int compare_lcells2( struct lcell* lca, struct cell* lcb);

void insert2(struct llist* llst, struct cell* c);

struct llist* load_file_2(char* file_name);

int64_t get_time();

