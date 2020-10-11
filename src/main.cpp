#include <MD5.hpp>
#include <iostream>

int main(int argc, const char *argv[]) {
    std::cout << toString(generateMD5Hash("abc"));
}
