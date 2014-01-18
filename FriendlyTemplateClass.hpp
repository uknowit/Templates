/*
 * FriendlyTemplateClass.hpp
 *
 *  Created on: Jan 18, 2014
 *      Author: shashi
 */

#ifndef FRIENDLYTEMPLATECLASS_HPP_
#define FRIENDLYTEMPLATECLASS_HPP_
#include <iostream>
using std::cout;
using std::iostream;

template<class T> class FriendlyTemplateClass;
template<class T> void ft(const FriendlyTemplateClass<T>&);

template<class T> class FriendlyTemplateClass {
	T t;
public:
		FriendlyTemplateClass(const T& theT):t(theT){}
		friend void ft(const FriendlyTemplateClass<T>& fo) {
			cout<<fo.t<<endl;
		}
		//language specifies that template friend must be previously declared
		void g(){ft(*this);}
};

void hft()
{
	ft(FriendlyTemplateClass<int>(1));
}




#endif /* FRIENDLYTEMPLATECLASS_HPP_ */
