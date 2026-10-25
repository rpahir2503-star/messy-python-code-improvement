/**
 * Course: Prompt Engineering / Problem Solving
 * Student: Ayan Khan (25BCON1174)
 * Assignment: Bug Fixing using Cursor AI (Corrected Version)
 * 
 * Corrections Made via Cursor AI 3-Step Chain Prompting:
 * - Bug 1 Fixed: Initialized `sum = 0;` so accumulator starts from clean state.
 * - Bug 2 Fixed: Changed loop condition to `i < n;` to prevent buffer overflow.
 * - Bug 3 Fixed: Cast `sum` to `(float)sum / n;` to retain fractional precision.
 */

#include <stdio.h>

float average(int arr[], int n) {
    int sum = 0; // BUG 1 FIX: Initialize sum to 0 to eliminate garbage value
    
    for (int i = 0; i < n; i++) { // BUG 2 FIX: Stop at i < n to prevent out-of-bounds memory read
        sum += arr[i];
    } 
    
    return (float)sum / n; // BUG 3 FIX: Cast sum to float to avoid integer truncation
} 

int main() {
    int data[5] = {10, 20, 30, 40, 51}; 
    
    // Expected mathematical average: (10 + 20 + 30 + 40 + 51) / 5 = 151 / 5 = 30.20
    float result = average(data, 5);
    
    printf("--- Array Average Test Verification ---\n");
    printf("Array Elements: {10, 20, 30, 40, 51}\n");
    printf("Element Count : 5\n");
    printf("Total Sum     : 151\n");
    printf("Calculated Avg: %f\n", result);
    printf("Formatted Avg : %.2f\n", result);
    
    return 0;
}
