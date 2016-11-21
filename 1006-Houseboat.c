#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	int count, i;

	scanf("%d", &count);

	for (i = 0; i < count; ++i)
	{
		int years;
		float X, Y, area;

		scanf("%f %f", &X, &Y);

		area = (X*X+Y*Y)*3.14/2;
		//处理过程

		years = area/50+1;
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, years);
	}

	printf("END OF OUTPUT.");

	return 0;
}