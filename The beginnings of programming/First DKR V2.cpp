#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    bool flag = true;
    bool number = false;
    bool ch = true;
    char str[80];
    int c = 0;
    cout<<"Enter string: ";
    cin.getline(str, 80);
    int k = strlen(str);
    for(int i = 0; i<k; i++)
    {
       if(!(((str[i]>='a') && (str[i]<='z')) || ((str[i]>='A') && (str[i]<='Z')) || (str[i]=='_') || ((str[i]>='0') && (str[i]<='9'))||(str[i] == ',') || (str[i]== '.')))
       {
           flag = false;
           cout<<"Error";
           break;
       }
    }

    if(flag == true)
    {
        if((str[0]=='_') || ((str[0]>='a') && (str[0]<='z' )) || ((str[0]>='A') && (str[0]<='Z')))
        {
        cout<<"Identificator";
        }
        else
        {
            if(str[0]>='0' && str[0]<='9')
            {
                for(int i = 1; i<k; i++)
                {
                    if((str[i] >='0' && str[i]<='9') || (str[i] == ',') || (str[i]== '.'))
                    {
                        if(str[i]=='.' || str[i]==',')
                            c++;
                        number = true;
                    }
                }
                if(c>1)
                        ch = false;
                    else
                        ch = true;

                if(number == true && ch == true)
                    cout<<"Chislo";
                else
                    cout<<"Error";
            }
            else
                cout<<"Error";
        }
    }
	_getch();
    return 0;
}
