#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int len = s.size();
    int answer = len;
    for (int i = 1; i <= s.size() / 2; i++) {
        string result = "";
        string comp = s.substr(0, i);
        int count = 1;
        for (int j = i; j <= len; j += i) {
            // cout<<"부분 문자열 : " << s.substr(j,i)<<endl;
            if (s.substr(j, i) == comp) {

                count++;
            }
            else {
                if (count == 1) {
                    result += comp;
                }
                else {
                    result += (to_string(count) + comp);
                }
                count = 1;
                comp = s.substr(j, i);
            }
        }
        if (len % i != 0) {
            result += s.substr((len / i) * i);
        }
        if (answer > result.size()) {
            answer = result.size();
        }
        //cout<<result<<endl;

    }

    return answer;
}