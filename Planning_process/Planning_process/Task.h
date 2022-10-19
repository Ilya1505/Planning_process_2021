#pragma once
#include<iostream>
using namespace System;
using namespace std;

class task
{
private:
	int ID;// ID задачи
	int difficult;// сложность (время выполнения)
	bool is_start;// старт
	bool is_finish;//финиш
	int current_difficult;// оставшееся время выполнения
	bool is_block;// заблокирована ли задача
	int counter_block;// счетчки блокировки
	int const_number;// константное число, необходимое для отнимания от сложности в процессе обработки задачи
	int current_procent;// текущий процент выполнения при блокировке
	bool was_block;// была ли блокировка
public:
	task(int ID, int difficult);// конструктор с параметрами
	~task();// деструктор
	bool execution();// метод моделирования обработки задачи
	void start();// старт обработки
	void block(int current_procent);// блокировка задачи
	bool time_block();// генерация времени блокировки
	//геттеры
	int get_ID();
	int get_difficult();
	bool get_is_start();
	bool get_is_finish();
	bool get_is_block();
	int get_counter_block();
	int get_current_difficult();
	void set_current_procent(int current_procent);
	int get_current_procent();
	String ^get_state();
};