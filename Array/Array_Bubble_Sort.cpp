#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {

    for (int leap=0; leap<size-1; leap++)
    {
        for (int i=0; i<size-leap-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
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
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout <<"Unsorted Array: ";
    printArray(arr,size);

    bubbleSort(arr,size);

    cout <<"Sorted Array in Ascending Order: ";
    printArray(arr, size);

    return 0;
}
