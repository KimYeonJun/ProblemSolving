/*
프로그래머스: N진수 게임
문제 유형 : 구현

number배열을 사용해서 10진수 -> N진수 변환 시 깔끔하게 코드 작성이 가능.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char number[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F' };
string changeNum(int num, int n) {
    string res = "";
    if (num == 0)
        return "0";
    while (num > 0) {
        res += number[num % n];
        num /= n;
    }
    reverse(res.begin(), res.end());
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    int idx = 0;
    string str = changeNum(num++, n);
    string tmp = "";
    for (int num = 0; tmp.size() <= m * t; num++) {
        tmp += changeNum(num, n);
    }
    for (int i = 0; i < t; i++) {
        answer += tmp[i * m + (p - 1)];
    }
    /*while(t--){
        for(int i=0;i<m;i++){
            if(i==p-1){
                answer+= str[idx];
            }
            idx++;
            if(idx==str.size()){
                idx=0;
                str = changeNum(num++,n);
            }
        }
    }*/
    /* for(int i=0;i<t;i++){
         for(int j=0;j<m;j++){

         }
         string str = changeNum(num++,n);


     }*/
    return answer;
}