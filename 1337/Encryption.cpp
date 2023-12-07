#include "Encryption.h"

Encryption::Encryption() : key(5) {}

Encryption::Encryption(int key) : key(key) {}

void Encryption::setKey(int key)
{
    this->key = key;
}

void Encryption::doFilter(std::ifstream &in, std::ofstream out)
{
    char ch;
    while (in.get(ch))
    {
        if (isprint(ch))
        {
            int encryptedValue = static_cast<int>(ch) + key;

            // Handle rollover
            if (encryptedValue > 126)
            {
                encryptedValue = 32 + (encryptedValue - 127);
            }
            else if (encryptedValue < 32)
            {
                encryptedValue = 127 - (32 - encryptedValue);
            }

            out.put(static_cast<char>(encryptedValue));
        }
        else
        {
            // Handle non-printable characters as needed
            out.put(ch);
        }
    }
}
