#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int arr[], int n)
{

  int maxi = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (maxi < arr[i])
    {
      maxi = arr[i];
    }
  }
  return maxi;
}

int secondSmallest(int arr[], int n)
{
  if (n < 2)
    return -1;
  int small = 1e9;
  int second_small = 1e9;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < small)
    {
      second_small = small;
      small = arr[i];
    }
    else if (arr[i] < second_small && arr[i] != small)
    {
      second_small = arr[i];
    }
  }
  return second_small;
}
int secondLargest(int arr[], int n)
{
  if (n < 2)
    return -1;
  int large = -1e9, second_large = -1e9;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > large)
    {
      second_large = large;
      large = arr[i];
    }

    else if (arr[i] > second_large && arr[i] != large)
    {
      second_large = arr[i];
    }
  }
  return second_large;
}

bool isSorted(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

int removeDuplicates(vector<int> &arr)
{
  int n = arr.size();
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (arr[i] != arr[j])
    {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

void leftRotateBy1(int arr[], int n)
{
  int temp = arr[0];
  for (int i = 0; i < n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}

void LeftRotate(vector<int> &arr, int k)
{
  int n = arr.size();
  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.end());
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

void RightRotate(vector<int> &arr, int k)
{
  int n = arr.size();
  reverse(arr.begin(), arr.begin() + n - k);
  reverse(arr.begin() + n - k, arr.end());
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

vector<int> moveZeros(int n, vector<int> a)
{
  int j = -1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
    return a;
  for (int i = j + 1; i < n; i++)
  {
    if (a[i] != 0)
    {
      swap(a[i], a[j]);
      j++;
    }
  }
  return a;
}

int search(int arr[], int n, int num)
{

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == num)
      return i;
  }
  return -1;
}

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
  int i = 0, j = 0;
  vector<int> ans;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      if (ans.size() == 0 || ans.back() != arr1[i])
        ans.push_back(arr1[i]);
      i++;
    }
    else
    {
      if (ans.size() == 0 || ans.back() != arr2[j])
        ans.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n)
  {
    if (ans.back() != arr1[i])
      ans.push_back(arr1[i]);
    i++;
  }
  while (j < m)
  {
    if (ans.back() != arr2[j])
      ans.push_back(arr2[j]);
    j++;
  }
  return ans;
}

int missingNumber(vector<int> &v)
{
  int x = 0;
  int n = v.size();
  for (int i = 0; i < n - 1; i++)
  {
    x ^= v[i];
    x ^= (i + 1);
  }
  x ^= n;
  return x;
}

int maxOnes(vector<int> &arr)
{
  int cnt = 0;
  int maxi = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == 1)
    {
      cnt++;
    }
    else
    {
      cnt = 0;
    }

    maxi = max(maxi, cnt);
  }
  return maxi;
}

int getSingleElement(vector<int> &arr)
{
  int n = arr.size();
  int xorr = 0;
  for (int i = 0; i < n; i++)
  {
    xorr = xorr ^ arr[i];
  }
  return xorr;
}

int LongestSubarray(vector<int>&v, int k){
  int n = v.size();
  int maxi = 0, sum = 0;
  int l = 0;
  for(int r = 0;r<n;r++){
    sum += v[r];
    while(sum>k and l<=r){
      sum -= v[l];
      l++;
    }

    if(sum==k){
      maxi = max(maxi,r-l+1);
    }
  }

  cout<<maxi<<'\n';
}

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); 

    map<int, int> preSumMap;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxi = max(maxi, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &c : v)
    cin >> c;
  LongestSubarray(v, 10);
  return 0;
}