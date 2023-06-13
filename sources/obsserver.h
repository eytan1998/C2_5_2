
#ifndef C2_5_2_OBSSERVER_H
#define C2_5_2_OBSSERVER_H

#include <vector>
#include <algorithm>

// Observer class
class Observer {
public:
    virtual void update(bool isDelete, int index) = 0;
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

    void notifyObservers(bool isDelete, int index) {
        for (Observer *observer: observers) {
            observer->update(isDelete, index);
        }
    }


};


#endif //C2_5_2_OBSSERVER_H
