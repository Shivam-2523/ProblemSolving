
/**********************************String Palindrome*********************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "12321";
    int l = 0;
    int r = s.length()-1;
    
    while (r>l)
    {
        if (s[l] == s[r])
            {l++; r--;}
        else
        {
            cout<<"False";
            return 0;;
        }
        
    }
    cout<<"True";
    return 0;
}

/**********************************Reverse an integer and Check Palindrome*********************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a  = 124;
    int reverse = 0;
    int temp =0;
    
    while (a > 0)
    {
        temp = a%10;
        a/=10;
        reverse = reverse * 10 + temp;
    }
 
    cout<<reverse<<endl;
    
    if (reverse = a)
        cout<<"Palindrome";
    else
        cout<<"Not a Palindrome";
    
    return 0;
}

/**********************************Check Prime*********************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a  = 14;
    
    if (a < 2)
        cout<<"Not a Prime";
        
    for (int i = 2; i<a/2; i++)
    {
        if (a%i == 0)
        {
            cout<<"Not a Prime";
            return 0;
        }
            
    }
    cout<<"Is Prime";
    
    return 0;
}

/*************************C++ program to illustrate the dynamic_cast************************************/
#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    virtual void speak() const
    {
        cout << "Animal speaks." << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void speak() const override
    {
        cout << "Dog barks." << endl;
    }
};

// Derived Class
class Cat : public Animal {
public:
    void speak() const override
    {
        cout << "Cat meows." << endl;
    }
};

int main()
{
    // base class pointer to derived class object
    Animal* animalPtr = new Dog();

    // downcasting
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    // checking if the typecasting is successfull
    if (dogPtr) {
        dogPtr->speak();
    }
    else {
        cout << "Failed to cast to Dog." << endl;
    }

    // typecasting to other dervied class
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
    if (catPtr) {
        catPtr->speak();
    }
    else {
        cout << "Failed to cast to Cat." << endl;
    }

    delete animalPtr;
    return 0;
}
/*****************************Use of copy constructor********************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Test 
{
    public:
        char * a;
        
        Test(): a(nullptr) {}
        Test(const char * b) 
        {
            int size = strlen (b);
            a = new char[size+1];
            strcpy(a,b);
        }
        void change (const char * b)
        {
            strcpy(a,b);
        }
        Test (const Test & obj) 
        {
            int size = strlen (obj.a);
            a = new char[size+1];
            strcpy(a,obj.a);
        }

    
};

int main()
{
    Test t1 ("Shivam");
    Test t2 = t1;
    
    cout<<t1.a<<" "<<t2.a;
    
    t1.change ("Simran");
    
    cout<<t1.a<<" "<<t2.a;

    return 0;
}
/********************Functor and Function Pointer*****************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Test 
{
    public:
        int a;
        
        Test (int b) : a(b) {}
        int operator() (int b) {return a+b;}
        
        
};

void print (int a) {cout<<a;}
int main()
{
    Test t (6);
    cout<<t(9)<<endl;
    void (*ptr) (int) = print;
    ptr(2);
    

    return 0;
}

/**************************Templates & Templates Specialization***********************************/
#include <iostream>
using namespace std;
 
template <typename t>
t print (t a)
{
    return a;
}

template <>
int print (int a)
{
    cout<<"Int";
    return a;
}

int main()
{
    cout<<print ('a')<<endl;
    cout<<print(7);
    return 0;
}
/****************************Templates used with classes*********************************/
#include <iostream>
using namespace std;
 
template <typename t>
class Test
{
    public:
        t a;
        t show () {return a;}
};

int main()
{
    Test<int> t;
    cout<<t.show();
    return 0;
}
/******************************Namespace*******************************/
#include <iostream>
using namespace std;
 
namespace a {
    int num = 23;
}
namespace b {
    int num = 25;
}

namespace c {
    int num = 13;
    namespace d {
        int num = 20;
    }
}

namespace e 
{
    using namespace b;
}
int main()
{
    cout<<a::num<<endl; //23
    cout<<c::d::num<<endl; //20
    cout<<e::num; //25
    return 0;
}
/****************************Multithreading***********************8*********************************/
#include <iostream>
#include <thread>
using namespace std;
 
// A dummy function
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "Thread using function"
                " pointer as callable\n";
    }
}
 
// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Thread using function"
                    " object as callable\n";
    }
};
 
// class definition
class Base {
public:
    // non-static member function
    void foo()
    {
        cout << "Thread using non-static member function "
                "as callable"
             << endl;
    }
    // static member function
    static void foo1()
    {
        cout << "Thread using static member function as "
                "callable"
             << endl;
    }
};
 
// Driver code
int main()
{
    cout << "Threads 1 and 2 and 3 "
            "operating independently"
         << endl;
 
    // This thread is launched by using
    // function pointer as callable
    thread th1(foo, 3);
 
    // This thread is launched by using
    // function object as callable
    thread th2(thread_obj(), 3);
 
    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using lambda"
                    " expression as callable\n";
    };
 
    // This thread is launched by using
    // lambda expression as callable
    thread th3(f, 3);
 
    // object of Base Class
    Base b;
   
    thread th4(&Base::foo, &b);
 
    thread th5(&Base::foo1);
 
    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();
 
    // Wait for thread t2 to finish
    th2.join();
 
    // Wait for thread t3 to finish
    th3.join();
 
    // Wait for thread t4 to finish
    th4.join();
 
    // Wait for thread t5 to finish
    th5.join();
 
    return 0;
}
/************************Smart Pointers*************************************/
#include <iostream>
using namespace std;
// Dynamic Memory management library
#include <memory>
 
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area() { return length * breadth; }
};
 
int main()
{
    cout<<"unique_ptr"<<endl;
    unique_ptr<Rectangle> P1(new Rectangle (10,5));
    cout<<P1->area()<<endl;
    unique_ptr<Rectangle> P2;
    P2 = move (P1);
    cout<<P2->area()<<endl;
    
    cout<<"shared_ptr"<<endl;
    shared_ptr<Rectangle> P3(new Rectangle (11,5));
    shared_ptr<Rectangle> P4;
    P4 = P3;
    cout<<P3->area()<<endl;
    cout<<P4->area()<<endl;
    cout<<P3.use_count()<<endl; //2
    
    cout<<"weak_ptr"<<endl;
    shared_ptr<Rectangle> P5(new Rectangle (12,5));
    weak_ptr<Rectangle> P6 (P5);
    cout<<P5->area()<<endl;
    cout<<P5.use_count()<<endl;
    
    return 0;
}
/****************************2D Vector Traversal*********************************/
vector<vector<int> > vvi;

//assuming you have a "2D" vector vvi (vector of vector of int's)
vector< vector<int> >::iterator row;
vector<int>::iterator col;
for (row = vvi.begin(); row != vvi.end(); row++) {
    for (col = row->begin(); col != row->end(); col++) {
        // do stuff ...
    }
}
/********************Linked List Implementation*****************************************/
#include <bits/stdc++.h>

using namespace std;

class LinkedlIst
{   
    public:
    int data;
    LinkedlIst * next;
    
    
        
        LinkedlIst() : data(0), next(nullptr) {}
        LinkedlIst (int d) : data(d), next (nullptr) {}
        LinkedlIst * Insert (LinkedlIst * head, int d)
        {
            if (head == nullptr)
            {
                head = new LinkedlIst (d);
                return head;
            } else
            {
                LinkedlIst * temp = new LinkedlIst(d);
                temp->next = head;
                head = temp;
            }
            return head;
        }
    
};

int main()
{
    LinkedlIst l;
    LinkedlIst * head;
    head = l.Insert (head, 2);
    head = l.Insert (head, 3);
    head = l.Insert (head, 4);
    
    while (head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}
/***************************Binary Search**********************************/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
 
// Driver code
int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
/***************************Operator Overloading**********************************/

#include <bits/stdc++.h>
using namespace std;

class Test
{
    public: 
    int a;
    Test (int b): a (b) {}
    Test operator+ (const Test & obj)
    {
        Test obj2(0);
        obj2.a = a + obj.a;
        return obj2;
    }
    void operator-()
    {
        a++;
    }
};

int main()
{
    Test obj (8);
    Test obj1 (9);
    Test obj3 = obj1 +obj;
    cout<<obj3.a<<endl;
    -obj3;
    cout<<obj3.a;


    return 0;
}
/**************************nth salary SQL***********************************/
Select emp_sal from Emp order by emp_sal DESC limit 3,1;
/*******************************2D Array using Pointer******************************/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int row = 2;
    int col = 3;
    
    int ** array = new int * [col];
    
    for(int i = 0; i< col; i++)
        array[i] = new int [row];
        
    for(int i = 0; i< row; i++)
        for(int j = 0; j< col; j++)
            array[i][j] = 1;
    
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col; j++){
            cout<<array[i][j];
        }
        cout<<endl;
    }
            
    
	return 0;
}

/****************************enum and unions*********************************/
#include <bits/stdc++.h>

using namespace std;

union a 
{
    int b;
    char c;
} var;

enum day
{
    sun = 9,
    mon = 13
};
int main()
{
    cout <<var.b<<endl;
    var.b = 8;
    cout<<var.c<<endl;

    cout<<sizeof(day)<<endl;
    
    enum day v = mon;
    cout<<v;
}
/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/