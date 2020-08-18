/*
프로그래머스: 순위
문제 유형 : 플로이드-와샬 알고리즘

시간복잡도: O(n^3) -> O(100*100*100) 

문제 풀이
1. 플로이드 와샬 알고리즘을 사용하여, 정점과 정점사이를 연결하여 승,패를 결정한다.
2. 어떠한 정점이 승,패의 count가 n-1이라면 순위가 명확한 것이므로 정답에 추가.
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