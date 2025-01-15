

#include <stdio.h>

void sortArray(int arr[], int size) {
  int i, j, temp;

  
}
void bubblesort(int arr[], int size){
  int i,j,temp;
  for (i = 0; i <=size-1; i++) {
    for (j =0; j <=size-i-2; j++) {
      if (arr[j] < arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        j++;
      }
    }
  }
}

int main() {
  int arr[] = {5,42, 8, 67, 1, 6, 4,45,22,100};
  int size = sizeof(arr) / sizeof(arr[0]);
     printf("\narray 1:");
  sortArray(arr, size);


  for (int i = 0; i < size; i++) {
    printf("  %d ", arr[i]);
  }
  

int arr1[] = {23,45,44,56,77};
int size1 = sizeof(arr1) / sizeof(arr[0]);
printf("\narray 2:");
   bubblesort(arr1, size1);
  

  for (int i = 0; i < size1; i++) {
    printf("  %d ", arr1[i]);
  }
  printf("\n%d",arr1[5]);
  


  return 0;
}
