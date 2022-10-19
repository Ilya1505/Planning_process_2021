#include "Task.h"

task::task(int ID, int difficult)// конструктор с параметрами
{
	this->ID = ID;
	this->difficult = difficult;
	is_start = false;
	is_finish = false;
	current_difficult = difficult;
	is_block = false;
	counter_block = 0;
	const_number = 1;
	current_procent = 0;
	was_block = false;
}
task::~task()// деструктор
{

}
bool task::execution()// метод моделирования обработки задачи
{
	if (!is_start)
		is_start = true;
	current_difficult -= const_number;
	if (!current_difficult)
		return is_finish = true;
	return is_finish;
}
// старт обработки
void task::start()
{
	is_start = true;
}
// блокировка задачи
void task::block(int current_procent)
{
	Random ^rand = gcnew Random();
	counter_block = rand->Next(1, difficult);
	is_block = true;
	was_block = true;
	this->current_procent = current_procent;
}
// генерация времени блокировки
bool task::time_block()
{
	if (!is_block)
		return is_block;
	counter_block -= const_number;
	if (!counter_block)
		is_block = false;
	return is_block;
}
//геттеры
int task::get_ID()
{
	return ID;
}
int task::get_difficult()
{
	return difficult;
}
bool task::get_is_start()
{
	return is_start;
}
bool task::get_is_finish()
{
	return is_finish;
}
bool task::get_is_block()
{
	return is_block;
}
int task::get_counter_block()
{
	return counter_block;
}
int task::get_current_difficult()
{
	return current_difficult;
}
void task::set_current_procent(int current_procent)
{
	this->current_procent = current_procent;
}
int task::get_current_procent()
{
	return current_procent;
}
String ^task::get_state()
{
	String ^string;
	if (was_block)
	{
		string = gcnew String("да");
	}
	else
	{
		string = gcnew String("нет");
	}
	return string;
}