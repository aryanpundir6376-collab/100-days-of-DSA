#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval *arr = (Interval *)malloc(n * sizeof(Interval));

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Result array
    Interval *res = (Interval *)malloc(n * sizeof(Interval));
    int k = 0;

    // Step 2: Merge
    res[k++] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping
        if (arr[i].start <= res[k - 1].end) {
            // Merge
            if (arr[i].end > res[k - 1].end) {
                res[k - 1].end = arr[i].end;
            }
        } else {
            // No overlap
            res[k++] = arr[i];
        }
    }

    // Output result
    printf("Merged intervals:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", res[i].start, res[i].end);
    }

    free(arr);
    free(res);

    return 0;
}