//
// Created by blockchain1 on 12/5/19.
//
#include "Tokenizer/tokenizer.h"
#include "Tokenizer/token_element.h"
#include <iostream>
#include "Parser/syntax_converter.h"

int main(int argc, char**argv){
    Syntax_Converter syntaxConverter(argv[1]);
    syntaxConverter.convert();
    return 0;
}