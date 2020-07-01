#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, arr[i] * (i + 1));
	}
	cout << answer << endl;
	return 0;
}