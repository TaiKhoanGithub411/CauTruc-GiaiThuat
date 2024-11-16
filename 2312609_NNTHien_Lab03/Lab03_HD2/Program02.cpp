#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

#include "Thuvien.h"
#include "Menu.h"
//====================================
void ChayChuongTrinh();
//====================================
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	SinhVien sv[MAX];
	int soMenu = 8, menu, n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, sv, n);
		system("PAUSE");
	} while (menu > 0);
}
