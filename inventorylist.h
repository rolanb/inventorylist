//InventoryList.h
#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H
#include <iostream>
#include <string>

using namespace std;

class InventoryList{
  private:
    struct nodeType{
      string id;  // Item ID
      string desc;  // Item Description
      double price;  // Item Price
      nodeType *link;  // Pointer to next node
    };
    nodeType *first, *last, *current; 
  public:
    InventoryList();
    void addItem(string, string, double);
    void removeItem(string);
    void displayList();
};

InventoryList::InventoryList(){
  first = NULL;
};

void InventoryList::addItem(string id, string desc, double price){

  if(price > 1000 || price < 0){ // check if price is valid
    cout << "Error: part not added" << endl;
    return;
  }
  // Create new node
  nodeType *newNode = new nodeType;
  newNode->id = id;
  newNode->desc = desc;
  newNode->price = price;
  newNode->link = NULL;

  if(!first){ // Check if there is a node in the list
    first = newNode;
    last = newNode;
    cout << "Item added" << endl;
  }
  else{ // Add node to the end of the list
    current = first;
    while(current->link != NULL){
      current = current->link;
    }
    current->link = newNode; 
    last = newNode;  
    cout << "Item added" << endl;
  } 
}
void InventoryList::removeItem(string id){
  if(first == NULL){ // Check if list is empty
    cout << "Error: list is empty" << endl;
    //return;
    
  }
  nodeType *current = first; // Create a pointer to the first node
  

  if(current->id == id){ // Check if the first node is the one to be removed
    first = current->link;
    delete current;
    cout << "Item removed" << endl;
    return;
    
  }

  nodeType *previous = NULL; // Create a pointer to the previous node to conserve links

  while(current != NULL){

    // If current node is not the one to be removed, it assignes its value to the previous node and moves to the next node
    if(current->id != id){ 
      previous = current;
      current = current->link;
      continue;
    }
    else if(current->id == id){
      previous->link = current->link;
      delete current;
      cout << "Item removed" << endl;
      return;
    }
  
  }
  cout << "Error: item not found" << endl;
  
}

void InventoryList::displayList(){
  if(first == NULL){ // Check if list is empty
    cout << "Error: list is empty" << endl;
   // return;
    
  }
  else{
    nodeType *current = first;
    cout << "\nInventory List:\n" << endl;
    cout << "N.\tID\tDescription\tPrice" << endl;
    // Itereate through each node and print its values until end of list
    int count = 1;
    while(current){
      cout << count << ". " << current->id << "\t" << current->desc << "\t" << current->price << endl;
      current = current->link;
      count++;
    }
  }
}
  
#endif
