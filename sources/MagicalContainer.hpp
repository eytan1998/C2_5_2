#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <stdexcept>
#include "iostream"
#include <algorithm>
#include <cmath>
#include <vector>

class Node{
public:
    int value;
    bool isPrime;
    explicit Node(int value);
};

#include "obsserver.h"


using namespace std;
namespace ariel{}



class MagicalContainer : public Subject{
private:
    vector<int*> pointers;

public:
    MagicalContainer();

    MagicalContainer(const MagicalContainer& other);

    ~MagicalContainer();

    MagicalContainer& operator=(const MagicalContainer& other);

    int operator[](size_t index);

    void addElement(int element);

    void removeElement(int element);

    size_t size() const;

    size_t Psize() const;//for prime

    static bool isPrime(int num);

/*
 * =============================================
 *              AscendingIterator
 * =============================================
 */
    class AscendingIterator : public Observer{
    private:
        MagicalContainer &container;
        size_t currentIndex;

    public:
        explicit AscendingIterator();

        explicit AscendingIterator(MagicalContainer& container);

        AscendingIterator(const AscendingIterator& other);

        ~AscendingIterator();

        AscendingIterator& operator=(const AscendingIterator& other);

        bool operator==(const AscendingIterator& other) const;

        bool operator!=(const AscendingIterator& other) const;

        bool operator<(const AscendingIterator& other) const;

        bool operator>(const AscendingIterator& other) const;

        int operator*() const;

        AscendingIterator& operator++();

        AscendingIterator begin();

        AscendingIterator end();

        void update(bool isDelete,bool isPrime, int index) override;

    };


/*
 * =============================================
 *              SideCrossIterator
 * =============================================
 */

    class SideCrossIterator :public Observer{
    private:
        MagicalContainer &container;
        bool isLeft;

    public:
        explicit SideCrossIterator();

        explicit SideCrossIterator(MagicalContainer& container);

        SideCrossIterator(const SideCrossIterator& other);

        ~SideCrossIterator();

        SideCrossIterator& operator=(const SideCrossIterator& other);

        int operator*() const;

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const;

        bool operator<(const SideCrossIterator& other) const;

        bool operator>(const SideCrossIterator& other) const;

        SideCrossIterator& operator++();

        SideCrossIterator begin();

        SideCrossIterator end();

        void update(bool isDelete,bool isPrime, int index) override;

        size_t currentIndex;
    };


/*
 * =============================================
 *              PrimeIterator
 * =============================================
 */
    class PrimeIterator : public Observer{
    private:
        MagicalContainer &container;
    public:


        size_t currentIndex;
        explicit PrimeIterator();

        explicit PrimeIterator(MagicalContainer& container);

        PrimeIterator(const PrimeIterator& other);

        ~PrimeIterator();

        PrimeIterator& operator=(const PrimeIterator& other);

        bool operator==(const PrimeIterator& other) const;

        bool operator!=(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator& other) const;

        bool operator>(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator++();

        PrimeIterator begin();

        PrimeIterator end();

        void update(bool isDelete,bool isPrime, int index) override;
    };


    vector<Node> elements;
};

#endif  // MAGICALCONTAINER_H
