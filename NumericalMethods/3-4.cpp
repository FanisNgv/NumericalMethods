#include <iostream>  
#include "locale.h"  
#include <math.h>  
#include <iomanip>  

using namespace std;
const float eps = 0.001;   // Точность  
const float x = 1.8, y = 1;  // Начальное приближение

// коэффициенты для МПИ:
const float alpha = -5.0/18;
const float beta = 0.0;
const float gamma = 5.0/48;
const float delta = -1.0/3;

void method_simple_implications() // Метод простых итераций 
{
	int k = 0;
	float x0 = x, x1 = x;     // x0 = x(k), x1 = x(k+1)
	float y0 = y, y1 = y;	  //y0 = y(k), y1 = y(k+1)
	float modx, mody; // modx: |x1 - x0|, mody: |y1 - y0|
	do
	{
		x0 = x1, y0 = y1;
		x1 = x0 + alpha * (pow(x0, 2) - 4.0) + beta * (x0 + 3 * y0 - 8.0);
		y1 = y0 + gamma * (pow(x0, 2) - 4.0) + delta * (x0 + 3 * y0 - 8.0);

		modx = fabs(x1 - x0);
		mody = fabs(y1 - y0);
		cout << "|" << setw(4) << k << setw(4) << "|" << setw(8) << x0 << setw(5) << "|" << setw(10) << x1 << setw(5) << "|" 
			<< setw(14) << modx << setw(8) << "|" << setw(9) << y0 << setw(4) << "|" << setw(9) << y1 <<
			setw(4) << "|" << setw(11) << mody << setw(7) << "|" << endl;
		k++;
	} while ((modx > eps) || (mody > eps));
}

void method_Newton() // Метод Ньютона 
{
	int k = 0;
	float x0 = x, x1 = x;     // x0 = x(k), x1 = x(k+1)
	float y0 = y, y1 = y;	  //y0 = y(k), y1 = y(k+1)  
	float modx, mody; // y0 = y(k), y1 = y(k+1)  
	do // modx: |x1 - x0|, mody: |y1 - y0|  
	{
		x0 = x1, y0 = y1;
		x1 = x0 - (3.0 * (pow(x0, 2) - 4.0) + 0.0 * (x0 + 3 * y0 - 8.0)) / (6 * x0);
		y1 = y0 - ((-1.0) * (pow(x0, 2) - 4.0) + (2.0 * x0) * (x0 + 3 * y0 - 8.0)) / (6 * x0);


		modx = fabs(x1 - x0);
		mody = fabs(y1 - y0);
		cout << "|" << setw(4) << k << setw(4) << "|" << setw(8) << x0 << setw(5) << "|" << setw(10) <<
			x1 << setw(5) << "|" << setw(14) << modx << setw(8) << "|" << setw(9) <<
			y0 << setw(4) << "|" << setw(9) << y1 << setw(4) << "|" << setw(11) <<
			mody << setw(7) << "|" << endl;
		k++;
	} while ((modx > eps) || (mody > eps));
}

void show_table()
{
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << "|   k   |    X(k)    |   X(k + 1)   |  |(X(k+1) - X(k))|  |    Y(k)    |   Y(k+1)   | |Y(k+1) - Y(k)| |\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
}

void func()
{
	int n;
	while (true)
	{
		cout << "Команда 1 - поиск корней на отрезке по МПИ" << endl;
		cout << "Команда 2 - поиск корней на отрезке по Методу Ньютона" << endl;   cout << "Введите команду: "; cin >> n;
		switch (n)
		{
		case 1:
			cout << "\nМетод простых итераций" << endl;
			show_table();
			method_simple_implications();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно!" << endl;
			break;
		case 2:
			cout << "\nМетод Ньютона" << endl;
			show_table();
			method_Newton();
			cout << "\nПроцесс поиска корня на отрезке прошел успешно!" << endl;
			break;
		default:
			cout << "Ошибка ввода !";
			break;
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Лабораторная работа по Вычислительной математике №3-4\n" << endl;
	cout << "Выполнили студенты Маннанов и Нигамадянов гр. 4310\n" << endl;
	cout << "Вариант №20\nСистема нелинейных уравнений:" << endl;
	cout << "x^2 - 4 = 0\nx + 3y - 8 = 0\nНачальное приближение: ( 1.8; 1 )\n" << endl;
	func();
	system("pause");
	return 0;
}
