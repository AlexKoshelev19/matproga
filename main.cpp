// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<float>> matrix = {
	{1,1,1,1,0,0,50},
	{1,2,3,0,1,0,73},
	{3,2,1,0,0,1,75},
	{-7,-3,-5,0,0,0, 0}
};

void sum_rows(vector<float> &a, const vector<float> &b)
{	
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] + b[i];
	}
}
void divide_rows(vector<float> &a, const vector<float> &b)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] / b[i];
	}
}

void product_row(vector<float> &a, float C)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] * C;
	}
}

void divide_row(vector<float> &a, float C)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] / C;
	}
}

size_t is_negative(vector<float> a)
{
	float min = a[0] ;
	size_t min_ind = -1;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] <= min && a[i] < 0) {
			min = a[i];
			min_ind = i;
		}
	}
	return min_ind;
}
size_t is_positive(vector<float> a)
{
	float max = a[0];
	size_t max_ind = -1;
	for (size_t i = 0; i < a.size() - 1; i++)   // -1, чтобы не трогать правую часть
	{
		if (a[i] >= max && a[i] > 0) {
			max = a[i];
			max_ind = i;
		}
	}
	return max_ind;
}


vector<float> get_colm(vector<vector<float>> a, size_t j)
{
	vector<float> res;
	for (size_t i = 0; i < a.size(); i++)
	{
		res.push_back(a[i][j]);
	}
	return res;
}


void norm_row(vector<float> &a, float pivot)
{
	divide_row(a, pivot);
}

size_t last_col_edit(size_t j)
{	
	size_t min_ind = -1;
	size_t last_ind = matrix[0].size() - 1;
	float min_elm = matrix[0][last_ind]/matrix[0][j];
	for (size_t k = 0; k < matrix.size()-1; k++)
	{
		if (matrix[k][last_ind] / matrix[k][j] <= min_elm)
		{
			min_elm = matrix[k][last_ind]/matrix[k][j];
			min_ind = k;
		}
	}
	return min_ind;
}

void print_matrix() {
	for (size_t k = 0; k < matrix.size(); k++)
	{
		for (size_t l = 0; l < matrix[0].size(); l++)
		{
			cout << setw(15) << matrix[k][l] ;
		}
		cout << '\n';
	}
}


void simplex(bool maximize) {
	vector<float> a;
	
	size_t j = -1;
	size_t i = -1;
	size_t last_row = matrix.size() - 1;
	float pivot;
	while(true){
		if (maximize == true) j = is_negative(matrix[last_row]);
		else j = is_positive(matrix[last_row]);
		if (j == -1) break;
		size_t i = last_col_edit(j);
		norm_row(matrix[i], matrix[i][j]);
		float temp;
		for (size_t k = 0; k < matrix.size(); k++)
		{
			if (k == i) continue;
			temp = matrix[k][j];
			vector<float> temp_vec  = matrix[i];
			product_row(temp_vec, -temp);
			sum_rows(matrix[k], temp_vec);				
		}
		print_matrix();
		cout << "--------------------------------------------------------------------------------------------------------------" << '\n';

	}
}

int main()

{
	vector<float> b = { 1,2,3,4,5 };
	vector<float> a = { 7,2,1,4,5 };
	simplex(1);
	system("pause");

    return 0;
}

