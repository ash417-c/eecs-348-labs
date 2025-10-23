#include <stdio.h>
#include <string.h>
#include <ctype.h>
double conversion(double temp, char type, char convertType)
{
	if(type == 'F')
	{
		temp = (temp - 32) * (5/9);
	}
	else if(type == 'K')
	{
		temp -= 272;
	}
	// temp is in C
	double converted = temp;
	if(convertType == 'F')
	{
		converted = (temp * (9/5)) + 32;
	}
	else if (convertType == 'K')
	{
		converted = temp + 272;
	}
	printf("Converted Temperature: %lf %c\n", converted, convertType);
	return temp;
}
int main()
{
	printf("Enter temperature value: ");
	double temp;
	scanf("%lf", &temp);

	printf("Enter original scale (C,F,K): ");
	char original;
	scanf(" %c", &original);
	original = toupper(original);

	printf("Enter scale to convert to (C,F,K): ");
	char convert;
	scanf(" %c", &convert);
	convert = toupper(convert);

	double tempC = conversion(temp, original, convert);
	char tempCat[50] = "Temperature category: ";
	char adv[50] = "Weather advisory: ";

	if(tempC < 0)
	{
		strcat(tempCat, "Freezing");
		strcat(adv, "Wear winter clothing");
	}
	else if(tempC < 10)
	{
		strcat(tempCat, "Cold");
		strcat(adv, "Keep handwarmers");
	}
	else if(tempC < 25)
	{
		strcat(tempCat, "Comfortable");
		strcat(adv, "Perfect weather");
	}
	else if(tempC < 35)
	{
		strcat(tempCat, "Hot");
		strcat(adv, "Stay in the shade");
	}
	else
	{
		strcat(tempCat, "Extreme Heat");
		strcat(adv, "Stay inside");
	}

	printf("%s\n", tempCat);
	printf("%s\n", adv);

	return 0;
}
