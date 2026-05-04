#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    double time;
};

// Sort by position descending
int compare(const void* a, const void* b) {
    struct Car* c1 = (struct Car*)a;
    struct Car* c2 = (struct Car*)b;
    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    struct Car cars[positionSize];

    // Step 1: Compute time
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, positionSize, sizeof(struct Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    // Step 3: Count fleets
    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    return fleets;
}