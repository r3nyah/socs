#include <stdio.h>

int main(){
	int n1,n2;
	int addition;
	int subtraction;
	int multiplication;
	int division;
	int modulo;
	
	printf("Enter two numbers :\n");
   	scanf("%d%d", & n1, & n2);
	addition = n1 + n2;
	subtraction = n1 - n2;
	multiplication = n1 * n2;
	division = n1 / n2;
	modulo = n1 % n2;
	
	printf("Addition of number one and number 2 : %d\n", addition);
	printf("Subtraction of number one and number 2 : %d\n", subtraction);
	printf("Multiplication of number one and number 2 : %d\n", multiplication);
	printf("Division of number one and number 2 : %d\n", division);
	printf("Modulo of number one and number two : %d\n", modulo);
	
	return (0);
}
