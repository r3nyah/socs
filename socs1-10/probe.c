#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);

        long long A[N];
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &A[i]);
        }

        long long maxLength = 0;
        long long currentLength = 0;
        long long currentSum = 0;

        for (int i = 0; i < N; ++i) {
            currentSum += A[i];
            currentLength++;

            while (currentSum > M && currentLength > 0) {
                currentSum -= A[i - currentLength + 1];
                currentLength--;
            }

            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }

        printf("Case #%d: %lld\n", t, (maxLength > 0) ? maxLength : -1);
    }

    return 0;
}
