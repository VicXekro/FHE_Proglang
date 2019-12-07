#include <iostream>
#include "seal/seal.h"

using namespace std;
using namespace seal;

/*int main() {
    EncryptionParameters params(scheme_type::BFV);
    size_t poly_modulus_degree = 8192;
    params.set_poly_modulus_degree(poly_modulus_degree);
    params.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    params.set_plain_modulus(1024);

    auto context = SEALContext::Create(params);

    auto &context_data = *context->key_context_data();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/
