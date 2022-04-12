#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

#define OVERHEAD 1
#define QUANTUM 3

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
    int j = 0;
    int k = 0;
    int totalExecutionTime = 0;

    cout << "      ==== Round Robin ====      " << endl << endl;

    while(j < taskCount){
        for(int i=0; i < taskCount; i++){
            if(k<taskCount){
                totalExecutionTime += tasks[i].time;
                k++;
            }
            if(tasks[i].time > 0){  
                cout << "Executando: " << tasks[i].name << " Tempo restante: " << tasks[i].time << endl;
                tasks[i].time -= (QUANTUM - OVERHEAD);
                totalExecutionTime += OVERHEAD;
                if(tasks[i].time <= 0){
                    cout << tasks[i].name << " Finalizada!" << endl;
                    j++;
                }
            }
        }
    }
    cout << "Tempo total: " << totalExecutionTime << endl;
}

void shortestJobFirst(struct Task *tasks, int taskCount){
    
    cout << "  === Shortest Job First ===  " << endl << endl;
    
    int i, j;
    int totalExecutionTime = 0;

    for(i=0; i<taskCount; i++){
        for(j=0; j<taskCount-1; j++){
            if(tasks[j].time > tasks[j+1].time){
                struct Task tempTask = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = tempTask;      
            }
        }
    }
    for(i=0; i<taskCount; i++){
        cout << tasks[i].time << endl;
        totalExecutionTime++;
        for(j=tasks[i].time; j>0;j--){
            cout << "Executando: " << tasks[i].name << " Tempo restante: " << tasks[i].time << endl;
            totalExecutionTime++;
            tasks[i].time--;
        }
    }
    cout << endl;
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
        struct Task TASKSCOPY[taskCount];
        
        for(int c; c < taskCount; c++){
            TASKSCOPY[c] = TASKS[c];
        }

        
        roundRobin(TASKS, taskCount);
        cout << endl;
        shortestJobFirst(TASKSCOPY, taskCount);
    }
    return 0;
}

