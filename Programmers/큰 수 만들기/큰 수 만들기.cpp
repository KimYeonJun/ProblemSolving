/*
프로그래머스 : 큰 수 만들기
문제 유형 : 그리디 알고리즘

문제 풀이
1. 정답의 자릿수를 구한다. (ex) number가 1924고 k가 2면 정답은 2자리
2. 각 자리수를 최대로 만든다. (십의 자리는 1,9,2만 비교 9가 최대이므로 일의 자리는 2,4 중 최대 값)
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    for (int i = number.size() - k; i > 0; i--) {
        int max = number[idx] - '0';
        for (int j = idx + 1; j <= number.size() - i; j++) {
            if (number[j] - '0' > max) {
                max = number[j] - '0';
                idx = j;
            }
        }
        idx++;
        answer += (max + '0');
    }
    return answer;
}