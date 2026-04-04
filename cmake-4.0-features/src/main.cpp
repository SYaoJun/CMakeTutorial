#include <iostream>
#include <vector>
#include <algorithm>

// C++23 特性示例
int main() {
    // C++23 std::print 支持 (需要 <format>)
    std::cout << "=== CMake 4.0 + C++23 Demo ===" << std::endl;
    
    // C++23 deducing this (如果编译器支持)
    struct Printer {
        auto print(this auto&& self, const std::string& msg) {
            std::cout << msg << std::endl;
        }
    };
    
    Printer p;
    p.print("Hello from deducing this!");
    
    // C++23 std::ranges 增强
    std::vector<int> nums = {3, 1, 4, 1, 5, 9};
    std::ranges::sort(nums);
    
    std::cout << "Sorted: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
