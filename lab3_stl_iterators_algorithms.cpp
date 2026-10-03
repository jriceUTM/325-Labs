#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void task1() {
    vector<int> v = {5, 10, 15};

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it = *it + 1;
    }

    cout << "Task 1 - Values after modification: ";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
        // *it = *it + 1; // This would fail because cbegin()/cend() are read-only.
    }
    cout << "\n\n";
}

void task2() {
    const vector<int> scores = {78, 92, 65, 88, 74, 92};
    int target;

    cout << "Task 2 - Enter a score to find: ";
    cin >> target;

    auto result = find(scores.cbegin(), scores.cend(), target);
    if (result != scores.cend()) {
        cout << "Found\n\n";
    } else {
        cout << "Not found\n\n";
    }
}

void task3() {
    vector<int> values = {78, 92, 65, 88, 74, 92};

    sort(values.begin(), values.end());
    cout << "Task 3 - Ascending: ";
    for (auto value : values) {
        cout << value << " ";
    }
    cout << endl;

    sort(values.begin(), values.end(), greater<int>());
    cout << "Task 3 - Descending: ";
    for (auto value : values) {
        cout << value << " ";
    }
    cout << "\n\n";
}

void task4() {
    vector<int> values = {78, 92, 65, 88, 74, 92};

    // count() returns how many elements in the range equal the requested value.
    auto numberOf92s = count(values.cbegin(), values.cend(), 92);

    cout << "Task 4 - count()\n";
    cout << "The value 92 occurs " << numberOf92s << " times.\n";
    cout << "count() returns a count and does not change the vector.\n";
}

int main() {
    task1();
    task2();
    task3();
    task4();
    return 0;
}
