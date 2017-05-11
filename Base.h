#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

class Printable
{
public:
	virtual void print(void) const = 0;
};

class Named : public Printable
{
	std::string name;
public:
	Named(std::string n) : name(n) {};
	std::string GetName(void) const
	{
		return name;
	}
};
