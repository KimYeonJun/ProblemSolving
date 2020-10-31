/*
[Programmers] 기능개발
문제 유형 : 큐


*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> que;
    for (int i = 0; i < progresses.size(); i++) {
        int tmp = (100 - progresses[i]) % speeds[i];

        if (tmp == 0) {
            que.push((100 - progresses[i]) / speeds[i]);
        }
        else
            que.push((100 - progresses[i]) / speeds[i] + 1);
    }
    while (!que.empty()) {
        int cnt = 1;
        int cur = que.front(); que.pop();

        while (cur >= que.front() && !que.empty()) {
            cnt++;
            que.pop();
        }
        answer.push_back(cnt);
    }

    return answer;
}