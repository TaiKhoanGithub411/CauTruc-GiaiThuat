//======================================================
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int array[MAX], int& n);
//======================================================
void XuatMenu()
{
	cout << "=========== MENU =============";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu";
	cout << "\n2.Chon truc tiep - Selection_R";
	cout << "\n3.Chon hai dau - Selection_R_L";
	cout << "\n4.Chen truc tiep - Insertion_R";
	cout << "\n5.Doi cho truc tiep - Interchange_R";
	cout << "\n6.Noi bot - Buble_Sort";
	cout << "\n7.Shaker Sort";
}
int ChonMenu(int soMenu)
{
	int stt;
	do
	{
		system("CLS");
		XuatMenu();
		cout << "\nChon so menu: ";
		cin >> stt;
	} while (0>stt&&stt>soMenu);
	return stt;
}
void XuLyMenu(int menu, int array[MAX], int& n)
{
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1.Tao du lieu";
		do
		{
			system("CLS");
			cout << "\nNhap ten tap tin: ";
			cin >> filename;
			kq = DocFile(filename, array, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 2:
		cout << "\n2.Chon truc tiep - Selection_R";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		Selection_R(array, n);
		cout << "\nMang sau khi sap xep\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3.Chon hai dau - Selection_R_L";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		Selection_R_L(array, n);
		cout << "\nMang sau khi sap xep\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 4:
		cout << "\n4.Chen truc tiep - Insertion_R";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		Insertion_R(array, n);
		cout << "\nMang sau khi sap xep\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 5:
		cout << "\n5.Doi cho truc tiep - Interchange_R";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		InterChange_R(array, n);
		cout << "\nMang sau khi sap xep\n";
		XuatMang(array, n);
		cout << endl;
		break;
	case 6:
		cout << "\n6.Noi bot - Buble_Sort";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		Buble_R(array, n);
		break;
	case 7:
		cout << "\n7.Shaker Sort";
		cout << "\nMang vua tao:\n";
		XuatMang(array, n);
		Shaker(array, n);
		cout << "\nMang sau khi sap xep\n";
		XuatMang(array, n);
		cout << endl;
		break;
	}
}