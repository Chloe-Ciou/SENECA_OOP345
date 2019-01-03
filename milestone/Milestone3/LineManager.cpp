
#include <fstream>
#include "Utilities.h"
#include "LineManager.h"

std::string LineManager::m_startPoint = "";
std::string LineManager::m_stopPoint = "";

LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerOrder){
    Utilities utilities;
    std::ifstream file(fileName);
    std::string record;
    if(file){
        while (!file.eof()) {
            bool more = true;
            size_t index = 0u, formerTaskIndex = 0u;
            std::getline(file, record);
            std::string formerTask = utilities.extractToken(record, index, more);
            std::string nextTask = "";
            if(more)
                nextTask = utilities.extractToken(record, index, more);
            
            for(size_t i = 0; i < tasks.size(); ++i){
                if(tasks[i]->getName() == formerTask){
                    formerTaskIndex = i;
                    break;
                }
            }
            if(!nextTask.empty()){
                for(size_t i = 0; i < tasks.size(); ++i){
                    if(tasks[i]->getName() == nextTask){
                        tasks[formerTaskIndex]->setNextTask(*tasks[i]);
                        break;
                    }
                }
            }
        }
    }
    
    for (size_t i = 0; i < customerOrder.size(); i++) {
        ToBeFilled.push_front(std::move(customerOrder[i]));
    }
    for(size_t i = 0; i < tasks.size(); ++i){
        AssemblyLine.push_back(tasks[i]);
    }
    
    //stores the starting point
    m_startPoint = tasks.back()->getName();
    //stores the ending point
    m_stopPoint = tasks[tasks.size() - 2]->getName();
    m_cntCustomerOrder = ToBeFilled.size();
}

bool LineManager::run(std::ostream& os){
    size_t startIndex = 0u, stopIndex = 0u;
    bool startSetUp = false, stopSetUp = false;
    
     //gets starting and ending index
    for(size_t i = 0; i < AssemblyLine.size(); ++i){
        if(AssemblyLine[i]->getName() == m_startPoint){
            startIndex = i;
            startSetUp = true;
        }else if(AssemblyLine[i]->getName() == m_stopPoint){
            stopIndex = i;
            stopSetUp = true;
        }
        //breaks the loop
        if(startSetUp && stopSetUp)
            break;
    }
    
    if(!ToBeFilled.empty()){
        *AssemblyLine[startIndex] += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }
    
    for(auto task: AssemblyLine)
        task->runProcess(os);
    for(auto task: AssemblyLine)
        task->moveTask();

    CustomerOrder temp;
    if(AssemblyLine[stopIndex]->getCompleted(temp)){
        Completed.push_back(std::move(temp));
    }
    return Completed.size() == m_cntCustomerOrder? true: false;
}

void LineManager::displayCompleted(std::ostream& os) const{
    for(size_t i = 0; i < Completed.size(); ++i)
        Completed[i].display(os);
}

void LineManager::validateTasks() const{
    for(auto task: AssemblyLine)
        task->validate(std::cout);
}

