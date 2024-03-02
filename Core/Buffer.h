#pragma once

#include"Types.h"

#define INIT_BUFFER_RESERVATION 1024

namespace Interface
{
    template<class T>
    class IBufferObject 
    {
        public:
        IBufferObject() {   ClearData();    }

        void PushData(std::vector<T> data) {    m_data.push_back(data); }
        void PushData(T *data, uint count) 
        {    
            for(uint i=0;i<count;++i)
            {
                m_data.push_back(*(data+i));
            }
        }
        void ClearData() {  m_data.clear(); }

        virtual void OffloadData() = 0;
        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        uint m_id;
        uint m_usage;
        std::vector<T> m_data;
    };
}