#include <iostream>

using namespace std;
// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi các phần tử
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int target){
    while(left<=right){
        int mid = left + ( right -left ) / 2;
        if ( arr[mid]==target){
            return mid;
        }
        else if ( arr[mid]<target){
            left=mid+1;
        }
        else {
            left=mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[]={ 5, 2, 9, 1, 3 };
    int size=sizeof(arr)/ sizeof(arr[0]);

    bubbleSort(arr,size);

    for( int i=0; i<size ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int target=3;


    int index=binarySearch(arr, 0, size-1, target);

    if ( index != -1){
        cout << index;
    }
    else{
        cout << "Not found";
    }
    return 0;
}