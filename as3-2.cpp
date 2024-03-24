#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>

using namespace std;
void merge(int* array, int left, int right, int mid)
{
	int i, j, n, c[1000];
	i = left;
	n = left;
	j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (array[i] > array[j])
		{
			c[n] = array[i];
			n++;
			i++;
		}
		else
		{
			c[n] = array[j];
			n++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[n] = array[i];
		n++;
		i++;
	}
	while (j <= right)
	{
		c[n] = array[j];
		n++;
		j++;
	}
	for (i = left; i < n; i++)
	{
		array[i] = c[i];
	}
}

void mergesort(int* array, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(array, left, mid);
		mergesort(array, mid + 1, right);
		merge(array, left, right, mid);
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	int n, d, S = 0;
	cout << "Введіть кількість елементів прогресії: ";
	cin >> n;
	int* A = new int[n];
	cout << "Перший член арифметичної прогресії: ";
	cin >> A[0];
	cout << "Введіть різницю прогресії: ";
	cin >> d;
	cout << "Елементи прогресії:" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = A[0] + d * i;
		S = S + A[i];
		cout << A[i] << endl;
	}
	cout << "Сума прогресії: " << S << endl;
	mergesort(A, 0, n);
	cout << "Посортований масив: " << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << endl;
	return 0;

}
