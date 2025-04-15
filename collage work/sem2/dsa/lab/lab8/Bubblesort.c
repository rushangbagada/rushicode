
#include <stdio.h>

void bubblesort(int arr[],int n){   
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            int temp;
            if(arr[j]>arr[j+1]){
               temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j] = temp;
            }
        }
    }
    return ;
}

void print(int arr[],int n){
    for (int i=0;i<n;i++){
        printf ("%d,",arr[i]);
    }
}
int main (){
    int n = 7;
    int arr[] = {4,5,1,1,3,2,6};

    bubblesort(arr,n);
    print(arr,n);
    return 0;
}