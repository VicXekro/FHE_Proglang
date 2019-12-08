//
// Created by blockchain1 on 12/7/19.
//
#include <iostream>
#include "statement.h"
Function_Statement::Function_Statement(std::string &type) {
    this->type = type;
}

void Function_Statement::set_identifier_datatype(const std::string& identifier, const std::string& datatype) {
    this->identifier = identifier;
    this->datatype = datatype;
    //std::cout << this->identifier<<std::endl;
    //std::cout << this->datatype<<std::endl;
}

void Function_Statement::add_arguments(Arguments arguments) {
    this->arguments.push_back(arguments);
    std::cout<<arguments.get_string()<<std::endl;
}

void Function_Statement::add_to_block(class Statement statement) {
    this->add_to_block(statement);
}