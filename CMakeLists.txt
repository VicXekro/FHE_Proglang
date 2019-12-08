cmake_minimum_required(VERSION 3.15)
project(FHE_ProLang)

set(CMAKE_CXX_STANDARD 17)

add_executable(FHE_ProLang main.cpp test_binary.cpp test_saving_key.cpp Tokenizer/tokenizer.cpp Tokenizer/tokenizer.h Tokenizer/token_element.cpp Tokenizer/token_element.h fhe_prolang_main.cpp Parser/syntax_analyzer.cpp Parser/syntax_analyzer.h Parser/Statement/statement.cpp Parser/Statement/statement.h Parser/Statement/declarartion_statement.cpp Parser/syntax_converter.cpp Parser/syntax_converter.h Parser/Statement/function_statement.cpp Parser/Statement/arguments.cpp Parser/Statement/print_statement.cpp Parser/Statement/expression_statement.cpp)

# Import Microsoft SEAL
find_package(SEAL)

# Link Microsoft SEAL
target_link_libraries(FHE_ProLang SEAL::seal)