#include <bits/stdc++.h>
using namespace std;

bool twoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return false;
}

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int majorityElement(vector<int> v)
{
    int n = v.size();
    int cnt = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i])
            cnt++;
        else
            cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LLONG_MIN;
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]n";

    return maxi;
}

int maxProfit(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}

vector<int> RearrangebySign(vector<int> A, int n)
{

    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
    }
    return A;
}

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size();

    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin() + ind + 1, A.end());
    return A;
}

vector<int> printLeaders(int arr[], int n)
{
    vector<int> ans;
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }

    return ans;
}

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

vector<int> printSpiral(vector<vector<int>> mat)
{

    vector<int> ans;

    int n = mat.size();
    int m = mat[0].size();

    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);

            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
        }
    }
    return ans;
}

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size();
    map<int,int>mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1;
    for (int i = 0; i < n; i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &c : v)
    {
        cin >> c;
    }
    return 0;
}