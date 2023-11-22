#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct C{
  char nama[100];
  int angka;
} data[100], temp;

int main(){
   
  int T;
  scanf("%d", &T);
     
    int n;
    for (n=0; n<T; n++){
      scanf("%s %d", data[n].nama, &data[n].angka);
    }
     
    int a, b;
    for (a=0; a<T-1; a++){
      for(b=0; b<T-1-a; b++){
        if (strcmp(data[b].nama, data[b+1].nama) > 0){
          temp = data[b];
          data[b] = data[b+1];
          data[b+1] = temp;
        }
      }
    }
     
    int i, j;
    for (i=0; i<T-1; i++){
      for(j=0; j<T-1-i; j++){
        if (data[j].angka > data[j+1].angka){
          temp = data[j];
          data[j] = data[j+1];
          data[j+1] = temp;
        }
      }
    }
     
    int x;
    for (x=0; x<T; x++){
      printf("%s\n", data[x].nama);
    }
 return 0;
}