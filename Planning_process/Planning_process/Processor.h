#pragma once
#include<iostream>
#include"Task.h"
using namespace std;

// класс процессора
class processor
{
private:
	int number;// номер
	task *current_task;// текущая задача
	int count_completed;// кол-во выполненных задач
	int current_procent;// процент выполнения текущей задачи
	bool is_finish;// финиш
public:
	processor();// конструткор
	processor(int number);//конструткор с параметрами
	~processor();// деструктор
	bool work();//метод работы процессора
	void new_task(task *new_task);// добавление новой задачи
	task* block_task();// блокировка текущей задачи
	//геттеры
	int get_count_completed();
	int get_current_procent();
	int get_number();
	task* get_task();
	bool is_finish_task();
	void set_number(int number);
	void set_is_finish();
	bool get_is_finish();
};