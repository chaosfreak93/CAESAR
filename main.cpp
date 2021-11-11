#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

char availableLetters[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

char* stringToCharArray(const string& msg) {
    char* array = new char[0];
    for (int i = 0; i < msg.length(); i++) {
        array[i] = msg[i];
    }
    array[msg.length()] = '\0';
    return array;
}

int getCharArraySize(char *str)
{
    int charCnt = 0;
    while (*str != '\0')
    {
        charCnt++;
        str++;
    }

    return charCnt;
}

char* encrypt(char *raw) {
    char* encrypted = new char[0];
    for (int i = 0; i < getCharArraySize(raw); i++) {
        char* out = find(begin(availableLetters), end(availableLetters), raw[i]);
        if (out != end(availableLetters)) {
            if (distance(availableLetters, out) + 3 >= getCharArraySize(availableLetters)) {
                encrypted[i] = availableLetters[(distance(availableLetters, out) + 3) - getCharArraySize(availableLetters)];
            } else {
                encrypted[i] = availableLetters[distance(availableLetters, out) + 3];
            }
        } else {
            cout << "Invalid char: " << raw[i] << endl;
            exit(0);
        }
    }
    encrypted[getCharArraySize(raw)] = '\0';
    return encrypted;
}

char* decrypt(char *raw) {
    char* decrypted = new char[0];
    for (int i = 0; i < getCharArraySize(raw); i++) {
        char* out = find(begin(availableLetters), end(availableLetters), raw[i]);
        if (out != end(availableLetters)) {
            if (distance(availableLetters, out) + 3 >= getCharArraySize(availableLetters)) {
                decrypted[i] = availableLetters[(distance(availableLetters, out) - 3) - getCharArraySize(availableLetters)];
            } else {
                decrypted[i] = availableLetters[distance(availableLetters, out) - 3];
            }
        } else {
            cout << "Invalid char: " << raw[i] << endl;
            exit(0);
        }
    }
    decrypted[getCharArraySize(raw)] = '\0';
    return decrypted;
}

void menu() {
    int mode;
    string input;
    cout << "What do you want to do?\n1 = Encrypt\n2 = Decrypt" << endl;
    cin >> mode;
    if (mode == 1) {
        system("cls");
        cout << "Write what you want to encrypt" << endl;
        cout << "Input: ";
        cin >> input;
        char* output = encrypt(stringToCharArray(input));
        cout << "Encrypted output: " << output << endl;
        Sleep(2000);
        system("cls");
        menu();
    } else if (mode == 2) {
        system("cls");
        cout << "Write what you want to decrypt" << endl;
        cout << "Input: ";
        cin >> input;
        char* output = decrypt(stringToCharArray(input));
        cout << "Decrypted output: " << output << endl;
        Sleep(2000);
        system("cls");
        menu();
    } else {
        system("cls");
        menu();
    }
}

int main() {
    menu();
    return 0;
}
