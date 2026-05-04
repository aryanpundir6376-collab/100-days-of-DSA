#include <stdio.h>
#include <stdlib.h>

// Simple insertion sort for each bucket
void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d values in range [0,1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);

        // validation
        if (arr[i] < 0 || arr[i] >= 1) {
            printf("Invalid! Enter again:\n");
            i--;
        }
    }

    // Create buckets
    float buckets[n][n];   // max n elements per bucket
    int count[n];

    // Initialize counts
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Distribute into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        if (index >= n) index = n - 1;

        buckets[index][count[index]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Output
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }

    return 0;
}