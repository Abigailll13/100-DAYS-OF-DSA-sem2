/*def longest_zero_sum_subarray(arr):
    prefix_sum = 0
    max_len = 0
    sum_map = {}

    for i in range(len(arr)):
        prefix_sum += arr[i]

        # Case 1: sum = 0
        if prefix_sum == 0:
            max_len = i + 1

        # Case 2: sum seen before
        if prefix_sum in sum_map:
            max_len = max(max_len, i - sum_map[prefix_sum])
        else:
            sum_map[prefix_sum] = i

    return max_len


# Example
arr = [15, -2, 2, -8, 1, 7, 10, 23]
print(longest_zero_sum_subarray(arr))  # Output: 5*/

#include <stdio.h>

#define MAX 1000

// Simple hashmap using arrays
int hash[MAX * 2];  // stores index
int used[MAX * 2];  // to check if filled

int hashFunc(int key) {
    return (key + MAX) % (MAX * 2);
}

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hashmap
    for (int i = 0; i < MAX * 2; i++) {
        used[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int h = hashFunc(sum);

        if (!used[h]) {
            hash[h] = i;
            used[h] = 1;
        } else {
            int length = i - hash[h];
            if (length > maxLen) {
                maxLen = length;
            }
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}

