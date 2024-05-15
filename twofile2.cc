// twofile2.cpp -- variables with internal and external linkage
#include <iostream>
extern int tom; // external declaration; tom defined in twofile1.cpp
static int dick = 10; // internal definition; overrides external dick in twofile1.cpp
int harry; // external definition; no conflict with twofile1.cpp's internal harry

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
}
//
// Created by 曾宁 on 2022/10/30.
//
