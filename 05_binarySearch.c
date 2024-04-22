#include <stdio.h>
#include <conio.h>

// Function to implement binary search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;      // non-recursive approach
        } else {
            high = mid - 1;      // non-recursive approach
        }
    }
    return -1;
}

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Changed to sort in ascending order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

    // Input the target element
    int target;
    printf("Enter the target element : ");
    scanf("%d", &target);

    bubbleSort(arr, n);
    int targetIndex = binarySearch(arr, 0, n - 1, target);

    // Checking the final condition of returned index
    if (targetIndex == -1) {
        printf("Target element not found in the array\n");
    } else {
        printf("Target element is found at index %d after array is sorted\n", targetIndex);
    }

    getch(); // Wait for a key press before exiting
    return 0;
}
