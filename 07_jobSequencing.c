#include <stdio.h>
#include <conio.h>

int jobSequencing(int deadline[], int profit[], int n, int sequence[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                int temp1 = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp1;

                int temp2 = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp2;
            }
        }
    }

    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = (deadline[i] - 1); j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                break;
            }
        }
    }

    int finalResult = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            finalResult += profit[result[i]];
            sequence[i] = result[i] + 1; // Storing job sequence
        }
    }
    return finalResult;
}

int main() {
    int n = 5; // Number of jobs
    int deadline[] = {4, 2, 3, 1, 1}; // Deadlines
    int profit[] = {20, 15, 10, 5, 1}; // Profits
    int sequence[n]; // Array to store job sequence

    clrscr(); // Clear the screen

    int totalProfit = jobSequencing(deadline, profit, n, sequence);

    printf("The total profit is %d\n", totalProfit);
    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (sequence[i] != 0) {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");

    getch(); // Wait for a key press before exiting
    return 0;
}
