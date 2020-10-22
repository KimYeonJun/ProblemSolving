/*
[Programmers] 배달

다익스트라를 사용하여, 한 정점에서 모든 정점까지의 최단거리를 구한다.
우선순위 큐를 사용한 다익스트라의 시간 복잡도는 O(ElogE).

플로이드 와샬도 가능하다. 플로이드 와샬의 시간 복잡도는 O(V^3)으로 이 문제에서는 비효율적이다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int dist[51];
vector<pair<int, int>> adj[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist[1] = 0;
    for (int i = 2; i <= N; i++)
        dist[i] = INF;
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int cost = cur.first;
        int idx = cur.second;
        if (dist[idx] != cost)
            continue;
        for (int i = 0; i < adj[idx].size(); i++) {
            int nxt = adj[idx][i].second;
            int ncost = adj[idx][i].first;
            if (dist[nxt] > cost + ncost) {
                dist[nxt] = cost + ncost;
                pq.push({ dist[nxt],nxt });
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }
    return answer;
}