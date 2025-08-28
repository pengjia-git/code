#ifndef __BOOK__H__
#define __BOOK__H__

#include <iostream>
#include <vector>
#include <string>

class Book
{
public:
	virtual std::string getName() = 0;
	virtual float getPrice() = 0;
};

class NovelBook : public Book
{
public:
	NovelBook(std::string name,float price);
	std::string getName();
	float getPrice();
private:
	std::string mName;
	float mPrice;
};

class NovelBookOff:public NovelBook
{
	public:

	NovelBookOff(std::string name,float price);
	float getPrice();
};
#endif
