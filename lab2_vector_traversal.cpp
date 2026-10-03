#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

void guidedPractice() {
    vector<double> temperatures = {72.5, 68.0, 74.5, 71.0, 69.5};

    cout << "Guided Practice - Temperatures\n";
    cout << "Index loop: ";
    for (size_t i = 0; i < temperatures.size(); i++) {
        cout << temperatures[i] << " ";
    }
    cout << "\nFirst: " << temperatures.front();
    cout << "\nLast: " << temperatures.back();
    cout << "\nIndex 2 with []: " << temperatures[2];
    cout << "\nIndex 2 with at(): " << temperatures.at(2) << endl;

    cout << "Range loop: ";
    for (double temp : temperatures) {
        cout << temp << " ";
    }
    cout << endl;

    for (double &temp : temperatures) {
        temp += 1.0;
    }

    cout << "After adding 1.0 with references: ";
    for (double temp : temperatures) {
        cout << temp << " ";
    }
    cout << "\n\n";
}

void task1() {
    vector<int> numbers = {5, 10, 15, 20, 25};

    cout << "Task 1 - Three Ways to Traverse\n";

    cout << "Index-based: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Range-based: ";
    for (int value : numbers) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Iterator-based: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

void task2() {
    vector<int> scores = {78, 91, 66, 84, 95, 73, 83, 92, 89, 77};

    int top1 = scores[0];
    int top2 = -1;
    int top3 = -1;
    int sum = 0;
    int count80 = 0;

    for (int score : scores) {
        sum += score;
        if (score >= 80) {
            count80++;
        }

        if (score > top1) {
            top3 = top2;
            top2 = top1;
            top1 = score;
        } else if (score > top2 && score != top1) {
            top3 = top2;
            top2 = score;
        } else if (score > top3 && score != top2 && score != top1) {
            top3 = score;
        }
    }

    double average = static_cast<double>(sum) / scores.size();

    cout << "Task 2 - Simple Vector Analysis\n";
    cout << "Top three scores: " << top1 << ", " << top2 << ", " << top3 << endl;
    cout << fixed << setprecision(1);
    cout << "Average score: " << average << endl;
    cout << "Scores >= 80: " << count80 << "\n\n";
}

void task3() {
    vector<int> v = {10, 20, 30};

    cout << "Task 3 - Compare [] and at()\n";
    cout << "Valid indices are 0, 1, and 2.\n";

    // The following line is intentionally left commented after testing because
    // operator[] does not check bounds and v[5] causes undefined behavior.
    // cout << v[5] << endl;

    try {
        cout << "Trying v.at(5)...\n";
        cout << v.at(5) << endl;
    } catch (const out_of_range &e) {
        cout << "at() detected an out-of-range index: " << e.what() << endl;
    }
}

int main() {
    guidedPractice();
    task1();
    task2();
    task3();
    return 0;
}
