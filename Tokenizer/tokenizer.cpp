//
// Created by blockchain1 on 12/5/19.
//

#include "tokenizer.h"

Tokenizer::Tokenizer(std::string filename){
    this->file_path = std::move(filename);
}

void Tokenizer::tokenize_sourceCode() {
    std::ifstream file (this->file_path);
    std::string line;
    int line_number = 0;// lines in the source file
    if (file.is_open()) {

        while (std::getline(file, line)) {
            std::string token;
            int length_line = line.length();
            for(int i= 0; i< length_line; i++){

                // check if character is not space else jump
                if(!isspace(line[i])){
                    token+= line[i];
                    //check if next character is space or end of line
                    if(((i+1)<=length_line) && (isspace(line[i+1])|| i==line.length()-1)){
                        std::cout << token << std::endl;

                        //check if token is datatype
                        if(Token_element::is_datatype(token)){
                            Token_element tokenElement(Token_element::TOKEN_DATATYPE, token, line_number);
                            this-> list_token.push_back(tokenElement); // add token to list
                        }

                        // Check if token is reserved word
                        if(Token_element::is_reserved_word(token)){
                            Token_element tokenElement(token,"",line_number);
                            this->list_token.push_back(tokenElement); // add token to list
                            std::cout << "yup reserved word"<<std::endl;
                        }

                        token = "";
                        i += 1; // skip space character
                    }
                }
            }
            //std::cout <<line <<std::endl;
            line_number++;
        }
        file.close();
    }else{
        std::cerr<<" Cannot Open file" << file_path <<std::endl;
    }

    for(auto & i : list_token){
        std::cout<<i.get_str_value()<<std::endl;
    }
}