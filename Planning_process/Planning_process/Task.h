#pragma once
#include<iostream>
using namespace System;
using namespace std;

class task
{
private:
	int ID;// ID ������
	int difficult;// ��������� (����� ����������)
	bool is_start;// �����
	bool is_finish;//�����
	int current_difficult;// ���������� ����� ����������
	bool is_block;// ������������� �� ������
	int counter_block;// ������� ����������
	int const_number;// ����������� �����, ����������� ��� ��������� �� ��������� � �������� ��������� ������
	int current_procent;// ������� ������� ���������� ��� ����������
	bool was_block;// ���� �� ����������
public:
	task(int ID, int difficult);// ����������� � �����������
	~task();// ����������
	bool execution();// ����� ������������� ��������� ������
	void start();// ����� ���������
	void block(int current_procent);// ���������� ������
	bool time_block();// ��������� ������� ����������
	//�������
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