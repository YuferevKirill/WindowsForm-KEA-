// ClassLibrary1.h

#pragma once
#include "Iterator.h"
using namespace System;

namespace ClassLibrary1 {

	public ref class itr{
		Iterator * i;
	public:
		itr(Iterator * _i)
		{
			i = _i;
		}
		int next()
		{
			return i->next();
		}
		bool hasNext()
		{
			return i->hasNext();
		}
	};

	public ref class ListSH{
		TList * l;
	public:
		ListSH(){
			l = new TList;
			l->add(1);
		}

		void add(int v)
		{
			l->add(v);
		}

		itr^ getIterator()
		{
			Iterator * i_c = l->iterator();
			itr^ i = gcnew itr(i_c);
			return i;
		}
	};
	public ref class Class1
	{
		// TODO: Add your methods for this class here.
	};
}
