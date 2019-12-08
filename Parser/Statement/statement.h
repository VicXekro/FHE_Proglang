//
// Created by blockchain1 on 12/6/19.
//

#ifndef FHE_PROLANG_STATEMENT_H
#define FHE_PROLANG_STATEMENT_H

#include <string>
#include <vector>
#include "../../Tokenizer/token_element.h"

/*class Statement {
public:
    std::string get_type();
protected:
    std::string type;
};*/

class Arguments{
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

class Declaration_Statement{
public:
    Declaration_Statement(std::string& type);
    void set_data_type(const std::string& datatype);
    void set_identifier(const std::string& identifier);
    std::string get_data_type();
    std::string get_identifier();
    std::string type;
private:
    std::string datatype="";
    std::string identifier="";
};

class Expression_Statement{
public:
    Expression_Statement (const std::string& type);
    void set_identifer(const std::string& identifier);
    void add_operators(Token_element tokenElement);
    void add_operands(Token_element tokenElement);
    std::vector<Token_element>& get_operators();
    std::vector<Token_element>& get_operands();
    std::string get_identifiers();
    std::string type;
private:
    std::vector<Token_element> operators;
    std::vector<Token_element> operands;
    std::string identifiers;
};

class Print_Statement{
public:
    explicit Print_Statement(const std::string& type);
    void set_identifier(const std::string& identifier);
    std::string get_identifier();
    std::string type;
private:
    std::string identifier = "";
};

class Function_Statement{
public:
    explicit Function_Statement(std::string& type);
    Function_Statement()= default;
    void add_arguments(Arguments argument);

    void set_identifier_datatype(const std::string& identifier, const std::string& datatype);
    std::string get_identifier();
    std::string get_datatype();

    std::vector<Arguments>& get_arguments();

    std::vector<Declaration_Statement> declarations;
    std::vector<Expression_Statement> expressions;
    std::vector<Print_Statement> print_statement;
    std::string  type;
private:
    std::string  identifier;
    std::string  datatype;
    std::vector<Arguments> arguments;
};

class Run_Statement{
public:
    Run_Statement ()= default;
    std::vector<std::string> params;
    std::string identifier;

};




#endif //FHE_PROLANG_STATEMENT_H
