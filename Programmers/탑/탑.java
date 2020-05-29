/*
프로그래머스: 탑
문제 유형 : 스택

자바의 Stack Collection을 사용하여 문제 해결.
 */
package Programmers;
import java.util.*;

class 탑 {
    class Tower{
        int idx;
        int height;
        public Tower(int idx, int height){
            this.idx = idx;
            this.height = height;
        }
    }
    public int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        Stack<Tower> stk = new Stack<Tower>();
        for(int i=0;i<heights.length;i++){
            Tower cur = new Tower(i+1,heights[i]);
            int receiveIdx=0;
            while(!stk.empty()){
                Tower top = stk.peek();
                if(top.height>cur.height){
                    receiveIdx = top.idx;
                    break;
                }
                stk.pop();
            }
            stk.push(cur);
            answer[i]=receiveIdx;
        }
        return answer;
    }
}