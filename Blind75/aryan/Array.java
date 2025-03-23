import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;



public class Array
{
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    // 1768
    public String mergeAlternately(String word1, String word2) {
        StringBuilder s = new StringBuilder();
        int n1 = word1.length();
        int n2 = word2.length();
        int n = Math.min(n1,n2);
        int i;
        for(i = 0;i<n;i++){
            s.append(word1.charAt(i));
            s.append(word2.charAt(i));
        }
        if(n1>n2){
            while(i<n1){
                s.append(word1.charAt(i));
                i++;
            }
        }
        else{
            while(i<n2){
                s.append(word2.charAt(i));
                i++;
            }
        }

        return s.toString();

    }

    // 1071
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2 + str1))return "";   
        
        int g = (int)gcd((long)str1.length(),(long)str2.length());

        return str1.substring(0, g);
    }

    // 1431
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxi = 0;
        for(int c:candies)maxi = Math.max(maxi, c);

        List<Boolean> l = new ArrayList<>();
        for(int c:candies){
            if(c+extraCandies >= maxi)l.add(true);
            else l.add(false);
        }
        return l;
    }

    // 605
    public boolean canPlaceFlowers(int[] f, int n) {
        int cnt = 0;
        if(n==0)return true;
        if(f.length==1){
            if(f[0]==0)return true;
            else return false;
        }
        for(int i = 0;i<f.length;i++){
            if(f[i]==1)continue;
            if(i==0){
                if(f[i+1]==0){f[i] = 1;cnt++;}
            }
            else if(i==f.length-1){
                if(f[i-1]==0){
                    f[i] = 1;
                    cnt++;
                }
            }
            else{
                if(f[i-1]==0 && f[i+1]==0){f[i] = 1;cnt++;}
            }
        }

        return cnt>=n;
    }
    

    // 345
    public String reverseVowels(String s) {
        char[] word = s.toCharArray();
        int l = 0,r = s.length()-1;

        String vowels = "aeiouAEIOU";

        while(l<r){
            while(l<r && vowels.indexOf(word[l])==-1)l++;
            while(l<r && vowels.indexOf(word[r])==-1)r--;

            if(l<r){
                char temp = word[l];
                word[l] = word[r];
                word[r] = temp;
                l++;
                r--;
            }
        }

        return new String(word);
    }

    // 151
    public String reverseWords(String s) {
        StringTokenizer st = new StringTokenizer(s);
        StringBuilder str = new StringBuilder();

        while(st.hasMoreTokens()){
            String token1 = st.nextToken();
            str.insert(0,token1 + " ");
        }

        return str.toString().trim();

    }

    // 238
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int [] ans = new int[n];
        int zeros = 0;
        int product1 = 1, product2 = 1;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                zeros++;
            }
            else product1 *= nums[i];
            product2 *= nums[i];
        }

        for(int i=0;i<n;i++){
            if(zeros>1)ans[i] = 0;
            else if(zeros==1 && nums[i]==0)ans[i] = product1;
            else if(zeros==1)ans[i] = 0;
            else ans[i] = product2/nums[i];
        }
        return ans;
    }
    
    //334 
    public boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for (int n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }
        return false;
    }

    //443
    public int compress(char[] chars) {
        int ind = 0;
        int n = chars.length;
        for(int i = 0;i<n;i++){
            char ch = chars[i];
            int cnt = 0;
            while(i<n && chars[i]==ch){
                cnt++;
                i++;
            }

            if(cnt==1){
                chars[ind] = ch;ind++;
            }
            else{
                chars[ind] = ch;
                ind++;
                for(char c: Integer.toString(cnt).toCharArray()){
                    chars[ind] = c;
                    ind++;
                }
            }
            i--;
        }
        return ind;   
    }

    public static void solve() throws Exception{
    }
    
    public static void main(String hi[]) throws Exception
    {
        try {
            
            int T=in.nextInt();
            while(T-- > 0){
                solve();
            }
            out.close();
        } catch (Exception e) {
            return;
        }
        
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readArr(int N){
            int [] arr = new int[N];
            for(int i = 0;i<N;i++)
                arr[i] = in.nextInt();
            return arr;
        }
    }

    public static void print(int[] arr)
    {
        for(int x: arr)
            out.print(x+" ");
        out.println();
    }
    public static boolean isPrime(long n)
    {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }
    public static long gcd(long a, long b)
    {
        if(a > b)
            a = (a+b)-(b=a);
        if(a == 0L)
            return b;
        return gcd(b%a, a);
    }
    public static long totient(long n)
    {
        long result = n;
        for (int p = 2; p*p <= n; ++p)
            if (n % p == 0)
            {
                while(n%p == 0)
                    n /= p;
                result -= result/p;
            }
        if (n > 1)
            result -= result/n;
        return result;
    }
    public static ArrayList<Integer> findDiv(int N)
    {
        ArrayList<Integer> ls1 = new ArrayList<Integer>();
        ArrayList<Integer> ls2 = new ArrayList<Integer>();
        for(int i=1; i <= (int)(Math.sqrt(N)+0.00000001); i++)
            if(N%i == 0)
            {
                ls1.add(i);
                ls2.add(N/i);
            }
        Collections.reverse(ls2);
        for(int b: ls2)
            if(b != ls1.get(ls1.size()-1))
                ls1.add(b);
        return ls1;
    }
    public static void sort(int[] arr)
    {
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static long power(long x, long y, long p)
    {
        long res = 1L;
        x = x%p;
        while(y > 0)
        {
            if((y&1)==1)
                res = (res*x)%p;
            y >>= 1;
            x = (x*x)%p;
        }
        return res;
    }
       
}

