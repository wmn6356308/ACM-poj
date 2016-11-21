#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int p, e, i, d, Case=0;
    int j;

    while(1){

    	scanf("%d %d %d %d", &p, &e, &i, &d);
    	if(p != -1 && e!=-1 && i!= -1 && d!=-1){

    		Case++;
	        for(j = 1; ; j++){

	        	if((j - p) % 23 == 0 && (j - e) % 28 == 0 && (j - i) % 33 == 0){
	                if(j < d){

	                	j += 23*28*33;
	                }
	                printf("Case %d: the next triple peak occurs in %d days.\n", Case, j-d);
	            	break;
	        	}
	        }
	    }else{
	    	break;
	    }
    }
}