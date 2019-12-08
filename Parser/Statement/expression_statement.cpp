//
// Created by blockchain1 on 12/7/19.
//

#include "statement.h"

Expression_Statement::Expression_Statement(const std::string& type){
    this->type = type;
}

void Expression_Statement::set_identifer(const std::string & identifier) {
    this->identifiers = identifier;
}

std::string Expression_Statement::get_identifiers(){
    return this->identifiers;
}

void Expression_Statement::add_operands(Token_element tokenElement) {
    this->operands.push_back(operands)
}

void Expression_Statement::add_operators(Token_element tokenElement) {
    this0>operators.push_back(operators);
}

std::vector<Token_element>& Expression_Statement::get_operands() {
    return this->operands;
}
std::vector<Token_element>& Expression_Statement::get_operators() {
    return this->operators;
}