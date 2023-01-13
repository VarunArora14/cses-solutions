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

vvi vis(9, vi(9)); // so we create border for edge cases
// add border as padding to avoid considering conditions for overflow/underflow of indices
vi dir_r = {0, 0, 1, -1};
vi dir_c = {-1, 1, 0, 0};
vi reserved(48);

int solve(int row, int col, int steps)
{

  // check if right and left are not blocked but up and down are blocked as we have to travel all 48 remaining positions excluding start
  if ((vis[row][col + 1] && vis[row][col - 1]) && (!vis[row - 1][col] && !vis[row + 1][col]))
    return 0;

  // check if up and down are not blocked but left and right are blocked
  if ((vis[row + 1][col] && vis[row - 1][col]) && (!vis[row][col - 1] && !vis[row][col + 1]))
    return 0;

  // base case
  if (row == 7 && col == 1)
  {
    return steps == 48; // 1 if true
  }

  if (steps == 48)
    return 0;

  int ret = 0;

  vis[row][col] = true; // mark curr node visited for DFS

  // we know the next direction
  if (reserved[steps] != -1)
  {
    // can go in any direction

    // we store dir_r and dir_c based on left, right, down, up values
    int nxt_row = row + dir_r[reserved[steps]];
    int nxt_col = col + dir_c[reserved[steps]];

    if (!vis[nxt_row][nxt_col])
      ret += solve(nxt_row, nxt_col, steps + 1);
  }
  else
  {
    // go in all dirs
    for (int i = 0; i < 4; i++)
    {
      int nxt_row = row + dir_r[i];
      int nxt_col = col + dir_c[i];

      // make sure to keep this check to reduce fn calls
      if (!vis[nxt_row][nxt_col])
        ret += solve(nxt_row, nxt_col, steps + 1);
    }
  }

  vis[row][col] = false; // backtracking
  return ret;
}
int main()
{
  // We have to travel the whole grid as input is 48 length string implying we travel all nodes and can't leavy any
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '?')
      reserved[i] = -1;
    else if (str[i] == 'L')
      reserved[i] = 0;
    else if (str[i] == 'R')
      reserved[i] = 1;
    else if (str[i] == 'D')
      reserved[i] = 2;
    else
      reserved[i] = 3; // case 'U'
  }

  for (int i = 0; i < 9; i++)
  {
    vis[0][i] = true;
    vis[8][i] = true;
    vis[i][0] = true;
    vis[i][8] = true;
  }

  vis[1][1] = true; // starting point
  int ans = solve(1, 1, 0);
  cout << ans;
  return 0;
}

// the code without visited check for horizontal and vertical rows works fine after few seconds but we can do better with this check
