#pragma once
#include <iostream>
#include <string>
#include "Player.h"
class Team {
public:
    int ID;
    string Name;
    string President;
    Team() {
        ID = 0;
        Name = "";
        President = "";
    }
};

class TeamNode {
public:
    Team data;
    TeamNode* next;
    TeamNode(Team team) {
        data = team;
        next = nullptr;
    }
};
class TeamLinkedList {
public:
    TeamNode* head;
    TeamLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addTeam(Team team) {
        TeamNode* newNode = new TeamNode(team);

        if (isEmpty()) {
            head = newNode;
        }
        else {
            TeamNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayTeam() {
        if (isEmpty()) {
            cout << "Empty Team" << endl;
            return;
        }
        else {
            TeamNode* currP = head;
            while (currP != nullptr) {
                cout << "ID: " << currP->data.ID << endl;
                cout << "Name: " << currP->data.Name << endl;
                cout << "President: " << currP->data.President << endl;
                cout << "-------------------" << endl;
                currP = currP->next;
            }
        }
    }

    void searchById(int ID) {
        if (isEmpty()) {
            cout << "The Team List is empty" << endl;
            return;
        }

        TeamNode* temp = head;

        while (temp != nullptr) {
            if (temp->data.ID == ID) {
                cout << "Name: " << temp->data.Name << endl;
                cout << "President: " << temp->data.President << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Team not found." << endl;
    }

    void removeTeam(int ID) {
        if (isEmpty()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->data.ID == ID) {
            TeamNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            cout << "Team removed successfully." << endl;
            return;
        }

        TeamNode* curr = head;
        TeamNode* prev = nullptr;

        while (curr != nullptr && curr->data.ID != ID) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Team with ID " << ID << " not found." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Team removed successfully." << endl;
    }

    void updateTeam(int ID, Team team) {
        if (isEmpty()) {
            cout << "The List is empty" << endl;
            return;
        }

        TeamNode* temp = head;

        while (temp != nullptr && temp->data.ID != ID) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Team with ID " << ID << " not found." << endl;
            return;
        }

        temp->data = team;
        cout << "The team with ID " << ID << " is successfully updated." << endl;
    }

    // ======== NEW BONUS: Average Age =========
    float getAverageAge(PlayerNode* playersHead, string teamName) {
        int sum = 0, count = 0;
        PlayerNode* p = playersHead;

        while (p != nullptr) {
            if (p->data.team == teamName) {
                sum += p->data.age;
                count++;
            }
            p = p->next;
        }

        if (count == 0) return 0;
        return (float)sum / count;
    }

    void displayTeamsOrderedByAverageAge(PlayerNode* playersHead) {

        struct TeamAvg {
            string name;
            float avg;
            TeamAvg* next;

            TeamAvg(string n, float a) {
                name = n;
                avg = a;
                next = nullptr;
            }
        };

        TeamAvg* sorted = nullptr;
        TeamNode* t = head;

        while (t != nullptr) {
            float avgAge = getAverageAge(playersHead, t->data.Name);
            TeamAvg* node = new TeamAvg(t->data.Name, avgAge);

            // insertion sort
            if (sorted == nullptr || node->avg < sorted->avg) {
                node->next = sorted;
                sorted = node;
            }
            else {
                TeamAvg* p = sorted;
                while (p->next != nullptr && p->next->avg < node->avg) {
                    p = p->next;
                }
                node->next = p->next;
                p->next = node;
            }

            t = t->next;
        }

        cout << "\nTeams ordered by average ages of players:\n\n";
        TeamAvg* p = sorted;

        while (p != nullptr) {
            cout << "Team: " << p->name
                << " | Average Age: " << p->avg << endl;
            TeamAvg* temp = p;
            p = p->next;
            delete temp;
        }

    }
};
