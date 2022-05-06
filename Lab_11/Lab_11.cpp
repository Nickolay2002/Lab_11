﻿#include <iostream>
#define N 9
#define MAX_BEST 10

using namespace std;

int load_capacity;//(R)
int ITEMS[N];//a[i]
int current_best_index = 0, max_sum = 0;
const int n = sizeof(ITEMS) / sizeof(int);
int vbest[MAX_BEST][n + 1];
int vector[n + 1] = { 0,0,0,0,0,0,0,0,0,  /*set_sum*/0 };

void clear_vector(int* array, int size = n + 1)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}

#pragma region 1st_task
/// <summary>
/// 
/// </summary>
void mark1()
{
	int current_sum = 0;
	for (int i = 0; i < n; ++i)
	{
		current_sum += vector[i] * ITEMS[i];
	}
	vector[n] = current_sum;//set sum
	if (current_sum > load_capacity)
	{
		return;
	}
	//if (current_sum > max_sum)
	//{
	//	max_sum = current_sum;
	//	current_best_index = 0;
	//}
	//
	//{
	//	for (int i = 0; i < n; ++i)
	//	{
	//		vbest[current_best_index][i] = vector[i];  //vbest[current_best_index]    vector  (0101010)  (7)set_sum 7
	//	}
	//	
	//}
	for (size_t i = 0; i < MAX_BEST; i++)
	{
		if (current_sum < vbest[i][n])
		{
			// insert(array, el, index)

			// right shift tail
			int tail = max(current_best_index, MAX_BEST - 1);
			for (size_t j = tail; j > i; j--)
			{
				for (int i = 0; i < n + 1; ++i)
				{
					vbest[j][i] = vbest[j - 1][i];
				}
			}
			// vbest[current_i] = vector
			for (int j = 0; j < n + 1; ++j)
			{
				vbest[i][j] = vector[j];
			}

		}
	}
	if (current_best_index < MAX_BEST)
	{
		current_best_index++;
	}

}//     v0  v1  v4  v6   v7  v8           vbest
// i:   0   1   2   3    4   5  | 6        
//     0.5 -1 - 2 - 3 -  7 - 10 | 00000          set_sum 
//  v9 sum 6

bool isnext1()
{
	for (int i = n - 1; i >= 0; --i)
	{
		if (vector[i] == 1)
		{
			vector[i] = 0;
		}
		else //vector[i] == 0
		{
			vector[i] = 1;
			return true;
		}
	}
	return false;
}
void enumerate1()
{
	vector[n - 1] = 1;
	do
	{
		mark1();
	} while (isnext1());
}
#pragma endregion

#pragma region 2nd_task
void mark2()
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += vector[i] * ITEMS[i];
	}
	if (sum > load_capacity || sum < max_sum)
	{
		return;
	}
	if (sum > max_sum)
	{
		max_sum = sum;
		current_best_index = 0;
	}
	if (current_best_index < 50)
	{
		for (int i = 0; i < n; ++i)
		{
			vbest[current_best_index][i] = vector[i];
		}
		current_best_index++;
	}
}
bool isnext2()
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
#pragma endregion

#pragma region 3rd_task
void mark3()
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += vector[i] * ITEMS[i];
	}
	if (sum > load_capacity || sum < max_sum)
	{
		return;
	}
	if (sum > max_sum)
	{
		max_sum = sum;
		current_best_index = 0;
	}
	if (current_best_index < 50)
	{
		for (int i = 0; i < n; ++i)
		{
			vbest[current_best_index][i] = vector[i];
		}
		current_best_index++;
	}
}
bool isnext3()
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
#pragma endregion

#pragma region 4th_task
void mark4()
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += vector[i] * ITEMS[i];
	}
	if (sum > load_capacity || sum < max_sum)
	{
		return;
	}
	if (sum > max_sum)
	{
		max_sum = sum;
		current_best_index = 0;
	}
	if (current_best_index < 50)
	{
		for (int i = 0; i < n; ++i)
		{
			vbest[current_best_index][i] = vector[i];
		}
		current_best_index++;
	}
}
bool isnext4()
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
#pragma endregion

int main()
{
	printf_s("size of bag=");
	scanf_s("%d", &load_capacity);
	for (int i = 0; i < N; i++)
	{
		printf_s("A[%d]=", i);
		scanf_s("%d", &ITEMS[i]);
	}
	enumerate1();
//TODO print result: vbest[n] (set_sum) , вывести vbest и соответсвующее веса элементов (ITEMS) 
	clear_vector(vector);
}