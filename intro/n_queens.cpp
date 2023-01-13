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

bool isValidQueen(int row, int col, vector<vector<char>> &grid)
{

  // vertical check, horizontal we take care of
  for (int i = 0; i < 8; i++)
  {
    if (grid[i][col] == 'Q')
      return false;
  }

  // check the diagonals

  // upper left diagonal
  int r = row, c = col;
  while (r >= 0 && c >= 0)
  {
    if (grid[r][c] == 'Q')
      return false;
    r--;
    c--;
  }

  // upper right diagonal
  r = row, c = col;
  while (r >= 0 && c < 8)
  {
    if (grid[r][c] == 'Q')
      return false;
    r--;
    c++;
  }

  // // bottom right diagonal
  // r = row, c = col;
  // while (r < 8 && c < 8)
  // {
  //   if (grid[r][c] == 'Q')
  //     return false;
  //   r++;
  //   c++;
  // }

  // // bottom left diagonal
  // r = row, c = col;
  // while (r < 8 && c >= 0)
  // {
  //   if (grid[r][c] == 'Q')
  //     return false;
  //   r++;
  //   c--;
  // }

  return true;
}

void solve(vector<vector<char>> &grid, int row, int &ans)
{
  // reach 8 not 7 to break as row=7 is reaching last row
  if (row == 8)
  {
    ans++;
    return;
  }

  for (int i = 0; i < 8; i++)
  {
    if (grid[row][i] != '*' && isValidQueen(row, i, grid))
    {
      // mark queen at current position
      grid[row][i] = 'Q';
      solve(grid, row + 1, ans); // go to next row
      grid[row][i] = '.';        // for backtracking
    }
  }
}

int main()
{
  vector<vector<char>> grid(8, vector<char>(8, '.'));
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cin >> grid[i][j];
    }
  }
  int ans = 0;
  solve(grid, 0, ans);
  cout << ans;
  return 0;
}