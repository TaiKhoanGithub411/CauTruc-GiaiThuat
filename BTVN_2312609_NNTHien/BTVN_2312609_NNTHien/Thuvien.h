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
int  LinearSearch_Last(List dsnv, char name[10]);
Node* Search_MaNV(List dsnv, char manv[10]);
void InsertAfter(List& dsnv, Data x, Node* y);
Data Nhap1NV(char manv[10], char ho[10], char tenlot[10], char ten[10], int namsinh, float hsluong);
int RemoveNode_First(List& dsnv, char ten[10]);
void RemoveX(List& dsnv, char ten[10]);
void SelectionSort_NamSinh(List& dsnv);
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
int  LinearSearch_Last(List dsnv, char name[10])
{
	Node* p;
	int kq = -1, i = 0;
	p = dsnv.Head;
	while (p != NULL)
	{
		if (_strcmpi(p->infor.Ten,name)==0)
			kq = i;
		i++;
		p = p->pNext;
	}
	return kq;
}
Node* Search_MaNV(List dsnv, char manv[10])
{
	Node* vt = dsnv.Head;
	while ((vt!=NULL)&&(_strcmpi(vt->infor.MaNV,manv)!=0))
	{
		vt = vt->pNext;
	}
	return vt;
}
void InsertAfter(List& dsnv, Data x, Node* y)
{
	Node* new_nv = GetNode(x);
	if (new_nv == NULL)
	{
		cout << "\nLoi cap bo nho";
		return;
	}
	if (y != NULL)
	{
		new_nv->pNext = y->pNext;
		y->pNext = new_nv;
		if (y == dsnv.Tail)
			dsnv.Tail = new_nv;
	}
	else
	{
		new_nv->pNext = y->pNext;
		y->pNext = new_nv;
		if (y == dsnv.Tail)
		{
			dsnv.Tail = new_nv;
		}
	}
}
void InsertX_End_Y(List& dsnv, char manv[10], Data x)
{
	Node* q;
	q = Search_MaNV(dsnv, manv);
	InsertAfter(dsnv, x, q);
}
Data Nhap1NV(char manv[10], char ho[10], char tenlot[10], char ten[10], int namsinh, float hsluong)
{
	Data x;
	strcpy_s(x.MaNV, sizeof(x.MaNV), manv);
	strcpy_s(x.Ho, sizeof(x.Ho), ho);
	strcpy_s(x.TenLot, sizeof(x.TenLot), tenlot);
	strcpy_s(x.Ten, sizeof(x.Ten), ten);
	x.NamSinh = namsinh;
	x.HeSoLuong = hsluong;
	return x;
}
int RemoveNode_First(List& dsnv, char ten[10])
{
	Node* p = dsnv.Head;
	Node* q = NULL;
	while (p != NULL)
	{
		if (_strcmpi(p->infor.Ten, ten) == 0)
			break;
		q = p; p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == dsnv.Tail)
			dsnv.Tail = q;
		q->pNext = p->pNext;
	}
	else
	{
		dsnv.Head = p->pNext;
		if (dsnv.Head == NULL)
			dsnv.Tail = NULL;
	}
	delete p;
	return 1;
}
void RemoveX(List& dsnv, char ten[10])
{
	while (RemoveNode_First(dsnv, ten));
}
void SelectionSort_NamSinh(List& dsnv)
{
	Node* min, * q, * p;
	p = dsnv.Head;
	while (p!=dsnv.Tail)
	{
		min = p;
		q = p->pNext;
		while (q!=NULL)
		{
			if (q->infor.NamSinh < min->infor.NamSinh)
				min = q;
			q = q->pNext;
		}
		swap(min->infor, p->infor);
		p = p->pNext;
	}
}