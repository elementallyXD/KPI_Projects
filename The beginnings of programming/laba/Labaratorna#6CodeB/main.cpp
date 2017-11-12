#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main()
{
	bool flag, flag2 = true;
	char str[255], B;
	int i = 0,j,k,R,t;

	cin.getline(str, 255);
	do{
        j = 0;
		while (isalnum(str[i])) {

			if (islower(str[i])){
				flag = true;
				i++;
				j++;}

			else{
				flag = false;

                while (isalnum(str[i])){
					i++;}

				break;}
		}

		if (flag)
		{
			k = i - j;
			while (k < i - 1)
			{
				if (str[k] <= str[k + 1]) flag2 = true;
                else{
                        flag2 = false;
                        break;
                    }
				k++;
			}
        }

		if (!(flag2))
		{   //Sort by exchange
			for (R=i-1;R>=i-j+1;R--){
                for (t=i-j;t<=R-1;t++){
                    if (str[t] <= str[t+1]){
                        B=str[t];
                        str[t]=str[t+1];
                        str[t+1]=B;}
                }
			}
		}

        for (k = i - j; k < i; k++){
			cout << str[k];}

		if (str[i] == ' '){
			i++;}

		cout << " ";
} while (str[i]!= '\0');

	_getch();
	return 0;
}
