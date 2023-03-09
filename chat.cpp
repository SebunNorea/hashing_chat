#include <iostream>
using namespace std;

#include "chat.h"
#include "string.h"

Chat::Chat() {}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    uint* hash = sha1(_pass, pass_length);
    data.emplace(_login, hash);
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    // Нужно вернуть true в случае успешного логина
    auto it = data.find(_login);
    if (it == data.end()) return false;

    uint* digest = sha1(_pass, pass_length);

    bool cmpHashes = !memcmp(
        it->second,
        digest,
        SHA1HASHLENGTHBYTES);
    delete[] digest;

    return cmpHashes;
}
