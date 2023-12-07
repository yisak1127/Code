#include "Copy.h"

void Copy::doFilter(std::ifstream &in, std::ofstream out) {
    char ch;
    while (in.get(ch)) {
        out.put(ch);
    }
}

