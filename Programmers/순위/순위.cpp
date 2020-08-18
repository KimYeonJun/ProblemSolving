/*
���α׷��ӽ�: ����
���� ���� : �÷��̵�-�ͼ� �˰���

�ð����⵵: O(n^3) -> O(100*100*100) 

���� Ǯ��
1. �÷��̵� �ͼ� �˰����� ����Ͽ�, ������ �������̸� �����Ͽ� ��,�и� �����Ѵ�.
2. ��� ������ ��,���� count�� n-1�̶�� ������ ��Ȯ�� ���̹Ƿ� ���信 �߰�.
*/
#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool d[105][105];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < results.size(); i++) {
        d[results[i][0]][results[i][1]] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (d[j][i] && d[i][k]) {
                    d[j][k] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i][j] || d[j][i])
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}