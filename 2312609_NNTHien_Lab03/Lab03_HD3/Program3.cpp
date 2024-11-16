#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
#include"Thuvien.h"
#include"Menu.h"
//=========================================
void ChayChuongTrinh();
//=========================================
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int soMenu = 7, array[MAX], n = 0, menu;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, array, n);
		system("PAUSE");
	} while (menu>0);
}