#include <iostream>
#include <vector>
using namespace std;

class Patient{

public:
    Patient();
    Patient(const string _name, const int _id, const int _num_conditions, const string* conditions);
    Patient(const Patient &p);
    ~Patient();

    //Mutators
    void setName(const string _name);
    void setId(const int _id);
    void addSymptom(const string _symptom);

    //Accessors
    string getName();
    int getId();
    string getSymptom(const int index);

    //Misc
    void print() const;

private:
    string name;
    int id;
    string* symptoms;
    int num_symptoms = 0;

    static const int MAX_SYMPTOMS = 5;

};

Patient::Patient()
{
    name = "";
    id = 0;
    num_symptoms = 0;
    symptoms = new string[MAX_SYMPTOMS];
}

Patient::Patient(const string _name, const int _id, const int _num_symptoms, const string* _symptoms)
{
    if(_num_symptoms >= 0 && _num_symptoms < MAX_SYMPTOMS)
    {
        name = _name;
        id = _id;
        num_symptoms = _num_symptoms;
        symptoms = new string[MAX_SYMPTOMS];

        for (int i = 0; i < num_symptoms; i++)
        {
            symptoms[i] = _symptoms[i];
        }
    }
    else
        cout << "Error: Patient must have between 0 and " << MAX_SYMPTOMS << " conditions.\n";
}

Patient::Patient(const Patient &p)
{
    name = p.name;
    id = p.id;
    num_symptoms = p.num_symptoms;
    symptoms = new string[MAX_SYMPTOMS];

    for (int i = 0; i < num_symptoms; i++)
    {
        symptoms[i] = p.symptoms[i];
    }
}

Patient::~Patient()
{
    cout << "Destructor called on " << name << "\n";
    delete [] symptoms;
}

void Patient::setName(const string _name)
{
    name = _name;
}

void Patient::setId(const int _id)
{
    if (_id > 0)
        id = _id;
    else
        cout << "Error: Patient ID must be positive number\n";
}

void Patient::addSymptom(const string _symptom)
{
    symptoms[num_symptoms] = _symptom;
    num_symptoms++;
}

string Patient::getName()
{
    return name;
}

int Patient::getId()
{
    return id;
}

string Patient::getSymptom(const int index)
{
    return symptoms[index];
}

void Patient::print() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "# of Symptoms: " << num_symptoms << endl;

    for (int i = 0; i < num_symptoms; i++)
        cout << "Symptom " << i+1 << ": " << symptoms[i] << endl;
    cout << "\n\n";
}

int main()
{
    Patient p1;
    p1.setName("Bob");
    p1.setId(3245);
    p1.addSymptom("Toothache");

    Patient p2;
    p2.setName("Susan");
    p2.setId(4321);
    p2.addSymptom("Nausea");

    Patient p3;
    p3.setName("John");
    p3.setId(4536);
    p3.addSymptom("Broken arm");

    p1.print();
    p2.print();
    p3.print();


    vector<Patient> er_queue;

    bool new_patient_event = false;

    //Flag gets set to true
    new_patient_event = true;

    if (new_patient_event)
    {
        Patient temp;
        temp.setName("Josh");
        temp.setId(123);
        temp.addSymptom("Very hungry");
        temp.addSymptom("Possibly infected with zombie virus");

        er_queue.push_back(temp);
        er_queue[0].print();

    }

    return 0;
}
