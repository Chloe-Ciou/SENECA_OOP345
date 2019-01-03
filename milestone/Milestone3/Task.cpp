
#include "Task.h"

Task::Task(std::string& record): Item(record){
}

void Task::runProcess(std::ostream& os){
    if(!m_orders.empty() && !m_orders.back().getOrderFillState()){
        if(!(m_orders.back().getItemFillState(this->getName()))){
            m_orders.back().fillItem(*this, os);
        }
    }
}

bool Task::moveTask(){
    if(!m_orders.empty()){
        if(m_orders.back().getItemFillState(getName()) && m_pNextTask){
            *m_pNextTask += std::move(m_orders.back());
            m_orders.pop_back();
        }
        return true;
    }
    return false;
}

void Task::setNextTask(Task& task){
    m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& custmerOrder){
    if(!m_orders.empty() && m_orders.back().getOrderFillState()){
        custmerOrder = std::move(m_orders.back());
        m_orders.pop_back();
        return true;
    }
    return false;
}

void Task::validate(std::ostream& os){
    os << getName() << " --> ";
    os << (m_pNextTask? m_pNextTask->getName(): "END OF LINE");
    os << std::endl;
}

Task& Task::operator+=(CustomerOrder&& customerOrder){
    m_orders.push_front(std::move(customerOrder));
    
    return *this;
}
