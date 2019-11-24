#pragma once
#ifndef __CLUSTER_H__
#define __CLUSTER_H__
#include "Queue.h"
#include <iostream>
#include <ctime>



class Cluster
{
	int proc_counter;  //число процессоров
	int* proc;

	int generated_tasks; //появившиеся задачи
	int done_tasks; //выполненные задачи
	int undone_tasks;  // задачи в очереди
	int error_tasks; //задачи, не попавшие в очередь из-за переполнения
	int _time; //общее время работы
	int busy_proc; //количество занятых процессоров при каждом такте 
public:
	Cluster(int _pr);
	~Cluster();
	int Free_proc();
	void Cluster_work(int _time_in_tacts, int _tasks_on_tact, int _p_for_task, int _t_for_task);
	void Print_statistics();
};
#endif
