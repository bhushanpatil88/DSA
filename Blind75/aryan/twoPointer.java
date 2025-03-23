import java.util.Arrays;

public class twoPointer {
    // 283
    public void moveZeroes(int[] nums) {
        int j = 0;
        int n = nums.length;
        while(j<n){if(nums[j]==0)break;j++;}


        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }
    // 392
    public boolean isSubsequence(String s, String t) {
        char[] sarry = s.toCharArray();
        char[] tarry = t.toCharArray();
        int i=0, j=0;
        while(i<sarry.length && j<tarry.length){
            if(sarry[i] == tarry[j]){
                i++;
            }
            j++;
        }
        return (i==sarry.length);
    }
    // 11
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

    //1679
    public int maxOperations(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int cnt = 0;
        int l = 0, r = n-1;
        while(l<r){
            int sum = nums[l] + nums[r];
            if(sum==k){
                cnt++;
                l++;
                r--;
            }else if(sum<k)l++;
            else r--;
        }

        return cnt;
    }
}
