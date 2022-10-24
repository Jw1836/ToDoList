#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoList.h"


using namespace std; 
vector<string> readIn(){
    ifstream input;
    vector<string> v;
    input.open("TODOList.txt"); 
    if(!input){
        cout << "ERROR" << endl;
        exit(-1);
    }
    while(!input.eof()){
        string s; 
        getline(input, s);
        if(s.length() >= 2){
            v.push_back(s);
        }
    }
    input.close();
    return v; 

}
int main(int argc, char *argv[]){

    TodoList myList; 
    // ofstream output; 
    // output.open("TODOList.txt");
    
    vector<string> v = readIn();
    string command = argv[1];

    if(command == "add"){

       string date = argv[2];
       string task = argv[3];
       myList.add(date, task); 
    
    } 
    else if(command == "remove"){
        string trash = argv[2]; 
        if(argc < 2){
            cout << "error" << endl;
        }
        myList.remove(trash);
    
    }
    else if(command == "printList"){
        myList.printTodoList();
    }
    else if(command == "printDay"){
        string day = argv[2];
        myList.printDaysTasks(day);
    }



return 0; 


}
