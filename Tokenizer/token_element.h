//
// Created by blockchain1 on 12/5/19.
//

#ifndef FHE_PROLANG_TOKEN_ELEMENT_H
#define FHE_PROLANG_TOKEN_ELEMENT_H

#include <string>
#include <utility>

class Token_element {
public:
    static const std::string TOKEN_IDENTIFIER;
    static const std::string TOKEN_DATATYPE ;
    static const std::string TOKEN_METHOD;
    static const std::string TOKEN_RUN ;
    static const std::string TOKEN_PRINT;

    //list of reserved word used by the language
    static const size_t reser_wrd_lenght = 3;
    static const size_t supp_datatype_lenght = 1;
    static const std::string* SUPPORTED_DATATYPE;
    static const std::string* RESERVED_WORD;

    Token_element(std::string id, std::string value, int line);
    Token_element() = default;
    std::string get_id(); // return the ID of the token
    std::string get_value(); // return the value of the token
    int get_line(); // return the line at which the token was found


    static bool is_reserved_word(std::string value);
    static bool is_datatype(std::string value);

    std::string get_str_value();
private:
    std::string id;
    std::string value;
    int line{};
};




#endif //FHE_PROLANG_TOKEN_ELEMENT_H
