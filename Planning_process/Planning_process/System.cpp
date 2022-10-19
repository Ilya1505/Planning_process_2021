#include "System.h"
// �����������
My_system::My_system(My_queue *tasks, size_t count_cpu, processor *cpu)
{
	this->general_queue_tasks = tasks;
	this->count_cpu = count_cpu;
	this->cpu = cpu;
	is_pause = true;
	is_finish = false;
	block_tasks = new My_queue();
	finish_tasks = new My_queue();
	count_tasks = tasks->Size();
}
//����������
My_system::~My_system()
{
	delete[] cpu;
	delete block_tasks;
	delete finish_tasks;
	delete general_queue_tasks;
}
//��������� ��������� ���������� �������
void My_system::setup()
{
	task *current_task;
	for (int i = 0; i < count_cpu; i++)
	{
		if (general_queue_tasks->Size() == 0)
		{
			break;
		}
		current_task = general_queue_tasks->pop_front();
		cpu[i].new_task(current_task);
	}
}
// ����� ������ �������
bool My_system::work()
{
	if (is_finish)
		return is_finish;
	task *current_task;
	for (int i = 0; i < block_tasks->Size(); i++)
	{
		current_task = block_tasks->operator[](i);
		if (!current_task->time_block())
		{
			block_tasks->removeAt(i);
			general_queue_tasks->push_back(current_task);
		}
	}
	for (int i = 0; i < count_cpu; i++)
	{
		if (cpu[i].is_finish_task()&&general_queue_tasks->Size() == 0)// ������� ���������� ��� ����������� ������ � ������ ������� �����
		{
			continue;
		}
		else if (cpu[i].is_finish_task()&&general_queue_tasks->Size() != 0)// �������� ���������� ����� ������ ��� ���������� ����������
		{
			current_task = general_queue_tasks->pop_front();
			cpu[i].new_task(current_task);
		}
		if (cpu[i].work())
		{
			if (cpu[i].get_task() != nullptr)
			{
				finish_tasks->push_back(cpu[i].get_task());
			}
			if (general_queue_tasks->Size() != 0)
			{
				current_task = general_queue_tasks->pop_front();
				cpu[i].new_task(current_task);
			}
		}
	}
	if (count_tasks == finish_tasks->Size())
	{
		is_finish = true;
	}
	return is_finish;
}
// ����� �����
void My_system::pause()
{
	is_pause = true;
}
// ����� ������ ������ �������
void My_system::start()
{
	is_pause = false;
}
// ������ ��� �����
bool My_system::get_is_pause()
{
	return is_pause;
}
// �������
task* My_system::get_task(size_t index)
{
	return general_queue_tasks->operator[](index);
}

task* My_system::get_block_task(size_t index)
{
	return block_tasks->operator[](index);
}

task* My_system::get_finish_task(size_t index)
{
	return finish_tasks->operator[](index);
}

processor* My_system::get_cpu(size_t index)
{
	if (index<0 || index>count_cpu)
	{
		return nullptr;
	}
	return &cpu[index];
}
size_t My_system::get_count_cpu()
{
	return count_cpu;
}
size_t My_system::get_count_general_queue_tasks()
{
	return general_queue_tasks->Size();
}
size_t My_system::get_count_block_tasks()
{
	return  block_tasks->Size();
}
// ���������� ��������� ������
void My_system::block_task(int index)
{
	task *temp = nullptr;
	if (!cpu[index].is_finish_task())
	{
		temp = cpu[index].block_task();
		if (temp)
		{
			block_tasks->push_back(temp);
		}
	}
}
size_t My_system::get_count_finish_tasks()
{
	return finish_tasks->Size();
}
size_t My_system::get_count_tasks()
{
	return count_tasks;
}