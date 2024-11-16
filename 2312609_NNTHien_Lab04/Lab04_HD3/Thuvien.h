#define MAX 100
struct NhanVien
{
	char maNV[8];
	char hoNV[10];
	char tenLot[10];
	char ten[10];
	char diachi[12];
	int namSinh;
	int luong;
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
//================================================
Node* GetNode(Data nv);
void CreatList(List& l);
int IsEmpty(List l);
void InsertHead(List& l, Data nv);
void InsertTail(List& l, Data nv);
int DocFile(char* filename, List& l);
void XuatTieuDe();
void Xuat1NV(Data nv);
void XuatDSNV(List l);
void Tach_Luong_x(List l, int x);
void Tach_LuanPhien(List l);
void DaoNguoc_DS(List l);
void Swap(Data& x, Data& y);
void SapTangTen(List& l);
void SapTangHoTenTenLot(List& l);
//================================================
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
void CreatList(List& l)
{
	l.Head = l.Tail = NULL;
}
int IsEmpty(List l)
{
	if (l.Head == NULL)
		return 1;
	return 0;
}
void InsertHead(List& l, Data nv)
{
	Node* new_nv = GetNode(nv);
	if (new_nv == NULL)
	{
		cout << "Loi cap phat bo nho";
		return;
	}
	if (l.Head == NULL)
	{
		l.Head = new_nv;
		l.Tail = l.Head;
	}
	else
	{
		new_nv->pNext = l.Head;
		l.Head = new_nv;
	}
}
void InsertTail(List& l, Data nv)
{
	Node* new_nv = GetNode(nv);
	if (new_nv == NULL)
	{
		cout << "Loi cap phat bo nho";
		return;
	}
	if (l.Head == NULL)
	{
		l.Head = new_nv;
		l.Tail = l.Head;
	}
	else
	{
		l.Tail->pNext = new_nv;
		l.Tail = new_nv;
	}
}
int DocFile(char* filename, List& l)
{
	Data x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(l);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoNV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.diachi;
		in >> x.namSinh;
		in >> x.luong;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	cout << setiosflags(ios::left)
		<< setw(10) << "MaNV"
		<< setw(10) << "Ho"
		<< setw(10) << "TenLot"
		<< setw(10) << "Ten"
		<< setw(15) << "DiaChi"
		<< setw(10) << "NamSinh"
		<< setw(20) << "Luong";
	cout << endl;
}
void Xuat1NV(Data nv)
{
	cout << setiosflags(ios::left)
		<< setw(10) << nv.maNV
		<< setw(10) << nv.hoNV
		<< setw(10) << nv.tenLot
		<< setw(10) << nv.ten
		<< setw(15) << nv.diachi
		<< setw(10) << nv.namSinh
		<< setw(20) << nv.luong;
	cout << endl;
}
void XuatDSNV(List l)
{
	XuatTieuDe();
	Node* p = l.Head;
	while (p!=NULL)
	{
		Xuat1NV(p->infor);
		p = p->pNext;
	}
}
void Tach_Luong_x(List l, int x)
{
	Node* p;
	List l1, l2;
	p = l.Head;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	CreatList(l1);
	CreatList(l2);
	while (p != NULL)
	{
		if (p->infor.luong <= x)
			InsertTail(l1, p->infor);
		else
			InsertTail(l2, p->infor);
		p = p->pNext;
	}
	cout << "\n- Danh sach l1 (luong <= " << x << "):\n";
	XuatDSNV(l1);
	cout << "\n- Danh sach l2 (luong > " << x << "):\n";
	XuatDSNV(l2);
	cout << endl;
}
void Tach_LuanPhien(List l)
{
	Node* p;
	List l1, l2;
	p = l.Head;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	int k = 1;
	CreatList(l1);
	CreatList(l2);
	while (p != NULL)
	{
		if (k == 1)
			InsertTail(l1, p->infor);
		else
			InsertTail(l2, p->infor);
		p = p->pNext;
		k = 3 - k;
	}
	cout << "\n- Danh sach l1:\n";
	XuatDSNV(l1);
	cout << "\n- Danh sach l2 :\n";
	XuatDSNV(l2);
	cout << endl;
}
void DaoNguoc_DS(List l)
{
	Node* p;
	List l1;
	p = l.Head;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	CreatList(l1);
	while (p != NULL)
	{
		InsertHead(l1, p->infor);
		p = p->pNext;
	}
	cout << "\n- Danh sach dao nguoc cua l:\n";
	XuatDSNV(l1);
}
void Swap(Data& x, Data& y)
{
	Data temp = x;
	x = y;
	y = temp;
}
void SapTangTen(List& l)
{
	Node* min, * p, * q;
	p = l.Head;
	while (p!=l.Tail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (_strcmpi(q->infor.ten, min->infor.ten) < 0)
				min = q;
			q = q->pNext;
		}
		Swap(min->infor, p->infor);
		p = p->pNext;
	}
}
void SapTangHoTenTenLot(List& l)
{
	SapTangTen(l);
	Node* p, * q;
	for (p = l.Head; p != l.Tail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->infor.ten, q->infor.ten) == 0)
				if (_strcmpi(p->infor.hoNV, q->infor.hoNV) > 0)
					Swap(q->infor, p->infor);
	for (p = l.Head; p != l.Tail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->infor.ten, q->infor.ten) == 0 && _strcmpi(p->infor.hoNV, q->infor.hoNV) == 0)
				if (_strcmpi(p->infor.tenLot, q->infor.tenLot) > 0)
					Swap(q->infor, p->infor);
}