//
// Created by blockchain1 on 12/7/19.
//
#include "statement.h"

Declaration_Statement::Declaration_Statement(std::string& type) {
    this->type = type;
}

std::string Declaration_Statement::get_data_type() {
    return this->datatype;
}

std::string Declaration_Statement::get_identifier() {
    return this->identifier;
}

void Declaration_Statement::set_identifier(const std::string & identifier) {
    this->identifier=identifier;
}

void Declaration_Statement::set_data_type(const std::string & datatype) {
    this->datatype=datatype;
}