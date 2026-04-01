#include "Team.cpp"
#include "Player.cpp"
#include <string>
#include <iostream>
using namespace std;
int main() {
    TeamLinkedList teamList;
    PlayerLinkedList playerList;
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "   EGYPTIAN LEAGUE MANAGEMENT SYSTEM" << endl;
        cout << "========================================" << endl;
        cout << "1. Add Team" << endl;
        cout << "2. Display All Teams" << endl;
        cout << "3. Search Team by ID" << endl;
        cout << "4. Update Team" << endl;
        cout << "5. Remove Team (Bonus)" << endl;
        cout << "6. Display Teams Ordered by Average Ages (Bonus)" << endl;
        cout << "--------" << endl;
        cout << "7. Add Player" << endl;
        cout << "8. Display All Players" << endl;
        cout << "9. Search Player by Name" << endl;
        cout << "10. Remove Player" << endl;
        cout << "11. Display Players sorted by salary (Bonus)" << endl;
        cout << "--------" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Team newTeam;
            cout << "\n--- Add New Team ---" << endl;
            cout << "Enter Team ID: ";
            cin >> newTeam.ID;
            cin.ignore();
            cout << "Enter Team Name: ";
            getline(cin, newTeam.Name);
            cout << "Enter President Name: ";
            getline(cin, newTeam.President);
            teamList.addTeam(newTeam);
            cout << "Team added successfully!" << endl;
            break;
        }

        case 2: {
            cout << "\n--- All Teams ---" << endl;
            teamList.displayTeam();
            break;
        }

        case 3: {
            int searchID;
            cout << "\n--- Search Team ---" << endl;
            cout << "Enter Team ID: ";
            cin >> searchID;
            teamList.searchById(searchID);
            break;
        }

        case 4: {
            Team updatedTeam;
            cout << "\n--- Update Team ---" << endl;
            cout << "Enter Team ID to update: ";
            cin >> updatedTeam.ID;
            cin.ignore();
            cout << "Enter New Team Name: ";
            getline(cin, updatedTeam.Name);
            cout << "Enter New President Name: ";
            getline(cin, updatedTeam.President);
            teamList.updateTeam(updatedTeam.ID, updatedTeam);
            break;
        }

        case 5: {
            int removeID;
            cout << "\n--- Remove Team ---" << endl;
            cout << "Enter Team ID to remove: ";
            cin >> removeID;
            teamList.removeTeam(removeID);
            break;
        }
        case 6: {
            cout << "\n--- Teams Ordered by Average Ages ---\n";
            teamList.displayTeamsOrderedByAverageAge(playerList.head);
            break;
        }
        case 7: {
            Player newPlayer;
            cout << "\n--- Add New Player ---" << endl;
            cout << "Enter Player ID: ";
            cin >> newPlayer.ID;
            cin.ignore();
            cout << "Enter Player Name: ";
            getline(cin, newPlayer.Name);
            cout << "Enter Team Name: ";
            getline(cin, newPlayer.team);
            cout << "Enter Position: ";
            getline(cin, newPlayer.position);
            cout << "Enter Age: ";
            cin >> newPlayer.age;
            cout << "Enter Salary: ";
            cin >> newPlayer.salary;
            playerList.addPlayer(newPlayer);
            cout << "Player added successfully!" << endl;
            break;
        }

        case 8: {
            cout << "\n--- All Players ---" << endl;
            playerList.displayPlayer();
            break;
        }

        case 9: {
            string searchName;
            cout << "\n--- Search Player ---" << endl;
            cin.ignore();
            cout << "Enter Player Name: ";
            getline(cin, searchName);
            playerList.searchByName(searchName);
            break;
        }

        case 10: {
            int removeID;
            cout << "\n--- Remove Player ---" << endl;
            cout << "Enter Player ID to remove: ";
            cin >> removeID;
            playerList.removePlayer(removeID);
            break;
        }

        case 11: {
            string teamName;
            cout << "\n--- Enter Team Name ---" << endl;
            cin.ignore();
            getline(cin, teamName);
            playerList.displayPlayersSortedBySalary(teamName);
            break;
        }
        case 0:
            cout << "\nThank you for using the system. Goodbye!" << endl;
            break;

        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}