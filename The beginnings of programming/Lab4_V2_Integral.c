#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

float integral (float (*func)(float), float a, float b, float e);
float f(float x);

int main()
{
    system ("color 2");
    float a=0;
    float b=M_PI;
    float accurancy=0.00001;
    float I;
    I = integral(f, a, b, accurancy);
    printf ("A=%.0f, B=%.3f, Integral=%f\n", a, b, I);
    return 0;
}

float integral (float (*func)(float), float a, float b, float e)
{
    int n=1;
    float h, i, s=0, s1=0;
    do
    {
        s1=s;
        s=0;
        n=n*2;
        h=(b-a)/n;
        for (i=0; i<=n; i++)
            if ((i==0) || (i==n))
                s=s+0.5*func(a+i*h);
            else s=s+func(a+i*h);
        s=s*h;
    } while (fabs (s1-s)>3*e);
    return s;
}

float f(float x)
{
    float f=0;
    f=exp(x)*sin(x);
    return f;
}
