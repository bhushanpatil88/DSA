public class slidingWindow {
    //643
    public double findMaxAverage(int[] nums, int k) {
        double ans=0;
        int l=0;
        double temp=0;
        for(int i=0;i<k;i++)temp+=nums[i];
        ans=temp/k;

        for(int r=k;r<nums.length;r++){
            temp += nums[r];
            if(r-l+1>k){
                temp-=nums[l++];
            }
            if(r-l+1 == k){
                ans = Math.max(ans,temp/k);
            }
            
        }
        return ans;
    }
    // 1456
    public int maxVowels(String s, int k) {
        char [] ss = s.toCharArray();
        String t = "aeiou";
        int n = s.length();
        int ans  = 0;
        int cnt = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            if(t.indexOf(ss[i])!=-1){
                cnt++;
            }
            if(i-j+1>k){
                if(t.indexOf(ss[j])!=-1)cnt--;
                j++;
            }
            ans = Math.max(ans, cnt);
        }

        return ans;
    }
    //1004
    public int longestOnes(int[] nums, int k) {
        int l = 0,r=0,n = nums.length;
        int cnt = 0,ans=0;
        for(;r<n;r++){
            if(nums[r]==0)cnt++;
            if(cnt>k){
                if(nums[l]==0)cnt--;
                l++;
            }
            ans = Math.max(ans,r-l+1);
        }

        return ans;
    }

    //1493
    public int longestSubarray(int[] nums) {
        int l = 0,r=0,n = nums.length;
       int cnt = 0,ans=0;
       int k = 1;
       for(;r<n;r++){
           if(nums[r]==0)cnt++;
           if(cnt>k){
               if(nums[l]==0)cnt--;
               l++;
           }
           ans = Math.max(ans,r-l);
       }

       return ans;
   }
}
