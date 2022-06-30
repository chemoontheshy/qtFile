#ifndef VSINGLETON_H
#define VSINGLETON_H
#include <iostream>

namespace hskj
{

    namespace tool
    {
        template <typename T>
        class Singleton
        {
        public:
            //删除默认的移动、拷贝、赋值、取值
            Singleton(T &&)             = delete;
            Singleton(const T &)        = delete ;
            void operator = (const T &) = delete ;
            T *operator &()             = delete ;
            //获取实例
            static T* instance()
            {
                static T object;
                return  &object;
            }
        private:
            //默认构造函数和默认析构函数
            Singleton()  = default;
            ~Singleton() = default;
        };

        ///测试用
        class Print
        {
        public:
            ~Print() = default;
            void puPrint()
            {
                std::cout<<m_sWord<<std::endl;
            }
            void setPrint(const std::string& word)
            {
                m_sWord = word;
            }
        private:
            std::string m_sWord = "word";
        };


    }
}

#endif // VSINGLETON_H
