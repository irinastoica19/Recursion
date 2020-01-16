#include <stdio.h>

int recursiveH(int n, int x);
int nonRecursiveH(int n, int x);

int main() {
    int n;
    int x;
    int result;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter x:\n");
    scanf("%d", &x);
    printf("Recursive Method:\n");
    for (int i=0; i<=n; i++){
        result=recursiveH(i,x);
        printf("H%d(%d) = %d\n", i, x, result);
    }
    printf("Non-Recursive Method:\n");
    for (int i=0; i<=n; i++){
        result=nonRecursiveH(i,x);
        printf("H%d(%d) = %d\n", i, x, result);
    }
    return 0;
}

int recursiveH(int n, int x){
    if (n<0)
        return -1;
    if (n==0)
        return 1;
    if (n==1)
        return 2*x;
    if (n>1)
        return (2*x*recursiveH(n-1, x) - 2*(n-1)*recursiveH(n-2, x));

}

int nonRecursiveH(int n, int x){
    if(n<0)
        return -1;
    if(n==0)
        return 1;
    if(n==1)
        return 2*x;
    if(n>1) {
        int result;
        int start1 = 2*x;
        int start2 = 1;
        for (int i=2; i<=n; i++) {
            result = 2*x*start1 - 2*(i-1)*start2;
            start2 = start1;
            start1 = result;
        }
        return result;
    }
}