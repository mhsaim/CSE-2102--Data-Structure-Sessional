#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i=1; i<size; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[]={12, 11, 13, 5, 6};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting: ";
    printArray(arr,size);

    insertionSort(arr,size);

    cout<<"Array after sorting: ";
    printArray(arr,size);
    return 0;
}
