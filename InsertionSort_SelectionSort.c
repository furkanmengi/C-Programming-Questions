#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

// Insertion Sort
void insertionSort(int dizi[], int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = dizi[i];
        j = i - 1;

        while(j >= 0 && dizi[j] > key)
        {
            dizi[j + 1] = dizi[j];
            j--;
        }

        dizi[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int dizi[], int n)
{
    int i, j, minIndex, temp;

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(dizi[j] < dizi[minIndex])
            {
                minIndex = j;
            }
        }

        temp = dizi[i];
        dizi[i] = dizi[minIndex];
        dizi[minIndex] = temp;
    }
}

int main()
{
    int X[SIZE], A[SIZE], B[SIZE];
    int i;

    srand(time(NULL));

    // 0-1000 arası rastgele sayı üret
    for(i = 0; i < SIZE; i++)
    {
        X[i] = rand() % 1001;
        A[i] = X[i];
        B[i] = X[i];
    }

    clock_t start, end;

    // Insertion Sort süresi
    start = clock();
    insertionSort(A, SIZE);
    end = clock();

    double insertionTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    // Selection Sort süresi
    start = clock();
    selectionSort(B, SIZE);
    end = clock();

    double selectionTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort Suresi: %f saniye\n",
           insertionTime);

    printf("Selection Sort Suresi: %f saniye\n",
           selectionTime);

    return 0;
}
