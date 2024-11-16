#pragma once
#define MAX 100
struct SinhVien
{
	char maSV[7];
	char HoSV[10];
	char tenLot[10];
	char ten[10];
	char Lop[5];
	int namSinh;
	double DTB;
	int TichLuy;
};
//===================================================
int DocFile(char* filename, SinhVien sv[MAX], int &n);
void TieuDe();
void Xuat1SV(SinhVien sv);
void XuatDSSV(SinhVien sv[MAX], int n);
void Swap(SinhVien& sv1, SinhVien& sv2);
void Partition(SinhVien sv[MAX], int l, int r);
void QuickSort(SinhVien sv[MAX], int n);
void Shift(SinhVien sv[MAX], int l, int r);
void Creat_Heap(SinhVien sv[MAX], int n);
void HeapSort(SinhVien sv[MAX], int n);
void Ditribution(SinhVien sv[MAX], SinhVien sv1[MAX], SinhVien sv2[MAX], int n, int& h1, int& h2, int p);
void Merge(SinhVien sv1[MAX], int h1, SinhVien sv2[MAX], int h2, SinhVien sv[MAX], int p);
//===================================================
int DocFile(char* filename, SinhVien sv[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> sv[n].maSV
			>> sv[n].HoSV
			>> sv[n].tenLot
			>> sv[n].ten
			>> sv[n].Lop
			>> sv[n].namSinh
			>> sv[n].DTB
			>> sv[n].TichLuy;
		n++;
	}
	in.close();
	return 1;
}
void TieuDe()
{
	int i;
	cout << "\n";
	cout << '|';
	for (i = 1; i <= 100; i++)
		cout << '-';
	cout << '|';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << '|';
	cout << setw(10) << "MSSV"
		<< '|'
		<< setw(30) << " Ho va Ten"
		<< '|'
		<< setw(10) << "Lop"
		<< '|'
		<< setw(10) << "Nam Sinh"
		<< '|'
		<< setw(10) << "DTB"
		<< '|'
		<< setw(10) << "TichLuy"
		<< '|';
		cout << "\n";
		cout << '|';
		for (i = 1; i <= 100; i++)
			cout << "-";
		cout << '|';
		cout << "\n";
}
void Xuat1SV(SinhVien sv)
{
	cout << '|';
	cout << setiosflags(ios::left)
		<< setw(10) << sv.maSV
		<< '|'
		<< setw(10) << sv.HoSV
		<< setw(10) << sv.tenLot
		<< setw(10) << sv.ten
		<< '|'
		<< setw(10) << sv.Lop
		<< '|'
		<< setw(10) << sv.namSinh
		<< '|'
		<< setw(10) << sv.DTB
		<< '|'
		<< setw(10) << sv.TichLuy
		<< '|';
}
void XuatDSSV(SinhVien sv[MAX], int n)
{
	TieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1SV(sv[i]);
		cout << "\n";
	}
	cout << '|';
	for (int j = 1; j <= 100; j++)
		cout << "-";
	cout << '|';
	cout << "\n";
}
void Swap(SinhVien &sv1, SinhVien &sv2)
{
	SinhVien temp = sv1;
	sv1 = sv2;
	sv2 = temp;
}
void Partition(SinhVien sv[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	x = sv[(l + r) / 2];
	i = l, j = r;
	do
	{
		while (sv[i].DTB < x.DTB)
			i++;
		while (sv[j].DTB > x.DTB)
			j--;
		if (i <= j)
		{
			Swap(sv[i], sv[j]);
			i++, j--;
		}
	} while (i<=j);
	if (l < j)
		Partition(sv, l, j);
	if (i < r)
		Partition(sv, i, r);
}
void QuickSort(SinhVien sv[MAX], int n)
{
	Partition(sv, 0, n - 1);
}
void Shift(SinhVien sv[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	i = l, j = 2 * i + 1;
	x = sv[i];
	while (j<=r)
	{
		if (j < r)
			if (sv[j].DTB < sv[j + 1].DTB)
				j = j + 1;
		if (sv[j].DTB <= x.DTB)
			return;
		else
		{
			sv[i] = sv[j];
			i = j;
			j = 2 * i + 1;
			sv[i] = x;
		}
	}
}	
void Creat_Heap(SinhVien sv[MAX], int n)
{
	int l = (n - 1) / 2;
	while (l>=0)
	{
		Shift(sv, l, n - 1);
		l = l - 1;
	}
}
void HeapSort(SinhVien sv[MAX], int n)
{
	int r, i = 0;
	Creat_Heap(sv, n);
	r = n - 1;
	while (r > 0)
	{
		i++;
		Swap(sv[0], sv[r]);
		r = r - 1;
		Shift(sv, 0, r);
	}
}
void Ditribution(SinhVien sv[MAX], SinhVien sv1[MAX], SinhVien sv2[MAX], int n, int&h1, int &h2, int p)
{
	int i, k = 1, l = 0;
	h1 = 0; h2 = 0;
	do
	{
		i = 1;
		while (i <= p && l < n)
		{
			if (k == 1)
			{
				sv[h1++] = sv[l];
			}
			else
			{
				sv[h2++] = sv[l];
			}
			i++;
			l++;
		}
		k = 3 - k;
	} while (l < n);
}
void Merge(SinhVien sv1[MAX], int h1, SinhVien sv2[MAX], int h2, SinhVien sv[MAX], int p)
{
	int i1 = 0, i2 = 0, r1, r2, h = 0;
	while (i1<h1&&i2<h2)
	{
		r1 = r2 = 1;
		while ((r1 <= p) && (r2 <= p) && i1 < h1 && i2 < h2)
		{
			if (sv1[i1].DTB < sv2[i2].DTB)
			{
				sv[h++] = sv1[i1];
				r1++;
				i1++;
			}
			else
			{
				sv[h++] = sv2[i2];
				r2++;
				i2++;
			}
		}
		while (i1 < h1 && r1 <= p)
		{
			sv[h++] = sv1[i1];
			i1++; 
			r1++;
		}
		while (i2 < h2 && r2 <= p)
		{
			sv[h++] = sv2[i2];
			i2++; 
			r2++;
		}
	}
}
void MergeSort(SinhVien sv[MAX], int n)
{
	int p = 1, h1, h2;
	SinhVien sv1[MAX], sv2[MAX];
	int i = 1;
	while (p<n)
	{
		Ditribution(sv, sv1, sv2, n, h1, h2, p);
		Merge(sv1, h1, sv2, h2, sv, p);
		i++;
		p = p * 2;
	}
}