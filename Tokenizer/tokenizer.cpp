//
// Created by blockchain1 on 12/5/19.
//

#include "tokenizer.h"

Tokenizer::Tokenizer(std::string filename){
    this->file_path = std::move(filename);
}

std::vector<Token_element>* Tokenizer::get_list_token() {
    return &(this->list_token);
}

void Tokenizer::tokenize_sourceCode() {
    std::ifstream file (this->file_path);
    std::string line;
    int line_number = 0;// lines in the source file
    if (file.is_open()) {

        while (std::getline(file, line)) {
            std::string token;
            std::string line_element;
            int length_line = line.length();
            for(int i= 0; i< length_line; i++){
                if(!isspace(line[i])){
                    line_element=line[i];
                    // Check if token is parenthesis
                    if (line_element=="(" || line_element==")"){
                        Token_element tokenElement(Token_element::TOKEN_PARENTHESES,line_element,line_number);
                        this->list_token.push_back(tokenElement);
                        //break;
                    }
                        // check if token is curly-braces
                    else if (line_element=="{" || line_element=="}"){
                        Token_element tokenElement(Token_element::TOKEN_BRACES,line_element,line_number);
                        this->list_token.push_back(tokenElement);
                        //break;
                    }
                        // Check if token is operator
                    else if (Token_element::is_operator(line_element)){
                        Token_element tokenElement(Token_element::TOKEN_OPERATOR,line_element,line_number);
                        this->list_token.push_back(tokenElement);
                        //break;
                    }
                    else {
                        token+=line_element;
                        if ((i+1)<length_line) {
                            std::string lookahead_char;
                            lookahead_char.push_back(line[i+1]);
                            if( Token_element::is_operator(lookahead_char) || lookahead_char=="{" ||
                                  lookahead_char=="}" || lookahead_char=="(" || lookahead_char==")" || isspace(line[i+1])){

                                //check if token is datatype
                                if (Token_element::is_datatype(token)) {
                                    Token_element tokenElement(Token_element::TOKEN_DATATYPE, token, line_number);
                                    this->list_token.push_back(tokenElement); // add token to list
                                }
                                    // Check if token is reserved word
                                else if(Token_element::is_reserved_word(token)){
                                    Token_element tokenElement(token,"",line_number);
                                    this->list_token.push_back(tokenElement); // add token to list
                                }
                                //check if number
                                else if(Token_element::is_number(token)){
                                    Token_element tokenElement(Token_element::TOKEN_VALUE,token,line_number);
                                    this->list_token.push_back(tokenElement); // add token to list
                                }

                                //check if identifier
                                else{
                                    Token_element tokenElement(Token_element::TOKEN_IDENTIFIER,token,line_number);
                                    this->list_token.push_back(tokenElement); // add token to list
                                }
                                token = "";
                            }
                        } else if (i==length_line-1){
                            //check if token is datatype
                            if (Token_element::is_datatype(token)) {
                                Token_element tokenElement(Token_element::TOKEN_DATATYPE, token, line_number);
                                this->list_token.push_back(tokenElement); // add token to list
                            }
                                // Check if token is reserved word
                            else if(Token_element::is_reserved_word(token)){
                                Token_element tokenElement(token,"",line_number);
                                this->list_token.push_back(tokenElement); // add token to list
                            }

                            //check if number
                            else if(Token_element::is_number(token)){
                                Token_element tokenElement(Token_element::TOKEN_VALUE,token,line_number);
                                this->list_token.push_back(tokenElement); // add token to list
                            }

                            else{
                                Token_element tokenElement(Token_element::TOKEN_IDENTIFIER,token,line_number);
                                this->list_token.push_back(tokenElement); // add token to list
                            }
                            token = "";
                        }
                    }
                }
            }
            Token_element tokenElement(Token_element::TOKEN_NEW_LINE,"",line_number);
            this->list_token.push_back(tokenElement);
            //std::cout <<line <<std::endl;
            line_number++;
        }
        file.close();
    }else{
        std::cerr<<" Cannot Open file" << file_path <<std::endl;
    }

    /*int count = 0;
    for(auto & i : list_token){
        if(i.get_line() == count)
            std::cout<<i.get_str_value();
        else{
            count = i.get_line();
            std::cout<<"\n"<<i.get_str_value();
        }
    }*/
}