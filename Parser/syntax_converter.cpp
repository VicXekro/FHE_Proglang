//
// Created by blockchain1 on 12/7/19.
//

#include "syntax_converter.h"

Syntax_Converter::Syntax_Converter(const std::string &filepath) {
    this->filepath = filepath;
}

void Syntax_Converter::convert() {
    Tokenizer tokenizer(filepath);
    tokenizer.tokenize_sourceCode();
    std::string s;
    for(auto i: *tokenizer.get_list_token()){
        if(i.get_id()==Token_element::TOKEN_DATATYPE){
            s+=i.get_value()+" ";
        }
        else if(i.get_id() == Token_element::TOKEN_IDENTIFIER){
            s+=i.get_value()+" ";
        }
        else if(i.get_id() == Token_element::TOKEN_PARENTHESES){
            s+=i.get_value()+ " ";
        }
        else if(i.get_id() == Token_element::TOKEN_OPERATOR){
            if(i.get_value() == ",")
                s+=i.get_value();
            else if(i.get_value() == "=")
                s+=i.get_value();
        }
        else if (i.get_id() == Token_element::TOKEN_BRACES){
            s+=i.get_value()+"\n";
        }
        else if(i.get_id() == Token_element::TOKEN_VALUE){
            s+=i.get_value()+" ";
        }

    }
    std::cout<< s ;
}