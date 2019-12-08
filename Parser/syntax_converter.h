//
// Created by blockchain1 on 12/7/19.
//

#ifndef FHE_PROLANG_SYNTAX_CONVERTER_H
#define FHE_PROLANG_SYNTAX_CONVERTER_H

#include "../Tokenizer/tokenizer.h"

class Syntax_Converter {
    public:
        explicit Syntax_Converter(const std::string& filepath);
        void convert();
    private:
        std::string filepath;
        std::string header = "#include <iostream>\n#include<seal/seal.h>\n";
};


#endif //FHE_PROLANG_SYNTAX_CONVERTER_H
