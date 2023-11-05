#include <iostream>
#include <fstream>
using namespace std;

class VirtualPetCat
{
private:
    string name;
    int hunger;
    int mood;

public:
    VirtualPetCat(const string &petName) : name(petName), hunger(50), mood(50) {}

    void feed()
    {
        if (hunger == 100)
        {
            cout << name + " has been fed already\n";
            return;
        }
        int ch;
        cout << "\nWhat would you feed your cat?\n";
        cout << "1 for Milk\n";
        cout << "2 for Fishy Candy\n";
        cout << "3 for Pani Purry\n";
        cout << "4 for Paw Bhaji\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << name + " drank the milk and loved it!\n";
            hunger += 10;
            break;
        case 2:

            cout << name + "  eats Fishy candy and licks her paws!\n";
            hunger += 30;
            break;
        case 3:
            cout << name + " eats Pani purry and wants more!\n";
            hunger += 50;
            break;
        case 4:
            cout << name + " eats Paw bhaji and is completely fed!!\n";
            hunger = 100;
            break;

        default:
            break;
        }

        if (hunger > 100)
            hunger = 100;
        mood -= 15;
        if (mood <= 0)
        {
            mood = 0;
            cout << name + " is sad...\n";
        }
        cout << "\nHunger level: " << hunger << endl;
    }

    void play()
    {
        if (hunger == 0)
        {
            cout << name + " is hungry and doesn't want to play...\n";
            return;
        }
        int ch;
        cout << "\nWhat would you play your cat?\n";
        cout << "1 for Feather Wand\n";
        cout << "2 for Pet\n";
        cout << "3 for Walk\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << name + " plays with the feather wand, tries to pounce on it and loves it!\n";
            mood += 10;
            break;
        case 2:
            cout << name + " sits calmly on your thighs and you pet her, she purrs!\n";
            mood += 30;
            hunger += 50;
            break;
        case 3:
            cout << "You take " + name + " for a walk!\n";
            mood += 50;
            break;

        default:
            break;
        }
        if (hunger < 50)
            hunger = 0;
        else
            hunger -= 50;
        try
        {
            string s = name + " is hungry\n";
            if (hunger == 0)
                throw s;
        }
        catch (string s)
        {
            cout << s << '\n';
        }
        if (mood >= 100)
            mood = 100;
        cout << " Mood: " << mood << endl;
    }

    void displayStatus()
    {
        cout << "Name: " << name << endl;
        cout << "Hunger: " << hunger << ", Mood: " << mood << endl;
    }

    void saveToFile()
    {
        ofstream petFile(name + ".txt");
        petFile << name << endl;
        petFile << hunger << endl;
        petFile << mood << endl;
        petFile.close();
    }

    void loadFromFile()
    {
        ifstream petFile(name + ".txt");
        try
        {
            if (petFile.is_open())
            {
                getline(petFile, name);
                petFile >> hunger >> mood;
                petFile.close();
                cout << name << " has been loaded from file." << endl;
            }
            else
            {
                string s = "No file name " + name + " found";
                throw s;
            }
        }
        catch (string s)
        {
            cout << s << endl;
            cout << "Creating new file\n";
        }
    }
};

int main()
{
    string petName;
    cout << "                   /\\_____/\\\n                  /  o   o  \\\n                 ( ==  ^  == )\n                  )         (\n                 (           )\n                ( (  )   (  ) )\n               (__(__)___(__)__)" << endl;

    cout << "*****Welcome to the Virtual Pet Cat program!*****" << endl;
    cout << "Enter the name of your pet cat: ";
    cin >> petName;

    VirtualPetCat cat(petName);

    cat.loadFromFile();

    int choice;

    do
    {
        cout << "\nOptions:\n";
        cout << "1 for Feed " << petName << endl;
        cout << "2 for Play with " << petName << endl;
        cout << "3 for Display " << petName << "'s Status" << endl;
        cout << "4 for Save " << petName << " to File" << endl;
        cout << "5 for Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cat.feed();
            break;
        case 2:
            cat.play();
            break;
        case 3:
            cat.displayStatus();
            break;
        case 4:
            cat.saveToFile();
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
