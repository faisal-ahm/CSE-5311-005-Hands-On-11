#include <bits/stdc++.h>
using namespace std;

class DynamicArray {
    int* data;
    int capacity;
    int size;

    // Double the capacity when array is full
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    // Halve the capacity when array is less than one-fourth full
    void shrink() {
        capacity /= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    // Constructor
    DynamicArray() : capacity(1), size(0) {
        data = new int[capacity];
    }

    // Add an element at the end
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Remove last element and shrink if needed
    void pop_back() {
        if (size > 0) {
            size--;
            if (size > 0 && size <= capacity / 4) {
                shrink();
            }
        }
    }

    // Get element at index
    int at(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw out_of_range("Index out of bounds");
    }

    // Get current size
    int get_size() const {
        return size;
    }

    // Get current capacity
    int get_capacity() const {
        return capacity;
    }

    void print_array(){
    	cout << "Elements: ";
    	for(int i = 0; i < size; i++){
    		cout << this->at(i) << " ";
    	}
    	cout << endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr;
    for (int i = 0; i < 10; i++) {
    	int x;
    	cin >> x; //input given in inputf.in file
        arr.push_back(x);
    }

    arr.print_array();
    cout << "Initial capacity: " << arr.get_capacity() << endl;

    for (int i = 0; i < 8; i++) {
        arr.pop_back();
        cout << "Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << endl;
    }

    return 0;
}

/*
OUTPUT:
Elements: 1 2 3 4 7 1 2 4 1 99 
Initial capacity: 16
Size: 9, Capacity: 16
Size: 8, Capacity: 16
Size: 7, Capacity: 16
Size: 6, Capacity: 16
Size: 5, Capacity: 16
Size: 4, Capacity: 8
Size: 3, Capacity: 8
Size: 2, Capacity: 4
*/
