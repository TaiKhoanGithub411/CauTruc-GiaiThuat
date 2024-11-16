#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<conio.h>
using namespace std;
#include"Thuvien.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	List l;
	BangDiem bd;
	if (DocFile_SinhVien((char*)"dssv.txt", l) && DocFile_BD((char*)"bangdiem.txt", bd))
		XuatBD(l, bd);
	else
		cout << "Loi";
	_getch();
}