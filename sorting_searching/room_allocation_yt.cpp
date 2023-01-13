// https://youtu.be/dZ_6MS14Mg4
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>
#include "array"

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

int main()
{
  int n;
  cin >> n;
  // array<int, 3> nums[max_n];
  vvi nums(n, vi(3));
  vi ans(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i][1] >> nums[i][0]; // destination time input later as sort based on it
    nums[i][2] = i;                  // store index for ans
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << nums[i][j] << " ";
    }
    cout << "\n";
  }
  set<array<int, 2>> s;
  for (int i = 0; i < n; i++)
  {
    // pointer to just smaller element than starting time
    auto it = s.lower_bound({nums[i][1]}); // pass braces for array otherwise error as it considers as list
    if (it != s.begin())
    {
      it--;
      ans[nums[i][2]] = (*it)[1];
      s.erase(it);
    }
    else
      ans[nums[i][2]] = s.size();            // give larger room if smaller
    s.insert({nums[i][0], ans[nums[i][2]]}); // push the ending time and index
  }

  cout << s.size() << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}