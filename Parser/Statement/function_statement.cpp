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
    //std::cout<<arguments.get_string()<<std::endl;
}

std::string Function_Statement::get_datatype() {
    return this->datatype;
}

std::string Function_Statement::get_identifier() {
    return this->identifier;
}

std::vector<Arguments>& Function_Statement::get_arguments() {
    return this->arguments;
}
