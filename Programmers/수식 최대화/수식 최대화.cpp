/*
카카오 인턴십 2번
프로그래머스 : 수식 최대화
문제 유형 : 구현

문제 풀이
1. 입력 expression에서 피연산자와, 연산자를 구분하여 추출
2. 연산자 우선순위를 직접 정해준다.
3. 연산자 우선순위에 따라 계산
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long calc(long long l1, long long l2, char op) {
    if (op == '+')
        return l1 + l2;
    else if (op == '-')
        return l1 - l2;
    else
        return l1 * l2;
}
long long getResult(vector<long long> num_list, vector<char> op_list, vector<char> op_comb) {
    for (int i = 0; i < op_comb.size(); i++) {
        for (int j = 0; j < op_list.size(); j++) {
            if (op_list[j] == op_comb[i]) {
                num_list[j] = calc(num_list[j], num_list[j + 1], op_list[j]);
                num_list.erase(num_list.begin() + (j + 1));
                op_list.erase(op_list.begin() + j);
                j--;
            }
        }
    }
    return abs(num_list[0]);
}
long long solution(string expression) {
    long long answer = 0;
    vector<long long> num_list;
    vector<char> op_list;
    string num = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            op_list.push_back(expression[i]);
            num_list.push_back(stoll(num));
            num = "";
            continue;
        }
        num += expression[i];
    }
    num_list.push_back(stoll(num));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'+', '-', '*'}));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'+', '*', '-'}));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'-', '*', '+'}));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'-', '+', '*'}));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'*', '-', '+'}));
    answer = max(answer, getResult(num_list, op_list, vector<char>{'*', '+', '-'}));
    return answer;
}