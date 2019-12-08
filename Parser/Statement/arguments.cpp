//
// Created by blockchain1 on 12/7/19.
//
#include "statement.h"

Arguments::Arguments(const std::string &datatype, const std::string &identifier) {
    this->identifier = identifier;
    this->datatype = datatype;
}

std::string Arguments::get_identifier() {
    return this->identifier;
}

std::string Arguments::get_datatype() {
    return this->datatype;
}

void Arguments::set_identifier(const std::string & identifier) {
    this->identifier=identifier;
}

void Arguments::set_datatype(const std::string & datatype) {
    this->datatype=datatype;
}

std::string Arguments::get_string() {
    return "Datatye: "+ this->datatype+"Identifer: "+this->identifier;
}
