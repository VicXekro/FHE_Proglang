//
// Created by blockchain1 on 12/6/19.
//

#ifndef FHE_PROLANG_SYNTAX_ANALYZER_H
#define FHE_PROLANG_SYNTAX_ANALYZER_H

#include "../Tokenizer/tokenizer.h"

class Syntax_Analyzer {
public:
    Syntax_Analyzer(const std::string& filepath);
    void analyze();
private:
    std::string filepath;
    void parse_function(std::vector<Token_element>* list_token);
};


#endif //FHE_PROLANG_SYNTAX_ANALYZER_H
