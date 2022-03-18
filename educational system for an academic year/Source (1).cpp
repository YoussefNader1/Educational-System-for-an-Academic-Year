#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>


using namespace std;

#define numberOfSubjects 5
#define manNumberOfStudents 1000
struct STUDENTS
{
	string firstName;
	string secondName;
	int id;
	float subjects[numberOfSubjects];
	float sumOfScore = 0.0;
	float avarageScore = 0.0;
}student[manNumberOfStudents];

vector <STUDENTS> studentsData;
void readfromfile();
void avarage();
void getStudents(int numberOfStudents);
void showHighGrades();
void showLowGrades();
void showNumOfPassedStudentsPerSub();
void standardDiviasion();
void menu();
int main()
{
	int numberOfStudents;
	char answer = 'Y';
	int option = 0;
	while (answer == 'Y' || answer == 'y')
	{
		menu();
		cin >> option;

		if (option == 1)
		{
			cout << "Enter the number of students : ";
			cin >> numberOfStudents;
			getStudents(numberOfStudents);
			studentsData.clear();
		}
		else if (option == 2)
		{
			avarage();
			studentsData.clear();
		}

		else if (option == 3)
		{
			showHighGrades();
			studentsData.clear();
		}
		else if (option == 4)
		{
			showLowGrades();
			studentsData.clear();
		}
		else if (option == 5)
		{
			showNumOfPassedStudentsPerSub();
			studentsData.clear();

		}
		else if (option == 6)
		{
			standardDiviasion();
			studentsData.clear();
		}

		else if (option == 7)
		{
			break;
		}
		else
		{
			cout << "Invlaid operation" << endl;
		}


		cout << "Another Operation? (Y/N)" << endl;
		cin >> answer;
	}
	return 0;
}

void readfromfile()
{
	ifstream readFromFile;
	readFromFile.open("Student.txt");
	while (!readFromFile.eof())
	{
		STUDENTS student1;
		readFromFile >> student1.firstName;
		if (student1.firstName.empty()) break;
		readFromFile >> student1.secondName;
		readFromFile >> student1.id;
		for (int m = 0; m < numberOfSubjects; m++)
		{
			readFromFile >> student1.subjects[m];
			student1.sumOfScore += student1.subjects[m];
		}
		studentsData.push_back(student1);
	}

	readFromFile.close();
}

void avarage()
{
	system("CLS");
	readfromfile();
	float sum = 0.0;
	float avarage = 0.0;
	for (int i = 0; i < studentsData.size(); i++)
	{
		sum = 0.0;
		avarage = 0.0;
		for (int j = 0; j < numberOfSubjects; j++)
		{
			sum += studentsData[i].subjects[j];
		}
		avarage = (sum / numberOfSubjects);
		studentsData[i].avarageScore = avarage;
		cout << studentsData[i].avarageScore << endl;

	}
}

void showHighGrades()
{
	system("CLS");
	readfromfile();
	for (int i = 0; i < studentsData.size(); i++)
	{
		if (studentsData[i].sumOfScore >= 400)
		{
			cout << "First name :  ";
			cout << studentsData[i].firstName << endl;
			cout << "Second name : ";
			cout << studentsData[i].secondName << endl;
			cout << "Student ID : ";
			cout << studentsData[i].id << endl;
			cout << "----------------------------------------------------------\n";
		}
	}
}

void showLowGrades()
{
	system("CLS");
	readfromfile();
	for (int i = 0; i < studentsData.size(); i++)
	{
		if (studentsData[i].sumOfScore <= 200)
		{
			cout << "First name :  ";
			cout << studentsData[i].firstName << endl;
			cout << "Second name : ";
			cout << studentsData[i].secondName << endl;
			cout << "Student ID : ";
			cout << studentsData[i].id << endl;
			cout << "----------------------------------------------------------\n";
		}

	}
}

void getStudents(int numberOfStudents)
{
	system("CLS");

	cout << "enter the data of " << numberOfStudents << " students please ! \n";
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Enter the first name of student number " << i + 1 << " : ";
		cin >> student[i].firstName;
		cout << "Enter the second name of student number " << i + 1 << " : ";
		cin >> student[i].secondName;
		cout << "Enter the ID of student number " << i + 1 << " : ";
		int ID;
		while (true)
		{
			cin >> ID;
			if (ID > 0)
			{
				student[i].id = ID;
				break;
			}
			else
			{
				cout << "Invalid number please enter positive number only !! \n";
			}
		}


		cout << "Enter five score for five subjects \n";

		for (int j = 0; j < numberOfSubjects; j++)
		{
			float grade;

			while (true)
			{
				cin >> grade;
				if (grade >= 0)
				{
					student[i].subjects[j] = grade;
					break;
				}
				else
				{
					cout << "Invalid number please enter positive numbers only !! ";
				}
			}

		}

		ifstream readFromFile;
		readFromFile.open("Student.txt");
		studentsData.clear();
		while (!readFromFile.eof())
		{
			STUDENTS student1;
			readFromFile >> student1.firstName;
			if (student1.firstName.empty()) break;
			readFromFile >> student1.secondName;
			readFromFile >> student1.id;
			for (int m = 0; m < numberOfSubjects; m++)
			{
				readFromFile >> student1.subjects[m];
			}
			studentsData.push_back(student1);
		}

		readFromFile.close();

		ofstream writeToFile;
		writeToFile.open("Student.txt");

		for (int n = 0; n < studentsData.size(); n++)
		{
			writeToFile << studentsData[n].firstName << endl;
			writeToFile << studentsData[n].secondName << endl;
			writeToFile << studentsData[n].id << endl;
			for (int k = 0; k < numberOfSubjects; k++)
			{
				writeToFile << studentsData[n].subjects[k] << " ";
			}
			writeToFile << endl;
		}
		writeToFile << student[i].firstName << endl;
		writeToFile << student[i].secondName << endl;
		writeToFile << student[i].id << endl;
		for (int k = 0; k < numberOfSubjects; k++)
		{
			writeToFile << student[i].subjects[k] << " ";
		}
		writeToFile << endl;
		studentsData.push_back(student[i]);
		writeToFile.close();
	}
}



void showNumOfPassedStudentsPerSub()
{
	system("CLS");
	readfromfile();
	float numberOfSucceeded = 0.0;
	for (int j = 0; j < numberOfSubjects; j++)
	{
		numberOfSucceeded = 0;

		for (int i = 0; i < studentsData.size(); i++)
		{
			if (studentsData[i].subjects[j] >= 50)
				numberOfSucceeded++;
		}
		cout << "Number of succeeded students in subject number " << j + 1 << " is "
			<< numberOfSucceeded << endl;
	}
}

void standardDiviasion()
{
	system("CLS");
	readfromfile();
	float sum = 0.0, mean = 0.0, standardDiviasion = 0.0;

	for (int j = 0; j < numberOfSubjects; j++)
	{
		for (int i = 0; i < studentsData.size(); i++)
		{
			sum += studentsData[i].subjects[j];
		}

		mean = sum / studentsData.size();

		for (int k = 0; k < studentsData.size(); k++)
		{
			standardDiviasion += pow(studentsData[j].subjects[k] - mean, 2);
		}

		cout << "The standard disviasion in subject number " << j + 1 << " is : " <<
			sqrt(standardDiviasion / studentsData.size()) << endl;
	}
}

void menu()
{
	system("CLS");
	cout << "Enter your option \n\n";
	cout << "[1] register student\n";
	cout << "[2] Show avarage score per student \n";
	cout << "[3] Show the data of highest accumulative score in all subjects\n";
	cout << "[4] Show the data of lowest accumulative score in all subjects\n";
	cout << "[5] Show number of succeeded students per subject \n";
	cout << "[6] Show the standard deviation per subject \n";
	cout << "[7] Exit \n";
}
