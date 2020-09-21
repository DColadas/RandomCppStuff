#include <array>

int main(int argc, char const* argv[]) {
    // Correct: size can be deduced from the argument (const char[4])
    const auto str1 = std::to_array("Hey");
    static_assert(str1.size() == 4);  //\0 as last character

    // ERROR: argv[0] decays to const char*
    //const auto str2 = std::to_array(argv[0]);

    // (this creates an std::array<const char*, 1>)
    const auto str3 = std::array{argv[0]};

    // Correct
    // Can define the expected type
    const auto i1 = std::to_array({1, 2});
    const auto i2 = std::to_array<int>({3, 4});
    const auto i3 = std::to_array<long>({3, 4});

    return 0;
}
