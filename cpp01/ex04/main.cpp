#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    
    inputFile.close();

    std::string result;
    size_t pos = 0;
    size_t s1Length = s1.length();

    while (pos < content.length()) {
        size_t found = content.find(s1, pos);
        if (found != std::string::npos) {
            result.append(content, pos, found - pos);
            result.append(s2);
            pos = found + s1Length;
        } else {
            result.append(content, pos, content.length() - pos);
            break;
        }
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl;
        return;
    }

    outputFile << result;
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    replaceInFile(filename, s1, s2);

    return 0;
}
