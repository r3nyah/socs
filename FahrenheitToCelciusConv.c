#include <stdio.h>

int main(){
	float c;
	float f;
	
	printf("Enter temperature in Fahrenheit : \n");
	scanf("%f", &f);
	c = (f-32) * 5/9;
	printf("Temperature in Celcius is : %f", c);
	
	return(0);
}
