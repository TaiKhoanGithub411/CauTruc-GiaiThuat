#define MAX 100
struct NhanVien
{
	char maNV[10];
	char hoNV[10];
	char tenLot[10];
	char tenNV[10];
	char diaChi[10];
	int namSinh;
	int luongNV;
};
//======================================================
int DocFile(char* filename, NhanVien nv[MAX], int& n);
void Xuat1NV(NhanVien nv);
void XuatTieuDe();
void XuatDSNV(NhanVien nv[MAX], int n);
void Swap(NhanVien& a, NhanVien& b);
//======================================================
int DocFile(char* filename, NhanVien nv[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> nv[n].maNV;
		in >> nv[n].hoNV;
		in >> nv[n].tenLot;
		in >> nv[n].tenNV;
		in >> nv[n].diaChi;
		in >> nv[n].namSinh;
		in >> nv[n].luongNV;
		n++;
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	cout << setiosflags(ios::left)
		<< "|"
		<< setw(10) << "MaNV"
		<< "|"
		<< setw(10) << "Ho"
		<< setw(20) << "Ten Lot"
		<< setw(10) << "Ten"
		<< "|"
		<< setw(10) << "Dia chi"
		<< "|"
		<< setw(10) << "NamSinh"
		<< "|"
		<< setw(10) << "Luong"
		<< "|";
	cout << "\n";
}
void Xuat1NV(NhanVien nv)
{
	cout << setiosflags(ios::left)
		<< "|"
		<< setw(10) << nv.maNV
		<< "|"
		<< setw(10) << nv.hoNV
		<< setw(20) << nv.tenLot
		<< setw(10) << nv.tenNV
		<< "|"
		<< setw(10) << nv.diaChi
		<< "|"
		<< setw(10) << nv.namSinh
		<< "|"
		<< setw(10) << nv.luongNV
		<< "|";
}
void XuatDSNV(NhanVien nv[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1NV(nv[i]);
		cout << "\n";
	}
}
void Swap(NhanVien& a, NhanVien& b)
{
	NhanVien temp = a;
	a = b;
	b = temp;
}
void Selection(NhanVien nv[MAX], int n)
{
	int min, i, j;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if ((string)nv[min].maNV > (string)nv[j].maNV)
				min = j;
		}
		Swap(nv[min], nv[i]);
	}
}
void Insertion(NhanVien nv[MAX], int n)
{
	NhanVien x;
	int i, pos;
	for (i = 1; i < n; i++)
	{
		x = nv[i];
		for (pos = i - 1; pos >= 0 && (string)nv[pos].diaChi > (string)x.diaChi; pos--)
			nv[pos + 1] = nv[pos];
		nv[pos + 1] = x;
	}
}