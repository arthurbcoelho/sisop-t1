#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Task
{
    string name;
    int start;
    int time;
};

void readLine(string line, string *taskName, int *taskStart, int *taskTime){

    int n = line.length();
    
    char *ptr;
    char sstring[n+1];
    
    strcpy(sstring, line.c_str());
    ptr = strtok(sstring, ",");
    
    for(int c=0; ptr != NULL; c++){  
        if(c == 0){
            *taskName = ptr;
        }
        else if (c == 1){
            *taskStart = stoi(ptr);
        }
        else{
            *taskTime = stoi(ptr);
        }
        ptr = strtok(NULL, ",");
    }
}

void roundRobin(struct Task *tasks, int taskCount){
    int quantum = 3;
    int overhead = 1;
    int j = 0;
    int k = 0;
    int totalExecutionTime = 0;

    cout << "      ==== Round Robin ====      " << endl << endl;

    while(j < taskCount){
        cout << "Caiu aqui" << endl;
        for(int i=0; i < taskCount; i++){
            if(k<taskCount){
                totalExecutionTime += tasks[i].time;
                k++;
            }
            if(tasks[i].time > 0){  
                cout << "Executando: " << tasks[i].name << " Tempo restante: " << tasks[i].time << endl;
                tasks[i].time -= (quantum - overhead);
                totalExecutionTime += overhead;

                if(tasks[i].time <= 0){
                    cout << tasks[i].name << " Finalizada!" << endl;
                    j++;
                }
            }
        }
    }
    cout << "Tempo total: " << totalExecutionTime << endl;
}

int main()
{
    int j = 0;
    int taskCount = 0;
    char *ptr;

    ifstream file("tarefas.txt");
    if (file.is_open()){
        string line;
        getline(file, line);
        taskCount = stoi(line);
        struct Task TASKS[taskCount];
        
        while (getline(file, line)){
            readLine(line, &TASKS[j].name, &TASKS[j].start, &TASKS[j].time);
            j++;
        }
        roundRobin(TASKS, taskCount);
    }
    return 0;
}

