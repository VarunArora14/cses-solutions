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
  ll k;
  int n, m;
  cin >> n >> m >> k;
  vll desired_apartments(n), free_apartments(m);
  for (int i = 0; i < n; i++)
  {
    cin >> desired_apartments[i];
  }
  for (int j = 0; j < m; j++)
  {

    cin >> free_apartments[j];
  }
  int ans = 0;
  sort(free_apartments.begin(), free_apartments.end());       // nlogn
  sort(desired_apartments.begin(), desired_apartments.end()); // mlogm

  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (abs(desired_apartments[i] - free_apartments[j]) <= k)
    {
      // print2(desired_apartments[i], free_apartments[j]);
      ans++;
      i++;
      j++;
    }
    else
    {
      if (desired_apartments[i] - free_apartments[j] > k)
      {
        j++; // desired too big, check next free apartment
      }
      else
        i++; // free too big this time
    }

    // print2(i, j);
  }
  cout << ans;
  return 0;
}