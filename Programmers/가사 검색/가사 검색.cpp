/*
프로그래머스: 가사 검색

이분 탐색으로 풀이
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<string>> m;
unordered_map<int, vector<string>> r_m;
int compare(string& word, string& query) {
    for (int i = 0; i < word.size(); i++) {
        char w = word[i];
        char q = query[i];
        if (q == '?')
            return 0;
        if (w > q) {
            return 1;
        }
        else if (w < q)
            return -1;
    }
    return 987654321;
}
int upper(vector<string>& words, string& query) {
    int left = 0;
    int right = words.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (compare(words[mid], query) <= 0) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}
int lower(vector<string>& words, string& query) {
    int left = 0;
    int right = words.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (compare(words[mid], query) < 0) {
            left = mid + 1;
        }
        else
            right = mid;
    }
    return left;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < words.size(); i++) {
        string tmp = words[i];
        m[tmp.size()].push_back(tmp);
        reverse(tmp.begin(), tmp.end());
        r_m[tmp.size()].push_back(tmp);
    }
    for (int i = 0; i < 10001; i++) {
        if (m[i].size() > 1) {
            sort(m[i].begin(), m[i].end());
            sort(r_m[i].begin(), r_m[i].end());
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int size = query.size();
        char l = query[0];
        char r = query[size - 1];
        int cnt;
        if (l == '?' && r == '?') {
            cnt = m[size].size();
        }
        else if (l == '?') {
            reverse(query.begin(), query.end());
            cnt = upper(r_m[size],query) - lower(r_m[size],query);
        }
        else if (r == '?') {
            cnt = upper(m[size], query) - lower(m[size], query);
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    vector<string> words{"frodo", "front", "frost", "frozen", "frame", "kakao","fffffff" };
    vector<string> queries{ "fro??", "????o", "fr???", "fro???", "pro?" };
    vector<int> answer = solution(words, queries);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}