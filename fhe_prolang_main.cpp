//
// Created by blockchain1 on 12/5/19.
//
#include "Tokenizer/tokenizer.h"
#include "Tokenizer/token_element.h"
#include <iostream>

int main(int argc, char**argv){
    Tokenizer tokenizer(argv[1]);
    tokenizer.tokenize_sourceCode();
    return 0;
}