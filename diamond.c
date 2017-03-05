#include <stdio.h>

int main() {
    int i, j, k;
    int n=5;
    
    printf("201120957  정순호\n\n");
    for (i = 1; i <= 2 * n - 1; i++) {
        int l = i <= n ? i : 2 * n - i;
        
        for (j = n - l; j > 0; j--) {
            printf(" ");
        }
        for (k = 1; k <= 2 * l - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}
