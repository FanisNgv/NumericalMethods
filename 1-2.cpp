#include <iostream>
#include "locale.h"
#include <math.h>
#include <iomanip>

using namespace std;
void method_simple_implications() // Метод простых итераций
{
  int n = 0;
  float x = -2.5, y, z, с = 1, mod1, mod2, eps = 0.001, d = 0.01;
  do
  {
    z = x; // z - это Xn
    y = z + с * (2*sin(z)-z+0.4); // y - это Xn + 1
    mod1 = fabs(y - z);
    mod2 = fabs(2 * sin(y) - y + 0.4);

    x = y;
    cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" <<
      setw(12) << y << setw(5) << "|" << setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8)
      << "|" << endl;
    n += 1;
  } while ((mod1 > eps)  (mod2 > d));
}


void method_Newton() // Метод Ньютона
{
  int n = 0;
  float x = -2.5, y, z, mod1, mod2, eps = 0.001, d = 0.01;
  do
  {
    z = x; // z - это Xn
    y = z - (2*sin(z)-z+0.4)/(2*cos(z)-1); // y - это Xn + 1
    mod1 = fabs(y - z);
    mod2 = fabs(2 * sin(y) - y + 0.4);
    x = y;
    cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" <<
      setw(12) << y << setw(5) << "|" << setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8)
      << "|" << endl;
    n += 1;
  } while ((mod1 > eps)  (mod2 > d));
}
void modification_method_Newton() // Модифицированный Метод Ньютона
{
  int n = 0;
  float x = -2.5, x0=x, y, z, mod1, mod2, eps = 0.001, d = 0.01;
  do
  {
    z = x; // z - это Xn
    y = z - (2 * sin(z) - z + 0.4) / (2 * cos(x0) - 1); // y - это Xn + 1
    mod1 = fabs(y - z);
    mod2 = fabs(2 * sin(y) - y + 0.4);
    x = y;
    cout << "|" << setw(5) << n << setw(5) << "|" << setw(12) << z << setw(5) << "|" <<
      setw(12) << y << setw(5) << "|" << setw(14) << mod1 << setw(8) << "|" << setw(14) << mod2 << setw(8)
      << "|" << endl;
    n += 1;
  } while ((mod1 > eps) || (mod2 > d));
}
void show_table()
{
  cout << "-----------------------------------------------------------------------------------------\n";
  cout << "|    n    |       Xn       |     Xn + 1     |    |(Xn+1 - Xn)|    |     |f(Xn + 1)|     |\n";
  cout << "-----------------------------------------------------------------------------------------\n";
}
void func()
{
  int n;
  while (true)
  {

    cout << "Команда 1 - поиск корня на отрезке по Методу простых итераций" << endl;
    cout << "Команда 2 - поиск корня на отрезке по Методу Ньютона" << endl;
    cout << "Команда 3 - поиск корня на отрезке по Модифицированному Методу Ньютона" << endl;

    cout << "Введите команду: "; cin >> n;
    switch (n)
    {
    case 1:
      cout << "\nМетод простых итераций" << endl;
      show_table();
      method_simple_implications();
      cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
      break;
    case 2:
      cout << "\nМетод Ньютона" << endl;
      show_table();
      method_Newton();
      cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
      break;
    case 3:
      cout << "\nМодифицированный Метод Ньютона" << endl;
      show_table();
      modification_method_Newton();
      cout << "\nПроцесс поиска корня на отрезке прошел успешно !" << endl;
      break;
    default:
      cout << "Ошибка ввода !";
      break;
    }
    cout << "\n";
    // system("pause");
    // system("cls");
  }
}
int main()
{
  setlocale(0, "");
  cout << "Лабораторная работа по Вычислительной математике No1-2\n" << endl;
  cout << "Выполнили студенты Маннанов и Нигамадянов гр. 4310\n" << endl;
  cout << "Вариант No6\nНелинейное уравнение: f(x) = 2sin(x)-x+0.4=0\n Отрезок: [ -2.5, -1.5 ]\n" << endl;
  func();
  system("pause");
  return 0;
}
