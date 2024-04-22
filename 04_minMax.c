#include <stdio.h>
#include <conio.h>

// Implementing the min-max algorithm
void minMax(int arr[], int n) {
    // Declare the minimum and maximum elements
    int min, max;
    min = max = arr[0];

    // logic for updating min, max values
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        } else {
            continue;
        }
    }

    // Printing the minimum and maximum values of array
    printf("The minimum element in array is : %d\n", min);
    printf("The maximum element in array is : %d\n", max);
}

int main() {
    // Input the size of array
    int n;
    clrscr(); // Clear the screen
    printf("Enter the size of array : ");
    scanf("%d", &n);

    // Input the elements in array
    int arr[50]; // Assuming a maximum array size of 50 for Turbo C
    printf("Enter the elements in array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // calling the minMax function
    minMax(arr, n);

    getch(); // Wait for a key press before exiting
    return 0;
}
