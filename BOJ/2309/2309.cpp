#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 9
#define MAX 100


int solution(int *arr,int sum) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				arr[i] = -1;
				arr[j] = -1;

				return 0;
			}
		}
	}
	return -1;
}
int main() {
	
	int arr[N];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	solution(arr, sum);
	sort(arr, arr + N);
	for (int i = 2; i < N; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}