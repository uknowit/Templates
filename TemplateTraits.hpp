/*
 * TemplateTraits.hpp
 *
 *  Created on: Jan 22, 2014
 *      Author: shashi
 */
#ifndef _TEMPLATE_TRAITS_HPP
#define _TEMPLATE_TRAITS_HPP
#include <string>
#include <iostream>
using std::cout;
using std::endl;

class ProjectManagement {
	std::string projectManagerGrade;
public:
	ProjectManagement(){projectManagerGrade="JG10";}
	void doProjectManagement(){cout<<"Doing project management...."<<endl;}
	friend std::ostream& operator <<(std::ostream& os, ProjectManagement& projectMangement){
		return os<<"["<<projectMangement.projectManagerGrade<<"]";
	}
};

class ProductManagement {
	std::string productManagerGrade;
public:
	ProductManagement(){productManagerGrade="JG9";}
	void doProductManagement(){cout<<"Doing product management by managing Features"<<endl;}
	friend std::ostream& operator <<(std::ostream& os,ProductManagement& productMgmt){
		return os<<"["<<productMgmt.productManagerGrade<<"]";
	}
};

class  ProjectManager {
	std::string projectManagerName;
public:
		ProjectManager(){projectManagerName="ASK";}
		friend std::ostream& operator <<(std::ostream& os,ProjectManager& projectManager){
			return os<<"["<<projectManager.projectManagerName<<"]";
		}
};


class  ProductManager {
	std::string productManagerName;
public:
		ProductManager(){productManagerName="Same";}
		friend std::ostream& operator <<(std::ostream& os,ProductManager& productManager ){
			return os<<"["<<productManager.productManagerName<<"]";
		}
};

template<class Role> class RoleTraits;
template<> class RoleTraits<ProjectManager> {
	public:
	typedef ProjectManagement job_type;
};

template<> class RoleTraits<ProductManager> {
public:
	typedef ProductManagement job_type;
};

class MixedJobRoles {
public:
	MixedJobRoles(){}
	typedef ProductManager job_type;
};

template<class Role,class traits=RoleTraits<Role> > class Company
{
	Role theRole;
	typedef typename  traits::job_type job_type;
	job_type job;
	std::string name;
public:
	Company(const Role& r) {theRole=r;}
	void print_everything() {
		cout<<"Role "<<" doing "<<job<<endl;
	}

};

template<typename D,typename B> class Derived {
	class NO {};
	class YES {NO no[3];};
	static YES Test(B*);
	static NO Test(...);

public:
	enum {Is=sizeof(Test(static_cast<D*>(0)))==sizeof(YES)};
};

class Base {};
class DerivedFromBase:public Base
{
};
class Rest{};
#endif

