#include <cstddef>
#include <string>
#include <vector>

#include "CipherMode.hpp"


class Cipher{
    public:

    virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;

    //default constructor
    Cipher() = default;
    //default copy constructor
    Cipher(const Cipher& rhs)  =default;
    //default move constructor
    Cipher(Cipher& rhs)  =default;
    //default copy assignment operator
    Cipher& operator = (const Cipher& rhs) = default;
    //default move assignment operator
    Cipher& operator = (Cipher& rhs) = default;
    //make default destructor constructor virtual
    virtual ~Cipher() = default;

};