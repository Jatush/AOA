#include <stdio.h>
#include <conio.h>

void combine(int arr[], int low, int mid, int high) {
    // new array
    int merge[high - low + 1];

    // Maintaining the indexes
    int idx1 = low;
    int idx2 = mid + 1;
    int x = 0;

    // comparing both the arrays
    while ((idx1 <= mid) && (idx2 <= high)) {
        if (arr[idx1] < arr[idx2]) {
            merge[x] = arr[idx1];
            x++;
            idx1++;
        } else {
            merge[x] = arr[idx2];
            x++;
            idx2++;
        }
    }

    // if first list is incomplete
    while (idx1 <= mid) {
        merge[x] = arr[idx1];
        x++;
        idx1++;
    }

    // if second list is incomplete
    while (idx2 <= high) {
        merge[x] = arr[idx2];
        x++;
        idx2++;
    }

    // Copying the elements to the main array
    for (int i = low, j = 0; i <= high; i++, j++) {
        arr[i] = merge[j];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) { // Base Condition
        int mid = (low + high) / 2;

        // dividing into 2 sublists
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // combine function
        combine(arr, low, mid, high);
    }
}

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

    mergeSort(arr, 0, n - 1);

    printf("The sorted array is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    getch(); // Wait for a key press before exiting
    return 0;
}
