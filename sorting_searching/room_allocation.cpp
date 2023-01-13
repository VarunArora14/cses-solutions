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

void solve(vector<pll> &nums)
{
  int n = nums.size();
  vi ans(n); // store the room number

  vector<tuple<long, long, long>> roomAllocator; // store {starting_time, departure_time, index}

  for (int i = 0; i < n; i++)
  {
    roomAllocator.push_back({nums[i].first, nums[i].second, i});
  }

  sort(roomAllocator.begin(), roomAllocator.end()); // to get smaller departure time first
  // for (auto [s, d, i] : roomAllocator)
  // {
  //   cout << s << " " << d << " " << i << "\n";
  // }

  priority_queue<pll> pq; // max heap
  int last_room = 0;
  // for (auto [starting_time, departure_time, index] : roomAllocator)
  // {
  //   cout << starting_time << " " << departure_time << " " << index << "\n";
  // }

  for (auto [starting_time, departure_time, index] : roomAllocator)
  {
    if (pq.empty())
    {
      last_room++;
      pq.push({-departure_time, last_room}); // smallest departure time with largest room number(as max heap)
      ans[index] = last_room;
    }
    else
    {
      auto [top_departure_time, top_last_room] = pq.top(); // smallest departure time with biggest room number
      if (-top_departure_time < starting_time)             // check if prev departure_time is smaller than current starting time
      {
        pq.pop();                                  // replace prev with current
        pq.push({-departure_time, top_last_room}); // departure times dont overlap, top_last_room and NOT last_room
        ans[index] = top_last_room;
      }
      else
      {
        last_room++; // keeps count of new room number if all full
        pq.push({-departure_time, last_room});
        ans[index] = last_room;
      }
    }
  }

  // As the array is sorted, either the new guest will go to room with smallest departure time or to new room
  // if the guest cannot go in smaller departure time room, he surely wont go to other rooms as well bcos they have larger
  // departure times

  int total_rooms = pq.size();
  cout << total_rooms << "\n";
  for (auto a : ans)
    cout << a << " ";
}

int main()
{
  int n;
  cin >> n;
  vector<pll> nums;

  for (int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    nums.push_back({a, b}); // push start and end time
  }

  solve(nums);

  return 0;
}

// here we have to give room numbers of each person in order they come and if 2 overlap, give them some other room
// first sort based on their ending time
// As we have to minimize the rooms, we check if first room is free and fill it first as well

// the problem comes down to ques to find how will we allocate a bigger room number to another guest
// Is a person is at room 1 (1,10) and another person comes

// we have to consider following cases - (1,2), (2,3) (3,4) then ans is [1,2,1] as we give room 1 to (3,4)
// Another is (1,2), (1,2), (1,2). Now we give rooms as [1,2,3]

// One clean way is to use max heap where we have pair<departure_time, room_number>
// since it is max heap, if same deaprture time, then bigger room number at top. As we have to minimize the departure time, we push
// -departure_time in heap

// All this time, we have to maintain for each person {starting_time, departure_time, index} . index is important as we have to return ans based
// on that

// why do last_room++ ?

// we store the last_room as largest value/upper bound of last room