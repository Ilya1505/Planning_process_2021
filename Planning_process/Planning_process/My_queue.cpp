#include "My_queue.h"

My_queue::My_queue()// конструктор класса My_queue
{
	size = 0;
	head = nullptr;
}


My_queue::~My_queue()// деструктор очереди
{
	clear();
}

void My_queue::push_back(task *data)// метод добавления данных в конец очереди
{
	if (head == nullptr)// проверка на пустоту списка
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;// current - доп указатель для итерации по списку 
		while (current->pNext != nullptr)// переход на последний элемент очереди
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}

task* My_queue::operator[](size_t index)// перегрузка оператора []
{
	Node *current = this->head;
	for (size_t i = 0; current != nullptr; i++)// поиск нужного элемента
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

task* My_queue::pop_front()// удаление первого элемента очереди
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

void My_queue::clear()// очистка списка
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
task* My_queue::removeAt(int index)// удаление элемента по указанному индексу
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
		for (int i = 0; i < index - 1; i++)// поиск удаляемого элемента
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
