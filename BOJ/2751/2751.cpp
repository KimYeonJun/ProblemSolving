/*
BOJ 2751번: 수 정렬하기2 (머지소트)

*/
#include <iostream>
#define endl '\n'
using namespace std;
int N;
int arr[1000000];
int arr2[1000000];
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
void Merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}
	int tmp = i > mid ? j : i;
	while (k <= right) {
		arr2[k++] = arr[tmp++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}
void Partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Partition(left, mid);
		Partition(mid + 1, right);
		Merge(left, right);
	}
}
void Solution() {
	Partition(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}