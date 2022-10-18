#include "llist.h"
#include "list.h"


struct llist* new_llist(){


  struct llist *llst = (struct llist*) malloc(sizeof(struct llist));


  if (lst == NULL){
    return NULL;
  }

  llst->head = NULL;
  return llst;
}



void new_free_llist(struct llist* lst){
    struct lcell *cur;
	struct list *tmp;
    // Empty list
	if (lst == NULL) {
        return;
    }
    cur = lst->head;

    while (cur!= NULL){
        tmp = cur;
        cur = cur->next;

        new_free_lcell(tmp);
    }
    lst->head = NULL;
    free(lst);
}


void new_free_lcell(struct lcell* lca){
    if (lca == NULL){
        return;
    }



    free_list(lca->prop);
    free(lca);

}

struct lcell* make_lcell(char MAJ,struct list* prop){
    struct lcell* lc;
    lc = malloc(sizeof(struct lcell));

    lc->MAJ = MAJ;
    lc->prop =prop;
    lc->next = NULL;


    return lc;
}





struct lcell* make_lcell(char MAJ, struct list *prop){

  struct lcell *lca;
  lca = malloc(sizeof(struct lcell));

  if (lca == NULL){
    return NULL;

  }
  lca ->MAJ = MAJ;
  lca ->prop = prop;
  lca->next = NULL;

  return lca;

}


int compare_lcells(struct lcell *lca, struct lcell *lcb){
  int res;

  res = strcmp(lca -> MAJ,lcb -> MAJ);

  return res;
}

void new_insert(struct llist *lst, struct lcell *lca){

  struct lcell *cc;
  cc = lst -> head;

  if (cc==NULL){
    lst-> head = lca;
    return;
  }

  result = compare_lcells(cc,lca);
  if (result>0){
		lca->next = lst->head;
		lst->head = lca;
	}
  while((cc->next != NULL)&& compare_cells(cc->next,lca)<=0){
    cc = cc->next;
    compare_lcells(cc,lca);

  }
  lca ->next = cc -> next;
  cc->next =lca;


}
struct lcell* make_lcell_from_list(struct list *lst){

  if (lst == NULL){
    printf("Error");
    exit(1);
  }
  cc = lst->head;
  struct lcell *lc;

  char MAJ;
  struct list* prop;//liste imbriquée
  struct lcell* next;//prochain lcell

  lc = malloc(sizeof(struct(lcell)));
  prop = malloc(sizeof(struct(list)));
  next = malloc(sizeof(struct(lcell)));

  lc->prop = lst;
  lc->MAJ = cc->fname[0];
  lc-> next = NULL;





}
struct lcell* search_maj(struct llist *lst, char MAJ){

  struct lcell *cc;
  cc = lst ->head;

  if (lst == NULL)
}


struct llist* load_llists(char* file_name){

  struct llist *lst;
  lst = new_llist();


  FILE *flecture;
  char line2[100];

  flecture = fopen(file_name,"r");
  if (flecture == NULL) {
        printf("Error: File not recognized\n");
    exit(1);
  }

  while (fgets(line2,50,flecture)!=NULL){

    struct cell *c1;
    c1 = make_cell_from_line(line2);

    if (letter not in lists){
      char MAJ = c1->fname[0];
      l3 = new_list();
      insert(l3,c1);
      struct lecell *lc;
      lc = make_lcell_from_list(l3);
      new_insert(lst,lc);
    }

    else{

      struct lcell *lc;

      c1->fname[0]

      insert(l1,c1)
    }



  }



}
