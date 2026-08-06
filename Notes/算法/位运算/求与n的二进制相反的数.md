```cpp

int reverse(int n) {
    int res = 0;
    while (n > 0) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}