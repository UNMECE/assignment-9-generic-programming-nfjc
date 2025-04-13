#include <iostream>
//Creating classes for use in my code.
template <typename T>
class GenericArray {
private:
    T* data;
    int length;

public:
    GenericArray() {
        data = nullptr;
        length = 0;
    }

    ~GenericArray() {
        delete[] data;
    }
//Being able to add new elements is very helpful but also required lol.
    void addElement(T value) {
        T* temp = new T[length + 1];
        for (int i = 0; i < length; i++) {
            temp[i] = data[i];
        }
        temp[length] = value;
        delete[] data;
        data = temp;
        length++;
    }

    T at(int index) {
        if (index >= 0 && index < length) {
            return data[index];
        }
        return 0;
    }
//Size variable returns length.
    int size() {
        return length;
    }
//Summing, maxing, minning, and slicing down here.
    T sum() {
        T total = 0;
        for (int i = 0; i < length; i++) {
            total += data[i];
        }
        return total;
    }

    T max() {
        if (length == 0) return 0;
        T m = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] > m) {
                m = data[i];
            }
        }
        return m;
    }

    T min() {
        if (length == 0) return 0;
        T m = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] < m) {
                m = data[i];
            }
        }
        return m;
    }

    T* slice(int begin, int end) {
        if (begin < 0 || end >= length || begin > end) {
            return nullptr;
        }
        int size = end - begin + 1;
        T* result = new T[size];
        for (int i = 0; i < size; i++) {
            result[i] = data[begin + i];
        }
        return result;
    }
};

int main() {
//Simply declaring the array in the scope of main/
    GenericArray<int> int_array;
//Adding elements to array in main.
    int_array.addElement(0);
    int_array.addElement(2);
    int_array.addElement(4);
    int_array.addElement(6);
    int_array.addElement(8);
//Printing output all pretty.
    std::cout << "Size: " << int_array.size() << "\n";
    std::cout << "Sum: " << int_array.sum() << "\n";
    std::cout << "Max: " << int_array.max() << "\n";
    std::cout << "Min: " << int_array.min() << "\n";

    int* sliced = int_array.slice(1, 3);
    if (sliced != nullptr) {
        std::cout << "Sliced: ";
        for (int i = 0; i < 3; i++) {
            std::cout << sliced[i] << " ";
        }
        std::cout << "\n";
        delete[] sliced;
    } else {
        std::cout << "Invalid slice range.\n";
    }
//Accounting for edge cases or invalid slice ranges.
    return 0;
}

