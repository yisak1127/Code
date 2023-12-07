#include "Uppercase.h"

char Uppercase::transform(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return static_cast<char>(ch - ('a' - 'A'));
    }
    return ch;
}

void Uppercase::doFilter(std::ifstream &in, std::ofstream out) {
    // Set the newline character explicitly
    out << std::noskipws;

    char ch;
    while (in.get(ch)) {
        out.put(transform(ch));
    }
}