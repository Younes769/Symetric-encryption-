#include "symmetric_encryption.h"
#include <stdexcept>

void SymmetricEncryption::initialize_key(const std::string& key) {
    // Initialize key schedule (similar to RC4 KSA)
    key_schedule.resize(256);
    
    // Initialize array with sequential numbers
    for (int i = 0; i < 256; i++) {
        key_schedule[i] = i;
    }
    
    // Mix the key into the schedule
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + key_schedule[i] + key[i % key.length()]) & 0xFF;
        std::swap(key_schedule[i], key_schedule[j]);
    }
}

unsigned char SymmetricEncryption::process_byte(unsigned char byte, bool encrypting) {
    // Reset i and j for each message to maintain synchronization
    static unsigned char i = 0;
    static unsigned char j = 0;
    
    // Generate key stream
    i = (i + 1) & 0xFF;
    j = (j + key_schedule[i]) & 0xFF;
    std::swap(key_schedule[i], key_schedule[j]);
    
    // Get key byte
    unsigned char k = key_schedule[(key_schedule[i] + key_schedule[j]) & 0xFF];
    
    // XOR operation is its own inverse, so same operation for encrypt/decrypt
    return byte ^ k;
}

std::string SymmetricEncryption::encrypt(const std::string& plaintext) {
    if (key_schedule.empty()) {
        throw std::runtime_error("No key set");
    }
    
    std::string result;
    result.reserve(plaintext.length());
    
    // Reset state before processing
    initialize_key(last_key);
    
    for (unsigned char c : plaintext) {
        result.push_back(process_byte(c, true));
    }
    
    return result;
}

std::string SymmetricEncryption::decrypt(const std::string& ciphertext) {
    if (key_schedule.empty()) {
        throw std::runtime_error("No key set");
    }
    
    std::string result;
    result.reserve(ciphertext.length());
    
    // Reset state before processing
    initialize_key(last_key);
    
    for (unsigned char c : ciphertext) {
        result.push_back(process_byte(c, false));
    }
    
    return result;
}

void SymmetricEncryption::set_key(const std::string& key) {
    if (key.empty()) {
        throw std::runtime_error("Empty key provided");
    }
    last_key = key;  // Store key for reinitialization
    initialize_key(key);
}

void SymmetricEncryption::clear() {
    key_schedule.clear();
    last_key.clear();
} 