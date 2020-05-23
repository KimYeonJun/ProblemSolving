/*
BOJ 1740��: �ŵ�����
2020 ���α׷��ӽ� �����ڵ� 2�������� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long N;
	cin >> N;
	vector<int> binaryScale;
	while (N > 0) {
		binaryScale.push_back(N % 2);
		N /= 2;
	}
	long long result = 0;
	long long t=1;
	for (long long i = 0; i < binaryScale.size(); i++) {
		result += (binaryScale[i] * t);
		t *= 3;
	}
	cout << result;


	return 0;
}