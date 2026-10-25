/**
 * Course: Prompt Engineering / Problem Solving
 * Student: Ayan Khan (25BCON1174)
 * Assignment: Bug Fixing using Cursor AI (Original Buggy Version)
 * 
 * Known Bugs in this version:
 * 1. Line 13: `int sum;` is uninitialized (contains indeterminate garbage value).
 * 2. Line 14: `for (int i = 0; i <= n; i++)` runs 6 times (indexes 0..5), reading past array boundary.
 * 3. Line 17: `return sum / n;` performs integer division before conversion to float.
 */

#include <stdio.h>

float average(int arr[], int n) {
    int sum; 
    for (int i = 0; i <= n; i++) {
        sum += arr[i];
    } 
    return sum / n; 
} 

int main() {
    int data[5] = {10, 20, 30, 40, 51}; 
    printf("Average=%f\n", average(data, 5));
    return 0;
}
