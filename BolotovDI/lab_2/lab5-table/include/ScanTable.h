#pragma once

#include "Table.h"

class ScanTable : table
{
private:
	int current_size; // ���������� �������
	int index; // ������ ������� ������ 
	void Repacking() override; // �����������
public:
	ScanTable(int nsize = 2) : table(nsize) { current_size = 0; index = -1; } // �����������
	~ScanTable() {} // ����������

	void Insert(const string s, const TPolinom &poli2) override; // �������
	TPolinom Search(const string k) const override; // �����
	void Delete(const string k) override; // ��������
};

void ScanTable::Repacking()
{
	max_size = max_size * 2;
	unit *tmp = new unit[max_size];
	for (int i = 0; i < current_size; i++)
	{
		tmp[i] = str[i];
	}
	delete str; // ???????????????????????????
	unit *str = new unit[max_size];
	for (int i = 0; i < index; i++)
	{
		str[i] = tmp[i];
	}
}

void ScanTable::Insert(const string s, const TPolinom &poli2)
{
	if (max_size == current_size) // �������� ����, ��� ������� ���������� � i = 0 � ���� � ��� max_size = 2 ( �� ������� ����� 2 ������), � �� ���� ����� 3 ������
	{
		Repacking();
	}
	str[current_size] = unit(s, poli2);
	current_size = current_size + 1;
	index = index + 1;
}

TPolinom ScanTable::Search(const string k) const
{
	int i = 0;
	while ((str[i].key != k) && (i < current_size))
	{
		i++;
	}

	if (i < current_size)
	{
		return str[i].data;
	}
	else
	{
		throw "Error";
	}
}

void ScanTable::Delete(const string k)
{
	int i = 0;
	while ((str[i].key != k) && (i < current_size))
	{
		i++;
	}

	if (i < current_size)
	{
		if (current_size > 1)
		{
			str[i] = str[index];
			current_size = current_size - 1;
			index = index - 1;
		}
		else
		{
			current_size = 0;
			index = -1;
		}
	}
	else
	{
		throw "Error";
	}
}