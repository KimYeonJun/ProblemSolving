/*
���α׷��ӽ�: ���߿켱����ť
���� ���� : ��(Heap)

�������� �켱���� ť, �������� �켱���� ť 2���� �̿��� Ǯ ���� ������
deque 1���� ����� ǰ.
���� ������ ������ ���� �ϰ� �ִ밪 or �ּҰ� ����
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