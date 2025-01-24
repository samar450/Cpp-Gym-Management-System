#include <iostream>
#include "Gym.h"

void displayMenu() {
    cout << "\n===== Welcome to the Gym Management System =====\n";
    cout << "1. Add Member\n";
    cout << "2. Remove Member\n";
    cout << "3. Update Member\n";
    cout << "4. Add Trainer\n";
    cout << "5. Add Equipment\n";
    cout << "6. Add Schedule\n";
    cout << "7. Display Members\n";
    cout << "8. Display Trainers\n";
    cout << "9. Display Equipments\n";
    cout << "10. Search Member\n";
    cout << "11. Generate Report of Active Members\n";
    cout << "12. Generate Bill\n";
    cout << "13. Increment Equipment Usage\n";
    cout << "14. Exit\n";
    cout << "===================================\n";
    cout << "Enter your choice (1-14): ";
}

int main() {
    Gym gym;
    int choice;
    string name, membershipType, trainerName, workoutType, time, equipmentName;
    double fee;
    int experience;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter member name: ";
            cin >> name;
            cout << "Enter membership type (Monthly/Yearly): ";
            cin >> membershipType;
            cout << "Enter fee: ";
            cin >> fee;
            gym.addMember(name, membershipType, fee);
            cout << "Member added successfully!" << endl;
            break;

        case 2:
            cout << "Enter member name to remove: ";
            cin >> name;
            gym.removeMember(name);
            break;

        case 3:
            cout << "Enter member name to update: ";
            cin >> name;
            cout << "Enter new membership type: ";
            cin >> membershipType;
            cout << "Enter new fee: ";
            cin >> fee;
            gym.updateMember(name, membershipType, fee);
            break;

        case 4:
            cout << "Enter trainer name: ";
            cin >> name;
            cout << "Enter experience in years: ";
            cin >> experience;
            gym.addTrainer(name, experience);
            cout << "Trainer added successfully!" << endl;
            break;

        case 5:
            cout << "Enter equipment name: ";
            cin >> name;
            gym.addEquipment(name);
            cout << "Equipment added successfully!" << endl;
            break;

        case 6:
            cout << "Enter workout type: ";
            cin >> workoutType;
            cout << "Enter trainer name: ";
            cin >> trainerName;
            cout << "Enter time: ";
            cin >> time;
            gym.addSchedule(workoutType, trainerName, time);
            cout << "Schedule added successfully!" << endl;
            break;

        case 7:
            gym.displayMembers();
            break;

        case 8:
            gym.displayTrainers();
            break;

        case 9:
            gym.displayEquipments();
            break;

        case 10:
            cout << "Enter member name to search: ";
            cin >> name;
            gym.searchMemberByName(name);
            break;

        case 11:
            gym.generateReport();
            break;

        case 12:
            cout << "Enter member name to generate bill: ";
            cin >> name;
            gym.generateBill(name);
            break;

        case 13:
            cout << "Enter equipment name to increment usage: ";
            cin >> equipmentName;
            gym.incrementEquipmentUsage(equipmentName);
            break;

        case 14:
            cout << "Exiting the system..." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
