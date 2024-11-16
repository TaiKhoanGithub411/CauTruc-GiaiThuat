#pragma once
//========================================
void XuatMenu();
int ChonMenu(int soMenu);
//========================================
void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu sinh vien";
	cout << "\n2. Xem du lieu sinh vien";
	cout << "\n3. QuickSort";
	cout << "\n4. HeapSort";
	cout << "\n5. MergeSort";
}
int ChonMenu(int soMenu)
{
	int stt;
	do
	{
		system("CLS");
		XuatMenu();
		cout << "\nChon so de chon menu: ";
		cin >> stt;
	} while (stt < 0 || stt>soMenu);
	return stt;
}
void XuLyMenu(int menu, SinhVien sv[MAX], int &n)
{
	int kq;
	char filename[MAX] = "DSSV.txt";
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh";
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu\n";
		do
		{
			//cout << "\nNhap ten file: ";
			//cin >> filename;
			kq = DocFile(filename, sv, n);
			if (kq == 0)
				cout << "Loi mo file";
		} while (kq==0);
		cout << "Mang vua tao: \n";
		XuatDSSV(sv, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "Mang vua tao: \n";
		XuatDSSV(sv, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n4. HeapSort\n";
		cout << "Mang vua tao: \n";
		XuatDSSV(sv, n);
		QuickSort(sv, n);
		cout << "Mang duoc sap tang theo QuickSort: \n";
		XuatDSSV(sv, n);
		cout << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n3. QuickSort\n";
		cout << "Mang vua tao: \n";
		XuatDSSV(sv, n);
		HeapSort(sv, n);
		cout << "Mang duoc sap tang theo HeapSort: \n";
		XuatDSSV(sv, n);
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n3. MergeSort\n";
		cout << "Mang vua tao: \n";
		XuatDSSV(sv, n);
		MergeSort(sv, n);
		cout << "Mang duoc sap tang theo MergeSort: \n";
		XuatDSSV(sv, n);
		cout << endl;
		break;
	}
}