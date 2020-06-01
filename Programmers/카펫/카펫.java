/*
프로그래머스: 카펫
문제유형: 완전탐색
 */
package Programmers;
class 카펫 {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int sum = brown + yellow;
        int m=sum,n=1;
        for(int i=2;i<=(int)Math.floor(Math.sqrt(sum));i++){
            if(sum%i==0){
                m = sum/i;
                n = i;
                if((m-2)*(n-2) == yellow){
                    answer[0]=m;
                    answer[1]=n;
                    break;
                }
            }
        }
        return answer;
    }
}