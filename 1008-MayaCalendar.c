#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Haab_month[][15] = {{"pop"}, {"no"}, {"zip"}, 
					{"zotz"}, {"tzec"}, {"xul"}, {"yoxkin"}, {"mol"}, 
					{"chen"}, {"yax"}, {"zac"}, {"ceh"}, {"mac"}, {"kankin"},
					{"muan"}, {"pax"}, {"koyab"}, {"cumhu"}, {"uayet"}};
char Tzol_month[][15] = {{"imix"}, {"ik"}, {"akbal"}, {"kan"}, {"chicchan"}, {"cimi"},
					{"manik"}, {"lamat"}, {"muluk"}, {"ok"}, {"chuen"}, {"eb"}, 
					{"ben"}, {"ix"}, {"mem"}, {"cib"}, {"caban"}, {"eznab"}, {"canac"}, {"ahau"}};

void convert(char *date, char *month, char *year, char *Ti_date){

	char date1[3];
	int H_date, H_month, H_year;
	int T_date, T_month, T_year;
	int i;
	int total_days;
	//获得日期
	strncpy(date1, date, 2);
	date1[3] = '\0';
	H_date = atoi(date1);

	//获取月份
	for (i = 0; i < 19; i++)
	{
		if(strcmp(month, Haab_month[i]) == 0){

			H_month = i;
			break;
		}
	}

	H_year = atoi(year);
	
	total_days = H_year*365+H_month*20+H_date+1;

	T_year = total_days/260;
	if(total_days%260 == 0){

		T_year--;
	}
	if((T_month = total_days%260%20) == 0){

		T_month = 19;
	}else{
		T_month--; 
	}
	if((T_date = total_days%260%13) == 0){

		T_date = 13;
	}

	sprintf(Ti_date, "%d %s %d", T_date, Tzol_month[T_month], T_year);
}

int main(int argc, char const *argv[])
{

	char date[3], month[10], year[6]; 
	char **Ti_date;
	int count, i;

	scanf("%d", &count);
	printf("%d\n", count);
	Ti_date = (char **)malloc(sizeof(char*)*count);

	for(i = 0; i < count; i++){

		Ti_date[i] = (char *)malloc(sizeof(char) * 20);
		scanf("%s %s %s", date, month, year);
		convert(date, month, year, Ti_date[i]);
		puts(Ti_date[i]);
	}

	return 0;
}