//
// Created by Diogo Muller on 1/27/26.
//

#include <iostream>
#include <ostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cerr << "Usage: foldercreator <path> <filetype>" << std::endl;
        return 1;
    }

    std::string path(argv[1]);
    std::string filetype(argv[2]);


    for (const auto & file : fs::directory_iterator(path))
    {
        auto extension = file.path().extension();
        if (file.path().extension() == filetype)
        {
            fs::path filepath(file.path());
            filepath.replace_extension();
            std::string newPath = path + filepath.filename().c_str();

            std::cout << "Creating folder for " << file.path().filename() << std::endl;
            fs::create_directory(newPath);
            std::string newFile = newPath + "/" + file.path().filename().c_str();
            fs::rename(file.path(), newFile);
        }
    }

    return 0;
}