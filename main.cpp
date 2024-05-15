// virtual Function.cpp : 定义控制台应用程序的入口点。
#include <iostream>
using namespace std;
class IHello
{
public:
    virtual void hello1() = 0;
    virtual void hello2() = 0;
};
class IWorld
{
public:
    virtual void world1() = 0;
    virtual void world2() = 0;
};
class HelloWorld: public IHello,public IWorld
{
public:
    void hello1();
    void hello2();
    void world1();
    void world2();
};
void HelloWorld::hello1()
{
    cout<<"hello1!"<<endl;
}
void HelloWorld::hello2()
{
    cout<<"hello2!"<<endl;
}
void HelloWorld::world1()
{
    cout<<"world1!"<<endl;
}
void HelloWorld::world2()
{
    cout<<"world2!"<<endl;
}
//int main(int argc, char** argv)
//{
//    IHello* pIHello = new HelloWorld;
//    IWorld* pIWorld = (IWorld*)(void*)pIHello;
//    cout<<"********************First test********************"<<endl;
//    pIWorld->world1();
//    pIWorld->world2();
//
//    cout<<"********************Second test********************"<<endl;
//    pIWorld = new HelloWorld;
//    pIWorld->world1();
//    pIWorld->world2();
//
//
//    return 0;
//}

#include <vector>
#include <fmt/ranges.h>

int main() {
    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);
}
