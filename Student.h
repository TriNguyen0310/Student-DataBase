#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
  public:
  //student data
      int id;
      string first_name;
      string last_name;
      int startyear;
      int toyear;
      
  //subject data
      int mathClass;
      string mathTeacher;
      double mathGrade;

      int englishClass;
      string englishTeacher;
      double englishGrade;

      double averageGrade;

  public:
      Student();
      Student(int id, string first_name, string last_name, int startyear, int toyear, int mathClass, string mathTeacher, double mathGrade, int englishClass, string englishTeacher, double englishGrade);
      ~Student();
      //Setter
      void setID(int);
      void setFirst_name(string);
      void setLast_name(string);
      void setStart_year(int);
      void setTo_year(int);

      void setMath_class(int);
      void setMath_teacher(string);
      void setMath_grade(double);

      void setEnglish_class(int);
      void setEnglish_teacher(string);
      void setEnglish_grade(double);

      //Getter
      int getID();
      string getFirst_name();
      string getLast_name();
      int getStart_year();
      int getTo_year();

      int getMath_class();
      string getMath_teacher();
      double getMath_grade();

      int getEnglish_class();
      string getEnglish_teacher();
      double getEnglish_grade();

      double getAverage_grade();

      bool operator<(Student stud);
      bool operator>(Student stud);
      bool operator<=(Student stud);
      bool operator>=(Student stud);
};

#endif