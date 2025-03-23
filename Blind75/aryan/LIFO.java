import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Stack;

public class LIFO {

    // 2390
    public String removeStars(String s) {
        Stack<Character> st = new Stack<>();
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)!='*')st.push(s.charAt(i));
            else{
                if(!st.isEmpty())st.pop();
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!st.isEmpty()){
            sb.insert(0,st.peek());
            st.pop();
        }

        return sb.toString();
    }

    // 735
    public int[] asteroidCollision(int[] nums) {
        Stack<Integer> st = new Stack<>();

        for(int i = 0;i<nums.length;i++){
            if(nums[i]>0)st.push(nums[i]);
            else{
                while(!st.isEmpty() && st.peek() > 0 && st.peek() < -1*nums[i] )st.pop();

                if(!st.isEmpty() && st.peek() == -1*nums[i] )st.pop();
                else{
                    if(st.isEmpty() || st.peek() < 0){
                        st.push(nums[i]);
                    }
                }
            }
        }
        int[] arr = new int[st.size()];
        for (int i = 0; i < st.size(); i++) {
            arr[i] = st.get(i);
        }
        return arr;
    }

    // 394
    public String decodeString(String s) {
        Deque<Integer> st = new ArrayDeque<>();
        Deque<StringBuilder> st1 = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();
        int n = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                n = n * 10 + (c - '0');
            } else if (c == '[') {
                st.push(n);
                n = 0;
                st1.push(sb);
                sb = new StringBuilder();
            } else if (c == ']') {
                int k = st.pop();
                StringBuilder temp = sb;
                sb = st1.pop();
                while (k-- > 0) {
                    sb.append(temp);
                }
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}
