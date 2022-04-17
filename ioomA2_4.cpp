#include <bits/stdc++.h>
using namespace std;
class linkedlist;
class ComplexInteger
{
    int real;
    int imaginary;
    ComplexInteger *next;
public:
    
    ComplexInteger()
    {
        real = 0;
        imaginary = 0;
        next = NULL;
    }
    ComplexInteger(int a, int b)
    {
        real = a;
        imaginary = b;
        next = NULL;
    }
    ComplexInteger(const ComplexInteger& obj)
    {
        real = obj.real;
        imaginary = obj.imaginary;
        next = obj.next;
    }
    ~ComplexInteger()
    {
        //destructor
    }
    void get_method(void)
    {
        cout<<real<<" + i"<<imaginary<<endl;
    }
    void set_method( int r , int i )
    {
        real = r;
        imaginary = i ;
    }
    friend class linkedlist;
    friend void display(linkedlist &LL);
    friend bool search(linkedlist &, ComplexInteger&);
    friend linkedlist operator+(linkedlist& , linkedlist& );
    friend linkedlist operator+(linkedlist& , ComplexInteger& );
    friend linkedlist operator-(linkedlist& );
    friend linkedlist operator*(linkedlist& , int );
    friend linkedlist operator<<(linkedlist& , int );
    friend linkedlist operator>>(linkedlist& , int );
};
class linkedlist
{
    private:
    ComplexInteger *head;
    public:
    linkedlist()
    {
        head = NULL;
    }
    linkedlist(ComplexInteger* ptr)
    {
        head = ptr;
    }
    linkedlist(const linkedlist &obj)
    {
        head = obj.head;
    }
    ~linkedlist()
    {
        //destructor
    }
    void insert(ComplexInteger ci)
    {
        if(head == NULL) 
        {
            head = new ComplexInteger;
            head->real = ci.real;
            head->imaginary = ci.imaginary;
            head->next = NULL;
        }
        else
        {
            ComplexInteger* temp1 = head , *temp2;
            while(temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp2 = new ComplexInteger;
            temp2->real = ci.real;
            temp2->imaginary = ci.imaginary;
            temp2->next = NULL;
            temp1->next = temp2;
        }
    }
    void operator=(const linkedlist &l2)
    {
        head = l2.head;
    }
    friend void display(linkedlist &LL);
    friend bool search(linkedlist &, ComplexInteger&);
    friend linkedlist operator+(linkedlist& , linkedlist& );
    friend linkedlist operator+(linkedlist& , ComplexInteger& );
    friend linkedlist operator-(linkedlist& );
    friend linkedlist operator*(linkedlist& , int );
    friend linkedlist operator<<(linkedlist& , int );
    friend linkedlist operator>>(linkedlist& , int );
};
void display(linkedlist &LL)
{
    ComplexInteger* ptr = LL.head;
    while(ptr != NULL)
    {
        ptr->get_method();
        ptr = ptr->next;
    }
    cout<<"----------------------------------"<<endl;
}
linkedlist operator+(linkedlist &l1 , linkedlist &l2)
{
    if(l1.head == NULL)
    {
        return l2;
    }
    else
    {
        ComplexInteger* temp1 = l1.head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = l2.head;
        return l1;
    }
}
linkedlist operator+(linkedlist &l1 , ComplexInteger &c1)
{
    if(l1.head == NULL)
    {
        ComplexInteger* temp1 = new ComplexInteger;
        temp1->real = c1.real;
        temp1->imaginary = c1.imaginary;
        temp1->next = NULL;
        l1.head = temp1;
        return l1;
    }
    else
    {
        ComplexInteger* temp2 = new ComplexInteger;
        temp2->real = c1.real;
        temp2->imaginary = c1.imaginary;
        temp2->next = NULL;
        ComplexInteger *temp3 = l1.head;
        while(temp3->next != NULL)
        {
            temp3 = temp3->next;
        }
        temp3->next = temp2;
        return l1;
    }

}
linkedlist operator-(linkedlist &l1)
{
    if(l1.head == NULL)
    {
        cout<<"ERROR"<<endl;
        return l1;
    }
    else
    {
        ComplexInteger* temp1 = l1.head;
        if(temp1->next == NULL)
        {
            l1.head = NULL;
        }
        else
        {
            while((temp1->next)->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = NULL;
        }
        return l1;
    }
}
linkedlist operator*(linkedlist& l1, int n)
{
    ComplexInteger* temp = l1.head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if(n <= count && n > 0)
    {
        int c = 1;
        ComplexInteger *temp2 = l1.head;
        ComplexInteger *temp3;
        if(n == 1)
        {
            temp2 = temp2->next;
            l1.head = temp2;
        }
        else
        {
            while((temp2->next) != NULL)
            {
                c++;
                temp3 = temp2;
                temp2 = temp2->next;
                if(c == n)
                {
                    break;
                }
            }
            temp3->next = temp2->next; 
        }
        return l1;

    }
    else
    {
        cout<<"ERROR"<<endl;
        return l1;
    }
}
linkedlist operator<<(linkedlist &l1, int n)
{
    ComplexInteger *temp = l1.head;
    ComplexInteger *temp2 = l1.head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = l1.head;
    for (int i = 0; i < n - 1; i++)
    {
        l1.head = (l1.head)->next;
    }
    temp2 = l1.head;
    l1.head = l1.head->next;
    temp2->next = NULL;
    return l1;
}
linkedlist operator>>(linkedlist &l1, int n)
{
    ComplexInteger *temp = l1.head;
    ComplexInteger *temp2 = l1.head;
    int cnt = 0;
    while (temp2->next != NULL)
    {
        cnt++;
        temp2 = temp2->next;
    }
    temp2->next = l1.head;
    for (int i = 0; i < cnt - n; i++)
    {
        l1.head = (l1.head)->next;
    }
    temp2 = l1.head;
    l1.head = l1.head->next;
    temp2->next = NULL;
    return l1;
}
bool search(linkedlist &l1, ComplexInteger &ci)
{
    ComplexInteger* temp = l1.head;
    while (temp != NULL)
    {
        if(ci.real == temp->real && ci.imaginary == temp->imaginary)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    linkedlist l1 , l2;
    ComplexInteger c1(1 , 2);
    l1.insert(c1);
    c1.set_method(3 , 4);
    l1.insert(c1);
    c1.set_method(5 , 6);
    l1.insert(c1);
    display(l1);
    ComplexInteger c2(7 , 8);
    l1 = l1+c2;
    display(l1);
    c2.set_method(9 , 10);
    l2.insert(c2);
    display(l2);
    l1 = l1 + l2;
    display(l1);
    l1 = -l1;
    display(l1);
    //l1 = l1*3;
    //display(l1);
    //l1 = l2;
    //display(l1);
    l1 = l1<<2;
    display(l1);
    l1 = l1>>2;
    display(l1);
    c2.set_method(5 , 6);
    cout<<search(l1 , c2)<<endl;
    return 0;
}