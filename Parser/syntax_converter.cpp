//
// Created by blockchain1 on 12/7/19.
//

#include "syntax_converter.h"

Syntax_Converter::Syntax_Converter(const std::string &filepath) {
    this->filepath = filepath;
}

void Syntax_Converter::convert() {
    Syntax_Analyzer syntaxAnalyzer(filepath);
    syntaxAnalyzer.analyze();
    Function_Statement functionStatement = syntaxAnalyzer.get_function_statement();
    Run_Statement runStatement = syntaxAnalyzer.get_run_statement();
    std::string final_cpp_file = header;

    define_method_header(final_cpp_file, functionStatement);

    final_cpp_file+=hearder_method;

    define_params_seal(final_cpp_file, functionStatement);

    define_operation(final_cpp_file, functionStatement);

    print_method_definition(final_cpp_file, functionStatement);

    run_method_definition(final_cpp_file, runStatement);

    std::cout<<final_cpp_file;
}

void Syntax_Converter::define_method_header(std::string& final_cpp_file, Function_Statement functionStatement){
    final_cpp_file+= functionStatement.get_datatype()+" "+functionStatement.get_identifier()+" (";
    auto i = functionStatement.get_arguments().begin();
    final_cpp_file+=i->get_datatype()+" "+i->get_identifier();
    i =std::next(i);
    for(i;i!=functionStatement.get_arguments().end();++i){
        final_cpp_file+=", "+i->get_datatype()+" "+i->get_identifier();
    }
    final_cpp_file+="){\n";
}

void Syntax_Converter::define_params_seal(std::string& final_cpp_file, Function_Statement functionStatement){
    for(auto &i: functionStatement.get_arguments()){
        final_cpp_file+= "    Plaintext plain_"+i.get_identifier()+" = encoder.encode("+i.get_identifier()+");\n";
        final_cpp_file+= "    Ciphertext cipher_"+i.get_identifier()+";\n";
        final_cpp_file+= "    encryptor.encrypt(plain_"+i.get_identifier()+", cipher_"+i.get_identifier()+");\n\n";
    }
}

void Syntax_Converter::define_operation(std::string& final_cpp_file, Function_Statement functionStatement){
    for(auto &i: functionStatement.declarations){
        final_cpp_file+="    Ciphertext cipher_"+i.get_identifier()+";\n";
        final_cpp_file+="    Plaintext plain_"+i.get_identifier()+";\n";
    }
    for(auto &i: functionStatement.expressions){
        Expression_Statement statement = i;
        auto operator_it = statement.get_operators().begin();
        //std::cout<<"Operator "<< operator_it->get_value()<<std::endl;
        auto operands_it = statement.get_operands().begin();
        auto operands_jt = std::next(operands_it);

        //first add
        if(operator_it->get_value() == "+"){
            if(operands_jt->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_jt->get_value()+" = encoder.encode("+operands_jt->get_value()+");\n";
                final_cpp_file+="    evaluator.add_plain(cipher_"+operands_it->get_value()+",plain_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";

            }else if (operands_it->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_it->get_value()+" = encoder.encode("+operands_it->get_value()+");\n";
                final_cpp_file+="    evaluator.add_plain(cipher_"+operands_jt->get_value()+",plain_"+operands_it->get_value()+",cipher_"+i.get_identifiers()+");\n";
            }else{
                final_cpp_file +="    evaluator.add(cipher_"+operands_it->get_value()+",cipher_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";
            }

          //first minus
        }else if(operator_it->get_value() == "-"){
            if(operands_jt->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_jt->get_value()+" = encoder.encode("+operands_jt->get_value()+");\n";
                final_cpp_file+="    evaluator.sub_plain(cipher_"+operands_it->get_value()+",plain_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";

            }else if (operands_it->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_it->get_value()+" = encoder.encode("+operands_it->get_value()+");\n";
                final_cpp_file+="    evaluator.sub_plain(cipher_"+operands_jt->get_value()+",plain_"+operands_it->get_value()+",cipher_"+i.get_identifiers()+");\n";
            }else{
                final_cpp_file +="    evaluator.sub(cipher_"+operands_it->get_value()+",cipher_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";
            }

         //first mult
        }else if(operator_it->get_value() == "*"){
            if(operands_jt->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_jt->get_value()+" = encoder.encode("+operands_jt->get_value()+");\n";
                final_cpp_file+="    evaluator.multiply_plain(cipher_"+operands_it->get_value()+",plain_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";
                final_cpp_file +="    evaluator.relinearize_inplace(cipher_"+i.get_identifiers()+", relin_keys);\n";

            }else if (operands_it->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file+="    Plaintext plain_"+operands_it->get_value()+" = encoder.encode("+operands_it->get_value()+");\n";
                final_cpp_file+="    evaluator.multiply_plain(cipher_"+operands_jt->get_value()+",plain_"+operands_it->get_value()+",cipher_"+i.get_identifiers()+");\n";
                final_cpp_file +="    evaluator.relinearize_inplace(cipher_"+i.get_identifiers()+", relin_keys);\n";
            }else{
                final_cpp_file +="    evaluator.multiply(cipher_"+operands_it->get_value()+",cipher_"+operands_jt->get_value()+",cipher_"+i.get_identifiers()+");\n";
                final_cpp_file +="    evaluator.relinearize_inplace(cipher_"+i.get_identifiers()+", relin_keys);\n";
            }

         //exponentiation
        }else if(operator_it->get_value()=="^"){
            if(operands_jt->get_id()==Token_element::TOKEN_VALUE){
                final_cpp_file +="    evaluator.exponentiate(cipher_"+operands_it->get_value()+", "+operands_jt->get_value()+
                                    ", cipher_"+i.get_identifiers()+");\n";
                final_cpp_file +="    evaluator.relinearize_inplace(cipher_"+i.get_identifiers()+", relin_keys);\n";

            } else{
                std::cerr<<"Expected litteral integer after ^ operator, line "<<operands_jt->get_line()<<std::endl;
                exit(0);
            }
        }
    }
}

void Syntax_Converter::print_method_definition(std::string& final_cpp_file, Function_Statement functionStatement){
    for(auto &i: functionStatement.print_statement){
        final_cpp_file += "    decryptor.decrypt(cipher_"+i.get_identifier()+", plain_"+i.get_identifier()+");\n";
        final_cpp_file += "    cout<< \""+i.get_identifier()+"\" << encoder.decode_int32(plain_"+i.get_identifier()+")<<endl;\n";
    }
    final_cpp_file+="}\n";
}

void Syntax_Converter::run_method_definition(std::string& file_cpp, Run_Statement runStatement){
    file_cpp+="\nint main (){\n";
    file_cpp+= "    "+runStatement.identifier +"(";
    auto i = runStatement.params.begin();
    file_cpp+= *i;
    i = std::next(i);
    for(i;i!=runStatement.params.end();++i){
        file_cpp+= ","+*i;
    }
    file_cpp+=");\n    return 0;\n}";
};

