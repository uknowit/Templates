/*
 * TemplateClassCount.hpp
 *
 *  Created on: Feb 1, 2014
 *      Author: shashi
 */

#ifndef TEMPLATECLASSCOUNT_HPP_
#define TEMPLATECLASSCOUNT_HPP_

template<class T> class TempCounted {
	static int tempCount;
public:
	TempCounted(){++tempCount;}
	TempCounted(const TempCounted&){++tempCount;}
	~TempCounted(){--tempCount;}
	static int getCount(){return tempCount;}
};

template<class T> int TempCounted<T>::tempCount=0;
/*http://www.codeproject.com/Tips/537606/Cplusplus-Prefer-Curiously-Recurring-Template-Patt*/
class TempCountedClass:public TempCounted<TempCountedClass>{};
class TempCountedClass2:public TempCounted<TempCountedClass2>{};

#endif /* TEMPLATECLASSCOUNT_HPP_ */
