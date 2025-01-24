#include "Gym.h"

//Member
Member::Member(string name, string membershipType, double fee)
    : name(name), membershipType(membershipType), fee(fee), isActive(true) {}

void Member::display() {
    cout << "Member: " << name << ", Membership Type: " << membershipType
        << ", Fee: $" << fee << ", Active: " << (isActive ? "Yes" : "No") << endl;
}

//Trainer
Trainer::Trainer(string name, int experience) : name(name), experience(experience) {}

void Trainer::display() {
    cout << "Trainer: " << name << ", Experience: " << experience << " years" << endl;
}

//Equipment 
Equipment::Equipment(string name) : name(name), isAvailable(true), usageCount(0) {}

void Equipment::display() {
    cout << "Equipment: " << name << ", Available: " << (isAvailable ? "Yes" : "No")
        << ", Usage Count: " << usageCount << endl;
}

void Equipment::toggleAvailability() {
    isAvailable = !isAvailable;
}

void Equipment::incrementUsage() {
    usageCount++;
}

//Schedule 
Schedule::Schedule(string workoutType, string trainerName, string time)
    : workoutType(workoutType), trainerName(trainerName), time(time) {}

void Schedule::display() {
    cout << "Workout: " << workoutType << ", Trainer: " << trainerName
        << ", Time: " << time << endl;
}

//Billing 
double Billing::calculateBill(Member& member) {
    if (member.membershipType == "Monthly") {
        return member.fee;
    }
    else if (member.membershipType == "Yearly") {
        return member.fee * 0.9;  
    }
    return 0;
}

//Gym Methods
void Gym::addMember(string name, string membershipType, double fee) {
    members.push_back(Member(name, membershipType, fee));
}

void Gym::removeMember(string name) {
    for (auto& member : members) {
        if (member.name == name) {
            member.isActive = false;
            cout << "Member " << name << " has been deactivated." << endl;
            return;
        }
    }
    cout << "Member not found!" << endl;
}

void Gym::updateMember(string name, string newMembershipType, double newFee) {
    for (auto& member : members) {
        if (member.name == name) {
            member.membershipType = newMembershipType;
            member.fee = newFee;
            cout << "Member " << name << " updated successfully." << endl;
            return;
        }
    }
    cout << "Member not found!" << endl;
}

void Gym::addTrainer(string name, int experience) {
    trainers.push_back(Trainer(name, experience));
}

void Gym::addEquipment(string name) {
    equipments.push_back(Equipment(name));
}

void Gym::addSchedule(string workoutType, string trainerName, string time) {
    schedules.push_back(Schedule(workoutType, trainerName, time));
}

void Gym::assignTrainingSession(string memberName, string workoutType) {
    cout << "Assigned " << workoutType << " session to member " << memberName << endl;
}

void Gym::displayMembers() {
    for (auto& member : members) {
        member.display();
    }
}

void Gym::displayTrainers() {
    for (auto& trainer : trainers) {
        trainer.display();
    }
}

void Gym::displayEquipments() {
    for (auto& equipment : equipments) {
        equipment.display();
    }
}

void Gym::displaySchedules() {
    for (auto& schedule : schedules) {
        schedule.display();
    }
}

void Gym::searchMemberByName(string name) {
    for (auto& member : members) {
        if (member.name == name) {
            member.display();
            return;
        }
    }
    cout << "Member not found!" << endl;
}

void Gym::generateReport() {
    cout << "\nGenerating report of active members:\n";
    for (auto& member : members) {
        if (member.isActive) {
            member.display();
        }
    }
}

void Gym::generateBill(string memberName) {
    for (auto& member : members) {
        if (member.name == memberName && member.isActive) {
            double billAmount = billing.calculateBill(member);
            cout << "Bill for " << member.name << ": $" << billAmount << endl;
            return;
        }
    }
    cout << "Member not found or inactive!" << endl;
}

void Gym::incrementEquipmentUsage(string equipmentName) {
    for (auto& equipment : equipments) {
        if (equipment.name == equipmentName) {
            equipment.incrementUsage();
            cout << "Equipment " << equipmentName << " usage count updated." << endl;
            return;
        }
    }
    cout << "Equipment not found!" << endl;
}
