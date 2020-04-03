/*
Programmers �ֽİ���
���� ���� : ����Ž��
���� Ǯ�� : 
            Solution : ����Ž������ O(N^2)
            Solution2 : ������ ����� ����Ž������ Solution���� ���� �ɸ� �� �˾Ҵµ� ū ���̴� ����. ���� O(N^2)
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<int> solution2(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> stk;
    for (int i = 0; i < prices.size(); i++) {
        while (!stk.empty()) {
            if (prices[i] < stk.top().first) {
                answer[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            else {
                stk.push(make_pair(prices[i], i));
                break;
            }
        }
        if (stk.empty())
            stk.push(make_pair(prices[i], i));
    }
    while (!stk.empty()) {
        answer[stk.top().second] = prices.size() - stk.top().second - 1;
        stk.pop();
    }
    return answer;
}
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int cnt = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            cnt++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}