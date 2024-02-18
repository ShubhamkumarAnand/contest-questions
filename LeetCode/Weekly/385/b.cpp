/*
   👲 :  @imskanand
   ⏳ :  Sunday : (18-Feb-24)
   ⏰ :  (09:02)
   🌞 :  'Karmanye vadhikaraste' - `You have the right to work only`
*/
#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007
#define inf 1e18

#define pb = emplace_back;
#define endl "\n"

using ll = long long int;
using ull = unsigned long long int;

// Take your first step, GOD will guide then!

// Unoptimized Solution - ! Will give a TLE at large input
class Solution {
 public:
  int findLongestCommonPrefix(const std::string& str1, const std::string& str2) {
    int commonPrefixLength = 0;
    int minLength = std::min(str1.length(), str2.length());

    for (int i = 0; i < minLength; ++i) {
      if (str1[i] == str2[i]) {
        commonPrefixLength++;
      } else {
        break;
      }
    }
    return commonPrefixLength;
  }

  int longestCommonPrefix(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int maxLength = 0;

    for (const int& x : arr1) {
      for (const int& y : arr2) {
        std::string strX = std::to_string(x);
        std::string strY = std::to_string(y);

        int currentLength = findLongestCommonPrefix(strX, strY);
        maxLength = std::max(maxLength, currentLength);
      }
    }

    return maxLength;
  }
};

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    int maxLength = 0;
    set<string> st;
    for (int i : arr1) {
      string num = to_string(i);
      string s = "";
      for (char c : num) {
        s += c;
        st.insert(s);
      }
    }
    for (int i : arr2) {
      string num = to_string(i);
      string s = "";
      for (char c : num) {
        s += c;
        if (st.count(s))
          maxLength = max(maxLength, (int)s.length());
      }
    }
    return maxLength;
  }
};

// Most Optimal - TC
class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> s;
    for (int x : arr2) {
      for (; x; x /= 10) {
        s.insert(x);
      }
    }
    int r = 0;
    for (int x : arr1) {
      for (; x > r; x /= 10) {
        if (s.count(x)) {
          r = x;
          break;
        }
      }
    }
    return r ? to_string(r).length() : 0;
  }
};

// Most optimal - SC
class Solution {
  void dedup(vector<int>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }

 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    dedup(arr1);
    dedup(arr2);
    int r = 0;
    for (int i = arr1.size() - 1; i >= 0 && arr1[i] > r; --i) {
      for (int j = arr2.size() - 1; j >= 0 && arr2[j] > r; --j) {
        for (int x = arr1[i], y = arr2[j]; x > r && y > r;) {
          if (x == y) {
            r = x;
            break;
          }
          if (x > y) {
            x /= 10;
          } else {
            y /= 10;
          }
        }
      }
    }
    return r ? to_string(r).length() : 0;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();