//
// Created by blockchain1 on 12/7/19.
//
#include "statement.h"

Declaration_Statement::Declaration_Statement(std::string& type, Token_element &datatype, Token_element &identifier) {
    this->type = type;
    this->datatype = datatype;
    this->identifier = identifier;
}

Token_element& Declaration_Statement::get_data_type() {
    return this->datatype;
}

Token_element& Declaration_Statement::get_identifier() {
    return this->identifier;
}