#include <stdio.h>
#include <stdbool.h>
#define ROWS 20
#define COLUMNS 20

void printSolution(int m, int n, int trace[m][n]);
void solveLabyrinth(int i, int m, int j, int n, int t, int labyrinth[i][j], int trace[m][n]);
int possible(int i,int j, int m, int n, int labyrinth[i][j], int trace[i][j]);

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
            labyrinth[i][j] = 1;
        }
    }
    int trace[ROWS][COLUMNS];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            trace[i][j]=0;
    }
    printf("Enter the initial coordinates\nRow:");
    scanf("%d", &i);
    printf("Column:");
    scanf("%d", &j);
    solveLabyrinth(i, m, j, n, t, labyrinth, trace);
    return 0;
}
int possible(int i,int j, int m, int n, int labyrinth[i][j], int trace[i][j])
{
    return (i >= 0 && j >= 0 && i <= m-1 && j <= n-1 && labyrinth[i][j]==1 && trace[i][j]==0);
}
void solveLabyrinth(int i, int m, int j, int n, int t, int labyrinth[i][j], int trace[m][n]){
    trace[i][j]=t;
    int move1[]={-1, 0, 1, 0};
    int move2[]={0, 1, 0, -1};
    if(i == m - 1 || j == n - 1 || i == 0 || j == 0){
        trace[i][j]=1;
        printSolution(m, n, trace);
    }
    else{
       for(int k=0; k<4; k++){
           if(possible(i+move1[k],j+move2[k], m, n, labyrinth, trace))
               solveLabyrinth(i+move1[k],m,j+move2[k],n, t+1, labyrinth, trace);
       }
   }
    trace[i][j]=0;
}
void printSolution(int m, int n, int trace[m][n]){
    for(int i=0; i<m; i++) {
        for (int j = 0; j<n; j++)
            printf("%d", trace[i][j]);
        printf("\n");
    }
    printf("\n--------------\n");
}