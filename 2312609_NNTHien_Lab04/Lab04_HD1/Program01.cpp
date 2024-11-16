#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
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
	int menu, soMenu = 18;
	List a;
	do
	{
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a);
		system("PAUSE");
	} while (menu > 0);
}