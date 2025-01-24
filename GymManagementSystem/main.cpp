#include <iostream>
#include "Gym.h"

void displayMenu() {
    std::cout << "\n===== Gym Management System =====\n";
    std::cout << "1. Add Member\n";
    std::cout << "2. Remove Member\n";
    std::cout << "3. Update Member\n";
    std::cout << "4. Add Trainer\n";
    std::cout << "5. Add Equipment\n";
    std::cout << "6. Add Schedule\n";
    std::cout << "7. Display Members\n";
    std::cout << "8. Display Trainers\n";
    std::cout << "9. Display Equipments\n";
    std::cout << "10. Search Member\n";
    std::cout << "11. Generate Report of Active Members\n";
    std::cout << "12. Generate Bill\n";
    std::cout << "13. Increment Equipment Usage\n";
    std::cout << "14. Exit\n";
    std::cout << "===================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Gym gym;
    int choice;
    std::string name, membershipType, trainerName, workoutType, time, equipmentName;
    double fee;
    int experience;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter member name: ";
            std::cin >> name;
            std::cout << "Enter membership type (Monthly/Yearly): ";
            std::cin >> membershipType;
            std::cout << "Enter fee: ";
            std::cin >> fee;
            gym.addMember(name, membershipType, fee);
            std::cout << "Member added successfully!" << std::endl;
            break;

        case 2:
            std::cout << "Enter member name to remove: ";
            std::cin >> name;
            gym.removeMember(name);
            break;

        case 3:
            std::cout << "Enter member name to update: ";
            std::cin >> name;
            std::cout << "Enter new membership type: ";
            std::cin >> membershipType;
            std::cout << "Enter new fee: ";
            std::cin >> fee;
            gym.updateMember(name, membershipType, fee);
            break;

        case 4:
            std::cout << "Enter trainer name: ";
            std::cin >> name;
            std::cout << "Enter experience in years: ";
            std::cin >> experience;
            gym.addTrainer(name, experience);
            std::cout << "Trainer added successfully!" << std::endl;
            break;

        case 5:
            std::cout << "Enter equipment name: ";
            std::cin >> name;
            gym.addEquipment(name);
            std::cout << "Equipment added successfully!" << std::endl;
            break;

        case 6:
            std::cout << "Enter workout type: ";
            std::cin >> workoutType;
            std::cout << "Enter trainer name: ";
            std::cin >> trainerName;
            std::cout << "Enter time: ";
            std::cin >> time;
            gym.addSchedule(workoutType, trainerName, time);
            std::cout << "Schedule added successfully!" << std::endl;
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
            std::cout << "Enter member name to search: ";
            std::cin >> name;
            gym.searchMemberByName(name);
            break;

        case 11:
            gym.generateReport();
            break;

        case 12:
            std::cout << "Enter member name to generate bill: ";
            std::cin >> name;
            gym.generateBill(name);
            break;

        case 13:
            std::cout << "Enter equipment name to increment usage: ";
            std::cin >> equipmentName;
            gym.incrementEquipmentUsage(equipmentName);
            break;

        case 14:
            std::cout << "Exiting the system..." << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    return 0;
}
