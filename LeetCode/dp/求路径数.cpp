#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define ff(n) fixed << setprecision(n)
#define PI acos(-1.0)
//用map处理
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        vector<int> next_odd(n, -1), next_even(n, -1);
        
        // 用 map 预处理
        map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            auto it = mp.lower_bound(arr[i]);
            if (it != mp.end()) next_odd[i] = it->second;
            mp[arr[i]] = i;
        }
        
        mp.clear();
        for (int i = n - 1; i >= 0; i--) {
            auto it = mp.upper_bound(arr[i]);
            if (it != mp.begin()) {
                --it;
                next_even[i] = it->second;
            }
            mp[arr[i]] = i;
        }

        // dp[i][0]：从 i 出发，当前跳了偶数次，能否到达终点
        // dp[i][1]：从 i 出发，当前跳了奇数次，能否到达终点
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[n-1][0] = true;  // 终点：不管奇偶，都已经到了
        dp[n-1][1] = true;
        
        for (int i = n - 2; i >= 0; i--) {
            if (next_odd[i] != -1) {
                dp[i][1] = dp[next_odd[i]][0];  // 奇数跳后变成偶数次
            }
            if (next_even[i] != -1) {
                dp[i][0] = dp[next_even[i]][1]; // 偶数跳后变成奇数次
            }
        }
        
        // 答案：从起点出发，第一步是奇数跳
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][1]) ans++;  // 从 i 出发，当前跳了奇数次能到终点
        }
        return ans;
    }
};