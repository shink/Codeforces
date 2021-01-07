/*
 * @author: shenke
 * @date: 2021/1/7
 * @project: Codeforces
 * @desp: 
 */

#include <stdio.h>

int main() {
    __int64 m, n, a;
    __int64 l, w;
    scanf("%I64d %I64d %I64d", &m, &n, &a);

    if (m % a == 0) {
        l = m / a;
    } else {
        l = m / a + 1;
    }

    if (n % a == 0) {
        w = n / a;
    } else {
        w = n / a + 1;
    }

    printf("%I64d", l * w);
    return 0;
}
