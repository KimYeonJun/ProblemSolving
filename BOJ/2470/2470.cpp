/*
BOJ 2470번: 두 용액
문제 유형 : 투 포인터

N 제한 100,000 이라서, O(N^2)은 시간 초과.
투 포인터를 사용하여, O(N)에 해결해보자.

입력받은 배열을 오름차순으로 정렬한다.
양쪽 끝에 포인터를 두고, 두 포인터의 값을 더해서 0에 가까우면 답을 갱신한다.
두 포인터의 합이 0보다 크다면 값이 작아져야 하므로 right point를 감소
0보다 작다면, 값이 커져야 하므로 left point를 증가시킨다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 1000001
#define MOD 1000000000
using namespace std;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int answer = 2000000000;
	sort(arr, arr + N);
	int l = 0, r = N - 1;
	int answer_list[2] = { 0, };
	while (l < r) {
		int sum = arr[l] + arr[r];
		if (abs(answer) > abs(sum)) {
			answer = sum;
			answer_list[0] = arr[l];
			answer_list[1] = arr[r];
			if (answer == 0)
				break;
		}
		if (sum > 0)
			r--;
		else
			l++;
	}
	cout << answer_list[0] << " " << answer_list[1] << endl;
	return 0;
}