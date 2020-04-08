/*
Programmers �������
���� ���� : ��Ʈ ����
���� Ǯ�� : arr1�� arr2�� ���� or �����Ͽ� ��ȣȭ�� �迭�� ���� ���Ѵ�.
            ��ȣȭ�� �迭�� ���� �������� ǥ���Ͽ� ������ �����Ѵ�.
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