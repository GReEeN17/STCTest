#ifndef STCTEST_FFILE_H
#define STCTEST_FFILE_H
#include <fstream>
#include <cstdlib>
using std::ifstream, std::ios, std::malloc, std::streampos, std::string;

class Ffile {
private:
    ifstream file;
    streampos size;
public:
    explicit Ffile(string file_name) {
        file.open(file_name, ios::binary);
        file.seekg (0, ios::end);
        size = file.tellg();
        file.seekg(0, ios::beg);
    }

    long long getSize() const {
        return size;
    }

    unsigned char* fread(long long size) {
        unsigned char* ptr = (unsigned char*) malloc(size);
        unsigned char byte;
        for (int i = 0; file.read((char*)&byte, sizeof(char)); i++) {
            ptr[i] = byte;
        }
        return ptr;
    }

    ~Ffile() {
        file.close();
    }
};

#endif //STCTEST_FFILE_H
