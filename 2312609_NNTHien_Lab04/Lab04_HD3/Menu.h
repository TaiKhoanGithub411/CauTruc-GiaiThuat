//=======================================================
void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, List& l);
//=======================================================
void XuatMenu()
{
	cout << "================== MENU =====================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao danh sach nhan vien";
	cout << "\n2.Xem danh sach nhan vien";
	cout << "\n3.Tach luong nhan vien theo x";
	cout << "\n4.Tach nhan vien theo thu tu luan phien";
	cout << "\n5.Dao nguoc danh sach nhan vien";
	cout << "\n6.Sap tang theo ten, trung ten tang theo ho, trung ten va ho tang theo ten lot";
}
int ChonMenu(int somenu)
{
	int chon;
	for (;;)
	{
		cout << "\nNhap chon so menu: ";
		cin >> chon;
		if (chon >= 0 && chon <= somenu)
			break;
	}
	return chon;
}
void XuLyMenu(int menu, List& l)
{
	char filename[MAX];
	int x;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1.Tao danh sach nhan vien\n";
		DocFile((char*)"dsnv.txt", l);
		XuatDSNV(l);
		break;
	case 2:
		cout << "\n2.Xem danh sach nhan vien\n";
		XuatDSNV(l);
		break;
	case 3:
		cout << "\n3.Tach luong nhan vien theo x\n";
		XuatDSNV(l);
		cout << "\nNhap so luong: ";
		cin >> x;
		cout << endl;
		Tach_Luong_x(l, x);
		break;
	case 4:
		cout << "\n4.Tach nhan vien theo thu tu luan phien\n";
		XuatDSNV(l);
		Tach_LuanPhien(l);
		break;
	case 5:
		cout << "\n5.Dao nguoc danh sach nhan vien\n";
		XuatDSNV(l);
		DaoNguoc_DS(l);
		break;
	case 6:
		cout << "\n6.Sap tang theo ten, trung ten tang theo ho, trung ten va ho tang theo ten lot\n";
		XuatDSNV(l);
		SapTangHoTenTenLot(l);
		cout << "\nDanh sach sau khi sap xep\n";
		XuatDSNV(l);
		break;
	}
}