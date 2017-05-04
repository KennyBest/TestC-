//
//  main.cpp
//  TestC++
//
//  Created by llj on 2017/4/21.
//  Copyright © 2017年 llj. All rights reserved.
//

#include <iostream>
#include <ctime> // C语言时间处理系统库
using namespace std;

double getAverage(double arr[], int size);

void testMultiplicationTable() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " * " << i << " = " << i * j << '\t';
            if (j == i) {
                cout << '\n';
            }
        }
    }
}

void test1(int a, int b) {
    cout << "a = " << a << "\tb = " << b << endl;
}

bool test2(int a, int b) {
    return a > b;
}

void test3(int *a, int *b) {
    cout << a << '\t' << b << endl;
    cout << *a << '\t' << *b << endl;
    int *tmp = a;
    a = b;
    b = tmp;
    cout << a << '\t' << b << endl;
    cout << *a << '\t' << *b << endl;
}

#pragma mark - 数组

void testArray() {
    double balance[5] = {100.0, 2.0, 3.0, 17.0, 50.0};
     balance[3] = 51.4;
    
    // 二维数组
    int a[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    
    int b[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << b[3][4] << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "a[" << i << "][" << j << "]\t=\t" << a[i][j] << endl;
        }
    }
    
    // 数组与指针
    string friusts[] = {"apple", "orange"};
    string *p = NULL;
    p = friusts;
    cout << *(friusts + 1) << endl;

    
    // 数组
    cout << getAverage(balance, 5) << endl;
}

double getAverage(double arr[], int size) {
    int sum = 0;
    double avg;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    avg = double(sum) / size;
    return avg;
}

void testPointer() {
    int a = 3;
    int *p = NULL;
    cout << "NULL address is : " << p << endl;
    p = &a;
    int b = *p;
    
    cout << b << endl;
    
    // 指针是变量 存储的是内存地址
    
    //0 1 2 3 4 5 6 7 8 9 A B C D E F
    // 指针的递增 是当前地址往后移动指针类型所占字节数位， 递减则向前移动
    
    int arr[3] = {10, 100, 1000};
    int *p1 = arr;
    for (int i = 0; i < 3; i++) {
        cout << *p1 << endl;
        cout << p1 << endl;
        
        p1++;
        cout << *p1 << endl;
    }
    
    // 指针跟数组
    // 数组名是数组第一个元素的内存地址，是一个指向该数组类型的指针 数组名不能有算法操作，它是一个固定值
    // 指针数组  数组里面放的是指针
    // 指向指针的指针 间接获取变量值
}

void swap(int& a, int& b);

#pragma mark - 测试引用

void testQuote() {
    int a = 5;
    int b = 3;
    
    swap(a, b);
    
    cout << a << "-----" << b << endl;
}

// 引用作为函数参数
// 引用作为返回类型 -- 返回的是指向这个类型的隐式指针
void swap(int& a, int& b)
{
    int tmp = a;
    
    a = b;
    b = tmp;
}


#pragma mark - 时间

// C++标准库里面没有提供时间处理函数，沿用C语言里面处理函数.

void testHandleTime() {
    
    // 系统的当前日历时间距1970.1.1的秒数  这里time_t就是long数据类型
    time_t currentTime = time(0);
    
    // 将时间转化为字符串形式
    char *dt = ctime(&currentTime);
    
    cout << "system current time:" << dt << endl;
    
    // 将time_t形式转为tm结构
    // 返回UTC时间
    tm *gmtm = gmtime(&currentTime);
    // 返回本地时间
    gmtm = localtime(&currentTime);
    // 返回一个指向time的指针
    dt = asctime(gmtm);
    
//    struct tm {
//    int	tm_sec;		/* seconds after the minute [0-60] */
//    int	tm_min;		/* minutes after the hour [0-59] */
//    int	tm_hour;	/* hours since midnight [0-23] */
//    int	tm_mday;	/* day of the month [1-31] */
//    int	tm_mon;		/* months since January [0-11] */
//    int	tm_year;	/* years since 1900 */
//    int	tm_wday;	/* days since Sunday [0-6] */
//    int	tm_yday;	/* days since January 1 [0-365] */
//    int	tm_isdst;	/* Daylight Savings Time flag */
//    long	tm_gmtoff;	/* offset from CUT in seconds */
//    char	*tm_zone;	/* timezone abbreviation */
//    };

    
    cout << "UTC data&&time is " << dt << endl;
    
    cout << "year : " << gmtm->tm_year + 1900
            << " month : " << gmtm->tm_mon + 1
            << " hour : " << gmtm->tm_hour
            << "timeZone : " << gmtm->tm_zone << '\n'
            << "wday : " << gmtm->tm_wday << '\n'
            << "yday : " << gmtm->tm_yday << '\n'
    << endl;
    
}


#pragma mark - Struct

void testStruct() {
    
    struct Person {
        char name[30];
        int age;
        char address[100];
    } person1;

    strcpy(person1.name, "xiaohong");
    cout << person1.name << endl;
    
    
    typedef struct {
        char name[20];
    } Book;
    Book book = Book();
    strcpy(book.name, "math");
    // 指向结构的指针
    Book *p = &book;
    // 指向结构体的指针必须使用->来获取成员变量
    cout << "Test name : " << p->name << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << "This is some test code." << endl;
    
//    test1(5, 6);
//    
//    cout << test2(5, 6) << endl;
//    
//    int a = 4;
//    int *p1 = &a;
//    int b = 5;
//    int *p2 = &b;
//
//
//    test3(p1, p2);
//    cout << "p1 -> " << *p1 << "\t p2 -> " << *p2 << endl;
//    
//    testPointer();
//
//    int c;
//    cout << "Please input one number" << endl;
//    cin >> c;
//    cout << c << endl;
    
//    testArray();
    
//    testQuote();
    
//    testHandleTime();
    
    testStruct();
    return 0;
}



