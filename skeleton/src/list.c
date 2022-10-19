#include "list.h"
#include <sys/time.h>

/* Construction/Destruction
======================== */


struct list* new_list() {
	struct list* lst = (struct list*)malloc(sizeof(struct list));

	if (lst == NULL) { 
		return NULL; 
	}

	lst->head=NULL;
	return lst;
}

static void free_cells(struct list *lst) {
	struct cell *cur;
	struct cell *tmp;
    // Empty list 
	if (lst == NULL) { 
        return; 
    }
    // Free each cell one by one
	cur = lst->head;
	while (cur != NULL) {
		tmp = cur;
		cur = cur->next;
        // If dynamically allocated!
        free(tmp->fname);
        free(tmp->lname);
        free(tmp->zip);
		free(tmp);
	}
	lst->head = NULL;
}

void free_list(struct list* lst) {
    free_cells(lst);
	free(lst);
}


/* Printing
======== */

void print_cell(struct cell* c) {
	/* Your code here */
	printf("[%s", c-> fname);
	printf(",%s", c->lname);
	printf(",%s]",c->zip );
}

void print_list(struct list *lst) {
	/* Your code here */
	printf("{ \n");

	struct cell *c ;
	c = lst ->head;

	if (c == NULL){
		printf("}\n");
		return;
	}

	while ( c->next != NULL)
	{
        
		print_cell(c);
		printf(",\n");
		c =  c->next;
	}
	print_cell(c);
	printf(" \n}");
	
	/*print_cell((lst->head));*/
    
	/*lst->head = (lst->head)-> next;*/
}

/* Cell addition
============= */

struct cell* make_cell(char* fname, char* lname, char* zip) {
	/* Your code here */
	

	struct cell *c1;

	c1 = malloc(sizeof(struct cell)) ;

	c1->fname = fname;
    c1->lname = lname;
	c1->zip = zip;
    
	
	return c1;

	
}

void push(struct list *lst, struct cell* c) {
	/* Your code here */
    c-> next =lst->head;
	lst->head = c;

}

void pop(struct list* lst, struct cell* out) {
	//struct cell *c;
	struct cell *inter;



	memcpy(out,lst->head,sizeof(struct cell));
	inter = lst ->head;
	free(inter);

	lst ->head = out->next;// on fait pointer le head sur la cellule d'après
    
	//memcpy(out,lst->head,sizeof(out));

}
struct cell* make_cell_from_line(char* line){
	struct cell *c1;
	char* fname;
	char* lname;
	char* zip;

    fname = malloc(sizeof(char)*40);
	lname = malloc(sizeof(char)*40);
	zip = malloc(sizeof(char)*10);
	c1 = malloc(sizeof(struct cell));


	
	//on crée un copie de la ligne pour pouvoir utiliser la fonction strtok
	const char * separators = ",;";
	
	char * strToken= strtok(line,separators);// Déclaration de strToken et utilisation de strtok sur la copie
	strcpy(fname,strToken);
    c1->fname = fname;

	strToken = strtok(NULL,separators);
	strcpy(lname,strToken);
	c1->lname = lname;


	strToken = strtok(NULL,separators);
	strcpy(zip,strToken);
	c1->zip = zip;
	

	return c1;

}

int compare_cells(struct cell *a,struct cell *b){
	int res;
	res = strcmp(a->lname,b->lname);//va etre supèrieur a zéro si a estt plus grand que c,infèrieur a zero si moins grand que c
	if (res == 0) {
		return strcmp(a->fname,b->fname);
	}
	return res;
    


	
}

struct list* load_file(char* file_name){
	struct list *l1;
	l1 = new_list();//besoion d'utiliser new_list?
	
	

	FILE *flecture;
    char line2[100];

	flecture = fopen(file_name,"r");
	if (flecture == NULL) {
        printf("Error: File not recognized\n");
		exit(1);
	} 
	int64_t t0;
	t0 = get_time();
	while (fgets(line2,50,flecture)!= NULL){
		
		struct cell *c1;
		c1 = make_cell_from_line(line2);
		// push(l1,c1);//problème car l1 vide?
        //Modification de la fonction avec la nouvelle fonction insert
		insert(l1,c1);
	}

	fclose(flecture);
	int64_t ttotal = get_time() - t0;
	printf("Le temps total pris par la méthode non optimisée est %lld",ttotal);
	

	return l1;

        
	
}

void insert(struct list* lst, struct cell* c){
	struct cell *cc ;

	
	
	cc = lst ->head;
    int result;

	//Testage d'abord de si la liste n'est pas vide
	if (cc == NULL){
		lst->head = c;
		return;
	}
	result = compare_cells(cc,c);
	//printf("le résultat est%d",result);
    if (result>0){
		c->next = lst->head;
		lst->head = c;
	}
	
	while ((cc->next != NULL)  && compare_cells(cc->next,c) <= 0){
	   cc = cc->next;
	}

	c-> next =cc->next;
	cc->next = c;
	
	

}

int64_t get_time(){

	struct timeval tp;
	gettimeofday(&tp,NULL);
	int64_t tpresent = tp.tv_usec;

	return tpresent;

}
