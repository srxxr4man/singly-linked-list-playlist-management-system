# 🎵 Playlist Management System (C++)

## 📌 Description

This project is an interactive, console-based **Music Playlist Management System** implemented in C++ using a custom **Singly Linked List** data structure.

It demonstrates fundamental memory management and pointer manipulation concepts without relying on high-level STL containers like `std::vector` or `std::list`. The program is beginner-friendly, clean, and serves as an educational blueprint for Data Structures and Algorithms (DSA).

---

## 🚀 Features

* ➕ **Flexible Insertion:** Add songs to the front, end, or after a specific Song ID
* ❌ **Safe Deletion:** Remove tracks from the front, end, or by targeted Song ID
* 📋 **Dynamic Display:** Visualizes current playlist nodes and pointer links
* 🧠 **Manual Memory Management:** Allocates and frees nodes cleanly on the heap
* 💻 **Interactive CLI:** Easy-to-use numbered menu inside the terminal

---

## 🛠️ Technologies Used

* C++ (C++11 or higher recommended)
* Standard Input/Output Stream (`<iostream>`)
* Dynamic Memory Allocation (`new` / `delete`)

---

## ⚙️ How It Works

* Each song is represented as an independent node holding:
  * Unique Song ID (`int`)
  * Song Title (`string`)
  * Artist Name (`string`)
  * Pointer to the next track (`Song* next`)
* Pointer operations update links dynamically:
  * Adding to front prepends the node and updates `head` in $O(1)$ time.
  * Adding to back traverses until `next == NULL` and appends in $O(n)$ time.
  * Specific removals bypass the target node and free its memory using `delete`.

---

## 🎯 Purpose

This project was created to:

* Understand pointers and node referencing in low-level memory
* Implement custom Linked List CRUD operations from scratch
* Avoid memory leaks through explicit node deletion
* Build a foundational stepping stone toward complex linear data structures

---

## 🖥️ Example

```text
Playlist Management System
----------------------------
1. Add a Song at Front
2. Add a Song at Back
3. Add a Song after specified Song ID
4. Display Playlist
5. Delete a Song from Front
6. Delete a Song from Back
7. Delete a Song with Song ID
8. Exit

Enter the Choice: 4
| ID: 101 | Name: Bohemian Rhapsody | Artist: Queen |  -> | ID: 102 | Name: Hotel California | Artist: Eagles |  -> NULL
