#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double eps=pow(10,-3);
long double h,runge=1,a=0,b=3.14,summ1=0,summ2=0,func,x,x1,xnew;
int N=100000,i=1;

double func_math(double xnewf)
{
    return func=exp(xnewf)*sin(xnewf);
}

long double first_integral(double krok,double functionx)
{
    if(i==1)
    {
        summ1+=0.5*functionx;
        i++;
        xnew=a+i*krok;
        first_integral(h,func_math(xnew));
    }
    else
    {
        if(i==N)
        {
            summ1+=0.5*func;
            i=1;
            return summ1*h;
        }
        else
        {
            if(i<=N)
            {
                i++;
                summ1+=func;
                xnew=a+i*krok;
                func_math(xnew);
                first_integral(h,xnew);
            }
        }
    }
}

long double second_integral(double krok,double functionx)
{
     //double xnew;
      if(i==1)
    {
        summ2+=0.5*functionx;
        i++;
        x=a+i*h;
        second_integral(h,functionx);
    }
    else
    {
        if(i==N)
        {
            summ2+=0.5*func;
            i=1;
            return summ2*h;
        }
        else
        {
            if(i<=N)
            {
                i++;
                summ2+=func;
                xnew=a+i*h;
                func_math(xnew);
                second_integral(h,xnew);
            }
        }
    }
}

int main()
{

    h=(b-a)/N;
    x=a+i*h;
    x1=a+i*h;
    func_math(x);
    while(runge>=eps)
    {
        summ1=0;summ2=0;
        first_integral(h,func_math(x));
        second_integral(2*h,func_math(x1));
        runge=(summ1*h-summ2*h)/3;
        if(runge>=eps)
        {
            N*=2;
        }
    }

        printf("Integral= %f",runge);
    return 0;
}
