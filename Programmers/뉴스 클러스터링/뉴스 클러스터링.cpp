/*
cctype라이브러리의 isalpha함수를 사용하면 파라미터로 입력한 값이 알파벳인지 아닌지 반환해준다.
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
vector<string> getSubset(string str) {
    vector<string> ans;
    string tmp;
    for (int i = 0; i < str.size() - 1; i++) {
        if (!isalpha(str[i]) || !isalpha(str[i + 1]))
            continue;
        tmp = str.substr(i, 2);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        ans.push_back(tmp);
    }
    return ans;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> subset1 = getSubset(str1);
    vector<string> subset2 = getSubset(str2);
    vector<string> tmp_subset = subset2;
    if (!subset1.size() && !subset2.size())
        return 65536;
    for (int i = 0; i < subset1.size(); i++) {
        vector<string>::iterator it;
        it = find(tmp_subset.begin(), tmp_subset.end(), subset1[i]);
        if (it != tmp_subset.end()) {
            tmp_subset.erase(it);
            answer++;
        }
    }
    answer = ((double)answer / (subset1.size() + subset2.size() - answer)) * 65536;
    return answer;
}