#pragma once
#include <stdio.h>

class Iterator
{
public:
  virtual bool hasNext() = 0;
  virtual int next()=0;
};


class ArrayIterator: public Iterator
{
  int *a;
  int N;
  int tmp;
public:

  ArrayIterator(int *a, int N)
  {
    this->a = a;
    this->N = N;
    tmp = 0;
  }

  virtual bool hasNext()
  {
    return tmp < N;
  }
  virtual int next()
  {
    if(tmp == N) throw "out of array";
    tmp++;
    return a[tmp-1];
  }
};

struct Node{
  int val; 
  Node * n;
};

class ListIterator: public Iterator
{
  Node * cur;
public:
  ListIterator(Node * h)
  {
    cur = h;
  }

  virtual bool hasNext()
  {
    return cur != NULL;
  }
  virtual int next()
  {
    if(cur == NULL) throw "out of list";
    Node *t = cur;
    cur = cur->n;
    return t->val;
  }
};


class ListPositiveIterator: public Iterator
{
  Node * cur;
public:
  ListPositiveIterator(Node * h)
  {
    cur = h;
    while(cur != NULL)
    {
      if(cur->val >= 0) break;
      cur = cur->n;
    }
  }

  virtual bool hasNext()
  {
    return cur != NULL;
  }
  virtual int next()
  {
    if(cur == NULL) throw "out of list";
    Node *t = cur;
    cur = cur->n;
    while(cur != NULL)
    {
      if(cur->val >= 0) break;
      cur = cur->n;
    }
    return t->val;
  }
};

class TList
{
  Node * h;
public:
  TList()
  {
    h = NULL;
  }

  void add(int val)
  {
    Node * t = new Node;
    t->val= val;
    t->n = NULL;

    t->n = h;
    h = t;
  }


  Iterator * iterator(){
    return new ListIterator(h);
  }
};

