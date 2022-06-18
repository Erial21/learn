#include<bits/stdc++.h>

int main(){
    std::tuple<int, char, std::string> t(1, 'a', "hello");

    std::cout<<std::get<0>(t)<<std::endl;
    std::cout<<std::get<1>(t)<<std::endl;
    std::cout<<std::get<2>(t)<<std::endl;
    std::cout<<std::get<int>(t)<<std::endl;
    std::cout<<std::get<char>(t)<<std::endl;
    std::cout<<std::get<std::string>(t)<<std::endl;
    return 0;
}