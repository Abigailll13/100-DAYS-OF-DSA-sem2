/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/


#include <stdio.h>
#include <string.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];

// Initialize table
void init(int m) {
    for(int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0, index;

    while(i < m) {
        index = (key % m + i * i) % m;

        if(table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0, index;

    while(i < m) {
        index = (key % m + i * i) % m;

        if(table[index] == key)
            return 1;

        if(table[index] == EMPTY)
            return 0;

        i++;
    }
    return 0;
}

int main() {
    int m, q;

    printf("Enter hash table size (m): ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    printf("Enter operations in format:\n");
    printf("INSERT <key> or SEARCH <key>\n");

    init(m);

    char op[10];
    int key;

    for(int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if(strcmp(op, "SEARCH") == 0) {
            if(search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}