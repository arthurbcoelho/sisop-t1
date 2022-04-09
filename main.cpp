#include <iostream>
#include <vector>
#include <fstrea>


using namespace std;

struct Task
{
    int id;
    int start;
    int duration;
};

int taskId = 0;
int totalTime = 0;

struct Task TASKS[] = {};


void initialiseTask(struct Task &t, int start, int duration)
{
    ifstream file("tarefas.txt");
    if (file.is_open()){
        string line;
        while (getline(file, line)){
            cout << line << endl; 
        }
    }
    
    //t.id = taskId;
    //t.start = start;
    //t.executio
    //t.duration = duration;
//
    //TASKS[taskId] = t;
//
    //taskId++;
    //totalTime += duration;
}

void roundRobin()
{

    int QUANTUM = 2;
    int taskCount = taskId;
    int j = 0;

    
}

int main()
{

    int totalExecutionTime = 0;
    struct Task T1, T2, T3, T4;

    initialiseTask(T1, 0, 8);
    initialiseTask(T2, 1, 4);
    initialiseTask(T3, 2, 9);
    initialiseTask(T4, 3, 5);

    roundRobin();

    // cout << TASKS[0].id << endl;
    // cout << TASKS[1].id << endl;
    // cout << TASKS[2].id << endl;
    // cout << TASKS[3].id << endl;
    // cout << totalTime << endl;
    // struct Task TASKS[] = {T1, T2, T3, T4}; // TODO Dinamic?
    // roundRobin(TASKS, sizeof(TASKS) / sizeof(struct Task));

    return 0;
}