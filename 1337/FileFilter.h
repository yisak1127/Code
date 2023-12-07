#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <fstream>

class FileFilter {
public:
    virtual void doFilter(std::ifstream &in, std::ofstream out) = 0;
};

#endif // FILEFILTER_H
