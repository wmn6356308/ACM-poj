/**
 * 怎么算逆序列
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_string_length(char *str);
int n, m;

int main(int argc, char const *argv[])
{

	int i, j;
	char **letters;
	int *length;
	int temp;

	scanf("%d %d", &n, &m);

	letters = (char **)malloc(sizeof(char*)*m);
	
	length = (int *)malloc(sizeof(int)*m);
	
	for(i = 0; i < m; i++){

		letters[i] = (char *)malloc(sizeof(char)*n);
		scanf("%s", letters[i]);
		
		//这一步很精彩，细细品味
		length[i]= get_string_length(letters[i])*1000+i;
	}

	
	for(i = 0; i < m; i++){

		for(j = i+1; j < m; j++){

				if(length[i] > length[j] || length[i] == length[j]){

					if(length[i] > length[j]){

						temp = length[i];
						length[i] = length[j];
						length[j] = temp;
					}else{

						if(length[i]%1000 > length[j]%1000){
							
							temp = length[i];
							length[i] = length[j];
							length[j] = temp;
						}

					}
				}
		}
	}

	for(i = 0; i < m; i++){

		puts(letters[length[i]%1000]);
	}

	return 0;
}

int get_string_length(char *str){

	char *str_cpy;
	int i, j, length = 0;
	
	str_cpy = (char *)malloc(sizeof(char) * n);

	strcpy(str_cpy, str);

		for(i = 0; i < n; i++){   		//计算字符串的逆序数    
			for(j = i + 1; j < n; j++){     
				if(str_cpy[i] > str_cpy[j]){
					length++;
				  //逆序数x1000+原序号储存，快排时不影响原序号  
	  			}
	  		}
	  	}
	
	return length;
}