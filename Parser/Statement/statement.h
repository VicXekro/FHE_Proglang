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

class Arguments:public Statement{
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


class Function_Statement: public Statement{
public:
    explicit Function_Statement(std::string& type);
    void add_arguments(Arguments argument);
    void add_to_block(Statement statement);
    void set_identifier_datatype(const std::string& identifier, const std::string& datatype);
    std::string get_identifier();
    std::string get_datatype();
    std::vector<Statement>& get_block();
    std::vector<Arguments>& get_arguments();
private:
    std::string  identifier;
    std::string  datatype;
    std::vector<Arguments> arguments;
    std::vector<Statement> block;
};

class Declaration_Statement: public Statement{
public:
    Declaration_Statement(std::string& type);
    void set_data_type(const std::string& datatype);
    void set_identifier(const std::string& identifier);
    std::string get_data_type();
    std::string get_identifier();

private:
    std::string datatype="";
    std::string identifier="";
};

class Expression_Statement: public Statement{
public:
    Expression_Statement (const std::string& type);
    void set_identifer(const std::string& identifier);
    void add_operators(Token_element tokenElement);
    void add_operands(Token_element tokenElement);
    std::vector<Token_element>& get_operators();
    std::vector<Token_element>& get_operands();
    std::string get_identifiers();
private:
    std::vector<Token_element> operators;
    std::vector<Token_element> operands;
    std::string identifiers;
};

class Print_Statement: public Statement{
public:
    explicit Print_Statement(const std::string& type);
    void set_identifier(const std::string& identifier);
    std::string get_identifier();
private:
    std::string identifier = "";
};




#endif //FHE_PROLANG_STATEMENT_H
