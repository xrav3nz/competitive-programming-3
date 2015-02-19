#include <cstdio>

int slide_distance, fatigue, day;
double well_height, climb_distance, current_height, first_day;

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while(scanf("%lf %lf %d %d", &well_height, &climb_distance, &slide_distance, &fatigue) != EOF && well_height){
		current_height = 0;
		first_day = climb_distance;
		for(day = 1; ; ++day){
			if(day == 1){
				current_height = climb_distance;
			}else{
				current_height += climb_distance;
			}

			climb_distance -= first_day * (fatigue / 100.0);
			if (climb_distance < 0) climb_distance = 0;

			if(current_height > well_height)
				break;

			current_height -= slide_distance;

			if(current_height < 0)
				break;
		}

		if(current_height <= 0)
			printf("failure on day %d\n", day);
		else
			printf("success on day %d\n", day);
	}	

	return 0;
}