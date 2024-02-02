#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

struct list // node description
{
    int field;
    struct list *next; // pointer to the next node
    struct list *prev; // pointer to the previous node
};

static struct list *init(int a) // a - value of the first node; here we initialize the list
{
    struct list *lst; // allocate space for the root (head) of the list
    lst = (struct list*)malloc(sizeof(struct list));  //! don't forget to clear memory in "main()"
    if (lst) // check that "lst" contains something and is not NULL
    {
        lst->field = a;
        lst->next = nullptr; // instead of "NULL" we will use the more standard "nullptr"
        lst->prev = nullptr;
    }
    return (lst);
}

static struct list *addelem(list *lst, int number) // this function will add the node to the next position after the specified position
{
    struct list *temp, *p;
    temp = (struct list*)malloc(sizeof(list)); //! don't forget to clear memory in "main()"
    p = lst->next; // save pointer to the next node
    if (temp) // check that "temp" contains something and is not NULL
    {
        lst->next = temp; // edit the pointer of the previous node to point to the created one
        temp->field = number; // allocate space for the created node
        temp->next = p; // the created node points to the next node
        temp->prev = lst; // the created node points to the previous node
    }
    if (p != nullptr)
    {
        p->prev = temp;
    }
    return(temp);
}

static void listprint(list *lst)
{
    struct list *p;
    p = lst;
    do 
    {
     cout << p->field << " "; // output the value of element "p"
     p = p->next; // move on to the next node
    } while (p != nullptr); // end of list
}

static void listprintreverse(list *lst)
{
    struct list *p;
    p = lst;
    while (p->next != nullptr)
    {
        p = p->next; // let's go to the end of the list
    }
    do
    {
        cout << p->field << " "; // output the value of element "p"
        p = p->prev; // move on to the previous node
    } while (p != nullptr); // start of list
}

int mainlab7()
{
    list *head, *cur;
    int num, a;
    cout << "set the capacity of the list: ";
    cin >> a;
    cout << "a[0] = ";
    cin >> num; 
    // it is clear that when creating such a list using a simple "for" loop, we have to set the initial element ("head") manually
    head = init(num);
    cur = head;
    for (int i = 0; i < a - 1; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> num;
        cur = addelem(cur, num);
    }
    listprint(head);
    cout << endl;
    listprintreverse(head);
    free(cur); // since we passed "cur" to "head" (line 82), clearing the memory allocated for "cur" we do the same with "head"
    _getch();
    return 0;
}