//Maciej Poleski
#ifdef DEBUG
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
void init(int argc, char** argv)
{
    if(argc != 3)
    {
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
std::istream& in = std::cin;
std::ostream& out = std::cout;
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

namespace
{
using namespace Wrapper;

class State;

struct Edge
{
    State *dest;
    char c;
};

class NFA;

typedef std::tr1::shared_ptr<NFA> NFAPtr;

class NFA
{
public:
    NFA(const NFA&) = delete;
    NFA & operator=(const NFA&) = delete;
    ~NFA();

    State *newState(bool start=false,bool terminal=false);

    std::size_t getAllStatesCount() const;
    void transferStates(NFAPtr from);

    bool isTerminal(State *state);
    const std::vector<State*>& getStartStates() const;

    static NFAPtr acceptChar(char c);
    static NFAPtr acceptDot();
    static NFAPtr acceptCat(NFAPtr A, NFAPtr B);
    static NFAPtr acceptAlt(NFAPtr A, NFAPtr B);
    static NFAPtr acceptStar(NFAPtr A);
    static NFAPtr acceptEmpty();          // akceptuje pusty napis

private:
    NFA() {}    // to nie ma sensu w API
    static NFAPtr createEmpty();

private:
    std::list<State*> allStates;        // Ułatwia dealokacje
    std::vector<State*> startStates;
    std::vector<State*> terminalStates;
    static const NFAPtr emptyNFA;
};

const NFAPtr NFA::emptyNFA=NFA::createEmpty();

class State
{
    friend State *NFA::newState(bool start,bool terminal);

public:
    std::vector<Edge> edges;

public:

private:
    State() {}
};

NFA::~NFA()
{
    for(std::list<State*>::iterator i=allStates.begin(),e=allStates.end(); i!=e; ++i)
    {
        delete *i;
    }
}

State* NFA::newState(bool start, bool terminal)
{
    State *result=new State();
    allStates.push_back(result);
    if(start)
        startStates.push_back(result);
    if(terminal)
        terminalStates.push_back(result);
    return result;
}

NFAPtr NFA::acceptChar(char c)
{
    NFAPtr result(new NFA);
    State *start=result->newState(true,false);
    State *terminal=result->newState(false,true);
    start->edges.push_back( {terminal,c});
    return result;
}

NFAPtr NFA::acceptDot()
{
    NFAPtr result(new NFA);
    State *start=result->newState(true,false);
    State *terminal=result->newState(false,true);
    start->edges.push_back( {terminal,'a'});
    start->edges.push_back( {terminal,'b'});
    return result;
}

void NFA::transferStates(NFAPtr from)
{
    check(this!=from.get());
    allStates.splice(allStates.end(),from->allStates);
}

NFAPtr NFA::acceptCat(NFAPtr A, NFAPtr B)
{
    if(A==emptyNFA)
        return B;
    else if(B==emptyNFA)
        return A;
    NFAPtr result(new NFA);
    result->transferStates(A);
    result->transferStates(B);
    result->startStates=A->startStates;
    result->terminalStates=B->terminalStates;
    for(std::vector<State*>::iterator i=A->terminalStates.begin(),e=A->terminalStates.end(); i!=e; ++i)
    {
        for(std::vector<State*>::iterator j=B->startStates.begin(),ee=B->startStates.end(); j!=ee; ++j)
        {
            (*i)->edges.push_back( {*j,'\0'});
        }
    }
    return result;
}

NFAPtr NFA::acceptAlt(NFAPtr A, NFAPtr B)
{
    if(A==emptyNFA)
        A=createEmpty();
    if(B==emptyNFA)
        B=createEmpty();
    NFAPtr result(new NFA);
    result->transferStates(A);
    result->transferStates(B);
    State *start=result->newState(true,false);
    State *terminal=result->newState(false,true);
    for(std::vector<State*>::iterator i=A->startStates.begin(),e=A->startStates.end(); i!=e; ++i)
    {
        start->edges.push_back( {*i,'\0'});
    }
    for(std::vector<State*>::iterator i=B->startStates.begin(),e=B->startStates.end(); i!=e; ++i)
    {
        start->edges.push_back( {*i,'\0'});
    }
    for(std::vector<State*>::iterator i=A->terminalStates.begin(),e=A->terminalStates.end(); i!=e; ++i)
    {
        (*i)->edges.push_back( {terminal,'\0'});
    }
    for(std::vector<State*>::iterator i=B->terminalStates.begin(),e=B->terminalStates.end(); i!=e; ++i)
    {
        (*i)->edges.push_back( {terminal,'\0'});
    }
    return result;
}

NFAPtr NFA::acceptStar(NFAPtr A)
{
    if(A==emptyNFA)
        return A;
    NFAPtr result(new NFA);
    result->transferStates(A);
    State *aux=result->newState(true,true);
    for(std::vector<State*>::iterator i=A->terminalStates.begin(),e=A->terminalStates.end(); i!=e; ++i)
    {
        (*i)->edges.push_back( {aux,'\0'});
    }
    for(std::vector<State*>::iterator i=A->startStates.begin(),e=A->startStates.end(); i!=e; ++i)
    {
        aux->edges.push_back( {*i,'\0'});
    }
    return result;
    //     NFAPtr result(new NFA);
    //     result->transferStates(A);
    //     State *start=result->newState(true,false);
    //     State *terminal=result->newState(false,true);
    //     start->edges.push_back( {terminal,'\0'});
    //     for(std::vector<State*>::iterator i=A->terminalStates.begin(),e=A->terminalStates.end(); i!=e; ++i)
    //     {
    //         (*i)->edges.push_back( {terminal,'\0'});
    //     }
    //     for(std::vector<State*>::iterator i=A->startStates.begin(),e=A->startStates.end(); i!=e; ++i)
    //     {
    //         start->edges.push_back( {*i,'\0'});
    //         terminal->edges.push_back( {*i,'\0'});
    //     }
    return result;
}

NFAPtr NFA::createEmpty()
{
    NFAPtr result(new NFA);
    result->newState(true,true);
    return result;
}

NFAPtr NFA::acceptEmpty()
{
    return emptyNFA;
}

bool NFA::isTerminal(State* state)
{
    return std::find(terminalStates.begin(),terminalStates.end(),state)!=terminalStates.end();
}

const std::vector< State* >& NFA::getStartStates() const
{
    return startStates;
}

static NFAPtr parseRegex()
{
    NFAPtr result=NFA::acceptStar(NFA::acceptDot());
    NFAPtr lastPart=NFA::acceptEmpty();
    for(;;)
    {
        char c=in.get();
        if(c==')' || std::isspace(c))
            break;
        else if(c=='(')
        {
            result=NFA::acceptCat(result,lastPart);
            lastPart=parseRegex();
        }
        else if(c=='*')
        {
            lastPart=NFA::acceptStar(lastPart);
        }
        else if(c=='a' || c=='b')
        {
            result=NFA::acceptCat(result,lastPart);
            lastPart=NFA::acceptChar(c);
        }
        else if(c=='.')
        {
            result=NFA::acceptCat(result,lastPart);
            lastPart=NFA::acceptDot();
        }
        else
        {
            check(c=='|');
            result=NFA::acceptCat(result,lastPart);
            NFAPtr right=parseRegex();
            return NFA::acceptAlt(result,right);
        }
    }
    return NFA::acceptCat(result,lastPart);
}

struct DetState
{
    uint32_t next[2];
    bool terminal;

    DetState() : terminal(false) {}
    DetState(const DetState &detState) : next {detState.next[0],detState.next[1]}, terminal(detState.terminal) {}

    DetState(uint32_t a,uint32_t b, bool terminal) : next {a,b}, terminal(terminal) {}
};

uint32_t charToIndex(const char c)
{
    return c=='b';
}

std::size_t NFA::getAllStatesCount() const
{
    return allStates.size();
}

static std::size_t getNFASize(NFAPtr nfa)
{
    // można lepiej, ale na razie nie widzę sensu
    return nfa->getAllStatesCount();
}

static void travelByNull(std::tr1::unordered_set<State*> &result, State *state)
{
    result.insert(state);
    for(std::vector<Edge>::const_iterator i=state->edges.begin(),e=state->edges.end(); i!=e; ++i)
    {
        if(i->c=='\0' && result.find(i->dest)==result.end())
            travelByNull(result,i->dest);
    }
}

static void travelByChar(std::tr1::unordered_set<State*> &result, State *state,char c)
{
    for(std::vector<Edge>::const_iterator i=state->edges.begin(),e=state->edges.end(); i!=e; ++i)
    {
        if(i->c==c && result.find(i->dest)==result.end())
            travelByNull(result,i->dest);
    }
}

class DFAMaker
{
public:
    DFAMaker(NFAPtr nfa) : nfa(nfa), NFASize(getNFASize(nfa)),
        nextIntegerFromState(0) {
        check(NFASize<=64); // typ size_t (zastąpić przez std::vector<bool> gdy biblioteka zostanie poprawiona)
    }

    void makeDFA();
    bool isAccepted(const std::string &line);

private:
    size_t integerFromState(State *state);
    uint32_t detStateFromStateSet(uint64_t stateSet);
    uint64_t stateSetFromStateSet(const std::tr1::unordered_set<State*> &set);

private:
    const NFAPtr nfa;
    const std::size_t NFASize;
    std::tr1::unordered_map<State*,size_t> stateToInteger;
    std::size_t nextIntegerFromState;
    std::vector<State*> stateByInteger;
    std::tr1::unordered_map<uint64_t,uint32_t> stateSetToDetState;
    // Wygląda na to, że w kompilatorze jest błąd. push_back na takim wektorze
    // składającym się z rzeczywistych obiektów powoduje dealokacje pamięci.
    // Jako obejście przechowuję w wektorze wskaźnik na rzeczywisty obiekt
    // GCC 4.7.2 (i satori) - nie działa
    // Clang 3.2 - działa
    std::vector<std::tr1::shared_ptr<DetState> > DFA;
};

void DFAMaker::makeDFA()
{
    std::stack<uint64_t> detStatesToFollow;
    uint64_t t=0;
    {
        const std::vector<State*> &startStates=nfa->getStartStates();
        std::tr1::unordered_set<State*> set;
        for(std::vector<State*>::const_iterator i=startStates.begin(),e=startStates.end(); i!=e; ++i)
        {
            travelByNull(set,*i);
        }
        t|=stateSetFromStateSet(set);
    }
    detStatesToFollow.push(t);
    std::tr1::unordered_set<uint64_t> stateSetEnqueued;
    stateSetEnqueued.insert(t);
    while(!detStatesToFollow.empty())
    {
        uint64_t stateSet=detStatesToFollow.top();
        detStatesToFollow.pop();
        uint32_t detState=detStateFromStateSet(stateSet);

        // a
        {
            std::tr1::unordered_set<State*> set;
            for(size_t i=0; i<NFASize; ++i)
            {
                if((1UL<<i) & stateSet)
                {
                    travelByChar(set,stateByInteger[i],'a');
                }
            }
            uint64_t a=stateSetFromStateSet(set);
            if(stateSetEnqueued.find(a)==stateSetEnqueued.end())
            {
                detStatesToFollow.push(a);
                stateSetEnqueued.insert(a);
            }
            DFA[detState]->next[charToIndex('a')]=detStateFromStateSet(a);
        }

        // b
        {
            std::tr1::unordered_set<State*> set;
            for(size_t i=0; i<NFASize; ++i)
            {
                if((1UL<<i) & stateSet)
                {
                    travelByChar(set,stateByInteger[i],'b');
                }
            }
            uint64_t b=stateSetFromStateSet(set);
            if(stateSetEnqueued.find(b)==stateSetEnqueued.end())
            {
                detStatesToFollow.push(b);
                stateSetEnqueued.insert(b);
            }
            DFA[detState]->next[charToIndex('b')]=detStateFromStateSet(b);
        }
    }
}

size_t DFAMaker::integerFromState(State* state)
{
    check(stateByInteger.size()==nextIntegerFromState);
    check(nextIntegerFromState<=64);
    if(stateToInteger.find(state)!=stateToInteger.end())
        return stateToInteger[state];
    check(nextIntegerFromState<64);
    stateByInteger.push_back(state);
    return stateToInteger[state]=nextIntegerFromState++;
}

uint32_t DFAMaker::detStateFromStateSet(const uint64_t stateSet)
{
    check(NFASize<=64);
    check(stateByInteger.size()==nextIntegerFromState);
    if(stateSetToDetState.find(stateSet)!=stateSetToDetState.end())
        return stateSetToDetState[stateSet];
    bool terminal=false;
    for(size_t i=0; i<NFASize; ++i)
    {
        if((1UL<<i) & stateSet)
        {
            check(i<nextIntegerFromState);
            if(nfa->isTerminal(stateByInteger[i]))
            {
                terminal=true;
                break;
            }
        }
    }
    std::tr1::shared_ptr<DetState> p(new DetState(0,0,terminal));
    DFA.push_back(p);
    return stateSetToDetState[stateSet]=DFA.size()-1;
}


uint64_t DFAMaker::stateSetFromStateSet(const std::tr1::unordered_set< State* >& set)
{
    uint64_t result=0;
    for(std::tr1::unordered_set< State* >::const_iterator i=set.begin(),e=set.end(); i!=e; ++i)
    {
        result|= (1UL<<integerFromState(*i));
    }
    return result;
}

bool DFAMaker::isAccepted(const std::string &line)
{
    uint32_t state=0;
    for(std::string::const_iterator i=line.begin(),e=line.end(); i!=e; ++i)
    {
        check(*i=='a' || *i=='b');
        state=DFA[state]->next[charToIndex(*i)];
    }
    return DFA[state]->terminal;
}

inline static void solution() __attribute__((optimize(3)));
inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //z=1;
    while(z--)
    {
        DFAMaker m(parseRegex());
        m.makeDFA();
        size_t q;
        in>>q;
        in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        while(q--)
        {
            std::string line;
            std::getline(in,line);
            out<<(m.isAccepted(line)?"TAK\n":"NIE\n");
        }
    }
}

} // namespace

int main(int argc, char** argv)
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
