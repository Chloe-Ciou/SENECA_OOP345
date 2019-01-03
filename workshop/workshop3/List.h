#ifndef LIST_H
#define LIST_H

template<typename T, size_t N>
class List{
    T m_list[N];
    size_t m_num;
    T m_dummy;
public:
    List():m_num(0u){}
    size_t size() const {
        return m_num;
    }
    const T& operator[](int index){
        return index >= 0 && index < N ? m_list[index] : m_dummy;
    }
    T operator[](int index) const{
        return index >= 0 && index < N ? m_list[index] : m_dummy;
    }
    void operator+=(const T& list){
        if(m_num < N)
            m_list[m_num++] = list;
    }
};
#endif /* List_h */
