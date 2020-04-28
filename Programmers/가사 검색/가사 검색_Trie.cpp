/*
프로그래머스: 가사 검색 (2020 카카오 기출)

Trie 자료구조를 사용하여 풀이
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
    int cnt;
    Trie* next[26];
    Trie() {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i])
                delete next[i];
        }
    }
    void insert(const char* word) {
        if (*word == '\0') {
            return;
        }
        int cur = *word - 'a';
        if (next[cur] == NULL) {
            next[cur] = new Trie();
        }
        next[cur]->cnt++;
        next[cur]->insert(word + 1);
    }
    int find(const char* word) {
        int cur = *word - 'a';
        if (next[cur] == NULL)
            return 0;
        if (*(word + 1) == '?') {
            return next[cur]->cnt;
        }
        return next[cur]->find(word + 1);
    }
};
Trie* root[10001];
Trie* r_root[100001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 1; i <= 10000; i++) {
        root[i] = new Trie();
        r_root[i] = new Trie();
    }
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int size = word.size();
        root[size]->insert(word.c_str());
        reverse(word.begin(), word.end());
        r_root[size]->insert(word.c_str());
    }
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int size = query.size();
        int cnt;
        if (query[0] == '?' && query[size - 1] == '?') {
            cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (root[size]->next[i])
                    cnt += root[size]->next[i]->cnt;
            }

        }
        else if (query[0] == '?') {
            reverse(query.begin(), query.end());
            cnt = r_root[size]->find(query.c_str());
        }
        else if (query[size - 1] == '?') {
            cnt = root[size]->find(query.c_str());
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