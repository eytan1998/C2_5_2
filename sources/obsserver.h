
#ifndef C2_5_2_OBSSERVER_H
#define C2_5_2_OBSSERVER_H

#include <vector>
#include <algorithm>
#include <vector>

// Observer class
class Observer {
public:
    virtual void update(bool isDelete, bool isPrime, int index) = 0;
};

class Subject {
    std::vector<Observer *> observers;
public:
    void addObserver(Observer *observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) {
        // Find and remove the observer from the vector
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyInsert(Node & node) {
        for (Observer *observer: observers) {
            observer->update(false, node.isPrime,node.value);
        }
    }
    void notifyDelete(Node & node) {
        for (Observer *observer: observers) {
            observer->update(true, node.isPrime,node.value);
        }
    }


};


#endif //C2_5_2_OBSSERVER_H
