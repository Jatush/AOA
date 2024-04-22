#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    clrscr(); // Clear the screen
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[50]; // Assuming a maximum array size of 50 for Turbo C
    printf("Enter the elements in array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\nSorted Array :");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch(); // Wait for a key press before exiting
    return 0;
}
