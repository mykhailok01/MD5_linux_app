#include "MD5.hpp"
#include <climits>
#include <cassert>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits>
using Chunk = std::array<std::uint32_t, 16>;// 512 bit
constexpr size_t CHUNK_SIZE = sizeof(Chunk::value_type) * 16;

template <typename I> std::string toString(I val, size_t hexLen = sizeof(I)<<1) 
{
    static const char* digits = "0123456789ABCDEF";
    std::string result(hexLen,'0');
    for (size_t i=0, j=(hexLen-1)*4 ; i<hexLen; ++i,j-=4)
        result[i] = digits[(val>>j) & 0x0f];
    return result;
}

std::string toString(const Chunk &chunk)
{
    std::string result;
    for(size_t i = 0; i < chunk.size(); ++i)
    {
        result += toString(chunk[i]);
    }
    return result;
}

std::uint32_t convert(const std::string &data, std::size_t begin)
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

std::vector<Chunk> toChunks(const std::string& data)
{
    std::vector<Chunk> result;
    for(size_t chunckBeginning = 0; chunckBeginning < data.size(); chunckBeginning += 64)
    {
        Chunk chunk;
        for (size_t index32Bit = 0, dataIndex = chunckBeginning;
            index32Bit < chunk.size() && dataIndex < data.size();
            index32Bit++)
        {
            chunk[index32Bit] = convert(data, dataIndex);
            dataIndex += sizeof(chunk[index32Bit]);
        }
        result.push_back(chunk);
    }
    return result;
}

void insertDataSize(std::vector<Chunk> &chunks, std::uint64_t bitsSize)
{
    return;
}

std::array<std::uint32_t, 4> generateMD5Hash(const std::string &data)
{
    static_assert(CHAR_BIT == 8, "generateMD5Hash requires byte to be 8 bit long");
    static_assert(sizeof(size_t) == 8 || sizeof(size_t) == 4, "generateMD5Hash requires size_t to be 8 or 4 bytes ");

    std::uint64_t bitsSize = static_cast<std::uint64_t>(data.size()) * sizeof(std::string::value_type) * CHAR_BIT;
    assert(bitsSize == std::numeric_limits<std::uint64_t>::max());

    auto chunks = toChunks(data);
    constexpr auto BITS_CHUNK_SIZE = CHUNK_SIZE * CHAR_BIT;
    // if (bitsSize >= BITS_CHUNK_SIZE * chunks.size())
    // chunks[][bitsSize % BITS_CHUNK_SIZE]
    for(size_t i = 0; i < chunks.size(); ++i)
    {
        std::cout << toString(chunks[i]) << " ";
    }
    return {1,1,1,1};
}

std::string toString(const MD5Hash &hash)
{
    std::string result;
    for(size_t i = 0; i < hash.size(); ++i)
    {
        result += toString(hash[i]);
    }
    return result;
}