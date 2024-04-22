#include <stdio.h>
#include <conio.h>

int main() {
    // Input no of elements
    int n;
    clrscr(); // Clear the screen
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    // Input array elements
    int arr[50]; // Assuming a maximum array size of 50 for Turbo C
    printf("Enter the elements in array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort Logic
    int mindex, marray;
    for (int i = 0; i < n - 1; i++) {
        mindex = i;
        marray = arr[i];

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < marray) {
                mindex = j;
                marray = arr[j];
            }
        }
        arr[mindex] = arr[i];
        arr[i] = marray;
    }

    // Sorted array output
    printf("The sorted array is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    getch(); // Wait for a key press before exiting
    return 0;
}
