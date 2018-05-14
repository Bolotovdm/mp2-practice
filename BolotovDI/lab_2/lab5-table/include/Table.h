#pragma once

#include "TPolinom.h"

using namespace std;

struct unit
{
	TPolinom data;
	string key;

	unit() { key = "", data = TPolinom(); }
	unit(const string s, const TPolinom &poli2) { key = s; data = poli2;}
	
	unit& operator= (const unit &tmp) { data = tmp.data; key = tmp.key.substr(0, tmp.key.length()); return *this; }
};

class table
{
protected:
	unit *str; // ��������� �� ��������� 
	int max_size; // ������������ ������
	int size; // ���������� �������
	int index; // ������ ������� ������ 
	virtual void Repacking() = 0; // ����������� 
public:
	table(int nsize = 2); // �����������
	virtual ~table() { delete[] str; } // ����������

	virtual void Insert(const string k, const TPolinom &poli2) = 0; // �������
	virtual TPolinom Search(const string k) const = 0; // �����
	virtual void Delete(const string k) = 0; // �������� 

	void Reset(); // ������ ������ �������� �������
	bool IsFull(); // �������� �� ������� ������
	void Next(); // index++
	unit& GetCurrent(); // ������� �������
};

table::table(int nsize)
{
	max_size = nsize;
	size = 0;
	index = -1;
	str = new unit[nsize];
}

void table::Reset()
{
	index = 0;
}

bool table::IsFull()
{
	if (max_size == size) // �������� ����, ��� ������� ���������� � i = 0 � ���� � ��� max_size = 2 ( �� ������� ����� 2 ������), � �� ���� ����� 3 ������
	{
		return true;
	}
	else
	{
		return false;
	}
}

void table::Next()
{
	index = index + 1;
}

unit& table::GetCurrent()
{
	return str[index];
}