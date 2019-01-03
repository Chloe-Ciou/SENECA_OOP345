
#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include "Task.h"

class LineManager{
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
    
    //starting point
    static std::string m_startPoint;
    //ending point
    static std::string m_stopPoint;
public:
    LineManager(){}
    LineManager(const std::string& filename, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerOrders);
    bool run(std::ostream& os);
    void displayCompleted(std::ostream& os) const;
    void validateTasks() const;
    virtual ~LineManager(){}
};

#endif
