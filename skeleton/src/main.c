#include <time.h>

#include "llist.h"

int main(int argc, char *argv[]) {
    //struct list* l;
    //l = new_list();
    //print_list(l);

    //struct cell* c2;
    // c2 = make_cell("R","f","er");
    // c = make_cell("Annie", "ERNAUX", "76170");

    //print_cell(c);
    // push(l, c);
    // push(l,c2);

    //print_cell(c);

    // print_list(l);

    //free_list(l);

    //testage du pop

    // struct cell *po;
    // po = make_cell("Poubelle","po2","po3");
    // pop(l,po);
    // print_list(l);
    // free(po);
    

    //Testage du début de l'exo 2(make_cell_from_line)- Question 1

    // char str2[] = "J,k,0;";
    // struct cell *p1;
    // p1 = make_cell_from_line(str2);
    // print_cell(p1);
    //printf("test");





    //Testage de comparaison(compare cells)- Question 3

    // struct cell *c3;
    // struct cell *c4;
    // int * comp1;
    // c3 = make_cell("R","f","er");
    // c4 = make_cell("A","f","er");
    // comp1 = compare_cells(c3,c4);
    // printf("%d",comp1);
    // return 0;

 

    //Vérification du insert- Question 3
    // struct list *l;//Différence entre list et newlist?
    // //print_list(l);
    // l = new_list();
    // print_list(l);

    // struct cell* c2;
    // struct cell*c;
    // struct cell *c3;

    // c2 = make_cell("R","f","er");
    // c = make_cell("Annie", "ERNAUX", "76170");
    // c3 = make_cell("re","g","ee");//C3 va etre plus grand que cc donc compare_cellls(cc,c3)va ertre infèrieyur a zero
    // //print_cell(c);
    // push(l, c);
    // print_list(l);
    // push(l,c2);
    // print_list(l);
    // printf("hello");
    // insert(l,c3);
    // print_list(l);



    //Vérification du load_file - Question 4

    // struct list *ltest;
    // char* adr = "large.txt";
    // ltest = load_file(adr);
    // return 0; 

    struct list *lnew; //Différence entre list et newlist?

    lnew = load_file("data/small.txt");
    
    // // // lnew = load_file("data/medium.txt");
    // // // lnew = load_file("data/large.txt");
    print_list(lnew);
    free_list(lnew);




    // printf("Deuxième partie");
    // //Deuxième partie: Structure de liste imbriquée

    struct llist *llst;
    llst = load_file_2("data/small.txt");
    // // llst = load_file_2("data/large.txt");
    // llst = load_file_2("data/medium.txt");

    print_llist(llst);
    new_free_llist(llst);
    
    

    return 0;
   
}




