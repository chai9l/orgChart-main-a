#include "OrgChart.hpp"

using namespace std;

using namespace ariel;

string& ariel::Node::get_name() {
    return this->name;
}

OrgChart &OrgChart::add_root(const string &root)
{
    return *this;
}
OrgChart &OrgChart::add_sub(const string &parent, const string &child)
{
    return *this;
}

OrgChart::iter OrgChart::begin_level_order()
{
    iter it;
    return it;
}

OrgChart::iter OrgChart::end_level_order()
{
    iter it;
    return it;
}

OrgChart::iter OrgChart::begin_reverse_order()
{
    iter it;
    return it;
}
OrgChart::iter OrgChart::reverse_order()
{
    iter it;
    return it;
}

OrgChart::iter OrgChart::begin_preorder()
{
    iter it;
    return it;
}

OrgChart::iter OrgChart::end_preorder() {
    iter it;
    return it;
}

OrgChart::iter OrgChart::begin(){
    iter it;
    return it;
}

OrgChart::iter OrgChart::end() {
    iter it;
    return it;
}

namespace ariel {
    ostream &operator<<(ostream &os, const OrgChart &oc){
        return os;
    }
}

