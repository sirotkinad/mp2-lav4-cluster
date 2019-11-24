#include "Cluster.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	int size, _time_in_tacts, _tasks_on_tact, _p_for_task, _t_for_task;
	cout << "Enter number of processors on cluster: ";
	cin >> size;
	cout << "Enter number of tacts: ";
	cin >> _time_in_tacts;
	cout << "Enter amount of tasks on 1 tact: ";
	cin >> _tasks_on_tact;
	cout << "Enter amount of processors for 1 task: ";
	cin >> _p_for_task;
	cout << "Enter amount of tacts on execution of 1 task: ";
	cin >> _t_for_task;

	Cluster Cluster(size);
	Cluster.Cluster_work(_time_in_tacts, _tasks_on_tact, _p_for_task, _t_for_task);

	Cluster.Print_statistics();
	system("pause");
	return 0;
}