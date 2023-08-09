#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

void inputDistances(int distances[MAX_CITIES][MAX_CITIES], int numCities) {
    printf("Enter the distance matrix (%d x %d):\n", numCities, numCities);
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &distances[i][j]);
        }
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int tspBruteForce(int distances[MAX_CITIES][MAX_CITIES], int numCities) {
    int minTourCost = INT_MAX;

    int cities[MAX_CITIES];
    for (int i = 0; i < numCities; i++) {
        cities[i] = i;
    }

    int totalPermutations = factorial(numCities);

    for (int i = 0; i < totalPermutations; i++) {
        int tourCost = 0;
        int tourIndex = 0;
        
        for (int j = 0; j < numCities - 1; j++) {
            tourCost += distances[cities[tourIndex]][cities[tourIndex + 1]];
            tourIndex++;
        }
        tourCost += distances[cities[tourIndex]][cities[0]];

        if (tourCost < minTourCost) {
            minTourCost = tourCost;
        }

        // Generate the next permutation
        int j = numCities - 2;
        while (j != -1 && cities[j] > cities[j + 1]) {
            j--;
        }
        if (j == -1) {
            break;  // All permutations done
        }

        int k = numCities - 1;
        while (cities[j] > cities[k]) {
            k--;
        }

        int temp = cities[j];
        cities[j] = cities[k];
        cities[k] = temp;

        for (int l = j + 1, r = numCities - 1; l < r; l++, r--) {
            temp = cities[l];
            cities[l] = cities[r];
            cities[r] = temp;
        }
    }

    return minTourCost;
}

int main() {
    int numCities;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    if (numCities > MAX_CITIES) {
        printf("Maximum number of cities allowed is %d.\n", MAX_CITIES);
        return 1;
    }

    int distances[MAX_CITIES][MAX_CITIES];
    inputDistances(distances, numCities);

    int minTourCost = tspBruteForce(distances, numCities);

    printf("Minimum Tour Cost: %d\n", minTourCost);

    return 0;
}

