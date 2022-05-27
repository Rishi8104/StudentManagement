#include<iostream>
using namespace std;

class Student
{
    private:
        int id;
        string name;
        float marks;
        string Contact;
        string address;
    public:
        void setId(int id)
        {
            this->id = id;
        }

        void setName(string name)
        {
            this->name = name;
        }
        void setMarks(float marks)
        {
            this->marks = marks;
        }
        void setContact (string Contact )
        {
            this->Contact = Contact;
        }
        void setAddress(string address)
        {
            this->address = address;
        }
        int getId()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        float getMarks()
        {
            return marks;
        }
       string getContact()
        {
            return Contact;
        }
        string getAddress()
        {
            return address;
        }
};


Student StudentList[60];
int pos=0;


class StudentService
{
    public:
        virtual void save(Student &student)=0;
        virtual void getAll()=0;
        virtual void getById(int id)=0;
        virtual void removeById(int id)=0;
};

class studentServiceImpl : public StudentService
{

public:
     void save(Student &student)
     {
         if(pos>=59)
         {
             cout<<"Cannot admit new Student in Class"<<endl;
         }
         else
         {
             StudentList[pos] = student;
             pos++;
         }
     }

    void getAll()
     {
         if(pos!=0)
         {
             cout<<"Student Data:\n";
             for(int i=0;i<pos;i++)
             {
                 cout<< "\nstudent "<<i+1<<endl;
                 cout<<"\nId: "<<StudentList[i].getId()<<"\nName: "<<StudentList[i].getName()<<"\nMarks: "<<StudentList[i].getMarks() \
                 <<"\nContact: "<<StudentList[i].getContact()<<"\nAddress: "<<StudentList[i].getAddress();
             }
         }
         else
         {
             cout<<"Students are Not Found";
         }
     }


         void getById(int id)
         {
            bool found = false;
                if(pos!=0)
                 {
                     for(int i=0;i<pos;i++)
                     {
                         if(StudentList[i].getId() == id)
                         {
                            cout<<"\nId: "<<StudentList[i].getId()<<"\nName: "<<StudentList[i].getName()<<"\nMarks: "<<StudentList[i].getMarks() \
                                <<"\nContact: "<<StudentList[i].getContact()<<"\nAddress: "<<StudentList[i].getAddress();
                            found = true;

                         }
                     }
                     if(!found)
                        cout<<"Id not found\n";
                 }
                 else
                 {
                     cout<<"No Students found\n";
                 }

         }

         void removeById(int id)
         {
             //Student s;
            // return 0;

         }

};

int main()
{
    studentServiceImpl service;
    int mainChoice;
    char ContinuationChoice;
    int id;
    string name;
    float marks;
    string contact;
    string address;

    cout<<"********** Student Management*******"<<endl;
    do
    {
         cout<<"\n\n1.Admit New Student\n2.Get all Students.\n3. Get student details"<<endl;
         cout<<"Enter Choice"<<endl;

         cin>>mainChoice;

         switch(mainChoice)
         {
            case 1:
            {
                Student study;
                cout<<"Enter id: " ;
                cin>>id;
                study.setId(id);
                cout<<"Enter name: ";
                cin>>name;
                study.setName(name);
                cout<<"Enter marks: ";
                cin>>marks;
                study.setMarks(marks);
                cout<<"Enter contact: ";
                cin>>contact;
                study.setContact(contact);
                cout<<"Enter address: ";
                cin>>address;
                study.setAddress(address);
                service.save(study);
             }
             break;
            case 2:
                {
                   service.getAll();
                }
                break;
            case 3:
                {
                    cout<<"Enter Id: ";
                    int id;
                    cin>>id;
                    service.getById(id);
                }
                break;
            default:
                break;
         }
         if(mainChoice > 3)
            break;
    }while(true);

    return 0;
 }

