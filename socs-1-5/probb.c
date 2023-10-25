#include <stdio.h>

void readArray(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void calculateColumnSums(int N, int matrix[N][N], int columnSums[N]) {
    for (int j = 0; j < N; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < N; i++) {
            columnSums[j] += matrix[i][j];
        }
    }
}

void printResults(int t, int N, int columnSums[N]) {
    printf("Case #%d:", t);
    for (int j = 0; j < N; j++) {
        printf(" %d", columnSums[j]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int matrix[N][N];
        readArray(N, matrix);

        int columnSums[N];
        calculateColumnSums(N, matrix, columnSums);

        printResults(t, N, columnSums);
    }

    return 0;
}
