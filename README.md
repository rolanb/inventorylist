# Inventory List Management System

This repository contains a C++ program that implements a command-line-based inventory management system. It uses a **linked list** data structure to store inventory items, allowing users to interactively add, remove, and display items.

### Features

- **Linked List Data Structure**: Efficiently stores inventory items in a dynamic, chained list.
- **Interactive Command Line Interface**: Users can perform inventory transactions via simple commands.
- **Add Items**: Add new inventory items with an ID, description, and price.
- **Remove Items**: Delete items from the list by their ID.
- **Display List**: View all current items in the inventory.
- **Input Parsing**: Handles user commands by splitting a delimited string into usable data.

### Technologies Used

- **C++**: The core programming language used for the application.
- **Standard Template Library (STL)**: Utilizes `iostream`, `string`, and `vector` for input/output, string manipulation, and data handling.

### How to Build and Run the Project

This project requires a C++ compiler (like g++).

1.  **Clone the repository**:
    ```bash
    git clone [https://github.com/rolanb/inventorylist.git](https://github.com/rolanb/inventorylist.git)
    cd inventorylist
    ```

2.  **Compile the code**:
    Use a C++ compiler to compile the source files (`main.cpp` and `inventorylist.h`) into an executable.

    ```bash
    g++ main.cpp -o inventory
    ```

3.  **Run the executable**:
    After successful compilation, you can run the program from your terminal.

    ```bash
    ./inventory
    ```

### Usage

The program provides a simple command-line interface with the following options:

-   **Add item**: `A-id-description-price`
-   **Remove item**: `R-id`
-   **Display list**: `L`
-   **Quit**: `Q`

**Example Transaction**:

  ```bash
    Enter transaction: A-123-Widget-50.75
    Item added
  ```

### Known Issues

-   The program does not support spaces within the transaction delimiter. The delimiter must be a single character (e.g., `-`).
-   The "remove" and "display" functions may produce an error message if the list is empty.

### Contribution

Feel free to open issues or submit pull requests if you find bugs or have suggestions for improvements.
