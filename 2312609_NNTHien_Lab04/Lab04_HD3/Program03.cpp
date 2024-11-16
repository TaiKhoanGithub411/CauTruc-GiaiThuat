#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
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
	int somenu = 6, menu;
	List l;
	do
	{
		system("CLS");
		XuatMenu();
		menu = ChonMenu(somenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu > 0);
}