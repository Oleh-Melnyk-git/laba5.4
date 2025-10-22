#include <iostream>
#include <cmath>
using namespace std;

double S1(const double K, double N)
{
	 	double s = 0;
	 	for (int i = K; i <= N; i++)
	 	{
	 		s += ((K * K) / (N * N)) * cos((N * N) / (K * K));
	 	}
	 	return s;
}

double S2(const double K, const double N, double i)
 	{
	 	if (i > N)
	 		return 0;
	 	else
	 		return ((K * K) / (N * N)) * cos((N * N) / (K * K))  + S2(K, N, i + 1);
}

double S3(const double K, const double N, double i)
{
	 	if (i < K)
	 		return 0;
	 	else
	 		return ((K * K) / (N * N)) * cos((N * N) / (K * K))  + S3(K, N, i - 1);
}

double S4(const double K, const double N, double i, double s)
{
	 	s += ((K * K) / (N * N)) * cos((N * N) / (K * K));
	 	if (i >= N)
	 		return s;
	 	else
	 		return S4(K, N, i + 1, s);
}

double S5(const double K, const double N, double i, double s)
{
	 	s += ((K * K) / (N * N)) * cos((N * N) / (K * K));
	 	if (i <= K)
	 		return s;
		  	else
	 		return S5(K, N, i - 1, s);
}

int main()
{
	 	int K;
	 	int N;

	 	cout << "N = "; cin >> N;
	 	cout << "K = "; cin >> K;

	  	cout << "P1 = " << S1(K, N) << endl;
	 	cout << "P2 = " << S2(K, N, N) * 10 << endl;
	 	cout << "P3 = " << S3(K, N, N) << endl;
	 	cout << "P4 = " << S4(K, N, N, 0) * 10 << endl;
	 	cout << "P5 = " << S5(K, N, N, 0) << endl;

	 	return 0;
}
