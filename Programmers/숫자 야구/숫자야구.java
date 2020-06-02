/*
프로그래머스: 숫자야구
문제유형: 완전탐색

문제풀이
1. 123~987까지 숫자를 ArrayList에 추가
2. ArrayList의 각 원소별로 baseball에 주어진 숫자들과 비교하여 조건에 충족하면 정답 추가.
 */
package Programmers;
import java.util.*;
class 숫자야구 {
    public int solution(int[][] baseball) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                if(i==j)
                    continue;
                for(int k=1;k<10;k++){
                    if(i==k||j==k)
                        continue;
                    list.add(100*i+10*j+k);
                }
            }
        }
        for(int i=0;i<list.size();i++){
            String listNum = Integer.toString(list.get(i));
            boolean flag=true;
            for(int j=0;j<baseball.length;j++){
                String num = Integer.toString(baseball[j][0]);
                int s_cnt=0;
                int b_cnt=0;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(listNum.charAt(k)==num.charAt(l)){
                            if(k==l)
                                s_cnt++;
                            else
                                b_cnt++;
                        }
                    }
                }
                if(!(s_cnt==baseball[j][1]&&b_cnt==baseball[j][2])){
                    flag=false;
                    break;
                }
            }
            if(flag)
                answer++;
        }
        return answer;
    }
}