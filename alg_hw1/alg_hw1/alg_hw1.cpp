// Zarivnoy Nikolay, home work #1

#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void Sol1();
void Sol2();
void Sol3();
void Sol4();

int main()
{
	printf("HW #1");
	printf("Select task ( 1 - Avtomorfnye, 2 - Random, 3 - Maximum, 4 - Srednee arifmeticheskoe)");
	int variant = 0;
	scanf("%i",&variant);
	switch (variant)
	{
	case 1:
		Sol1();
		break;
	case 2:
		Sol2();
		break;
	case 3:
		Sol3();
		break;
	case 4:
		Sol4();
		break;

	default:
		printf("Пока!");
		break;
	}


	return 0;
}

int getCountsOfDigits(int number) {
	int count = (number == 0) ? 1 : 0;
	while (number != 0) {
		count++;
		number /= 10;
	}
	return count;
}

void Sol1()
{
	printf("Автоморфные числа\n");
	printf("Input:");
	int user_input = 0;
	scanf("%i", &user_input);
	int iter = 0;
	int iter_sqr;
	int iter_length;
	while (iter < user_input) 
	{
		iter++;
		iter_sqr = iter * iter;
		iter_length = pow(10,getCountsOfDigits(iter));
		//printf("---------------------------------> %d   -   %d   -    %d\n", iter, iter_sqr, iter_length);
		if (iter == iter_sqr % iter_length)
		{
			printf("%d   -   %d\n", iter, iter_sqr);
		}
	}
}

void Sol2()
{
	srand(time(NULL));
	printf("Генерация случайных чисел\n");
	printf("%d\n", rand() % 101);

}

void Sol3()
{
	printf("Поиск максимального числа из 3х\n");
	int ans = 0;
	int user_input = 0;

	for (int i=0; i<4; i++)
	{
		printf("Input:");
		scanf("%i", &user_input);
		if (user_input > ans) { ans = user_input; }
	}
	printf("Max: %d\n", ans);
}

void Sol4()
{
	printf("Среднее арифметическое из четных оканчивающихся на 8\n");
	int user_input = 1;
	int result_A = 0;
	int count = 0;
	while (user_input != 0)
	{
		printf("Input:");
		scanf("%i", &user_input);
		if ((user_input > 0) && (user_input % 10 == 8)) //положительные четные оканчивающиеся на 8
		{
			result_A += user_input;
			count++;
		}
	}
	if (count > 0)
	{
		printf("Srednee: %d\n", result_A / count);
	}
}