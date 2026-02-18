
/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>
void rotateArray(int* arr, int n, int k) {
    k = k % n; 
    int temp[n];
    
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    rotateArray(arr, n, k);
    
    return 0;
}// update
