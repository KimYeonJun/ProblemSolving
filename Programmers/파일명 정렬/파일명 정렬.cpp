/*
프로그래머스: 파일명 정렬
문제 유형: 문자열

조건에 따라 문자열 정렬.

*  sort하면 입력에 주어진 순서를 유지하지 않는다.
*  대신에, stable_sort하면 주어진 순서를 유지함(File에 idx가 필요 없음)
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct File {
    string head;
    string number;
    string tail;
    //int idx;
};
bool cmp(File f1, File f2) {
    std::transform(f1.head.begin(), f1.head.end(), f1.head.begin(), ::tolower);
    std::transform(f2.head.begin(), f2.head.end(), f2.head.begin(), ::tolower);
    if (f1.head == f2.head) {
       // if (stoi(f1.number) == stoi(f2.number))
           //return f1.idx < f2.idx;
        return stoi(f1.number) < stoi(f2.number);
    }
    return f1.head < f2.head;
}

File splitFile(string f, int idx) {
    string str = "";
    File res;
    bool flag = false;
    int startIdx, endIdx;
    for (int i = 0; i < f.size(); i++) {
        if (isdigit(f[i]) && !flag) {
            startIdx = i;
            flag = true;
        }
        else if (!isdigit(f[i]) && flag) {
            endIdx = i;
            break;
        }
    }
    res.head = f.substr(0, startIdx);
    res.number = f.substr(startIdx, endIdx - startIdx);
    res.tail = f.substr(endIdx, f.size());
   // res.idx = idx;
    return res;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fileList;
    for (int i = 0; i < files.size(); i++) {
        File file = splitFile(files[i], i);
        fileList.push_back(file);
    }
    stable_sort(fileList.begin(), fileList.end(), cmp);
    for (int i = 0; i < fileList.size(); i++) {
        string str = "";
        File file = fileList[i];
        str += file.head + file.number + file.tail;
        answer.push_back(str);
    }
    return answer;
}