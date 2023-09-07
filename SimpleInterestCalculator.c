#include <stdio.h>

int main(){
	float PrincipleAmount;
	float Rate;
	float Time;
	float SimpleInterest;
	
	printf("Enter principal amount, Rate of interest and time Respectively : ");
	scanf("%f%f%f", &PrincipleAmount, &Rate, &Time);
	SimpleInterest = (PrincipleAmount * Rate * Time) / 100;
	printf("Simple Interset is : %f", SimpleInterest);
	return (0);
}
