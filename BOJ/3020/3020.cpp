/*
BOJ 3020번: 개똥벌레
문제 유형 : 이분탐색

석순(bottom)과 종유석(top)의 길이를 각각의 벡터에 저장한다.
장애물의 크기(2<=H<=500,000)
N*H = 100,000,000,000 으로 완전탐색 불가능
-> 이분탐색을 사용하여, logN * H의 시간으로 해결가능.

bottom과 top을 정렬한다.
장애물의 크기(1~H)를 결정하고, bottom은 그대로, top은 (H+1-i)에 대해 이분탐색을 진행.
-> lower_bound를 사용하여 해당 크기의 가장 왼쪽 인덱스를 구한 후, 이를 Size에서 빼주면 파괴 된 장애물의 수가 나온다.
-> 이러한 방식으로 파괴 된 장애물 수의 최소값을 찾는다.


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