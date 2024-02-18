/*
   👲 :  @imskanand
   ⏳ :  Sunday : (18-Feb-24)
   ⏰ :  (08:39)
   🌞 :  'Karmanye vadhikaraste' - `You have the right to work only`
*/
#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007
#define inf 1e18

#define pb = push_back
#define endl "\n"

using ll = long long int;
using ull = unsigned long long int;

// Take your first step, GOD will guide then!
class Solution {
 public:
  bool isPrefixAndSuffix(string& w1, string& w2) {
    int n1 = w1.size();
    int n2 = w2.size();
    if (n2 < n1)
      return false;
    for (int i = 0; i < n1; ++i) {
      if (w1[i] != w2[i] || w1[i] != w2[n2 - n1 + i]) {
        return false;
      }
    }
    return true;
  }

  int countPrefixSuffixPairs(vector<string>& words) {
    const int n = words.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isPrefixAndSuffix(words[i], words[j])) {
          result++;
        }
      }
    }
    return result;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();
