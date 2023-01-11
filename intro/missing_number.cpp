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
  ll ans = 0; // we use this to do xor
  for (int i = 0; i < n - 1; i++)
  {
    int num;
    cin >> num;
    ans = (ans ^ num); // do xor again
  }
  for (int i = 1; i <= n; i++)
  {
    ans ^= i; // stores xor from 1 to n
  }

  cout << ans;
  // at last it will be 0 ^ missing_number as others will be 0 which gives the missing number
  return 0;
}

// we know xor of same number leads to 0