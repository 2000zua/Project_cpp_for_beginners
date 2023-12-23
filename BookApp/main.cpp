#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact{
    string name;
    string phone;
    string email;
};

void addContact(vector<Contact>& contacts){
    Contact newContact;
    cout << "Enter name: ";
    cin >> newContact.name;
    cout << "Enter phone: ";
    cin >> newContact.phone;
    cout << "Enter email: ";
    cin >> newContact.email;
    contacts.push_back(newContact);
    cout << "Contact added.\n";
}

void displayContacts(const vector<Contact>& contacts){
    for(const auto &constact : contacts){
        cout <<"Nome: "<< constact.name <<", Phone: "<<constact.phone <<", Email: "<<constact.email <<endl; 
    }
}

void searchContact(const vector<Contact>& contacts){
    string searchTerm;
    cout << "Enter name to search: ";
    cin >> searchTerm;
    bool found = false;

    for (const auto &contact : contacts){
        if(contact.name == searchTerm){
            cout <<"Contact found.\n";
            cout <<"Nome: "<< contact.name <<", Phone: "<<contact.phone <<", Email: "<<contact.email <<endl;
            found = true;
            break;
        }
    }

    if(!found){
        cout <<"Contact not found."<<endl;
    }
}

void deleteContact(vector<Contact>& contacts){
    string nameToDelete;
    cout <<"Enter name of contact to delete: ";
    cin >> nameToDelete;
    
    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact &conta){
        return conta.name == nameToDelete;
    });

    if(it != contacts.end()){
        contacts.erase(it, contacts.end());
        cout << "Contact deleted."<<endl;
    }else{
        cout << "Contact nor found."<<endl;
    }
}

void screem(){
    cout <<"========================================================\n";
    cout <<"================== CONTACT BOOK APP ====================\n";
    cout <<"========================================================\n";
    cout <<"====== 1. Add Contact: \n";
    cout <<"====== 2. Display Contacts: \n";
    cout <<"====== 3. Search Contact: \n";
    cout <<"====== 4. Delete Contact: \n";
    cout <<"====== 5. Exit:\n";
    cout <<"=== Enter your choice (1-5): ";
}

int main(){
    vector<Contact> contactos;
    int choice;

    do{
        screem();
        cin >> choice;

        switch (choice){
        case 1:
            addContact(contactos);
            break;
        case 2:
            displayContacts(contactos);
            break;
        case 3:
            searchContact(contactos);
            break;
        case 4:
            deleteContact(contactos);
            break;
        case 5:
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }

    } while (choice != 5);
    

    return 0;
}

