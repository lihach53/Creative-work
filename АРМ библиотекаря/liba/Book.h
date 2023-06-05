/*#pragma once
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

ref class Book
{
public:
	Book(String^ title, String^ author, String^ publisher, int year)
		: title(title), author(author), publisher(publisher), year(year) {}
	String^ get_title() { return title; }
	String^ get_author() { return author; }
	String^ get_publisher() { return publisher; }
	int get_year() { return year; }
	String^ to_string() { return title + " by " + author + " (" + publisher + ", " + year + ")"; }
private:
	String^ title;
	String^ author;
	String^ publisher;
	int year;
};*/
#pragma once
#include <iostream>
#include <string>

public class Book
{
private:
	std::string title;
	std::string author;
	std::string publisher;
	int year;

public:
	Book()
	{
		this->title = "";
		this->publisher = "";
		this->author = "";
		this->year = 0;
	}

	Book(std::string title, std::string author, std::string publisher, int year)
	{
		this->title = title;
		this->publisher = publisher;
		this->author = author;
		this->year = year; 
	}
	std::string get_title() { return this->title; }
	std::string get_author() { return this->author; }
	std::string get_publisher() { return this->publisher; }
	int get_year() { return this->year; }
	std::string toString()
	{
		return this->title + " by " + this->author + " (" + this->publisher + ", " + std::to_string(this->year) + ")";
	}
};