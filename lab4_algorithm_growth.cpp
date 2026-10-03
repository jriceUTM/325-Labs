#include <iostream>
#include  <iomanip>

using namespace std;

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        
        arr[i] = i + 1;
    }

}

long long directAccess(const int arr[], int size) {
    long long counter = 0;
    if (size > 0) {
    
        int value = arr[size / 2];
        counter++;

        (void)value;
    }
    return counter;
}

long long oneLoop(const int arr[], int size) {
    long long counter = 0;
    for (int i = 0; i < size; i++) {
        int value = arr[i];
        counter++;
        (void)value;
    }
    return counter;
}

long long divideBy2(int n) {
    long long counter = 0;
    int current = n;

    while (current > 1) {
        current /= 2;
        counter++;
    }

    return counter;
}

long long insideLoopD2(int n) {
    long long counter = 0;

    for (int i = 0; i < n; i++) {
        int current = n;
        while (current > 1) {
            current /= 2;
            counter++;
        }
    }

    return counter;
}

long long nestedLoop(int n) {
    long long counter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter++;
        }
    }

    return counter;
}

int main() {
    const int sizes[] = {10, 100, 500, 2000};

    cout << left
         << setw(10) << "n"
         << setw(16) << "directAccess"
         << setw(12) << "oneLoop"
         << setw(14) << "divideBy2"
         << setw(16) << "insideLoopD2"
         << setw(14) << "nestedLoop" << endl;

    for (int size : sizes) {
        int *arr = new int[size];
        fillArray(arr, size);

        cout << left
             << setw(10) << size
             << setw(16) << directAccess(arr, size)
             << setw(12) << oneLoop(arr, size)
             << setw(14) << divideBy2(size)
             << setw(16) << insideLoopD2(size)
             << setw(14) << nestedLoop(size)
             << endl;

        delete[] arr;
    }

    cout << "\nComplexities:\n";
    cout << "directAccess(): O(1)\n";
    cout << "oneLoop(): O(n)\n";
    cout << "divideBy2(): O(log n)\n";
    cout << "insideLoopD2(): O(n log n)\n";
    cout << "nestedLoop(): O(n^2)\n";

    return 0;
}
