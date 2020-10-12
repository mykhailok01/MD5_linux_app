#include <MD5.hpp>
#include <iostream>

int main(int argc, const char *argv[]) {
    toString(generateMD5Hash("a"));
    std::cout << "\n";
    toString(generateMD5Hash(""));
}
