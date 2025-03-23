package striver;

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

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            if(mp.containsKey(target-nums[i])){
                return new int[]{i, mp.get(target-nums[i])};
            }
            mp.put(nums[i], i);
        }

        return new int[]{};
    }
    
    public int maxProfit(int[] prices) {
        int buy = Integer.MAX_VALUE;
        int ans = 0;
        for(int i = 0;i<prices.length;i++){
            buy = Math.min(buy, prices[i]);
            ans = Math.max(ans, prices[i] - buy);
        }
        return ans;
    }

    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 1;i<n;i++){
            if(nums[i]==nums[i-1])return true;
        } 
        return false;  
    }

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

    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = 0;i<nums.length;i++){
            sum += nums[i];
            ans = Math.max(ans,sum);
            if(sum<0)sum = 0;
        }
        return ans;
    }

    public int maxProduct(int[] nums) {
        int n = nums.length;

        int pre = 1, suff = 1;
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            pre *= nums[i];
            suff *= nums[n - i - 1];
            ans = Math.max(ans, Math.max(pre, suff));
        }
        return ans;
    }

    public static int findMin(int []arr) {
        int low = 0, high = arr.length - 1;
        int ans = Integer.MAX_VALUE;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[low] <= arr[high]) {
                ans = Math.min(ans, arr[low]);
                break;
            }
            if (arr[low] <= arr[mid]) {
                ans = Math.min(ans, arr[low]);
                low = mid + 1;

            } else {
                ans = Math.min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }

    public int search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<=nums[mid])h = mid-1;
                else l = mid+1;
            }else{
                if(nums[mid]<=target && target<=nums[h])l = mid+1;
                else h = mid-1;
            }
        }
        return -1;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
        
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)j++;
                else if(sum > 0 )k--;
                else{
                    ans.add(Arrays.asList(nums[i], nums[j],nums[k]));
                    while(++j<k && nums[j]==nums[j-1]);
                    while(j<--k && nums[k]==nums[k+1]);
                }
            }
        }
        return ans;
    }

    public int maxArea(int[] h) {
        int n = h.length;
        int l = 0, r = n-1;
        int ans = 0;
        while(l<r){
            int area  = Math.min(h[l],h[r])*(r-l);
            ans = Math.max(ans,area);
            if(h[l]<h[r])l++;
            else r--;
        }
        return ans;
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

