#include "Gym.h"

//Member
Member::Member(std::string name, std::string membershipType, double fee)
    : name(name), membershipType(membershipType), fee(fee), isActive(true) {}

void Member::display() {
    std::cout << "Member: " << name << ", Membership Type: " << membershipType
        << ", Fee: $" << fee << ", Active: " << (isActive ? "Yes" : "No") << std::endl;
}

//Trainer
Trainer::Trainer(std::string name, int experience) : name(name), experience(experience) {}

void Trainer::display() {
    std::cout << "Trainer: " << name << ", Experience: " << experience << " years" << std::endl;
}

//Equipment 
Equipment::Equipment(std::string name) : name(name), isAvailable(true), usageCount(0) {}

void Equipment::display() {
    std::cout << "Equipment: " << name << ", Available: " << (isAvailable ? "Yes" : "No")
        << ", Usage Count: " << usageCount << std::endl;
}

void Equipment::toggleAvailability() {
    isAvailable = !isAvailable;
}

void Equipment::incrementUsage() {
    usageCount++;
}

//Schedule 
Schedule::Schedule(std::string workoutType, std::string trainerName, std::string time)
    : workoutType(workoutType), trainerName(trainerName), time(time) {}

void Schedule::display() {
    std::cout << "Workout: " << workoutType << ", Trainer: " << trainerName
        << ", Time: " << time << std::endl;
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
void Gym::addMember(std::string name, std::string membershipType, double fee) {
    members.push_back(Member(name, membershipType, fee));
}

void Gym::removeMember(std::string name) {
    for (auto& member : members) {
        if (member.name == name) {
            member.isActive = false;
            std::cout << "Member " << name << " has been deactivated." << std::endl;
            return;
        }
    }
    std::cout << "Member not found!" << std::endl;
}

void Gym::updateMember(std::string name, std::string newMembershipType, double newFee) {
    for (auto& member : members) {
        if (member.name == name) {
            member.membershipType = newMembershipType;
            member.fee = newFee;
            std::cout << "Member " << name << " updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Member not found!" << std::endl;
}

void Gym::addTrainer(std::string name, int experience) {
    trainers.push_back(Trainer(name, experience));
}

void Gym::addEquipment(std::string name) {
    equipments.push_back(Equipment(name));
}

void Gym::addSchedule(std::string workoutType, std::string trainerName, std::string time) {
    schedules.push_back(Schedule(workoutType, trainerName, time));
}

void Gym::assignTrainingSession(std::string memberName, std::string workoutType) {
    std::cout << "Assigned " << workoutType << " session to member " << memberName << std::endl;
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

void Gym::searchMemberByName(std::string name) {
    for (auto& member : members) {
        if (member.name == name) {
            member.display();
            return;
        }
    }
    std::cout << "Member not found!" << std::endl;
}

void Gym::generateReport() {
    std::cout << "\nGenerating report of active members:\n";
    for (auto& member : members) {
        if (member.isActive) {
            member.display();
        }
    }
}

void Gym::generateBill(std::string memberName) {
    for (auto& member : members) {
        if (member.name == memberName && member.isActive) {
            double billAmount = billing.calculateBill(member);
            std::cout << "Bill for " << member.name << ": $" << billAmount << std::endl;
            return;
        }
    }
    std::cout << "Member not found or inactive!" << std::endl;
}

void Gym::incrementEquipmentUsage(std::string equipmentName) {
    for (auto& equipment : equipments) {
        if (equipment.name == equipmentName) {
            equipment.incrementUsage();
            std::cout << "Equipment " << equipmentName << " usage count updated." << std::endl;
            return;
        }
    }
    std::cout << "Equipment not found!" << std::endl;
}
