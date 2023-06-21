#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findCommonElements(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> commonElements;

    std::vector<int> sortedVec1 = vec1;
    std::vector<int> sortedVec2 = vec2;

    // Sắp xếp các vector để dễ dàng sử dụng hàm set_intersection
    std::sort(sortedVec1.begin(), sortedVec1.end());
    std::sort(sortedVec2.begin(), sortedVec2.end());

    // Tạo một vector đủ lớn để chứa các phần tử chung
    std::vector<int> intersectionVec(sortedVec1.size() + sortedVec2.size());

    // Tìm các phần tử chung giữa hai vector
    auto it = std::set_intersection(sortedVec1.begin(), sortedVec1.end(), sortedVec2.begin(), sortedVec2.end(), intersectionVec.begin());

    // Resize vector intersectionVec để chỉ chứa các phần tử chung thực sự
    intersectionVec.resize(it - intersectionVec.begin());

    return intersectionVec;
}

int main() {
    std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
    std::vector<int> vec2 = { 4, 5, 6, 7 };

    std::vector<int> commonElements = findCommonElements(vec1, vec2);

    if (commonElements.empty()) {
        std::cout << "No common elements found." << std::endl;
    }
    else {
        std::cout << "Common elements: ";
        for (int element : commonElements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
