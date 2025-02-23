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
    clock_t debut, fin;
    double tempsExecution;
    debut = clock();
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
    fin = clock();
    tempsExecution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n", tempsExecution);
}
void bubbleSortOpt(int A[], int n)
{
    int m = n - 1;
    bool change = true;
    clock_t debut, fin;
    double tempsExecution;
    debut = clock();
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
    fin = clock();
    tempsExecution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n", tempsExecution);
}
// Gnome sort
void gnomeSort(int arr[], int n)
{
    int i = 0;

    clock_t t1,t2;
    t1=clock();
    while (i < n)
    {
        if (i == 0 || arr[i] >= arr[i - 1])
        {
            i++;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
    t2=clock();
    double tempsExecution = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps d'execution : %f secondes\n", tempsExecution);

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
    count = {0, 1, 2, 1, 0, 1, 0, 0, 0, 0}
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
void redixSort(int A[], int n, int k)
{
    clock_t debut, fin;
    double tempsExecution;

    debut = clock();

    for (int i = 0; i < k; i++)
    {
        sortAux(A, n, i);
    }

    fin = clock();
    tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("Temps d'execution du tri Radix: %f secondes\n", tempsExecution);
}

// quick sort
int partition(int tab[], int d, int f)
{
    int eltPivot = tab[d];
    int i = d + 1, j = f;

    while (i<=j)
    {
        while (i <= f && tab[i] <= eltPivot)
        {
            i++;
        }

        while (j >= d && tab[j] > eltPivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&tab[i], &tab[j]);
        }
    }


    swap(&tab[d],&tab[j]);
    return j;
}
void QuickSort(int tab[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(tab, p, r);
        QuickSort(tab, p, q-1);
        QuickSort(tab, q + 1, r);
    }
    
}

// heap sort
void heapify(int A[], int n, int i)
{
    int max = i;
    int gauche = 2 * i + 1;
    int droit = 2 * i + 2;
    if (gauche < n && A[gauche] > A[max])
        max = gauche;
    if (droit < n && A[droit] > A[max])
        max = droit;
    if (max != i)
    {
        swap(&A[i], &A[max]);
        heapify(A, n, max);
    }
}

void heapSort(int A[], int n)
{
    clock_t debut, fin;
    double tempsExecution;
    debut = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
    fin = clock();
    tempsExecution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("temps d'execution :%f secondes \n", tempsExecution);
}

int main()
{
 int array50 []={
       64, 90, 99, 89, 75, 57, 82, 96, 99, 83,
        8, 16, 85, 56, 62, 42, 70, 89, 85, 85,
        53, 90, 24, 99, 44, 5, 17, 11, 10, 27,
        0, 80, 63, 14, 9, 21, 89, 91, 41, 53,
        86, 21, 78, 97, 10, 42, 62, 75, 78, 64,
 };
 int array100[]={
        32, 80, 97, 76, 22, 97, 44, 20, 4, 15,
        32, 96, 77, 37, 86, 45, 98, 85, 30, 86,
        72, 8, 73, 34, 74, 19, 6, 32, 20, 7,
        18, 31, 80, 79, 62, 62, 83, 73, 25, 9,
        88, 9, 19, 97, 56, 13, 93, 57, 69, 2,
        26, 17, 69, 19, 90, 75, 17, 60, 17, 4,
        31, 52, 93, 76, 83, 27, 4, 61, 25, 38,
        52, 81, 23, 11, 4, 18, 4, 53, 80, 77,
        58, 68, 83, 42, 88, 49, 84, 35, 83, 84,
        10, 67, 79, 53, 49, 98, 16, 57, 58, 62,
 };

 int array200[]={
       82, 90, 35, 28, 77, 52, 70, 88, 19, 71,
        31, 99, 21, 80, 63, 54, 61, 1, 0, 31,
        62, 87, 53, 45, 61, 74, 26, 12, 23, 83,
        79, 79, 19, 68, 17, 20, 2, 30, 21, 34,
        56, 15, 79, 62, 65, 97, 53, 10, 95, 60,
        27, 52, 49, 91, 18, 86, 85, 72, 82, 22,
        14, 29, 77, 35, 45, 33, 33, 80, 0, 91,
        31, 81, 12, 77, 32, 52, 76, 97, 68, 5,
        73, 1, 82, 65, 21, 40, 43, 27, 78, 63,
        91, 77, 27, 20, 20, 98, 58, 85, 76, 92,
        44, 13, 5, 43, 97, 76, 18, 70, 6, 55,
        45, 18, 16, 25, 23, 13, 30, 0, 24, 70,
        90, 52, 32, 93, 44, 74, 89, 83, 0, 24,
        41, 63, 1, 51, 66, 11, 6, 32, 5, 79,
        31, 23, 8, 2, 55, 97, 47, 1, 61, 85,
 };
 int array500[]={ 
    4571 ,4392 ,3808 ,935 ,4608 ,960 ,3442, 
    2266, 3070, 4170,2675 ,1433 ,845 ,3609 ,
    1695 ,4425 ,1476 ,3635 ,4666 ,4288 ,2725,
    3956 ,1946, 3376 ,1924 ,4511 ,797 ,1790 ,
    1341 ,513 ,242,  445 ,3786, 4880, 726, 77,
    1429, 609 ,4954, 4086, 3457, 4781, 4700, 3541,   
    3904 ,626 ,4500 ,715 ,2208 ,1348 ,4542 ,1215 ,
    1132 ,3539 ,304 ,4495 ,3626 ,2438 ,876 ,3540,
    45, 88, 21, 73, 58, 75, 8, 54, 51, 84,
    90, 14, 58, 26, 67, 8, 56, 47, 4, 29,
    92, 61, 28, 77, 1, 53, 66, 47, 86, 89,
    21, 58, 73, 4, 9, 96, 21, 87, 24, 72,
    60, 94, 29, 51, 29, 4, 99, 42, 5, 23,
    73, 87, 57, 24, 64, 1, 19, 70, 70, 73,
    76, 28, 14, 62, 65, 3, 8, 51, 81, 12,
    55, 88, 55, 87, 24, 67, 92, 10, 48, 20,
    62, 49, 4, 86, 70, 1, 68, 99, 15, 29,
    98, 69, 21, 95, 41, 95, 97, 20, 82, 76,
    29, 63, 97, 50, 63, 11, 31, 54, 17, 47,
        94, 62, 95, 42, 34, 78, 80, 80, 63, 23,
        58, 79, 26, 65, 32, 21, 61, 64, 65, 25,
        73, 66, 31, 7, 70, 14, 29, 82, 14, 40,
        84, 44, 46, 67, 28, 96, 9, 75, 35, 40,
        5, 41, 2, 80, 79, 84, 86, 63, 30, 29,
        17, 30, 35, 85, 85, 37, 59, 57, 21, 63,
        54, 85, 39, 53, 38, 53, 0, 79, 91, 26,
        50, 85, 38, 1, 23, 59, 20, 22, 31, 0,
        32, 98, 20, 24, 99, 96, 96, 1, 75, 37,
        90, 18, 2, 14, 65, 81, 5, 87, 9, 95,
        84, 73, 51, 45, 39, 36, 19, 89, 29, 66,
        19, 73, 12, 27, 63, 35, 10, 61, 68, 70,
        23, 91, 10, 92, 62, 17, 81, 65, 68, 50,
        1, 59, 70, 66, 92, 1, 11, 60, 36, 13,
        95, 78, 70, 41, 41, 56, 23, 94, 55, 75,
        12, 76, 5, 12, 3, 1, 11, 52, 76, 92,
        17, 36, 77, 59, 75, 43, 2, 32, 86, 71,
        11, 20, 84, 77, 44, 57, 24, 5, 57, 78,
        66, 62, 74, 9, 83, 66, 18, 64, 72, 5,
        10, 11, 99, 26, 93, 92, 39, 50, 13, 36,
        25, 11, 0, 1, 11, 51, 32, 65, 19, 79,
        48, 70, 87, 50, 68, 42, 81, 11, 19, 82,
        13, 34, 79, 93, 26, 48, 20, 26, 44, 93,
        56, 69, 15, 46, 43, 57, 97, 57, 99, 64,
        46, 72, 57, 84, 3, 91, 50, 46, 93, 67,
        44, 24, 52, 14, 67, 12, 67, 59, 53, 79,
        36, 71, 5, 57, 59, 59, 24, 19, 23, 5,
        12, 84, 74, 28, 44, 35, 81, 95, 27, 51,
        40, 52, 0, 40, 38, 37, 41, 17, 81, 59,
        74, 95, 83, 7, 29, 53, 20, 46, 60, 65,
        52, 31, 10, 74, 43, 11, 38, 65, 51, 52,
        56, 69, 25, 86, 25, 50, 44, 46, 21, 10,
        54, 23, 71, 83, 91, 55, 9, 91, 83, 13     
 };
 int array1000[] = {
    41, 467, 334, 500, 169, 724, 478, 358, 962, 464,
    705, 145, 281, 827, 961, 491, 995, 942, 827, 436,
    391, 604, 902, 153, 292, 382, 421, 716, 718, 895,
    447, 726, 771, 538, 869, 912, 667, 299, 35, 894,
    703, 811, 322, 333, 673, 664, 141, 711, 253, 868,
    547, 644, 662, 757, 37, 859, 723, 741, 529, 778,
    316, 35, 190, 842, 288, 106, 40, 942, 264, 648,
    446, 805, 890, 729, 370, 350, 6, 101, 393, 548,
    629, 623, 84, 954, 756, 840, 966, 376, 931, 308,
    944, 439, 626, 323, 537, 538, 118, 82, 929, 541,
    833, 115, 639, 658, 704, 930, 977, 306, 673, 386,
    21, 745, 924, 72, 270, 829, 777, 573, 97, 512,
    986, 290, 161, 636, 355, 767, 655, 574, 31, 52,
    350, 150, 941, 724, 966, 430, 107, 191, 7, 337,
    457, 287, 753, 383, 945, 909, 209, 758, 221, 588,
    422, 946, 506, 30, 413, 168, 900, 591, 762, 655,
    410, 359, 624, 537, 548, 483, 595, 41, 602, 350,
    291, 836, 374, 20, 596, 21, 348, 199, 668, 484,
    281, 734, 53, 999, 418, 938, 900, 788, 127, 467,
    728, 893, 648, 483, 807, 421, 310, 617, 813, 514,
    309, 616, 935, 451, 600, 249, 519, 556, 798, 303,
    224, 8, 844, 609, 989, 702, 195, 485, 93, 343,
    523, 587, 314, 503, 448, 200, 458, 618, 580, 796,
    798, 281, 589, 798, 9, 157, 472, 622, 538, 292,
    38, 179, 190, 657, 958, 191, 815, 888, 156, 511,
    202, 634, 272, 55, 328, 646, 362, 886, 875, 433,
    869, 142, 844, 416, 881, 998, 322, 651, 21, 699,
    557, 476, 892, 389, 75, 712, 600, 510, 3, 869,
    861, 688, 401, 789, 255, 423, 2, 585, 182, 285,
    88, 426, 617, 757, 832, 932, 169, 154, 721, 189,
    976, 329, 368, 692, 425, 555, 434, 549, 441, 512,
    145, 60, 718, 753, 139, 423, 279, 996, 687, 529,
    549, 437, 866, 949, 193, 195, 297, 416, 286, 105,
    488, 282, 455, 734, 114, 701, 316, 671, 786, 263,
    313, 355, 185, 53, 912, 808, 832, 945, 313, 756,
    321, 558, 646, 982, 481, 144, 196, 222, 129, 161,
    535, 450, 173, 466, 44, 659, 292, 439, 253, 24,
    154, 510, 745, 649, 186, 313, 474, 22, 168, 18,
    787, 905, 958, 391, 202, 625, 477, 414, 314, 824,
    334, 874, 372, 159, 833, 70, 487, 297, 518, 177,
    773, 270, 763, 668, 192, 985, 102, 480, 213, 627,
    802, 99, 527, 625, 543, 924, 23, 972, 61, 181,
    3, 432, 505, 593, 725, 31, 492, 142, 222, 286,
    64, 900, 187, 360, 413, 974, 270, 170, 235, 833,
    711, 760, 896, 667, 285, 550, 140, 694, 695, 624,
    19, 125, 576, 694, 658, 302, 371, 466, 678, 593,
    851, 484, 18, 464, 119, 152, 800, 87, 60, 926,
    10, 757, 170, 315, 576, 227, 43, 758, 164, 109,
    882, 86, 565, 487, 577, 474, 625, 627, 629, 928,
    423, 520, 902, 962, 123, 596, 737, 261, 195, 525,
    264, 260, 202, 116, 30, 326, 11, 771, 411, 547,
    153, 520, 790, 924, 188, 763, 940, 851, 662, 829,
    900, 713, 958, 578, 365, 7, 477, 200, 58, 439,
    303, 760, 357, 324, 477, 108, 113, 887, 801, 850,
    460, 428, 993, 384, 405, 540, 111, 704, 835, 356,
    72, 350, 823, 485, 556, 216, 626, 357, 526, 357,
    337, 271, 869, 361, 896, 22, 617, 112, 717, 696,
    585, 41, 423, 129, 229, 565, 559, 932, 296, 855,
    53, 962, 584, 734, 654, 972, 457, 369, 532, 963,
    607, 483, 911, 635, 67, 848, 675, 938, 223, 142,
    754, 511, 741, 175, 459, 825, 221, 870, 626, 934,
    205, 783, 850, 398, 279, 701, 193, 734, 637, 534,
    556, 993, 176, 705, 962, 548, 881, 300, 413, 641,
    855, 855, 142, 462, 611, 877, 424, 678, 752, 443,
    296, 673, 40, 313, 875, 72, 818, 610, 17, 932,
    112, 695, 169, 831, 40, 488, 685, 90, 497, 589,
    990, 145, 353, 314, 651, 740, 44, 258, 335, 759,
    192, 605, 264, 181, 503, 829, 775, 608, 292, 997,
    549, 556, 561, 627, 467, 541, 129, 240, 813, 174,
    601, 77, 215, 683, 213, 992, 824, 601, 392, 759,
    670, 428, 27, 84, 75, 786, 498, 970, 287, 847,
    604, 503, 221, 663, 706, 363, 10,
    69, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 2, 416, 452, 8, 262, 233, 
    454, 303, 634, 303, 256, 148, 124, 317, 213, 109, 
    28, 200, 80, 318, 858, 50, 155, 361, 264, 903, 
    676, 643, 909, 902, 561, 489, 948, 282, 653, 674, 
    220, 402, 923, 831, 369, 878, 259, 8, 619, 971, 
    3, 945, 781, 504, 392, 685, 313, 698, 589, 722, 
    938, 37, 410, 461, 234, 508, 961, 959, 493, 515, 
    269, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 29, 971, 3, 945, 781, 504, 
    392, 685, 313, 698, 589, 722, 938, 37, 410, 461, 
    234, 508, 961, 959, 493, 515, 269, 937, 869, 58, 
    700, 971, 264, 117, 215, 555, 815, 330, 39, 212, 
    288, 82, 954, 85, 710, 484, 774, 380, 815, 951, 
    541, 115, 679, 110, 898, 73, 788, 977, 132, 956, 
    689, 113, 8, 941, 790, 723, 363, 28, 184, 778, 
    215, 951, 541, 115, 679, 110, 898, 73, 788, 977, 
    132, 956, 689, 113, 8, 941, 790, 723, 363, 28, 
    184, 778, 200, 71, 885, 974, 71, 333, 867, 153, 
    295, 168, 825, 676, 629, 650, 598, 309, 693, 686, 
    80, 116,82, 90, 35, 28, 77, 52, 70, 88, 19, 71,
    31, 99, 21, 80, 63, 54, 61, 1, 0, 31,10,
};
int array1500[]={
    4571 ,4392 ,3808 ,935 ,4608 ,960 ,3442, 
    2266, 3070, 4170,2675 ,1433 ,845 ,3609 ,
    1695 ,4425 ,1476 ,3635 ,4666 ,4288 ,2725,
    3956 ,1946, 3376 ,1924 ,4511 ,797 ,1790 ,
    1341 ,513 ,242,  445 ,3786, 4880, 726, 77,
    1429, 609 ,4954, 4086, 3457, 4781, 4700, 3541,   
    3904 ,626 ,4500 ,715 ,2208 ,1348 ,4542 ,1215 ,
    1132 ,3539 ,304 ,4495 ,3626 ,2438 ,876 ,3540,
    45, 88, 21, 73, 58, 75, 8, 54, 51, 84,
    90, 14, 58, 26, 67, 8, 56, 47, 4, 29,
    92, 61, 28, 77, 1, 53, 66, 47, 86, 89,
    21, 58, 73, 4, 9, 96, 21, 87, 24, 72,
    60, 94, 29, 51, 29, 4, 99, 42, 5, 23,
    73, 87, 57, 24, 64, 1, 19, 70, 70, 73,
    76, 28, 14, 62, 65, 3, 8, 51, 81, 12,
    55, 88, 55, 87, 24, 67, 92, 10, 48, 20,
    62, 49, 4, 86, 70, 1, 68, 99, 15, 29,
    98, 69, 21, 95, 41, 95, 97, 20, 82, 76,
    29, 63, 97, 50, 63, 11, 31, 54, 17, 47,
        94, 62, 95, 42, 34, 78, 80, 80, 63, 23,
        58, 79, 26, 65, 32, 21, 61, 64, 65, 25,
        73, 66, 31, 7, 70, 14, 29, 82, 14, 40,
        84, 44, 46, 67, 28, 96, 9, 75, 35, 40,
        5, 41, 2, 80, 79, 84, 86, 63, 30, 29,
        17, 30, 35, 85, 85, 37, 59, 57, 21, 63,
        54, 85, 39, 53, 38, 53, 0, 79, 91, 26,
        50, 85, 38, 1, 23, 59, 20, 22, 31, 0,
        32, 98, 20, 24, 99, 96, 96, 1, 75, 37,
        90, 18, 2, 14, 65, 81, 5, 87, 9, 95,
        84, 73, 51, 45, 39, 36, 19, 89, 29, 66,
        19, 73, 12, 27, 63, 35, 10, 61, 68, 70,
        23, 91, 10, 92, 62, 17, 81, 65, 68, 50,
        1, 59, 70, 66, 92, 1, 11, 60, 36, 13,
        95, 78, 70, 41, 41, 56, 23, 94, 55, 75,
        12, 76, 5, 12, 3, 1, 11, 52, 76, 92,
        17, 36, 77, 59, 75, 43, 2, 32, 86, 71,
        11, 20, 84, 77, 44, 57, 24, 5, 57, 78,
        66, 62, 74, 9, 83, 66, 18, 64, 72, 5,
        10, 11, 99, 26, 93, 92, 39, 50, 13, 36,
        25, 11, 0, 1, 11, 51, 32, 65, 19, 79,
        48, 70, 87, 50, 68, 42, 81, 11, 19, 82,
        13, 34, 79, 93, 26, 48, 20, 26, 44, 93,
        56, 69, 15, 46, 43, 57, 97, 57, 99, 64,
        46, 72, 57, 84, 3, 91, 50, 46, 93, 67,
        44, 24, 52, 14, 67, 12, 67, 59, 53, 79,
        36, 71, 5, 57, 59, 59, 24, 19, 23, 5,
        12, 84, 74, 28, 44, 35, 81, 95, 27, 51,
        40, 52, 0, 40, 38, 37, 41, 17, 81, 59,
        74, 95, 83, 7, 29, 53, 20, 46, 60, 65,
        52, 31, 10, 74, 43, 11, 38, 65, 51, 52,
        56, 69, 25, 86, 25, 50, 44, 46, 21, 10,
        54, 23, 71, 83, 91, 55, 9, 91, 83, 13, 
        41, 467, 334, 500, 169, 724, 478, 358, 962, 464,
    705, 145, 281, 827, 961, 491, 995, 942, 827, 436,
    391, 604, 902, 153, 292, 382, 421, 716, 718, 895,
    447, 726, 771, 538, 869, 912, 667, 299, 35, 894,
    703, 811, 322, 333, 673, 664, 141, 711, 253, 868,
    547, 644, 662, 757, 37, 859, 723, 741, 529, 778,
    316, 35, 190, 842, 288, 106, 40, 942, 264, 648,
    446, 805, 890, 729, 370, 350, 6, 101, 393, 548,
    629, 623, 84, 954, 756, 840, 966, 376, 931, 308,
    944, 439, 626, 323, 537, 538, 118, 82, 929, 541,
    833, 115, 639, 658, 704, 930, 977, 306, 673, 386,
    21, 745, 924, 72, 270, 829, 777, 573, 97, 512,
    986, 290, 161, 636, 355, 767, 655, 574, 31, 52,
    350, 150, 941, 724, 966, 430, 107, 191, 7, 337,
    457, 287, 753, 383, 945, 909, 209, 758, 221, 588,
    422, 946, 506, 30, 413, 168, 900, 591, 762, 655,
    410, 359, 624, 537, 548, 483, 595, 41, 602, 350,
    291, 836, 374, 20, 596, 21, 348, 199, 668, 484,
    281, 734, 53, 999, 418, 938, 900, 788, 127, 467,
    728, 893, 648, 483, 807, 421, 310, 617, 813, 514,
    309, 616, 935, 451, 600, 249, 519, 556, 798, 303,
    224, 8, 844, 609, 989, 702, 195, 485, 93, 343,
    523, 587, 314, 503, 448, 200, 458, 618, 580, 796,
    798, 281, 589, 798, 9, 157, 472, 622, 538, 292,
    38, 179, 190, 657, 958, 191, 815, 888, 156, 511,
    202, 634, 272, 55, 328, 646, 362, 886, 875, 433,
    869, 142, 844, 416, 881, 998, 322, 651, 21, 699,
    557, 476, 892, 389, 75, 712, 600, 510, 3, 869,
    861, 688, 401, 789, 255, 423, 2, 585, 182, 285,
    88, 426, 617, 757, 832, 932, 169, 154, 721, 189,
    976, 329, 368, 692, 425, 555, 434, 549, 441, 512,
    145, 60, 718, 753, 139, 423, 279, 996, 687, 529,
    549, 437, 866, 949, 193, 195, 297, 416, 286, 105,
    488, 282, 455, 734, 114, 701, 316, 671, 786, 263,
    313, 355, 185, 53, 912, 808, 832, 945, 313, 756,
    321, 558, 646, 982, 481, 144, 196, 222, 129, 161,
    535, 450, 173, 466, 44, 659, 292, 439, 253, 24,
    154, 510, 745, 649, 186, 313, 474, 22, 168, 18,
    787, 905, 958, 391, 202, 625, 477, 414, 314, 824,
    334, 874, 372, 159, 833, 70, 487, 297, 518, 177,
    773, 270, 763, 668, 192, 985, 102, 480, 213, 627,
    802, 99, 527, 625, 543, 924, 23, 972, 61, 181,
    3, 432, 505, 593, 725, 31, 492, 142, 222, 286,
    64, 900, 187, 360, 413, 974, 270, 170, 235, 833,
    711, 760, 896, 667, 285, 550, 140, 694, 695, 624,
    19, 125, 576, 694, 658, 302, 371, 466, 678, 593,
    851, 484, 18, 464, 119, 152, 800, 87, 60, 926,
    10, 757, 170, 315, 576, 227, 43, 758, 164, 109,
    882, 86, 565, 487, 577, 474, 625, 627, 629, 928,
    423, 520, 902, 962, 123, 596, 737, 261, 195, 525,
    264, 260, 202, 116, 30, 326, 11, 771, 411, 547,
    153, 520, 790, 924, 188, 763, 940, 851, 662, 829,
    900, 713, 958, 578, 365, 7, 477, 200, 58, 439,
    303, 760, 357, 324, 477, 108, 113, 887, 801, 850,
    460, 428, 993, 384, 405, 540, 111, 704, 835, 356,
    72, 350, 823, 485, 556, 216, 626, 357, 526, 357,
    337, 271, 869, 361, 896, 22, 617, 112, 717, 696,
    585, 41, 423, 129, 229, 565, 559, 932, 296, 855,
    53, 962, 584, 734, 654, 972, 457, 369, 532, 963,
    607, 483, 911, 635, 67, 848, 675, 938, 223, 142,
    754, 511, 741, 175, 459, 825, 221, 870, 626, 934,
    205, 783, 850, 398, 279, 701, 193, 734, 637, 534,
    556, 993, 176, 705, 962, 548, 881, 300, 413, 641,
    855, 855, 142, 462, 611, 877, 424, 678, 752, 443,
    296, 673, 40, 313, 875, 72, 818, 610, 17, 932,
    112, 695, 169, 831, 40, 488, 685, 90, 497, 589,
    990, 145, 353, 314, 651, 740, 44, 258, 335, 759,
    192, 605, 264, 181, 503, 829, 775, 608, 292, 997,
    549, 556, 561, 627, 467, 541, 129, 240, 813, 174,
    601, 77, 215, 683, 213, 992, 824, 601, 392, 759,
    670, 428, 27, 84, 75, 786, 498, 970, 287, 847,
    604, 503, 221, 663, 706, 363, 10,
    69, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 2, 416, 452, 8, 262, 233, 
    454, 303, 634, 303, 256, 148, 124, 317, 213, 109, 
    28, 200, 80, 318, 858, 50, 155, 361, 264, 903, 
    676, 643, 909, 902, 561, 489, 948, 282, 653, 674, 
    220, 402, 923, 831, 369, 878, 259, 8, 619, 971, 
    3, 945, 781, 504, 392, 685, 313, 698, 589, 722, 
    938, 37, 410, 461, 234, 508, 961, 959, 493, 515, 
    269, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 29, 971, 3, 945, 781, 504, 
    392, 685, 313, 698, 589, 722, 938, 37, 410, 461, 
    234, 508, 961, 959, 493, 515, 269, 937, 869, 58, 
    700, 971, 264, 117, 215, 555, 815, 330, 39, 212, 
    288, 82, 954, 85, 710, 484, 774, 380, 815, 951, 
    541, 115, 679, 110, 898, 73, 788, 977, 132, 956, 
    689, 113, 8, 941, 790, 723, 363, 28, 184, 778, 
    215, 951, 541, 115, 679, 110, 898, 73, 788, 977, 
    132, 956, 689, 113, 8, 941, 790, 723, 363, 28, 
    184, 778, 200, 71, 885, 974, 71, 333, 867, 153, 
    295, 168, 825, 676, 629, 650, 598, 309, 693, 686, 
    80, 116,82, 90, 35, 28, 77, 52, 70, 88, 19, 71,
    31, 99, 21, 80, 63, 54, 61, 1, 0, 31,10,  

};
int array []={
     4571 ,4392 ,3808 ,935 ,4608 ,960 ,3442, 
    2266, 3070, 4170,2675 ,1433 ,845 ,3609 ,
    1695 ,4425 ,1476 ,3635 ,4666 ,4288 ,2725,
    3956 ,1946, 3376 ,1924 ,4511 ,797 ,1790 ,
    1341 ,513 ,242,  445 ,3786, 4880, 726, 77,
    1429, 609 ,4954, 4086, 3457, 4781, 4700, 3541,   
    3904 ,626 ,4500 ,715 ,2208 ,1348 ,4542 ,1215 ,
    1132 ,3539 ,304 ,4495 ,3626 ,2438 ,876 ,3540,
    45, 88, 21, 73, 58, 75, 8, 54, 51, 84,
    90, 14, 58, 26, 67, 8, 56, 47, 4, 29,
    92, 61, 28, 77, 1, 53, 66, 47, 86, 89,
    21, 58, 73, 4, 9, 96, 21, 87, 24, 72,
    60, 94, 29, 51, 29, 4, 99, 42, 5, 23,
    73, 87, 57, 24, 64, 1, 19, 70, 70, 73,
    76, 28, 14, 62, 65, 3, 8, 51, 81, 12,
    55, 88, 55, 87, 24, 67, 92, 10, 48, 20,
    62, 49, 4, 86, 70, 1, 68, 99, 15, 29,
    98, 69, 21, 95, 41, 95, 97, 20, 82, 76,
    29, 63, 97, 50, 63, 11, 31, 54, 17, 47,
        94, 62, 95, 42, 34, 78, 80, 80, 63, 23,
        58, 79, 26, 65, 32, 21, 61, 64, 65, 25,
        73, 66, 31, 7, 70, 14, 29, 82, 14, 40,
        84, 44, 46, 67, 28, 96, 9, 75, 35, 40,
        5, 41, 2, 80, 79, 84, 86, 63, 30, 29,
        17, 30, 35, 85, 85, 37, 59, 57, 21, 63,
        54, 85, 39, 53, 38, 53, 0, 79, 91, 26,
        50, 85, 38, 1, 23, 59, 20, 22, 31, 0,
        32, 98, 20, 24, 99, 96, 96, 1, 75, 37,
        90, 18, 2, 14, 65, 81, 5, 87, 9, 95,
        84, 73, 51, 45, 39, 36, 19, 89, 29, 66,
        19, 73, 12, 27, 63, 35, 10, 61, 68, 70,
        23, 91, 10, 92, 62, 17, 81, 65, 68, 50,
        1, 59, 70, 66, 92, 1, 11, 60, 36, 13,
        95, 78, 70, 41, 41, 56, 23, 94, 55, 75,
        12, 76, 5, 12, 3, 1, 11, 52, 76, 92,
        17, 36, 77, 59, 75, 43, 2, 32, 86, 71,
        11, 20, 84, 77, 44, 57, 24, 5, 57, 78,
        66, 62, 74, 9, 83, 66, 18, 64, 72, 5,
        10, 11, 99, 26, 93, 92, 39, 50, 13, 36,
        25, 11, 0, 1, 11, 51, 32, 65, 19, 79,
        48, 70, 87, 50, 68, 42, 81, 11, 19, 82,
        13, 34, 79, 93, 26, 48, 20, 26, 44, 93,
        56, 69, 15, 46, 43, 57, 97, 57, 99, 64,
        46, 72, 57, 84, 3, 91, 50, 46, 93, 67,
        44, 24, 52, 14, 67, 12, 67, 59, 53, 79,
        36, 71, 5, 57, 59, 59, 24, 19, 23, 5,
        12, 84, 74, 28, 44, 35, 81, 95, 27, 51,
        40, 52, 0, 40, 38, 37, 41, 17, 81, 59,
        74, 95, 83, 7, 29, 53, 20, 46, 60, 65,
        52, 31, 10, 74, 43, 11, 38, 65, 51, 52,
        56, 69, 25, 86, 25, 50, 44, 46, 21, 10,
        54, 23, 71, 83, 91, 55, 9, 91, 83, 13, 
        41, 467, 334, 500, 169, 724, 478, 358, 962, 464,
    705, 145, 281, 827, 961, 491, 995, 942, 827, 436,
    391, 604, 902, 153, 292, 382, 421, 716, 718, 895,
    447, 726, 771, 538, 869, 912, 667, 299, 35, 894,
    703, 811, 322, 333, 673, 664, 141, 711, 253, 868,
    547, 644, 662, 757, 37, 859, 723, 741, 529, 778,
    316, 35, 190, 842, 288, 106, 40, 942, 264, 648,
    446, 805, 890, 729, 370, 350, 6, 101, 393, 548,
    629, 623, 84, 954, 756, 840, 966, 376, 931, 308,
    944, 439, 626, 323, 537, 538, 118, 82, 929, 541,
    833, 115, 639, 658, 704, 930, 977, 306, 673, 386,
    21, 745, 924, 72, 270, 829, 777, 573, 97, 512,
    986, 290, 161, 636, 355, 767, 655, 574, 31, 52,
    350, 150, 941, 724, 966, 430, 107, 191, 7, 337,
    457, 287, 753, 383, 945, 909, 209, 758, 221, 588,
    422, 946, 506, 30, 413, 168, 900, 591, 762, 655,
    410, 359, 624, 537, 548, 483, 595, 41, 602, 350,
    291, 836, 374, 20, 596, 21, 348, 199, 668, 484,
    281, 734, 53, 999, 418, 938, 900, 788, 127, 467,
    728, 893, 648, 483, 807, 421, 310, 617, 813, 514,
    309, 616, 935, 451, 600, 249, 519, 556, 798, 303,
    224, 8, 844, 609, 989, 702, 195, 485, 93, 343,
    523, 587, 314, 503, 448, 200, 458, 618, 580, 796,
    798, 281, 589, 798, 9, 157, 472, 622, 538, 292,
    38, 179, 190, 657, 958, 191, 815, 888, 156, 511,
    202, 634, 272, 55, 328, 646, 362, 886, 875, 433,
    869, 142, 844, 416, 881, 998, 322, 651, 21, 699,
    557, 476, 892, 389, 75, 712, 600, 510, 3, 869,
    861, 688, 401, 789, 255, 423, 2, 585, 182, 285,
    88, 426, 617, 757, 832, 932, 169, 154, 721, 189,
    976, 329, 368, 692, 425, 555, 434, 549, 441, 512,
    145, 60, 718, 753, 139, 423, 279, 996, 687, 529,
    549, 437, 866, 949, 193, 195, 297, 416, 286, 105,
    488, 282, 455, 734, 114, 701, 316, 671, 786, 263,
    313, 355, 185, 53, 912, 808, 832, 945, 313, 756,
    321, 558, 646, 982, 481, 144, 196, 222, 129, 161,
    535, 450, 173, 466, 44, 659, 292, 439, 253, 24,
    154, 510, 745, 649, 186, 313, 474, 22, 168, 18,
    787, 905, 958, 391, 202, 625, 477, 414, 314, 824,
    334, 874, 372, 159, 833, 70, 487, 297, 518, 177,
    773, 270, 763, 668, 192, 985, 102, 480, 213, 627,
    802, 99, 527, 625, 543, 924, 23, 972, 61, 181,
    3, 432, 505, 593, 725, 31, 492, 142, 222, 286,
    64, 900, 187, 360, 413, 974, 270, 170, 235, 833,
    711, 760, 896, 667, 285, 550, 140, 694, 695, 624,
    19, 125, 576, 694, 658, 302, 371, 466, 678, 593,
    851, 484, 18, 464, 119, 152, 800, 87, 60, 926,
    10, 757, 170, 315, 576, 227, 43, 758, 164, 109,
    882, 86, 565, 487, 577, 474, 625, 627, 629, 928,
    423, 520, 902, 962, 123, 596, 737, 261, 195, 525,
    264, 260, 202, 116, 30, 326, 11, 771, 411, 547,
    153, 520, 790, 924, 188, 763, 940, 851, 662, 829,
    900, 713, 958, 578, 365, 7, 477, 200, 58, 439,
    303, 760, 357, 324, 477, 108, 113, 887, 801, 850,
    460, 428, 993, 384, 405, 540, 111, 704, 835, 356,
    72, 350, 823, 485, 556, 216, 626, 357, 526, 357,
    337, 271, 869, 361, 896, 22, 617, 112, 717, 696,
    585, 41, 423, 129, 229, 565, 559, 932, 296, 855,
    53, 962, 584, 734, 654, 972, 457, 369, 532, 963,
    607, 483, 911, 635, 67, 848, 675, 938, 223, 142,
    754, 511, 741, 175, 459, 825, 221, 870, 626, 934,
    205, 783, 850, 398, 279, 701, 193, 734, 637, 534,
    556, 993, 176, 705, 962, 548, 881, 300, 413, 641,
    855, 855, 142, 462, 611, 877, 424, 678, 752, 443,
    296, 673, 40, 313, 875, 72, 818, 610, 17, 932,
    112, 695, 169, 831, 40, 488, 685, 90, 497, 589,
    990, 145, 353, 314, 651, 740, 44, 258, 335, 759,
    192, 605, 264, 181, 503, 829, 775, 608, 292, 997,
    549, 556, 561, 627, 467, 541, 129, 240, 813, 174,
    601, 77, 215, 683, 213, 992, 824, 601, 392, 759,
    670, 428, 27, 84, 75, 786, 498, 970, 287, 847,
    604, 503, 221, 663, 706, 363, 10,
    69, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 2, 416, 452, 8, 262, 233, 
    454, 303, 634, 303, 256, 148, 124, 317, 213, 109, 
    28, 200, 80, 318, 858, 50, 155, 361, 264, 903, 
    676, 643, 909, 902, 561, 489, 948, 282, 653, 674, 
    220, 402, 923, 831, 369, 878, 259, 8, 619, 971, 
    3, 945, 781, 504, 392, 685, 313, 698, 589, 722, 
    938, 37, 410, 461, 234, 508, 961, 959, 493, 515, 
    269, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 29, 971, 3, 945, 781, 504, 
    392, 685, 313, 698, 589, 722, 938, 37, 410, 461, 
    234, 508, 961, 959, 493, 515, 269, 937, 869, 58, 
    700, 971, 264, 117, 215, 555, 815, 330, 39, 212, 
    288, 82, 954, 85, 710, 484, 774, 380, 815, 951, 
    541, 115, 679, 110, 898, 73, 788, 977, 132, 956, 
    689, 113, 8, 941, 790, 723, 363, 28, 184, 778, 
    215, 951, 541, 115, 679, 110, 898, 73, 788, 977, 
    132, 956, 689, 113, 8, 941, 790, 723, 363, 28, 
    184, 778, 200, 71, 885, 974, 71, 333, 867, 153, 
    295, 168, 825, 676, 629, 650, 598, 309, 693, 686, 
    80, 116,82, 90, 35, 28, 77, 52, 70, 88, 19, 71,
    31, 99, 21, 80, 63, 54, 61, 1, 0, 31,10,
      41, 467, 334, 500, 169, 724, 478, 358, 962, 464,
    705, 145, 281, 827, 961, 491, 995, 942, 827, 436,
    391, 604, 902, 153, 292, 382, 421, 716, 718, 895,
    447, 726, 771, 538, 869, 912, 667, 299, 35, 894,
    703, 811, 322, 333, 673, 664, 141, 711, 253, 868,
    547, 644, 662, 757, 37, 859, 723, 741, 529, 778,
    316, 35, 190, 842, 288, 106, 40, 942, 264, 648,
    446, 805, 890, 729, 370, 350, 6, 101, 393, 548,
    629, 623, 84, 954, 756, 840, 966, 376, 931, 308,
    944, 439, 626, 323, 537, 538, 118, 82, 929, 541,
    833, 115, 639, 658, 704, 930, 977, 306, 673, 386,
    21, 745, 924, 72, 270, 829, 777, 573, 97, 512,
    986, 290, 161, 636, 355, 767, 655, 574, 31, 52,
    350, 150, 941, 724, 966, 430, 107, 191, 7, 337,
    457, 287, 753, 383, 945, 909, 209, 758, 221, 588,
    422, 946, 506, 30, 413, 168, 900, 591, 762, 655,
    410, 359, 624, 537, 548, 483, 595, 41, 602, 350,
    291, 836, 374, 20, 596, 21, 348, 199, 668, 484,
    281, 734, 53, 999, 418, 938, 900, 788, 127, 467,
    728, 893, 648, 483, 807, 421, 310, 617, 813, 514,
    309, 616, 935, 451, 600, 249, 519, 556, 798, 303,
    224, 8, 844, 609, 989, 702, 195, 485, 93, 343,
    523, 587, 314, 503, 448, 200, 458, 618, 580, 796,
    798, 281, 589, 798, 9, 157, 472, 622, 538, 292,
    38, 179, 190, 657, 958, 191, 815, 888, 156, 511,
    202, 634, 272, 55, 328, 646, 362, 886, 875, 433,
    869, 142, 844, 416, 881, 998, 322, 651, 21, 699,
    557, 476, 892, 389, 75, 712, 600, 510, 3, 869,
    861, 688, 401, 789, 255, 423, 2, 585, 182, 285,
    88, 426, 617, 757, 832, 932, 169, 154, 721, 189,
    976, 329, 368, 692, 425, 555, 434, 549, 441, 512,
    145, 60, 718, 753, 139, 423, 279, 996, 687, 529,
    549, 437, 866, 949, 193, 195, 297, 416, 286, 105,
    488, 282, 455, 734, 114, 701, 316, 671, 786, 263,
    313, 355, 185, 53, 912, 808, 832, 945, 313, 756,
    321, 558, 646, 982, 481, 144, 196, 222, 129, 161,
    535, 450, 173, 466, 44, 659, 292, 439, 253, 24,
    154, 510, 745, 649, 186, 313, 474, 22, 168, 18,
    787, 905, 958, 391, 202, 625, 477, 414, 314, 824,
    334, 874, 372, 159, 833, 70, 487, 297, 518, 177,
    773, 270, 763, 668, 192, 985, 102, 480, 213, 627,
    802, 99, 527, 625, 543, 924, 23, 972, 61, 181,
    3, 432, 505, 593, 725, 31, 492, 142, 222, 286,
    64, 900, 187, 360, 413, 974, 270, 170, 235, 833,
    711, 760, 896, 667, 285, 550, 140, 694, 695, 624,
    19, 125, 576, 694, 658, 302, 371, 466, 678, 593,
    851, 484, 18, 464, 119, 152, 800, 87, 60, 926,
    10, 757, 170, 315, 576, 227, 43, 758, 164, 109,
    882, 86, 565, 487, 577, 474, 625, 627, 629, 928,
    423, 520, 902, 962, 123, 596, 737, 261, 195, 525,
    264, 260, 202, 116, 30, 326, 11, 771, 411, 547,
    153, 520, 790, 924, 188, 763, 940, 851, 662, 829,
    900, 713, 958, 578, 365, 7, 477, 200, 58, 439,
    303, 760, 357, 324, 477, 108, 113, 887, 801, 850,
    460, 428, 993, 384, 405, 540, 111, 704, 835, 356,
    72, 350, 823, 485, 556, 216, 626, 357, 526, 357,
    337, 271, 869, 361, 896, 22, 617, 112, 717, 696,
    585, 41, 423, 129, 229, 565, 559, 932, 296, 855,
    53, 962, 584, 734, 654, 972, 457, 369, 532, 963,
    607, 483, 911, 635, 67, 848, 675, 938, 223, 142,
    754, 511, 741, 175, 459, 825, 221, 870, 626, 934,
    205, 783, 850, 398, 279, 701, 193, 734, 637, 534,
    556, 993, 176, 705, 962, 548, 881, 300, 413, 641,
    855, 855, 142, 462, 611, 877, 424, 678, 752, 443,
    296, 673, 40, 313, 875, 72, 818, 610, 17, 932,
    112, 695, 169, 831, 40, 488, 685, 90, 497, 589,
    990, 145, 353, 314, 651, 740, 44, 258, 335, 759,
    192, 605, 264, 181, 503, 829, 775, 608, 292, 997,
    549, 556, 561, 627, 467, 541, 129, 240, 813, 174,
    601, 77, 215, 683, 213, 992, 824, 601, 392, 759,
    670, 428, 27, 84, 75, 786, 498, 970, 287, 847,
    604, 503, 221, 663, 706, 363, 10,
    69, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 2, 416, 452, 8, 262, 233, 
    454, 303, 634, 303, 256, 148, 124, 317, 213, 109, 
    28, 200, 80, 318, 858, 50, 155, 361, 264, 903, 
    676, 643, 909, 902, 561, 489, 948, 282, 653, 674, 
    220, 402, 923, 831, 369, 878, 259, 8, 619, 971, 
    3, 945, 781, 504, 392, 685, 313, 698, 589, 722, 
    938, 37, 410, 461, 234, 508, 961, 959, 493, 515, 
    269, 937, 869, 58, 700, 971, 264, 117, 215, 555, 
    815, 330, 39, 212, 288, 82, 954, 85, 710, 484, 
    774, 380, 815, 951, 541, 115, 679, 110, 898, 73, 
    788, 977, 132, 956, 689, 113, 8, 941, 790, 723, 
    363, 28, 184, 778, 29, 971, 3, 945, 781, 504, 
    392, 685, 313, 698, 589, 722, 938, 37, 410, 461, 
    234, 508, 961, 959, 493, 515, 269, 937, 869, 58, 
    700, 971, 264, 117, 215, 555, 815, 330, 39, 212, 
    288, 82, 954, 85, 710, 484, 774, 380, 815, 951, 
    541, 115, 679, 110, 898, 73, 788, 977, 132, 956, 
    689, 113, 8, 941, 790, 723, 363, 28, 184, 778, 
    215, 951, 541, 115, 679, 110, 898, 73, 788, 977, 
    132, 956, 689, 113, 8, 941, 790, 723, 363, 28, 
    184, 778, 200, 71, 885, 974, 71, 333, 867, 153, 
    295, 168, 825, 676, 629, 650, 598, 309, 693, 686, 
    80, 116,82, 90, 35, 28, 77, 52, 70, 88, 19, 71,
    31, 99, 21, 80, 63, 54, 61, 1, 0, 31,10,    
};

    int n50 = sizeof(array50) / sizeof(array50[0]);
    printf("tableau de 50 elements : " );
    bubbleSort(array50,n50);

    int n100 = sizeof(array100) / sizeof(array100[0]);
    printf("tableau de 100 elements : " );
    bubbleSort(array100,n100);

    int n200 = sizeof(array200) / sizeof(array200[0]);
    printf("tableau de 200 elements : " );
    bubbleSort(array200,n200);

    int n500 = sizeof(array500) / sizeof(array500[0]);
    printf("tableau de 500 elements : " );
    bubbleSort(array500,n500);

    int n1000 = sizeof(array1000) / sizeof(array1000[0]);
    printf("tableau de 1000 elements : " );
    bubbleSort(array1000,n1000); 

    int n1500 = sizeof(array1500) / sizeof(array1500[0]);
    printf("tableau de 1500 elements : " );
    bubbleSort(array1500,n1500);

    int n = sizeof(array) / sizeof(array[0]);
    printf("tableau de 2500 elements : " );
    bubbleSort(array,n);
    
    return 0;
}




