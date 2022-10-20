 #include <time.h>

#include "llist.h"

int main(int argc, char *argv[]) {


    //testage du pop et du print- Partie 1

    // struct cell *po;
    // po = make_cell("Poubelle","po2","po3");
    // pop(l,po);
    // print_list(l);
    // free_cell(po);
    // free_list(l);
    

    //Testage du début de Partie 2- Question 1

    // char str2[] = "J,k,0;";
    // struct cell *p1;
    // p1 = make_cell_from_line(str2);
    // print_cell(p1);
    // free_cells(p1);





    //Testage de comparaison(compare cells)- Question 3 - Partie2

    // struct cell *c3;
    // struct cell *c4;
    // int * comp1;
    // c3 = make_cell("R","f","er");
    // c4 = make_cell("A","f","er");
    // comp1 = compare_cells(c3,c4);
    // printf("%d",comp1);
    //free_cells(c3);
    //free_cells(c4);

 

    //Vérification du insert- Question 4 - Partie2
    // struct list *l;//Différence entre list et newlist?
   
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
    // free_list(l);



    //Vérification du load_file - Question 4

 

    struct list *lnew; 

    lnew = load_file("data/small.txt");
    
    // lnew = load_file("data/medium.txt");
    // lnew = load_file("data/large.txt");
    print_list(lnew);
    free_list(lnew);




    
    //Deuxième partie: Structure de liste imbriquée


    //Vérification du deuxième load_file, load_file_2
    
    struct llist *llst;
    llst = load_file_2("data/small.txt");
    // // llst = load_file_2("data/large.txt");
    // llst = load_file_2("data/medium.txt");

    print_llist(llst);
    new_free_llist(llst);
    
    

    return 0;
   
}




