#include <stdio.h>

void main(){
    int N;
    int count = 0;
    scanf("%d",&N);
    int var = 0;
    for (int j = 0; j <= N; j++) { 
        for (int l = 0; l <= N; l++) { 
            int b = N - j - l;
            if (b >= 0) {
                var++;
            }
        }
    }
    printf("%d\n",var);

}