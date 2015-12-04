/*
 * AddressGenerator.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: shashi
 */

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
string strTolower(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}



