#include "url.hpp"
#include <iostream>


int main()
{
    using namespace lighturl;
    url hu, fu;
    std::string http = "http://localhost:8080/index.html?a==b&c==d#p3";
    std::string ftp = "ftp://pink:1234567@localhost:2000/lover.mp3";
    hu.parse(http);
    fu.parse(ftp);
    std::cout << hu.query() << " " << hu.params();
    std::cout << fu.print() << std::endl;
    std::cout << hu.print() << std::endl;
    std::string s = hu.print();


    // For networking
    std::string buffer = "http:/";
    url u;
    auto len = buffer.size();
    for (auto i = 0; i < buffer.size(); ++i)
    {
        u.parse(buffer[i]);
    }

    // buffer recv more data
    buffer += "/192.168.1.1/index.htm";
    for (auto i = len; i < buffer.size(); ++i)
    {
        u.parse(buffer[i]);
    }

    std::cout << u.print() << std::endl;

    auto mv_u = std::move(u);
    std::cout << u.print() << std::endl;
    std::cout << mv_u.print() << std::endl;
}
