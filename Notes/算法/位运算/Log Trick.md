

作用：用于解决连续子数组问题，其中去重是最重要的优化！


```cpp



void logTrick(vector<int>& nums) {
    vector<pair<int, int>> or_left; // (子数组或值，最小左端点)
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        // 计算以 i 为右端点的子数组或值
        for (auto& [or_val, _] : or_left) {
            or_val |= x; // **根据题目修改**
            
        }
        // x 单独一个数作为子数组
        or_left.emplace_back(x, i);

        // 原地去重（相同或值只保留最左边的）
        int m = 1;
        for (int j = 1; j < or_left.size(); j++) {
            if (or_left[j].first != or_left[j - 1].first) {
                or_left[m++] = or_left[j];
            }
        }
        or_left.resize(m);

        cout << i << " " << x << endl;
        for (int k = 0; k < m; k++) {
            auto [or_val, left] = or_left[k];
            int right = k + 1 < m ? or_left[k + 1].second - 1 : i;
            // 对于左端点在 [left, right]，右端点为 i 的子数组，OR 值都是 or_val
            cout << left << " " << right << " " << or_val << endl;
        }
    }
}

int main() {
    vector<int> nums = {4, 2, 1, 5};
    logTrick(nums);
    return 0;
}


