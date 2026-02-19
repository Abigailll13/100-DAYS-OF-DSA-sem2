/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/
#include <stdio.h>
#include <stdlib.h>

void mergeLogs(int* log1, int p, int* log2, int q) {
    int i = 0, j = 0;
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }
}
 
int main() {
    int p, q;
    scanf("%d", &p);
    int* log1 = (int*)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    scanf("%d", &q);
    int* log2 = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    mergeLogs(log1, p, log2, q);
    
    free(log1);
    free(log2);
    
    return 0;
}