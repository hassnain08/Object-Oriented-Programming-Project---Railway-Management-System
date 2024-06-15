#include <iostream>
#include <fstream>//file handling
#include <iomanip>//used for setfill
#include <stdlib.h>
#include <cstdio>
#include <string.h>//string
#include <conio.h>
#include <cstdlib>
#include<limits>//streamsize 


/*operator overloading, classes, inheritance and encapsulation done.*/

using namespace std;
void mainMenu2();
void firstPage();
void waitForEnter();
void displayMenu();
void foodOptions();
void welcomeMessage(); 

class Management
{
public:
    Management()
    {
        welcomeMessage();
    }
};

void waitForEnter()
{
    cout << "Press Enter to continue...";
    cin.ignore(); // Ignore any leftover characters in the input buffer
    cin.get();    // Wait for the user to press Enter
}


void firstPage()
{
    cout << setw(80) << setfill('-') << "-"  << endl;
    cout  << "1. Registration"  << endl;
    cout  << "2. Login" << endl;
    cout  << "3. Terms and Conditions"  << endl;
    cout  << "4. Project Credits" <<  endl;
    cout  << "5. OOP Concepts Used" << endl;
    cout  << "6. Exit" << endl;
    cout  << setw(80) << setfill('-') << "-" << endl;

    int choice;
     cout << "Choose(1-6):" << endl;

    while (!(cin >> choice) || choice < 1 || choice > 6) {
        cout << "Invalid input. Please enter a number from 1 to 6: ";
        cin.clear();//clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard the invalid input
    }

    system("cls"); 
  switch (choice)
{
case 1:
{
    cout<<"User Registration: Creating a new account" << endl;

    string uid, upass;
    cout << "Enter the New ID: ";
    cin >> uid;// Check if uid contains a negative sign
    
    while (uid.find('-') != string::npos)
    /*npos=maximum possible value of sting 
    returned when the searched-for substring or character is not found*/
    {
        cout << "ID cannot contain a negative sign. Please enter a valid ID: ";
        cin >> uid;
    }

    cout << "Enter Password: ";
    cin >> upass;

    ofstream outFile("user.txt", ios::app); //file handling
    if (outFile.is_open())
    {
        outFile << uid << " " << upass << endl; // Store ID and password
        outFile.close(); // Close the file after adding the new user
        cout << "New User ID created!\n";
        cout << "Your User ID is " << uid << ", password is " << upass << endl;
    }
    else 
    {
        cout << "Error: Unable to open file for writing!" << endl;
    }

    firstPage();
    break;
}
case 2:
{
    cout << "__________________________________________________________________________________" << endl;
    cout << "__________________________________LOGGING IN_______________________________________" << endl;
    string uid, upass;
    string cuidFromFile, cupassFromFile;

    cout << "\nEnter ID: ";
    cin >> uid;

    cout << "\nEnter Password: ";
    cin >> upass;

    ifstream f1("user.txt"); // Open user data file in input mode
    if (f1.is_open()) {
        bool found = false;// Flag to indicate if credentials are found

        // Loop through each line in the file to read user data
        while (f1 >> cuidFromFile >> cupassFromFile) {
            if (uid == cuidFromFile && upass == cupassFromFile)
            {
                found = true; // Credentials matched
                cout << "\nCredentials Matched!" << endl;
                cout << "\n_____________________________________________________________________________________" << endl;
                break; 
            }
        }
        f1.close();//Close file

        if (!found) {//if credentials are not found
            cout << "\nIncorrect Password or ID!." << endl;
            cout << "\n_____________________________________________________________________________________" << endl;
            waitForEnter();
            system("cls");
            firstPage();//go back to the login page
        } else {
            waitForEnter();//wait for user to press Enter
            system("cls");
            mainMenu2();//display main menu
        }
    }
    else
    {
        cout << "Error: Unable to open file for reading!" << endl;
    }
   break;
}
    case 3:
    {
     // ANSI escape codes for text color
    const string red = "\033[1;31m";
    const string green = "\033[1;32m";
    const string blue = "\033[1;34m";
    const string reset = "\033[0m"; // Reset to default color
    

    cout << red << "|---------------------------------------------------------------------------------------------------------------------------|" << reset << endl;
    
    cout << green << "|                                         Terms and Conditions for Railway Operations                                       |" << reset << endl;
    
    cout << blue << "|-------------------------------------------------------------------------------------------------------------------------- |" << reset << endl<<endl;
    
    // Terms and Conditions
   cout << "| 1.\033[1;33m Schedule Adherence\033[0m: Ensuring trains depart and arrive at their scheduled times." << endl;
    cout << "| 2. \033[1;33mOccupancy Monitoring\033[0m: Tracking the number of passengers on board to manage seating availability and safety." << endl;
    cout << "| 3. \033[1;33mTrack and Signal Conditions\033[0m: Monitoring track conditions and signals to ensure safe and efficient travel." << endl;
    cout << "| 4. \033[1;33mWeather Conditions\033[0m: Considering weather forecasts to anticipate and mitigate potential disruptions." << endl;
    cout << "| 5. \033[1;33mMaintenance Status\033[0m: Checking the maintenance status of trains and equipment to prevent breakdowns." << endl;
    cout << "| 6. \033[1;33mEmergency Protocols\033[0m: Establishing protocols for handling emergencies such as accidents or medical incidents." << endl;
    cout << "| 7. \033[1;33mStaffing Levels\033[0m: Ensuring appropriate staffing levels for onboard crew and station personnel." << endl;
    cout << "| 8. \033[1;33mTicketing and Payment Systems\033[0m: Managing ticket sales, validations, and payments." << endl;
    cout << "| 9. \033[1;33mSecurity Measures\033[0m: Implementing security measures to safeguard passengers and assets." << endl;
    cout << "|10. \033[1;33mCustomer Feedback and Complaints\033[0m: Monitoring feedback and addressing passenger complaints promptly to improve service quality." << endl;
   
    cout << red <<endl << "|-----------------------------------------------------------------------------------------------------------------------------|" << reset << endl;
waitForEnter();
    system("cls");
    firstPage();
    break;
    }
case 4:
{  
    cout << "__________________________________________________________________________________" << endl;
    cout << "_______________________________PROJECT MEMBERS____________________________________" << endl;
    cout << endl;
    cout << "   Project Members:" << endl;
    cout << "   ----------------" << endl;
    cout << "   - Hassnain Abbas (23P-3029)" << endl;
    cout << "   - Ali Umar       (23P-3041)" << endl;
    cout << "   - Talha Zia      (22P-9228)" << endl;
    cout << endl;
    cout << "   ----------------" << endl;
    cout << "__________________________________________________________________________________" << endl;
    waitForEnter();
    system("cls");
    firstPage();
    break;
}

    case 5:
    {
        cout<<"----------------------------------------------\n";
        cout<<"\nwe used the following oop concepts:\n";
        cout<<"1.classes\n2.inheritance\n3.operator overloading -> line: 1028\n4.encapsulation -> line: 1021\n5.factory function -> line: 1444\n";
        cout<<"\n-----------------------------------------------";
        cout<<endl;
        waitForEnter();
        system("cls");
        firstPage();
    }
    case 6:
    {

        cout << "___________________Thanks for using RMS_____________________" << endl
             << endl;
        exit(0);
    }
}
}

void welcomeMessage()
{

    cout << "\033[1;32m/                            <<<<<<<<<<<<<<<<                >>>>>>>>>>>>>>>> \033[0m" << endl;
    cout << "\033[1;32m                           |                   R A I L W A Y                  |\033[0m" << endl;
    cout << "\033[1;33m                           |                M A N A G E M E N T               |\033[0m" << endl;
    cout << "\033[1;32m                           |                    S Y S T E M                   |\033[0m" << endl;

    cout << "\033[1;32m                           +--------------------------------------------------+\033[0m" << endl;


    cin.get();
    system("cls"); // Clear screen
    firstPage();
}

class Details
{
public:
    static string name[6], gender[6];
    int phoneNo;
    static int age[6];
    static int cId[6];
    char arr[100];
    static int n;
    static string cnic[6]; 

void information()
{
    cout << "\nEnter the number of passengers: ";
    cin >> n;

    if (cin.fail() || n < 1 || n > 6)
    {
        cout << "Invalid input. You can book tickets for only 1 to 6 passengers in a ticket." << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard wrong input.
        information();
        return;//exit
    }

    for (int i = 0; i < n; i++)
    {
        string tempCnic; // Temporary variable for CNIC input
        cout << "\nEnter the customer ID: ";
        cin >> cId[i];
        if (cin.fail())
        {
            cout << "Invalid customer ID input. Please enter again." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            i--;//decrement i to re-enter the current passenger's details
            continue;//skip to the next iteration of the loop
        }
        cout << "\nEnter the Name: ";
        cin >> name[i];
         for (int i = 0; i < n; ++i)
         {
    cout<<"\nEnter the age for passenger " << i + 1 << ": ";
    cin>>age[i];
    
            if (cin.fail() || age[i] < 18 )
        {
            cout << "elligible age for booking ticket. (Must be atleast 18)" << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard invalid input
            i--;//Decrement i to re-enter the age for the current passenger
        }
    }

        for (int i = 0; i < n; ++i)
        {
    while (true)
    {
        cout << "\nEnter your CNIC ID: ";
        cin >> tempCnic;

        if (tempCnic.find_first_not_of("0123456789-") == string::npos)
        {
            cnic[i] = tempCnic;
            break; //exit  loop if CNIC valid
        }
        else {
            cout << "Invalid input! Please enter a valid CNIC." << endl;
        }
    }
}
        cout << "\nEnter gender: ";
        cin >> gender[i];
    }
    cout << "Your details are saved with us." << endl;
}
};

//defining initialized variables from class outside the class
int Details::cId[6] = {0};
string Details::name[6] = {""};
string Details::gender[6] = {""};
string Details::cnic[6] = {""};
int Details::age[6] = {0};
int Details::n = 0;

class registration :public Details
{
//TrainBooking
public:
    static int choice;
    int choice1;
    static float charges;

    void trains()
    {
        cout<<"-----------------------------------------------------------\n";
        cout<<"      Welcome To The Railway Ticketing Section!            "<<endl;
        cout<<"-----------------------------------------------------------\n\n";

        string trainsN[] = {"| Rawalpindi ", "| Karachi ", "| Lahore ", "| Taxila ", "| Faisalabad ", "| Hyderabad"};

         for (int a = 0; a < 6; a++) 
    {
        cout << (a + 1) << ". Book Train to --> \033[1;31m" << trainsN[a] << "\033[0m" << endl;
    }

        
cout << "\nSelect the City you want to travel to from your nearest train station..";
    while (!(cin >> choice1) || choice1 < 1 || choice1 > 6)
    {
    cout << "Invalid input. Please enter a number between 1 and 6: ";
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
        
        switch(choice1)
        {
    case 1:
{
    system("cls");
    cout << "\n\n|              WELCOME TO Rawalpindi              |\n" << endl;
    cout << "|your comfort is our priority, enjoy the journey!|" << endl << endl;
    cout << " Following are the available trains: \n" << endl << endl;

    cout << " 1.RWP-123 " << endl;
    cout << "| Date:\033[1;32m 08-01-2022\033[0m | Time:\033[1;32m 8:00AM\033[0m | Duration:\033[1;32m 10 hrs\033[0m |"<< endl;  
    cout << "| 3- Rs.\033[1;32m 2100 [E]\033[0m   | 2- Rs.\033[1;32m3100 [B]\033[0m   | 1- Rs.\033[1;32m5200 [S]\033[0m   |" << endl << endl;

    cout << " 2.RWP-345 " << endl;
    cout << "| Date:\033[1;32m 09-01-2022\033[0m | Time:\033[1;32m 2:00PM\033[0m | Duration:\033[1;32m 14 hrs\033[0m |"<< endl;  
    cout << "| 3- Rs.\033[1;32m 2350 [E]\033[0m   | 2- Rs.\033[1;32m3300 B]\033[0m   | 1- Rs.\033[1;32m5450 [S]\033[0m   |" << endl << endl;

    cout << " 3.RWP-456 " << endl;
    cout << "| Date:\033[1;32m 10-01-2022\033[0m | Time:\033[1;32m 12:00AM\033[0m | Duration:\033[1;32m 11 hrs\033[0m |"<< endl;  
    cout << "| 3- Rs.\033[1; 32m2400 [E]\033[0m   | 2- Rs.\033[1;32m3500 [B]\033[0m   | 1- Rs.\033[1;32m5100 [S]\033[0m   |" << endl << endl;


    cout << "\nSelect the Trains you want to book : ";
    cout << "\n";
    cin >> choice1;

    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }

    int f;

    while (true) {
    cout << "\nSelect Class:\n1. Sleeper.\n2. Business Class.\n3. Economy Class.\nEnter Class: ";
    cin >> f;

    if (cin.fail() || f < 1 || f > 3) {
        cout << "Invalid input. Please enter a number between 1 and 3." << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    } else {
        if (choice1 == 1) {
            if (f == 3) {
                charges = 2100;
            } else if (f == 2) {
                charges = 3100;
            } else if (f == 1) {
                charges = 5200;
            }
            cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
            cout<<"TRAIN NUMBER: | RWP-123 |" << endl << endl;
            cout << "\nPlease Choose Option 3 in Main Menu To Print Your Ticket Receipt. Thank you! " << endl;
        } else if (choice1 == 2) {
            if (f == 3) {
                charges = 2300;
            } else if (f == 2) {
                charges = 3300;
            } else if (f == 1) {
                charges = 5400;
            }
            cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | RWP-345 |" << endl << endl;
            cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Receipt. Thank you! " << endl;
        } else if (choice1 == 3)
        {
            if (f == 3) {
                charges = 2400;
            } else if (f == 2) {
                charges = 3500;
            } else if (f == 1) {
                charges = 5100;
            }
            cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
            cout<<"TRAIN NUMBER: | RWP-456 |" << endl << endl;
            cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Receipt. Thank you! " << endl;
        }
        else
        {
            cout << "Invalid input, shifting to the previous menu" << endl;
            trains();
        }
        waitForEnter();
        system("cls");
        mainMenu2();
        break; // Exit the loop if input is valid
    }
}


      case 2:
{   
    system("cls");
    cout << "|               WELCOME TO Karachi                |\n" << endl;
    cout << "|your comfort is our priority , Enjoy the journey!|" << endl << endl;
    cout << " Following are the Trains: \n" << endl << endl;

    cout << " 1.KHI-897 " << endl;
    cout << "| Date:\033[1;32m20-01-2022\033[0m | Time: \033[1;32m8:00PM\033[0m | Duration: \033[1;32m10hrs\033[0m |"<< endl;  
    cout << "| 3-Rs.\033[1;32m1800 [E]\033[0m   | 2-Rs.\033[1;32m2600 [B]\033[0m   | 1-Rs.\033[1;32m4400 [S]\033[0m   |" << endl << endl;

    cout << " 2.KHI-567 " << endl;
    cout << "| Date:\033[1;32m21-01-2022\033[0m | Time: \033[1;32m10:00PM\033[0m | Duration: \033[1;32m15hrs\033[0m |"<< endl;  
    cout << "| 3-Rs.\033[1;32m1900 [E]\033[0m   | 2-Rs.\033[1;32m2200 [B]\033[0m   | 1-Rs.\033[1;32m4800 [S]\033[0m   |" << endl << endl;

    cout << " 3.KHI-789 " << endl;
    cout << "| Date:\033[1;32m22-01-2022\033[0m | Time: \033[1;32m11:00PM\033[0m | Duration: \033[1;32m20hrs\033[0m |"<< endl;  
    cout << "| 3-Rs.\033[1;32m1700 [E]\033[0m   | 2-Rs.\033[1;32m2100 [B]\033[0m   | 1-Rs.\033[1;32m4500 [S]\033[0m   |" << endl << endl;

    int choice1;
    //cout << "\n Select the TRAINS you want to book : ";
    //cin >> choice1;

    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }

    int f;

    while (true) {
        cout << "\n Select Class:\n1.Sleeper.\n2.Business Class.\n3.Economy Class.\nEnter Class:";
        cin >> f;

        if (cin.fail() || f < 1 || f > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();                                                          // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Discard invalid input
        }
        else
        {
            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | KHI-123 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | KHI-345 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
               cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | KHI-456 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }
            waitForEnter();
            system("cls");
            mainMenu2();
            break; // Exit the loop if input is valid
        }
    }
    break;
}

        case 3:
        {
            system("cls");
            cout << "\n\n|                WELCOME TO Lahore                 |\n" << endl;
            cout << "|your comfort is our priority , Enjoy the journey! |" << endl << endl;
            cout << " Following are the TRAINS \n" << endl << endl;

            cout << " 1.LHR-123 " << endl;
            cout << "| Date:\033[1;32m24-01-2022\033[0m | Time: \033[1;32m12:00AM\033[0m | Duration: \033[1;32m10hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m2200 [E]\033[0m   | 2-Rs.\033[1;32m3200 [B]\033[0m   | 1-Rs.\033[1;32m5500 [S]\033[0m   |" << endl << endl;

            cout << " 2.LHR-345 " << endl;
            cout << "| Date:\033[1;32m25-01-2022\033[0m | Time: \033[1;32m2:00PM\033[0m  | Duration: \033[1;32m15hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m2300 [E]\033[0m   | 2-Rs.\033[1;32m3400 [B]\033[0m   | 1-Rs.\033[1;32m5600 [S]\033[0m   |" << endl << endl;

            cout << " 3.LHR-456 " << endl;
            cout << "| Date:\033[1;32m26-01-2022\033[0m | Time: \033[1;32m4:00PM\033[0m  | Duration: \033[1;32m20hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m2400 [E]\033[0m   | 2-Rs.\033[1;32m3600 [B]\033[0m   | 1-Rs.\033[1;32m5700 [S]\033[0m   |" << endl << endl;


    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }

    while (true) {
        cout << "\n Select Class:\n1.Sleeper.\n2.Business Class.\n3.Economy Class.\nEnter Class:";
        cin >> f;

        if (cin.fail() || f < 1 || f > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();                                                          // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Discard invalid input
        }
        else
        {
            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | LHR-123 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | LHR-345 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | LHR-456 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }
            waitForEnter();
            system("cls");
            mainMenu2();
            break; // Exit the loop if input is valid
        }
    }
    break;

}
        case 4:
        {
            system("cls");
            cout << "\n\n|                WELCOME TO Taxila                 |\n" << endl;
            cout << "| your comfort is our priority , Enjoy the journey! |" << endl << endl;
            cout << " Following are the TRAINS \n" << endl << endl;

            cout << " 1.TAXILA-123 " << endl;
            cout << "| Date:\033[1;32m14-03-2022\033[0m | Time: \033[1;32m12:00AM\033[0m | Duration: \033[1;32m10hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1300 [E]\033[0m   | 2-Rs.\033[1;32m1900 [B]\033[0m   | 1-Rs.\033[1;32m3400 [S]\033[0m   |" << endl << endl;

            cout << " 2.TAXILA-345 " << endl;
            cout << "| Date:\033[1;32m15-03-2022\033[0m | Time: \033[1;32m2:00PM\033[0m  | Duration: \033[1;32m15hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1400 [E]\033[0m   | 2-Rs.\033[1;32m2000 [B]\033[0m   | 1-Rs.\033[1;32m3500 [S]\033[0m   |" << endl << endl;

            cout << " 3.TAXILA-456 " << endl;
            cout << "| Date:\033[1;32m16-03-2022\033[0m | Time: \033[1;32m4:00PM\033[0m  | Duration: \033[1;32m20hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1500 [E]\033[0m   | 2-Rs.\033[1;32m2100 [B]\033[0m   | 1-Rs.\033[1;32m4200 [S]\033[0m   |" << endl;

    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }
    
    while (true) {
        cout << "\n Select Class:\n1.Sleeper.\n2.Business Class.\n3.Economy Class.\nEnter Class:";
        cin >> f;

        if (cin.fail() || f < 1 || f > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();                                                          // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Discard invalid input
        }
        else
        {
            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | TAXILLA-123 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | TAXILLA-345 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | TAXILLA-456 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }
            waitForEnter();
            system("cls");
            mainMenu2();
            break; // Exit the loop if input is valid
        }
    }
    break;
}

        case 5:
        {
           system("cls");
            cout << "\n\n|                WELCOME TO Faisalabad                 |\n" << endl;
            cout << "| your comfort is our priority , Enjoy the journey! |" << endl << endl;
            cout << " Following are the TRAINS \n" << endl << endl;

            cout << " 1.FSD-123 " << endl;
            cout << "| Date:\033[1;32m17-01-2022\033[0m | Time: \033[1;32m12:00AM\033[0m | Duration: \033[1;32m10hrs\033[0m |"<< endl;  
            cout << "| 3A-Rs.\033[1;32m2200 [E]\033[0m   | 2A-Rs.\033[1;32m3200 [B]\033[0m   | 1A-Rs.\033[1;32m5300 [S]\033[0m   |" << endl << endl;

            cout << " 2.FSD-345 " << endl;
            cout << "| Date:\033[1;32m18-01-2022\033[0m | Time: \033[1;32m2:00PM\033[0m  | Duration: \033[1;32m15hrs\033[0m |"<< endl;  
            cout << "| 3A-Rs.\033[1;32m2300 [E]\033[0m   | 2A-Rs.\033[1;32m3300 [B]\033[0m   | 1A-Rs.\033[1;32m5400 [S]\033[0m   |" << endl << endl;

            cout << " 3.FSD-456 " << endl;
            cout << "| Date:\033[1;32m19-01-2022\033[0m | Time: \033[1;32m4:00PM\033[0m  | Duration: \033[1;32m20hrs\033[0m |"<< endl;  
            cout << "| 3A-Rs.\033[1;32m2400 [E]\033[0m   | 2A-Rs.\033[1;32m3500 [B]\033[0m   | 1A-Rs.\033[1;32m5500 [S]\033[0m   |" << endl << endl;

    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }

    while (true) {
        cout << "\n Select Class:\n1.Sleeper.\n2.Business Class.\n3.Economy Class.\nEnter Class:";
        cin >> f;

        if (cin.fail() || f < 1 || f > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();                                                          // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Discard invalid input
        }
        else
        {
            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | FSD-123 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | FSD-345 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | FSD-456 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }
            waitForEnter();
            system("cls");
            mainMenu2();
            break; // Exit the loop if input is valid
        }
    }
    break;
}

        case 6:
        {

            system("cls");
            cout << "\n\n|                WELCOME TO Hyderabad                 |\n" << endl;
            cout << "| your comfort is our priority , Enjoy the journey! |" << endl << endl;
            cout << " Following are the TRAINS \n" << endl << endl;

            cout << " 1.HYD-123 " << endl;
            cout << "| Date:\033[1;32m04-09-2022\033[0m | Time: \033[1;32m12:00AM\033[0m | Duration: \033[1;32m10hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1500 [E]\033[0m   | 2-Rs.\033[1;32m2200 [B]\033[0m   | 1-Rs.\033[1;32m3700 [S]\033[0m   |" << endl << endl;

            cout << " 2.HYD-345 " << endl;
            cout << "| Date:\033[1;32m05-09-2022\033[0m | Time: \033[1;32m2:00PM\033[0m  | Duration: \033[1;32m15hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1600 [E]\033[0m   | 2-Rs.\033[1;32m2300 [B]\033[0m   | 1-Rs.\033[1;32m3800 [S]\033[0m   |" << endl << endl;

            cout << " 3.HYD-456 " << endl;
            cout << "| Date:\033[1;32m06-09-2022\033[0m | Time: \033[1;32m4:00PM\033[0m  | Duration: \033[1;32m20hrs\033[0m |"<< endl;  
            cout << "| 3-Rs.\033[1;32m1700 [E]\033[0m   | 2-Rs.\033[1;32m2400 [B]\033[0m   | 1-Rs.\033[1;32m3900 [S]\033[0m   |" << endl;



    while (true) 
    {
        cout << "Select the TRAIN you want to book : ";
        if (!(cin >> choice1) || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 
        else 
        {
            break; // Exit the loop if the choice is valid
        }
    }

    while (true) {
        cout << "\n Select Class:\n1.Sleeper.\n2.Business Class.\n3.Economy Class.\nEnter Class:";
        cin >> f;

        if (cin.fail() || f < 1 || f > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();                                                          // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Discard invalid input
        }
        else
        {
            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | HYD-123 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | HYD-345 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }

            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n THE TRAIN HAS BEEN SUCCESSFULLY BOOKED!"<<endl; 
                cout<<"TRAIN NUMBER: | HYD-456 |" << endl << endl;
                cout << "Please Choose Option 3 in Main Menu To Print Your Ticket Recipt. Thank you! " << endl;            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }
            waitForEnter();
            system("cls");
            mainMenu2();
            break; // Exit the loop if input is valid
        }
    }
    break;
}
        default:
        {
            cout << " invalid input, going back to the main menu.." << endl;
            mainMenu2();
            break;
        }
        }
    }
}
};
//defining the above initialized variables

int registration::choice = 0;
float registration::charges = 0.0f;


class ticket : public registration
{
private: 
    float totalCharges;//encapsulation used here.

public:
    ticket() : totalCharges(0.0f) {}

    void Bill()
    {
    ofstream outf("tickets.txt", ios::app);
    if (!outf)
    {
        cout << "Error opening tickets.txt for writing!" << endl;
        return;
    }

    string destination = "";
    for (int i = 0; i < n; i++) {
        outf << cId[i] << "\t\t|";
        outf << name[i] << "\t|";
        outf << gender[i] << "\t|";

        // Determine destination based on the choice
        switch (choice) {
            case 1:
                destination = "Rawalpindi";
                break;
            case 2:
                destination = "Karachi";
                break;
            case 3:
                destination = "Lahore";
                break;
            case 4:
                destination = "Taxila";
                break;
            case 5:
                destination = "Faisalabad";
                break;
            case 6:
                destination = "Hyderabad";
                break;
            default:
                destination = "N/A";
                break;
        }

        outf << "Your Destination" << "\t\t|";
        outf << destination << "\t\t|";
        outf << charges << "\t|";
        outf << endl;
    }

    // Close the ofstream object
    outf.close();
}

void dispBill()
{
    // Clear the screen before displaying tickets
    system("cls"); 

    cout<<"--------------------------------\n";
    cout<<"           RMS Railways         "<<endl;
    cout<<"          Tickets Recipt            "<<endl;
    cout<<"--------------------------------"<<endl<<endl;

    cout<< "Customer ID\t|"<<"Name\t\t|"<<"Gender\t|"<< "Destination\t\t\t\t\t|"<< "Charge\t|"<<endl;

    ifstream ifs("tickets.txt");
    if (!ifs)
    {
        cout << "Error opening tickets.txt for reading!" << endl;
        return;
    }
    string line;
    while (getline(ifs, line)) {
        cout<<line<<endl;
    }
    ifs.close();
}


void deleteticket()//function to delete the ticket.
{
    string uid;
    cout << "Enter User ID:" << endl;
    cin >> uid;
    cin.ignore();

    ifstream myfile("tickets.txt");
    ofstream temp("temp.txt", ios::app); // Open temp file in append mode

    if (!myfile || !temp) {
        cout << "Error: Unable to open files!" << endl;
        return;
    }

    int ccid;
    string line;
    bool found = false;

    // Read each line from the file
    while (getline(myfile, line))
    {
        istringstream iss(line);
        iss >> ccid; // Assuming ccid is the first value in each line
        if (to_string(ccid) == uid) {
            found = true;
            cout << "Ticket with the specified ID found and deleted!" << endl;
            continue;//skip writing
        }
        // Write ticket details to temp file
        temp << line << endl;
    }

    myfile.close();
    temp.close();

    if (!found)
    {
        cout << "Ticket with the specified ID not found!" << endl;
        remove("temp.txt"); // Remove the temporary file as no ticket was deleted
    } else {
        // Replace original file with temporary file
        if (remove("tickets.txt") != 0)
        {
            cout << "Error: Unable to delete original file!" << endl;
            return;
        }
        if (rename("temp.txt", "tickets.txt") != 0)
        {
            cout << "Error: Unable to rename temporary file!" << endl;
            return;
        }
        cout << "Ticket canceled successfully!" << endl;
    }
}
};

class orderFood : public ticket
{
public:

    string cname, ccid, cgen, cdest, ccharges;
    int fcharges;

    void foodOptions()
{
    cout<<"\n_____________________________________________________________________________"<<endl;
    cout<<"________________________WELCOME TO E-CATERING SERVICE________________________"<<endl
         << endl;
    cout<<"\t1. View Menu and Order Food"<<endl;
    cout<<"\t2. Print Receipt"<<endl;
    cout<<"\t3. Back"<<endl;
   do
   {
        cout << "Enter your choice: ";
        cin >> choice1;

        if (cin.fail() || choice1 < 1 || choice1 > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else
        {
            break; // Break the loop if the input is valid
        }
    }
    while (true);

    switch (choice1)
    {
    case 1:
    {
           
        system("cls");
        displayMenu();
        break;
    }

    case 2:
    {
        system("cls");
        displayFoodReceipt();
        break;
    }

    case 3:
    {
        system("cls");
        mainMenu2();
        break;
    }

    default:
    {
        cout << "Invalid Option! Try Again!" << endl;
        foodOptions();
    }
    }
}

void getDetails()
{
    cout<<"\n____________________________________________________________________" << endl;
    cout<<"Enter Details to continue" << endl;

    string userId, password; // Variables to store user's ID and password
    cout << "Enter your User ID: ";
    cin >> userId;
    cout << "Enter your Password: ";
    cin >> password;

    ifstream userFile("user.txt"); // Open file containing user credentials
    if (!userFile)
    {
        cerr << "Error: Unable to open user credentials file!" << endl;//cerr is like cout but buffer is not included. its used in file handling.
        return;
    }

    string storedUserId, storedPassword; // Variables to store ID and password read from file
    bool found = false;//flag if user credentials are found

    // Loop through each line in the file to read user credentials
    while (userFile >> storedUserId >> storedPassword)
    {
        if (userId == storedUserId && password == storedPassword)
        {
            found = true;//Credentials matched
            break;
        }
    }

    userFile.close();//close  file

    if (found) {
        cout << "User ID and Password verified!" << endl;
        displayMenu();//proceed with the operation
    } else {
        cout << "Incorrect User ID or Password! Please try again." << endl;
        getDetails(); // Retry to get valid credentials
    }
}

void displayMenu()
{
    fcharges = 0;
    cout << "\n____________________________________________________________________" << endl;
    cout << "____________________________FOOD MENU_________________________________" << endl << endl;

    cout << "\t|Serial no."<< "\t|Item Name"<< endl;
    cout << "\t|1."<< "\t|\033[1;33mPasta\033[0m"<< endl;
    cout << "\t|2."<<"\t|\033[1;33mChicken Karhai\033[0m"<< endl;
    cout << "\t|3."<< "\t|\033[1;33mBiryani\033[0m"
         << endl;
    cout << "\t|4."
         << "\t|\033[1;33mKeema\033[0m"
         << endl;
    cout << "\t|5."
         << "\t|\033[1;33mCold Drink\033[0m"
         << endl;
    cout << "\t|6."
         << "\t|\033[1;33mBurger\033[0m"
         << endl;
    cout << "\t|7."
         << "\t|\033[1;33mPizza\033[0m"
         << endl;
    cout << "\t|8."
         << "\t|\033[1;33mChai\033[0m"
         << endl;

    cout<<"--------------------------------------------------------------------------\n";

    int choicess[10], noOfItems;
      cout << "Enter the number of Items you want to book (1-9): ";
    while (!(cin >> noOfItems) || noOfItems < 1 || noOfItems > 9) {
        cout << "Invalid input. Please enter a number between 1 and 9: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ofstream foodFile("foodr.txt", ios::app);//Open file in append mode to add new food items

        for (int i = 0; i < noOfItems; i++)
        {
            tryagain:
            cout << "Enter your Choice " << i + 1 << ": ";
            while (!(cin >> choicess[i]) || choicess[i] < 1 || choicess[i] > 8) {
            cout << "Invalid input. Please enter a valid number between 1 and 8: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choicess[i])
        {
            case 1:
                cout << "\tPasta booked -> \033[32m190\033[0m" << endl;
                fcharges += 190;
                foodFile << "Pasta" << endl; 
                break;
            case 2:
                cout << "\tChicken Karhai booked -> \033[32m210\033[0m" << endl;
                fcharges += 210;
                foodFile << "Chicken Karhai" << endl; 
                break;
            case 3:
                cout << "\tBiryani booked -> \033[32m240\033[0m" << endl;
                fcharges += 240;
                foodFile << "Biryani" << endl; 
                break;
            case 4:
                cout << "\tKeema booked -> \033[32m210\033[0m" << endl;
                fcharges += 210;
                foodFile << "Keema" << endl; 
                break;
            case 5:
                cout << "\tCold Drink booked -> \033[32m250\033[0m" << endl;
                fcharges += 250;
                foodFile << "Cold Drink" << endl; 
                break;
            case 6:
                cout << "\tBurger booked -> \033[32m270\033[0m" << endl;
                fcharges += 270;
                foodFile << "Burger" << endl; 
                break;
            case 7:
                cout << "\tPizza booked -> \033[32m210\033[0m" << endl;
                fcharges += 210;
                foodFile << "Pizza" << endl; 
                break;
            case 8:
                cout << "\tChai booked -> \033[32m240\033[0m" << endl;
                fcharges += 240;
                foodFile << "Chai" << endl; 
                break;
            default:
                cout << "Enter Valid Input!\n";
                goto tryagain;
        }
    }

    foodFile.close(); // Close the file after adding the food items
    cout << "\n\nOrder Placed Successfully! Please collect your Receipt by selecting the Print Receipt option!" << endl;
    system("pause");
    system("cls");
    foodOptions();
}


void displayFoodReceipt() {
    cout << "\n________________________________________________________________________" << endl;
    cout << "______________________________ORDER RECEIPT_________________________________" << endl << endl;

    cout << "\tOrdered Food Details:\n";
    ifstream f4("foodr.txt");
    if (!f4.is_open())
    {//Check if the file is open
        cout << "Error opening food txt file X !" << endl;
        //don't proceed further if there's an error opening the file
        return;
    }

    string foodItem;
    int totalBill = 0; // Variable to store the total bill

    while (getline(f4, foodItem)) { // Read each line from the file
        cout << "\t" << foodItem; // Display the food item
        totalBill += getPrice(foodItem); // Calculate the price of the item and add it to the total bill
        cout << endl; 
    }
    f4.close();

    cout << "\n\tTotal Bill: Rs. " << totalBill << endl;//display the total bill

    //remove the system("pause") as it might cause issues and is unnecessary
    cout<<"\nPress Enter to go back to the food options menu..."<<endl;
    cin.ignore(); //ignore any previous newline characters in the input buffer
    cin.get();//wait for the user to press Enter
    system("cls");

    // Call the foodOptions function to go back to the food options menu
    foodOptions();
}

// Function to get the price of a food item
int getPrice(string foodItem) {
    if (foodItem == "Pasta")
        return 190;
    else if (foodItem == "Chicken Karhai")
        return 210;
    else if (foodItem == "Biryani")
        return 240;
    else if (foodItem == "Keema")
        return 210;
    else if (foodItem == "Cold Drink")
        return 250;
    else if (foodItem == "Burger")
        return 270;
    else if (foodItem == "Pizza")
        return 210;
    else if (foodItem == "Chai")
        return 240;
    else
        return 0; // Return 0 if the food item is not found (this case should not occur)
}
};


void mainMenu2()// concepts of factory architecture design in software development.
{
    int lchoice;
    int schoice, back;

    cout << "\t               XYZ Railways "<<endl<<endl;
    cout << "\t_________________________Main Menu_______________________" << endl;
    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t|\t Press 1 to add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 for Train Booking              \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 to Cancel                      \t|" << endl;
    cout << "\t|\t Press 5 to order food                  \t|" << endl;
    cout << "\t|\t Press 6 to exit                         \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t____________________________________________________________" << endl;

   do
   {
        cout<<"Enter the Choice: ";
        cin>>lchoice;
        if(cin.fail()||lchoice<1||lchoice>6)
        {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else
        {
            break;//break the loop if the input is valid
        }
    }
    while (true);


    Details d;
    registration r;
    ticket t;
    orderFood f;
    // cancel c;

    switch (lchoice)
    {
    case 1:
    {
        char filename[] = "tickets.txt";
        remove(filename);

        cout<<"-------------------\n";
        cout<<"     Customers    "<<endl;
        cout<<"-------------------"<<endl;
        d.information();
       waitForEnter();
       system("cls");
       mainMenu2();
    }

    case 2:
    {
        system("cls");
        r.trains();
        break;
    }

    case 3:
    {
        t.Bill();
        cout<<"-----------------------------------------------------------";
        cout << "Your Ticket is printed, you can collect it" << endl<< endl;
        cout << "Press 1 to display your ticket ";
        cout<<"------------------------------------------------------------";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            waitForEnter();
            system("cls");
            mainMenu2();
        }

        else
        {
            mainMenu2();
        }
        break;
    }

    case 4:
    {
        t.deleteticket();
        cout << "Press any key to go back" << endl;
        waitForEnter();
        system("cls");
        mainMenu2();
        break;
    }
    case 5:
    {
        f.foodOptions();
        break;
    }
    case 6:
    {
        cout<<endl<<endl;
        exit(0);
        break;
    }
    }
}                   

int main()
{
    Management mobj;
    orderFood f;
    f.foodOptions();
    return 0;
}