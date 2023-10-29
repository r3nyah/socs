#include <stdio.h>

char fibonacci(char A, char B, int N);

int main(){
    int T;
    scanf("%d",&T);

    for(int i = 1; i <= T; i++){
        int N;
        char A,B;
        scanf("%d %c %c", &N,&A,&B);
        printf("Case #%d: ", i);
        fibonacci(A,B,N);
        printf("\n");
    }
}

char fibonacci(char A, char B, int N){
    if(N == 0){
        printf("%c", A);
    }else if(N == 1){
        printf("%c", B);
    }else{
        fibonacci(A,B,N - 1);
        fibonacci(A,B,N - 2);
    }
}