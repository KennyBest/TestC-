//
//  Person.cpp
//  TestC++
//
//  Created by llj on 2017/5/5.
//  Copyright © 2017年 llj. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

void Person::study() {
    std::cout << "Person eat and sleep" << std::endl;
}

void Person::write() {
    std::cout << this->m_name << " write some things" << std::endl;
}

Person::Person () {
    m_name = "";
    m_age = 0;
    m_address = "";
}

//Person::Person(std::string name, int age, std::string address) {
//    m_name = name;
//    m_age = age;
//    m_address = address;
//}

// 参数初始化列表
Person::Person(std::string name, int age, std::string address) : m_name(name), m_age(age), m_address(address) {
   // 作用和👆构造函数一样
}
