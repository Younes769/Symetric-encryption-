#ifndef SYMMETRIC_ENCRYPTION_H
#define SYMMETRIC_ENCRYPTION_H

#include <string>
#include <vector>

class SymmetricEncryption {
private:
    std::vector<unsigned char> key_schedule;
    std::string last_key;  // Store the key for reinitialization
    
    // Initialize the key schedule using the provided key
    void initialize_key(const std::string& key);
    
    // Single round of encryption/decryption
    unsigned char process_byte(unsigned char byte, bool encrypting);

public:
    SymmetricEncryption() = default;
    
    // Set or change the encryption key
    void set_key(const std::string& key);
    
    // Main encryption/decryption functions
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);
    
    // Clear the key and reset the cipher
    void clear();
};

#endif // SYMMETRIC_ENCRYPTION_H 