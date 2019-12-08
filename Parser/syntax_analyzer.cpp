//
// Created by blockchain1 on 12/6/19.
//

#include "syntax_analyzer.h"
#include "Statement/statement.h"

Syntax_Analyzer::Syntax_Analyzer(const std::string &filepath) {
    this->filepath = filepath;
}

void Syntax_Analyzer::analyze() {
    Tokenizer tokenizer(filepath);
    tokenizer.tokenize_sourceCode();
    std::vector<Token_element> *list_token = tokenizer.get_list_token();
    int count = 0;
    parse_sourceCode(list_token);
    //std::cout << *runStatement.params.begin()<<std::endl;
}

void Syntax_Analyzer::parse_sourceCode(std::vector<Token_element>* list_token) {
    auto i = list_token->begin();
    auto j = std::next(i);
    auto k = std::next(j);
    if(i->get_id()==Token_element::TOKEN_DATATYPE && j->get_id()==Token_element::TOKEN_METHOD &&
     k->get_id()==Token_element::TOKEN_IDENTIFIER){
        std::string type = "function";
        Function_Statement functionStatement(type);
        int count = 0;

        //get the return type and name of the function
        functionStatement.set_identifier_datatype(k->get_value(), i->get_value());

        list_token->erase(i);//erase first element
        list_token->erase(i);//erase second element
        list_token->erase(i);//erase third element

        //get the arguments of the function
        if(i->get_id()==Token_element::TOKEN_PARENTHESES) {
            list_token->erase(i);
            //std::cout<<"token erased"<<i->get_line();
            while(i->get_value()!=")"){
                Arguments arguments;
                if(i->get_id()==Token_element::TOKEN_DATATYPE) {
                    arguments.set_datatype(i->get_value());
                    i = std::next(i);
                    if(i->get_id()==Token_element::TOKEN_IDENTIFIER){
                        arguments.set_identifier(i->get_value());
                        functionStatement.add_arguments(arguments);
                    }
                }
                i = std::next(i);
            }
            //std::cout<<"end while"<<i->get_value();
            list_token->erase(i);
            //std::cout<<"errased"<<i->get_value();

            //get different statement of the function
            if(i->get_id()==Token_element::TOKEN_BRACES){
                list_token->erase(i);
                if(i->get_id()==Token_element::TOKEN_NEW_LINE){
                    list_token->erase(i);
                    while(i->get_value()!="}"){

                        if(i->get_id()==Token_element::TOKEN_DATATYPE) {
                            std::string type1 = "declaration";
                            Declaration_Statement declarationStatement(type1);
                            declarationStatement.set_data_type(i->get_value());
                            i = std::next(i);
                            if (i->get_id() == Token_element::TOKEN_IDENTIFIER) {
                                declarationStatement.set_identifier(i->get_value());
                                functionStatement.declarations.push_back(declarationStatement);
                            }
                        }

                        else if (i->get_id()==Token_element::TOKEN_IDENTIFIER) {
                            std::string type2="expression";
                            Expression_Statement expressionStatement(type2);
                            expressionStatement.set_identifer(i->get_value());
                            i = std::next(i);
                            while(i->get_id()!=Token_element::TOKEN_NEW_LINE){
                                if(i->get_id()==Token_element::TOKEN_OPERATOR && i->get_value()!="="){
                                    expressionStatement.add_operators(*i);
                                }else if(i->get_id()==Token_element::TOKEN_IDENTIFIER||
                                         i->get_id()==Token_element::TOKEN_VALUE){
                                    expressionStatement.add_operands(*i);
                                }
                                i = std::next(i);
                            }
                        }


                        else if (i->get_id()==Token_element::TOKEN_PRINT){
                            Print_Statement printStatement(Token_element::TOKEN_PRINT);
                            i = std::next(i);
                            if(i->get_id()==Token_element::TOKEN_IDENTIFIER){
                                printStatement.set_identifier(i->get_value());
                                functionStatement.print_statement.push_back(printStatement);
                            }
                        }

                        i = std::next(i);
                    }
                }else{
                    std::cerr<<"Expecting new line at line "<<i->get_line();
                    exit(0);
                }
            }else{
                std::cerr<<"Expecting braces at line "<<i->get_line();
                exit(0);
            }
        }else{
            std::cerr<<"Expecting paranthesis at line "<<i->get_line();
            exit(0);
        }

        //obtainned the functionstatement
        this->functionStatement = functionStatement;

        //get runstatement
        Run_Statement runStatement;
        while(i->get_id()!=Token_element::TOKEN_RUN && i!=list_token->end()){
            //std::cout<<i->get_id()<<std::endl;
            i = std::next(i);
        }
        if(i->get_id()==Token_element::TOKEN_RUN){
            i = std::next(i);
            if(i->get_id()==Token_element::TOKEN_METHOD){
                i = std::next(i);
                if(i->get_id()==Token_element::TOKEN_IDENTIFIER){
                    runStatement.identifier = i->get_value();
                    i = std::next(i);
                    if(i->get_value()=="("){
                        i = std::next(i);
                        while(i->get_value()!=")"){
                            if(i->get_id()==Token_element::TOKEN_VALUE){
                                runStatement.params.push_back(i->get_value());
                            }
                            i = std::next(i);
                        }
                    }else{
                        std::cerr<<"Expecting parentheses at line "<<i->get_line() <<std::endl;
                        exit(0);
                    }
                }
            }else{
                std::cerr<<"Expecting method Keyword at line "<<i->get_line() <<std::endl;
                exit(0);
            }
        }
        this->runStatement = runStatement;

    }
    else{
      std::cerr<<"Expecting method declaration at line "<<i->get_line() <<std::endl;
      exit(0);
    }
}

