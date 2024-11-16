//=======================================================
void XuatMenu();
int ChonMenu(int somenu);
//=======================================================
void XuatMenu()
{
	cout << "================== Menu ======================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu nhan vien";
	cout << "\n2.Xem danh sach nhan vien";
	cout << "\n3.Dem nhan vien co he so luong >= 3.4";
	cout << "\n4.Tim kiem tuyen tinh theo ten nhan vien - tra ve node cuoi cung";
	cout << "\n5.Chen 1 nhan vien sau nhan vien co ma x";
	cout << "\n6.Xoa tat ca nhan vien co ten x";
	cout << "\n7.Chon truc tiep - tang theo nam sinh";
}
int ChonMenu(int somenu)
{
	int chon;
	for (;;)
	{
		cout << "\nNhap chon somenu: ";
		cin >> chon;
		if (chon >= 0 && chon <= somenu)
			break;
	}
	return chon;
}
void XuLyMenu(int menu, List& dsnv)
{
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1.Tao du lieu nhan vien\n";
		DocFile((char*)"dsnv.txt", dsnv);
		cout << "\nDanh sach nhan vien vua tao\n";
		XuatDSNV(dsnv);
		break;
	case 2:
		cout << "\n2.Xem danh sach nhan vien\n";
		XuatDSNV(dsnv);
		break;
	case 3:
		cout << "\n3.Dem nhan vien co he so luong >= 3.4\n";
		XuatDSNV(dsnv);
		cout << "\nSo luong nhan vien co he so luong >= 3.4 la: " << DemNV_HSLuong(dsnv) << "\n";
		break;
	}
}