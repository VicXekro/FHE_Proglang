//
// Created by blockchain1 on 12/5/19.
//

#ifndef FHE_PROLANG_TOKENIZER_H
#define FHE_PROLANG_TOKENIZER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "token_element.h"

/*
 * This file implement a scanner for our programming language
 * */
class Tokenizer {
public:
    Tokenizer (std::string filename);
    void tokenize_sourceCode();
    std::vector<Token_element>* get_list_token();
private:
    std::vector<Token_element> list_token;
    std::string file_path;
};


#endif //FHE_PROLANG_TOKENIZER_H
