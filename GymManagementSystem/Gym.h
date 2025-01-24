#ifndef GYM_H
#define GYM_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Member {
public:
    string name;
    string membershipType;
    double fee;
    bool isActive;

    Member(string name, string membershipType, double fee);
    void display();
};

class Trainer {
public:
    string name;
    int experience;

    Trainer(string name, int experience);
    void display();
};

class Equipment {
public:
    string name;
    bool isAvailable;
    int usageCount;  

    Equipment(string name);
    void display();
    void toggleAvailability();
    void incrementUsage();
};

class Schedule {
public:
    string workoutType;
    string trainerName;
    string time;

    Schedule(string workoutType, string trainerName, string time);
    void display();
};

class Billing {
public:
    double calculateBill(Member& member);
};

class Gym {
private:
    vector<Member> members;
    vector<Trainer> trainers;
    vector<Equipment> equipments;
    vector<Schedule> schedules;
    Billing billing;

public:
    void addMember(string name, string membershipType, double fee);
    void removeMember(string name);
    void updateMember(string name, string newMembershipType, double newFee);
    void addTrainer(string name, int experience);
    void addEquipment(string name);
    void addSchedule(string workoutType, string trainerName, string time);
    void assignTrainingSession(string memberName, string workoutType);
    void displayMembers();
    void displayTrainers();
    void displayEquipments();
    void displaySchedules();
    void searchMemberByName(string name);
    void generateReport();
    void generateBill(string memberName);
    void incrementEquipmentUsage(string equipmentName);
};

#endif // GYM_H
