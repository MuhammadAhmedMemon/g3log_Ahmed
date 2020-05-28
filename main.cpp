#include <iostream>
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"

void runG3logger(){
    const std::string directory = "../logs";
    const std::string filename = "logfile";

    auto worker = g3::LogWorker::createLogWorker();
    auto sinkHandle = worker->addDefaultLogger(filename,directory);

    g3::initializeLogging(worker.get());
    LOG(DEBUG) << "This is debug message";
}


int main(){
    
    runG3logger();
    return 0;
}