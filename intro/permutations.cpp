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

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
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
  if (n == 1)
  {
    cout << 1;
    return 0;
  }
  if (n == 2 || n == 3)
  {
    cout << "NO SOLUTION";
    return 0;
  }
  vi nums;

  // make first n/2 as even and remaining n/2 as odd
  for (int i = 2; i <= n; i += 2)
  {
    nums.push_back(i);
  }
  for (int i = 1; i <= n; i += 2)
  {
    nums.push_back(i);
  }

  for (int num : nums)
    cout << num << " ";
  return 0;
}