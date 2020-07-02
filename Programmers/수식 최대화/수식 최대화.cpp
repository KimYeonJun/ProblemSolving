/*
īī�� ���Ͻ� 2��
���α׷��ӽ� : ���� �ִ�ȭ
���� ���� : ����

���� Ǯ��
1. �Է� expression���� �ǿ����ڿ�, �����ڸ� �����Ͽ� ����
2. ������ �켱������ ���� �����ش�.
3. ������ �켱������ ���� ���
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