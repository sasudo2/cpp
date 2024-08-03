#include <iostream>
#include <algorithm> // for std::swap

template <typename T>
class Array {
private:
    T* arr;
    int size;

public:
    // Constructor to initialize the array with a given size
    Array(T* inputArr, int s) : size(s) {
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = inputArr[i];
        }
    }

    // Destructor to release allocated memory
    ~Array() {
        delete[] arr;
    }

    // Function to display the array elements
    void displayArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Function to sort the array elements using selection sort
    void sortArray() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(arr[i], arr[minIndex]);
            }
        }
    }
};

int main() {
    const int size = 10;
    int predefinedArray[size] = {34, 7, 23, 32, 5, 62, 32, 14, 26, 11};

    // Create an Array object with predefined values
    Array<int> intArray(predefinedArray, size);

    // Display the array before sorting
    std::cout << "Array before sorting: ";
    intArray.displayArray();

    // Sort the array
    intArray.sortArray();

    // Display the array after sorting
    std::cout << "Array after sorting: ";
    intArray.displayArray();

    return 0;
}
