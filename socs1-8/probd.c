#include <stdio.h>
#include <string.h>

void exchange(float* a, float *b){
    float t = *a;
    *a = *b;
    *b = t;
}

void stringExchange(char a[], char b[]){
	char temp[1001];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void characterExchange(char *a, char *b){
	char temp = *a;
	*a =  *b;
	*b = temp;
}

void main(){
    FILE *db = fopen("E:/socs1-8/testdata.in", "r");
    int i,j,k,m;
	float b[101]; 
	float d[101]; 
	char a[101][1001];
	char c[101];

	int n=0;
	while(!feof(db)){
		fscanf(db,"%[^#]#%f#%c\n",&a[n],&b[n],&c[n]); 
		d[n]=b[n];
		n++;
	}
	
	for(m=0; m<n; m++){
		if(c[m]=='F'){
			d[m]=(float)(d[m]-32)*5/9;	
		}
	}

	for(j=0; j<n-1; j++){  
        for(k=0; k<n-1; k++){
             if(d[k]>d[k+1]){
             	exchange(&d[k], &d[k+1]);	
             	exchange(&b[k], &b[k+1]);	
             	stringExchange(a[k], a[k+1]);	
             	characterExchange(&c[k], &c[k+1]);	
            }
            if(d[k] == d[k+1]){	
            	if(strcmp(a[k], a[k+1]) > 0){		
            		stringExchange(a[k], a[k+1]);
				}
			}
        }
    }
	
	for(i=0; i<n; i++){
        printf("%s is %.2f%c\n",a[i],b[i],c[i]);
	}
            
	fclose(db); 
}