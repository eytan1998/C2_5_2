#include "MagicalContainer.hpp"


Node::Node(int value) : value(value), isPrime(MagicalContainer::isPrime(value)) {}

/*
 * =============================================
 *              MagicalContainer
 * =============================================
 */
MagicalContainer::MagicalContainer() = default;

MagicalContainer::MagicalContainer(const MagicalContainer &other) = default;

MagicalContainer::~MagicalContainer() = default;

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

int MagicalContainer::operator[](const size_t index) {
    if (index >= elements.size()) throw std::runtime_error("[]. Out of bound.");
    return elements.at((size_t) index).value;
}

//add on O(n)
void MagicalContainer::addElement(int value) {

    // Element already exists, do not add
    auto it = find_if(elements.begin(), elements.end(), [value](const Node &node) {
        return node.value == value;
    });
    if (it != elements.end()) {
        return;
    }
    //make newNode and sort as insert
    Node newNode(value); //isPrime is auto

    auto itr = std::lower_bound(elements.begin(), elements.end(), value,
                                [](const Node &node, int targetValue) {
                                    return node.value < targetValue;
                                });
    elements.insert(itr, newNode);

    //update the list of primes, O(n)
    pointers.clear();
    for (Node &node: elements) {
        // Check if the Node is prime
        if (node.isPrime) {
            // Add the address of the value to the pointers vector
            pointers.push_back(&(node.value));
        }
    }
}


void MagicalContainer::removeElement(int value) {
    //find if match value
    auto it = find_if(elements.begin(), elements.end(), [value](const Node &node) {
        return node.value == value;
    });
    //throw if not exist
    if (it == elements.end()) throw std::runtime_error("removeElement. not an element.");

    elements.erase(it);
    //update the list of primes, O(n)
    pointers.clear();
    for (Node &node: elements) {
        // Check if the Node is prime
        if (node.isPrime) {
            // Add the address of the value to the pointers vector
            pointers.push_back(&(node.value));
        }
    }


}

size_t MagicalContainer::Psize() const {
    return pointers.size();
}

size_t MagicalContainer::size() const {
    return elements.size();
}

bool MagicalContainer::isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}



