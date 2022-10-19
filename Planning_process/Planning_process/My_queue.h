#pragma once
#include <iostream>
#include "Task.h"
using namespace std;

class My_queue
{
private:
	class Node// узел очереди - класс, содержащий указатель на след элемент и задачу
	{
	public:
		Node *pNext;// указатель на след элемент
		task *data;// задача
		Node(task *data, Node *pNext = nullptr)// констркутор
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	size_t size;// кол-во элементов в списке
	Node *head;// уазатель на последний добавленный элемент в очереди
public:
	My_queue();// конструктор
	~My_queue();// деструктор
	void push_back(task *data);// метод добавления данных в конец очереди
	task* pop_front();// удаление элемента с начала очереди
	void clear();// очистка очереди
	int Size()// метод, возвращающий кол-во элементов в списке
	{
		return size;
	}
	task* operator[](const size_t index);// перегрузка оператора []
	task *removeAt(int index);// удаление элемента по индексу
};

