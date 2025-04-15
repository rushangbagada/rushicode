#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int n, int a) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == a) {
            return mid;
        } else if (arr[mid] < a) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);

    int a;
    printf("Enter the element to be searched: ");
    scanf("%d", &a);

    int index = binary_search(arr, n, a);
    if (index == -1) {
        printf("Element not found\n");
        return 0;
    }
    printf("The %d is found at index %d in sorted array\n", a, index);
    return 0;
}