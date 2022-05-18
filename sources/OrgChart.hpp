#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
namespace ariel
{

    class Node
    {
    private:
        string name;

    public:
        void add_child(Node c);
        void set_name(string &r);
        string& get_name();
        vector<Node> children;
    };

    class OrgChart
    {

    private:
        Node *root;

    public:

        class iter
        {
        private:
            Node *curr_value;

        public:
            iter(Node* ptr = nullptr) : curr_value(ptr){}

            iter &operator++()
            {
                return *this;
            }
            iter* operator->()
            {
                return this;
            }
            const string operator*() const
            {
                if (this->curr_value == nullptr) {
                    return "";
                }
                return curr_value->get_name();
            }
            bool operator!=(const iter &other) const
            {
                return false;
            }
            bool operator==(const iter &other)const
            {
                return true;
            }
            int size(){
                return 1;
            }
        };

        OrgChart &add_root(const std::string &root);
        OrgChart &add_sub(const std::string &parent, const std::string &child);

        iter begin_level_order();
        iter end_level_order();

        iter begin_reverse_order();
        iter reverse_order();

        iter begin_preorder();
        iter end_preorder();

        iter begin();
        iter end();
        friend std::ostream &operator<<(std::ostream &os, const OrgChart &oc);

        int size();
    };
}