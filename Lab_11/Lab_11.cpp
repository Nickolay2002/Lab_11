#include <iostream>
#define N 9

int size;//(R)
int array[N];//a[i]
int kbest = 0, mxs = 0;
const int n = sizeof(array) / sizeof(int);
int vbest[50][n];
int vector[n] = { 0 };

/// <summary>
/// best var
/// </summary>
void mark() 
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += vector[i] * array[i];
	}
	if (sum > size || sum < mxs)
	{
		return;
	}
	if (sum > mxs) 
	{
		mxs = sum;
		kbest = 0;
	}
	if (kbest < 50)
	{
		for (int i = 0; i < n; ++i)
		{
			vbest[kbest][i] = vector[i];
		}
		kbest++;
	}
}
/// <summary>
/// bool vector {0,1}
/// </summary>
/// <returns></returns>
bool isnext()
{
	for (int i = n - 1; i >= 0; --i)
	{
		if (vector[i] == 1)
		{
			vector[i] = 0;
		}
		else 
		{
			vector[i] = 1;
			return true;
		}
	return false;
	}
}

int main()
{
	printf_s("size of bag=");
	scanf_s("%d", &size);
	for (int i = 0; i < N; i++)
	{
		printf_s("A[%d]=", i);
		scanf_s("%d", &array[i]);
	}
	void mark();
	vector[n - 1] = 1;
	do 
	{
		mark();
	} while (isnext());
}