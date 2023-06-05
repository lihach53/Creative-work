#pragma once
#include <iostream>
#include <string>

public class Reader
{
private:
	std::string fio;
	std::string passNum;

public:
	Reader()
	{
		this->fio = "";
		this->passNum = "";
	}

	Reader(std::string fio, std::string passNum)
	{
		this->fio = fio;
		this->passNum = passNum;
	}
	std::string get_fio() { return this->fio; }
	std::string get_passNum() { return this->passNum; }
	std::string toString()
	{
		return this->fio + " (Passport: " + this->passNum + " )";
	}
};