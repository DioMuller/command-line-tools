//
// Created by Diogo Muller on 1/23/26.
//

#include <iostream>
#include <ostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cerr << "Usage: mediarenamer <path> <filetype>" << std::endl;
        return 1;
    }

    std::string path(argv[1]);
    std::string filetype(argv[2]);

    for (const auto & entry : fs::directory_iterator(path))
    {
        if ( entry.is_directory() )
        {
            for (const auto & file : fs::directory_iterator(entry))
            {
                auto extension = file.path().extension();
                if (file.path().extension() == filetype)
                {
                    fs::path filepath(file.path());
                    filepath.replace_extension();
                    std::string newPath = path + filepath.filename().c_str();

                    std::cout << "Renaming " << entry.path().filename() << " to " << newPath << std::endl;
                    fs::rename(entry.path(), newPath);
                }
            }
        }
        else
        {
            std::cout << entry.path() << " is not a directory. Skipping." << std::endl;
        }
    }

    return 0;
}