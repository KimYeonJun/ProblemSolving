/*
프로그래머스: 프린터
문제 유형 : Queue

Queue와 PriorityQueue를 사용하여 문제 해결.
 */
package Programmers;
import java.util.*;
class 프린터 {
    class Doc{
        int num;
        int loc;
        public Doc(int num,int loc){
            this.num = num;
            this.loc = loc;
        }
    }
    public int solution(int[] priorities, int location) {
        int answer = 1;
        Queue<Doc> que = new LinkedList<Doc>();
        PriorityQueue<Integer> p_que = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i=0;i<priorities.length;i++){
            Doc d = new Doc(priorities[i],i);
            que.add(d);
            p_que.add(priorities[i]);
        }
        while(!que.isEmpty()){
            if(que.peek().num==p_que.peek()){
                if(que.peek().loc==location){
                    return answer;
                }
                else{
                    answer++;
                    que.poll();
                    p_que.poll();
                }
            }
            else{
                que.add(que.poll());
            }
        }
        return answer;
    }
}