#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if cows can be placed with at least 'dist' gap
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;  // first cow placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k)
            return 1;
    }
    return 0;
}

// Main logic
int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;   // try larger distance
        } else {
            high = mid - 1;  // reduce distance
        }
    }
    return ans;
}

int main() {
    int n, k;

    printf("Enter number of stalls and number of cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter the positions of stalls:\n");
    for (int i = 0; i < n; i++) {
        printf("Stall %d: ", i + 1);
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);

    printf("Maximum possible minimum distance = %d\n", result);

    return 0;
}