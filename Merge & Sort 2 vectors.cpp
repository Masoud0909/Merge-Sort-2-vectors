/*Write a function that takes vectors a and b as parameters, each containing a sorted list
of integers. The function merges the two vectors into one sorted vector, which is returned to main().
Follow the algorithm:
While there are elements in both a and b
 Compare an el from a with an el from b,
and append the smaller one to the new vector.
While there are still elements in a
Append all elements in a to the new vector
While there are still elements in b
Append all elements in b to the new vector*/
#include <iostream>
#include <vector>

using namespace std;

/// Function to get input for the vector
vector<int> getinfo() {
    vector<int> list;
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter the elements in sorted order:\n";
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }
    return list;
}

/// Function to print the vector
void print(const vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

/// Function to merge two sorted vectors
vector<int> merge(vector<int>& a, vector<int>& b) {
    // Append all elements from b to a
    for (int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
    }

    /// Sort the combined vector using bubble sort
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                /// Swap a[j] and a[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return a;
}

int main() {
    vector<int> first_half = getinfo();
    vector<int> second_half = getinfo();
    vector<int> list = merge(first_half, second_half);
    print(list);
    return 0;
}
