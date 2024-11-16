struct SinhVien
{
	char maSV[8];
	char ho[15];
	char ten[10];
	int namSinh;
	char nguyenQuan[15];
};
struct tagNode
{
	SinhVien infor;
	tagNode* pNext;
};
typedef tagNode NODE;
struct List
{
	NODE* Head;
	NODE* Tail;
};
struct DiemTP
{
	char maSV[8];
	double dBT1;
	double dBT2;
	double dGk;
	double dQT;
};
struct tagNodeDiem
{
	DiemTP info;
	tagNodeDiem* pNext;
};
typedef tagNodeDiem NODEBD;
struct BangDiem
{
	NODEBD* pHead;
	NODEBD* pTail;
};
//============================================================
NODE* GetNode(SinhVien sv);
void CreatList_SinhVien(List& l);
void InsertTail_SinhVien(List& l, SinhVien sv);
int DocFile_SinhVien(char* filename, List& l);
NODEBD* GetNode_BD(DiemTP diem);
void CreatList_BD(BangDiem &bd);
void InsertTail_BD(BangDiem& bd, DiemTP diem);
int DocFile_BD(char* filename, BangDiem& bd);
void TieuDe();
void XuatBD(List l, BangDiem bd);
//============================================================
NODE* GetNode(SinhVien sv)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->infor = sv;
		p->pNext = NULL;
	}
	return p;
}
void CreatList_SinhVien(List& l)
{
	l.Head = l.Tail = NULL;
}
void InsertTail_SinhVien(List& l, SinhVien sv)
{
	NODE* new_ele = GetNode(sv);
	if (new_ele == NULL)
	{
		cout << "Khong du bo nho";
		_getch();
		return;
	}
	if (l.Head == NULL)
	{
		l.Head = new_ele;
		l.Tail = l.Head;
	}
	else
	{
		l.Tail->pNext = new_ele;
		l.Tail = new_ele;
	}
}
int DocFile_SinhVien(char* filename, List& l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	SinhVien sv;
	CreatList_SinhVien(l);
	while (!in.eof())
	{
		in >> sv.maSV;
		in >> sv.ho;
		in >> sv.ten;
		in >> sv.namSinh;
		in >> sv.nguyenQuan;
		InsertTail_SinhVien(l, sv);
	}
	in.close();
	return 1;
}
NODEBD* GetNode_BD(DiemTP diem)
{
	NODEBD* p = new NODEBD;
	if (p != NULL)
	{
		p->info = diem;
		p->pNext = NULL;
	}
	return p;
}
void CreatList_BD(BangDiem& bd)
{
	bd.pHead = bd.pTail = NULL;
}
void InsertTail_BD(BangDiem& bd, DiemTP diem)
{
	NODEBD* new_diem = GetNode_BD(diem);
	if (new_diem == NULL)
	{
		cout << "Khong du bo nho";
		_getch();
		return;
	}
	if (bd.pHead == NULL)
	{
		bd.pHead = new_diem;
		bd.pTail = bd.pHead;
	}
	else
	{
		bd.pTail->pNext = new_diem;
		bd.pTail = new_diem;
	}
}
int DocFile_BD(char* filename, BangDiem& bd)
{
	ifstream in(filename);
	if (!in)
		return 0;
	DiemTP diem;
	CreatList_BD(bd);
	while (!in.eof())
	{
		in >> diem.maSV;
		in >> diem.dBT1;
		in >> diem.dBT2;
		in >> diem.dGk;
		diem.dQT = diem.dBT1 + diem.dBT2 + diem.dGk;
		InsertTail_BD(bd, diem);
	}
	in.close();
	return 1;
}
void TieuDe()
{
	cout << setiosflags(ios::left);
	cout << setw(10) << "Ma SV"
		<< setw(16) << "Ho"
		<< setw(11) << "Ten"
		<< setw(6) << "NSinh"
		<< setw(8) << "DiemGK";
}
void XuatBD(List l, BangDiem bd)
{
	TieuDe();
	NODE* p = l.Head;
	NODEBD* b = bd.pHead;
	while (p!=NULL &&b!=NULL)
	{
		cout << endl;
		cout << setiosflags(ios::left)
			<< setw(10) << p->infor.maSV
			<< setw(16) << p->infor.ho
			<< setw(11) << p->infor.ten
			<< setw(6) << p->infor.namSinh
			<< setw(8) << setprecision(2) << setiosflags(ios::fixed) << b->info.dQT;
		p = p->pNext;
		b = b->pNext;
	}
}