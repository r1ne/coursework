#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>


/*Описание игры:
На столе лежит ряд спичек. 
При своем ходе игрок может взять одну или две смежные спички.
Выигрывает тот, кто берет последнюю спичку.
Удачи.*/

void print_matches(int num)
{
	int i;
	// for (i = 0; i < num; i++)
	// 	printf("* ");

	// printf("\n");

	for (i = 0; i < num; i++)		
		printf("| ");

	printf("\n");
}

int take_matches(int num)
{
	switch (num) 
	{
		case 1:
		return 1;

		case 2:
		return 2;

		case 4:
		return 1;

		case 5:
		return 2;

		case 7:
		return 1;
	}
	// if (num == 2)
	// 	return 2;
	// if (num == 1)
	// 	return 1;
	// if (num == 4)
	// 	return 1;
	// if (num == 5)
	//	return 2;
	srand(time(0));
	return rand() % 2 + 1;
}
void main()
{
	setlocale(LC_ALL, "rus");
	int matches;
	int you_win = 0;
	int choose = 0;
	printf("Введите количество спичек для игры\n");
	scanf("%i", &matches);

	while (matches > 0)
	{
		//system("cls");
		print_matches(matches);
		while ((choose != 1) && (choose != 2))
		{
			printf("Забираем 1 или 2 спички?\n");
			scanf("%i", &choose);
		}

		printf("Вы выбрали %i спички\n", choose);
		matches -= choose;

		if (matches == 0) 
			you_win = 1;

		if (!you_win)
		{
			choose = take_matches(matches);
			printf("Компьютер взял %i спички\n\n", choose);

			matches -= choose;
			if (matches == 0) 
				you_win = 0;
		}

		choose = 0;
	}

	if (you_win)
		printf("Вы выиграли!");
	else printf("Вы проиграли :(");
}