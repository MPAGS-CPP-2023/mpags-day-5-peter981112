#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <cstddef>
#include <string>
#include <vector>


class Cipher{
      public:
    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
    /**
     * \brief Determine the type of cipher algorithm
     *
     * \return the cipher type
     */
    virtual CipherType type() const = 0;
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
#endif
