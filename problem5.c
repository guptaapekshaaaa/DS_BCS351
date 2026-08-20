#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum = arr[0];
    int minimum = arr[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > maximum) {
            maximum = arr[i];
        }

        if (arr[i] < minimum) {
            minimum = arr[i];
        }

        sum = sum + arr[i];
    }

    float average = (float)sum / n;

    printf("\nMaximum = %d\n", maximum);
    printf("Minimum = %d\n", minimum);
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}