/*
프로그래머스: 섬 연결하기
문제 유형 : 그리디, MST, 크루스칼

1. cost 오름차순으로 정렬
2. 두 섬이 같은 그룹이 아니라면 그룹화하고 cost 추가
    2.1 같은 그룹이라면 continue;
3. 그룹에 모든 섬이 포함되면 종료
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int parent[101];
int level[101];
bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[2] < v2[2];
}
int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (level[u] < level[v])
        parent[u] = v;
    else
        parent[v] = u;
    if (level[u] == level[v])
        level[u]++;
    return true;

}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        level[i] = 1;
    }
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < costs.size(); i++) {
        int isl_1 = costs[i][0];
        int isl_2 = costs[i][1];
        int cost = costs[i][2];
        if (!uni(isl_1, isl_2))
            continue;
        answer += cost;
        if (n == (++cnt))
            break;
    }
    return answer;
}