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
	char name[10], ho[10], tenlot[10], manv[10];
	int kq, namsinh;
	float hsluong;
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
	case 4:
		cout << "\n4.Tim kiem tuyen tinh theo ten nhan vien - tra ve node cuoi cung\n";
		XuatDSNV(dsnv);
		cout << "\nNhap ten can tim: ";
		cin >> name;
		kq = LinearSearch_Last(dsnv, name);
		if (!kq)
			cout << "\nNode co ten " << name << " xuat hien cuoi cung la: " << kq<<"\n";
		else
			cout << "\nKhong co ten " << name << " trong danh sach\n";
		break;
	case 5:
		system("CLS");
		cout << "\n5.Chen 1 nhan vien sau nhan vien co ma x\n";
		XuatDSNV(dsnv);
		cout << "\nNhap thong tin nhan vien can chen:";
		cout << "\nNhap ma so nhan vien: ";
		cin >> manv;
		cout << "\nNhap ho nhan vien: ";
		cin >> ho;
		cout << "\nNhap ten lot nhan vien: ";
		cin >> tenlot;
		cout << "\nNhap ten nhan vien: ";
		cin >> name;
		cout << "\nNhap nam sinh cua nhan vien: ";
		cin >> namsinh;
		cout << "\nNhap he so luong nhan vien: ";
		cin >> hsluong;
		Data x = Nhap1NV(manv, ho, tenlot, name, namsinh, hsluong);
		cout << "\nNhap ma so nhan vien can chen sau: ";
		cin >> manv;
		cout << "\nThong tin nhan vien can chen: \n";
		Xuat1NV(x);
		InsertX_End_Y(dsnv, manv, x);
		cout << "\nDanh sach nhan vien sau khi chen\n";
		XuatDSNV(dsnv);
		break;
	case 6:
		cout << "\n6.Xoa tat ca nhan vien co ten x\n";
		XuatDSNV(dsnv);
		cout << "\nnhap ten can xoa : ";
		cin >> name;
		RemoveX(dsnv, name);
		cout << "\nDanh sach sau khi xoa ten " << name << "\n";
		XuatDSNV(dsnv);
		break;
	case 7:
		cout << "\n7.Chon truc tiep - tang theo nam sinh\n";
		XuatDSNV(dsnv);
		SelectionSort_NamSinh(dsnv);
		cout << "\nDanh sach sau khi sap xep\n";
		XuatDSNV(dsnv);
		break;
	}
}