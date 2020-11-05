/*
[BOJ] 1543번: 문서 검색
문자 유형 : 문자열

<조심할 점>
문서의 길이보다 검색하는 단어의 길이가 작음이 보장하지 않는다.
이로 인해, 런타임에러가 발생한다.
문제 꼼꼼히 읽기!

<문제 풀이>
문서의 길이만큼 반복문을 돌리면서
검색하는 단어와 동일한 구간이 나오면 정답에 추가하고, 그 길이만큼 건너뛴다.

*/
#include <stdio.h>
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
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int answer = 0;
	if (a.size() < b.size()) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i <= a.size()-b.size(); i++) {
		bool flag = true;
		for (int j = i; j < i + b.size(); j++) {
			if (a[j] != b[j - i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer++;
			i += b.size() - 1;
		}
	}
	cout << answer << endl;
}