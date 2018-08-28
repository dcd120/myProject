
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// ����������� ������� ��� ���������� ��������� ������������� ����� �� ������������ ������� 
// ����� ����������������� ������� �� 2
int trans10to2(int v10)
{
	if (v10 > 2)
	{
		int v2 = trans10to2(v10 / 2);
		printf("%d",v10 % 2);
	}
	else {
		printf("%d", v10 / 2);
		printf("%d", v10 % 2);
	}
}

void variant1()
{
	printf("������ �������� ����� �� 10 ������� � ��������, � �������������� ��������\n");
	int v10;
	printf("������� ����� � 10 �������, ��� �������� � �������: ");
	scanf("%d",&v10);
	// ���������� ����� ����� ������ �� 2 � �������� � ��������, ���� ������� �� ������� �� ����� ������ 2
	trans10to2(v10);
	// ���� ����� �� ������ �� �����
	printf("\n");
	system("pause");
}

void variant2()
{
	printf("������ ���������� ����� � �������, ��� �������� (������������� �������������)\n");
	printf("������� �����, ��� ���������� � �������:\n");
	int v_base = 0;
	scanf("%d",&v_base);
	printf("������� �������, � ������� ���������� �������� ������ �����:\n");
	int v_pow = 0;
	scanf("%d", &v_pow);
	printf("\n");
	int res = v_base;
	for (int i=1; i < v_pow; i++)
	{
		res *= v_base;
	}
	printf("���������: %d", res);
	printf("\n");
	system("pause");
}

int rec_pow1(int base, int power)
{
	if (power == 2)
	{
		return base * base;
	}
	else {
		return base * rec_pow1(base, power - 1);
	}
}

void variant3()
{
	printf("������ ���������� ����� � �������, � ���������\n");
	printf("������� �����, ��� ���������� � �������:\n");
	int v_base = 0;
	scanf("%d", &v_base);
	printf("������� �������, � ������� ���������� �������� ������ �����:\n");
	int v_pow = 0;
	scanf("%d", &v_pow);
	printf("\n");
	int res = 0;

	// ���������� ����������� ������� ��� ������� �������
	res = rec_pow1(v_base, v_pow);

	printf("���������: %d", res);
	printf("\n");
	system("pause");
}

int rec_pow2(int base, int power)
{
	// ������ �������
	if (power == 2)
	{
		return base * base;
	}
	else if (power % 2 == 0)
	{
		rec_pow2(base * base, power / 2);
	}
	else {
		return base * rec_pow2(base, power - 1);
	}
}

void variant4()
{
	printf("������ ���������� ����� � �������, � ���������, ��������� ������ �������� �������\n");
	printf("������� �����, ��� ���������� � �������:\n");
	int v_base = 0;
	scanf("%d", &v_base);
	printf("������� �������, � ������� ���������� �������� ������ �����:\n");
	int v_pow = 0;
	scanf("%d", &v_pow);
	printf("\n");
	int res = 0;

	// ���������� ����������� ������� ��� ������� �������
	res = rec_pow2(v_base, v_pow);

	printf("���������: %d", res);
	printf("\n");
	system("pause");
}

void variant5()
{
	printf("������ �������������� 3 � 20, ����� +1 � *2, � �������������� �������\n");
	// �������� ������ ��������, ������� �� ����� �������� �� ������� ������
	int min = 3;
	int max = 20;
	int _mass[21][21] = { 0 };
	int count = 1;
	int h = 0;
	_mass[3][0] = 3;
	int solutions = 0;
	int current = 0;
	int new_val = 0;
	for ( int i = min+1; i <= max+1; i++ )
	{
		count = 0; // �������, ������� ������� �� ��� �������������
		printf("��� ---------------- %d\n", i);
		for (h = 0; h < max; h++)
		{
			// ������� ��� �������. ���������� �� ������� ����, � ���������� � ��� (+1) � (*2)
			current = _mass[i-1][h];
			printf("> %d\n",current);
			if (current == max)
			{
				// ������� ���� �� �������
				solutions++;
				printf("������� �������> %d\n", current);
				//break;
			}
			if (current == 0)
			{
				break;
			}
			else {
				new_val = current + 1;
				printf("--> %d  ", new_val);
				if (new_val < max+1)
				{
					_mass[i][count] = new_val;
					count++;
				}
				new_val = current * 2;
				printf("--> %d\n", new_val);
				if (new_val < max+1)
				{
					_mass[i][count] = new_val;
					count++;
				}
			}
		}
	}
	printf("���������: %d\n", solutions);
	system("pause");
}

// ������ �� ������ �����, � �� ������ �����, ��������� ���������� ������ 1
int rec_calc(int current, int destanation)
{
	printf("%d\n",current);
	if (current == destanation)
	{
		printf("+++++\n");
		return 1;
	}
	if (current > destanation) return 0;
	return rec_calc(current + 1, destanation) + rec_calc(current * 2, destanation);
}

//int rec_calc(int min, int max)
//{
//	if (max > min)
//	{
//		if ((max % 2 == 0)&&(max / 2 >= min))
//		{
//			printf("%d DIV\n", max);
//			return  1 + rec_calc(min, max / 2) + rec_calc(min, max - 1);
//			
//		}
//		else
//		{
//			printf("%d\n", max);
//			return rec_calc(min, max - 1);
//			
//		}
//	}
//	else
//	{
//		printf("MIN!\n");
//		return 0;
//	}
//}

void variant6()
{
	printf("������ �������������� 3 � 20, ����� +1 � *2, � �������������� ��������\n");
	// ����� �������� �������, ������� ����� ���������� �� 20 � 3, �������� �� ������ ������, 
	// ��������� ������ ����� ������ � ������� �����
	int result = rec_calc(3, 20);
	printf("���������: %d\n", result);
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	// ���� ������
	printf("�������� �������� ��� ������������:\n");
	printf("1 - ������� ����� �� 10 ������� � ��������, � �������������� ��������\n");
	printf("2 - ���������� ����� � �������, ��� ��������\n");
	printf("3 - ���������� ����� � �������, � ���������\n");
	printf("4 - ���������� ����� � �������, � ���������, ��������� ������ �������� �������\n");
	printf("5 - �������������� 3 � 20, ����� +1 � *2, � �������������� �������\n");
	printf("6 - �������������� 3 � 20, ����� +1 � *2, � �������������� ��������\n");

	int sel;
	scanf("%d", &sel);

	switch (sel)
	{
	case 1:
		variant1();
		break;
	case 2:
		variant2();
		break;
	case 3:
		variant3();
		break;
	case 4:
		variant4();
		break;
	case 5:
		variant5();
		break;
	case 6:
		variant6();
		break;
	default:
		return;
		break;
	}

}