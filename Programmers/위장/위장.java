/*
프로그래머스: 위장
문제 유형 : 해시

자바로 HashMap을 사용한 문제 풀이.

 */
package Programmers;
import java.util.*;
class 위장 {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        for(int i=0;i<clothes.length;i++){
            if(!map.containsKey(clothes[i][1])){
                map.put(clothes[i][1],1);
            }
            else{
                map.put(clothes[i][1],map.get(clothes[i][1])+1);
            }
        }
        Iterator<String> keys = map.keySet().iterator();
        while(keys.hasNext()){
            answer *= (map.get(keys.next())+1);
        }
        return answer-1;
    }
}