#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	float length = 0.00;

	while(1){

		scanf("%f", &length);

		if(length != 0.00)
		{
			int cards_num = 0;
			float cards_length = 0.00, i = 2.00;
			float single_length;
			while(cards_length < length){

				cards_length = cards_length+1/i++;
				cards_num++;
				//printf("%.2f\n", cards_length);
			}

			printf("%d card(s)\n", cards_num);
		}else{
			break;
		}
	}
	return 0;
}