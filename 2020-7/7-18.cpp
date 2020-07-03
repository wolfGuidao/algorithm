/*************************************************************************
  > File Name: 7-18.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月03日 星期五 14时21分21秒
 ************************************************************************/

#include "Header.hpp"

#include <stdio.h>
#include <stdlib.h>

typedef struct _Parent
{  
    int a;  
    int b;  
    void (*print)(struct _Parent *This);  
}Parent; 

typedef struct _Child
{  
    Parent parent;  
    int c;  
}Child;

void print_parent(Parent *This)  
{  
    printf("i am print_parent\n");
    printf("a = %d. b = %d.\n",   This->a, This->b);  
}  
  
void print_child(Parent *This)  
{  
    Child *p = (Child *)This;  
    printf("i am print_child\n");
	printf("a = %d. b = %d. c = %d.\n", p->parent.a, p->parent.b, p->c);  
}  
  
Parent *create_parent(int a, int b)  
{  
    Parent *This;  
  
    This = NULL;  
    This = (Parent *)malloc(sizeof(Parent));  
    if (This != NULL)
	{  
        This->a = a;  
        This->b = b;  
        This->print = print_parent;  
        printf("Create parent successfully!\n");  
    }  
      
    return This;  
}  
  
void destroy_parent(Parent **p)  
{  
    if (*p != NULL)
	{  
        free(*p);  
        *p = NULL;  
        printf("Delete parent successfully!\n");  
    }  
}  
  
Child *create_child(int a, int b, int c)  
{  
    Child *This;  
  
    This = NULL;  
    This = (Child *)malloc(sizeof(Child));  
    if (This != NULL)
	{  
        This->parent.a = a;  
        This->parent.b = b;  
        This->c = c;  
        This->parent.print = print_child;  
        printf("Create child successfully!\n");  
    }  
      
    return This;  
}  
  
void destroy_child(Child **p)  
{  
    if (*p != NULL)
	{  
        free(*p);  
        *p = NULL;  
        printf("Delete child successfully!\n");  
    }  
}  
  
int main()  
{  
    //Child *p = create_child(1, 2, 3);  
    //Parent *q;  
  

    //q = (Parent *)p;  
    //
    //q->print(q);  
  
    //destroy_child(&p); 
    
    Parent* parent = create_parent(999,666);
    parent->print(parent);

    Child* child = create_child(123,456,789);
    child->parent.print(parent);    
    return 0;  
}  

