//
// Created by 曾宁 on 2022/10/30.
//

// twofile1.cpp -- variables with external and internal linkage
// to be compiled with twofile2.cpp
#include <iostream>
int tom = 3; // external definition
int dick = 30; // external definition
static int harry = 300; // internal definition

void remote_access();

int main()
{
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
    remote_access();
    return 0;
}
