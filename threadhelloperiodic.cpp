//Compile with g++ -std=c++11 threadhelloperiodic.cpp -pthread -o threadhelloperiodic

#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono;
void concurrent_function(int samp_time_ms)  {
  int counter = 0; 
  milliseconds period {samp_time_ms};
  steady_clock::time_point start {steady_clock::now()};
  steady_clock::time_point next_time {start+period};
  duration<double,milli> elapsed;

  while(++counter  < 10) {
    elapsed = steady_clock::now()-start;
    cout << elapsed.count()<<"(ms): "<<": Hello from Child Thread # "<<this_thread::get_id() << endl;
    this_thread::sleep_until(next_time);
    next_time += period;
  }
  elapsed = steady_clock::now()-start;
  cout << "Elapsed Time in Child Thread # "
            << this_thread::get_id() << ": "
            <<elapsed.count() << "(ms)" << endl;
}

int main()   {
  cout << "Starting Main Thread #"  << this_thread::get_id() << endl;
  auto start_time = steady_clock::now();
  thread t1 {concurrent_function, 200};
  cout << "Created Child Thread 1 # " << t1.get_id() << endl;
  thread t2 {concurrent_function, 200};
  cout << "Created Child Thread 2 # "  << t2.get_id() << endl;
  this_thread::sleep_for(milliseconds(1000));
  t1.join(); //wait until t1 finishes
  t2.join(); //wait until t2 finishes
  auto elapsed = steady_clock::now()-start_time;
  cout << "Threads Finished." << endl
           << "Elapsed Time in Main Thread # "
           << this_thread::get_id() << ": "
           << elapsed.count(); 
  cout << "(ms)" << endl;
  getchar();
}

