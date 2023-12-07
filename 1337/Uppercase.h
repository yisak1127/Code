#ifndef UPPERCASE_H
#define UPPERCASE_H

#include "FileFilter.h"

class Uppercase : public FileFilter {
private:
    char transform(char ch);

public:
    virtual void doFilter(std::ifstream &in, std::ofstream out) override;
};

#endif // UPPERCASE_H
