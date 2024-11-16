//=========================================
void XuatMenu();
int ChonMenu(int soMenu);
//=========================================
void XuatMenu()
{
	cout << "=============== MENU ==================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu";
	cout << "\n2.Xem du lieu";
	cout << "\n3.Tim x - Co/Khong";
	cout << "\n4.Tim x - Tra ve nut dau neu co";
	cout << "\n5.Tim x - Tra ve nut cuoi neu co";
	cout << "\n6.Tim x - Xuat tat ca nut neu co";
	cout << "\n7.Chen x vao dau danh sach";
	cout << "\n8.Chen x vao cuoi danh sach";
	cout << "\n9.Chen x sau nut co du lieu y xuat hien dau tien";
	cout << "\n10.Chen x sau nut co du lieu y xuat hien cuoi cung";
	cout << "\n11.Huy nut dau danh sach";
	cout << "\n12.Huy nut cuoi danh sach";
	cout << "\n13.Huy nut x dau tien";
	cout << "\n14.Huy nut x cuoi cung";
	cout << "\n15.Huy tat ca nut x";
	cout << "\n16.Huy toan bo danh sach";
	cout << "\n17.Sap tang - Chon truc tiep (hoan doi du lieu)";
	cout << "\n18.Sap tang - Chon truc tiep (hoan doi lien ket)";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		cout << "\nChon menu: ";
		cin >> stt;
		if (stt >= 0 && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, List& a)
{
	char filename[MAX];
	Data x, y;
	NODE* vt;
	int kq;
	List b;
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
			_flushall();
			cin >> filename;
			kq = DocFile(filename, a);
			if (!kq)
				cout << "\nLoi mo file";
		} while (!kq);
		cout << "\nDanh sach vua tao:\n";
		XuatDS(a);
		cout << endl;
		break;
	case 2:
		cout << "\n2.Xem du lieu";
		cout << "\nDanh sach vua tao:\n";
		XuatDS(a);
		cout << endl;
		break;
	case 3:
		cout << "\n3.Tim x - Co/Khong\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		vt = Search_YN(a, x);
		if (vt != NULL)
			cout << "\nCo " << x << " trong danh sach";
		else
			cout << "\nKhong co " << x << " trong danh sach";
		break;
	case 4:
		cout << "\n4.Tim x - Tra ve nut dau neu co\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		kq = Search_First(a, x);
		if (kq == -1)
			cout << "Khong co " << x << "  trong danh sach\n";
		else
			cout << x << " xuat hien dau tien tai " << kq << "\n";
	case 5:
		cout << "\n5.Tim x - Tra ve nut cuoi neu co\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		kq = Search_VTLast(a, x);
		if (kq != -1)
			cout << x << " xuat hien cuoi tai nut " << kq << "\n";
		else
			cout << x << " khong co trong danh sach";
		break;
	case 6:
		cout << "\n6.Tim x - Xuat tat ca nut neu co\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		cout << endl;
		Search_VTAll(a, x);
		break;
	case 7:
		cout << "\n7.Chen x vao dau danh sach\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		InsertFirst(a, x);
		cout << "\nDanh sach sau khi chen\n";
		XuatDS(a);
		cout << endl;
		break;
	case 8:
		cout << "\n8.Chen x vao cuoi danh sach\n";
		XuatDS(a);
		cout << endl;
		cout << "Nhap x: ";
		cin >> x;
		InsertTail(a, x);
		cout << "\nDanh sach sau khi chen\n";
		XuatDS(a);
		cout << endl;
		break;
	case 9:
		cout << "\n9.Chen x sau nut co du lieu y xuat hien dau tien\n";
		XuatDS(a);
		cout << endl;
		cout << "\nNhap x can chen: ";
		cin >> x;
		cout << "\nNhap y can chen x sau: ";
		cin >> y;
		InsertX_First_Y(a, y, x);
		cout << "\Danh sach sau khi chen\n";
		XuatDS(a);
		break;
	case 10:
		cout << "\n10.Chen x sau nut co du lieu y xuat hien cuoi cung\n";
		XuatDS(a);
		cout << endl;
		cout << "\nNhap x can chen: ";
		cin >> x;
		cout << "\nNhap y can chen x sau: ";
		cin >> y;
		InsertX_End_Y(a, y, x);
		cout << "\Danh sach sau khi chen\n";
		XuatDS(a);
		break;
	case 11:
		cout << "\n11.Huy nut dau danh sach\n";
		XuatDS(a);
		cout << endl;
		RemoveHead(a);
		cout << "\nDanh sach sau khi xoa\n";
		XuatDS(a);
		cout << endl;
		break;
	case 12:
		cout << "\n12.Huy nut cuoi danh sach\n";
		XuatDS(a);
		cout << endl;
		RemoveTail(a);
		cout << "\nDanh sach sau khi xoa\n";
		XuatDS(a);
		cout << endl;
		break;
	case 13:
		cout << "\n13.Huy nut x dau tien\n";
		XuatDS(a);
		cout << endl;
		cout << "\nNhap x can xoa: ";
		cin >> x;
		kq = RemoveNode_First(a, x);
		if (!kq)
			cout << "\n" << x << " khong co trong danh sach";
		else
		{
			cout << "\nDanh sach sau khi xoa " << x << " dau tien\n";
			XuatDS(a);
			cout << endl;
		}
		break;
	}
}