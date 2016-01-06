#include <boost/algorithm/string.hpp>
#include <string>
#include <locale>
#include <iostream>

using namespace boost::algorithm;

int main()
{
    std::string s_1 = "Shashi";
    std::string upper_case1 = to_upper_copy(s_1);
    std::string upper_case2 = to_upper_copy(s_1, std::locale{"kn_IN"});
    std::locale::global(std::locale{"kn_IN"});
    std::cout<<std::locale("").name().c_str()<<std::endl;
    std::cout << upper_case1 << '\n';
    std::cout << upper_case2 << '\n';

    std::string s = "Boost C++ Libraries";
    boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
    std::cout << r << '\n';
    r = find_first(s, "xyz");
    std::cout << r << '\n';
}
