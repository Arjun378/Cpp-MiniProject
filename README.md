# Cpp-MiniProject
# Library Management System with Hash Table

This is a simple Library Management System implemented in C++ using a Hash Table. It allows users to manage a collection of books and track which books have been issued to students.

## How It Works

- The program initializes a hash table with a certain capacity (initially set to 7).
- Users can choose from various options via a menu:
  1. **Display Books**: Lists all available books with their IDs.
  2. **Issue Book**: Lets students check out books. Users need to enter their Student PRN and the Book ID.
  3. **Return Book**: Allows students to return books based on their PRN.
  4. **Search for Student**: Users can search for students by PRN to find out which book they have issued.
  5. **Display Hash Table**: Shows the current state of the hash table, indicating which books are issued to which students.
  6. **Exit**: Quits the program.

- The program employs a hash table to efficiently store book records, including their titles and IDs.
- When a book is issued to a student, the system uses the student's PRN and the book's ID to store this information in the hash table.
- When a book is returned, the program removes the corresponding record.
- Users can view the status of the library, check which books are available, and find out who has issued a particular book.
- The program automatically handles the hash table's resizing to accommodate more records.

## How to Use

1. Compile the program using a C++ compiler.
2. Run the compiled program.
3. Follow the on-screen menu to perform library management actions.
