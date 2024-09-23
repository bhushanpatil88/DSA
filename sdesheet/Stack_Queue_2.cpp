

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1), pge(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            nge[st.top()] = i;
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return nge;
}

vector<int> nextGreaterElements2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
                nge[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

vector<int> previousSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1), nse(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            nse[st.top()] = i;
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

int sumSubarrayMinimum(vector<int> &v)
{
    vector<int> nse = {};
    vector<int> pse = previousSmallerElement(v);
    int ans = 0;
    const int M = 1e9 + 7;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int l = i - pse[i];
        int r = nse[i] - i;
        ans += (r * l * v[i]) % M;
    }
    return ans;
}

string removeKDigits(string num, int k)
{
    if (num.size() <= k)
        return "0";

    if (k == 0)
        return num;

    string ans;
    stack<char> st;
    st.push(num[0]);
    for (int i = 1; i < num.size(); i++)
    {
        while (k > 0 and !st.empty() and num[i] < st.top())
        {
            k--;
            st.pop();
        }

        st.push(num[i]);
        // pop preceding zero
        if (st.size() == 1 and st.top() == '0')
            st.pop();
    }

    while (k > 0 and !st.empty())
    {
        k--;
        st.pop();
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    if (ans.size() == 0)
        return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}

int largestRectangleArea(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int Celebrity(vector<vector<int>>mat){
    int n = mat.size();
    int top = 0, bottom = n-1;
    while(top<bottom){
        if(mat[top][bottom]==1)top++;
        else if(mat[bottom][top]==1)bottom--;
        else top++,bottom--;
    }
    if(top>bottom)return -1;
    if(top==bottom){
        for(int i=0;i<n;i++){
            if(i==top)continue;
            if(mat[i][top]==1 and mat[top][i]==0)continue;
            else return -1;
        }
        return top;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &c : v)
        cin >> c;

    return 0;
}