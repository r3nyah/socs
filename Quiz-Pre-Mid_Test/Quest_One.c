#include <stdio.h>

/*
	Name
	Nim
	Question Number 1 - Selection
*/
int PosNegNumb();
void Grade();
int LarNumb();

void main(){
	int answer;
	printf("Menu Navigasi");
	printf("\n1. Positive or Negative");
	printf("\n2. Grading");
	printf("\n3. Largest Menu");
	printf("\nPilihan Menu: ");
	scanf("%d",&answer);
	
	switch(answer){
		case 1:
			PosNegNumb();
			break;
		case 2:
			Grade();
			break;
		case 3:
			LarNumb();
			break;
		default:
			break;
	}
}

int PosNegNumb(){
	int numA,numB,numC,resABC;
	
	printf("Masukan 3 Angka: ");scanf("%d %d %d",&numA,&numB,&numC);
	if(numA < 0){
		resABC += 1;
		//printf("numA adalah bilangan negatif");
	}if(numB < 0){
		resABC += 1;
		//printf("numA adalah bilangan negatif");
	}if(numC < 0){
		resABC += 1;
		//printf("numA adalah bilangan negatif");
	}
	
	printf("%d angka negatif",resABC);
	return 0;
}

void Grade(){
	int numA;
	
	printf("Masukan nilai: ");scanf("%d",&numA);
	if(numA < 101 && numA > 84){
		printf("Grade A");
	}
	else if(numA < 71 && numA > 83){
		printf("Grade B");
	}
	else if(numA < 70 && numA > 64){
		printf("Grade C");
	}
	else if(numA < 65 && numA > 49){
		printf("Grade D");
	}
	else if(numA < 50 && numA >= 0){
		printf("Grade E");
	}
	else{
			
	}
	
}

int LarNumb(){
	int numA,numB,numC,resABC;
	
	printf("Masukan 3 Angka: ");scanf("%d %d %d",&numA,&numB,&numC);
//	if(numA > numB){
//		resABC = numA;
//		printf("%d", resABC);
//	}else if(numA > numC){
//		resABC = numA;
//		printf("%d", resABC);
//	}else if(numB > numA){
//		resABC = numB;
//		printf("%d", resABC);
//	}else if(numB > numC){
//		resABC = numB;
//		printf("%d", resABC);
//	}else if(numC > numA){
//		resABC = numC;
//		printf("%d", resABC);
//	}else if(numC > numB){
//		resABC = numC;
//		printf("%d", resABC);
//	}else{
//		
//	}
	if(numA > numB && numA > numC){
		resABC = numA;
		printf("%d", resABC);
	}else if(numB > numA && numB > numC){
		resABC = numB;
		printf("%d", resABC);
	}else if(numC > numA && numC > numA){
		resABC = numC;
		printf("%d", resABC);
	}
	
	return 0;
}
