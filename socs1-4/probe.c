#include <stdio.h>

void main(){
    int x;
    int y;
    int k;
    scanf("%d %d %d", &x, &y, &k);
    int time = -1;
    for(int i=0; i<100; i++){
        if(x+i == y-i && y-i == k) {
        time = i;
        break;
        }
    }   
    printf("%d\n", time);
}