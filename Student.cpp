#include <iostream>
#include "Student.h"

//Constructors/Destructors
//Making by Tri and Noah

Student::Student(){
  this->id = -1;
  this->first_name = "first_name";
  this->last_name = "last_name";
  this->startyear = -1;
  this->toyear = -1;
  this->mathClass = -1;
  this->mathTeacher = "mathTeacher";
  this->mathGrade = -1;
  this->englishClass = -1;
  this->englishTeacher = "englishTeacher";
  this->englishGrade = -1;
}

Student::Student(int id, string first_name, string last_name, int startyear, int toyear, int mathClass, string mathTeacher, double mathGrade, int englishClass, string englishTeacher, double englishGrade){

  this->id = id;
  this->first_name = first_name;
  this->last_name = last_name;
  this->startyear = startyear;
  this->toyear = toyear;
  this->mathClass = mathClass;
  this->mathTeacher = mathTeacher;
  this->mathGrade = mathGrade;
  this->englishClass = englishClass;
  this->englishTeacher = englishTeacher;
  this->englishGrade = englishGrade;
  this->averageGrade = (this->englishGrade + this->mathGrade)/2;

}

Student::~Student(){

}

//Setters

void Student::setID(int i){
  this->id = i;
}

void Student::setFirst_name(string s){
  this->first_name = s;
}

void Student::setLast_name(string s){
  this->last_name = s;
}

void Student::setStart_year(int i){
  this->startyear = i;
}
void Student::setTo_year(int i){
  this->toyear = i;
}

void Student::setMath_class(int i){
 this->mathClass = i;
}
void Student::setMath_teacher(string s){
  this->mathTeacher = s;
}

void Student::setMath_grade(double i){
  this->mathGrade = i;
}

void Student::setEnglish_class(int i){
  this->englishClass = i;
}

void Student::setEnglish_teacher(string s){
  this->englishTeacher = s;
}

void Student::setEnglish_grade(double i){
  this->englishGrade = i;
}

//Getters
int Student::getID(){
  return this->id;
}

string Student::getFirst_name(){
  return this->first_name;
}

string Student::getLast_name(){
  return this->last_name;
}

int Student::getStart_year(){
  return this->startyear;
}

int Student::getTo_year(){
  return this->toyear;
}

int Student::getMath_class(){
  return this->mathClass;
}

string Student::getMath_teacher(){
  return this->mathTeacher;
}

double Student::getMath_grade(){
  return this->mathGrade;
}

int Student::getEnglish_class(){
  return this->englishClass;
}

string Student::getEnglish_teacher(){
  return this->englishTeacher;
}

double Student::getEnglish_grade(){
  return this->englishGrade;
}

double Student::getAverage_grade(){
  return (static_cast<double>(this->englishGrade + this->mathGrade))/2;
}

bool Student::operator<(Student stud){
  return (this->last_name < stud.getLast_name());
}

bool Student::operator>(Student stud){
  return (this->last_name > stud.getLast_name());
}

bool Student::operator<=(Student stud){
  return (this->last_name <= stud.getLast_name());
}

bool Student::operator>=(Student stud){
  return (this->last_name >= stud.getLast_name());
}