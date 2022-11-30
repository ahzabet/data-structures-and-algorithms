#ifndef LIST_H
#define LIST_H
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
// #include <sstream>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/reader.h>

using namespace std;

class Node
{
public:
    int id;
    string data;
    Node *next, *prev;

    Node();            // Node default constructor
    Node(string data); // Node parameterized constructor
};

class List
{
private:
    Node *head, *tail;

private:
    Node getNodebyId(int id);              // Returns the Node associated with the specified ID
    void setIds();                         // Sets the ID of each Node
    void insertNode(string data, Node *p); // Inserts a node after the specified Node *p
    void deleteNode(Node *p);              // Deletes a node
    string removeQuotes(string string);    // Removes quotes from the returned JSON string
    void displayCommands();                // Part of runProgram()
    void success();                        // Part of runProgram()

public:
    List();                                   // List default constructor
    void insertNodeById(int id, string data); // Inserts a node after the specified ID
    void push_front(string data);             // Inserts a node at the begining of the list
    void push_back(string data);              // Inserts a node at the end of the list
    void deleteNodeById(int id);              // Deletes a node by ID
    void deleteAllNodes();                    // Deletes all nodes
    void size();                              // Returns the number of elements in the list
    void sort();                              // Sorts the list
    bool empty();                             // Checks whether the list is empty or not
    void printNodeById(int id);               // Prints a node
    void print();                             // Prints the list
    void saveToFile(string fileName);         // Saves list to file
    void loadFromFile(string file);           // Loads a list from file
    void runProgram();                        // The method of methods
};

#endif
