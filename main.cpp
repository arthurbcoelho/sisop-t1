#include <iostream>

using namespace std;

struct Task {
    int id;
    int start;
    int timeToComplete;
};

void initialiseTask(Task &t, int id, int start, int timeToComplete){
    t.id = id;
    t.start = start;
    t.timeToComplete = timeToComplete;
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

    cout << TASKS[0].id << endl;
    cout << T1.start << endl;
    cout << T1.timeToComplete << endl;

    return 0;
}