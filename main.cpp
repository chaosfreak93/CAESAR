#include <iostream>
#include <string>

char availableLetters[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

int* stringToASCIIArray(const std::string& msg) {
    int* array = new int[0];
    for (int i = 0; i <= msg.length(); i++) {
        array[i] = (unsigned char)msg[i];
    }
    return array;
}

int main() {
    std::string test;
    std::cout << "Please write something, then press enter" << std::endl;
    std::getline(std::cin, test);
    std::cout << stringToASCIIArray(test) << std::endl;
    /**char *out = std::find(std::begin(availableLetters), std::end(availableLetters), stringToASCIIArray(test)[0]);
    if (out != std::end(availableLetters)) {
        std::cout << stringToASCIIArray(test) << std::endl;
    } else {

    }**/
    return 0;
}
