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

  //1er cas: La llist ets nulle ou il faut placer la lcellule au debut de liste, en tete de liste
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
    //Deuxième cas: Cas ou l'on va rajouter lc au milieu
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
    //Troisième cas: Un lc est déja présent pour cette lettre, on a plus qu'à insert la cellule dans la liste associée.
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
  int64_t t0 = get_time();
  while (fgets(line2,50,flecture)!= NULL){


    struct cell *c1;
    c1 = make_cell_from_line(line2);
    
    insert2(llst,c1);


  }
  fclose(flecture);
  int64_t ttotal = get_time() - t0;
  printf("Le temps total pris par la méthode  optimisée est %lld",ttotal);

  
  
  return llst;


}

