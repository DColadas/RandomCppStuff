#include <algorithm>
#include <concepts>
#include <vector>

template <typename T>
concept EqComparable = std::equality_comparable<T>;

// Checks T has operator==
template <EqComparable T>
T find_eq(std::vector<T> v, T obj) {
    return *std::find(v.begin(), v.end(), obj);
}

// Does not check if T has operator==
template <typename T>
T find_n(std::vector<T> v, T obj) {
    return *std::find(v.begin(), v.end(), obj);
}

// Custom type with equality operator defined
struct TestEq {
    int a;
    int b;

    bool operator==(const TestEq& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

// Type without equality operator
struct TestN {
    int a;
    int b;
};

int main() {
    std::vector<TestEq> veq{{1, 2}, {1, 3}, {2, 2}};  // Provides operator==
    std::vector<TestN> vn{{1, 2}, {1, 3}, {2, 2}};    // Does NOT provide operator==

    // Correct: TestEq is EqComparable
    const auto result_eq = find_eq(veq, {1, 3});

    // ERROR: TestN is NOT EqComparable
    // Easy to read compile error, also marked by IntelliSense (red underline)
    const auto result_n = find_eq(vn, {1, 3});

    // ERROR: TestN does not provide operator==
    // Ugly template error only notified on compilation
    const auto result_n2 = find_n(vn, {1, 3});

    return 0;
}