#include <iostream>

using namespace std;

void print(const int *const, size_t);
int* apply_all(const int *const, size_t, const int *const, size_t);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    
    delete [] results;
    cout << endl;
    return 0;
}

void print(const int *const arr, size_t s) {
    cout << "[ ";
    for (size_t i{0}; i<s; i++) {
        cout << *(arr+i) << " ";
    }
    cout << "]" << endl;
}

int* apply_all(const int *const a1, size_t s1, const int *const a2, size_t s2) {
    int* arr_ptr {nullptr};
    arr_ptr = new int[s1*s2];
    
    for (size_t i{0}; i<s2; i++) {
        for (size_t j{0}; j<s1; j++) {
            arr_ptr[s1*i+j] = a2[i]*a1[j];
        }
    }
    
    return arr_ptr;
}