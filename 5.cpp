#include <iostream>
#include "locale.h"
#include <math.h>
#include <iomanip>
using namespace std;
const float eps = 0.001; // точность
const float x = 1.0, y = -126.0/705.0, z = - 3.0/4.0; // начальное приближение
const int rr = 10000; // округление

void method_simple_implications() // Метод простых итераций
{
	int k = 0;
	float x0 = x, x1 = x; // x0 = x(k), x1 = x(k+1)
	float y0 = y, y1 = y; // y0 = y(k), y1 = y(k+1)
	float z0 = z, z1 = z; // z0 = y(k), z1 = z(k+1)
	float modx, mody, modz; // modx = |x1 - x0|, mody = |y1 - y0|, modz = |z1 - z0|

	do
	{
		x0 = x1; y0 = y1; z0 = z1;
		x1 = x - 0.1 * y0 - (1.0/8.0) * z0;
		y1 = y + (126.0/705.0) * x0 + (9.0/141.0) * z0;
		z1 = z + (3.0/4.0) * x0 - (1.0/8.0) * y0;
		modx = fabs(x1 - x0);
		mody = fabs(y1 - y0);
		modz = fabs(z1 - z0);

		cout << "|" << setw(2) << k << setw(2)
			<< "|" << setw(8) << x0 << setw(5)
			<< "|" << setw(10) << x1 << setw(5)
			<< "|" << setw(14) << modx << setw(8)
			<< "|" << setw(12) << y0 << setw(4)
			<< "|" << setw(12) << y1 << setw(4)
			<< "|" << setw(14) << mody << setw(7)
			<< "|" << setw(12) << z0 << setw(4)
			<< "|" << setw(12) << z1 << setw(4)
			<< "|" << setw(14) << modz << setw(7)
			<< "|" << endl;
		k++;
	} while ((modx > eps) || (mody > eps) || (modz > eps));
}

void method_Zeidela() // Метод Зейделя
{
	int k = 0;
	float x0 = x, x1 = x; // x0 = x(k), x1 = x(k+1)
	float y0 = y, y1 = y; // y0 = y(k), y1 = y(k+1)
	float z0 = z, z1 = z; // z0 = y(k), z1 = z(k+1)
	float modx, mody, modz; // modx = |x1 - x0|, mody = |y1 - y0|, modz = |z1 - z0|

	do
	{
		x0 = x1; y0 = y1; z0 = z1;
		x1 = x - 0.1 * y0 - (1.0 / 8.0) * z0;
		y1 = y + (126.0 / 705.0) * x1 + (9.0 / 141.0) * z0;
		z1 = z + (3.0 / 4.0) * x1 - (1.0 / 8.0) * y1;
		modx = fabs(x1 - x0);
		mody = fabs(y1 - y0);
		modz = fabs(z1 - z0);

		cout << "|" << setw(2) << k << setw(2)
			<< "|" << setw(8) << x0 << setw(5)
			<< "|" << setw(10) << x1 << setw(5)
			<< "|" << setw(14) << modx << setw(8)
			<< "|" << setw(12) << y0 << setw(4)
			<< "|" << setw(12) << y1 << setw(4)
			<< "|" << setw(14) << mody << setw(7)
			<< "|" << setw(12) << z0 << setw(4)
			<< "|" << setw(12) << z1 << setw(4)
			<< "|" << setw(14) << modz << setw(7)
			<< "|" << endl;
		k++;
	} while ((modx > eps) || (mody > eps) || (modz > eps));
}

void show_table()
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "| k |    X(k)    |   X(k + 1)   |  |(X(k+1) - X(k))|  |     Y(k)      |   Y(k + 1)    |  |Y(k + 1) - Y(k)| |      Z(k)     |    Z(k + 1)   |  |Z(k + 1) - Z(k)| |\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void func()
{
	int n;
	while (true)
	{
		cout << "Команда 1 - поиск корня на отрезке по Методу простых итераций" << endl;
		cout << "Команда 2 - поиск корня на отрезке по Методу Зейделя" << endl;
		cout << "Введите команду: "; cin >> n;
		switch (n)
		{

		case 1:
			cout << "\nМетод простых итераций" << endl;
			show_table();
			method_simple_implications();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно!" << endl;
			break;
		case 2:
			cout << "\nМетод Зейделя" << endl;
			show_table();
			method_Zeidela();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно!" << endl;
			break;
		default:
			cout << "\nОшибка ввода! Команды не существует! Повторите ввод!\n";
			break;
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(0, "");
	cout << "Лабораторная работа по Вычислительной математике №5\n" << endl;
	cout << "Выполнили студенты Маннанов и Нигамадянов гр. 4310\n" << endl;
	cout << "Вариант №19\nСЛАУ:\n 5x  +  0.5y  +  5/8 z = 5;\n 2.8x  -  141/9 y  +  z = 2.8;\n 6x - y - 8z = 6;\n" << endl;
	func();
	system("pause");
	return 0;
}
