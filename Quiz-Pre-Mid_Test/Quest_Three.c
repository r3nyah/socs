#include <stdio.h>
/*
	Name
	Nim
	Question Number 3 - Recursive
*/

int answer;
int nCr();
long int lakukan_permutasi();
int lakukan_fibonacci();
void lakukan_bilangan_natural();
int lakukan_jumlah_natural();
void soal();
void Fibonacci();
void Natural();
void Permutasi();
void Kombinasi();
void Keluar();

void main(){
        soal();
        scanf("%d", &answer);

        switch (answer) {
            case 1:
                Fibonacci();
                break;
            case 2:
                Natural();
                break;
            case 3:
                Permutasi();
                break;
            case 4:
                Kombinasi();
                break;
            case 5:
                printf("Terima kasih. Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }

}

void soal(){
	printf("Serba-Serbi Rekursi\n");
	printf("===================");
	printf("\n1. Deret Fibonacci\n2. Bilangan Natural\n3. Permutasi\n4. Kombinasi\n5. Keluar");
	printf("\nPilih >> ");
}

void Fibonacci(){
	int N;
    printf("Masukan angka n : ");scanf("%d", &N);

    if(N < 0){
        printf("Bilangan harus lebih dari 0\n");
    }else{
        printf("Deret Fibonacci = ");
        for(int i = 0; i <= N; i++){
            printf("%d ", lakukan_fibonacci(i));
        }
        printf("\n");
    }
}

void Natural(){
	int N;
    printf("Masukan angka n : ");scanf("%d", &N);

    if(N < 0){
        printf("Bilangan harus lebih dari 0\n");
    }else{
        printf("Deret natural hingga %d = ", N);
        lakukan_bilangan_natural(N);
        printf("\nJumlah dari baris bilangan natural = %d\n",lakukan_jumlah_natural(N));
    }
}

void Permutasi() {
    int N, R;

    printf("Masukan nilai N: ");scanf("%d", &N);
    printf("Masukan nilai R: ");scanf("%d", &R);

  if (N < R) {
    printf("Nilai N harus lebih besar atau sama dengan nilai R.\n");
    return;
  }

  long int hasil = lakukan_permutasi(N, R);
  printf("Hasil dari permutasi %d dan %d adalah %ld\n", N, R, hasil);
}


void Kombinasi(){
    int N,R;

    printf("Masukan nilai N: ");scanf("%d", &N);
    printf("Masukan nilai R: ");scanf("%d", &R);

    if(R >= N){
        printf("R harus lebih kecil dari N.\n");
    }else if(N <= 0 || R <= 0){
        printf("N dan R harus lebih besar dari 0.\n");
    }

    printf("%dP%d = %d",N,R,nCr(N,R));
}

void Keluar(){
	
}

/*
======================Helper======================
*/

int lakukan_fibonacci(int n){
    if (n <= 1){
        return n;
    }

    return lakukan_fibonacci(n - 1) + lakukan_fibonacci(n - 2);
}

void lakukan_bilangan_natural(int n) {
    if (n <= 0) {
        return;
    }
    lakukan_bilangan_natural(n - 1);
    printf("%d", n);
    if (n != 1) {
        printf(" ");
    }
}

int lakukan_jumlah_natural(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + lakukan_jumlah_natural(n - 1);
}

long int lakukan_permutasi(int n, int r) {
  if (r == 0) {
    return 1;
  } else {
    return n * lakukan_permutasi(n - 1, r - 1);
  }
}

int nCr(int n,int r){
    if(r == 0 || n == r){
        return 1;
    }

    return nCr(n - 1, r - 1) + nCr(n - 1,r);
}