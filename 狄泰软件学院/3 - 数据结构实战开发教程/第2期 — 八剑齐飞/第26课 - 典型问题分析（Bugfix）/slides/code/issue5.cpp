#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "LinkList.h"

namespace DTLib
{

template< typename T, int N >
class StaticLinkList : public LinkList<T>
{
protected:
    // ... ...
    
public:
    StaticLinkList()
    {
        for(int i=0; i<N; i++)
        {
            m_used[i] = 0;
        }
    }

    int capacity()
    {
        return N;
    }

    ~StaticLinkList()
    {
        this->clear();
    }
};

}

#endif // STATICLINKLIST_H
