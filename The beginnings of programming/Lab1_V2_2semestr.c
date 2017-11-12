#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fout;
int i,count=1;
float component=0,max;

int main()
{
    Zapovnennya();
    MaxValue();

    return 0;
}

void Zapovnennya()
{
    if((fout=fopen("fout.dat","wb"))==NULL){
        perror("fout.dat");
        printf("ERROR");
        return 0;
    }

    for (i=1;i<10;i++){
        component = sqrt(3*i+component);
        fwrite(&component,sizeof(component),1,fout);
    }
    fclose(fout);

    printf("Components in file:\n");

    if ((fout=fopen("fout.dat","rb"))==0){
        perror("fout.dat");
        printf("ERROR");
        return 0;
    }

    while (fread(&component,sizeof(component),1,fout)) printf("%f \n", component);
    fclose(fout);
    printf("________________________________\n");
}

void MaxValue()
{
    if ((fout=fopen("fout.dat","rb"))==0){
        perror("fout.dat");
        printf("ERROR");
        return 0;
    }

    fread(&max,sizeof(max),1,fout);
    while(fread(&component,sizeof(component),1,fout)){
            count++;
       if (!(count % 2==0) && (abs(component) >= abs(max))) max = component;
    }
    fclose(fout);
    printf("\nMax value in file = %f\n",max);
}
