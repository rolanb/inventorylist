// Programmer: Rolan Belgrave
// Program Purposes: This program will implement a linked list data structure that holds inventory items and allows user to display, add and remove items from the list.
#include <iostream>
#include <string>
#include <vector>

#include "inventorylist.h"

using namespace std;

const string delimeter = "-"; // SWITCH TO " " NOTE: PROGRAM DOES NOT WORK WITH SPACE AS DELIMETER, IT MUST BE ANY OTHER CARRACTER LIKE COMMA, DASH, ETC.

vector<string> split(string, string); // Declaration of split function

double price;
string transaction, id_n, description; //Declare variable for strings
vector<string> input; // Declare vector to hold transaction orders


int main() {
  // Test transactions
  cout << "******************************************" << endl;
  cout << "*                TEST RUN                *" << endl;
  cout << "******************************************" << endl;
  InventoryList list;
  list.addItem("123", "Test1", 23.1);
  list.addItem("456", "Test2", 12.2);
  list.addItem("789", "Test3", 34.3);
  list.displayList();
  cout << "Test: removal of item with id 123" << endl;
  list.removeItem("123");
  list.displayList();
  list.removeItem("456");
  list.removeItem("789");
  
  cout << "*****************END OF TEST****************" << endl;
  cout << "\nOptions: \n" << "A. Add item (a-id-desc-value)\n" << "R. Remove item (r-id)\n" << "L. Display list\n" <<"Q. Quit\n" << endl; 
  while(true){
    cout << "\nEnter transaction: ";
    cin >> transaction;
    
    input = split(transaction, delimeter); //Split transaction into vector to assess each element
    
    //for (int i = 0; i < input.size(); i++) { // INPUT CHECK FOR DEBUGGING
     // cout << input[i] << endl;
    //}
    
    // add item if user enters A
    if (input[0] == "A" || input[0] == "a"){
      id_n = input[1];
      description = input[2];
      price = stod(input[3]);
 
      list.addItem(id_n, description, price);
      continue;
      }
    // remove item if user enters R
    else if (input[0] == "R" || input[0] == "r"){
      id_n = input[1];
      list.removeItem(id_n);
      continue;
    } 
    // display current list if user enters L
    else if (input[0] == "L" || input[0] == "l"){
      list.displayList();
      continue;
    }  
    // quit if user enters Q
    else if (input[0] == "Q" || input[0] == "q"){
      cout << "Exiting program" << endl;
      break;
    }
  }
  cout << "Program has been exited" << endl;
  return 0;
}


// Definition of Split() funtion to split commnan into tokens. 
vector<string> split(const string str, const string delimiter){
  
  vector<string> internal;
  
  size_t start=0, end = 0; // Declare variables for start and end of tokens
  while ((end = str.find(delimiter, start)) != string::npos){
    internal.push_back(str.substr(start, end - start)); // Add token to vector
    start = end + delimiter.length();// switch size to length
  }
  internal.push_back(str.substr(start)); // Add last token to vector
  return internal;
 
}
