//
// Created by blockchain1 on 12/6/19.
//

#ifndef FHE_PROLANG_STATEMENT_H
#define FHE_PROLANG_STATEMENT_H

#include <string>
#include <vector>
#include "../../Tokenizer/token_element.h"

class Statement {
public:
    std::string get_type();
protected:
    std::string type;
};

class Arguments:Statement{
public:
    Arguments(const std::string& datatype, const std::string& identifier);
    Arguments()= default;
    std::string get_datatype();
    std::string get_identifier();
    void set_datatype(const std::string& datatype);
    void set_identifier(const std::string& identifier);

    std::string get_string();
private:
    std::string datatype;
    std::string identifier;
};


class Function_Statement: Statement{
public:
    explicit Function_Statement(std::string& type);
    void add_arguments(Arguments argument);
    void add_to_block(Statement statement);
    void set_identifier_datatype(const std::string& identifier, const std::string& datatype);

private:
    std::string  identifier;
    std::string  datatype;
    std::vector<Arguments> arguments;
    std::vector<Statement> block;
};

class Declaration_Statement: Statement{
public:
    Declaration_Statement(std::string& type, const std::string &datatype,  const std::string &identifier);
    std::string get_data_type();
    std::string get_identifier();s

private:
    std::string datatype;
    std::string identifier;
};

class Expression_Statement: Statement{

};

class Print_Statement: Statement{

};




#endif //FHE_PROLANG_STATEMENT_H
