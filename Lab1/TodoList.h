#ifndef TODO_LIST_H
#define TODO_LIST_H
#include "TodoListInterface.h"


#include <vector>

using namespace std;

class TodoList: public TodoListInterface{
public:
    TodoList() {
        //cout << "In constructor" << endl;
        ifstream infile ("TODOList.txt");
        string line;
        if(infile.is_open()){
            while(getline(infile, line)){
                //cout << line << '\n';
                tasks.push_back(line);

            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        //cout << "In destructor" << endl;
        ofstream outfile;
        outfile.open("TODOList.txt", ofstream :: out | ofstream :: trunc);
        for(int i =0; i < tasks.size(); i++){
            outfile << tasks[i] << endl;
        } 

        outfile.close();
    }

    vector<string> tasks;
    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task){

        cout << "In add" << endl;
        cout << " _duedate " << _duedate << " task " << _task << endl; 
        tasks.push_back(_duedate + " "+_task);
        
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual void remove(string trash){ // changed from int to void 
        cout << "in remove" << endl;
        int index = 0; 
        for(index; index < tasks.size(); index++){
            if(tasks[index].find(trash) != string::npos){
                tasks.erase(tasks.begin()+index);
                break; 
            }

            // ofstream output("TODOList.txt");
            // for(int i = 0; i < tasks.size(); i++){
            //     output << tasks.at(i) << endl;
            // }
        }

    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList(){
        cout << "print to do list"<< tasks.size() << endl;
        for(int i = 0; i < tasks.size(); i++){
            cout <<i << " : " <<  tasks[i] << endl; 
        }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date){
        cout << "print tasks" << endl;
        int index = 0; 
        for(index; index < tasks.size(); index++){
            //cout << " day = " << tasks[index].substr(0, tasks[index].find(" ")) << endl;
            if(tasks[index].substr(0, tasks[index].find(" ")) == _date){
                cout << tasks[index] << endl;
            }
            
        }
    }
};

#endif