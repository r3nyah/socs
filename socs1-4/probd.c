#include <stdio.h>

void main(){
    int testCase;
    scanf("%d", &testCase);
    for(int i=1; i <= testCase; i++){
        int a;
        int b;
        int total = 0;
        scanf("%d %d", &a, &b);
        total = a;
        while(a >= b){
            int new = a/b;
            total += new;
            a = new + (a%b);
        }
        printf("Case #%d: %d\n",i,total);
    }
}