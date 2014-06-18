//============================================================================
// Name        : TemplatesInitial.cpp
// Author      : Shashikumar HN
// Version     :
// Copyright   : Dream big
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stack.hpp"
#include "Container.hpp"
#include "typeName.hpp"
#include "DelayedInstatiation.hpp"
#include "NameLookUp.hpp"
#include "FriendlyClass.hpp"
#include "FriendlyTemplateClass.hpp"
#include "FriendOverloading.hpp"
#include "TemplateTraits.hpp"
#include "Traits.hpp"
#include "ClassCount.hpp"
#include "TemplateClassCount.hpp"
#include  "Accumlate.hpp"
#include "ExpressionTemplate.hpp"
#include "ExerciseTemplate.hpp"
#include "PartialSpecialization.hpp"
#include "FunctionTemplates.hpp"
#include "FunctionObject.hpp"
#include <string>


using  std::cout;
using  std::endl;
using  std::string;

string strTolower(string);

template<typename T> void  displayMessage(T message)
{
}

template<typename T> const T& min(const T& a,const T& b)
{
	return (a<b)?a:b;
}

template<> const char* const& min<const char* >(const char* const & a,const char* const& b)
{
	return string(a).compare(string(b))>0?a:b;
}

int main()
{
	cout<<"==============="<<endl;
	string msg = "Welcome to 2014 ....";
	displayMessage(msg);
	MyStack<int,10> stackTest;
	int i=10;
	int j=20;
	stackTest.push(i);
	stackTest.push(j);
	stackTest.pop();
	stackTest.pop();
	Container<int,MyStack> container;
	container.append(1);
	container.pop_back();
	X<Y> xy;
	xy.f();
	cout<<strTolower(msg)<<endl;
	const char* s2="Say \"Hi!\" ",*s1="knights who" ;
	cout<<min(s1,s2)<<endl;
	cout<<min<>(s1,s2)<<endl;
	Z<XX> zxx;
	zxx.a();
	Z<YY> zyy;
	zyy.b();
	XXX<int> xxx;
	cout<<xxx.f()<<endl;
	hf();
	Friendly(2).g();
	hft();
	FriendlyTemplateClass<int>(2).g();
	FriendOverloading<int> a11(82),a22(33);
	cout<<a11+a22<<endl;
	FriendOverloading<std::string> ss1("Shashi"),ss2("Kumar");
	cout<<ss1+ss2<<endl;
    //cout<<ss1+"HN"<<endl;
	(a11<a22)?cout<<"a11 is lesser"<<endl:cout<<"a22 is lesser"<<endl;

	ProductManager productManager;
	Company<ProductManager> c1(productManager);
	c1.print_everything();

	ProjectManager projectManager;
	Company<ProjectManager> c2(projectManager);
	c2.print_everything();

	MixedJobRoles jobRoles;
	Company<ProductManager,MixedJobRoles> c3(productManager);
	c3.print_everything();
	//C<string> ccc;
	Derived<DerivedFromBase,Base> testMe;
	//assert(testMe.Is);
	//Derived<DerivedFromBase,Rest> testYou;
	//assert(testYou.Is);
	CountedClass ca;
	cout<<ca.getCount()<<endl;
	CountedClass cb;
	cout<<cb.getCount()<<endl;
	CountedClass2 ca1;
	cout<<ca1.getCount()<<endl;
	TempCountedClass tca;
	cout<<tca.getCount()<<endl;
	TempCountedClass tcb;
	cout<<tcb.getCount()<<endl;
	TempCountedClass2 tcc;
	cout<<tcc.getCount()<<endl;

	cout<<Accumlate<4,Identity>::val<<endl;
	cout<<Accumlate<4,Square>::val<<endl;
	cout<<Accumlate<4,Cube>::val<<endl;
	srand(time(0));
	MyVector<int,5> v1;
	init(v1);
	print(v1);

	MyVector<int,5> v2;
	init(v2);
	print(v2);
	MyVector<int,5> v3;
	v3=v1+v2;
	print(v3);
	double initDouArr[10];
	initializeExTemp(initDouArr,10);
	double sumLocal=0.0;
	for(int index=2;index<=7;index++)
		sumLocal=sumLocal+initDouArr[index];
	cout<<calculateSum(initDouArr,2,7,0.0)<<endl;
	cout<<sumLocal<<endl;

	My<Buddy> me,bud;
	me.play(bud);
	templatePartial<20,int,Defaultsorter> initialPartial;
	templatePartial<20,std::string,Defaultsorter> secondPartial;
	initialPartial.initT();
	initialPartial.sort();
	srand(time(0));
	secondPartial.initT();
	secondPartial.sort();

	SmartPtr<Top> pointer1=SmartPtr<Middle>(new Middle);
	SmartPtr<Top> pointer2=SmartPtr<Bottom>(new Bottom);
	//SmartPtr<Middle> pointer4=SmartPtr<Top>(new Top);
	SmartPtr<const Top> pointer3=pointer1;

	std::list<double> doubleList;
	doubleList.push_back(3.0);
	doubleList.push_back(5.0);
	doubleList.push_back(8.0);
	fDouble(doubleList);
	Sum<int> sum(20);
	sum(39);
	std::cout<<"Understanding overriding operator()::"<<sum.result()<<std::endl;
	std::list<Club> clubList;
	clubList.push_back(Club("ASD"));
	clubList.push_back(Club("ABC"));
	clubList.push_back(Club("AFG"));
	std::list<Club>::iterator clubIter=find_if(clubList.begin(),clubList.end(),Club_eq("ABC"));
	if(clubIter!=clubList.end())
		std::cout<<(*clubIter).clubName<<endl;
	for_each(clubList.begin(),clubList.end(),mem_fun_ref(&Club::getName));
	std::list<double>::iterator listiter=std::find_if(doubleList.begin(),doubleList.end(),m_bind2nd(std::less<double>(),8.0));
	std::cout<<(*listiter)<<std::endl;
	std::list<double> doubleListSecond;
	doubleListSecond.push_back(3.0);
	doubleListSecond.push_back(5.0);
	//doubleListSecond.push_back(8.0);
	doubleListSecond.push_back(10.0);
	std::pair<std::list<double>::iterator,std::list<double>::iterator> resultPair;
	resultPair=std::mismatch(doubleList.begin(),doubleList.end(),doubleListSecond.begin(),std::not2(std::less<int>()));
	std::cout<<"I am thinking...."<<*resultPair.first<<"  "<<*resultPair.second<<std::endl;
	std::list<Person*> off;
	for_each(clubList.begin(),clubList.end(),Extract_officers(off));
}

