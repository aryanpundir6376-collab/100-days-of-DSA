#include <stdio.h>

// Check if allocation is possible with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

// Main logic
int allocateBooks(int arr[], int n, int m) {
    int low = arr[0], high = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller max
        } else {
            low = mid + 1;    // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;

    printf("Enter number of books and number of students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter number of pages in each book:\n");
    for (int i = 0; i < n; i++) {
        printf("Book %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    if (m > n) {
        printf("Not possible to allocate (students > books)\n");
        return 0;
    }

    int result = allocateBooks(arr, n, m);

    printf("Minimum possible maximum pages = %d\n", result);

    return 0;
}