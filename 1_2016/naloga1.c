#include <stdio.h>
#include <stdlib.h>

int vsota_stevk(int x) {
    long long sum = 0;
    while (x != 0)
    {
        int temp = x % 10;
        sum += (long long) temp;
        x = x / 10;
    }
    return sum;
}

int main() {
    long p, q, n;
    scanf("%ld %ld %ld", &p, &q, &n);

    long long x = p * q;

    for(int i = 0; i < n; i++) {
        long long temp = vsota_stevk(x);
        x = temp;
    }

    printf("%lld\n", x);
    return 0;
}