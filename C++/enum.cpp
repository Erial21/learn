#include<bits/stdc++.h>


enum WeekDay {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}wday;



int main(int argc, char* argv[]) {
    wday = Tuesday;
    std::cout << wday << std::endl;
    for (wday = Monday;wday <= Sunday;wday = (WeekDay)(wday + 1)) {
        std::cout << "enum element: " << wday << std::endl;
    }
    return 0;
}