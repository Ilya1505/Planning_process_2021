#include "Processor.h"

processor::processor()// конструткор
{
	this->number = 0;
	current_task = nullptr;
	count_completed = 0;
	current_procent = 0;
	is_finish = false;
}
//конструткор с параметрами
processor::processor(int number)
{
	this->number = number;
	current_task = nullptr;
	count_completed = 0;
	current_procent = 0;
	is_finish = false;
}
// деструктор
processor::~processor()
{
	if (current_task)
	{
		delete current_task;
	}
}
//метод работы процессора
bool processor::work()
{
	if (!current_task)
		return true;
	if (current_task->execution())
		count_completed++;
	current_procent = ((current_task->get_difficult() - current_task->get_current_difficult()) * 100) / current_task->get_difficult();
	current_task->set_current_procent(current_procent);
	return current_task->get_is_finish();
}
// добавление новой задачи
void processor::new_task(task *new_task)
{
	current_task = new_task;
	current_procent = current_task->get_current_procent();
}
// блокировка текущей задачи
task* processor::block_task()
{
	if (!current_task)
		return nullptr;
	current_task->block(current_procent);
	task *temp = current_task;
	current_task = nullptr;
	return temp;
}
//геттеры
int processor::get_count_completed()
{
	return count_completed;
}
int processor::get_current_procent()
{
	return current_procent;
}
task* processor::get_task()
{
	return this->current_task;
}
bool processor::is_finish_task()
{
	if (!current_task)
	{
		return true;
	}
	return current_task->get_is_finish();
}
void processor::set_number(int number)
{
	this->number = number;
}
void processor::set_is_finish()
{
	is_finish = true;
}
bool processor::get_is_finish()
{
	return is_finish;
}
int processor::get_number()
{
	return number;
}