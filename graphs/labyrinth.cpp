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

  bool ans = false;
  vector<char> path;
  vvi vis(n, vi(m));
  vvi prevStep(n, vi(m));
  queue<pii> q;
  pii start, end;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'A')
      {
        start = {i, j};
        q.push({i, j});
        vis[i][j] = true;
      }
      else if (grid[i][j] == 'B')
        end = {i, j};
    }
  }

  vector<tuple<int, int, char>> dirs = {{0, -1, 'L'}, {0, 1, 'R'}, {1, 0, 'D'}, {-1, 0, 'U'}};
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  string stepDir = "URDL";
  string res = "";

  while (!q.empty())
  {
    auto [row, col] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nxtrow = row + dx[i];
      int nxtcol = col + dy[i];
      if (nxtcol < 0 || nxtrow < 0 || nxtrow >= n || nxtcol >= m || grid[nxtrow][nxtcol] == '#' || vis[nxtrow][nxtcol] == true)
        continue;

      q.push({nxtrow, nxtcol});
      prevStep[nxtrow][nxtcol] = i; // store parent/prev step instead of whole path, as BFS, we get shortest path
      vis[nxtrow][nxtcol] = true;
    }
  }
  if (vis[end.first][end.second])
  {
    cout << "YES\n";
    vector<int> steps;
    while (end != start)
    {
      int parent = prevStep[end.first][end.second];
      steps.push_back(parent);                                 // store 0 to 3 representing U,R,D,L
      end = {end.first - dx[parent], end.second - dy[parent]}; // backtrack to previous
    }

    reverse(steps.begin(), steps.end()); // to show A to B as we had from B to A
    cout << steps.size() << endl;
    for (int c : steps)
    {
      cout << stepDir[c];
    }
    cout << "\n";
  }
  else
    cout << "NO";

  return 0;
}