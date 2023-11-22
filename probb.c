#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sort{
    char nama[51];
    int angka;
} data[50], temp;

int main(){
    
    int T;
    scanf("%d", &T);
    
    int z;
    for (z=1; z<=T; z++){
        int N;
        scanf("%d", &N);
        
        int n;
        for (n=0; n<N; n++){
            scanf("%[^#]#%d", data[n].nama, &data[n].angka);
        }
        
        int a, b;
        for (a=0; a<N-1; a++){
            for(b=0; b<N-1-a; b++){
                if (strcmp(data[b].nama, data[b+1].nama) > 0){
                    temp = data[b];
                    data[b] = data[b+1];
                    data[b+1] = temp;
                }
            }
        }
        
        
        int i, j;
        for (i=0; i<N-1; i++){
            for(j=0; j<N-1-i; j++){
                if (data[j].angka < data[j+1].angka){
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
        
        printf("Case #%d:", z);
        int x;
        for (x=0; x<N; x++){
            printf("%s - %d", data[x].nama, data[x].angka);
        }
        printf("\n");
    }
 return 0;
}