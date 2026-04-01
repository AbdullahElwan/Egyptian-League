# ⚽ Egyptian League Management System (Data Structures Project)

A high-performance **C++ console-based management system** designed to simulate core operations of the Egyptian Football League using **custom-built data structures**.

This project demonstrates strong fundamentals in **Data Structures & Algorithms**, object-oriented design, and efficient memory handling by implementing **linked lists from scratch** to manage teams and players dynamically.

---

## 🚀 Key Features

### 🏟️ Team Management

* Add, update, search, and delete teams
* Display all teams in a structured format
* Sort teams based on **average player age** *(advanced feature)*

### 👤 Player Management

* Add and manage player records
* Search players by name
* Remove players efficiently
* Display players sorted by **salary (descending)** *(bonus feature)*

---

## 🧠 Technical Highlights

* 💡 **Custom Linked List Implementation**

  * Separate linked lists for Teams and Players
  * Dynamic memory management without STL containers

* 🔍 **Efficient Searching Algorithms**

  * Search by Team ID and Player Name

* 🔄 **Sorting Techniques**

  * Insertion-based sorting for:

    * Player salaries
    * Team average ages

* 🧩 **Modular Design**

  * Clean separation of concerns across:

    * `Player.h / Player.cpp`
    * `Team.h / Team.cpp`
    * `main.cpp`

---

## 🏗️ System Architecture

* **TeamLinkedList** → Handles all team-related operations
* **PlayerLinkedList** → Manages player data and operations
* **Node-based structure** → Ensures efficient insertion & deletion

The system is fully interactive via a CLI menu interface, allowing users to simulate real-world league operations.

---

## 📂 Example Functional Flow

The application provides a structured menu system allowing users to:

* Insert new teams and players
* Perform search and update operations
* Execute sorting and analytics features

👉 Core interaction is handled through a menu-driven interface in


---

## 🎯 Why This Project Matters

This project showcases:

* Strong understanding of **Data Structures (Linked Lists)**
* Ability to build **scalable systems without relying on STL**
* Clean implementation of **real-world problem modeling**
* Practical use of **OOP principles in C++**

---

## 🛠️ Tech Stack

* **Language:** C++
* **Concepts:** Data Structures, OOP, Memory Management
* **Environment:** Console Application

---

## 🌟 Future Improvements

* Convert to GUI-based application
* Integrate database (SQL / NoSQL)
* Add match simulation and league standings
* Improve sorting with more advanced algorithms

---

## 👨‍💻 Author

Developed as a Data Structures project to demonstrate practical implementation of linked lists in a real-world scenario.

---

⭐ *If you found this project interesting, feel free to star the repo!*
