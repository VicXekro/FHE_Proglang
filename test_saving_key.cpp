//
// Created by blockchain1 on 12/5/19.
//
#include <iostream>
#include "seal/seal.h"
#include <fstream>

using namespace std;
using namespace seal;

void test_save_data(){
    EncryptionParameters params(scheme_type::BFV);
    size_t poly_modulus_degree = 8192;
    params.set_poly_modulus_degree(poly_modulus_degree);
    params.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    params.set_plain_modulus(1024);
    auto context = SEALContext::Create(params);
    KeyGenerator keyGen(context);

    auto publicKey = keyGen.public_key();
    auto secretKey = keyGen.secret_key();

    Encryptor encryptor(context,publicKey);

    Ciphertext ciphertext;
    Plaintext plaintext(to_string(2));
    encryptor.encrypt(plaintext,ciphertext);

    ofstream file_params("file_params",ios::binary|ios::out);
    ofstream file_pk("pk",ios::binary|ios::out);
    ofstream file_sk("sk",ios::binary|ios::out);
    ofstream file_cipher("cipher",ios::binary|ios::out);
    ciphertext.save(file_cipher);
    params.save(file_params);
    publicKey.save(file_pk);
    secretKey.save(file_sk);
    file_params.close();
    file_pk.close();
    file_sk.close();
    file_cipher.close();

}

void test_read_data(){
    EncryptionParameters params(scheme_type::BFV);
    ifstream file_params("file_params",ios::binary|ios::in);
    ifstream file_pk("pk",ios::binary|ios::in);
    ifstream file_sk("sk",ios::binary|ios::in);
    ifstream file_cipher("cipher",ios::binary|ios::in);
    params.load(file_params);
    auto context = SEALContext::Create(params);
    PublicKey publicKey;
    publicKey.load(context,file_pk);
    SecretKey secretKey;
    secretKey.load(context, file_sk);
    Ciphertext ciphertext;
    ciphertext.load(context,file_cipher);
    Decryptor decryptor(context, secretKey);

    Plaintext plaintext;
    decryptor.decrypt(ciphertext, plaintext);
    cout<<plaintext.to_string()<<endl;
}

/*int main(){
 //test_save_data();
 test_read_data();
}*/
