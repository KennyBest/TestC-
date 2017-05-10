//
//  Person.hpp
//  TestC++
//
//  Created by llj on 2017/5/5.
//  Copyright © 2017年 llj. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Person {
    
public:
    std::string m_name;
    int m_age;
    std::string m_address;
    
    void study(void);
    void write();
    
    Person();
    Person(std::string name, int age, std::string address);
};

#endif /* Person_hpp */

/**
 构造函数具有强制性，一旦定义了就必须调用。
 系统会自动生成一个无参的构造函数。
 一旦用户自定义了，不管几个，系统都不再自动生成。
 调用无参的构造函数可以省略括号。
 构造函数是否同一个也是看参数类型和参数个数。
 
 成员变量的赋值顺序由它们在类中的声明顺序决定的。
 参数初始化表另一个作用就是初始化const成员变量。
 
 ----
 析构函数
 */

/**
 static 静态成员变量 只能在类外部定义，只有在初始化时才分配内存。没有初始化就不能使用。
 1. 不同对象可以调用同一个静态成员变量
 2. 静态成员变量在全局数据区分配内存，知道程序结束时才释放
 3. 静态成员变量必须初始化，并且只能在类外声明
 4. 静态成员变量既能通过对象调用，也能通过类名调用
 
 静态成员函数
 1. 只能访问静态成员变量
 2. 函数内部不能使用this指针

 */

/**
 *  cosnt 修饰成员变量、函数、类
 1. const 限定函数时是在函数声明、定义时末尾加上const关键字
 */

/**
 friend 友元函数 友元类
 1. 友元函数不能使用this指针， 必须通过传递对象指针来获取对象的成员变量
 友元类中所有的成员函数都是友元函数
 */

/**
 struct里面的成员都是public，class默认是private
 class继承是private继承， struct是public继承
 class可以使用模板，struct不能使用
 */

/***  引用
 *     
    引用 -- 就是使用被引用的数据
    类型 &变量名 = 被引用的变量名  (定义时初始化，并且初始化之后不可再更改，在使用时不需要带&。)
 
 */

