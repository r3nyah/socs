#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int N;
        scanf("%d", &N);

        int result;
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            if (i == 0)
                result = num;
            else
                result = gcd(result, num);
        }

        printf("Case #%d: %d\n", t, result);
    }

    return 0;
}
