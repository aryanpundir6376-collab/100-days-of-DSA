#include <stdio.h>

// Check if painting is possible within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

// Main logic
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller time
        } else {
            low = mid + 1;    // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;

    printf("Enter number of boards and number of painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter lengths of boards:\n");
    for (int i = 0; i < n; i++) {
        printf("Board %d: ", i + 1);
        scanf("%d", &boards[i]);
    }

    int result = minTime(boards, n, k);

    printf("Minimum time required = %d\n", result);

    return 0;
}