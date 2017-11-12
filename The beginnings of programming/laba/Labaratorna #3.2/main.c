#include <stdio.h>
#include <conio.h>

void Inputing (int);
void Output ();
void Sorting (int);

FILE *Inpute;

int main()
{
    const int N=20;
    Inputing (N);
    Output ();
    printf("\nNew FILE coming... Press Enter\n");
    _getch();
    system ("cls");
    Sorting (N);
    printf("New FILE:\n");
    Output ();

    return 0;
}

void Inputing (int x){
    int c,j,i;
    if((Inpute=fopen("Inpute.dat","wb"))==NULL){
        perror("Inpute.dat");
        printf("ERROR");
    }
        for (j=0;j<(x/20);j++){
    for (i=1;i<=10;i++)
        {
           c = ((i+1) * 12*i);
           fwrite(&c,sizeof(c),1,Inpute);
        }
    for (i=1;i<=10;i++)
        {
            c = -((i+1)*12*i);
            fwrite(&c,sizeof(c),1,Inpute);
        }
        }
    fclose(Inpute);
}

void Output (){
    int c;
    if((Inpute=fopen("Inpute.dat","rb"))==NULL){
        perror("Inpute.dat");
        printf("ERROR");
    }
    while (fread(&c,sizeof(int),1,Inpute)){
        printf(" %d\n",c);
    }
    fclose(Inpute);
}

void Sorting (int x){
    int a[10],c,j,i;
    if((Inpute=fopen("Inpute.dat","rb+"))==NULL){
        perror("Inpute.dat");
        printf("ERROR");
    }
    for (j=0;j<x;j+=20){
        fseek(Inpute,j*4+20,SEEK_SET);
        for (i=0;i<10;i++)
        {
            fread(&c,sizeof(int),1,Inpute);
            a[i]=c;
        }
        fseek(Inpute,j*4 + 40,SEEK_SET);
        for (i=0;i<5;i++){
            c=a[i];
            fwrite(&c,sizeof(int),1,Inpute);
        }

        fseek (Inpute,j*4 + 20,SEEK_SET);
        for (i=5;i<10;i++){
            c=a[i];
            fwrite(&c,sizeof(int),1,Inpute);
        }
   }
    fclose(Inpute);
}
