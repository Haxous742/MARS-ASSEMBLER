#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int left = 0, right = n - 1, mid;
    bool found = false;

    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1; 
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
