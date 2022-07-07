#include <stdio.h>
#include <stdlib.h>
struct complex
{
    double im;
    double re;
}a,b,c;
struct complex sum(struct complex a, struct complex b)
{
    struct complex c;
    c.im = a.im + b.im;
    c.re = a.re + b.re;
    return c;
}
struct complex dif(struct complex a, struct complex b)
{
    struct complex c;
    c.im = a.im - b.im;
    c.re = a.re - b.re;
    return c;
}
struct complex conj(struct complex a)
{
    a.im = -a.im;
    return a;
}
struct complex prod(struct complex a, struct complex b)
{
    struct complex c;
    c.im = a.re * b.im + a.im * b.re;
    c.re = a.re * b.re - a.im * b.im;
    return c;
}
double mod(struct complex a)
{
    return a.im*a.im + a.re*a.re;
}
double energy(struct complex z[], int n, int m)
{
    int i,p=0;
    double w=0;
    for(i=0;i<m;i++)
        w=w+mod(z[i]);
    double max=w;
    for(i=0;i<n-1;i++)
    {
        w=w+mod(z[(m+i)%n])-mod(z[i]);
        if(max<w)
        {
            max=w;
            p=i+1;
        }
    }
    for(i=0;i<m;i++)
        printf("%lf %lf\n",z[p+i].re, z[p+i].im);
    printf("%lf\n", max);
}
int main()
{/*
    a.im=2;
    a.re=3;
    b.im=4;
    b.re=1;
    c=sum(a,b);
    printf("%lf %lf\n",c.re,c.im);
    c=dif(a,b);
    printf("%lf %lf\n",c.re,c.im);
    c=conj(a);
    printf("%lf %lf\n",c.re,c.im);
    c=prod(a,b);
    printf("%lf %lf\n",c.re,c.im);
    c.re=mod(a);
    printf("%lf %lf\n",c.re,c.im);
    */
    int n,m,i;
    scanf("%d",&n);
    do
    {
        struct complex z[n];
        for(i=0;i<n;i++)
            scanf("%lf %lf",&z[i].re,&z[i].im);
        scanf("%d",&m);
        energy(z,n,m);
        scanf("%d",&n);
    }while(n);
    return 0;
}
