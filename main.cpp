#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a structure to represent an animal node
struct AnimalNode {
    string animalName;
    AnimalNode* next;
};

int main()
{
    fstream myFile;
    myFile.open("C:\\Users\\BE129\\Downloads\\animalNames.txt", ios::in); //Remember to redirect Path in your local memory

    if (myFile.is_open())
    {
        string line;
        AnimalNode* head = nullptr;
        AnimalNode* currentAnimal = nullptr;

        while (getline(myFile, line))
        {
            // Create a new animal node
            AnimalNode* newNode = new AnimalNode;
            newNode->animalName = line;
            newNode->next = nullptr;

            // Add the new node to the linked list
            if (head == nullptr) {
                head = newNode;
                currentAnimal = newNode;
            }
            else {
                currentAnimal->next = newNode;
                currentAnimal = newNode;
            }
        }

        myFile.close();

        // Print the linked list
        AnimalNode* current = head;
        while (current != nullptr)
        {
            cout << "Animal: " << current->animalName << endl;
            current = current->next;
        }

        // Clean up: Delete the linked list nodes
        current = head;
        while (current != nullptr)
        {
            AnimalNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
