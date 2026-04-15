/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[100][50];   // store input names
    char unique[100][50];  // store unique names
    int count[100] = {0};  // count votes

    // input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int k = 0; // number of unique candidates

    // count frequency
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < k; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(unique[k], names[i]);
            count[k] = 1;
            k++;
        } else {
            count[found]++;
        }
    }

    // find winner
    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < k; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}