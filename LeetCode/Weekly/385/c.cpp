/*
   👲 :  @imskanand
   ⏳ :  Sunday : (18-Feb-24)
   ⏰ :  (13:13)
   🌞 :  'Karmanye vadhikaraste' - `You have the right to work only`
*/
#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007
#define inf 1e18

#define pb(x) = emplace_back(x);
#define endl "\n"

using ll = long long int;
using ull = unsigned long long int;

// Take your first step, GOD will guide then!
class Solution {
  bool isPrime(int x) {
    if (x == 2)
      return false;
    for (int i = 2; i * i <= x; ++i)
      if (x % i == 0)
        return false;
    return true;
  }

 public:
  int mostFrequentPrime(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 8; ++k) {
          int x = i, y = j;
          int num = mat[i][j];
          while (true) {
            x += dx[k], y += dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m)
              break;
            num = num * 10 + mat[x][y];
            if (isPrime(num))
              mp[num]++;
          }
        }
      }
    }
    int ans = -1, freq = 0;
    for (auto [k, v] : mp) {
      if (v >= freq)
        ans = k, freq = v;
    }
    return ans;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();