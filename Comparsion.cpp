#include "Comparsion.hpp"
#include <list>
#include <algorithm>
#include <map>

bool NoCase::operator()(const std::string& x, const std::string& y) const
{
    auto p = x.begin();
    auto q = y.begin();
    while(p != x.end() && q != y.end() && toupper(*p) == toupper(*q))
    {
        ++p;
        ++q;
    }
    if(p == x.end()) return q != y.end();
    if(q == y.end()) return false;
    return toupper(*p) < toupper(*q);
}


int main()
{
    
    // Without user defined comparision function, map use pointer based comparisions
    // std::map<const char*, int> default_sort_map;
    std::map<const char*, int, CString_less> default_sort_map;
    default_sort_map.insert(std::pair<const char*,int>("Shashi",9739963530));
    default_sort_map.insert(std::pair<const char*,int>("Kitty" ,9900363001));
    default_sort_map.insert(std::pair<const char*,int>("Ramu"  ,9880161180));
    for(auto&  kv:default_sort_map)
        std::cout<<kv.first<<std::endl;
    std::cout<<"*******************"<<std::endl;

    // std::list<std::string> str_list;
    // std::list cannot use std::sort method as std::sort requires random access iterator
    // where as std::list provides only bi-directional iterator
    std::vector<std::string> str_list;
    str_list.push_back("apple");
    str_list.push_back("pear");
    str_list.push_back("Apple");
    str_list.push_back("Pear");
    str_list.push_back("lemon");
    std::sort(str_list.begin(), str_list.end(), NoCase());
    for(auto str : str_list)
        std::cout<<str<<std::endl;
    
    std::multimap<std::string,int> m_equv_map;
    std::multimap<std::string,int>::iterator it;
    m_equv_map.insert(std::pair<std::string, int>("Last", 1));
    m_equv_map.insert(std::pair<std::string, int>("LAST", 2));
    m_equv_map.insert(std::pair<std::string, int>("lASt", 3));
    m_equv_map.insert(std::pair<std::string, int>("LasT", 4));
    for(it = m_equv_map.begin(); it != m_equv_map.end(); it = m_equv_map.upper_bound(it->first))
        std::cout<<(*it).first<<" "<<(*it).second<<std::endl;
    return 0;
}
