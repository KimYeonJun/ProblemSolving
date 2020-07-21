/*
프로그래머스: 이중우선순위큐
문제 유형 : 힙(Heap)

내림차순 우선순위 큐, 오름차순 우선순위 큐 2개를 이용해 풀 수도 있지만
deque 1개를 사용해 품.
삭제 연산이 들어오면 정렬 하고 최대값 or 최소값 삭제
*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            dq.push_back(stoi(operations[i].substr(2)));
        }
        else {
            if (dq.size() == 0)
                continue;
            sort(dq.begin(), dq.end());
            if (operations[i][2] == '1')
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
    if (dq.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        sort(dq.begin(), dq.end());
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}