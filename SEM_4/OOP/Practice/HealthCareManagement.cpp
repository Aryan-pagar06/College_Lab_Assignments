#include <iostream>
using namespace std;

class User 
{
   protected :

   int id;
   string name;
   string contact;

   public:

   User(int i, string n, string con) {
    id = i;
    name = n;
    contact = con;
   }

   virtual void displayProfile() {
    cout<<"Name : "<<name<<endl;
    cout<<"Contact Number : "<<contact<<endl;
    cout<<"ID : "<<id<<endl;
   }
};

class Doctor : public User 
{
   private :
   string specialization;
   double fee;
   public:
   Doctor(int i, string n, string con, string spe, double f ) : User(i, n, con) {
    specialization = spe;
    fee = f;
   }
   void displayProfile () override {
   User :: displayProfile();
   cout << "Specialization : " << specialization << endl;
   cout << "Fee : " << fee << endl;
   }
   double getFee() {
    return fee;
   }
}; 

class Patient : public User 
{
   private :
   string specialization;
   double consultfee;
   public:
    Patient() : User(0, "", "") {    // default constructor
        specialization = "";
        consultfee = 0;
    }
   Patient(int i, string n, string con, string spe, double f ) : User(i, n, con) {
    specialization = spe;
    consultfee = f;
   }
   void displayProfile() override {
   User :: displayProfile();
   cout << "Specialization : " << specialization << endl;
   cout << "Consultation Fee : " << consultfee << endl;
   }
}; 

class Appointment 
{
    private :
    Patient patient;
    Doctor *doctor;
    string date, time;
    public :
    Appointment (Patient p, Doctor *d, string dt, string t) {
        patient = p;
        doctor = d;
        date = dt;
        time = t;
    }

    void calculateBilling() {
        double fee = doctor -> getFee();
        double total = fee + (fee*0.1);
        cout<<"Total fee : "<<total<<endl;
    }

    void displayAppointment() {
        cout << "\n--- Appointment Details ---" << endl;
        cout << "Date : " << date << endl;
        cout << "Time : " << time << endl;
        cout << "\n-- Doctor Profile --" << endl;
        doctor->displayProfile();
        cout << "\n-- Patient Profile --" << endl;
        patient.displayProfile();
        calculateBilling();
    }
};

class ClinicManager {
private:
    vector<User*> users;                // list of all users (doctors + patients)
    vector<Appointment> appointments;   // list of all appointments

public:
    void registerUser(User* u) {
        users.push_back(u);   // add user to list
    }

    void scheduleAppointment(Appointment a) {
        appointments.push_back(a);   // add appointment to list
    }

    void generateReport() {
        cout << "\n===== Daily Schedule Report =====" << endl;
        for (auto i = appointments.begin(); i != appointments.end(); i++) {
            i->displayAppointment();   // display each appointment
        }
    }
};

int main() {
    // Step 1 — create doctor and patient
    Doctor d1(1, "Dr. Sharma", "9999", "Cardiology", 1000);
    Patient p1(2, "Aryan", "8888", "Heart Pain", 500);

    // Step 2 — create clinic manager
    ClinicManager cm;

    // Step 3 — register users
    cm.registerUser(&d1);
    cm.registerUser(&p1);

    // Step 4 — schedule appointment
    Appointment a1(p1, &d1, "23-04-2026", "10:00 AM");
    cm.scheduleAppointment(a1);

    // Step 5 — generate report
    cm.generateReport();

    return 0;
}