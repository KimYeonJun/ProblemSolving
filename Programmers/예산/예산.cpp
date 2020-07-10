/*
프로그래머스: 예산
문제 유형 : 이분탐색
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    vector<int> res;
    sort(budgets.begin(), budgets.end());
    int l = 0;
    int r = budgets[budgets.size() - 1];
    while (l <= r) {
        int mid = (l + r) / 2;
        long sum = 0;
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i] < mid)
                sum += budgets[i];
            else
                sum += mid;
        }
        if (sum > M)
            r = mid - 1;
        else {
            answer = mid;
            l = mid + 1;
        }
    }
    return answer;
}