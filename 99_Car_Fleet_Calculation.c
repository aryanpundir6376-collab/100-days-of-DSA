#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Comparator: sort by position descending
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car *cars = (Car *)malloc(n * sizeof(Car));

    // Store position and speed together
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // Else: joins existing fleet
    }

    free(cars);
    return fleets;
}

int main() {
    int n, target;

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}