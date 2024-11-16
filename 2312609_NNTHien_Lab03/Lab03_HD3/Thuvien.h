#define MAX 100
//=================================================
int DocFile(char* filename, int array[MAX], int& n);
void XuatMang(int array[MAX], int n);
void Swap(int& a, int& b);
void Selection_R(int array[MAX], int n);
void Selection_R_L(int array[MAX], int n);
void Insertion_R(int array[MAX], int n);
void InterChange_R(int array[MAX], int n);
void Buble_R(int array[MAX], int n);
void Shaker(int array[MAX], int n);
//=================================================
int DocFile(char* filename, int array[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> array[i];
	in.close();
	return 1;
}
void XuatMang(int array[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << "\t";
}
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Selection_R(int array[MAX], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int max = n - 1 - i;
		for (int j = n - 2 - i; j >= 0; j--) 
		{
			if (array[j] > array[max])
			{
				max = j;
			}
		}
		Swap(array[n - 1 - i], array[max]);
	}
}
void Selection_R_L(int array[MAX], int n)
{
	int i, j, cs_min, cs_max;
	for (i = 0; i < n / 2; i++)
	{
		cs_min = i;
		cs_max = n - 1 - i;
		for (j = i; j <= n - 1 - i; j++)
		{
			if (array[j] < array[cs_min])
				cs_min = j;
			if (array[j] > array[cs_max])
				cs_max = j;
		}
		if (cs_min == n - i - 1)
		{
			Swap(array[i], array[cs_min]);
			if (cs_max != i) //?
				Swap(array[cs_max], array[n - i - 1]);
		}
		else
		{
			Swap(array[cs_max], array[n - i - 1]);
			Swap(array[i], array[cs_min]);
		}
	}
}
void Insertion_R(int array[MAX], int n)
{
	int pos, i, x;
	for (i = n - 2; i >= 0; i--)
	{
		x = array[i];
		for (pos = i + 1; (pos < n) && (array[pos] < x); pos++)
			array[pos - 1] = array[pos];
		array[pos - 1] = x;
	}
}
void Buble_R(int array[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < n - 1; i++)
			if (array[i] > array[i + 1])
				Swap(array[i + 1], array[i]);
		cout << "\nBuoc " << n - j << ":\n";
		XuatMang(array, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
}
void InterChange_R(int array[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
			if (array[i] > array[j])
				Swap(array[i], array[j]);
	}
}
void Shaker(int array[MAX], int n)
{
	int l = 0, r = n - 1, k = n - 1, j, buoc = 0;
	while (l<r)
	{
		buoc++;
		j = r;
		while (j>l)
		{
			if (array[j] < array[j - 1])
			{
				Swap(array[j], array[j - 1]);
				k = j;
				cout << "\nk = " << k;
			}
			j = j - 1;
		}
		l = k, j = 1;
		while (j<r)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
				k = j;
			}
			j = j + 1;
		}
		r = k;
	}
}