#include <MD5.hpp>
#include <iostream>
#include <fstream>
#include <argparse/argparse.hpp>

int main(int argc, const char *argv[]) 
{
    argparse::ArgumentParser argumentParser("MD5HashGenerator");
    argumentParser.add_description("MD5 hash generator.");

    argumentParser.add_argument("input")
        .help("will be hashed");
    argumentParser.add_argument("--isfile", "-f")
        .help("is the input a text or a file path.")
        .default_value(false)
        .implicit_value(true);

    try
    {
        argumentParser.parse_args(argc, argv);
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << '\n';
        std::cout << argumentParser;
        exit(0);
    }

    auto file = argumentParser.get<bool>("--isfile");
    auto input = argumentParser.get<std::string>("input");

    if (file)
    {
        std::ifstream inFs(input, std::ios::binary | std::ios::ate);
        std::streamsize size = inFs.tellg();
        inFs.seekg(0, std::ios::beg);
        std::string content(size, '\0');
        if (inFs.read(content.data(), size))
        {
            std::cout << toString(generateMD5Hash(content));
        }
    }
    else
        std::cout << toString(generateMD5Hash(input));
    
}
