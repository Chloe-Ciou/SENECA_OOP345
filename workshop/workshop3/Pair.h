#ifndef PAIR_H
#define PAIR_H

template<typename A, typename B>
class Pair{
    A m_a;
    B m_b;
public:
    Pair(){}
    Pair(const A& a, const B& b){
        m_a = a;
        m_b = b;
    }
    const A& getKey() const{
        return m_a ;
    }
    const B& getValue() const{
        return m_b;
    }
};

#endif
