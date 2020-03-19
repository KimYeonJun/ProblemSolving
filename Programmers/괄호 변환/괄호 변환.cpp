#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


string solution(string p) {
    string answer = "";
    if (p.size() == 0)
        return "";
    int l = 0;
    int r = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            l++;
        else
            r++;
        if (r == l) {
            int cnt = 0;
            bool flag = true;
            for (int j = 0; j <= i; j++) {
                if (p[j] == '(') {
                    cnt++;
                }
                else
                    cnt--;
                if (cnt < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) { //u가 올바른 괄호 문자열

                return p.substr(0, i + 1) + solution(p.substr(i + 1));
            }
            else { //u가 올바른 괄호 문자열이 아니다.
                string u = p.substr(0, i + 1);
                string v = p.substr(i + 1);
                string temp = "(" + solution(v) + ")";
                for (int j = 1; j < u.size() - 1; j++) {
                    if (u[j] == '(')
                        temp += ')';
                    else {
                        temp += '(';
                    }
                }
                return temp;
            }
        }
    }
    return answer;
}