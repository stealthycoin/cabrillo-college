// CS19:Final Exam (Spring 2011)
// Linked List, Inheritance, Templates exercise
// Filename: linkedlistF.cpp
// templated link list inherited to special-case list

// you will code (ONLY!) the functions 
// ClassExam::insertRear and ClassExam::getMeanAndStddev

// John Carlyle jcarlyle

// you may add additional #includes if necessary
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

// forward definition
template <class T>
class List;

// LinkNode "internal" helper class for List
template <class T>
class LinkNode{
  friend class List<T>;
public:
  LinkNode(T *d=0, LinkNode *n=0 ){next=n; data=d;}
  ~LinkNode(){ if (data){ delete data; data=0;} }
  void setData( T *d){ data = d; }
  void setNext(LinkNode *n){ next = n; }
  T *getData(){ return data; }
  LinkNode *getNext(){ return next; }
private:
  T *data;
  LinkNode *next;
};

//-----------------------------------------------------
// Linked List class with Templates
template <class T>
class List{
public:
  List(){ first = 0; }
  ~List();
  void insert( T *); // insert at front
  void remove( T *); // remove 1st matching
  void print();
  void clearAll(); // sets list to empty
protected:
  LinkNode<T> *first;
};

template <class T>
List<T>::~List(){
  clearAll();
}

template <class T>
void List<T>::clearAll(){
  LinkNode<T> *link = first;
  while (first){
    link = first;
    first = first-> next;
    delete link;
  }
}

template <class T>
void List<T>::insert(T *d){
  LinkNode<T> *link = new LinkNode<T>();
  T *nd = new T();
  *nd = *d;
  link->next = first;
  first = link;
  link->data = nd;
}

template <class T>
void List<T>::remove(T *d){
  LinkNode<T> *temp = first;
  if(!first) return;
  if( *(first->data) == *d ){
    first = first->next;
    delete temp->data;
    delete temp;
    return;
  }
  temp = first->next;
  LinkNode<T> *prev = first;
  while(temp){
    if( *(temp->data) == *d ){
      prev->next = temp->next;
      delete temp->data;
      delete temp;
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

template <class T>
void List<T>::print(){
  LinkNode<T> *link = first;
  while(link){
    cout << *(link->data) << endl;
    link = link->next;
  }
}

// --------------------------------------------------------
/*
 * an Exam Score Object stores:
 * string name ( of the student )
 * int score ( achieved on test )
 * int maxScore ( possible for that exam )
 *
 */
class ExamScore{
public:
  friend ostream &operator<<(ostream &os, ExamScore &c);
  ExamScore(string="", double=0.0, double=100.0);
  double getScore()const{return score;}
  double getMaxScore()const{return maxScore;}
  string getName()const{return name;}
  void setScore(double n){if(n>=0.0 && n<=maxScore) score=n;}
  void setMaxScore(double n){if(n>=0.0 && n>=score) maxScore=n;}
private:
  string name; 
  double score;
  double maxScore;
};

ExamScore::ExamScore(string s, double n, double max){
  name = s;
  if (n < 0.0 || max < n ){
    score = 0.0; maxScore = 100.0;
  } else {
    score = n; maxScore = max;
  }
}

ostream &operator<<(ostream &os, ExamScore &c){
  os << c.name << " " << c.score << "/" << c.maxScore;
  return os;
}

// ********************************************************
class ClassExam : public List<ExamScore>{
public:
  void insertFront(ExamScore *ns){ insert(ns); }
  // you will code these two functions (below)
  void insertRear(ExamScore *ns);
  pair<double, double> getMeanAndStddev();
private:
};

// *******************************************************
// define the following function
// it should add a new node at the end of the list
void ClassExam::insertRear(ExamScore *ne){
  //new exam score object and copy all values into new one
  ExamScore *newScore = new ExamScore(ne->getName(), 
				      ne->getScore(), 
				      ne->getMaxScore());
  //create new node with the score in it
  LinkNode<ExamScore> *newNode = new LinkNode<ExamScore>(newScore);
  LinkNode<ExamScore> *prev = NULL, *node = first;
  
  while (node) {//traverse to end of list
    prev = node;
    node = node->getNext();
  }
  if (!first)//if it was empty
    first = newNode;
  else//if it was not empty
    prev->setNext(newNode);
  //not sure what kind of cleanup you want so ill just get rid of these
  prev=0;newNode=0;newScore=0;
}

// this function should return a pair of doubles
// where the first value is the (arithmetic) mean (average) value of the scores 
// of the student exams in the list
// and the second value is the Standard Deviation of the scores
// of the student exams in the list
// return a value of 0.0 for both values if the list is empty
// The formula for calculating the standard deviation is provided on the 
// paper copy of the exam 
pair<double, double> ClassExam::getMeanAndStddev(){
  pair<double, double> temp(0.0, 0.0);
  LinkNode<ExamScore> *node = first;
  int count = 0;
  while (node) {
    temp.first += node->getData()->getScore();
    count++;
    node = node->getNext();
  }
  temp.first /= count;
  //average done
  
  node = first;
  while (node) {
    temp.second += pow(node->getData()->getScore()-temp.first, 2);
    node = node->getNext();
  }
  temp.second = sqrt(temp.second/count);
  //standard deviation done
  //not done well due to it being on a test.
  return temp;
}

// -------------------------------------------------------------------
main(){
  cout << "CS19 Final Exam - Linked List Exercise" << endl;
  cout << "John Carlyle jcarlyle" << endl;
  ClassExam cl;
  ExamScore *temp=0;

  cout << "Pre-Registration:" << endl;
  cl.print(); // should have no entries!
  cout << "Enrolling Students..." << endl;
  temp = new ExamScore("Samuel Mputa", 80.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Clarissa Oakes", 65.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Thomas Pullings", 100.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("William Reade", 92.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Amanda Smith", 76.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Barret Bonden", 60.0, 100.0);
  cl.insertFront(temp);
  delete temp; temp=0;
  temp = new ExamScore("William Babbington", 85.0, 100.0);
  cl.insertFront(temp);
  delete temp; temp=0;
  temp = new ExamScore("Diana Villiers", 90.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Christine Wood", 72.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;
  temp = new ExamScore("Andrew Wray", 20.0, 100.0);
  cl.insertRear(temp);
  delete temp; temp=0;


  cout << "Class Scores:" << endl;
  cl.print(); // should be 10 students listed alphabetical by last name
  pair<double, double> results = cl.getMeanAndStddev();
  // correct average is 74
  cout << "Average Score is " << results.first << "." << endl;
  // correct standard deviation is 21.48
  cout << "Standard Deviation is " << results.second << "." << endl;
  return 0;
}
