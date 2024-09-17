package Array.JAVA;

import java.util.*;

public class ArrayMedium {
    public static void main(String[] args) {

    }

    public static boolean twoSum(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                return true;
            } else if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }

    public static void sortArray(ArrayList<Integer> arr, int n) {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr.get(mid) == 0) {
                int temp = arr.get(low);
                arr.set(low, arr.get(mid));
                arr.set(mid, temp);

                low++;
                mid++;

            } else if (arr.get(mid) == 1) {
                mid++;

            } else {
                int temp = arr.get(mid);
                arr.set(mid, arr.get(high));
                arr.set(high, temp);

                high--;
            }
        }
    }

    public static int majorityElement(int[] v) {
        int n = v.length;
        int cnt = 0;
        int el = 0;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = v[i];
            } else if (el == v[i])
                cnt++;
            else
                cnt--;
        }

        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el)
                cnt1++;
        }

        if (cnt1 > (n / 2))
            return el;
        return -1;
    }

    public static long maxSubarraySum(int[] arr, int n) {
        long maxi = Long.MIN_VALUE;
        long sum = 0;

        int start = 0;
        int ansStart = -1, ansEnd = -1;
        for (int i = 0; i < n; i++) {

            if (sum == 0)
                start = i;
            sum += arr[i];

            if (sum > maxi) {
                maxi = sum;

                ansStart = start;
                ansEnd = i;
            }
            if (sum < 0) {
                sum = 0;
            }
        }

        System.out.print("The subarray is: [");
        for (int i = ansStart; i <= ansEnd; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("]n");
        return maxi;
    }

    static int maxProfit(int[] arr) {
        int maxPro = 0;
        int minPrice = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            minPrice = Math.min(minPrice, arr[i]);
            maxPro = Math.max(maxPro, arr[i] - minPrice);
        }
        return maxPro;
    }

    public static int[] RearrangebySign(int[] A, int n) {

        ArrayList<Integer> pos = new ArrayList<>();
        ArrayList<Integer> neg = new ArrayList<>();
        for (int i = 0; i < n; i++) {

            if (A[i] > 0)
                pos.add(A[i]);
            else
                neg.add(A[i]);
        }

        for (int i = 0; i < n / 2; i++) {
            A[2 * i] = pos.get(i);
            A[2 * i + 1] = neg.get(i);
        }

        return A;
    }

    public static List<Integer> nextPermutation(List<Integer> A) {
        int n = A.size();
        int bp = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (A.get(i) < A.get(i + 1)) {
                bp = i;
                break;
            }
        }
        if (bp == -1) {
            Collections.reverse(A);
            return A;
        }

        for (int i = n - 1; i > bp; i--) {
            if (A.get(i) > A.get(bp)) {
                int t = A.get(bp);
                A.set(bp, A.get(i));
                A.set(i, t);
                break;
            }
        }

        List<Integer> subList = A.subList(bp + 1, n);
        Collections.reverse(subList);
        return A;
    }

    public static ArrayList<Integer> Leaders(int[] arr, int n) {

        ArrayList<Integer> ans = new ArrayList<>();

        int max = arr[n - 1];

        ans.add(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--)
            if (arr[i] > max) {
                ans.add(arr[i]);
                max = arr[i];
            }

        return ans;

    }

    public static int longestSuccessiveElements(int[] a){
        int n = a.length;
        if(n==0)return 0;
        int len = 1;
        Set<Integer> st = new HashSet<>();
        for(int i=0;i<n;i++){
            st.add(a[i]);
        }

        for(int it:st){
            if(!st.contains(it-1)){
                int ct = 1;
                int x = it;
                while(st.contains(x+1)){
                    x += 1;
                    ct += 1;
                }
                len = Math.max(len, ct);
            }
        }

        return len;

    }

    static ArrayList<ArrayList<Integer>> zeroMatrix(ArrayList<ArrayList<Integer>> matrix, int n, int m) {


        int col0 = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix.get(i).get(j) == 0) {
                    matrix.get(i).set(0, 0);
                    if (j != 0)
                        matrix.get(0).set(j, 0);
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix.get(i).get(j) != 0) {
                    if (matrix.get(i).get(0) == 0 || matrix.get(0).get(j) == 0) {
                        matrix.get(i).set(j, 0);
                    }
                }
            }
        }
        if (matrix.get(0).get(0) == 0) {
            for (int j = 0; j < m; j++) {
                matrix.get(0).set(j, 0);
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix.get(i).set(0, 0);
            }
        }

        return matrix;
    }

    static void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i; j < matrix[0].length; j++) {
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length / 2; j++) {
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.length - 1 - j];
                matrix[i][matrix.length - 1 - j] = temp;
            }
        }
    }

    public static List<Integer> printSpiral(int[][] mat) {
        
        List<Integer> ans = new ArrayList<>();
        
        int n = mat.length; 
        int m = mat[0].length; 
        

        int top = 0, left = 0, bottom = n - 1, right = m - 1;


        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                ans.add(mat[top][i]);

            top++;

            for (int i = top; i <= bottom; i++)
                ans.add(mat[i][right]);

            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.add(mat[bottom][i]);

                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.add(mat[i][left]);

                left++;
            }
        }
        return ans;
    }

    public static int findAllSubarraysWithGivenSum(int arr[], int k) {
        int n = arr.length;
        Map<Integer,Integer> mpp = new HashMap<>();
        int preSum = 0, cnt = 0;
        mpp.put(0, 1);
        for (int i = 0; i < n; i++) {
            preSum += arr[i];
            int remove = preSum - k;
            cnt += mpp.getOrDefault(remove, 0);
            mpp.put(preSum, mpp.getOrDefault(preSum, 0) + 1);
        }
        return cnt;
    }


}
