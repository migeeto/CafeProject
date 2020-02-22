#include <iostream>
#include <string>
#include <list>
#include <vector>

//items for the menu each have a name and cost
class item
{
public:
    std::string itemName;
    float itemCost;
    item(std::string, double);
};
item::item(std::string name, double cost) 
{
    itemName = name;
    itemCost = cost;
}


//creating functions
void run();
std::vector<item> makeMenu();
void printMenu(std::vector<item> menu);
void userChoice(std::vector<item> menu);


//program starts here
int main()
{
    run();
    return 0;
}

//actual content of program
void run()
{
    //generate list of items - menu
    std::vector<item> menu = makeMenu();

    //prints menu
    printMenu(menu);

    //accepts user input
    userChoice(menu);
}

std::vector<item> makeMenu()
{
    //create the food items:
    item coff("Coffee", 2.15);
    item Tea("Tea", 1.75);
    item latt("Latte", 3.75);
    item moch("Mocha", 4.00);
    item sand("Sandwich", 4.50);
    item sCoo("Cookie", 1.25);


    //create the menu
    std::vector<item> menu;
    menu.push_back(coff);
    menu.push_back(Tea);
    menu.push_back(latt);
    menu.push_back(moch);
    menu.push_back(sand);
    menu.push_back(sCoo);

    return menu;
}

void printMenu(std::vector<item> menu)
{
    std::cout << "Welcome to Half Baked, the best cafe around." << std::endl;
    int iterator = 1;
    for (item i : menu) //loops thru items on menu, printing each one with its price (numbered)
    {
        std::cout << iterator << ":" << i.itemName << "-$" << i.itemCost << std::endl;
        iterator++;
    }
    std::cout << "Please select a number from the menu:";
}

void userChoice(std::vector<item> menu)
{
    int pChoice = 0;
    int choiceNum = 0;
    std::cin >> pChoice;
    std::cout << "How many would you like?" << std::endl;
    std::cin >> choiceNum;
    std::cout << "That will be: $" << menu[pChoice-1].itemCost * choiceNum << "." << std::endl;
}