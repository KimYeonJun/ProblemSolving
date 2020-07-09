/*
프로그래머스: 베스트앨범
문제 유형 : 해시

*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Song {
    int id;
    int play;
    string genre;
};
bool cmp(Song s1, Song s2) {
    if (s1.play == s2.play)
        return s1.id < s2.id;
    return s1.play > s2.play;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genreMap;
    unordered_map<string, vector<Song>> m;
    for (int i = 0; i < genres.size(); i++) {
        int id = i;
        int play = plays[i];
        string genre = genres[i];
        genreMap[genre] += play;
        m[genre].push_back(Song{ id,play,genre });
    }

    vector<pair<int, string>> sortedGenres;
    for (auto it = genreMap.begin(); it != genreMap.end(); it++) {
        sortedGenres.push_back({ it->second,it->first });
    }
    sort(sortedGenres.begin(), sortedGenres.end());
    for (int i = sortedGenres.size() - 1; i >= 0; i--) {
        string genre = sortedGenres[i].second;
        sort(m[genre].begin(), m[genre].end(), cmp);
        for (int j = 0; j < m[genre].size() && j < 2; j++) {
            answer.push_back(m[genre][j].id);
        }
    }

    return answer;
}