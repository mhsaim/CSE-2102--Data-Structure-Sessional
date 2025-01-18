#include <iostream>
using namespace std;
void removeElement(int arr[], int &size, int index) {
    for (int i=index; i<size-1;i++) {
        arr[i]=arr[i+1];
    }
    size--;
}

int main()
{
    int arr[]={10, 20, 30, 40, 50};
    int size=5;

    int removeindex=2;

    removeElement(arr, size, removeindex);

    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
