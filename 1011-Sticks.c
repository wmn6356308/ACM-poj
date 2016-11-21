#include <stdio.h>

/**
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
8
1 1 1 1 1 2 3 5
0
 */

int main(int argc, char const *argv[])
{
	int num;
	
	scanf("%d", &num);
	while(num != 0){
		int i = 0, j, temp;
		int flag[num], length[num], length_tot = 0;
		
		while(i != num){
			scanf("%d", &length[i]);
			flag[i] = 0;
			length_tot += length[i++];
		}


		for(i = 0; i < num; i++){

			for(j = i+1; j < num; j++){
				if(length[i] < length[j]){

					temp = length[i];
					length[i] = length[j];
					length[j] = temp;
				}

			}
		}

		for(i = 0; i < num; i++){

			printf("%d ", length[i]);
		}
		printf("\n");
		//printf("length_tot = %d\n", length_tot);

		//int temp = 0;

		for(i = length_tot; i >0; i--){

			if(length_tot % i == 0){
				int  k;
				int min_len = length_tot/i;
				if(min_len < length[0]){

					continue;
				}

				for(j = 0; j < i; j++){
					min_len = length_tot/i;
					int re_flag;
					for(k = 0; k < num; k++){

						if(flag[k] == 1){
							continue;
						}

						if(min_len - length[k] < 0){
							printf("--\n");
							int f = 0, m;
							for(m = 0; m < num; m++){
								if(flag[m] == 0){
									f = 1;
									break;
								}
							}
							if(f == 0){
								k = re_flag+1;
								flag[re_flag] = 0;
								min_len = min_len + length[re_flag];
								if(i == 5){
									printf("min_len = %d\n", min_len);
								}
							}else{

								continue;
							}
						}else if(min_len - length[k] == 0){

							flag[k] = 1;
							
							break;
						}else{
							printf("re_fla = %d\n ", re_flag);
							re_flag = k;
							min_len = min_len - length[k];
							flag[k] = 1;
						}
					}
					if(i == 5){
					int n;
					printf("%d\n", i);
					for(n = 0; n < num; n++){
						printf("%d ", flag[n]);
					}
					printf("\n");
					}
				}

				int n, flag_done = 0;

				for(n = 0; n < num; n++){

					if(flag[n] == 0){
						flag_done = 1;
						break;
					}
				}

				if(flag_done == 0){

					printf("%d", length_tot/i);
					break;
				}else{

					for(n = 0; n < num; n++){

						flag[n] = 0;
					}
				}
			}
		}

		scanf("%d", &num);
	}

	return 0;
}