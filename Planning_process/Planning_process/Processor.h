#pragma once
#include<iostream>
#include"Task.h"
using namespace std;

// ����� ����������
class processor
{
private:
	int number;// �����
	task *current_task;// ������� ������
	int count_completed;// ���-�� ����������� �����
	int current_procent;// ������� ���������� ������� ������
	bool is_finish;// �����
public:
	processor();// �����������
	processor(int number);//����������� � �����������
	~processor();// ����������
	bool work();//����� ������ ����������
	void new_task(task *new_task);// ���������� ����� ������
	task* block_task();// ���������� ������� ������
	//�������
	int get_count_completed();
	int get_current_procent();
	int get_number();
	task* get_task();
	bool is_finish_task();
	void set_number(int number);
	void set_is_finish();
	bool get_is_finish();
};