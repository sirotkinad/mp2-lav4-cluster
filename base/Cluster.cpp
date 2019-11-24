#include "Cluster.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
#define MIN_CPU 4
#define MAX_CPU 64


Cluster::Cluster(int _pr)
{
	if ((_pr < MIN_CPU) || (_pr > MAX_CPU))
		throw "Incorrect amount of processors";
	_time = 0;
	generated_tasks = 0;
	error_tasks = 0;
	busy_proc = 0;
	proc_counter = _pr;
	proc = new int[_pr];
	for (int i = 0; i < _pr; i++)
		proc[i] = 0;
}

Cluster::~Cluster()
{
	delete[] proc;
}

int Cluster::Free_proc()
{
	int Free_pr = 0;
	for (int i = 0; i < proc_counter; i++)
		if (proc[i] == 0)
			Free_pr++;
	return Free_pr;
}


void Cluster::Cluster_work(int _time_in_tacts, int _tasks_on_tact, int _p_for_task, int _t_for_task)
{
	if ((_time_in_tacts < 1) || (_tasks_on_tact < 1) || (_p_for_task < 1) || (_t_for_task < 1))
		throw "Incorrect data";

	if (_time_in_tacts * _tasks_on_tact > MaxSize)
		throw "Incorrect data";

	if (_p_for_task > proc_counter)
		throw "Excess of processors for 1 task";
	int b, c;
	int tasks_on_tact;
	int free = Free_proc();
	int length = _time_in_tacts * _tasks_on_tact;
	Queue<int> Tasks_queue_proc(length);
	Queue<int> Tasks_queue_tact(length);
	while (_time < _time_in_tacts)
	{
		tasks_on_tact = rand() % (_tasks_on_tact)+1;
		for (int i = 0; i < tasks_on_tact; i++)
		{
			generated_tasks++;
			b = rand() % _p_for_task + 1;
			c = rand() % _t_for_task + 1;
			if (!Tasks_queue_proc.Full() && !Tasks_queue_proc.Full()) //если неполная очередь, добавляем
			{
				Tasks_queue_proc.Push(b);
				Tasks_queue_tact.Push(c);
			}
			else
				error_tasks++;
			if (!Tasks_queue_proc.Empty()) // если очередь не пустая
			{
				int amount_of_proc = Tasks_queue_proc.GetElem(); //количество процессоров
				int amount_of_tacts = Tasks_queue_tact.GetElem(); //количество тактов
				int change_proc = amount_of_proc;
				if (free >= amount_of_proc) //если свободных больше, чем процессоров задачи
				{
					for (int i = 0; i < proc_counter; i++) //процессоров всего на кластере
					{
						if ((proc[i] == 0) && (change_proc > 0))
						{
							proc[i] = amount_of_tacts + 1;
							change_proc--;
						}
					}
					Tasks_queue_proc.Pop();
					Tasks_queue_tact.Pop();
				}

				free = Free_proc();
			}
			for (int i = 0; i < proc_counter; i++) //уменьшаем число тактов
			{
				if (proc[i] > 0)
					proc[i]--;
			}
			busy_proc = busy_proc + (proc_counter - free);
		}
		_time++;
	}
	undone_tasks = Tasks_queue_proc.GetSize();
}

void Cluster::Print_statistics()
{
	done_tasks = generated_tasks - (undone_tasks + error_tasks);
	double average_load_proc = busy_proc / _time;
	cout << endl;
	cout << "The statistics of cluster: " << endl;
	cout << "Number of generated tasks: " << generated_tasks << endl;
	cout << "Number of completed tasks: " << done_tasks << endl;
	cout << "Number of tasks stayed in queue: " << undone_tasks << endl;
	cout << "Number of tasks not completed because of the overflow in the queue: " << error_tasks << endl;
	cout << "Work time: " << _time << " tacts" << endl;
	cout << "Average load of cluster: " << (average_load_proc/10)*100 <<"%" << endl;
}