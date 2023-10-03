#pragma once

class Matrix
{
public:
	Matrix(int num_rows, int num_cols);

	Matrix(const Matrix& b);

	~Matrix();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	Matrix Add(const Matrix& b);

	Matrix Transpose();

	void Print();

private:
	float* values_ = nullptr;
	int num_rows_ = 0;
	int num_cols_ = 0;
};
