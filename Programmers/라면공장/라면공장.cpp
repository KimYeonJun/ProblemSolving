/*
프로그래머스: 라면공장
문제 유형 : 힙(Heap)
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int idx = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < k; i++) {
        if (idx < dates.size() && i == dates[idx]) {
            pq.push(supplies[idx++]);
        }
        if (stock == 0) {
            int cur = pq.top();
            pq.pop();
            stock += cur;
            answer++;
        }
        stock--;
    }
    return answer;
}