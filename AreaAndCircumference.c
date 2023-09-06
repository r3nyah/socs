#include<stdio.h>

//Circumference of circle
int main()
{
    float r;
    float a;
    float c;
    printf("enter radius : ");
    scanf("%f", &r);
    a = 3.14*r*r;
    c = 2*3.14*r;
    printf("Area = %f\ncircumference = %f\n",a,c);
    return 0;
}
