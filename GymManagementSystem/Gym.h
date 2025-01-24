#ifndef GYM_H
#define GYM_H

#include <string>
#include <vector>
#include <iostream>

class Member {
public:
    std::string name;
    std::string membershipType;
    double fee;
    bool isActive;

    Member(std::string name, std::string membershipType, double fee);
    void display();
};

class Trainer {
public:
    std::string name;
    int experience;

    Trainer(std::string name, int experience);
    void display();
};

class Equipment {
public:
    std::string name;
    bool isAvailable;
    int usageCount;  

    Equipment(std::string name);
    void display();
    void toggleAvailability();
    void incrementUsage();
};

class Schedule {
public:
    std::string workoutType;
    std::string trainerName;
    std::string time;

    Schedule(std::string workoutType, std::string trainerName, std::string time);
    void display();
};

class Billing {
public:
    double calculateBill(Member& member);
};

class Gym {
private:
    std::vector<Member> members;
    std::vector<Trainer> trainers;
    std::vector<Equipment> equipments;
    std::vector<Schedule> schedules;
    Billing billing;

public:
    void addMember(std::string name, std::string membershipType, double fee);
    void removeMember(std::string name);
    void updateMember(std::string name, std::string newMembershipType, double newFee);
    void addTrainer(std::string name, int experience);
    void addEquipment(std::string name);
    void addSchedule(std::string workoutType, std::string trainerName, std::string time);
    void assignTrainingSession(std::string memberName, std::string workoutType);
    void displayMembers();
    void displayTrainers();
    void displayEquipments();
    void displaySchedules();
    void searchMemberByName(std::string name);
    void generateReport();
    void generateBill(std::string memberName);
    void incrementEquipmentUsage(std::string equipmentName);
};

#endif // GYM_H
