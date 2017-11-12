#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *Text;
    int count=0;
    char c,x;

    if((Text=fopen("Text.txt","r"))==NULL){
        perror("Text.txt");
        printf("ERROR");
        return 0;
        }
        if (feof(Text)) printf("File is empty");
        while (fread(&c,sizeof(c),1,Text)){
            if (c == 'a') {
                    fread(&x,sizeof(x),1,Text);
                    if (x == 'b') count++;
            }
            if (c == 'A') {
                    fread(&x,sizeof(x),1,Text);
                    if (x == 'B') count++;
            }
        }
    fclose(Text);

    printf("Value AB || ab = %d;",count);

    if((Text=fopen("Text.txt","a"))==NULL){
        perror("Text.txt");
        printf("ERROR");
        return 0;
        }
        switch (count){
        case 1: fprintf(Text,"One");
                break;
        case 2: fprintf(Text,"Two");
                break;
        case 3: fprintf(Text,"Tree");
                break;
        case 4: fprintf(Text,"Four");
                break;
        case 5: fprintf(Text,"Five");
                break;
        case 6: fprintf(Text,"Six");
                break;
        case 7: fprintf(Text,"Seven");
                break;
        case 8: fprintf(Text,"Eight");
                break;
        case 9: fprintf(Text,"Nine");
                break;
        case 10: fprintf(Text,"Ten");
                break;
        default:fprintf(Text,"Empty");
        }

    fclose(Text);
    printf("\nValue inputed in file\n");
}

