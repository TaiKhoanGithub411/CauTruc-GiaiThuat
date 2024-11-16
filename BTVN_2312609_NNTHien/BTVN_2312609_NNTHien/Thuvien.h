struct NhanVien
{
	char MaNV[10];
	char Ho[10];
	char TenLot[10];
	char Ten[10];
	int NamSinh;
	float HeSoLuong;
};
typedef NhanVien Data;
struct tagNode
{
	Data infor;
	tagNode* pNext;
};
typedef tagNode Node;
struct List
{
	Node* Head;
	Node* Tail;
};
//===================================================================
Node* GetNode(Data nv);
void CreatList(List& dsnv);
int IsEmpty(List dsnv);
void InsertTail(List& dsnv, Data nv);
int DocFile(char* filename, List& dsnv);
void XuatTieuDe();
void Xuat1NV(Data nv);
void XuatDSNV(List dsnv);
//===================================================================
Node* GetNode(Data nv)
{
	Node* p = new Node;
	if (p != NULL)
	{
		p->infor = nv;
		p->pNext = NULL;
	}
	return p;
}
void CreatList(List& dsnv)
{
	dsnv.Head = dsnv.Tail = NULL;
}
int IsEmpty(List dsnv)
{
	if (dsnv.Head != NULL)
		return 1;
	return 0;
}
int DocFile(char* filename, List& dsnv)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(dsnv);
	Data nv;
	while (!in.eof())
	{
		in >> nv.MaNV;
		in >> nv.Ho;
		in >> nv.TenLot;
		in >> nv.Ten;
		in >> nv.NamSinh;
		in >> nv.HeSoLuong;
		InsertTail(dsnv, nv);
	}
	in.close();
	return 1;
}
void InsertTail(List& dsnv, Data nv)
{
	Node* new_nv = GetNode(nv);
	if (new_nv == NULL)
	{
		cout << "Loi cap phat bo nho";
		return;
	}
	else if (dsnv.Head == NULL)
	{
		dsnv.Head = new_nv;
		dsnv.Tail = dsnv.Head;
	}
	else
	{
		dsnv.Tail->pNext = new_nv;
		dsnv.Tail = new_nv;
	}
}
void XuatTieuDe()
{
	cout << setiosflags(ios::left)
		<< setw(10) << "MaNV"
		<< setw(10) << "Ho"
		<< setw(10) << "TenLot"
		<< setw(10) << "Ten"
		<< setw(10) << "NamSinh"
		<< setw(10) << "HSLuong";
	cout << endl;
}
void Xuat1NV(Data nv)
{
	cout << setiosflags(ios::left)
		<< setw(10) << nv.MaNV
		<< setw(10) << nv.Ho
		<< setw(10) << nv.TenLot
		<< setw(10) << nv.Ten
		<< setw(10) << nv.NamSinh
		<< setw(10) << nv.HeSoLuong;
	cout << endl;
}
void XuatDSNV(List dsnv)
{
	XuatTieuDe();
	Node* p = dsnv.Head;
	while (p != NULL)
	{
		Xuat1NV(p->infor);
		p = p->pNext;
	}
}
int DemNV_HSLuong(List dsnv)
{
	Node* p;
	int dem=0;
	for (p = dsnv.Head; p != dsnv.Tail; p = p->pNext)
	{
		if (p->infor.HeSoLuong >= 3.4)
			dem++;
	}
	return dem;
}