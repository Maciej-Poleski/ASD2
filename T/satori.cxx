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

template<typename T,class Compare = std::less<T> >
class LeftistTree : public std::tr1::enable_shared_from_this<LeftistTree<T,Compare> >
{
    struct Node
    {
        friend class LeftistTree<T,Compare>;

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

    std::tr1::shared_ptr<LeftistTree<T,Compare> > merge(std::tr1::shared_ptr<LeftistTree<T,Compare> > rhs);
    void deleteMin();
    void insert(const T &value);

private:
    LeftistTree(Node *root) : root(root) {}

    static std::tr1::shared_ptr<LeftistTree<T,Compare> >
    merge(std::tr1::shared_ptr<LeftistTree<T,Compare> > lhs,
          std::tr1::shared_ptr<LeftistTree<T,Compare> > rhs);

private:
    Node *root;
};

template<typename T,class Compare >
std::tr1::shared_ptr<LeftistTree<T,Compare> >
merge(std::tr1::shared_ptr<LeftistTree<T,Compare> > lhs,
      std::tr1::shared_ptr<LeftistTree<T,Compare> > rhs)
{
    return lhs.merge(rhs);
}

template<typename T,class Compare>
void swap(LeftistTree<T,Compare> &lhs,LeftistTree<T,Compare> &rhs)
{
    lhs.swap(rhs);
}

template<typename T,class Compare >
std::tr1::shared_ptr<LeftistTree<T,Compare> >
LeftistTree<T,Compare>::merge(std::tr1::shared_ptr<LeftistTree<T,Compare> > rhs)
{
    using std::swap;
    std::tr1::shared_ptr<LeftistTree<T,Compare> > t = LeftistTree<T,Compare>::merge(this->shared_from_this(),rhs);
    swap(*this,*t);
    return this->shared_from_this();
}

template<typename T,class Compare>
void LeftistTree<T,Compare>::deleteMin()
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
        std::tr1::shared_ptr<LeftistTree<T,Compare> > l(new LeftistTree<T,Compare>(left));
        std::tr1::shared_ptr<LeftistTree<T,Compare> > r(new LeftistTree<T,Compare>(right));
        std::tr1::shared_ptr<LeftistTree<T,Compare> > t(merge(l,r));
        swap(*this,*t);
    }
}

template<typename T,class Compare >
void LeftistTree<T,Compare>::insert(const T& value)
{
    Node *node=new Node;
    node->value=value;
    std::tr1::shared_ptr<LeftistTree<T,Compare> > t(new LeftistTree<T,Compare>(node));
    merge(t);
}

template<typename T,class Compare >
std::tr1::shared_ptr<LeftistTree<T,Compare> >
LeftistTree<T,Compare>::merge(std::tr1::shared_ptr<LeftistTree<T,Compare> > lhs,
                              std::tr1::shared_ptr<LeftistTree<T,Compare> > rhs)
{
    if(lhs==rhs)
        return lhs;
    std::tr1::shared_ptr<LeftistTree<T,Compare> > result(new LeftistTree<T,Compare>(Node::merge(lhs->root,rhs->root)));
    lhs->root=0;
    rhs->root=0;
    return result;
}

template<typename T,class Compare>
typename LeftistTree<T,Compare>::Node* LeftistTree<T,Compare>::Node::merge(Node* a, Node* b)
{
    using std::swap;
    if(a==0)
        return b;
    else if(b==0)
        return a;

    check(a);
    check(b);
    Compare comp;
    if(comp(b->value,a->value))
        swap(a,b);
    a->right=merge(a->right,b);
    if((a->left==0) ||( (a->right!=0) && (a->left->s < a->right->s)))
        swap(a->left,a->right);
    a->s=(a->right?a->right->s:0)+1;
    return a;
}

struct Curve
{
    uint16_t left,right;
    uint16_t id;
    uint8_t color;
    bool onStack;
    std::vector<uint16_t> edges;

    Curve() : color(255),onStack(false) {}
};

static Curve *G;
static size_t n,k;

const bool operator<(const Curve &lhs,const Curve &rhs) __attribute__((pure));
const bool operator<(const Curve &lhs,const Curve &rhs)
{
    return (lhs.left<rhs.left) || ((lhs.left==rhs.left) && (lhs.right>rhs.right));
}

struct CurvePtrComp
{
    const bool operator()(const Curve * const &lhs,const Curve * const &rhs) const
    {
        return lhs->right<rhs->right;
    }
};

static void makeColor(uint16_t k,uint8_t color)
{
    if(G[k].color!=255)
        return;
    G[k].color=color;
    for(std::vector<uint16_t>::const_iterator i=G[k].edges.begin(),e=G[k].edges.end(); i!=e; ++i)
    {
        makeColor(*i,color^1);
    }
}

struct CurveComp
{
    const bool operator()(const Curve &lhs,const Curve &rhs) const
    {
        return lhs.id<rhs.id;
    }
};

struct Event
{
    uint16_t id;
    bool right;
};

const bool operator==(const Event &lhs,const Event &rhs)
{
    return (lhs.id==rhs.id) && (lhs.right==rhs.right);
}

const bool operator<(const Event &lhs,const Event &rhs)
{
    if(lhs==rhs)
        return false;
    uint16_t l=lhs.right?G[lhs.id].right:G[lhs.id].left;
    uint16_t r=rhs.right?G[rhs.id].right:G[rhs.id].left;
    if(l!=r)
        return l<r;
    if(lhs.right!=rhs.right)
        return lhs.right;
    bool c=G[lhs.id]<G[rhs.id];
    if(!lhs.right)
        return c;
    else
        return !c;
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        in>>n>>k;
        G=new Curve[k];

        for(size_t i=0; i<k; ++i)
        {
            uint16_t a,b;
            in>>a>>b;
            G[i].left=a;
            G[i].right=b;
            G[i].id=i;
        }
        std::sort(G,G+k);
        typedef std::tr1::shared_ptr<LeftistTree<Curve*,CurvePtrComp> > TreePtr;
        std::stack<TreePtr> stack;
        for(size_t i=0; i<k; ++i)
        {
            while(!stack.empty())
            {
                TreePtr tree=stack.top();
                while(!tree->isEmpty())
                {
                    if(tree->getMin()->right<=G[i].left)
                        tree->deleteMin();
                    else
                        break;
                }
                if(tree->isEmpty())
                    stack.pop();
                else
                    break;
            }
            TreePtr newConnectedComponent(new LeftistTree<Curve*,CurvePtrComp>());
            newConnectedComponent->insert(&G[i]);
            while(!stack.empty())
            {
                TreePtr tree=stack.top();
                if(tree->getMin()->right<G[i].right)
                {
                    G[i].edges.push_back(tree->getMin()-G);
                    G[tree->getMin()-G].edges.push_back(i);
                    newConnectedComponent->merge(tree);
                    stack.pop();
                }
                else
                    break;
            }
            stack.push(newConnectedComponent);
        }
        for(size_t i=0; i<k; ++i)
            makeColor(i,0);
        std::vector<Event> events[2];
        for(size_t i=0; i<k; ++i)
        {
            check(G[i].color==0 || G[i].color==1);
            events[G[i].color].push_back({i,false});
            events[G[i].color].push_back({i,true});
        }
        std::sort(events[0].begin(),events[0].end());
        std::sort(events[1].begin(),events[1].end());
        bool ok=true;
        for(size_t q=0; q<2 && ok; ++q)
        {
            std::stack<uint16_t> stack;
            for(std::vector<Event>::const_iterator i=events[q].begin(),e=events[q].end(); i!=e && ok; ++i)
            {
                if(G[i->id].onStack)
                {
                    if(stack.top()==i->id)
                    {
                        stack.pop();
                    }
                    else
                    {
                        ok=false;
                    }
                }
                else
                {
                    stack.push(i->id);
                    G[i->id].onStack=true;
                }
            }
        }
        std::sort(G,G+k,CurveComp());
        if(ok)
            for(size_t i=0; i<k; ++i)
            {
                out<<(G[i].color==0?"N\n":"S\n");
            }
        else
            out<<"NIE\n";
        delete [] G;
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





