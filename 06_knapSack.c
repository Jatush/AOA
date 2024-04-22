#include <stdio.h>
#include <conio.h>

void printTable(float profit[], float weight[], float ratio[], int n) {
    printf("Item\tProfit\tWeight\tRatio\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, profit[i], weight[i], ratio[i]);
    }
}

float knapsack(float profit[], float weight[], float ratio[], int n, int W, float x[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
            }
        }
    }

    printf("\n The Sorted Table is :\n");
    printTable(profit, weight, ratio, n);

    float totalWeight = 0;
    float totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + weight[i] <= W) {
            x[i] = 1;
            totalWeight += weight[i];
            totalProfit += profit[i];
        } else {
            x[i] = (W - totalWeight) / weight[i];
            totalWeight += weight[i] * x[i];
            totalProfit += profit[i] * x[i];
            break;
        }
    }
    return totalProfit;
}

void predefinedKnapsack(int n, float profit[], float weight[], int W) {
    float ratio[n], x[n];

    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    printf("\nThe Table is :\n");
    printTable(profit, weight, ratio, n);

    float maxProfit = knapsack(profit, weight, ratio, n, W, x);
    printf("\nMaximum profit: %.2f\n", maxProfit);
}

int main() {
    int n = 5; // Number of items
    float profit[] = {10, 5, 15, 7, 6}; // Profits
    float weight[] = {2, 3, 5, 7, 1}; // Weights
    int W = 10; // Knapsack capacity

    clrscr(); // Clear the screen
    predefinedKnapsack(n, profit, weight, W);

    getch(); // Wait for a key press before exiting
    return 0;
}
