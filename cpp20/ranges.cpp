
#include <iostream>
#include <map>
#include <ranges>

int main() {
    std::map<int, int> map = {{1, 2},
                              {3, 4},
                              {5, 6},
                              {7, 8},
                              {9, 10}};

    // In C++20 we can get all the keys/values without iterating and copying them!
    auto view = map |
                std::ranges::views::values |
                std::ranges::views::transform([](auto i) { return i * 2; }) |
                std::ranges::views::reverse;

    for (const auto& v : view) {
        std::cout << v << " ";
    }
    std::cout << '\n';

    // The view does NOT modify the container
    for (const auto& [k, v] : map) {
        std::cout << k << " ";
    }
}