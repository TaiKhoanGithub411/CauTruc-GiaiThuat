#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
#include"Thuvien.h"
#include"Menu.h"

void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	NhanVien nv[MAX];
	int menu, soMenu = 6, n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, nv, n);
		system("PAUSE");
	} while (menu > 0);
}