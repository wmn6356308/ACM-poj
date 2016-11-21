#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	float money[12];
	float total_money = 0.00;

	int i;
	for(i = 0; i < 12; i++){

		scanf("%f", &money[i]);
		total_money = total_money+money[i];
	}

	printf("$%.2f", total_money/12);

	return 0;
}