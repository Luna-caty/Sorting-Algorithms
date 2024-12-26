#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
void swap(int *a, int *b)
{
    int x;
    x = *a;
    *a = *b;
    *b = x;
}
void bubbleSort(int A[], int n)
{
    bool change = true;
    clock_t debut,fin;
    double tempsExecution;
    debut=clock();
    while (change == true)
    {
        change = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                swap(&A[i], &A[i + 1]);
                change = true;
            }
        }
    }
    fin=clock();
    tempsExecution= ((double) (fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n",tempsExecution);

}
void bubbleSortOpt(int A[], int n)
{
    int m = n - 1;
    bool change = true;
    clock_t debut,fin;
    double tempsExecution;
    debut=clock();
    while (change)
    {
        change = false;
        for (int i = 0; i < m; i++)
        {
            if (A[i] > A[i + 1])
            {
                swap(&A[i], &A[i + 1]);
                change = true;
            }
        }
        m = m - 1;
    }
    fin=clock();
    tempsExecution= ((double) (fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n",tempsExecution);
}

// redix sort
int key(int x, int i)
{
    int div = pow(10, i);
    return (x / div) % 10;
}
void sortAux(int A[], int n, int i)
{
    int count[10] = {0}; //  tableau comptage des occurences de chiffres
    int B[n];
    int j, k;

    // on calcule l'occurence de chaque chiffre
    for (j = 0; j < n; j++)
    {
        count[key(A[j], i)]++;
    }
    /* pour T = {141,232,45,112,143}
    on aura dans count
    count = {0, 1, 2, 1, 0, 1, 0, 0, 0, 0}§
    dans ce cas on a pris le cas des unités
    */

    // on calcule les positions cumulées pour chaque chiffre
    for (j = 1; j < 10; j++)
    {

        count[j] += count[j - 1];
    }
    // resultat count = {0, 1, 3, 4, 4, 5, 5, 5, 5, 5}

    // on place les elements dnas l'ordre trié selon le chiffre à la position i

    /*
    A[1]=232  le chiffre des unités c'est 2 
    on va placer 232 a la position count [2] -1 = 3 -1 => 2 dans B 
    et decrement count [2] (donc il devient 2)
    
    A[3]=112 
    le chiffre des unités est 2 on va placer 232 a la position count [2] -1 => 2-1 =1 dans B
    et on decremente count 2 (donc il devient 1)
    */
    for (j = n - 1; j >= 0; j--)
    {
        k = count[key(A[j], i)] - 1;
        B[k] = A[j];
        count[key(A[j], i)]--;
    }

    // on recopie les elements dans le tableau original
    for (j = 0; j < n; j++)
    {

        A[j] = B[j];
    }
}
void redixSort(int A[], int n, int k) {
    clock_t debut, fin;
    double tempsExecution;

    debut = clock(); 

    for (int i = 0; i < k; i++) {
        sortAux(A, n, i);
    }

    fin = clock();
    tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("Temps d'execution du tri Radix: %f secondes\n", tempsExecution);
}


// heap sort 
void heapify(int A[], int n, int i) {
    int max = i;
    int gauche = 2 * i + 1;
    int droit = 2 * i + 2;
    if (gauche < n && A[gauche] > A[max]) max = gauche;
    if (droit < n && A[droit] > A[max]) max = droit;
    if (max != i) {
        swap(&A[i], &A[max]);
        heapify(A, n, max);
    }
}

void heapSort(int A[], int n) {
    clock_t debut,fin;
    double tempsExecution;
    debut=clock();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(A, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
    fin=clock();
    tempsExecution= ((double) (fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n",tempsExecution);

}


int main()
{
    int T[] = {
        1254, 8965, 7412, 3698, 9514, 6325, 4587, 1236, 7896, 4563,
        7895, 1478, 2589, 6547, 9632, 1597, 4568, 7896, 3214, 6589,
        4521, 7896, 3214, 6587, 9854, 1236, 5478, 9632, 1478, 5896,
        7412, 3698, 9514, 6325, 4587, 1236, 7896, 4563, 7895, 1478,
        2589, 6547, 9632, 1597, 4568, 7896, 3214, 6589, 4521, 7896,
        1254, 8965, 7412, 3698, 9514, 6325, 4587, 1236, 7896, 4563,
        7895, 1478, 2589, 6547, 9632, 1597, 4568, 7896, 3214, 6589,
        4521, 7896, 3214, 6587, 9854, 1236, 5478, 9632, 1478, 5896,
        7412, 3698, 9514, 6325, 4587, 1236, 7896, 4563, 7895, 1478,
        2589, 6547, 9632, 1597, 4568, 7896, 3214, 6589, 4521, 7896
    };
    
    int n = sizeof(T)/sizeof(T[0]);
    heapSort(T,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }

    return 0;
}