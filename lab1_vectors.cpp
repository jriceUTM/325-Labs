#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void display_vec(vector<T> vec){
    for (T v : vec){
        cout << v << endl;
    }
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
}

void practice(){
    vector<int> grades;
    
    grades.push_back(78);
    grades.push_back(92);
    grades.push_back(65);
    grades.push_back(88);
    grades.push_back(95);

    display_vec(grades);

    grades.pop_back();

    display_vec(grades);
}
void challenge_1(){
    vector<int> numbers = {10, 20 ,30 , 40 ,50};

    display_vec(numbers);
    numbers.push_back(60);
    numbers.push_back(70);
    display_vec(numbers);
    numbers.pop_back();
    display_vec(numbers);

}
template <typename T>

T findMax(vector<T> vector){

    if (vector.size() == 0) {return -1;}

    T maxx = vector[0];

    for (T v : vector){
        if (v > maxx){
            maxx = v;
        }
    }

    return maxx;
}

void challenge_2(){
    vector<int> scores = {78, 92, 65, 88, 95, 73};

    int maxx = findMax(scores);

    cout << "Maximum: " << maxx << endl;

}





int main(){

    practice();

    challenge_1();

    challenge_2();
    


    

    return 0;
}