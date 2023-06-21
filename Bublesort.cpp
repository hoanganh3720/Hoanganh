#include <iostream>

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi các phần tử
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Phần tử được tìm thấy, trả về chỉ số của nó
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Phần tử cần tìm nằm bên phải
        }
        else {
            right = mid - 1; // Phần tử cần tìm nằm bên trái
        }
    }

    return -1; // Phần tử không tồn tại trong mảng
}

int main() {
    int arr[] = { 5, 2, 9, 1, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sắp xếp mảng bằng Bubble Sort
    bubbleSort(arr, size);

    std::cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int target = 3;

    // Tìm kiếm phần tử bằng Binary Search
    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1) {
        std::cout << "Phan tu " << target << " duoc tim thay tai vi tri " << index << std::endl;
    }
    else {
        std::cout << "Phan tu " << target << " khong ton tai trong mang" << std::endl;
    }

    return 0;
}
