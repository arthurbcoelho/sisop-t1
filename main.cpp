#include <iostream>

using namespace std;

struct Task {
    int id;
    int start;
    int duration;
};

void initialiseTask(struct Task &t, int id, int start, int duration){
    t.id = id;
    t.start = start;
    t.duration = duration;
}

void roundRobin(struct Task *tasks, size_t n){

    int totalExecutionTime = 0;

    for(int i = 0; i < n; i++){
        totalExecutionTime += tasks[i].duration;
    }

    cout << totalExecutionTime << endl;
}

int main() {

    struct Task T1;
    struct Task T2;
    struct Task T3;
    struct Task T4;
    
    initialiseTask(T1, 1, 0, 8);
    initialiseTask(T2, 2, 1, 4);
    initialiseTask(T3, 3, 2, 9);
    initialiseTask(T4, 4, 3, 5);

    struct Task TASKS[] = {T1, T2, T3, T4}; // TODO

    roundRobin(TASKS, sizeof(TASKS) / sizeof(struct Task));
    
    return 0;
}