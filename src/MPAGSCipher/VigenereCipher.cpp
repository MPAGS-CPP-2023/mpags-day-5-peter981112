#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"
#include "Alphabet.hpp"
#include "CipherMode.hpp"

#include <algorithm>
#include <string>
#include <cstddef>
#include <vector>
#include <iostream>

VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{

    if (key.empty()) {

        std::cerr
            << "[error] cipher key must not be blank"<< std::endl;
        return;    
    }
    key_ = key;
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{""};
    int len{0};
    len = inputText.size();
    std::string temp_str{""};

    std::size_t temp_key{1};
    int key_len = key_.size();
    std::vector<int> key_int_lst=std::vector<int>(key_len,0);
    // For each letter in input:
    // Find the corresponding letter in the key,
    // repeating/truncating as required
    // Find the Caesar cipher from the lookup
    // Run the (de)encryption  
    // Loop over the input text
    for(int i=0; i<key_len; i++) //convert string key_ into a vector of int
    {
        auto itr = std::find(Alphabet::alphabet.begin(), Alphabet::alphabet.end(), std::toupper(key_[i]));
        key_int_lst.at(i) = std::distance(Alphabet::alphabet.begin(), itr)+1;
    }
   
    for (int i=0; i<len; i++) {
        temp_key = key_int_lst[i%key_len];
        temp_str = temp_str+inputText[i];

        const CaesarCipher cipher{temp_key};
        temp_str = cipher.applyCipher(temp_str, cipherMode); //de, en crypt text

        // Add the new character to the output text
        outputText += temp_str;
        temp_str = "";
    }
    // Add the result to the output
    return outputText;
}