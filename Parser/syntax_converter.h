//
// Created by blockchain1 on 12/7/19.
//

#ifndef FHE_PROLANG_SYNTAX_CONVERTER_H
#define FHE_PROLANG_SYNTAX_CONVERTER_H

#include "../Tokenizer/tokenizer.h"
#include "syntax_analyzer.h"

class Syntax_Converter {
    public:
        explicit Syntax_Converter(const std::string& filepath);
        void convert();
    private:
        std::string filepath;
        std::string header = "#include <iostream>\n#include \"seal/seal.h\"\n"
                             "using namespace std;\nusing namespace seal;\n\n";
        std::string hearder_method = "    EncryptionParameters params(scheme_type::BFV);\n"
                                     "    size_t poly_modulus_degree = 8192;\n"
                                     "    params.set_poly_modulus_degree(poly_modulus_degree);\n"
                                     "    params.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));\n"
                                     "    params.set_plain_modulus(1024);\n"
                                     "    auto context = SEALContext::Create(params);\n"
                                     "    KeyGenerator keyGen(context);\n"
                                     "    IntegerEncoder encoder(context);\n"
                                     "\n"
                                     "    auto publicKey = keyGen.public_key();\n"
                                     "    auto secretKey = keyGen.secret_key();\n"
                                     "    auto relin_keys = keygen.relin_keys();\n\n"
                                     "    Encryptor encryptor(context, public_key);\n"
                                     "    Evaluator evaluator(context);\n"
                                     "    Decryptor decryptor(context, secret_key);\n\n";

        void define_method_header(std::string& final_cpp, Function_Statement functionStatement);
    void define_params_seal(std::string& final_cpp_file, Function_Statement functionStatement);
    void define_operation(std::string& final_cpp_file, Function_Statement functionStatement);
    void run_method_definition(std::string& file_cpp, Run_Statement runStatement);
};


#endif //FHE_PROLANG_SYNTAX_CONVERTER_H
