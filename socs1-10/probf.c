#include <stdio.h>

int main() {
    int N, Q;

    scanf("%d", &N);

    long long A[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }

    scanf("%d", &Q);

    for (int caseNumber = 1; caseNumber <= Q; ++caseNumber) {
        long long M;
        scanf("%lld", &M);

        int maxLength = 0;
        long long currentSum = 0;
        int currentLength = 0;

        for (int i = 0; i < N; ++i) {
            currentSum += A[i];
            currentLength++;

            while (currentSum > M) {
                currentSum -= A[i - currentLength + 1];
                currentLength--;
            }

            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }

        printf("Case #%d: %d\n", caseNumber, maxLength);
    }

    return 0;
}
