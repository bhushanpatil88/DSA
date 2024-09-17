package Array.JAVA;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ArrayEasy {
    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // System.out.println(findLargestElement(arr));
        // System.out.println(secondLargest(arr));
        // System.out.println(secondSmallest(arr));
        moveZeros(arr);
    }

    static int findLargestElement(int arr[]) {
        int maxi = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }
        return maxi;
    }

    static int secondSmallest(int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return -1;
        }
        int small = (int) 1e9;
        int second_small = (int) 1e9;
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] < small) {
                second_small = small;
                small = arr[i];
            } else if (arr[i] < second_small && arr[i] != small) {
                second_small = arr[i];
            }
        }
        return second_small;
    }

    static int secondLargest(int[] arr) {
        int n = arr.length;
        if (n < 2)
            return -1;
        int large = (int) -1e9;
        int second_large = (int) -1e9;
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] > large) {
                second_large = large;
                large = arr[i];
            }

            else if (arr[i] > second_large && arr[i] != large) {
                second_large = arr[i];
            }
        }
        return second_large;
    }

    static boolean isSorted(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }

        return true;
    }

    static int removeDuplicates(int[] arr) {
        int n = arr.length;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (arr[i] != arr[j]) {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;
    }

    static void leftRotateBy1(int[] arr) {
        int n = arr.length;
        int temp = arr[0];
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1];
        }
        arr[n - 1] = temp;
        System.out.println(arr);
    }

    private static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static void leftRotate(int[] arr, int k) {
        int n = arr.length;
        k = k % n;
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        reverse(arr, 0, n - 1);
        System.out.println(arr);
    }

    public static void rightRotate(int[] arr, int k) {
        int n = arr.length;
        k = k % n;
        reverse(arr, 0, n - k - 1);
        reverse(arr, n - k, n - 1);
        reverse(arr, 0, n - 1);
        System.out.println(arr);
    }

    public static void printArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void moveZeros(int[] arr) {
        int n = arr.length;
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                j = i;
                break;
            }
        }
        for (int i = j + 1; i < n; i++) {
            if (arr[i] != 0) {
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
                j++;
            }
        }
        printArray(arr);
    }

    public static List<Integer> Union(int[] arr1, int[] arr2, int n, int m) {
        int i = 0, j = 0;
        List<Integer> l = new ArrayList<>();
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                if (l.isEmpty() || l.get(l.size() - 1) != arr1[i]) {
                    l.add(arr1[i]);
                }
            } else {
                if (l.isEmpty() || l.get(l.size() - 1) != arr2[j]) {
                    l.add(arr2[j]);
                }
            }
            i++;
            j++;
        }

        while (i < n) {
            if (l.isEmpty() || l.get(l.size() - 1) != arr1[i]) {
                l.add(arr1[i]);
            }
            i++;
        }

        while (j < m) {
            if (l.isEmpty() || l.get(l.size() - 1) != arr2[j]) {
                l.add(arr2[j]);
            }
            j++;
        }

        return l;
    }

    public static int missingNumber(int[] arr) {
        int x = 0;
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            x ^= arr[i];
            x ^= (i + 1);
        }
        x ^= n;

        return x;
    }

    static int maxOnes(int[] arr){
        int maxi = 0, cnt = 0;
        int n = arr.length;
        for(int i = 0;i<n;i++){
            if(arr[i]==1){
                cnt++;
            }
            else cnt = 0;

            maxi = Math.max(maxi, cnt);
        }

        return maxi;
    }

    public static int getSingleElement(int []arr) {
        int n = arr.length;
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }
        return xorr;
    }

    public static int getLongestSubarray(int []arr, long k) {
        int n = arr.length; 

        int l = 0; 
        int maxi = 0, sum  = 0;
        for (int r = 0;r<n;r++) {
            sum += arr[r];
            while (l <= r && sum > k) {
                sum -= arr[l];
                l++;
            }
            if (sum == k) {
                maxi = Math.max(maxi, r - l + 1);
            }
        }

        return maxi;
    }

    public static int getSubarray(int []arr, int k) {
        int n = arr.length;

        Map<Integer,Integer> preSumMap = new HashMap<>();
        int sum = 0;
        int maxi = 0;
        preSumMap.put(0, -1);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int rem = sum - k;
            if(preSumMap.containsKey(rem)){
                maxi = Math.max(i - preSumMap.get(rem), maxi);
            }

            if(!preSumMap.containsKey(sum)){
                preSumMap.put(sum, i);
            }
        }
        return maxi;
    }

}
