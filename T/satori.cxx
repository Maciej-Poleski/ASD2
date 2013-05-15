//Maciej Poleski
#ifdef DEBUG
#define _GLIBCXX_CONCEPT_CHECKS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
namespace
{
namespace Wrapper
{
std::ifstream in;
std::ofstream out;
}
void init(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Potrzeba dokładnie dwóch argumentów\n";
        std::abort();
    }
    Wrapper::in.open(argv[1]);
    Wrapper::out.open(argv[2]);
}
}
#define check(x) assert(x)
#else
#ifndef NDEBUG
#define NDEBUG
#endif
#define check(x)
#include <iostream>
namespace
{
namespace Wrapper
{
std::istream &in = std::cin;
std::ostream &out = std::cout;
}
}
#endif

#include <tr1/cstdint>

namespace
{
namespace Wrapper
{
typedef std::tr1::uint_fast64_t uint_fast64_t;
typedef std::tr1::uint_fast32_t uint_fast32_t;
typedef std::tr1::uint_fast16_t uint_fast16_t;
typedef std::tr1::uint_fast8_t uint_fast8_t;

typedef std::tr1::uint64_t uint64_t;
typedef std::tr1::uint32_t uint32_t;
typedef std::tr1::uint16_t uint16_t;
typedef std::tr1::uint8_t uint8_t;

typedef std::tr1::int_fast64_t int_fast64_t;
typedef std::tr1::int_fast32_t int_fast32_t;
typedef std::tr1::int_fast16_t int_fast16_t;
typedef std::tr1::int_fast8_t int_fast8_t;

typedef std::tr1::int64_t int64_t;
typedef std::tr1::int32_t int32_t;
typedef std::tr1::int16_t int16_t;
typedef std::tr1::int8_t int8_t;

typedef std::size_t size_t;
}

}

#include <string>
#include <algorithm>
#include <limits>
#include <locale>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <tr1/random>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <tr1/memory>
#include <tr1/functional>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <complex>

namespace
{
using namespace Wrapper;

template<typename T>
class LeftistTree : public std::tr1::enable_shared_from_this<LeftistTree<T> >
{
    struct Node
    {
        friend class LeftistTree<T>;

    private:
        Node() : left(0), right(0),s(1) {}
        Node(const T &value) : left(0), right(0),s(1),value(value) {}

        Node(const Node &) = delete;
        Node & operator=(const Node &) = delete;

        ~Node()
        {
            delete left;
            delete right;
        }

        static Node * merge(Node *a,Node *b);

    private:
        Node *left,*right;
        size_t s;
        T value;
    };

public:
    LeftistTree() : root(0) {}
    ~LeftistTree()
    {
        delete root;
    }
    LeftistTree(const LeftistTree&) = delete;
    LeftistTree & operator=(const LeftistTree&)=delete;

    bool isEmpty() const
    {
        return root==0;
    }

    T getMin() const
    {
        return root->value;
    }

    void swap(LeftistTree &v)
    {
        Node *t=root;
        root=v.root;
        v.root=t;
    }

    std::tr1::shared_ptr<LeftistTree<T> > merge(std::tr1::shared_ptr<LeftistTree<T> > rhs);
    void deleteMin();
    void insert(const T &value);

private:
    LeftistTree(Node *root) : root(root) {}

    static std::tr1::shared_ptr<LeftistTree<T> >
    merge(std::tr1::shared_ptr<LeftistTree<T> > lhs,
          std::tr1::shared_ptr<LeftistTree<T> > rhs);

private:
    Node *root;
};

template<typename T>
std::tr1::shared_ptr<LeftistTree<T> >
merge(std::tr1::shared_ptr<LeftistTree<T> > lhs,
      std::tr1::shared_ptr<LeftistTree<T> > rhs)
{
    return lhs.merge(rhs);
}

template<typename T>
void swap(LeftistTree<T> &lhs,LeftistTree<T> &rhs)
{
    lhs.swap(rhs);
}

template<typename T>
std::tr1::shared_ptr<LeftistTree<T> >
LeftistTree<T>::merge(std::tr1::shared_ptr<LeftistTree<T> > rhs)
{
    using std::swap;
    std::tr1::shared_ptr<LeftistTree<T> > t = LeftistTree<T>::merge(this->shared_from_this(),rhs);
    swap(*this,*t);
    return this->shared_from_this();
}

template<typename T>
void LeftistTree<T>::deleteMin()
{
    check(root);
    Node *left=root->left;
    Node *right=root->right;
    root->left=0;
    root->right=0;
    delete root;
    root=0;
    if(left==0)
        root=right;
    else if(right==0)
        root=left;
    else
    {
        using std::swap;
        std::tr1::shared_ptr<LeftistTree<T> > l(new LeftistTree<T>(left));
        std::tr1::shared_ptr<LeftistTree<T> > r(new LeftistTree<T>(right));
        std::tr1::shared_ptr<LeftistTree<T> > t(merge(l,r));
        swap(*this,*t);
    }
}

template<typename T>
void LeftistTree<T>::insert(const T& value)
{
    Node *node=new Node;
    node->value=value;
    std::tr1::shared_ptr<LeftistTree<T> > t(new LeftistTree<T>(node));
    merge(t);
}

template<typename T>
std::tr1::shared_ptr<LeftistTree<T> >
LeftistTree<T>::merge(std::tr1::shared_ptr<LeftistTree<T> > lhs,
                      std::tr1::shared_ptr<LeftistTree<T> > rhs)
{
    if(lhs==rhs)
        return lhs;
    std::tr1::shared_ptr<LeftistTree<T> > result(new LeftistTree<T>(Node::merge(lhs->root,rhs->root)));
    lhs->root=0;
    rhs->root=0;
    return result;
}

template<typename T>
typename LeftistTree<T>::Node* LeftistTree<T>::Node::merge(Node* a, Node* b)
{
    using std::swap;
    if(a==0)
        return b;
    else if(b==0)
        return a;

    check(a);
    check(b);
    if((a->value)>(b->value))
        swap(a,b);
    a->right=merge(a->right,b);
    if((a->left==0) ||( (a->right!=0) && (a->left->s < a->right->s)))
        swap(a->left,a->right);
    a->s=(a->right?a->right->s:0)+1;
    return a;
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        size_t n,m;
        in>>n>>m;
        std::tr1::shared_ptr<LeftistTree< uint32_t> > *trees=new std::tr1::shared_ptr<LeftistTree<uint32_t> >[n];
        for(size_t i=0;i<n;++i)
            trees[i].reset(new LeftistTree<uint32_t>);
        while(m--)
        {
            std::string command;
            in>>command;
            if(command[0]=='i')
            {
                //insert
                size_t k;
                uint32_t e;
                in>>k>>e;
                trees[k]->insert(e);
            }
            else if(command[0]=='m')
            {
                // move
                size_t s,t;
                in>>s>>t;
                trees[t]->merge(trees[s]);
            }
            else if(command[0]=='d')
            {
                // delmin
                size_t k;
                in>>k;
                if(!trees[k]->isEmpty())
                {
                    trees[k]->deleteMin();
                }
            }
            else
            {
                check(command[0]=='g');
                // getmin
                size_t k;
                in>>k;
                if(!trees[k]->isEmpty())
                {
                    out<<trees[k]->getMin()<<' ';
                }
                else
                {
                    out<<"-1 ";
                }
            }
        }
        out<<'\n';
        delete [] trees;
    }
}

} // namespace

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
#ifdef DEBUG
    init(argc, argv);
#else
    (void)argc;
    (void)argv;
#endif
    solution();
    return 0;
}





