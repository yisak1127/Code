#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "FileFilter.h"

class Encryption : public FileFilter {
private:
    int key;

public:
    Encryption();
    Encryption(int key);
    void setKey(int key);
    virtual void doFilter(std::ifstream &in, std::ofstream out) override;
};

#endif // ENCRYPTION_H
