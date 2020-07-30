/*
���α׷��ӽ�: �� �����ϱ�
���� ���� : �׸���, MST, ũ�罺Į

1. cost ������������ ����
2. �� ���� ���� �׷��� �ƴ϶�� �׷�ȭ�ϰ� cost �߰�
    2.1 ���� �׷��̶�� continue;
3. �׷쿡 ��� ���� ���ԵǸ� ����
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