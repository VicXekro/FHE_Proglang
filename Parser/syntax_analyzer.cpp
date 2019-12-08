//
// Created by blockchain1 on 12/6/19.
//

#include "syntax_analyzer.h"
#include "Statement/statement.h"

Syntax_Analyzer::Syntax_Analyzer(const std::string &filepath) {
    this->filepath = filepath;
}

void Syntax_Analyzer::analyze() {
    Tokenizer tokenizer(filepath);
    tokenizer.tokenize_sourceCode();
    std::vector<Token_element> *list_token = tokenizer.get_list_token();
    int count = 0;
    parse_function(list_token);

}

void Syntax_Analyzer::parse_function(std::vector<Token_element>* list_token) {
    auto i = list_token->begin();
    auto j = std::next(i);
    auto k = std::next(j);
    if(i->get_id()==Token_element::TOKEN_DATATYPE && j->get_id()==Token_element::TOKEN_METHOD &&
     k->get_id()==Token_element::TOKEN_IDENTIFIER){
        std::string type = "function";
        Function_Statement functionStatement(type);
        int count = 0;
        functionStatement.set_identifier_datatype(k->get_value(), i->get_value());
        list_token->erase(i);//erase first element
        list_token->erase(i);//erase second element
        list_token->erase(i);//erase third element

        while(i->get_value()!=")"){
            if(i->get_id()==Token_element::TOKEN_PARENTHESES){
                list_token->erase(i);

            }
        }

    for(; i != list_token->end(); ++i){
        if(i->get_id()==Token_element::TOKEN_IDENTIFIER){

            list_token->erase(i);
            if(i->get_id()==Token_element::TOKEN_PARENTHESES){

            }
        }
    }
    }
    else{
      std::cerr<<"Expecting method declaration at line "<<i->get_line() <<std::endl;
      exit(0);
    }

}