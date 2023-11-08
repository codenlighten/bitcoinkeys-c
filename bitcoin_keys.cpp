#include <bitcoin/bitcoin.hpp>
#include <iostream>
#include <fstream>

int main() {
    // Create a new private key
    bc::ec_secret privateKey;
    do {
        privateKey = bc::random_secret();
    } while (!bc::verify_private_key(privateKey));

    // Generate the public key
    bc::wallet::ec_public publicKey(privateKey);

    // Save the private and public keys to a file
    std::ofstream privateFile("private_key.txt");
    privateFile << bc::encode_base16(privateKey);
    privateFile.close();

    std::ofstream publicFile("public_key.txt");
    publicFile << publicKey.encoded();
    publicFile.close();

    std::cout << "Private Key: " << bc::encode_base16(privateKey) << std::endl;
    std::cout << "Public Key: " << publicKey.encoded() << std::endl;

    return 0;
}
