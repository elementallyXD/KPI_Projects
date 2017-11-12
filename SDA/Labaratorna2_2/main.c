#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int M=3,N=4;
    int i,j,k,B,g;
    int A[M][N];

    printf("Inpute array:\n");
    for(i=0;i<M;i++){
        for (j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }

    system("cls");

    printf("\nYour array:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%*d",3,A[i][j]);
        }
        printf("\n");
    }
    printf("_______________________\n");

    for (i=0;i<M;i++){
        for (j=1;j<N;j++){
            B=A[i][j];
            g=j;
            while ((g>=1)&&(B>A[i][g-1])){
                A[i][g]=A[i][g-1];
                g-=1;
            }
            A[i][g]=B;
        }
    }

    printf("\nSorted array:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%*d",3,A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
