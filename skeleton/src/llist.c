#include "llist.h"


struct llist* new_llist(){
  struct llist *llst = (struct llist*) malloc(sizeof(struct llist));
  if (llst == NULL){
    return NULL;
  }
  llst->head = NULL;
  return llst;
}



void new_free_llist(struct llist* lst){
  struct lcell *cur;
	struct lcell *tmp;
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

// struct lcell* make_lcell(char MAJ,struct list* prop){
//     struct lcell* lc;
//     lc = malloc(sizeof(struct lcell));

//     lc->MAJ = MAJ;
//     lc->prop =prop;
//     lc->next = NULL;


//     return lc;
// }


struct lcell* make_lcell(char MAJ, struct list *prop){
  struct lcell *lca;
  lca = (struct lcell*) malloc(sizeof(struct lcell));
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
  res = lca -> MAJ - lcb -> MAJ;
  return res;
}

void new_insert(struct llist *lst, struct lcell *lca){
  int result;
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
  while((cc->next != NULL)&& compare_lcells(cc->next,lca)<=0){
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

  struct lcell *lc;

  //char MAJ;
  // struct list* prop;//liste imbriquée
  // struct lcell* next;//prochain lcell

  // lc = malloc(sizeof(struct lcell ));
  // prop = malloc(sizeof(struct list ));
  // next = malloc(sizeof(struct lcell ));

  lc = make_lcell(lst->head->fname[0], lst);
  return lc;
}


struct lcell* search_maj(struct llist *lst, char MAJ){

  struct lcell *cc;

  if (lst == NULL){
    printf("Error");
    exit(1);
  }

  cc = lst ->head;

  while (cc != NULL){
    if (cc->MAJ == MAJ){
      return cc;
    }
    cc = cc->next;
  }
  return NULL;
}


struct llist* load_llists(char* file_name){

  struct llist *llst;
  llst = new_llist();


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
    printf("On passe");
    if (search_maj(llst,c1->fname[0])==NULL){
      // char MAJ = c1->fname[0];

      struct list *l3;
      l3 = new_list();
      insert(l3,c1);

      struct lcell *lc;
      lc = make_lcell_from_list(l3);
      new_insert(llst,lc);
    } 
    else{

      struct lcell *lc;

      lc = search_maj(llst,c1->fname[0]);
      
      
      insert(lc->prop,c1);

    }
  fclose(flecture);
  }
  return llst;
}


void print_lcell(struct lcell *lc){


  printf("MAJ%c", lc-> MAJ);
	
	print_list(lc-> prop );
}


void print_lcells(struct llist *llst){
  if (llst==NULL){
    printf("La liste est vide");
    return;
  }
  struct lcell *lc;
  lc = llst->head;

  while( lc!=NULL){
   print_lcell(lc);
   lc = lc->next;

  }
}

void print_llist(struct llist*llst){

  if (llst == NULL){
    printf("La liste imbriqué est vide");
    return;
  }
  struct lcell *lc;
  lc = llst->head;

  while (lc!= NULL){
    print_list(lc->prop);
    lc = lc->next;
  }
}

//NEW 


int compare_lcells2( struct lcell* lca, struct cell* lcb){
   
  float res;
  res = lca->MAJ - lcb->fname[0];
  return res;

}


void insert2(struct llist *llst, struct cell *c){

  struct lcell *lc;
  lc = llst->head;

  //1er cas 
  if (lc == NULL || compare_lcells2(lc,c) < 0){
    

    
    struct list *lst;
    lst = new_list();
    insert(lst,c);

    struct lcell *lc2;
    lc2 = make_lcell(c->fname[0],lst);
    lc2->next = llst ->head;
    llst->head = lc2;
    return;

  }

  while (lc->next !=NULL ){
    //Deuxième cas
    if (compare_lcells2(lc,c)>0 && (lc->next)!= NULL && compare_lcells2(lc->next,c)<0){

      struct list *lst;
      lst = new_list();
      insert(lst,c);

      struct lcell *lc2;
      lc2 = make_lcell(c->fname[0],lst);

      // Ajout a la lliste
      lc2->next = lc->next;
      lc->next = lc2;

      return;

    }
    //Troisième cas
    else if (compare_lcells2(lc,c)==0){
      
      insert(lc->prop,c);
      return;
    }
    lc = lc->next;

  }

}

struct  llist* load_file_2(char * filename){



  struct llist *llst;
  llst = new_llist();

  FILE *flecture;
  char line2[100];

	flecture = fopen(filename,"r");



  if (flecture == NULL) {
    printf("Error: File not recognized\n");
		exit(1);
	} 
  while (fgets(line2,50,flecture)!= NULL){


    struct cell *c1;
    c1 = make_cell_from_line(line2);
    
    insert2(llst,c1);


  }
  return llst;

  fclose(flecture);

}

