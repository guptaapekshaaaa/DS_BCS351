#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in sorted order:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int linearResult = linearSearch(arr, n, target);
    int binaryResult = binarySearch(arr, n, target);

    if (linearResult != -1)
        printf("Linear Search: Element found at index %d\n", linearResult);
    else
        printf("Linear Search: Element not found\n");

    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n", binaryResult);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}