#pragma once

// 앞 예제와 구분하기 위해 Array2D 라는 이름 사용
// 내용은 Matrix와 동일
class Array2D
{
public:
	Array2D(int num_rows, int num_cols);

	Array2D(const Array2D& b);

	~Array2D();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	Array2D Add(const Array2D& b);

	Array2D Transpose();

	void Print();

private:
	float** arrays_ = nullptr; // 2중 포인터
	int num_rows_ = 0;
	int num_cols_ = 0;
};
