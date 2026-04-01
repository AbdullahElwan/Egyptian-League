#pragma once
#include <iostream>
#include <string>
using namespace std;
class Player {
public:
    int ID;
    string Name;
    string team;
    string position;
    int age;
    float salary;

    Player() {
        ID = 0;
        Name = "";
        team = "";
        position = "";
        age = 0;
        salary = 0.0;
    }
};

class PlayerNode {
public:
    Player data;
    PlayerNode* next;
    PlayerNode(Player player) {
        data = player;
        next = nullptr;
    }
};

class PlayerLinkedList {
public:
    PlayerNode* head;
    PlayerLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }
    
    void addPlayer(Player player) {
        PlayerNode* newNode = new PlayerNode(player);

        if (isEmpty()) {
            head = newNode;
        }
        else {
            PlayerNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayPlayer() {
        if (isEmpty()) {
            cout << "Empty Player" << endl;
            return;
        }
        else {
            PlayerNode* currP = head;

            while (currP != nullptr) {
                cout << "ID: " << currP->data.ID << endl;
                cout << "Name: " << currP->data.Name << endl;
                cout << "Team: " << currP->data.team << endl;
                cout << "Position: " << currP->data.position << endl;
                cout << "Age: " << currP->data.age << endl;
                cout << "Salary: " << currP->data.salary << endl;
                cout << "-------------------" << endl;

                currP = currP->next;
            }
        }
    }

    void searchByName(string Name) {
        if (isEmpty()) {
            cout << "The Player List is empty" << endl;
            return;
        }

        PlayerNode* temp = head;

        while (temp != nullptr) {
            if (temp->data.Name == Name) {
                cout << "Name: " << temp->data.Name << endl;
                cout << "Team: " << temp->data.team << endl;
                cout << "Position: " << temp->data.position << endl;
                cout << "Age: " << temp->data.age << endl;
                cout << "Salary: " << temp->data.salary << endl;
                cout << "-------------------" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Player not found." << endl;
    }

    void removePlayer(int ID) {
        if (isEmpty()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->data.ID == ID) {
            PlayerNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            cout << "Player removed successfully." << endl;
            return;
        }

        PlayerNode* curr = head;
        PlayerNode* prev = nullptr;

        while (curr != nullptr && curr->data.ID != ID) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Player with ID " << ID << " not found." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Player removed successfully." << endl;
    }

    // BONUS: Sort Players by Salary
    void displayPlayersSortedBySalary(string teamName) {
        PlayerNode* curr = head;
        PlayerNode* sorted = nullptr;

        while (curr != nullptr) {
            if (curr->data.team == teamName) {
                PlayerNode* newNode = new PlayerNode(curr->data);

                if (sorted == nullptr || newNode->data.salary > sorted->data.salary) {
                    newNode->next = sorted;
                    sorted = newNode;
                }
                else {
                    PlayerNode* p = sorted;
                    while (p->next != nullptr && p->next->data.salary > newNode->data.salary) {
                        p = p->next;
                    }
                    newNode->next = p->next;
                    p->next = newNode;
                }
            }
            curr = curr->next;
        }

        if (sorted == nullptr) {
            cout << "No players found for this team." << endl;
            return;
        }

        cout << "\nPlayers of team '" << teamName << "' ordered by salary:\n";
        PlayerNode* p = sorted;
        while (p != nullptr) {
            cout << "ID: " << p->data.ID << " | Name: " << p->data.Name
                << " | Salary: " << p->data.salary << endl;

            PlayerNode* temp = p;
            p = p->next;
            delete temp;
        }
    }
};

