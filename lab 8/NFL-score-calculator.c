#include <stdio.h>
#include <stdlib.h>

void findCombinations(int score)
{
	for(int td2 = 0; td2 <= score/8; td2++)
	{
		for(int tdfg = 0; tdfg <= score/7; tdfg++)
		{
			for(int td = 0; td <= score/6; td++)
			{
				for(int fg = 0; fg <= score/3; fg++)
				{
					for(int safety = 0; safety <= score/2; safety++)
					{
						int total = td2*8 + tdfg*7 + td*6 + fg*3 + safety*2;
						if(total == score)
						{
							printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety);
						}
					}
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		printf("Enter the NFL score (Enter 1 to stop):");
		int score;
		scanf("%d", &score);

		if(score == 1)
		{
			break;
		}

		findCombinations(score);
	}
	return 1;
}
