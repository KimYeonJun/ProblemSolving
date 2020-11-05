/*
[BOJ] 1543��: ���� �˻�
���� ���� : ���ڿ�

<������ ��>
������ ���̺��� �˻��ϴ� �ܾ��� ���̰� ������ �������� �ʴ´�.
�̷� ����, ��Ÿ�ӿ����� �߻��Ѵ�.
���� �Ĳ��� �б�!

<���� Ǯ��>
������ ���̸�ŭ �ݺ����� �����鼭
�˻��ϴ� �ܾ�� ������ ������ ������ ���信 �߰��ϰ�, �� ���̸�ŭ �ǳʶڴ�.

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