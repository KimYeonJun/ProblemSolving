/*
BOJ 2470��: �� ���
���� ���� : �� ������

N ���� 100,000 �̶�, O(N^2)�� �ð� �ʰ�.
�� �����͸� ����Ͽ�, O(N)�� �ذ��غ���.

�Է¹��� �迭�� ������������ �����Ѵ�.
���� ���� �����͸� �ΰ�, �� �������� ���� ���ؼ� 0�� ������ ���� �����Ѵ�.
�� �������� ���� 0���� ũ�ٸ� ���� �۾����� �ϹǷ� right point�� ����
0���� �۴ٸ�, ���� Ŀ���� �ϹǷ� left point�� ������Ų��.
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