//
// Created by blockchain1 on 12/5/19.
//

#include "token_element.h"

const std::string Token_element::TOKEN_IDENTIFIER = "identifier";
const std::string Token_element::TOKEN_DATATYPE = "datatype";
const std::string Token_element::TOKEN_METHOD = "method";
const std::string Token_element::TOKEN_RUN = "run";
const std::string Token_element::TOKEN_PRINT = "print";

static const std::string list_reserved_word [Token_element::reser_wrd_lenght] = {Token_element::TOKEN_METHOD,
                                                                                 Token_element::TOKEN_PRINT,
                                                                                 Token_element::TOKEN_RUN};

const std::string* Token_element::RESERVED_WORD = list_reserved_word;

static const std::string supported_datatype[Token_element::supp_datatype_lenght]= {"int"};
const std::string* Token_element::SUPPORTED_DATATYPE = supported_datatype;

Token_element::Token_element(std::string id, std::string value, int line) {
    this->id = std::move(id);
    this->value = std::move(value);
    this->line = line;
}


int Token_element::get_line() {
    return this->line;
}

std::string Token_element::get_value() {
    return this->value;
}

std::string Token_element::get_id() {
    return this->id;
}

std::string Token_element::get_str_value() {
    std::string s = "Token Identifier: "+this->id+ "\nToken value: "+this->value+
            "\nToken line: "+std::to_string(this->line);
    return s;
}


/**
 * check is the value variable is a reserved word of the language
 * @param value
 * @return
 */
bool Token_element::is_reserved_word(std::string value) {
    for (int i=0; i<reser_wrd_lenght; i++){
        if(Token_element::RESERVED_WORD[i] == value)
            return true;
    }
    return false;
}

/**
 * check is the value variable is a datatype supported by the language
 * @param value
 * @return
 */
bool Token_element::is_datatype(std::string value){
    for(int i=0; i<supp_datatype_lenght; i++){
        if(Token_element::SUPPORTED_DATATYPE[i] == value)
            return true;
    }
    return false;
}
