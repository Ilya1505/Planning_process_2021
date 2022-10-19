#pragma once
#include<iostream>
#include"My_queue.h"
#include"Processor.h"
#include"Task.h"

using namespace std;
// ����� �������
class My_system
{
private:
	bool is_pause;// �����
	bool is_finish;// �����
	size_t count_cpu;// ���-�� �����������
	My_queue *general_queue_tasks;// ��������� �� ������� ������� �����
	My_queue *block_tasks;// ��������� �� ������� ��������������� �����
	My_queue *finish_tasks;// // ��������� �� ������� ����������� �����
	processor *cpu;// ��������� �� ������ �����������
	size_t count_tasks;// ���-�� �����
public:
	My_system(My_queue *tasks, size_t count_cpu, processor *cpu);// ����������� � �����������
	~My_system();// ����������
	void setup();// ��������� ��������� ����������
	bool work();// ����� ������ �������
	void pause();// ����� �����
	void start();// ����� ������ ������ �������
	bool get_is_pause();// ������ ��� �����
	void block_task(int index);// ���������� ��������� ������
	// �������
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