#include "My_queue.h"

My_queue::My_queue()// ����������� ������ My_queue
{
	size = 0;
	head = nullptr;
}


My_queue::~My_queue()// ���������� �������
{
	clear();
}

void My_queue::push_back(task *data)// ����� ���������� ������ � ����� �������
{
	if (head == nullptr)// �������� �� ������� ������
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;// current - ��� ��������� ��� �������� �� ������ 
		while (current->pNext != nullptr)// ������� �� ��������� ������� �������
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}

task* My_queue::operator[](size_t index)// ���������� ��������� []
{
	Node *current = this->head;
	for (size_t i = 0; current != nullptr; i++)// ����� ������� ��������
	{
		if (i == index)
		{
			return current->data;
		}
		current = current->pNext;
	}
	task *cr = new task(1,1);
	return cr;
}

task* My_queue::pop_front()// �������� ������� �������� �������
{
	if (size != 0)
	{
		Node *current = head;
		head = head->pNext;
		size--;
		return current->data;
	}
	else
	{
		return nullptr;
	}
}

void My_queue::clear()// ������� ������
{
	task *current;
	while (size)
	{
		current = pop_front();
		if (current)
		{
			delete current;
		}
	}
}
task* My_queue::removeAt(int index)// �������� �������� �� ���������� �������
{
	task *temp;
	if (index == 0)
	{ 
		temp = pop_front();
		return temp;

	}
	else
	{
		Node *current = head;
		for (int i = 0; i < index - 1; i++)// ����� ���������� ��������
		{
			current = current->pNext;
		}
		Node *temp_first = current->pNext;
		current->pNext = temp_first->pNext;
		temp = temp_first->data;
		size--;
		return temp;
	}

}
