#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

void gotoxy (int row, int col)

{
printf("\033[%d;%dH", row, col);
}

int main()
{
    int p,i,j;
    const int M=80, N=25;
    const int d=1;

    system("cls");
    for (p=1; p<=(N-1)/2; p++) {
        for (i=p+1; i<=N-1-p; i++){
            gotoxy(i,M-1-p);
            printf("*%");
            usleep(d);}

        for (j=M-2-p; j>=p; j--){
            gotoxy(N-1-p,j);
            printf("*%");
            usleep(d);}

        for (i=N-1-p; i>=p+1; i--){
            gotoxy(i,p);
            printf("*%");
            usleep(d);}

        for (j=p; j<=M-1-p; j++) {
            gotoxy(p,j);
            printf("*%");
            usleep(d);}
        }
    getch();
    system("pause");

  return 0;
}
