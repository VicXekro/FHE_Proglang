//
// Created by blockchain1 on 12/7/19.
//
#include "statement.h"

Declaration_Statement::Declaration_Statement(std::string& type, const std::string &datatype, const std::string &identifier) {
    this->type = type;
    this->datatype = datatype;
    this->identifier = identifier;
}

std::string Declaration_Statement::get_data_type() {
    return this->datatype;
}

std::string Declaration_Statement::get_identifier() {
    return this->identifier;
}