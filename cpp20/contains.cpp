#include <iostream>
#include <map>

// Before C++20:
//   Mom can we have contains
//   We already have contains at home
//   contains at home:
template <typename K, typename V>
bool contains(const std::map<K, V>& map, const K& key) {
    return map.find(key) != map.end();
}

int main() {
    // imagine waiting for decades before getting .contains in C++ lmao
    std::map<int, int> m{
        {1, 2},
        {2, 3},
        {3, 4}};

    std::cout << std::boolalpha;  // Print booleans as text
    std::cout << "contains(map, 1): " << contains(m, 1) << std::endl;
    std::cout << "contains(map, 10): " << contains(m, 10) << std::endl;

    // Chad .contains
    std::cout << "map.contains(1): " << m.contains(1) << std::endl;
    std::cout << "map.contains(10): " << m.contains(10) << std::endl;
    return 0;
}
