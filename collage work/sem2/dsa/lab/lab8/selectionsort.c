#include <stdio.h>
#include <limits.h>
 int n = 6;

void swap(int* a,int* b){
    int temp = *a ;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[]){
    for (int i=0;i<n;i++){
        int  a=i;
         int min = INT_MAX;
        for (int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                a = j;
            }
        }
        swap(&arr[i],&arr[a]);
    }
    return ;
}

void print(int arr[]){
    for (int i=0;i<n;i++){
        printf ("%d ",arr[i]);
    }
}
int main (){
   
    int arr[] = {4,5,1,3,2,6};
    selectionsort(arr);
    print(arr);
    return 0;
}