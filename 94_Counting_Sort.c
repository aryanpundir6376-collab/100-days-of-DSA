#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create count array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Output array
    int *output = (int *)malloc(n * sizeof(int));

    // Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Input elements
    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    // Output sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}