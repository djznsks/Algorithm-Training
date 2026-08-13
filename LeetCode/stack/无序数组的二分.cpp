#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define ff(n) fixed << setprecision(n)
#define PI acos(-1.0)

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int N = A.size();
        
        // 构建跳转表
        auto make = [&](vector<int>& B) {
            vector<int> ans(N, -1);
            vector<int> stack;  // 单调递减栈
            for (int i : B) {
                while (!stack.empty() && i > stack.back()) {
                    ans[stack.back()] = i;
                    stack.pop_back();
                }
                stack.push_back(i);
            }
            return ans;
        };
        
        // 按值升序排序索引（奇数跳：找 >= 当前值的最小值）
        vector<int> B(N);
        iota(B.begin(), B.end(), 0);  // 初始化 0, 1, 2, ..., N-1
        sort(B.begin(), B.end(), [&](int i, int j) {
            return A[i] < A[j];
        });
        vector<int> oddnext = make(B);
        
        // 按值降序排序索引（偶数跳：找 <= 当前值的最大值）
        sort(B.begin(), B.end(), [&](int i, int j) {
            return A[i] > A[j];
        });
        vector<int> evennext = make(B);
        
    
    }
};