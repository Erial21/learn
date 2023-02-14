// findSubStrPosition.cpp
#include <iostream>
#include <string>

bool isSubstr(std::string str1, std::string str2) {
    if (str1.length() < str2.length())
        return false;
    int index = 0;
    while (index < str2.length()) {
        if (str2[index] == str1[index])
            index++;
        else
            return false;
    }
    return true;
}

int findSubStrPosition(std::string str1, std::string str2) {
    int index = 0;
    while (index < (str1.length() - str2.length())) {
        if (isSubstr(str1.substr(index), str2))
            return index + 1;  // start 1
        else
            index++;
    }
    return -1;
}

int main() {
    std::string str1 = "ABCDLANCEXYZ";
    std::string str2 = "LANCE";
    int position = 0;
    position = findSubStrPosition(str1, str2);
    std::cout << "the substring position is " << position << std::endl;
    // std::cout<< "the substring position is "<< str1.find(str2) << std::endl;
    return 0;
}