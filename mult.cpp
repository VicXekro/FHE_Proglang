#include <iostream>
#include "seal/seal.h"
using namespace std;
using namespace seal;

void mult (int a, int b){
    EncryptionParameters params(scheme_type::BFV);
    size_t poly_modulus_degree = 8192;
    params.set_poly_modulus_degree(poly_modulus_degree);
    params.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    params.set_plain_modulus(1024);
    auto context = SEALContext::Create(params);
    KeyGenerator keyGen(context);
    IntegerEncoder encoder(context);

    auto publicKey = keyGen.public_key();
    auto secretKey = keyGen.secret_key();
    auto relin_keys = keyGen.relin_keys();

    Encryptor encryptor(context, publicKey);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secretKey);

    Plaintext plain_a = encoder.encode(a);
    Ciphertext cipher_a;
    encryptor.encrypt(plain_a, cipher_a);

    Plaintext plain_b = encoder.encode(b);
    Ciphertext cipher_b;
    encryptor.encrypt(plain_b, cipher_b);

    Ciphertext cipher_result;
    Plaintext plain_result;
    evaluator.multiply(cipher_a,cipher_b,cipher_result);
    evaluator.relinearize_inplace(cipher_result, relin_keys);
    decryptor.decrypt(cipher_result, plain_result);
    cout<< "result   " << encoder.decode_int32(plain_result)<<endl;
}

int main (){
    mult(2,3);
    return 0;
}