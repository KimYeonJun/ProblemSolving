/*
Programmers 비밀지도
문제 유형 : 비트 연산
문제 풀이 : arr1과 arr2의 값을 or 연산하여 암호화된 배열의 값을 구한다.
            암호화된 배열의 값을 이진수로 표현하여 정답을 도출한다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int val = arr1[i] | arr2[i];
        string temp;
        temp.assign(" ", n);
        for (int j = n - 1; j >= 0; j--) {
            if (val % 2 == 1) {
                temp[j] = '#';
            }
            else
                temp[j] = ' ';
            val /= 2;
        }
        answer.push_back(temp);
    }
    return answer;
}