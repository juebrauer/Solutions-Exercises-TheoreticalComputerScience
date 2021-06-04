#include <stdio.h>
#include <stdlib.h> // for system()

#define N 16

void set_cursor(int x, int y)
{
    printf("\033[%d;%dH",y+1,x+1);
}



int size[] = { 3,4,7,8 };
int gain[] = { 4,5,10,11 };
int best[N];
int item[N];
int m = 4;

void knapsack(int n)
{
    system("clear");
    int i, j, tmp;

    // initialize arrays with zeros
    for (int j=0; j<=n; j++)
    {
        best[j] = 0;
        item[j] = 0;
    }


    // print column headers
    for (int i = 0; i < m; i++)
    {
        set_cursor(10 + i * 10, 0);
        printf("i=%d", i);
    }


    // the algorithm
    // solving the Rucksack problem with dynamic programming
    for (i = 0; i < m; i++) {
        for (j = 0; j <= n; j++) {

            set_cursor(0, 1+j);
            printf("j=%d", j);
            
            if (j - size[i] >= 0) { // passt der i-te Gegenstand noch rein?
                tmp = best[j - size[i]]; 
                tmp += gain[i];
                if (tmp >= best[j]) {
                    best[j] = tmp;
                    item[j] = i;
                } // if
            } // if

            set_cursor(10 + i * 10, 1+j);
            printf("%d,%d", best[j], item[j]);
        } // for
    } // for

} // func knapsack



int main()
{
    knapsack(N);

    printf("\n\nOptimal packing of the knapsack is:\n");
    for (int j = N; j >= 3; j -= size[item[j]])
        printf("%d ", item[j]);
    printf("\n");
}