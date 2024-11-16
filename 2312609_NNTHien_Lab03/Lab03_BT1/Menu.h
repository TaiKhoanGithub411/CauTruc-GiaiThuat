//==============================================================
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int array[MAX], int& n);
//==============================================================
void XuatMenu()
{
	cout << "=============== MENU =================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu";
	cout << "\n2.Xem du lieu";
	cout << "\n3.Chon truc tiep - dua GTNN ve cuoi mang";
	cout << "\n4.Chon truc tiep = dua GTLN ve cuoi mang";
	cout << "\n5.Chon hai dau";
	cout << "\n6.Chen truc tiep - tang ben trai";
	cout << "\n7.Chen truc tiep - tang ben phai";
	cout << "\n8.Doi cho truc tiep - GTNN ve dau mang";
	cout << "\n9.Doi cho truc tiep - GTLN ve cuoi mang";
	cout << "\n10.Buble - GTNN ve dau mang";
	cout << "\n11.Buble - GTLN ve cuoi mang";
}
int ChonMenu(int soMenu)
{
	int stt;
	do
	{
		cout << "\nChon so menu: ";
		cin >> stt;
	} while (stt < 0 || stt > soMenu);
	return stt;
}
void XuLyMenu(int menu, int array[MAX], int& n)
{
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh\n";
		break;
	case 1:
		cout << "\n1.Tao du lieu";
		do
		{
			system("CLS");
			cout << "Nhap ten file: ";
			cin >> filename;
			kq = DocFile(filename, array, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 2:
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3.Chon truc tiep - dua GTNN ve cuoi mang\n";
		XuatMang(array, n);
		Seclection_GTNN_CuoiMang(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 4:
		cout << "\n4.Chon truc tiep = dua GTLN ve cuoi mang\n";
		XuatMang(array, n);
		Selection_GTLN_CuoiMang(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 5:
		cout << "\n5.Chon hai dau\n";
		XuatMang(array, n);
		ChonHaiDau(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 6:
		cout << "\n6.Chen truc tiep - tang ben trai\n";
		XuatMang(array, n);
		Insertion_L(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 7:
		cout << "\n7.Chen truc tiep - tang ben phai\n";
		XuatMang(array, n);
		Insertion_R(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 8:
		cout << "\n8.Doi cho truc tiep - GTNN ve dau mang\n";
		XuatMang(array, n);
		Interchange_GTNN(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 9:
		cout << "\n9.Doi cho truc tiep - GTLN ve cuoi mang\n";
		XuatMang(array, n);
		Interchange_GTLN(array, n);
		cout << "\nMang sau sap xep:\n";
		XuatMang(array, n);
		break;
	case 10:
		cout << "\n10.Buble - GTNN ve dau mang\n";
		XuatMang(array, n);
		Buble_L(array, n);
		break;
	case 11:
		cout << "\n11.Buble - GTLN ve cuoi mang\n";
		XuatMang(array, n);
		Buble_R(array, n);
		break;
	}
}