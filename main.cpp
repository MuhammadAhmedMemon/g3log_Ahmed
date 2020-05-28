//2workers
#include <iostream>
#include <thread>
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"
#include <chrono>

auto start = std::chrono::high_resolution_clock::now(); 

void runAhmedlogger(int n){

    const std::string directory = "../logs";
    const std::string filename = "AhmedLog"; 
    auto worker = g3::LogWorker::createLogWorker();
    auto sinkHandle = worker->addDefaultLogger(filename,directory);
    
    g3::initializeLogging(worker.get());
    
     for(int i = 0;i<n;i++){
           LOG(DEBUG) << "This is debug message from ahmedlogger";
    }
}




int main(){
    
    std::thread th1(runAhmedlogger,50);

    std::thread th2(runAhmedlogger,50);

    th1.join();
    th2.join();
    
    auto stop =  std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout <<"Total Execution Time Asynchronus:" <<duration.count() <<std::endl;

    std::cout <<"Both threads completed"<<std::endl;
    return 0;
}