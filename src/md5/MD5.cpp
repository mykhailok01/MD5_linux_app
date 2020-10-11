#include "MD5.hpp"
#include <climits>
#include <cassert>
#include <sstream>

using Chunk = std::array<std::uint32_t, 16>;

std::uint32_t convert(const std::string &data, std::size_t begin, bool isLast = false)
{
    assert(begin < data.size());
    std::uint32_t value = 0;
    size_t i = begin, end = begin + 4;
    for (; i < end && i < data.size(); ++i)
    {
        value <<=CHAR_BIT;
        value += static_cast<std::uint32_t>(data[i]);
    }
    return value << (end - i) * CHAR_BIT;
}

std::array<std::uint32_t, 4> generateMD5Hash(const std::string &data)
{
    static_assert(CHAR_BIT == 8, "generateMD5Hash requires byte to be 8 bit long");
    std::array<std::uint32_t, 16> chunk;// 512 bits
    size_t bits_size = data.size() * sizeof(std::string::value_type) * CHAR_BIT;
    return {1,1,1,1};
}

std::string toString(const MD5Hash &hash)
{
    constexpr size_t BYTE_TO_HEX_MAX_LEN = 2;
    auto toHexString = [] (auto val) 
    {
        std::ostringstream out;
        out << std::hex << val;
        return out.str();
    };
    std::string result;
    for(size_t i = 0; i < hash.size(); ++i)
    {
        std::string hex = toHexString(hash[i]);
        result += std::string(sizeof(hash[i]) * BYTE_TO_HEX_MAX_LEN - hex.size(), '0') + hex;
    }
    return result;
}