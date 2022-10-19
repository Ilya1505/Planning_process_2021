#pragma once
#include <iostream>
#include "Task.h"
using namespace std;

class My_queue
{
private:
	class Node// ���� ������� - �����, ���������� ��������� �� ���� ������� � ������
	{
	public:
		Node *pNext;// ��������� �� ���� �������
		task *data;// ������
		Node(task *data, Node *pNext = nullptr)// �����������
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	size_t size;// ���-�� ��������� � ������
	Node *head;// �������� �� ��������� ����������� ������� � �������
public:
	My_queue();// �����������
	~My_queue();// ����������
	void push_back(task *data);// ����� ���������� ������ � ����� �������
	task* pop_front();// �������� �������� � ������ �������
	void clear();// ������� �������
	int Size()// �����, ������������ ���-�� ��������� � ������
	{
		return size;
	}
	task* operator[](const size_t index);// ���������� ��������� []
	task *removeAt(int index);// �������� �������� �� �������
};

