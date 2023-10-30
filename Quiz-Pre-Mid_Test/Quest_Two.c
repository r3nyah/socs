#include <stdio.h>
/*
	Name
	Nim
	Question Number 2 - Repeatition
*/
void jajargenjang();
void segitigaprima();
int iniprima();

void main(){
	int answer;
	printf("Masukan angka 1 atau 2");
	printf("\nPerulangan Jajar Genjang");
	printf("\nPerulangan Segitiga Prima");
	printf("\nJawaban disini : ");
	scanf("%d",&answer);
	switch(answer){
		case 1:
			jajargenjang();break;
		case 2:
			segitigaprima();break;
		default:
			break;
	}
}

void jajargenjang(){
	int baris;
	int kolom;
	printf("Masukan panjang baris ");scanf("%d",&baris);
	printf("Masukan panjang kolom ");scanf("%d",&kolom);
	printf("Jajargenjang: \n\n");
	for(int b = 0; b < baris; b++){
        for(int s = 0; s < b;s++){
            printf(" ");
        }

        for(int k = 0; k < kolom; k++){
            printf("*");
        }

        printf("\n");
    }
    printf("\n");
}

void segitigaprima(){
	/*
	prima : 2 3 5 7 11 13 17 19 23 31 37 41 43 47 53 59 61 67 71 73
	*/
	int tinggi;
	printf("Masukan tinggi segitiga ");scanf("%d",&tinggi);
	printf("Segitiga Prima: \n\n");

	if(tinggi <= 0){
		printf("Gagal, Coba masukan angka lain.\n");
	}else{
		int angka_saat_ini = 2;
		for(int i = 1; i <= tinggi; i++){
			for(int j = 1; j <= i; j++){
				while(!iniprima(angka_saat_ini)){
					angka_saat_ini++;
				}
				printf("%d ", angka_saat_ini);
				angka_saat_ini++;
			}
			printf("\n");
		}
	}
	printf("\n");
}

int iniprima(int angka){
	if(angka <= 1){
		return 0;
	}
	for(int i = 2; i * i <= angka; i++){
		if(angka % i == 0){
			return 0;
		}
	}
	return 1;
}