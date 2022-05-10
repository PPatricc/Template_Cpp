//
// Created by Patryk on 16.01.2022.
//
#pragma once
#include <iostream>
#include <string.h>

using namespace std;


template<class ID, class obj> class map_template{

    struct node{
        node *next;
        ID key;
        obj val;

        node (ID k):next (NULL)
        {
            key=k;
        };
        ~node (){}
    private:			//assignment not allowed
        node & operator= (const node &);
    };
    node *head;

    void clear(){
        while (head){
            node *t = head->next;
            delete head;
            head = t;
        };
    }

public:

    map_template(){head = NULL;};
    map_template(const map_template & l){
        node *src, **dst;
        head = NULL;
        src = l.head;
        dst = &head;
        try
        {
            while (src)
            {
                *dst = new node (*src);
                src = src->next;
                dst = &((*dst)->next);
            }
        }
        catch (...)
        {
            clear ();
            throw;
        };
    };
    map_template & operator= (const map_template & l)
    {
        if (&l == this) return *this;
        map_template t (l);
        node *temp=head;
        head=t.head;
        t.head=temp;

        return *this;
    }
    ~map_template (){
        clear();
    };

    void Add(ID key, obj o){
        node *newn = new node (key);
        newn->next=head;
        head=newn;
        head->val=o;
    }

    obj *Find(ID key){
        node *Tofind = head;
        while(Tofind){
            if(Tofind->key==key){
                return &(Tofind->val);
            }
            Tofind=Tofind->next;
        }
        return NULL;
    }
    friend ostream& operator<<(ostream& os, const map_template& t)
    {
        node *cur = t.head;
        while(true)
        {
            os<< "\"" << cur->key << "\"" << ", "<<cur->val;
            if(cur->next == NULL)   return os;
            os << endl;
            cur = cur->next;
        }
    }
};

