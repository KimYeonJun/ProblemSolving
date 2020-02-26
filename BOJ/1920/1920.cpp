#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int N,M;
/*
BOJ 1920 : �� ã��
Linear�ϰ� Ž���ϸ� n������ 100000�̹Ƿ� 100000 * 100000 = 10000000000�̶�� ��û�� �ð����⵵�� �����Ƿ�
�̺�Ž���� ����Ͽ� ������ Ǯ�����
Solution1�� �ݺ����� ����� �̺�Ž��
Solution2�� ��͸� ����� �̺�Ž��.

*/
int *A;
int *B;
int middle;
bool flag;
void Input() {
	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	B = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
}
bool search_binary(int *A, int first, int last, int target) {
	if (first > last)
		return false;
	middle = (first + last)/2;
	if (A[middle] == target) {
		return true;
	}
	else if (A[middle] > target) {
		last = middle - 1;
		return search_binary(A, first, last, target);
	}
	else {
		first = middle + 1;
		return search_binary(A, first, last, target);
	}
	
}
void Solution2() {
	sort(A, A + N);
	for (int i = 0; i < M; i++) {
		flag=search_binary(A, 0, N-1, B[i]);
		if (flag == false) {
			cout << "0" << endl;
		}
		else
			cout << "1" << endl;
	}
}
void Solution1() {
	sort(A, A+N);
	int flag;
	for (int i = 0; i < M; i++) {
		flag = 0;
		int first = 0;
		int last = N - 1;
		int middle = (first + last) / 2;
		while (first <= last) {
			if (B[i] == A[middle]) {
				flag = 1;
				break;
			}
			else if(B[i]> A[middle]){
				first = middle + 1;

			}
			else {
				last = middle - 1;
			}
			middle = (first + last) / 2;
		}
		if (flag == 1) {
			cout << "1" << endl;
		}
		else
			cout << "0" << endl;
	}
}
void Solve() {
	Input();
	Solution1();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();

	return 0;
}