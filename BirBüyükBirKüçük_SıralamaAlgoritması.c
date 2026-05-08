#include <stdio.h>

void sirala(int dizi[], int n)
{
    int i, j, temp;

    // Büyükten küçüğe sıralama
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(dizi[i] < dizi[j])
            {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }

    // Bir büyük bir küçük dizme
    int sonuc[n];
    int sol = 0;
    int sag = n - 1;
    int index = 0;

    while(sol <= sag)
    {
        if(sol <= sag)
        {
            sonuc[index++] = dizi[sol++];
        }

        if(sol <= sag)
        {
            sonuc[index++] = dizi[sag--];
        }
    }

    printf("Yeni Dizi:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", sonuc[i]);
    }
}

int main()
{
    int dizi[] = {60,80,3,9,57,11};
    int n = 6;

    sirala(dizi, n);

    return 0;
}
