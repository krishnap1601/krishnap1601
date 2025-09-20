#include <stdio.h>
void multiplyMatrix(int A[10][10], int B[10][10], int
C[10][10], int m, int n, int p) {
int i, j, k;
for (i = 0; i < m; i++) {
for (j = 0; j < p; j++) {
C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int m, n, p, i, j;

    printf("Enter rows and columns of Matrix A (m x n): ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and columns of Matrix B (n x p): ");
    scanf("%d %d", &n, &p);

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    multiplyMatrix(A, B, C, m, n, p);

    printf("\nResultant Matrix (A x B):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}
