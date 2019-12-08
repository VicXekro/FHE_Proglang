//
// Created by blockchain1 on 12/5/19.
//
#include "Tokenizer/tokenizer.h"
#include "Tokenizer/token_element.h"
#include <iostream>
#include "Parser/syntax_analyzer.h"

int main(int argc, char**argv){
    Syntax_Analyzer syntaxAnalyzer(argv[1]);
    syntaxAnalyzer.analyze();
    return 0;
}