给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

测试用例保证结果在 32 位有符号整数范围内。

 ```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m) return 0;
        vector<vector<unsigned long long>>f(n+1,vector<unsigned long long>(m+1,0));
        
        for(int i=0;i<n;i++) f[i][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(t[i-1]==s[j-1]) f[j][i]=f[j-1][i-1]+f[j-1][i];
                else f[j][i]=f[j-1][i];
            }
        }
        return f[n][m];
    }
};