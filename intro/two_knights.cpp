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

  ll k;
  cin >> k;

  cout << 0 << "\n";
  for (ll i = 2; i <= k; i++)
  {
    // first is number of ways to put 2 knights, 2nd is ways 2 knights attack each other
    cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << "\n";
  }

  // each knight takes 2*3 block for 1 attack and there are possible 8 attacks / 2 as both knights look same

  return 0;
}

// https://japlslounge.com/posts/cses/two_knights/1.htm