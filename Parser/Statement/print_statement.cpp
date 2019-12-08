//
// Created by blockchain1 on 12/7/19.
//

#include "statement.h"

Print_Statement::Print_Statement(const std::string& type){
    this->type = type;
}

std::string Print_Statement::get_identifier() {
    return this->identifier;
}

void Print_Statement::set_identifier(const std::string & identifier) {
    this->identifier = identifier;
}