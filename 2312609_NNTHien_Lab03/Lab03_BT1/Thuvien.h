#define MAX 100
//================================================
int DocFile(char* filename, int array[MAX], int& n);
void XuatMang(int array[MAX], int n);
void Swap(int& a, int& b);
void Seclection_GTNN_CuoiMang(int array[MAX], int n);
void Selection_GTLN_CuoiMang(int array[MAX], int n);
void ChonHaiDau(int array[MAX], int n);
void Insertion_L(int array[MAX], int n);
void Insertion_R(int array[MAX], int n);
void Interchange_GTNN(int array[MAX], int n);
void Interchange_GTLN(int array[MAX], int n);
void Buble_L(int array[MAX], int n);
void Buble_R(int array[MAX], int n);
//================================================
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
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Seclection_GTNN_CuoiMang(int array[MAX], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = n - 1 - i;
		for (j = n - 2 - i; j >= 0; j--)
		{
			if (array[j] < array[min])
				min = j;
			Swap(array[n - 1 - i], array[min]);
		}
	}
}
void Selection_GTLN_CuoiMang(int array[MAX], int n)
{
	int i, j, max;
	for (i = 0; i < n - 1; i++)
	{
		max = n - 1 - i;
		for (j = n - 2 - i; j >= 0; j--)
		{
			if (array[j] > array[max])
				max = j;
			Swap(array[n - 1 - i], array[max]);
		}
	}
}
void ChonHaiDau(int array[MAX], int n)
{
	int j, i, max, min;
	for (i = 0; i < n / 2; i++)
	{
		min = i, max = n - 1 - i;
		for (j = i; j <= n - 1 - i; j++)
		{
			if (array[j] < array[min])
				min = j;
			if (array[j] > array[max])
				max = j;
		}
		if (min == n - 1 - i)
		{
			Swap(array[i], array[min]);
			if (max != i)
				Swap(array[max], array[n - 1 - i]);
		}
		else
		{
			Swap(array[max], array[n - i - 1]);
			Swap(array[i], array[min]);
		}
	}
}
void Insertion_L(int array[MAX], int n)
{
	int i, x, pos;
	for (i = n - 2; i >= 0; i--)
	{
		x = array[i];
		for (pos = i + 1; (pos < n) && (array[pos] < x); pos++)
			array[pos - 1] = array[pos];
		array[pos - 1] = x;
	}
}
void Insertion_R(int array[MAX], int n)
{
	int i, x, pos;
	for (i = n - 2; i >= 0; i--)
	{
		x = array[i];
		for (pos = i + 1; (pos < n) && (array[pos] > x); pos++)
		{
			array[pos - 1] = array[pos];
		}
		array[pos - 1] = x;
	}
}
void Interchange_GTNN(int array[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (array[j] < array[i])
				Swap(array[i], array[j]);
}
void Interchange_GTLN(int array[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
		for (i = 0; i < j; i++)
			if (array[i] > array[j])
				Swap(array[i], array[j]);
}
void Buble_L(int array[MAX], int n)
{
	int i, j;
	for (j = 0; j < n - 1; j++)
	{
		for (i = n - 1; i > j; i--)
		{
			if (array[i] < array[i - 1])
			{
				Swap(array[i], array[i - 1]);
			}
		}
		cout << "\nBuoc: " << j + 1 << " : ";
		XuatMang(array, n);
		cout << "\n";
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
		cout << "\nBuoc: " << n - j << " : ";
		XuatMang(array, n);
		cout << "\n";
	}
}