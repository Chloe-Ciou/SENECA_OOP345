
#ifndef TASK_H
#define TASK_H
#include <deque>
#include "CustomerOrder.h"
#include "Item.h"

class Task: public Item{
    std::deque<CustomerOrder> m_orders;
    Task* m_pNextTask = nullptr;
public:
    Task(){}
    Task(std::string& record);
    Task(const Task&) = delete;
    Task(Task&&) = delete;
    Task& operator=(const Task&) = delete;
    Task& operator=(Task&&) = delete;
    void runProcess(std::ostream& os);
    bool moveTask();
    void setNextTask(Task& task);
    bool getCompleted(CustomerOrder& customerOrder);
    void validate(std::ostream& os);
    Task& operator+=(CustomerOrder&& customerOrder);
    virtual ~Task(){}
};

#endif
