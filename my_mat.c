/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
#include <stdbool.h>

int adj[10][10];
int INF = (int)1e7;

void Mat_Creator()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
                if (adj[i][j] >= 0)
                {
                    printf("the values you're entering should be valid");
                    scanf("%d", &adj[i][j]);
                }

            

        }
    }
}
int Floyd_Varshell_T_or_F(int i, int j)
{
    
    bool flag = 0;
    for (int g = 0; g < 10; g++)
    {
        adj[g][g] = 0;
    }

    for (int k = 0; k < 10; k++)
    {
        for (int g = 0; g < 10; g++)
        {
            for (int v = 0; v < 10; j++)
            {
                if (adj[g][v] > adj[g][k] + adj[k][v])
                {
                    adj[g][v] = adj[g][k] + adj[k][v];

                }
            }
        }
    }


    if (adj[i][j] != INF)
    {
        flag = 1;
    }
    return flag;
}

int Floyd_Varshell_evaluating_shortest_path(int i, int j)
{
    
    int shortestPath[10][10];
    for (int s = 0; s < 10; s++)
    {
        adj[s][s] = 0;
    }
    for (int s = 0; s < 10; s++) {
        for (int d = 0; d < 10; d++) {
            if (adj[s][d] == INF) {
                shortestPath[s][d] = -1;
            }
            else {
                shortestPath[s][d] = d;
            }
        }
    }

    for (int k = 0; k < 10; k++)
    {
        for (int m = 0; m < 10; m++)
        {
            for (int l = 0; l < 10; l++)
            {
                if (adj[m][l] > adj[m][k] + adj[k][l]) {
                    adj[m][l] = adj[m][k] + adj[k][l];
                    shortestPath[m][l] = shortestPath[m][k];
                }
            }
        }
    }
    int a[10];
    int temp = 0;
    a[temp] = i;
    temp++;
    if (shortestPath[i][j] == -1) {
        return -1;
    }
    else if (i == j) {
        return -1;
    }
    else {
        while (i != j) {
            i = shortestPath[i][j];
            a[temp] = i;
            temp++;
        }
        
    }
    printf("this sp is: %d",  temp - 1);
    return temp- 1;
}

int main()
{

    return 0;
}

