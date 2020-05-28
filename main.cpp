#include <iostream>
#include <thread>
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"

void runAhmedlogger(){

    const std::string directory = "../logs";
    const std::string filename = "AhmedLog"; 
    auto worker = g3::LogWorker::createLogWorker();
    auto sinkHandle = worker->addDefaultLogger(filename,directory);
    
    g3::initializeLogging(worker.get());
    
     for(int i = 0;i<50;i++){
           LOG(DEBUG) << "This is debug message from ahmedlogger";
    }
}
void runLogiciellogger(){
    
    const std::string directory = "../logs";
    const std::string filename = "logicielLog"; 
    auto worker2 = g3::LogWorker::createLogWorker();
    auto sinkHandle = worker2->addDefaultLogger(filename,directory);
    
    g3::initializeLogging(worker2.get());
    
     for(int i = 0;i<50;i++){
           LOG(DEBUG) << "This is debug message from ahmedlogger";
    }
}



int main(){
    
    std::thread th1(runAhmedlogger);

    std::thread th2(runLogiciellogger);

    th1.join();
    th2.join();
    
    std::cout <<"Both threads completed"<<std::endl;
    return 0;
}