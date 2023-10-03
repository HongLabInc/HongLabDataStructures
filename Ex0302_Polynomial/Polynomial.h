#pragma once

class Polynomial
{
public:
	Polynomial(int max_degree = 100);

	Polynomial(const Polynomial& poly);

	~Polynomial();

	int MaxDegree();

	void NewTerm(const float coef, const int exp);

	Polynomial Add(const Polynomial& poly);

	Polynomial Mult(const Polynomial& poly);

	float Eval(float x);

	void Print();

private:
	int capacity_ = 0; // 항상 모든 항(term)들이 다 차 있는 것은 아니기 때문에 size 대신 capacity 사용
	float* coeffs_ = nullptr;
};