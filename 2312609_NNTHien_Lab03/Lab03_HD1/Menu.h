#pragma once
//===============================================
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int& n);
//===============================================
void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Chon truc tiep";
	cout << "\n4. Chen truc tiep";
	cout << "\n5. Doi cho truc tiep";
	cout << "\n6. Noi bot";
	cout << "\n7. Chen nhi phan";
	cout << "\n8. Radix";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so de chon menu: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu,int a[MAX], int&n)
{
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin: ";
			cin >> filename;
			kq = DocFile(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao\n";
		Xuat(a, n);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		cout << "\nMang vua tao:\n";
		Xuat(a, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Chon truc tiep\n";
		Xuat(a, n);
		ChonTrucTiep(a,n);
		cout << "\nMang sap tang theo chon truc tiep la: \n";
		Xuat(a, n);
		break;
	case 4:
		cout << "\n4. Chen truc tiep\n";
		Xuat(a, n);
		ChenTrucTiep(a, n);
		cout << "\nMang sap tang theo chen truc tiep la: \n";
		Xuat(a, n);
		break;
	case 5:
		cout << "\n5. Doi cho truc tiep\n";
		Xuat(a, n);
		DoiChoTrucTiep(a, n);
		cout << "\nMang sap tang theo doi cho truc tiep la: \n";
		Xuat(a, n);
		break;
	case 6:
		cout << "\n6. Doi cho truc tiep\n";
		Xuat(a, n);
		NoiBot(a, n);
		cout << "\nMang sap tang theo noi bot la: \n";
		Xuat(a, n);
		break;
	case 7:
		cout << "\n7. Chen nhi phan\n";
		Xuat(a, n);
		ChenNhiPhan(a, n);
		cout << "\nMang sap tang theo doi chen nhi phan la: \n";
		Xuat(a, n);
		break;
	case 8:
		cout << "\n7. Chen nhi phan\n";
		Xuat(a, n);
		RadixSort(a, n);
		cout << "\nMang sap tang theo doi chen nhi phan la: \n";
		Xuat(a, n);
		break;
	}
}
