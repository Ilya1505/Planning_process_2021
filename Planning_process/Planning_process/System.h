#pragma once
#include<iostream>
#include"My_queue.h"
#include"Processor.h"
#include"Task.h"

using namespace std;
// класс система
class My_system
{
private:
	bool is_pause;// пауза
	bool is_finish;// финиш
	size_t count_cpu;// кол-во процессоров
	My_queue *general_queue_tasks;// указатель на главную очередь задач
	My_queue *block_tasks;// указатель на очередь заблокированных задач
	My_queue *finish_tasks;// // указатель на очередь выполненных задач
	processor *cpu;// указатель на массив процессоров
	size_t count_tasks;// кол-во задач
public:
	My_system(My_queue *tasks, size_t count_cpu, processor *cpu);// конструктор с параметрами
	~My_system();// деструктор
	void setup();// установка начальных параметров
	bool work();// метод работы системы
	void pause();// метод паузы
	void start();// метод начала работы системы
	bool get_is_pause();// геттер для паузы
	void block_task(int index);// блокировка выбранной задачи
	// геттеры
	task* get_task(size_t index);
	task* get_block_task(size_t index);
	processor* get_cpu(size_t index);
	size_t get_count_cpu();
	size_t get_count_general_queue_tasks();
	size_t get_count_block_tasks();
	size_t get_count_finish_tasks();
	size_t get_count_tasks();
	task* get_finish_task(size_t index);
};