/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/

#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int isFeasible(int stalls[], int n, int k, int mid) {
    int count = 1; 
    int last_position = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= mid) {
            count++;
            last_position = stalls[i];
            if (count == k) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int stalls[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    
    qsort(stalls, n, sizeof(int), compare);
    
    int left = 0;
    int right = stalls[n-1] - stalls[0];
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isFeasible(stalls, n, k, mid)) {
            result = mid;
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}