#include <stdio.h>

int main(){
	int numTestCases;
	scanf("%d", &numTestCases);
	
	for(int testCaseNum = 1; testCaseNum <= numTestCases; testCaseNum++){
		int arrayLength;
		scanf("%d", &arrayLength);
		int dataArray[arrayLength];
 
		for(int i = 0; i < arrayLength; i++){
			scanf("%d", &dataArray[i]);
		}
 
		int temp;
		for (int i=0; i<arrayLength-1; i++){
      for(int j=0; j<arrayLength-1-i; j++){
        if (dataArray[j] > dataArray[j+1]){
          temp = dataArray[j];
          dataArray[j] = dataArray[j+1];
          dataArray[j+1] = temp;
        }
      }
    }
     
    int searchTarget;
    scanf("%d", &searchTarget);
     
    printf("CASE #%d: ", testCaseNum);
     
    for(int i = 0; i < arrayLength; i++){
    	if(searchTarget == dataArray[i]){
    		if(dataArray[i] == dataArray[arrayLength-1]){
    			printf("%d %d\n", dataArray[i-1], dataArray[i]);
    			break;
				}else{
					printf("%d %d\n", dataArray[i], dataArray[i+1]);
					break;
				}
			}else if(i == arrayLength-1){
				printf("-1 -1\n");
			}
		}
	}
	return 0;
}