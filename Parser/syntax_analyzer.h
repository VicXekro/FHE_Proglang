//
// Created by blockchain1 on 12/6/19.
//

#ifndef FHE_PROLANG_SYNTAX_ANALYZER_H
#define FHE_PROLANG_SYNTAX_ANALYZER_H

#include "../Tokenizer/tokenizer.h"
#include "Statement/statement.h"

class Syntax_Analyzer {
public:
    Syntax_Analyzer(const std::string& filepath);
    void analyze();
    Function_Statement get_function_statement();
    Run_Statement get_run_statement();

private:
    std::string filepath;
    void parse_sourceCode(std::vector<Token_element>* list_token);
    void parse_run(std::vector<Token_element>* list_token);
    Function_Statement functionStatement;
    Run_Statement runStatement;
};


#endif //FHE_PROLANG_SYNTAX_ANALYZER_H
