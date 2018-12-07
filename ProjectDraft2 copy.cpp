#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//ahahaha


struct timeInfo{
  int startHours;
  int startMins;
  int endHours;
  int endMins;
  string event;
  string ampm;
  string name;
  timeInfo *freetime;
  timeInfo *next;
  timeInfo *previous;

};


class timeSlot{
private:

  timeInfo *queueFront = NULL;
  timeInfo *QueueRear = NULL;


public:

  timeInfo *list;
  bool isEmpty();
  void storeInfo(timeInfo* list);
  int freeTime(timeInfo* list);
  void conflicts();
  void recommendation();
  void enqueue(timeInfo* list);
  timeInfo* getQueueFront() {return queueFront;};
  timeInfo* getQueueRear() {return QueueRear;};
  // timeInfo* getQueueAtTime(int x, int y); //start and end time
};

bool timeSlot::isEmpty()
{
  if (getQueueRear() == NULL && getQueueFront() == NULL)
  {
    return true;
  }

  return false;
}

void timeSlot::storeInfo(timeInfo* list)
{
  cout << "Welcome, here is your schedule for today!" << endl;
  cout<< "At "<< list->startHours << ":" << list->startMins << list->ampm << ", you have: " << list->event << endl;
}

// void timeSlot::storeInfo(int h, int m, string ap, string e)
// {
//
// }
//   this -> queue = new timeInfo; //take data member of queue and point it to next element in the list
//   *temp = new queue
//   //queue -> LLNext = temp;
//   //cout << "Welcome, here is your schedule for today!" << endl;
//
//   // h=hrs;
//   // m=mins;
  //ap = ampm;
//   // e = event;
//
// //ask for the userinput
//
//   // if((h<0 && h>12) && (m<0 && m>60)){
//   //   cout << "invalid input"<<endl;
//
//     // time restrictions
//     // changing ampm
//   }
//
//   else{
//
//     cout<< "At "<< h << ":" << m << ampm << ", you have: " << e << endl;
//
//   // do the offile to get the data input
//   }


//printing out the set schedule by the user


int timeSlot::freeTime(timeInfo* list){
  // need to do after the reading the
  // created file based on the userinput


  // 1. calculating the freeTime
  int total=0;
  timeInfo* freetime = new timeInfo;
  timeInfo* slot1 = new timeInfo;
  timeInfo* slot2 = new timeInfo;

  cout << "before if"<< endl;

  if(slot2->startHours != slot1->endHours && slot2->startMins!= slot1->endMins)// getting segfault
  {
    cout << "inside if"<< endl;

    cout << "From "<< slot1->endHours << ":" <<slot1->endMins << "you have" << total<< " hrs of free time" << endl;

    freetime->startHours = slot1->endHours;
    freetime->startMins = slot1->endMins;
    freetime->endHours = slot2->startHours;
    freetime->endMins = slot2->startMins;

  }
  return freetime -> startHours;
}




void timeSlot::conflicts(){

}



void timeSlot::recommendation(){
// 1.
// 2.
}

void timeSlot::enqueue (timeInfo* list)
{

 timeInfo *ptr = new timeInfo;

 ptr -> startHours = list -> startHours;
 ptr -> startMins  = list -> startMins;
 ptr -> endHours = list -> endHours;
 ptr -> endMins = list -> endMins;
 ptr -> ampm = list -> ampm;
 ptr -> event = list -> event;

 //If inserting the first element/node
 if(queueFront == NULL )
 {
  queueFront = ptr;
  QueueRear = ptr;
 }
 else
 {
  QueueRear = ptr;
 }

 cout <<"Start " <<ptr -> startHours <<":" <<ptr -> startMins <<" End " << ptr -> endHours <<":" <<ptr -> endMins <<" event :" <<ptr -> event <<endl;
}

int main(){
  timeSlot t;
  // t.storeInfo(8,30,"am","Physics");
  // t.storeInfo(10,30,"am","Chemistry");
  string input;
  string name;
  string startTime1;
  string startTime2;
  string endTime1;
  string endTime2;
  string appointment;
  string ampm;

  cout << "Welcome to your daily scheduler! " <<endl; //put in line 1 name of person
  cout <<"Enter your name: " <<endl;
  getline(cin, name);
  cout << " ------------- Main Menu ------------- " <<endl;
  cout << "1. Enter Info " <<endl;
  cout << "2. View Schedule " <<endl;
  cout << "3. Get Recommendations " <<endl;
  cout << "4. Quit" <<endl;

  getline(cin, input); //maybe use getline instead?
  while (input != "4")
  {
    if (input != "1" && input != "2" && input != "3" && input != "4")
    {
      cout <<"Invalid Input! Please enter 1, 2, 3, or 4 to quit. \n Thank you!" <<endl;
    }
    if (input == "1")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<"Please enter your schedule: " <<endl;
      cout <<"What time (hours) is your appointment? " <<endl;
      getline(cin, startTime1);
      cout <<"What time (minutes) is your appointment? " <<endl;
      getline(cin, startTime2);
      cout <<"What time (hours) does your appointment end? " <<endl;
      getline(cin, endTime1);
      cout <<"What time minutes) does your appointment end? " <<endl;
      getline(cin, endTime2);
      cout <<"Is it in the morning or afternoon? (Enter am/pm) " <<endl;
      getline(cin, ampm);
      cout <<"What do you have scheduled at " <<startTime1 <<":" <<startTime2 <<ampm <<" ?" <<endl;
      getline(cin, appointment);

      t.list->startHours = stoi(startTime1);
      t.list->startMins = stoi(startTime2);
      t.list->endHours = stoi(endTime1);
      t.list->endMins = stoi(endTime2);
      t.list->event = appointment;
      t.list->ampm = ampm;

      t.storeInfo(t.list);
      t.enqueue(t.list);

    }
    if (input == "2")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<" ------------- Schedule ------------- " <<endl;
      t.storeInfo(t.list);
      //t.storeInfo(8,30,"am","Physics");
      //t.storeInfo(10,30,"am","Chemistry");
    }//SEG FAULTS HERE -----------
    // if (input == "3")
    // {
    //   cout <<"Your freetime: " <<endl;
    //   t.freeTime(t.list);
    // }
  }


  // t.freeTime();
}
