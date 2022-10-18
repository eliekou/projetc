

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

int compare_lcells( struct lcell* lca, struct lcell* lcb);

struct llist* new_load_from_files(char* file_name);
