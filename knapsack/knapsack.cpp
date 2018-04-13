#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define N 99

void set_cursor(int x, int y)
{
    //Initialize the coordinates
    COORD coord = { x, y };
    //Set the position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} // set_cursor_position


int size[] = { 3,4,7,8 };
int gain[] = { 4,5,10,11 };
int best[N];
int item[N];
int m = 4;

void knapsack(int n)
{
    system("cls");
    int i, j, tmp;

    for (int i = 0; i < m; i++)
    {
        set_cursor(10 + i * 10, 0);
        printf("i=%d", i);
    }

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
    _getch();        
}