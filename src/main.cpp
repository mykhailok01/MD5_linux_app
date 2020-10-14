#include <MD5.hpp>
#include <iostream>

int main(int argc, const char *argv[]) {
    std::cout << '\n' << toString(generateMD5Hash("a")) << '\n';
    std::cout << "\n";
    std::cout << toString(generateMD5Hash("")) << '\n';
}
