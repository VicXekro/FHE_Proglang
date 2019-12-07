//
// Created by blockchain1 on 12/5/19.
//

#include <algorithm>
#include "token_element.h"

// Set of tokens used by the language
const std::string Token_element::TOKEN_IDENTIFIER = "identifier";
const std::string Token_element::TOKEN_VALUE = "value";
const std::string Token_element::TOKEN_DATATYPE = "datatype";
const std::string Token_element::TOKEN_METHOD = "method";
const std::string Token_element::TOKEN_RUN = "run";
const std::string Token_element::TOKEN_PRINT = "print";
const std::string Token_element::TOKEN_OPERATOR = "operator";
const std::string Token_element::TOKEN_BRACES = "braces";
const std::string Token_element::TOKEN_PARENTHESES = "parentheses";

static const std::string list_reserved_word [Token_element::reser_wrd_length] = {Token_element::TOKEN_METHOD,
                                                                                 Token_element::TOKEN_PRINT,
                                                                                 Token_element::TOKEN_RUN};

const std::string* Token_element::RESERVED_WORD = list_reserved_word;

static const std::string supported_datatype[Token_element::supp_datatype_length]= {"int"};
const std::string* Token_element::SUPPORTED_DATATYPE = supported_datatype;

static const std::string simple_operator[Token_element::simple_op_length] = {"+","-","*","^","=",","};
const std::string* Token_element::SIMPLE_OPERATOR = simple_operator;

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
    //std::string s = "Token Identifier: "+this->id+ "\nToken value: "+this->value+
    //        "\nToken line: "+std::to_string(this->line);
    std::string s = this->id+ "-->";
    return s;
}


/**
 * check is the value variable is a reserved word of the language
 * @param value
 * @return
 */
bool Token_element::is_reserved_word(const std::string& value) {
    for (int i=0; i < reser_wrd_length; i++){
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
bool Token_element::is_datatype(const std::string& value){
    for(int i=0; i < supp_datatype_length; i++){
        if(Token_element::SUPPORTED_DATATYPE[i] == value)
            return true;
    }
    return false;
}

/**
 * check is the value variable is an operator supported by the language
 * @param value
 * @return
 */
bool Token_element::is_operator(const std::string&  value){
    for(int i=0; i < simple_op_length; i++){
        if(Token_element::SIMPLE_OPERATOR[i] == value)
            return true;
    }
    return false;
}

/**
 * check is the value variable is a number supported by the language
 * @param value
 * @return
 */
bool Token_element::is_number(const std::string& value)
{
    return !value.empty() && std::find_if(value.begin(),
                                          value.end(), [](char c) { return !std::isdigit(c); }) == value.end();
}
