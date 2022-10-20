Le fichier comporte dans le main les différents appels aux fonctions.

Pour la partie 2, pour la lecture de données non optimisée:

On a d'abord l'appel au load_file(pour les trois types de fichiers dans data), et à print_list, ce qui affiche la liste de manière non optimisée.
Le load_file va faire appel aux fonctions: - insert
                                           - compare_cells




Pour la partie 3, pour la lecture de donnée avec la structure optimisée.
On a l'appel au load_file_2, fonction qui va utiliser la gestion de la liste sous forme optimisée.

Le load_file_2 va faire appel aux fonctions: - insert_2
                                             - compare_lcells2


La fonction qui va permettre de comparer les temps est la fonction get_time().

Le main comporte plusieurs parties commentées, en fonction des différents tests réalisés à chaque question, les seules parties décommentées concerent le test du load_file avec les deux méthodes, listes imbriquées et non imbriquées.