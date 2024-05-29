/*matrix chain multiplication
write a program to take input to chain input of matrix
1. matrix chain order
2. print optimal parens
3. to display the parenthesisation of chain of matrix also display the m table and s table
*/
 //implementation of matrix chain multiplication
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void print_optimal_parens(int s[][100],int i,int j){
    if(i == j){
        printf("A%d",i);
    }
    else{
        printf("(");
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j] + 1,j);
        printf(")");
    }

}

void matrix_chain_order(int p[],int n){
    int m[100][100];
    int s[100][100];
    for(int i=1; i <= n; i++){
        m[i][i] = 0;
    }
    for(int l=2; l <= n; l++){
        for(int i=1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k=i; k <= j - 1; k++){
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nM Table\n");
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\nS Table\n");
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal Parenthesisation\n");
    print_optimal_parens(s,1,n);  
}

int main(){
    int n;
    printf("\nEnter The Number Of Matrices\n");
    scanf("%d",&n);
    int p[n + 1];
    printf("\nEnter The Dimensions Of Matrices\n");
    for(int i=0; i <= n; i++){
        scanf("%d",&p[i]);
    }
    matrix_chain_order(p,n);
    return 0;
}