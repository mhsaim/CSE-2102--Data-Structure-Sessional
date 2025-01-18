#include <iostream>
using namespace std;

void insertAtPosition(int arr[], int& n, int element, int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    n++;
}

int main() {
    int arr[100];
    int n = 5;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    int element = 10, position = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertAtPosition(arr, n, element, position);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
