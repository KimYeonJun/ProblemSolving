#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    s.insert(words[0]);
    char end = words[0][words[0].size() - 1];
    for (int i = 1; i < words.size(); i++) {
        if (end != words[i][0] || s.count(words[i]) != 0) {
            answer.push_back((i % n) + 1);
            answer.push_back(i / n + 1);
            break;
        }
        s.insert(words[i]);
        end = words[i][words[i].size() - 1];
    }
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}