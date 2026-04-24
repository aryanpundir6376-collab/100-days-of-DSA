#include <stdio.h>

#define MAX 1000

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hash table (simple array for prefix sums)
    // Initialize with a special value (-1 means not seen)
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2; // -2 means not visited
    }

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum is zero from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: prefix sum seen before
        if (hash[prefixSum + offset] != -2) {
            int prevIndex = hash[prefixSum + offset];
            int length = i - prevIndex;

            if (length > maxLen) {
                maxLen = length;
            }
        } 
        else {
            // store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    printf("Length of longest zero-sum subarray: %d\n", maxLen);

    return 0;
}