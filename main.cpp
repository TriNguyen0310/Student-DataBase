//Group 5

#include <iostream> //Input/Output
#include <string> //For Strings
#include <fstream> //File Input/Output
#include <math.h> //For log() function
#include "LinkedList.h" //LinkedList
#include "TimSort.h" //TimSort
#include "Student.h" //Student class
#include "binarysearch.h" //binary search with ID
#include "StudentBinaryTree.h" //Binary Tree for last name with search
#include "PQueue.h" //Priority Queue by average grade for class selection

using namespace std;

//Functions
void readfile(string filename, string header[], LinkedList<Student> &list);
void displayStudents(const LinkedList<Student> list);
void displayHeader(const string header[]);
LinkedList<Student> sortByLast(const LinkedList<Student> &list);
LinkedList<Student> sortByHighestEnglishGrade(const LinkedList<Student> &list);
LinkedList<Student> sortByLowestEnglishGrade(const LinkedList<Student> &list);
LinkedList<Student> sortByHighestMathGrade(const LinkedList<Student> &list);
LinkedList<Student> sortByLowestMathGrade(const LinkedList<Student> &list);
void writeToFile(string header[], const LinkedList<Student> list);
void searchWbinary(const LinkedList<Student> list, int id, string header[]);
void addStudent(LinkedList<Student> &list);
void PQueueDisplay(LinkedList<Student>* q_ref);
LinkedList<Student> groupByMathTeacher(LinkedList<Student> list);
LinkedList<Student> groupByEngTeacher(LinkedList<Student> list);
LinkedList<Student> groupByMathClass(LinkedList<Student> list);
LinkedList<Student> groupByEngClass(LinkedList<Student> list);

//Main
int main() {

  //Initialize list and binary tree
  LinkedList<Student> list;
  Tree<Student>* tree = new Tree<Student>;
  
  string header[11];

  readfile("student_record.csv", header, list);
  initBinaryTree(tree, list);

  //Menu
  //Tri, Noah
    
    int option = 0;
    do{

      cout << setw(14) <<"\nMenu" << endl;
      cout << "1: Display all Data\n";
      cout << "2: Display all Data with Sorting\n";
      cout << "3: With ID, Search for Student Info using Binary Search\n";
      cout << "4: With Last Name, Search for Student Info using Binary Tree\n";
      cout << "5: Priority Queue for Class Selection by Highest Average grade\n";
      cout << "6: Group and Display Data\n";
      cout << "7: Traverse Binary Tree\n";
      cout << "8: Add Student\n";
      cout << "9: Exit\n-> ";

      //Take input
      cin >> option;
      
      char ans = 'N';
      int tempIn = 1;
      LinkedList<Student> tempList = list;

      switch(option){
          case(1):
          //Display Students
          displayHeader(header);
          displayStudents(list);

          cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
          ans = 'N';
          cin >> ans;
          if(ans == 'Y' || ans == 'y'){
            //Write results to txt file
            writeToFile(header, list);
          }
          cout << "\x1B[2J\x1B[H";
          break;
        case(2):
          //Display Sorted

          cout << "\nWhat would you like to sort by?\n1: Last Name\n2: Lowest to Highest Math Grade\n3: Highest to Lowest Math Grade\n4: Lowest to Highest English Grade\n5: Highest to Lowest English Grade\n-> ";

          tempIn = 1;
          cin >> tempIn;
          displayHeader(header);
          ans = 'N';
          tempList = list;

          switch(tempIn){
            //By Last Name
            case(1):
              
              tempList = sortByLast(tempList);
              displayHeader(header);
              displayStudents(tempList);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              tempList.clear();
              cout << "\x1B[2J\x1B[H";
              break;
            //By Lowest Math Grade
            case(2):
              tempList = sortByLowestMathGrade(tempList);
              displayHeader(header);
              displayStudents(tempList);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              tempList.clear();
              cout << "\x1B[2J\x1B[H";
              break;
            //By Highest Math Grade
            case(3):
              tempList = sortByHighestMathGrade(tempList);
              displayHeader(header);
              displayStudents(tempList);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              tempList.clear();
              cout << "\x1B[2J\x1B[H";
              break;
            //By Lowest English Grade
            case(4):
              tempList = sortByLowestEnglishGrade(tempList);
              displayHeader(header);
              displayStudents(tempList);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              tempList.clear();
              cout << "\x1B[2J\x1B[H";
              break;
            //By Highest English Grade
            case(5):
              tempList = sortByHighestEnglishGrade(tempList);
              displayHeader(header);
              displayStudents(tempList);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              tempList.clear();
              cout << "\x1B[2J\x1B[H";
              break;
          }
          break;
        case(3):
          //Search for Student Info using ID

          tempIn = 1;
          cout << "\nPlease input the lD of student to search:\n-> ";
          cin >> tempIn;
          searchWbinary(list,tempIn,header);
          break;

        case(4):
          //Search by Last Name using Binary Tree

          tree->clear();
          initBinaryTree(tree, tempList);
          
          tempList = binaryTreeSearch(tree);
          displayHeader(header);
          displayStudents(tempList);
          cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
          ans = 'N';
          cin >> ans;
          if(ans == 'Y' || ans == 'y'){
            //Write results to txt file
            writeToFile(header, tempList);
          }

          tempList.clear();
          cout << "\x1B[2J\x1B[H";
          break;

        case(5):
          //Display Priority Queue

          PQueueDisplay(&list);
          break;

        case(6):
          //Grouping

          tempList = list;
          tempIn = 1;
          cout << "\nWhat would you like to group by?\n1: Math Teacher\n2: English Teacher\n3: Math Class\n4: English Class\n-> ";
          cin >> tempIn;
          displayHeader(header);
          ans = 'N';

          switch(tempIn){
            //By Math Teacher
            case(1):
              tempList = groupByMathTeacher(list);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              cout << "\x1B[2J\x1B[H";
              break;
            //By English Teacher
            case(2):
              tempList = groupByEngTeacher(list);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              cout << "\x1B[2J\x1B[H";
              break;
            //By Math Year
            case(3):
              tempList = groupByMathClass(list);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              cout << "\x1B[2J\x1B[H";
              break;
            //By English Year
            case(4):
              tempList = groupByEngClass(list);
              cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
              ans = 'N';
              cin >> ans;
              if(ans == 'Y' || ans == 'y'){
                //Write results to txt file
                writeToFile(header, tempList);
              }
              cout << "\x1B[2J\x1B[H";
              break;
          }
          tempList.clear();
          break;

        case(7):
          
          tempList = traverse(tree);
          displayHeader(header);
          displayStudents(tempList);
          cout << "\nWould you like to print to \'StudentList.txt\'? (Y/N)-> ";
          ans = 'N';
          cin >> ans;
          if(ans == 'Y' || ans == 'y'){
            //Write results to txt file
            writeToFile(header, tempList);
          }

          tempList.clear();
          cout << "\x1B[2J\x1B[H";
          break;
        case(8):

          addStudent(list);
          break;
      }
    } while(option != 9);
    return 0;
}

//Read csv file into list
void readfile(string filename, string header[], LinkedList<Student> &list){
    //Tri
    //variable and open file
    ifstream input;
    input.open(filename);
    string line;
    int pos;

    //get header
    getline(input,line);

    for(int i = 0; i < 11 ; i++){
      pos = line.find(",");
      header[i] = line.substr(0,pos);
      line.erase(0,pos+1);
    }

    //get all data
    Student s;
    while(getline(input,line)) {

        //get id
        pos = line.find(",");
        s.setID(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);
        
        //get firstname
        pos = line.find(",");    
        s.setFirst_name(line.substr(0,pos));
        line.erase(0,pos+1);

        //get last name;
        pos = line.find(",");    
        s.setLast_name(line.substr(0,pos));
        line.erase(0,pos+1);

        //get startyear
        pos = line.find(",");
        s.setStart_year(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        // //get toyear
        pos = line.find(",");    
        s.setTo_year(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        //get mathClass
        pos = line.find(",");    
        s.setMath_class(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        //get mathGrade
        pos = line.find(",");
        s.setMath_grade(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        //get mathTeacher
        pos = line.find(",");
        s.setMath_teacher(line.substr(0,pos));
        line.erase(0,pos+1);
        
        //get englishClass
        pos = line.find(",");    
        s.setEnglish_class(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        //get englishGrade
        pos = line.find(",");    
        s.setEnglish_grade(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        //get englishTeacher
        pos = line.find(",");    
        s.setEnglish_teacher(line.substr(0,pos));
        line.erase(0,pos+1);
        
        list.add(s);

    }
    input.close();
}

//Display Header
void displayHeader(const string header[]){
  //-Noah
  //---Print header to console---
  cout << "\x1B[2J\x1B[H" << "\n";
  for(int i = 0; i < 11; i++){
    cout << header[i] << "   ";
  }
  //-----------------------------
}

//Display all students
void displayStudents(const LinkedList<Student> list){
  //-Noah,Tri
  
  //---Print student info to console---
  for(int i = 0; i < list.getSize(); i++){
    Student temp = list.get(i);
    cout << endl << temp.getID() << right << setw(14 - (int)(log10(temp.getID()))) << temp.getFirst_name() << setw(12) << temp.getLast_name() << setw(12) << temp.getStart_year() << setw(12) << temp.getTo_year() << setw(12) << temp.getMath_class()<< setw(12) << temp.getMath_grade() << "%" << setw(15) << temp.getMath_teacher() << setw(10) << temp.getEnglish_class() << setw(12) << temp.getEnglish_grade() << "%" << setw(14) << temp.getEnglish_teacher();
  }
  cout << endl;
  //-----------------------------------
}

//Write current list and header to output file
void writeToFile(string header[], const LinkedList<Student> list){
  //-Noah

  //Open output file
  ofstream file;
  file.open("StudentList.txt");

  //---Print header to file---
  cout << "\n";
  for(int i = 0; i < 11; i++){
    file << header[i] << "   ";
  }
  cout << "\n";
  //--------------------------

  //---Print Students from list to file---
  for(int i = 0; i < list.getSize(); i++){
    Student temp = list.get(i);
    file << endl << temp.getID() << right << setw(14 - (int)(log10(temp.getID()))) << temp.getFirst_name() << setw(12) << temp.getLast_name() << setw(12) << temp.getStart_year() << setw(12) << temp.getTo_year() << setw(12) << temp.getMath_class()<< setw(12) << temp.getMath_grade() << "%" << setw(15) << temp.getMath_teacher() << setw(10) << temp.getEnglish_class() << setw(12) << temp.getEnglish_grade() << "%" << setw(14) << temp.getEnglish_teacher();
  }
  file << endl;
  //---------------------------------------
}

//Sort by last name
LinkedList<Student> sortByLast(const LinkedList<Student> &list){
  //-Noah,Tri
  //---Setting last names to array to compare---

  Student nameArray[list.getSize()];

  for(int i = 0; i < list.getSize(); i++){
    Student worker = list.get(i);
    nameArray[i] = worker; 
  }
  //--------------------------------------------

  //Call timSort to sort last names
  timSortByLastName(nameArray, list.getSize());

  //---Setting students in order of sorted list---
  LinkedList<Student> temp; 

  for(int i = 0; i < list.getSize(); i++){
    Student stud = nameArray[i];
    temp.add(stud);
  }
  return temp;
  //----------------------------------------------
}

//Sort by Highest ENG grade
LinkedList<Student> sortByHighestEnglishGrade(const LinkedList<Student> &list){
  //-Noah,Tri

  //Call timSort to sort by highest grade
  Student arr[list.getSize()];
  for(int i = 0; i < list.getSize(); i++){
    arr[i] = list.get(i);
  }
  timSortByEnglishGrade(arr, list.getSize());

  //---Setting students in order of sorted list---
  LinkedList<Student> temp;

  for(int i = 0; i < list.getSize(); i++){
    Student worker = arr[i];
    temp.addFirst(worker);
  }
  return temp;
  //----------------------------------------------
}

//Sort by Lowest ENG grade
LinkedList<Student> sortByLowestEnglishGrade(const LinkedList<Student> &list){
  //-Noah,Tri

  //Call timSort to sort by highest grade
  Student arr[list.getSize()];
  for(int i = 0; i < list.getSize(); i++){
    arr[i] = list.get(i);
  }
  timSortByEnglishGrade(arr, list.getSize());

  //---Setting students in order of sorted list---
  LinkedList<Student> temp;

  for(int i = 0; i < list.getSize(); i++){
    Student worker = arr[i];
    temp.add(worker);
  }
  return temp;
  //----------------------------------------------
}

//Sort by Highest MATH grade
LinkedList<Student> sortByHighestMathGrade(const LinkedList<Student> &list){
  //-Noah,Tri

  //Call timSort to sort by highest grade
  Student arr[list.getSize()];
  for(int i = 0; i < list.getSize(); i++){
    arr[i] = list.get(i);
  }
  timSortByMathGrade(arr, list.getSize());

  //---Setting students in order of sorted list---
  LinkedList<Student> temp;

  for(int i = 0; i < list.getSize(); i++){
    Student worker = arr[i];
    temp.addFirst(worker);
  }
  return temp;
  //----------------------------------------------
}

//Sort by Lowest MATH grade
LinkedList<Student> sortByLowestMathGrade(const LinkedList<Student> &list){
  //-Noah, Tri

  //Call timSort to sort by highest grade
  Student arr[list.getSize()];
  for(int i = 0; i < list.getSize(); i++){
    arr[i] = list.get(i);
  }
  timSortByMathGrade(arr, list.getSize());

  //---Setting students in order of sorted list---
  LinkedList<Student> temp;

  for(int i = 0; i < list.getSize(); i++){
    Student worker = arr[i];
    temp.add(worker);
  }
  return temp;
  //----------------------------------------------
}

//Binary Search for ID
void searchWbinary(const LinkedList<Student> list, int id, string header[]){
  //Tri, Noah
  int idArray[list.getSize()];

  for(int i = 0; i < list.getSize(); i++){
    Student temp = list.get(i);
    idArray[i] = temp.getID();
  }

  int index = binarySearch(idArray,0,list.getSize(),id);

  cout << "Is present index" << index << endl;

  LinkedList<Student> temp;
  Student worker = list.get(index);
  temp.add(worker);
  displayHeader(header);
  displayStudents(temp);
}

//Add Student to csv
void addStudent(LinkedList<Student> &list){
  //-Noah

  //Ask for and take input data
  cout << "\nPlease enter the Student's first name: ";
  string fname;
  cin >> fname;
  cout<< "\nPlease enter the Student's last name: ";
  string lname;
  cin >> lname;
  cout << "\nPlease enter the Student's starting year: ";
  int syear;
  cin >> syear;
  cout << "\nPlease enter the Student's ending year: ";
  int eyear;
  cin >> eyear;
  cout << "\nPlease enter the Student's Highest Math Year Level: ";
  int mclass;
  cin >> mclass;
  cout << "\nPlease enter the Student's Math Grade: ";
  double mgrade;
  cin >> mgrade;
  cout << "\nPlease enter the Student's Math Teacher: ";
  string mteach;
  cin >> mteach;
  cout << "\nPlease enter the Student's Highest English Year Level: ";
  int eclass;
  cin >> eclass;
  cout << "\nPlease enter the Student's English Grade: ";
  double egrade;
  cin >> egrade;
  cout << "\nPlease enter the Student's English Teacher: ";
  string eteach;
  cin >> eteach;

  //Find new highest ID
  int id = -1;
  for(int i = 0; i < list.getSize(); i++){
    Student s = list.get(i);
    if(s.getID() >= id){
      id = s.getID() + 1;
    }
  }

  //Set new student to use info
  Student temp(id, fname, lname, syear, eyear, mclass, mteach, mgrade, eclass, eteach, egrade);

  //Set info to csv file
  ofstream file;
  file.open("student_record.csv", std::ios::app);

  file << id << "," << fname << "," << lname << "," << syear << "," << eyear << "," << mclass << "," << mgrade << "," << mteach << "," << eclass << "," << egrade << "," << eteach << "\n";
  
  file.close();

  //Add student to list
  list.add(temp);
}

//Group by Math Teacher
LinkedList<Student> groupByMathTeacher(LinkedList<Student> list){
  //-Noah

  LinkedList<string> nameList;

  bool usedFlag = false;
  for(int i = 0; i < list.getSize(); i++){
    usedFlag = false;
    for(int j = 0; j < nameList.getSize(); j++){
      if(nameList.get(j) == list.get(i).getMath_teacher()){

        usedFlag = true;
      }
    }
    if(usedFlag == false){
      nameList.add(list.get(i).getMath_teacher());
    }
  }

  LinkedList<Student> temp;
  LinkedList<Student> returnList;

  for(int i = 0; i < nameList.getSize(); i++){
    for(int j = 0; j < list.getSize(); j++){
      if(list.get(j).getMath_teacher() == nameList.get(i)){
        temp.add(list.get(j));
      }
    }
    cout << "\n";
    displayStudents(temp);
    for(int k = 0; k < temp.getSize(); k++){
      returnList.add(temp.get(k));
    }
    temp.clear();
  }
  cout << "\n";
  return returnList;
}

//Group by English Teacher
LinkedList<Student> groupByEngTeacher(LinkedList<Student> list){
  //-Noah

  LinkedList<string> nameList;

  bool usedFlag = false;
  for(int i = 0; i < list.getSize(); i++){
    usedFlag = false;
    for(int j = 0; j < nameList.getSize(); j++){
      if(nameList.get(j) == list.get(i).getEnglish_teacher()){

        usedFlag = true;
      }
    }
    if(usedFlag == false){
      nameList.add(list.get(i).getEnglish_teacher());
    }
  }

  LinkedList<Student> temp;
  LinkedList<Student> returnList;

  for(int i = 0; i < nameList.getSize(); i++){
    for(int j = 0; j < list.getSize(); j++){
      if(list.get(j).getEnglish_teacher() == nameList.get(i)){
        temp.add(list.get(j));
      }
    }
    cout << "\n";
    displayStudents(temp);
    for(int k = 0; k < temp.getSize(); k++){
      returnList.add(temp.get(k));
    }
    temp.clear();
  }
  cout << "\n";
  return returnList;
}

//Group by Math Class
LinkedList<Student> groupByMathClass(LinkedList<Student> list){
  //-Noah

  LinkedList<int> gradeList;

  bool usedFlag = false;
  for(int i = 0; i < list.getSize(); i++){
    usedFlag = false;
    for(int j = 0; j < gradeList.getSize(); j++){
      if(gradeList.get(j) == list.get(i).getMath_class()){

        usedFlag = true;
      }
    }
    if(usedFlag == false){
      gradeList.add(list.get(i).getMath_class());
    }
  }

  LinkedList<Student> temp;
  LinkedList<Student> returnList;

  for(int i = 0; i < gradeList.getSize(); i++){
    for(int j = 0; j < list.getSize(); j++){
      if(list.get(j).getMath_class() == gradeList.get(i)){
        temp.add(list.get(j));
      }
    }
    cout << "\n";
    displayStudents(temp);
    for(int k = 0; k < temp.getSize(); k++){
      returnList.add(temp.get(k));
    }
    temp.clear();
  }
  cout << "\nFinished\n";
  return returnList;
}

//Group by English Class
LinkedList<Student> groupByEngClass(LinkedList<Student> list){
  //-Noah

  LinkedList<int> gradeList;

  bool usedFlag = false;
  for(int i = 0; i < list.getSize(); i++){
    usedFlag = false;
    for(int j = 0; j < gradeList.getSize(); j++){
      if(gradeList.get(j) == list.get(i).getEnglish_class()){

        usedFlag = true;
      }
    }
    if(usedFlag == false){
      gradeList.add(list.get(i).getEnglish_class());
    }
  }

  LinkedList<Student> temp;
  LinkedList<Student> returnList;

  for(int i = 0; i < gradeList.getSize(); i++){
    for(int j = 0; j < list.getSize(); j++){
      if(list.get(j).getEnglish_class() == gradeList.get(i)){
        temp.add(list.get(j));
      }
    }
    displayStudents(temp);
    cout << "\n";
    for(int k = 0; k < temp.getSize(); k++){
      returnList.add(temp.get(k));
    }
    temp.clear();
  }
  cout << "\n";
  return returnList;
}

//Display Priority Queue
void PQueueDisplay(LinkedList<Student>* q_ref){
    //Tri, Noah
    PQueue<Student> queue;
    for(int i = 0; i < q_ref->getSize(); i++){
      Student s = q_ref->get(i);
      queue.enqueue(s, 100 - s.getAverage_grade());

    }
    
    while(queue.getSize() > 0){
      
      Student s = queue.dequeue();
      cout << "\n" << left << setw(4) << s.getID() << setw(12) << s.getFirst_name() << " " << setw(12) << s.getLast_name() << setw(6) << " - " << setw(4) << s.getAverage_grade() << left << setw(6) << "%, " << left << setw(10);

      if(s.getAverage_grade() < 50){
        cout << " F ";
      }
      else if(s.getAverage_grade() < 59){
        cout << " D ";
      }
      else if(s.getAverage_grade() < 69){
        cout << " C ";
      }
      else if(s.getAverage_grade() < 79){
        cout << " B ";
      }
      else {
        cout << " A ";
      }

      if(s.getAverage_grade() >= 80){
        cout << "Excellent!!";
      }

      else if(s.getAverage_grade() < 50){
        cout << "Failed!!   ";
      }

      else if(s.getAverage_grade() >= 50 || s.getAverage_grade() < 80){
        cout << "Good job!! ";
      }

      if(s.getEnglish_grade() < 50){
        cout << " (Pass AVG, failed English Class)";
      }
      if(s.getMath_grade() < 50){
        cout << " (Pass AVG, failed Math Class)";
      }

    }
    
    cout << endl;
}