package Programmers;

import java.util.Stack;
class Solution {
    public int solution(String arrangement) {
        int answer = 0;
        Stack<Character> st = new Stack<Character>();
        arrangement = arrangement.replace("()","0");
        for(int i=0;i<arrangement.length();i++){
            if(arrangement.charAt(i)=='0'){
                answer += st.size();
            }
            else if(arrangement.charAt(i)=='('){
                st.push(arrangement.charAt(i));
            }
            else if(arrangement.charAt(i)==')'){
                answer += 1;
                st.pop();
            }

        }
        return answer;
    }
}
