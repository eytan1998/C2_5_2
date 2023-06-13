#include "MagicalContainer.hpp"


/*
 * =============================================
 *              PrimeIterator
 * =============================================
 */

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(container), currentIndex(0) {
    container.addObserver(this);
}


MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)= default;

MagicalContainer::PrimeIterator::~PrimeIterator(){container.removeObserver(this);}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator
::operator=(const MagicalContainer::PrimeIterator &other) {
    if (this != &other) {
        if (&container != &other.container) throw std::runtime_error("=. different containers");
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator iter(*this);
    iter.currentIndex =0;
    return iter;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(*this);
    iter.currentIndex = container.Psize();
    return iter;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return *(container.pointers.at(currentIndex));
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (currentIndex == container.Psize()) throw runtime_error("cant increment end()");
    currentIndex++;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    if (&container != &other.container)throw std::runtime_error(">. different containers");
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    if (&container != &other.container)throw std::runtime_error(">. different containers");
    return currentIndex > other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    if (&container != &other.container)throw std::runtime_error(">. different containers");
    return currentIndex < other.currentIndex;
}

void MagicalContainer::PrimeIterator::update(bool isDelete,bool isPrime, int value) {
    if(!isPrime) return;
    if(isDelete){
        if(*(*this) > value) {
            currentIndex--;
        }
    }else{
        //insert
        if(*(*this) > value){
            currentIndex++;
        }
    }
}
