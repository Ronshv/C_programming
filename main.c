#include<stdio.h>
#include"my_mat.h"

int main()
{
    int i, j;
    char request;
    printf("A) enter values for matrix initiallization");
    printf("B) insert some i, j points to check for an existing path");
    printf("C) insert i,j once again in order to find the shortest path from point i to j");
    while (1)
    {
        request = getchar();
        switch (request)
        {
        case 'A':
            Mat_Creator();

        case 'B':
            scanf("%d %d", &i, &j);   //getting two required points from user
            Floyd_Varshell_T_or_F(i, j);

        case 'C':
            scanf("%d %d", &i, &j);
            int shortest = Floyd_Varshell_evaluating_shortest_path(i, j);
            printf("the path is of size:%d ", shortest);

        case 'D':
            printf(""you should exit"");
            break;

        }
    }

    return 0;
}