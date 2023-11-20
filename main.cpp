/**
 * 
 * File name   : StudentRcdMgmtSys/main.cpp
 * Description : This program is made to manage student records for a fictional school
 *              The target of this project is to demonstrate how user-defined function
 *              are defined and used in a program.
 * Programmer  : Zul Iskandar bin Zainorhan
 * 
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global Variables declaration
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
const string schoolName = "Starlight High School";    // school name
const int studentLimit  = 50;                         // the limit for number of student

int studentID[studentLimit];                          // Students' ID
string studentName[studentLimit];                     // Students' Name
double scores[studentLimit];                          // Students' Score
int attendances[studentLimit];                        // Students' Attendeance
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// functions declarations
void inputStudentData(   int (&ids)[],
                         string (&names)[],
                         double (&scores)[],
                         int (&attendances)[],
                         int maxData);               // Data Input

double  calculateAverageScores( double scoreArray[],
                                int numStudent);     // Calculate Average Scores

void    displayStudentRecords(  int ids[],
                                string names[],
                                double scores[],
                                int attendances[],
                                int maxData);        // Display Student Records
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Sample Data
 * 
 * Description:
 *     Sample data is provided only for testing and debugging.
 * 
 *     Sample data only contain 50 sample data and can only be
 *     altered through programming session. To use a sample data,
 *     just enable it by changing variable usingSampleData to true.
 * 
 *     Programmer can change number of sample data by changing the
 *     value of variable usingLimitedSample in arange of 1 to 50.
 * 
 * Warning: Please disable it before run this code for testing
 * or using with real data or user-input data.
*/
bool usingSampleData = false;           // change to true for using sample data

int usingLimitedSample =  10;           // set a number of sample to be used in a range 1-50
int sampleId[] = {                      // sample Id
    80000, 80001, 80002, 80003, 80004, 80005, 80006, 80007, 80008, 80009,
    80010, 80011, 80012, 80013, 80014, 80015, 80016, 80017, 80018, 80019,
    80020, 80021, 80022, 80023, 80024, 80025, 80026, 80027, 80028, 80029,
    80030, 80031, 80032, 80033, 80034, 80035, 80036, 80037, 80038, 80039,
    80040, 80041, 80042, 80043, 80044, 80045, 80046, 80047, 80048, 80049
};
string sampleName[] = {                 // sample Name
    "N00", "N01", "N02", "N03", "N04", "N05", "N06", "N07", "N08", "N09",
    "N10", "N11", "N12", "N13", "N14", "N15", "N16", "N17", "N18", "N19",
    "N20", "N21", "N22", "N23", "N24", "N25", "N26", "N27", "N28", "N29",
    "N30", "N31", "N32", "N33", "N34", "N35", "N36", "N37", "N38", "N39",
    "N40", "N41", "N42", "N43", "N44", "N45", "N46", "N47", "N48", "N49"
};
double sampleScores[] = {               // sample Scores
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100
};
int sampleAttendance[] = {              // sample Attendance
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40
};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------



/**
 * Main function
 * 
 * Description:
 *     Main function is where the program will run.
*/
int main() {
    // the program will run until Exit action called
    bool runProgram = true;
    while (runProgram) {
        //ask to use a function
        cout << setfill('-') << setw(100) << "-"   << endl;
        cout << "Student Record Management System" << endl;
        cout << "School Name: " << schoolName      << endl;

        cout << "\n\nPlease Choose an Action:"     << endl;
        cout << "1 - Input Student Data"           << endl;
        cout << "2 - Calculate Average Score"      << endl;
        cout << "3 - Display Student Records"      << endl;
        cout << "4 - Exit"                         << endl;

        int funcCode;
        cout << "\nAction Code: ";
        cin >> funcCode;

        // if not using sample data
        if (!usingSampleData){
            switch (funcCode) {
                case 1: inputStudentData(studentID, studentName, scores, attendances, studentLimit);                             // Input Student Data
                    break;                    
                    
                case 2: cout << "Average score among " << studentLimit << " students is "                                        // Calculate Average Score
                             << calculateAverageScores(scores, studentLimit) << " over 100. ["                     
                             << calculateAverageScores(scores, studentLimit) << "/100]\n" << endl;                    
                    break;                    
                    
                case 3: displayStudentRecords(studentID, studentName, scores, attendances, studentLimit);                        // Display Student(s) Records
                    break;                    
                    
                case 4: runProgram = false;                                                                                      // Exit Program
                    break;                    
                    
                default: cout << "Function not Available" << endl;                                                               // Error Catch if function code inputed is invalid
                    break;
            }
        }

        // if using sample data[only during testing and debugging]
        if (usingSampleData){
            switch (funcCode) {
                case 1: cout << "\nAttention: \"usingSampleData\" is enable. Please disable first before use\n" << endl;         // Input Student Data
                    break;

                case 2: cout << "Average score among " << usingLimitedSample << " students is "                                  // Calculate Average Score
                             << calculateAverageScores(sampleScores, usingLimitedSample) << " over 100. [" 
                             << calculateAverageScores(sampleScores, usingLimitedSample) << "/100]\n" << endl;
                    break;

                case 3: displayStudentRecords(sampleId, sampleName, sampleScores, sampleAttendance, usingLimitedSample);         // Display Student(s) Records
                    break;
                    
                case 4: runProgram = false;                                                                                      // Exit Program
                    break;

                default: cout << "Function not Available" << endl;                                                               // Error Catch if function code inputed is invalid
                    break;
            }
        }

        char holdProgram = ' ';
        cout << "Press any key then press ENTER to continue: "; cin >> holdProgram; cout << "\n\n\n\n";

    }
    cout << "Program Ended" << endl;
    return 0;
}

/** Input Students' Data function
 * 
 * Description:
 *     This function will be turned of during output and display testing.
 *     This function is used to input students records that may consist of
 *     their name, student id, score, and attendance.
 *     
 *     The input session will be last until the maximum data needed is reach
 *     which is controlled by setting the parameter maxData.
*/
void inputStudentData(  int (&ids)[],         // List of IDs
                        string (&names)[],    // List of Names
                        double (&scores)[],   // List of Scores
                        int (&attendances)[], // List of Attendance
                        int maxData) {        // Maximum number of student
    // input operation
    for (int dataIndex = 0; dataIndex < maxData; dataIndex++) {
        cout << "\nInput Student" << (dataIndex + 1) << " Data:\n" << endl;

        cout << "ID"         << setfill('-') << setw(13) << ":"; cin >> ids[dataIndex];
        cout << "Name"       << setfill('-') << setw(11) << ":"; cin >> names[dataIndex];
        cout << "Score"      << setfill('-') << setw(10) << ":"; cin >> scores[dataIndex];
        cout << "Attendance" << setfill('-') << setw(5)  << ":"; cin >> attendances[dataIndex];

        // Print out stored data
        cout << "\nStudent " << dataIndex << ", Completed.";
        cout << "\nInformation:\n";

        cout << "|->ID"           << setfill('-') << setw(13) << ":" << ids[dataIndex]         << endl;
        cout << "|->Name"         << setfill('-') << setw(11) << ":" << names[dataIndex]       << endl;
        cout << "|->Score"        << setfill('-') << setw(10) << ":" << scores[dataIndex]      << endl;
        cout << "+->Attendance"   << setfill('-') << setw(5)  << ":" << attendances[dataIndex] << endl;
    }
}

/** Calculate Average Scores function
 * 
 * Description:
 *     This function is used to calculate the average score of all students in
 *     a given record.
 * 
 *     The average is calculate by using this equation:
 *         average = total score / number of students
 * 
*/
double calculateAverageScores(double scoreArray[], // List of Scores
                              int numStudent) {    // Number of Students
    double totalScore = 0;
    for (int i = 0; i < numStudent; i++) totalScore += scoreArray[i];
    return totalScore / numStudent;
}

/** Display a Student's Records
 * 
 * Description:
 *     This function is used to display student(s)' records in table form.
 *     This function allow users to choose any data to be hidden or to be
 *     shown. This is also to keep the data to be shown limited to public
 *     or to make a priority of targeted data.
*/
void displayStudentRecords( int ids[],         // Students' IDs
                            string names[],    // Students' Names
                            double scores[],   // Students' Scores
                            int attendances[], // Students' Attendances
                            int maxData) {     // Maximum number of records
    cout << "\nDisplay Student Records\n" << endl;

    // Configure display configuration
    cout << "\nConfigure output display\n" << endl;
    cout << "Type 1 for enable display, 0 to disable display" << endl;
    cout << "Select display configuration:\n" << endl;

    int displayIdConfig    = 0; cout << setw(20) << "Show Id: "        ; cin >> displayIdConfig;    // Confugure Id display
    int displayNameConfig  = 0; cout << setw(20) << "Show Name: "      ; cin >> displayNameConfig;  // Confugure Name display
    int displayScoreConfig = 0; cout << setw(20) << "Show Score: "     ; cin >> displayScoreConfig; // Confugure Score display
    int displayAtdConfig   = 0; cout << setw(20) << "Show Attendance: "; cin >> displayAtdConfig;   // Confugure Attendance display

    // Configure data selection
    cout << "\nConfigure data selection\n" << endl;

    cout << "0 - All Student"    << endl;
    cout << "1 - Search by Id"   << endl;
    cout << "2 - Search by Name" << endl;
    
    int dataSelection;
    cout << "Select data selection:";
    cin >> dataSelection;

    switch (dataSelection) {
        // Display all records
        case 0:
        {
            // Print records in table form
            cout << "+" << setfill('-') << setw(12) << "ID"
                 << "+" << setfill('-') << setw(20) << "NAME"
                 << "+" << setfill('-') << setw(6)  << "SCORE"
                 << "+" << setfill('-') << setw(11) << "ATTENDANCE"
                 << "+" << endl;
            for(int tableIndex = 0; tableIndex < maxData; tableIndex++) {
                cout << "|" << setw(12); if (displayIdConfig    == 1) cout << ids[tableIndex];         if (displayIdConfig    == 0) cout << "Hidden"; // ID
                cout << "|" << setw(20); if (displayNameConfig  == 1) cout << names[tableIndex];       if (displayNameConfig  == 0) cout << "Hidden"; // Name
                cout << "|" << setw( 6); if (displayScoreConfig == 1) cout << scores[tableIndex];      if (displayScoreConfig == 0) cout << "Hidden"; // Score
                cout << "|" << setw(11); if (displayAtdConfig   == 1) cout << attendances[tableIndex]; if (displayAtdConfig   == 0) cout << "Hidden"; // Attendance
                cout << "|" << endl;
            }
            cout << "+" << setfill('-') << setw(12) << "-"
                 << "+" << setfill('-') << setw(20) << "-"
                 << "+" << setfill('-') << setw(6)  << "-"
                 << "+" << setfill('-') << setw(11) << "-"
                 << "+\n\n\n" << endl;

            break;
        }
        
        // Display selection with Id
        case 1:
        {
            // Scanning all IDs to find the given ID in records
            int numberOfId = maxData;

            int searchingId;
            cout << "Enter ID:";
            cin >> searchingId;

            cout << "\n\n\n" << endl;

            int idIndex = 0;
            while (idIndex < numberOfId) {
                cout << ids[idIndex] << endl;
                if (ids[idIndex] == searchingId) break;
                idIndex += 1;
            }

            // Display selection results
            if (idIndex < numberOfId) {
                // Print record in table form
                cout << "+" << setfill('-') << setw(12) << "ID"
                     << "+" << setfill('-') << setw(20) << "NAME"
                     << "+" << setfill('-') << setw(6)  << "SCORE"
                     << "+" << setfill('-') << setw(11) << "ATTENDANCE"
                     << "+" << endl;
                cout << "|" << setw(12); if (displayIdConfig    == 1) cout << ids[idIndex];         if (displayIdConfig    == 0) cout << "Hidden"; // ID
                cout << "|" << setw(20); if (displayNameConfig  == 1) cout << names[idIndex];       if (displayNameConfig  == 0) cout << "Hidden"; // Name
                cout << "|" << setw( 6); if (displayScoreConfig == 1) cout << scores[idIndex];      if (displayScoreConfig == 0) cout << "Hidden"; // Score
                cout << "|" << setw(11); if (displayAtdConfig   == 1) cout << attendances[idIndex]; if (displayAtdConfig   == 0) cout << "Hidden"; // Attendance
                cout << "|" << endl;
                cout << "+" << setfill('-') << setw(12) << "-"
                     << "+" << setfill('-') << setw(20) << "-"
                     << "+" << setfill('-') << setw(6)  << "-"
                     << "+" << setfill('-') << setw(11) << "-"
                     << "+\n\n\n" << endl;

            } else cout << "ID is not available\n\n" << endl;
            break;
        }

        // Display selection with name
        case 2:
        {
            // Scanning all names to find the given name in records
            int numberOfName = maxData;

            string searchingName;
            cout << "Enter Name: ";
            cin >> searchingName;

            cout << "\n\n\n" << endl;

            int nameIndex = 0;
            while (nameIndex < numberOfName) {
                if (names[nameIndex] == searchingName) break;
                nameIndex += 1;
            }

            if (nameIndex < numberOfName) {
                // Print record in table form
                cout << "+" << setfill('-') << setw(12) << "ID"
                     << "+" << setfill('-') << setw(20) << "NAME"
                     << "+" << setfill('-') << setw(6)  << "SCORE"
                     << "+" << setfill('-') << setw(11) << "ATTENDANCE"
                     << "+" << endl;
                cout << "|" << setw(12); if (displayIdConfig    == 1) cout << ids[nameIndex];         if (displayIdConfig    == 0) cout << "Hidden"; // ID
                cout << "|" << setw(20); if (displayNameConfig  == 1) cout << names[nameIndex];       if (displayNameConfig  == 0) cout << "Hidden"; // Name
                cout << "|" << setw( 6); if (displayScoreConfig == 1) cout << scores[nameIndex];      if (displayScoreConfig == 0) cout << "Hidden"; // Score
                cout << "|" << setw(11); if (displayAtdConfig   == 1) cout << attendances[nameIndex]; if (displayAtdConfig   == 0) cout << "Hidden"; // Attendance
                cout << "|" << endl;
                cout << "+" << setfill('-') << setw(12) << "-"
                     << "+" << setfill('-') << setw(20) << "-"
                     << "+" << setfill('-') << setw(6)  << "-"
                     << "+" << setfill('-') << setw(11) << "-"
                     << "+\n\n\n" << endl;

            } else cout << "Name is not available\n\n" << endl;

            break;
        }
    }
}


