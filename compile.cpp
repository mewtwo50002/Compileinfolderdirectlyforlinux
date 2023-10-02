#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

std::string getTimeStr(){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return s;
}

int main()
{
    string filename;
    string filename2;
    string consoleCommand2;
    string logName;
    int firstTime = 0;
    
    cout<<"whats the name of the file without the .cpp: ";
    cin>>filename;
    
    filename2 = filename + ".cpp";
    consoleCommand2 = "g++ " + filename2 + " -o " + filename + ".out";
    const char * consoleCommand = consoleCommand2.c_str();
    
    while (true)
    {
        
        system(consoleCommand); 
        
        logName = "log_" + filename + ".txt";
        fstream myFile1;
        
        if (firstTime == 0)
        {
            myFile1.open(logName,ios::out);
            if (myFile1.is_open())
            {
                cout<<"First compiled at "<< getTimeStr()<<endl;
                myFile1<<"compiled at "<< getTimeStr()<<endl;
                myFile1.close();
            }
            firstTime++;
        }else
        {
            myFile1.open(logName, ios::app);
            if (myFile1.is_open())
            {
                cout<<"compiled at "<< getTimeStr()<<endl;
                myFile1<<"compiled at "<< getTimeStr()<<endl;
                myFile1.close();
            }
        }
        
        
        
        
        

        sleep_for(seconds(5));
    }
}



