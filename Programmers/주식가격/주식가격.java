/*
프로그래머스: 주식가격
문제유형: 스택
 */
package Programmers;
import java.util.*;
class 주식가격 {
    class Stock{
        int price;
        int idx;
        public Stock(int price,int idx){
            this.price= price;
            this.idx = idx;
        }
    }
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Stock> stk = new Stack<Stock>();
        for(int i=0;i<prices.length;i++){
            Stock stock = new Stock(prices[i],i);
            while(!stk.isEmpty()){
                if(stk.peek().price>stock.price){
                    answer[stk.peek().idx] = stock.idx - stk.peek().idx;
                    stk.pop();
                }
                else{
                    stk.push(stock);
                    break;
                }
            }
            if(stk.isEmpty()){
                stk.push(stock);
            }
        }
        while(!stk.isEmpty()){
            Stock stock = stk.pop();
            answer[stock.idx] = prices.length-1-stock.idx;
        }
        return answer;
    }
}