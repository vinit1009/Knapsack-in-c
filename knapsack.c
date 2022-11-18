#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int max(int a, int b) {
    if(b > a){
        return b;
    }
    else{
        return a;
    }
}

int main(int argc, char **argv)
{



    int W = atoi(argv[1]);
    int n;
    
    FILE *fPointer;
	fPointer = fopen(argv[2], "r");

	fscanf(fPointer, "%d", &n);
    //printf("%d", n);

	int *val = malloc(128);
    int* wt = (int*)malloc(n*sizeof(int));
    char** vinit;
    vinit = malloc(n*sizeof(char *));
    for(int i = 0; i < n; i++){
        vinit[i] = (char *)malloc(31+1);
    }
	char** goat;
    goat = malloc(n*sizeof(char *));
    for(int i = 0; i < n; i++){
        goat[i] = (char *)malloc(31+1);
    }


    for(int i = 0; i <n; i++){
    
        
        fscanf(fPointer, "%s", vinit[i]);
        //printf("\n %s", vinit[i]);
        fscanf(fPointer, "%d", &wt[i]);
       // printf("\n %d", wt[i]);
        fscanf(fPointer, "%d", &val[i]);
        //printf("\n %d\n", val[i]);
        
        
    }
     
    int i, w;
    int** K = (int **)malloc((n+1)*sizeof(int*));
    for(int i = 0; i <= n; ++i){
        K[i] = (int*)malloc((W+1)*sizeof(int));
    }
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    int res = K[n][W];  
	int val_total = res; 
    //printf("%d\n", res);
     
    w = W;
	int t_val=0;
	int num = 0;
    for (i = n; i > 0 && res > 0; i--) {
         
        if (res == K[i - 1][w])
            continue;       
        else {
			
 
            //printf("%d ", wt[i - 1]);
			t_val = t_val + wt[i-1];
			
			//printf("%s\n", vinit[i-1]);
			strcpy(goat[num],vinit[i-1]);
			num = num+1;
			
			
             

            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
	for(int i = num -1; i >=0; i--){
		printf("%s\n", goat[i]);
	}
	printf("%d / %d",val_total, t_val);
    
    
    ;

    //free(val);
    free(wt);
    for(int i = 0; i < n; i++){
        free(vinit[i]);
    }
    free(vinit);
	for(int i = 0; i < n; i++){
        free(goat[i]);
    }
    free(goat);
    for(int i = 0; i <= n; i++){
        free(K[i]);
        
    }
    free(K);
     
    return 0;
}
