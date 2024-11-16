//==========================================================
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, NhanVien nv[MAX], int& n);
//==========================================================
void XuatMenu()
{
	cout << "================ MENU ==================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu";
	cout << "\n2.Sap tang danh sach theo ma NV - Chon truc tiep";
	cout << "\n3.Sap tang danh sah theo dia chi - Chen truc tiep";
	cout << "\n4.Sap tang danh sach theo nam sinh - Radix";
}
int ChonMenu(int soMenu)
{
	int stt;
	XuatMenu();
	for (;;)
	{
		cout << "\nChon menu: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, NhanVien nv[MAX], int& n)
{
	char filename[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1.Tao du lieu";
		do
		{
			cout << "\nNhap ten file: ";
			cin >> filename;
			kq = DocFile(filename, nv, n);
		} while (kq==0);
		cout << "\nDanh sach nhan vien da tao: \n";
		XuatDSNV(nv, n);
		break;
	case 2:
		cout << "\n2.Sap tang danh sach theo ma NV - Chon truc tiep\n";
		XuatDSNV(nv, n);
		Selection(nv, n);
		cout << "\nMang sau sap xep:\n";
		XuatDSNV(nv, n);
		break;
	case 3:
		cout << "\n3.Sap tang danh sah theo dia chi - Chen truc tiep\n";
		XuatDSNV(nv, n);
		Insertion(nv, n);
		cout << "\nMang sau sap xep:\n";
		XuatDSNV(nv, n);
		break;
	}
}

