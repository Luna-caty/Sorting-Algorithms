# Sorting Algorithms
le but de ce mini projet est d'implementer 6 types des algorithmes de tri
et de calculer le temps d'execution de chaque algorithme avec differents taille du tableau pour que a la fin on fait une comparaison de tout les algorithmes
## Les tris implementé
Les tests de temps d'éxecution ont été fait sur des tableau de taille 50,100,200,500,1000,1500,2500
 ### Bubble sort
Son principe est de comparer des paires d'éléments adjacents et en les échangeant s'ils sont dans le mauvais ordre. Ce processus est répété plusieurs fois jusqu'à ce que le tableau soit complètement trié

Sa complexité est O (n²)
![alt text](<bubble sort.png>)
 ### Optimized bubble sort 
 c'est une version optimisé du Bubble sort 
 Il fonctionne en comparant des paires d'éléments consécutifs et en les échangeant si nécessaire pour les mettre dans le bon ordre

si le tableau est trié sa complexité est O (n) 

sinon c'est O(n²)

![alt text](<opt bubblesort.png>)

### Comparaison entre Bubble sort et sa version optimisé

![alt text](<comparition optbubblesort & bubblesort.png>)

### Gnome sort
Son principe est de comparer deux éléments consécutifs : s’ils sont dans l’ordre on se déplace d’un pas vers lafin du tableau (ou on s’arrête si la fin est atteinte)

sinon, on les permute et on se déplace d’un pas versle début du tableau,on commence par le début du tableau

si le valeurs sont triées à l'envers la complexité est de O (n²)

et si les valeurs sont déjà triées la complexité est de O (n)

![alt text](<gnome sort.png>)

### Radix Sort
Le Radix Sort est un algorithme de tri non-comparatif qui trie les éléments en fonction de leurs chiffres ou caractères, position par position, en commençant par le chiffre le moins significatif 

Sa complexité est O (k*n) avec k le nombre de chiffres maximum d'un nombre du tableau

![alt text](<redix sort.png>)

### Quick Sort
Son principe est de choisir un élement du tableau pivot.

On divise ensuite la liste en deux sous-listes. La première, à gauche, contientles éléments inférieurs au pivot. 

La seconde, à droite, contient les éléments supérieurs au pivot 

Cette étape est répétée récursivement pour chaque sous-tableau jusqu'à ce que tous les éléments soient triés

![alt text](<quick sort.png>)

Sa complexité est O (n log (n) )


### Heap Sort

Son principe est de transformer d'abord un tableau en un tas max, où le plus grand élément est à la racine. L'algorithme procède ensuite par extractions successives : il échange le premier élément (le plus grand) avec le dernier, réduit la taille du tas, puis réorganise le tas pour maintenir sa structure

Sa complexité est O (n log (n) )
![alt text](<heap sort.png>)

## Comparaison Final 


On peut remarquer que Heap sort et Quick sort sont efficace pour les tableaux de grands taille 

![alt text](<comparision 5 sorting.png>)