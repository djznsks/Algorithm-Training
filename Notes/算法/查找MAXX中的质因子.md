

gcd:最大公因数
lcm:最小公倍数

gcd(a,b)×lcm(a,b)=a×b



```cpp
void init() {
   
	质数：只能被1或它本身整除，大于1；
	质因子：是质数的因子；
    // 从小到大枚举 i
    for (int i = 2; i <= MAXX; i++) {

        // 如果 fac[i] 是空的 → 说明 i 是质数！
        // 因为如果 i 不是质数，它早就被更小的质数加进去了
        if (fac[i].empty()) {

            // 把 i 的所有倍数 j 都遍历一遍
            for (int j = i; j <= MAXX; j += i) {

                // i 是 j 的一个质因子 → 存进去
                fac[j].push_back(i);
            }
        }
    }
}
```

只要**两个数有同一个质因子**

→ 它们的最大公约数一定大于 1
