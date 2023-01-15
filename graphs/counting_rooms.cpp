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

void floodfill(vvi &vis, vector<vector<char>> &grid, int row, int col)
{
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '#' || vis[row][col] == true)
    return;

  vis[row][col] = true;
  floodfill(vis, grid, row - 1, col);
  floodfill(vis, grid, row + 1, col);
  floodfill(vis, grid, row, col - 1);
  floodfill(vis, grid, row, col + 1);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  int ans = 0;
  vvi vis(n, vi(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '.' && vis[i][j] == false)
      {
        floodfill(vis, grid, i, j);
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}