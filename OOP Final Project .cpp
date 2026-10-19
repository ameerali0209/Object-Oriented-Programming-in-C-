/* --------------------------------------
    OOP FINAL PROJECT
-----------------------------------------
   2025-AI-487  Muhammad Haseeb Saleem
   2025-AI-457  Ameer Ali
---------------------------------------*/
/* Class/Functions   |    line
int main ()               1797
void mainInterface ()     1745
void delDynamicMemory ()  1734
void loadAllData ()       1709
void loginBlock ()        1620
void registrationBlock () 1568
void adminMenu ()         1107
void userMenu ()          979
void driverMenu ()        868
Template classes          833
Global variables          801
Class FileManager         497
Class TransportManager    448
Class Report              409
Class Bill                327
Class Pass                267
Class Route               208
Class Vehicle             169
Class Driver              127
Class Staff               89
Class Student             42
Class User                18
*/
//-----------------------------------------CODE START FROM HERE------------------------------------------------------------------------------
#include <iostream>
#include <window.h>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 20;

// ============================================
//                  CLASSES 
// ============================================ 
class User { 
protected:
    int    id         ;
    string name       ;
    string password   ;
public:
    User() {
        id = 0;
    }

    void setId(int i)           { id       = i; }
    void setName(string n)      { name     = n; }
    void setPassword(string p)  { password = p; }

    int    getId()       { return id; }
    string getName()     { return name; }
    string getPassword() { return password; }

    virtual void showInfo() = 0;
    virtual string getRole() = 0;

    virtual ~User() {}
};

class Student : public User {
private:
    string regNo  ;
    int    hasPass;

public:
    Student() {
        hasPass = 0;
    }

    void setRegNo(string r)   { regNo   = r; }
    void setHasPass(int h)    { hasPass = h; }

    string getRegNo()   { return regNo; }
    int    getHasPass() { return hasPass; }
    
    Student(const Student& other) {
        id      = other.id       ;
        name    = other.name     ;
        password= other.password ;
        regNo   = other.regNo    ;
        hasPass = other.hasPass  ;
    } 

    Student& operator=(const Student& other) {
        if (this != &other) {
            id      = other.id       ;
            name    = other.name     ;
            password= other.password ;
            regNo   = other.regNo    ;
            hasPass = other.hasPass  ;
        }
    return *this;
   }

   string getRole() override { return "Student"; }

    void showInfo() override {
        cout << " | ID   : "    << id      << endl
             << " | Name : "  << name    << endl
             << " | RegNo: " << regNo   << endl
             << " | Pass : "  << (hasPass ? "YES" : "NO")
             << endl;
       cout << "\n-----------------------------\n";
    }
};

class Staff : public User {
private:
    string designation;

public:
    Staff() {}

    void setDesignation(string d)  { designation = d; }
    string getDesignation()        { return designation; }

    string getRole()  { return "Staff"; }

    void showInfo()  {
        cout << " | ID: "           << id          << endl
             << " | Name: "        << name         << endl
             << " | Designation: " << designation  << endl;
        cout << "\n-----------------------------\n";
    }
    
    Staff(const Staff& other) {
        id          = other.id          ;
        name        = other.name        ;
        password    = other.password    ;
        designation = other.designation ;  
   }

    Staff& operator=(const Staff& other) {
        if (this != &other) {
            id          = other.id           ;
            name        = other.name         ;
            password    = other.password     ;
            designation = other.designation  ;
        }
        return *this;
   }

};

class Driver : public User {
private:
    int assignedVehicleId;  

public:
    Driver() {
        assignedVehicleId = -1;
    }

    void setAssignedVehicleId(int v) { assignedVehicleId = v; }
    int  getAssignedVehicleId()      { return assignedVehicleId; }
    
    Driver(const Driver& other) {
        id               = other.id;
        name             = other.name;
        password         = other.password;
        assignedVehicleId = other.assignedVehicleId;
    }

    Driver& operator=(const Driver& other) {
        if (this != &other) {
            id               = other.id;
            name             = other.name;
            password         = other.password;
            assignedVehicleId = other.assignedVehicleId;
        }
        return *this;
    }

    string getRole()  { return "Driver"; }

    void showInfo()  { 
        cout << " | ID      : "   << id            << endl
             << " | Name    : "   << name          << endl
             << " | Password: "   << getPassword() << endl
             << " | Vehicle ID: "
             << (assignedVehicleId == -1 ? "Not Assigned To You" : to_string(assignedVehicleId))
             << endl;
        cout << "\n-----------------------------\n";
    }
};

class Vehicle {
private:
    int    vid       ;
    string plate     ;
    int    capacity  ;
    int    seatsUsed ;
    string type      ;   

public:

    Vehicle() {
        vid       = 0;
        capacity  = 0;
        seatsUsed = 0;
    }

    void setVid(int v)          { vid       = v; }
    void setPlate(string p)     { plate     = p; }
    void setCapacity(int c)     { capacity  = c; }
    void setSeatsUsed(int s)    { seatsUsed = s; }
    void setType(string t)      { type      = t; }

    int    getVid()       { return vid; }
    string getPlate()     { return plate; }
    int    getCapacity()  { return capacity; }
    int    getSeatsUsed() { return seatsUsed; }
    string getType()      { return type; }

    void showInfo() {
        cout << "  ID: "       << vid
             << " | Plate: "   << plate
             << " | Type: "    << type
             << " | Seats: "   << seatsUsed 
			 << "/" << capacity
             << endl;
        
    }
};

class Route {
private:
    int    rid;
    string startPoint;
    string endPoint;
    float  distance;
    int    vehicleId;   

public:
    Route() {
        rid       = 0;
        distance  = 0;
        vehicleId =-1;
    }

    void setRid(int r)             { rid        = r; }
    void setStartPoint(string s)   { startPoint = s; }
    void setEndPoint(string e)     { endPoint   = e; }
    void setDistance(float d)      { distance   = d; }
    void setVehicleId(int v)       { vehicleId  = v; }

    int    getRid()        { return rid; }
    string getStartPoint() { return startPoint; }
    string getEndPoint()   { return endPoint; }
    float  getDistance()   { return distance; }
    int    getVehicleId()  { return vehicleId; }

    float monthlyFee() { return distance * 50.0; }

    void showInfo() {
        cout << "  Route ID: "  << rid
             << " | "           << startPoint
             << " --> "         << endPoint
             << " | "           << distance 
			 << " km"
             << " | Fee: Rs "   << monthlyFee()
             << " | VehicleID: "<< (vehicleId == -1 ? "None" : to_string(vehicleId))
             << endl;
        
    }
    
   bool operator<(const Route& other) const {
      return distance < other.distance;
   }

   bool operator==(const Route& other) const {
      return rid == other.rid;
   }

   friend ostream& operator<<(ostream& out, Route& r) {
        cout << "Route[" << r.rid << "]: "
        << r.startPoint << " --> " << r.endPoint
        << " | " << r.distance << " km"
        << " | Fee: Rs " << r.monthlyFee();
     return out;
    }

};

class Pass {
private:
    int    passId     ;
    int    studentId  ;
    int    routeId    ;
    string status     ;  
    float  fee        ;
    int    paid       ;   

public:

    Pass() {
        passId    = 0;
        studentId = 0;
        routeId   = 0;
        status    = "pending";
        fee       = 0;
        paid      = 0;
    }

    void setPassId(int p)    { passId    = p; }
    void setStudentId(int s) { studentId = s; }
    void setRouteId(int r)   { routeId   = r; }
    void setStatus(string s) { status    = s; }
    void setFee(float f)     { fee       = f; }
    void setPaid(int p)      { paid      = p; }

    int    getPassId()    { return passId; }
    int    getStudentId() { return studentId; }
    int    getRouteId()   { return routeId; }
    string getStatus()    { return status; }
    float  getFee()       { return fee; }
    int    getPaid()      { return paid; }

    void showInfo() {
        cout << "  PassID: "    << passId
        << " | Student: "  << studentId
	    << " | Route: "    << routeId
        << " | Status: "   << status
        << " | Fee: Rs "   << fee
        << " | Paid: "     << (paid ? "YES" : "NO")
        << endl;
   }
    
    bool operator==(const Pass& other) const {
        return passId == other.passId;
   }

    friend ostream& operator<<(ostream& out, Pass& p) {
        cout << "Pass[" << p.passId << "]"
        << " Student:" << p.studentId
        << " Route:"   << p.routeId
        << " Status:"  << p.status
        << " Fee:Rs "  << p.fee
        << " Paid:"    << (p.paid ? "YES" : "NO");
      return out;
   }

};
 
class Bill {
private:
    int    billId   ;
    Pass   pass     ;       
    float  totalFee ;
    string dueDate  ;
    int    isPaid   ;

public:
    Bill() {
        billId   = 0     ;
        totalFee = 0     ;
        isPaid   = 0     ;
        dueDate  = "N/A" ;
    }

    Bill(int bid, Pass p, string date) {
        billId   = bid          ;
        pass     = p            ;
        totalFee = p.getFee()   ;
        dueDate  = date         ;
        isPaid   = p.getPaid()  ;
    }

    Bill(const Bill& other) {
        billId   = other.billId   ;
        pass     = other.pass     ;
        totalFee = other.totalFee ;
        dueDate  = other.dueDate  ;
        isPaid   = other.isPaid   ;
    }

    Bill& operator=(const Bill& other) {
        if (this != &other) {
            billId   = other.billId   ;
            pass     = other.pass     ;
            totalFee = other.totalFee ;
            dueDate  = other.dueDate  ;
            isPaid   = other.isPaid   ;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, Bill& b) {
        out << "Bill[" << b.billId << "]"
            << " PassID:" << b.pass.getPassId()
            << " Fee:Rs " << b.totalFee
            << " Due:"    << b.dueDate
            << " Paid:"   << (b.isPaid ? "YES" : "NO");
        return out;
    }

    void setBillId(int b)    { billId  = b; }
    void setDueDate(string d){ dueDate = d; }
    void setIsPaid(int p)    { isPaid  = p; }

    int    getBillId()   { return billId;   }
    float  getTotalFee() { return totalFee; }
    string getDueDate()  { return dueDate;  }
    int    getIsPaid()   { return isPaid;   }

    void showInfo() {
        cout << "  BillID: "  << billId
             << " | PassID: " << pass.getPassId()
             << " | Fee: Rs " << totalFee
             << " | Due: "    << dueDate
             << " | Paid: "   << (isPaid ? "YES" : "NO")
             << endl;
    }
    
    float calculateLateFee(bool isOverdue) {
        if (!isPaid && isOverdue) {
            float lateFee = toatalFee * 0.10f;  // 10% fine
            totalFee = totalFee + lateFee;
            cout << "  Late fee applied Because you did not pay your fee on time! Extra Rs " << lateFee << endl;
            return lateFee;
        }
       return 0;
   } 
};


class Report {
public:
    void routeWiseReport(Pass passes[], int passCount,
                         Route routes[], int routeCount) {
        cout << "\n-----------------------------\n"
             << "      Route-Wise Report      \n"
             << "-----------------------------\n";
        for (int i = 0; i < routeCount; i++) {
            int count = 0;
            for (int j = 0; j < passCount; j++) {
                if (passes[j].getRouteId()  == routes[i].getRid() &&
                    passes[j].getStatus()   == "approved")
                    count++;
            }
            cout << "  Route " << routes[i].getRid()
                 << " (" << routes[i].getStartPoint()
                 << " --> " << routes[i].getEndPoint()
                 << ") : " << count << " students\n";
        }
    }

    void revenueReport(Pass passes[], int passCount) {
        float total = 0;
        int   paid  = 0;
        cout << "\n-----------------------------\n"
             << "       Revenue Report        \n"
             << "-----------------------------\n";
        for (int i = 0; i < passCount; i++) {
            if (passes[i].getStatus() == "approved") {
                total += passes[i].getFee();
                if (passes[i].getPaid()) paid++;
            }
        }
        cout << "  Total Expected Revenue : Rs " << total << endl
             << "  Paid Students          : "    << paid  << endl
             << "  Unpaid Students        : "    << (passCount - paid) << endl;
    }
};
/*
class TransportManager {
private:
    string managerName   ;
    Vehicle* vehicleList ;   
    Route*   routeList   ;     
    int*     vCount      ;
    int*     rCount      ;

public:
    TransportManager(string name,
                     Vehicle* vArr, int* vc,
                     Route*   rArr, int* rc) {
        managerName = name;
        vehicleList = vArr;
        routeList   = rArr;
        vCount      = vc  ;
        rCount      = rc  ;
    }

    ~TransportManager() {}

    string getName() { return managerName; }

    bool assignVehicleToRoute(int routeId, int vehicleId) {
        for (int i = 0; i < *rCount; i++) {
            if (routeList[i].getRid() == routeId) {
                routeList[i].setVehicleId(vehicleId);
                cout << "  Vehicle " << vehicleId
                     << " Assigned to Route " << routeId << endl;
                return true;
            }
        }
        cout << "  Route not found.\n";
        return false;
    }

    void showAllVehicles() {
        cout << "\n| Vehicles under " << managerName << " |\n";
        for (int i = 0; i < *vCount; i++)
            vehicleList[i].showInfo();
    }

    void showAllRoutes() {
        cout << "\n| Routes under " << managerName << " |\n";
        for (int i = 0; i < *rCount; i++)
            routeList[i].showInfo();
    }
};
*/
class FileManager {
private:
    string studentFile;
    string staffFile;
    string vehiclesFile;
    string routesFile;
    string passesFile;
    string driverFile;

    void checkFile(string filename) {
        ifstream f(filename);
        if (f.is_open()) {
            cout << "  [EXISTS]  " << filename << endl;
            f.close();
        } else {
            cout << "  [MISSING] " << filename << endl;
        }
        cout << "-----------------------------\n";
    }

public:
    FileManager() {
        studentFile  = "student.txt" ;
        staffFile    = "staff.txt"   ;
        vehiclesFile = "vehicles.txt";
        routesFile   = "routes.txt"  ;
        passesFile   = "passes.txt"  ;
        driverFile   = "drivers.txt" ;
    }
    
    ~FileManager() {}

    void saveStudents(Student students[], int count) {
        ofstream file(studentFile);
        if (!file.is_open()) {
            cout << "  ERROR: Cannot open " << studentFile << endl;
            return;
        }
        file << count << "\n";
        for (int i = 0; i < count; i++) {
            file << students[i].getId()       << "\n";
            file << students[i].getName()     << "\n";
            file << students[i].getPassword() << "\n";
            file << students[i].getRegNo()    << "\n";
            file << students[i].getHasPass()  << "\n";
        }
        file.close();
        cout << "\n-----------------------------\n";
        cout << "1.Students Saved to " << studentFile << endl;
    }

    void saveStaff(Staff staffArr[], int count) {
        ofstream file(staffFile);
        if (!file.is_open()) {
            cout << "  ERROR: Cannot open " << staffFile << endl;
            return;
        }
        file << count << "\n";
        for (int i = 0; i < count; i++) {
            file << staffArr[i].getId()           << "\n";
            file << staffArr[i].getName()         << "\n";
            file << staffArr[i].getPassword()     << "\n";
            file << staffArr[i].getDesignation()  << "\n";
        }
        file.close();
        cout << "2.Staff    Saved to " << staffFile << endl;
    }

    void saveVehicles(Vehicle vehicles[], int count) {
        ofstream file(vehiclesFile);
        if (!file.is_open()) {
            cout << "  ERROR: Cannot open " << vehiclesFile << endl;
            return;
        }
        file << count << "\n";
        for (int i = 0; i < count; i++) {
            file << vehicles[i].getVid()       << "\n";
            file << vehicles[i].getPlate()     << "\n";
            file << vehicles[i].getCapacity()  << "\n";
            file << vehicles[i].getSeatsUsed() << "\n";
            file << vehicles[i].getType()      << "\n";
        }
        file.close();
        cout << "3.Vehicles Saved to " << vehiclesFile << endl;
    }

    void saveRoutes(Route routes[], int count) {
        ofstream file(routesFile);
        if (!file.is_open()) {
            cout << "  ERROR: Cannot open " << routesFile << endl;
            return;
        }
        file << count << "\n";
        for (int i = 0; i < count; i++) {
            file << routes[i].getRid()        << "\n";
            file << routes[i].getStartPoint() << "\n";
            file << routes[i].getEndPoint()   << "\n";
            file << routes[i].getDistance()   << "\n";
            file << routes[i].getVehicleId()  << "\n";
        }
        file.close();
        cout << "4.Routes   Saved to " << routesFile << endl;
    }

    void savePasses(Pass passes[], int count) {
        ofstream file(passesFile);
        if (!file.is_open()) {
            cout << "  ERROR: Cannot open " << passesFile << endl;
            return;
        }
        file << count << "\n";
        for (int i = 0; i < count; i++) {
            file << passes[i].getPassId()    << "\n";
            file << passes[i].getStudentId() << "\n";
            file << passes[i].getRouteId()   << "\n";
            file << passes[i].getStatus()    << "\n";
            file << passes[i].getFee()       << "\n";
            file << passes[i].getPaid()      << "\n";
        }
        file.close();
        cout << "5.Passes   Saved to " << passesFile << endl;
    }
    
    void saveDrivers(Driver drivers[], int count) {
       ofstream file("drivers.txt");
       if (!file.is_open()) {
          cout << "  ERROR: Cannot open drivers.txt\n"; return;
       }
       file << count << "\n";
       for (int i = 0; i < count; i++) {
            file << drivers[i].getId()               << "\n";
            file << drivers[i].getName()             << "\n";
            file << drivers[i].getPassword()         << "\n";
            file << drivers[i].getAssignedVehicleId()<< "\n";
       } 
       file.close();
       cout << "6.Drivers  Saved to drivers.txt\n";
    }
 
    int loadStudents(Student students[]) {
        ifstream file(studentFile);
        int count = 0;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            int id, hasPass;
            string name, pass, regNo;
            file >> id; file.ignore();
            getline(file, name);
            getline(file, pass);
            getline(file, regNo);
            file >> hasPass; file.ignore();
            students[i].setId(id);
            students[i].setName(name);
            students[i].setPassword(pass);
            students[i].setRegNo(regNo);
            students[i].setHasPass(hasPass);
        }
        file.close();
        return count;
    }

    int loadStaff(Staff staffArr[]) {
        ifstream file(staffFile);
        int count = 0;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            int id;
            string name, pass, desig;
            file >> id; file.ignore();
            getline(file, name);
            getline(file, pass);
            getline(file, desig);
            staffArr[i].setId(id);
            staffArr[i].setName(name);
            staffArr[i].setPassword(pass);
            staffArr[i].setDesignation(desig);
        }
        file.close();
        return count;
    }

    int loadVehicles(Vehicle vehicles[]) {
        ifstream file(vehiclesFile);
        int count = 0;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            int vid, cap, seats;
            string plate, type;
            file >> vid; file.ignore();
            getline(file, plate);
            file >> cap >> seats; file.ignore();
            getline(file, type);
            vehicles[i].setVid(vid);
            vehicles[i].setPlate(plate);
            vehicles[i].setCapacity(cap);
            vehicles[i].setSeatsUsed(seats);
            vehicles[i].setType(type);
        }
        file.close();
        return count;
    }

    int loadRoutes(Route routes[]) {
        ifstream file(routesFile);
        int count = 0;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            int rid, vid;
            string start, end;
            float dist;
            file >> rid; file.ignore();
            getline(file, start);
            getline(file, end);
            file >> dist >> vid; file.ignore();
            routes[i].setRid(rid);
            routes[i].setStartPoint(start);
            routes[i].setEndPoint(end);
            routes[i].setDistance(dist);
            routes[i].setVehicleId(vid);
        }
        file.close();
        return count;
    }

    int loadPasses(Pass passes[]) {
        ifstream file(passesFile);
        int count = 0;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            int pid, sid, rid, paid;
            string status;
            float fee;
            file >> pid >> sid >> rid; file.ignore();
            getline(file, status);
            file >> fee >> paid; file.ignore();
            passes[i].setPassId(pid);
            passes[i].setStudentId(sid);
            passes[i].setRouteId(rid);
            passes[i].setStatus(status);
            passes[i].setFee(fee);
            passes[i].setPaid(paid);
        }
        file.close();
        return count;
    }
    
    int loadDrivers(Driver drivers[]) {
        ifstream file("drivers.txt");
        int count = 0;
        if (!file.is_open()) return 0;
        file >> count; file.ignore();
        for (int i = 0; i < count; i++) {
           int id, vid;
           string name, pass;
           file >> id; file.ignore();
           getline(file, name);
           getline(file, pass);
           file >> vid; file.ignore();
           drivers[i].setId(id);
           drivers[i].setName(name);
           drivers[i].setPassword(pass);
           drivers[i].setAssignedVehicleId(vid);
        }
        file.close();
        return count;
   }

    void saveAll(Student  students[], int sCount,
                 Staff    staffArr[], int stCount,
                 Vehicle  vehicles[], int vCount,
                 Route    routes[]  , int rCount,
                 Pass     passes[]  , int pCount,
				 Driver   drivers[] , int dCount) {
        cout << "\n-----------------------------\n";
        cout << "     Saving All Data          " ;
        saveStudents(students, sCount)  ;
        saveStaff   (staffArr, stCount) ;
        saveVehicles(vehicles, vCount)  ;
        saveRoutes  (routes,   rCount)  ;
        savePasses  (passes,   pCount)  ;
        saveDrivers (drivers,dCount)    ;
        cout << "-----------------------------\n";
        cout << " All Data Saved! " << endl;
        cout << "-----------------------------\n";
    }
    
    void showFileStatus() {
    	cout << "\n-----------------------------\n";
        cout << "\n      File Status     \n" ;
        cout << "\n-----------------------------\n";
        checkFile(studentFile) ;
        checkFile(staffFile)   ;
        checkFile(vehiclesFile);
        checkFile(routesFile)  ;
        checkFile(passesFile)  ;
        checkFile(driverFile)  ;
    }
};

// ============================================
// GLOBAL Variables 
// ============================================ 
Student*  students = new Student[MAX] ;   
Staff*    staffArr = new Staff[MAX]   ;     
Vehicle*  vehicles = new Vehicle[MAX] ;   
Route*    routes   = new Route[MAX]   ;     
Pass*     passes   = new Pass[MAX]    ;      
Bill*     bills    = new Bill[MAX]    ;
Driver*   drivers  = new Driver[MAX]  ;  

TransportManager* tm = nullptr ;
FileManager fm                 ;
Report rp                      ;

int studentCount = 0;
int staffCount   = 0;
int vehicleCount = 0;
int routeCount   = 0;
int passCount    = 0;
int billCount    = 0;
int driverCount  = 0;

int nextStudentId = 100 ;
int nextStaffId   = 200 ;
int nextVehicleId = 1   ;
int nextRouteId   = 1   ;
int nextPassId    = 1   ;
int nextBillId    = 1   ;
int nextDriverId  = 300 ;


// ============================================
//              Templates
// ============================================

template <typename T>
T getValidInput(string prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n-----------------------------\n";
            cout << "| Invalid! Enter a number.  |\n";
            cout << "-----------------------------\n";
        } else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

template <typename T>
void removeByIndex(T arr[], int& count, int index) {
    for (int i = index; i < count - 1; i++)
        arr[i] = arr[i + 1];
    count--;
}


// ============================================
// MENU AND OTHER FUNCTIONS
// ============================================

void driverMenu(int driverIndex) {
    int choice;
    do {
        cout << "\n=============================\n"
             << "        Driver Menu          \n"
             << "=============================\n"
             << "1. View My Vehicle\n"
             << "2. View My Route\n"
             << "3. View Passengers\n"
             << "4. About\n"
             << "5. Logout\n";
        choice = getValidInput<int>("Choice: ");
        cout << "\n=============================\n";

        switch (choice) {
            case 1: {
                int vid = drivers[driverIndex].getAssignedVehicleId();
                cout << "\n-----------------------------\n"
                     << "        My Vehicle           \n"
                     << "-----------------------------\n";
                if (vid == -1) {
                    cout << "  No vehicle assigned yet.\n";
                    break;
                }
                bool found = false;
                for (int i = 0; i < vehicleCount; i++) {
                    if (vehicles[i].getVid() == vid) {
                        vehicles[i].showInfo();
                        found = true; break;
                    }
                }
                if (!found) cout << "  Vehicle not found.\n";
                cout << "-----------------------------\n";
                break;
            }
            case 2: {
                int vid = drivers[driverIndex].getAssignedVehicleId();
                cout << "\n-----------------------------\n"
                     << "         My Route            \n"
                     << "-----------------------------\n";
                if (vid == -1) {
                    cout << "  No vehicle assigned, so no route.\n";
                    break;
                }
                bool found = false;
                for (int i = 0; i < routeCount; i++) {
                    if (routes[i].getVehicleId() == vid) {
                        routes[i].showInfo();
                        found = true; break;
                    }
                }
                if (!found) cout << "  No route assigned to your vehicle yet.\n";
                cout << "-----------------------------\n";
                break;
            }
            case 3: {
                int vid = drivers[driverIndex].getAssignedVehicleId();
                cout << "\n-----------------------------\n"
                     << "       My Passengers         \n"
                     << "-----------------------------\n";
                if (vid == -1) {
                    cout << "  No vehicle assigned.\n";
                    break;
                } 
                int assignedRouteId = -1;
                for (int i = 0; i < routeCount; i++) {
                    if (routes[i].getVehicleId() == vid) {
                        assignedRouteId = routes[i].getRid();
                        break;
                    }
                }
                if (assignedRouteId == -1) {
                    cout << "  No route assigned to your vehicle.\n";
                    break;
                } 
                bool anyFound = false;
                for (int i = 0; i < passCount; i++) {
                    if (passes[i].getRouteId() == assignedRouteId &&
                        passes[i].getStatus()  == "approved") {
                        for (int j = 0; j < studentCount; j++) {
                            if (students[j].getId() == passes[i].getStudentId()) {
                                students[j].showInfo();
                                anyFound = true; break;
                            }
                        }
                    }
                }
                if (!anyFound) cout << "  No passengers on your route yet.\n";
                cout << "-----------------------------\n";
                break;
            }
            case 4: {
                drivers[driverIndex].showInfo();
                cout << " |University Transport System|\n";
                cout << "          |UET KSK|\n";
                cout << "-----------------------------\n";
                break;
            }
            case 5: {
                cout << "  Logged out.\n";
                cout << "-----------------------------\n";
                break;
            }
            default:
                cout << "  Invalid choice.\n";
                cout << "-----------------------------\n";
        }
    } while (choice != 5);
}


void userMenu(int studentIndex) {
    int choice;
    do {
        cout << "\n=============================\n"
            << "         User Menu         \n"
            << "=============================\n"
            << "1. View Routes\n"
            << "2. Apply for Transport\n"
            << "3. View My Registration\n"
            << "4. Cancel Registration\n"
            << "5. About\n"
            << "6. Logout\n";
            choice = getValidInput<int>("Choice: ");
        cout << "\n=============================\n";

        switch (choice) {
            case 1:{
                cout << "\n-----------------------------\n"
                <<"        View Routes          \n"
                << "-----------------------------\n";
                if (routeCount == 0) { 
                   cout << "  No routes added yet.\n"; 
                   break; 
                }

                for (int i = 0; i < routeCount - 1; i++)
                    for (int j = 0; j < routeCount - i - 1; j++)
                        if (routes[j] < routes[j+1])   
                            swap(routes[j], routes[j+1]);
               cout << "|List Of Routes From Expensive To Cheaper | \n\n";
               for (int i = 0; i < routeCount; i++)
                    routes[i].showInfo();
                break;
            }
            case 2: {
                int rid;
                cout << "\n-----------------------------\n"
                <<"       Apply For Transport           \n"
                << "-----------------------------\n";
                rid = getValidInput<int>("  Enter Route ID: ");
                if (students[studentIndex].getHasPass()) {
                  cout << "  You already applied!\n"; break;
                }
                    bool found = false;
                    for (int i = 0; i < routeCount; i++) {
                        if (routes[i].getRid() == rid) {
                            passes[passCount].setPassId(nextPassId++);
                            passes[passCount].setStudentId(students[studentIndex].getId());
                            passes[passCount].setRouteId(rid);
                            passes[passCount].setStatus("pending");
                            passes[passCount].setFee(routes[i].monthlyFee());
                            passes[passCount].setPaid(0);
                            passCount++;
                            cout << "  Applied! Waiting for approval.\n";
                            found = true; break;
                        }
                   }
                    if (!found) cout << "  Route not found.\n";
                    cout << "-----------------------------\n";
                break;
            }
            case 3: {
                cout << "\n-----------------------------\n"
                <<"        My Resgistration           \n"
                << "-----------------------------\n";
                    for (int i = 0; i < passCount; i++) {
                       if (passes[i].getStudentId() == students[studentIndex].getId()) {
                            passes[i].showInfo();
                            if (passes[i].getStatus() == "approved" && passes[i].getPaid() == 0) {
                                for (int b = 0; b < billCount; b++) {
                                    if (bills[b].getIsPaid() == 0) {
                                        bills[b].showInfo();
                                        int overdue = getValidInput<int>("  Is due date passed? (1=Yes / 0=No): ");
                                            if (overdue == 1) {
                                                bills[b].calculateLateFee(true);
                                                cout << "  Updated Fee: Rs " << bills[b].getTotalFee() << endl;
                                            }
                                       break;
                                    }
                               }
                           }
                        }
                    }
		       cout << "-----------------------------\n";
               break;
            }
            case 4: {
                for (int i = 0; i < passCount; i++) {
                    if (passes[i].getStudentId() == students[studentIndex].getId() &&
                        passes[i].getStatus() == "approved") {
                        passes[i].setStatus("cancelled");
                        students[studentIndex].setHasPass(0);
                        for (int r = 0; r < routeCount; r++) {
                            if (routes[r].getRid() == passes[i].getRouteId()) {
                                int vid = routes[r].getVehicleId();
                                for (int v = 0; v < vehicleCount; v++) {
                                    if (vehicles[v].getVid() == vid) {
                                        vehicles[v].setSeatsUsed(vehicles[v].getSeatsUsed() - 1);
                                        break;
                                    }
                                }
                               break;
                           }
                       }                       
                        cout << "  Registration cancelled.\n";
                    }
                }
                cout << "-----------------------------\n";
                break;
            }
            case 5: {
            	students[studentIndex].showInfo();
                cout << " |University Transport System| \n";
                cout << "           |UET KSK|\n";
              break;
            } 
            case 6: {
                cout << "  Logged out.\n";
                cout << "-----------------------------\n";
                break;
            } 
            default:
            cout << "  Invalid choice.\n";
            cout << "-----------------------------\n";
        }
    } while (choice != 6);
} 

void adminMenu() {
int choice0 , choice1 , choice2 , choice3 , choice4 , choice5 , choice6;
    do{
            cout << "\n=============================\n"
             << "         Admin Menu          \n"
             << "=============================\n"
             << "1.  Manage Vehicles \n"
             << "2.  Manage Routes \n"
             << "3.  Manage Applications \n"
             << "4.  Manage Drivers \n"
             << "5.  View Reports \n"
             << "6.  View Users \n"
             << "7.  Save Data \n"
             << "8.  File Status \n"
             << "9.  Reset System \n"
             << "10. Logout \n";
			choice0 = getValidInput<int>("Choice : ");
            cout << "\n=============================\n";
        if (choice0 == 1){
        	do { 
                cout << "\n-----------------------------\n"
                <<"       Manage Vehicles           \n"
                << "-----------------------------\n"
                << " 1. Add Bus\n"
                << " 2. Add Van\n"
                << " 3. Remove Vehicle\n"
                << " 4. List Vehicles\n"
				<< " 5. Exit \n";
				choice1 = getValidInput<int>("Choice : ");
                cout << "\n-----------------------------\n";    
              switch (choice1) {
                case 1: {
                   string plate; int cap;
                   cout << "  NO. Plate: ";    cin >> plate;
                   cout << "  Capacity : "; cin >> cap;  
                   vehicles[vehicleCount].setVid(nextVehicleId++);   
                   vehicles[vehicleCount].setPlate(plate);
                   vehicles[vehicleCount].setCapacity(cap);
                   vehicles[vehicleCount].setSeatsUsed(0);
                   vehicles[vehicleCount].setType("Bus");
                   vehicleCount++;
                   cout << "  Bus added! (Vehicle ID = " <<vehicles[vehicleCount-1].getVid();
                   cout << " ) \n";
				   cout << "\n-----------------------------\n";
                   break;
                }
               case 2: {
                   string plate; int cap;
                   cout << "  NO. Plate: ";    cin >> plate;
                   cout << "  Capacity : "; cin >> cap;
                   vehicles[vehicleCount].setVid(nextVehicleId++);
                   vehicles[vehicleCount].setPlate(plate);
                   vehicles[vehicleCount].setCapacity(cap);
                   vehicles[vehicleCount].setSeatsUsed(0);
                   vehicles[vehicleCount].setType("Van");
                   vehicleCount++;
                   cout << "  Van added! (Vehicle ID = " <<vehicles[vehicleCount-1].getVid();
                   cout << " ) \n";
				   cout << "\n-----------------------------\n";
                   break;
                }
               case 3: {
                   int vid;
                   vid = getValidInput<int>("  Vehicle ID: ");
                   bool found = false;
                   for (int i = 0; i < vehicleCount; i++) {
                        if (vehicles[i].getVid() == vid) {
                            removeByIndex(vehicles, vehicleCount, i);
                            cout << "  Vehicle removed!\n";
                            found = true;
                            break;
                        }
                    }
                   if (!found) cout << "  Vehicle does not exist.\n";
                   cout << "\n-----------------------------\n";
                   break;
				}
               case 4: {
                    cout << "\n-----------------------------\n"
                    <<"          All Vehicles            \n"
                    << "-----------------------------\n";
                    if (vehicleCount == 0) { cout << "  No vehicles.\n"; break; }
                    for (int i = 0; i < vehicleCount; i++){
                        vehicles[i].showInfo();
                    }
                    cout << "\n-----------------------------\n";
                   break;
                }
                case 5: {
                	cout << " Thanks! \n";
                	cout << "\n-----------------------------\n";
					break;
				}
             }
           }
           while(choice1 != 5);
       }
       else if (choice0 == 2){
       	    do {
       	         cout << "\n-----------------------------\n"
                 <<"        Manage Routes           \n"
                 << "-----------------------------\n"
                 << " 1. Add Route\n"
                 << " 2. Assign Vehicle to Route\n"
                 << " 3. List Routes\n"
				 << " 4. Exit \n";
				 choice2 = getValidInput<int>("Choice : "); 
                 cout << "\n-----------------------------\n";
              switch (choice2) {
               case 1: {
                  string s, e; float d;
                  cout << "  Start: ";         cin >> s;
                  cout << "  End: ";           cin >> e;
                  cout << "  Distance (km): "; cin >> d;
                  routes[routeCount].setRid(nextRouteId++);
                  routes[routeCount].setStartPoint(s);
                  routes[routeCount].setEndPoint(e);
                  routes[routeCount].setDistance(d);
                  routes[routeCount].setVehicleId(-1);
                  routeCount++;
                  cout << "  Route added!\n";
				  cout << "\n-----------------------------\n";
                  break;
                }
               case 2: {
                   int rid, vid;
                    rid = getValidInput<int>("  Route ID: ");
                    vid = getValidInput<int>("  Vehicle ID: ");
                  for (int i = 0; i < routeCount; i++) {
                     if (routes[i].getRid() == rid) {
                         routes[i].setVehicleId(vid);
                         cout << "  Vehicle assigned!\n";
                         break;
                        }
                    }
                    cout << "\n-----------------------------\n";
                   break;
                }
               case 3: {
                    cout << "\n-----------------------------\n"
                    <<"          All Routes           \n"
                    << "-----------------------------\n";
                    if (routeCount == 0) { cout << "  No routes.\n"; break; }
                    for (int i = 0; i < routeCount; i++)
                    routes[i].showInfo();
                    cout << "\n-----------------------------\n";
                    break;
                }
               case 4:{
               	    cout << "Thanks! ";
               	    cout << "\n-----------------------------\n";
					break;
				}
              }
           }
           while(choice2 != 4);
       }
        else if (choice0 == 3){
        	do{
        	     cout << "\n-----------------------------\n"
                 <<"       Manage Applications           \n"
                 << "-----------------------------\n"
                 << " 1. View Applications\n"
                 << " 2. Approve Application\n"
                 << " 3. Reject Application\n"
				 << " 4. Exit \n";
				 choice3 = getValidInput<int>("Choice : "); 
                 cout << "\n-----------------------------\n";
              switch (choice3) { 
        	     case 1:{
                     cout << "\n-----------------------------\n"
                     <<"         All Applications           \n"
                     << "-----------------------------\n";
                     if (passCount == 0) { cout << "  No applications.\n"; break; }
                     for (int i = 0; i < passCount; i++)
                     passes[i].showInfo();
                     cout << "\n-----------------------------\n";
                     break;
                    }
                 case 2: {
                     int pid;
                     pid = getValidInput<int>("  Pass ID to approve: ");
                        for (int i = 0; i < passCount; i++) {
                            if (passes[i].getPassId() == pid &&
                              passes[i].getStatus() == "pending") {
                              int assignedVehicleId = -1;
                                for (int r = 0; r < routeCount; r++) {
                                    if (routes[r].getRid() == passes[i].getRouteId()) {
                                        assignedVehicleId = routes[r].getVehicleId();
                                        break;
                                    }
                                }
                             bool capacityOk = true;
                             int vehicleIndex = -1;
                                if (assignedVehicleId != -1) {
                                    for (int v = 0; v < vehicleCount; v++) {
                                        if (vehicles[v].getVid() == assignedVehicleId) {
                                            vehicleIndex = v;
                                            if (vehicles[v].getSeatsUsed() >= vehicles[v].getCapacity()) {
                                                capacityOk = false;
                                            }
                                            break;
                                        }
                                    }
                                }
                             if (!capacityOk) {
                                cout << "  Cannot approve: vehicle is full!\n";
                                break;
                              }
                             passes[i].setStatus("approved");
                             bills[billCount] = Bill(nextBillId++ , passes[i] , "2026-06-30");
                             billCount++ ;
                             if (vehicleIndex != -1){
                                vehicles[vehicleIndex].setSeatsUsed(
                                vehicles[vehicleIndex].getSeatsUsed() + 1);
                              } 
                              for (int j = 0; j < studentCount; j++) {
                                if (students[j].getId() == passes[i].getStudentId()) {
                                    students[j].setHasPass(1);
                                    break;
                                }
                              }
						     cout << "  Pass approved!\n";
						     cout << "-----------------------------\n";
                             break;
                            }
                            else {
                            	cout << "Invalid Detail ";
							}
                        }
                        break;
                   }
                    case 3: {
                        int pid;
                        pid = getValidInput<int>("  Pass ID to reject: "); 
                         bool found = false;
                            for (int i = 0; i < passCount; i++) {
                                if (passes[i].getPassId() == pid) {
                                    found = true;
                                    if (passes[i].getStatus() == "pending") {
                                        passes[i].setStatus("rejected");
                                        cout << "  Pass rejected.\n";
                                    } 
									else {
                                        cout << "  Cannot reject! \n Status is: "
                                        << passes[i].getStatus() << "\n";
                                        break;
                                    }
                                    break;
                                }
                           }
                           if (!found) cout << "  Pass ID not found.\n";
                        cout << "\n-----------------------------\n";
                     break;
                   }
                 case 4:{
                 	cout <<" Thanks! \n";
					cout << "\n-----------------------------\n";
					break;
		    	 }
               } 
            }
           while(choice3 != 4 );
       }
       else if (choice0 == 4 ){
            do {
                cout << "\n-----------------------------\n"
                << "       Manage Drivers        \n"
                << "-----------------------------\n"
                << "1. Add Driver\n"
                << "2. Assign Vehicle to Driver\n"
                << "3. List Drivers\n"
                << "4. Remove Driver\n"
                << "5. Exit\n";
               choice4 = getValidInput<int>("Choice : ");
               cout << "\n-----------------------------\n";
               switch (choice4) {
             case 1: {
                string name, pass;
                cout << "  Name     : "; getline(cin,name);
                cout << "  Password : "; getline(cin,pass);
                drivers[driverCount].setId(nextDriverId++);
                drivers[driverCount].setName(name);
                drivers[driverCount].setPassword(pass);
                drivers[driverCount].setAssignedVehicleId(-1);
                driverCount++;
                cout << "  Driver registered! ID = "
                     << drivers[driverCount - 1].getId() << endl;
                cout << "-----------------------------\n";
                break;
             }
             case 2: {
                int did, vid;
                did = getValidInput<int>("  Driver ID: ");
                vid = getValidInput<int>("  Vehicle ID: ");
                bool found = false;
                for (int i = 0; i < driverCount; i++) {
                    if (drivers[i].getId() == did) {
                        drivers[i].setAssignedVehicleId(vid);
                        cout << "  Vehicle " << vid
                             << " assigned to Driver " << did << endl;
                        found = true; break;
                    }
                }
                if (!found) cout << "  Driver not found.\n";
                cout << "-----------------------------\n";
                break;
             }
             case 3: {
                 cout << "\n-----------------------------\n"
                     << "        All Drivers          \n"
                     << "-----------------------------\n";
                if (driverCount == 0) { cout << "  No drivers.\n"; break; }
                for (int i = 0; i < driverCount; i++)
                    drivers[i].showInfo();
                cout << "-----------------------------\n";
                break;
             }
             case 4: {
                int did;
                did = getValidInput<int>("  Driver ID to remove: ");
                bool found = false;
                for (int i = 0; i < driverCount; i++) {
                    if (drivers[i].getId() == did) {
                        removeByIndex(drivers, driverCount, i);
                        cout << "  Driver removed.\n";
                        found = true; break;
                    }
                }
                if (!found) cout << "  Driver not found.\n";
                cout << "-----------------------------\n";
                break;
             }
             case 5: {
                cout << "  Thanks!\n";
                cout << "-----------------------------\n";
                break;
             }
             }
           }
	       while (choice4 != 5);
       }
	    else if (choice0 == 5 ){
            do{
         	   cout << "\n-----------------------------\n"
                 <<"         View Reports          \n"
                 << "-----------------------------\n"
                 << "1. Route Report\n"
                 << "2. Revenue Report\n"
                 << "3. Exit\n";
				 choice5 = getValidInput<int>("Choice : "); 
               cout << "\n-----------------------------\n";
             switch (choice5) { 
	            case 1:{
                    rp.routeWiseReport(passes, passCount, routes, routeCount); 
                    cout << "\n-----------------------------\n";
                    break;
                }
                case 2: {
                    rp.revenueReport(passes, passCount);
                    cout << "\n-----------------------------\n";
                    break;
                }
				case 3:{
					cout<<" Thanks! \n";
					cout << "\n-----------------------------\n";
					break;
				} 
              }
            }
           while(choice5 != 3);
                
	   }
       else if (choice0 == 6 ){
       	    do{
         	   cout << "\n-----------------------------\n"
                 <<"         View Users          \n"
                 << "-----------------------------\n"
                 << "1. List Students\n"
                 << "2. List Staff\n"
                 << "3. Exit\n";
				 choice6 = getValidInput<int>("Choice : "); 
               cout << "\n-----------------------------\n";
             switch (choice6) { 
	            case 1:{
                   cout << "\n-----------------------------\n"
                   <<"          All Students         \n"
                   << "-----------------------------\n";
                    if (studentCount == 0) { cout << "  No students.\n"; break; }
                    for (int i = 0; i < studentCount; i++)
                    students[i].showInfo();
                    cout << "\n-----------------------------\n";
                    break;
                }
                case 2: {
                    cout << "\n-----------------------------\n"
                    <<"         All Staff Members         \n"
                    << "-----------------------------\n";
                    if (staffCount == 0) { cout << "  No staff.\n"; break; }
                    for (int i = 0; i < staffCount; i++)
                    staffArr[i].showInfo();
                    cout << "\n-----------------------------\n";
                    break;
                }
				case 3:{
					cout<<" Thanks! \n";
					cout << "\n-----------------------------\n";
					break;
				} 
              }
            }
           while(choice6 != 3);
        }
        else if (choice0 == 7){
           fm.saveAll(students, studentCount,
                       staffArr, staffCount,
                       vehicles, vehicleCount,
                       routes,   routeCount,
                       passes,   passCount ,
					   drivers,  driverCount);
        }
        else if (choice0 == 8){
	      fm.showFileStatus();
        }
        else if (choice0 == 9) {
            studentCount = 0      ;
            staffCount   = 0      ;
            vehicleCount = 0      ;
            routeCount   = 0      ;
            passCount    = 0      ;
            billCount    = 0      ;
            driverCount  = 0      ;
            nextStudentId = 100   ;
            nextStaffId   = 200   ;
            nextDriverId  = 300   ;
            nextVehicleId = 1     ;
            nextRouteId   = 1     ;
            nextPassId    = 1     ;
            nextBillId    = 1     ;
            remove("student.txt") ;
            remove("staff.txt")   ;
            remove("vehicles.txt");
            remove("routes.txt")  ;
            remove("passes.txt")  ;
            remove("drivers.txt") ;
            remove("bills.txt")   ; 
            cout << "  System Reseted!";
            cout << "\n-----------------------------\n";
        } 
        else if (choice0 == 10){
            cout << "  Logged out. ";
            cout << "\n-----------------------------\n";
        }
        else {
            cout << "  Invalid choice. ";
            cout << "\n-----------------------------\n";
        }
    } while (choice0 != 10);
}


void registrationBlock() {
    int ch;
    string name, pass, regNo, desig;

    cout << "\n=============================\n"
        << "     Registration Block      \n"
        << "=============================\n"
        << "1. Register Student\n"
        << "2. Register Staff\n"
        << "3. Back\n";
        ch = getValidInput<int>("Choice: ");
    cout << "\n=============================\n";

    if (ch == 1) {
        cout << "  Name            : "; cin >> name;
        cout << "  Password        : "; cin >> pass;
        cout << "  Registration No : "; cin >> regNo;

        students[studentCount].setId(nextStudentId++);
        students[studentCount].setName(name);
        students[studentCount].setPassword(pass);
        students[studentCount].setRegNo(regNo);
        students[studentCount].setHasPass(0);
        studentCount++;

        cout << "  Student registered successfully!\n";
        cout << "-----------------------------\n";
    }
	else if (ch == 2) {
        cout << "  Name        : "; cin >> name;
        cout << "  Password    : "; cin >> pass;
        cout << "  Designation : "; cin >> desig;

        staffArr[staffCount].setId(nextStaffId++);
        staffArr[staffCount].setName(name);
        staffArr[staffCount].setPassword(pass);
        staffArr[staffCount].setDesignation(desig);
        staffCount++;

        cout << "  Staff registered successfully!\n";
        cout << "-----------------------------\n";
    }
	else if (ch == 3) {
        cout << "  Going back...\n";
        cout << "-----------------------------\n";
    }
	 else {
        cout << "  Invalid choice.\n";
        cout << "-----------------------------\n";
    }
}

void loginBlock() {
    string  nameStudent , nameStaff , passStudent ;
	string  passStaff , passAdmin , usernameAdmin ;
    int c;

    cout << "\n=============================\n"
        << "         Login Block         \n"
        << "=============================\n"
        << "1. Student\n"
        << "2. Staff\n"
        << "3. Driver\n"
        << "4. Admin\n"
        << "5. Back\n";
        c = getValidInput<int>("Choice: "); 
    cout << "\n=============================\n";

    if (c == 1) {
        cout << "  Username: "; cin >> nameStudent;
        cout << "  Password: "; cin >> passStudent;
        // find student
        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getName() == nameStudent &&
                students[i].getPassword() == passStudent) {
                cout << "  Welcome " << nameStudent << "!\n";
                userMenu(i);
                found = true; break;
            }
        }
        if (!found) cout << "  Invalid credentials.\n";
        cout << "-----------------------------\n";
    } 
	else if (c == 2) {
        cout << "  Username    : "; cin >> nameStaff;
        cout << "  Password    : "; cin >> passStaff;
        bool found = false;
        for (int i = 0; i < staffCount; i++) {
            if (staffArr[i].getName() == nameStaff &&
                staffArr[i].getPassword() == passStaff) {
                cout << "  Welcome " << nameStaff << "!\n";
                userMenu(i);
                found = true; break;
            }
        }
        if (!found) cout << "  Invalid credentials.\n";
        cout << "-----------------------------\n";
    } 
    else if (c == 3) {
        string nameDriver, passDriver;
        cout << "  Username: "; cin >> nameDriver;
        cout << "  Password: "; cin >> passDriver;
        bool found = false;
        for (int i = 0; i < driverCount; i++) {
            if (drivers[i].getName()     == nameDriver &&
                drivers[i].getPassword() == passDriver) {
                cout << "  Welcome Driver " << nameDriver << "!\n";
                driverMenu(i);
                found = true; break;
            }
        }
        if (!found) cout << "  Invalid credentials.\n";
        cout << "-----------------------------\n";
	}
	else if (c == 4) {
		cout << " Admin Username: "; cin >> usernameAdmin;
        cout << " Admin Password: "; cin >> passAdmin;
        if (usernameAdmin == "admin" && passAdmin == "123") {
            cout << "  Welcome Admin!\n";
            adminMenu();
        } 
		else if (usernameAdmin != "admin"){
            cout << "  Wrong username!\n";
        }
        else if (passAdmin != "123") {
            cout << "  Wrong password!\n";
        }
        else {
            cout << "  ERROR!\n";
        }
    }
	else if (c == 5) {
        cout << "  Going back...\n";
    } 
	else {
        cout << "  Invalid choice.\n";
    }
    
}

void loadAllData(){
    studentCount = fm.loadStudents(students) ;
    staffCount   = fm.loadStaff(staffArr)    ;
    vehicleCount = fm.loadVehicles(vehicles) ;
    routeCount   = fm.loadRoutes(routes)     ;
    passCount    = fm.loadPasses(passes)     ;
    driverCount  = fm.loadDrivers(drivers)   ;

    tm = new TransportManager ("Admin",
    vehicles, &vehicleCount, routes,   &routeCount);
    
    if (studentCount > 0)
        nextStudentId = students[studentCount - 1].getId() + 1  ;
    if (staffCount > 0)
        nextStaffId = staffArr[staffCount - 1].getId() + 1      ;
    if (vehicleCount > 0)
        nextVehicleId = vehicles[vehicleCount - 1].getVid() + 1 ;
    if (routeCount > 0)
        nextRouteId = routes[routeCount - 1].getRid() + 1       ;
    if (passCount > 0) 
        nextPassId = passes[passCount - 1].getPassId() + 1      ;
    if (driverCount > 0)
        nextDriverId = drivers[driverCount - 1].getId() + 1     ;
}

void delDynamicMemory(){
   delete[] students  ;
   delete[] staffArr  ;
   delete[] vehicles  ;
   delete[] routes    ;
   delete[] passes    ;
   delete[] bills     ;
   delete[] drivers   ;
   delete tm          ;
}

void mainInterface(){
	int choice; 
	do {
        cout << "\n=============================\n"
             << " University Transport System \n"
             << "=============================\n"
             << "1. Register\n"
             << "2. Login\n"
             << "3. Exit\n";
             choice = getValidInput<int>("Choice: ");
        cout << "\n=============================\n";
        
        if (choice == 1) {
            registrationBlock();
        }
	    else if (choice == 2) {
            loginBlock();
        } 
		else if (choice == 3) {
			int c;
			do{
			cout << "|1. Save and Exit |\n";
			cout << "|2. Exit only     |\n";
			c = getValidInput<int>("Choice: ");
			cout << "-----------------------------\n";
			   if (c == 1){
		         fm.saveAll(students , studentCount,
                            staffArr , staffCount, 
                            vehicles , vehicleCount,
                            routes   , routeCount,
                            passes   , passCount ,
					        drivers  , driverCount);
                 cout << "  Goodbye!\n";
                }
                else if ( c == 2 ){
                	cout << "Thanks! \n";
				}
				else {
					cout << " Invalid Input! \n\n";
					cout << "-----------------------------\n";
				}
			}
			while(c!=1 && c!=2);
        }
	    else {
            cout << "  Invalid choice.\n";
        }
    } while (choice != 3);
}
// ============================================
// MAIN FUNCTION
// ============================================ 
int main() {
	loadAllData()     ;      
    mainInterface()   ;     
    delDynamicMemory();  
    return 0;
} 

