#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int M=4,N=3;
    int i,j,x,k,L,R;
    int A[M][N];

    printf("Inpute array:\n");
    for(i=0;i<M;i++){
        for (j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }

    printf("What \"X\" u need find?\nX = ");
    scanf("%d",&x);

    system("cls");

    printf("U finding X = %d \n",x);
    printf("\nYour array:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%*d",3,A[i][j]);
        }
        printf("\n");
    }
    printf("_______________________\n");

    for (j=0;j<N;j++){
        for(i=0;i<M;i++){
            L=0;
            R=M-1;

            while (L<R){
                k=(L+R)/2;
                if (A[k][j]>x) L=k+1;
                else L=k+1;
            }
        }
        if (A[R][j]==x) printf("Element found in %d column with coord:[%d] [%d] \n",j,R,j);
        else printf("Element not found in column %d \n",j);
    }
    return 0;
}

