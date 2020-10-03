/*
BOJ 3020��: ���˹���
���� ���� : �̺�Ž��

����(bottom)�� ������(top)�� ���̸� ������ ���Ϳ� �����Ѵ�.
��ֹ��� ũ��(2<=H<=500,000)
N*H = 100,000,000,000 ���� ����Ž�� �Ұ���
-> �̺�Ž���� ����Ͽ�, logN * H�� �ð����� �ذᰡ��.

bottom�� top�� �����Ѵ�.
��ֹ��� ũ��(1~H)�� �����ϰ�, bottom�� �״��, top�� (H+1-i)�� ���� �̺�Ž���� ����.
-> lower_bound�� ����Ͽ� �ش� ũ���� ���� ���� �ε����� ���� ��, �̸� Size���� ���ָ� �ı� �� ��ֹ��� ���� ���´�.
-> �̷��� ������� �ı� �� ��ֹ� ���� �ּҰ��� ã�´�.


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
int N, H;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	vector<int> bottom(N / 2), top(N / 2);
	for (int i = 0; i < N/2; i++) {
		cin >> bottom[i] >> top[i];
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	int result = INF;
	int cnt=1;
	for (int i = 1; i <= H; i++) {
		int tmp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		tmp += top.size() - (lower_bound(top.begin(), top.end(), H + 1 - i) - top.begin());
		if (result == tmp)
			cnt++;
		else if (result > tmp) {
			result = tmp;
			cnt = 1;
		}
	}
	cout << result << " " << cnt << endl;
	
}