#include <stdio.h>
#include <stdlib.h>

// Structure to store car data
struct Car {
    int position;
    int speed;
    float time;
};

// Compare function (sort by position descending)
int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    struct Car cars[n];

    // Step 1: Create car array with time
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
        cars[i].time = (float)(target - position[i]) / speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    float prevTime = 0.0;

    // Step 3: Count fleets
    for (int i = 0; i < n; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    return fleets;
}

// Main
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}
