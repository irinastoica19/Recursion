#include <stdio.h>
#include <stdbool.h>
#define ROWS 20
#define COLUMNS 20

void printSolution(int i, int j, int trace[i][j]);

int main() {
    int m, n;
    int i, j;
    int t;
    printf("Enter the number of rows:");
    scanf("%d", &m);
    printf("Enter the number of columns:");
    scanf("%d", &n);
    int labyrinth[ROWS][COLUMNS];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            labyrinth[i][j] == 1;
        }
    }
    int trace[ROWS][COLUMNS];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++)
            trace[i][j]=0;
    }
    printf("Enter the initial coordinates\nRow:");
    scanf("%d", &i);
    printf("Column:");
    scanf("%d", &j);

    printSolution(m, n, trace[i][j]);

    return 0;
}

bool solveLabyrinth(int i, int m, int j, int n, int trace[m][n], int labyrinth[i][j]){
    if(i == m - 1 || j == n - 1 || i == 0 || j == 0){
        trace[i][j]==1;
        return true;
    }
    if(i >= 0 && j >= 0 && i <= m-1 && j <= n-1 && labyrinth[i][j]==1 && trace[i][j]==0){

    }

}
void printSolution(int m, int n, int trace[m][n]){
    for(int i=0; i<m; i++) {
        for (int j = 0; j<n; j++)
            printf("&d", &trace[i][j]);
        printf("\n");
    }
    printf("\n--------------\n");
}
