#include "MagicalContainer.hpp"
#include <algorithm>
#include <stdexcept>
namespace ariel{


    void MagicalContainer::addElement(int element) {
        vec_elemnts.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        if(this->size() == 0) throw runtime_error("The container empty");
      
        vec_elemnts.erase(remove(vec_elemnts.begin(), vec_elemnts.end(), element), vec_elemnts.end());
    }

    vector<int> MagicalContainer::getE()  {
        return vec_elemnts;
    }

    int MagicalContainer::size() const {
            return vec_elemnts.size();
        }
    /// @brief 
    // AscendingIterator
  /// @return 
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container) {
        sortE = container.getE();
        std::sort(sortE.begin(), sortE.end());
    }

    MagicalContainer::AscendingIterator::Iterator MagicalContainer::AscendingIterator::begin() {
        return Iterator(sortE.begin());
    }

    MagicalContainer::AscendingIterator::Iterator MagicalContainer::AscendingIterator::end() {
        return Iterator(sortE.end());
    }

    /// @brief 
        // AscendingIterator::Iterator 
    /// @return 
    int MagicalContainer::AscendingIterator::Iterator::operator*() {
        return *iterate;
    }

    MagicalContainer::AscendingIterator::Iterator& MagicalContainer::AscendingIterator::Iterator::operator++() {
        ++iterate;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::Iterator::operator==(const Iterator& other) const {
        return iterate == other.iterate;
    }

    bool MagicalContainer::AscendingIterator::Iterator::operator!=(const Iterator& other) const {
        return iterate != other.iterate;
    }


    //--------------------- SideCrossIterator ------------------------------------

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container) {
        crossOrderE = container.getE();
      std::sort(crossOrderE.begin(), crossOrderE.end(), [](int a, int b) {
        if (a % 2 == 0 && b % 2 == 0) {
            return a < b;  
        } else if (a % 2 != 0 && b % 2 != 0) {
            return a > b;  
        } else if (a % 2 == 0 && b % 2 != 0) {
            return true;   
        } else {
            return false; 
        }
    });

    }

    MagicalContainer::SideCrossIterator::Iterator MagicalContainer::SideCrossIterator::begin()  {
        return Iterator(crossOrderE.begin());
    }

    MagicalContainer::SideCrossIterator::Iterator MagicalContainer::SideCrossIterator::end()  {
        return Iterator(crossOrderE.end());
    }

    /// @brief
    // SideCrossIterator::Iterator 
    /// @return 

    int MagicalContainer::SideCrossIterator::Iterator::operator*() {
        return *iterateS;
    }

    MagicalContainer::SideCrossIterator::Iterator& MagicalContainer::SideCrossIterator::Iterator::operator++() {
        ++iterateS;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::Iterator::operator==(const Iterator& other) const {
        return iterateS == other.iterateS;
    }

    /// @brief //???/////////////////////////////////?????????????
    /// @param other 
    /// @return 
    bool ariel::MagicalContainer::operator==(const ariel::MagicalContainer &other) const{

        return true;

    }
bool ariel::MagicalContainer::operator!=(const ariel::MagicalContainer &other) const{
    return false;
}
/// @brief //???
    /// @param other 
    /// @return  //???/////////////////////////////////?????????????


    bool MagicalContainer::SideCrossIterator::Iterator::operator!=(const Iterator& other) const {
        return iterateS != other.iterateS;
    }
    MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer& container) : container(container) {
        const std::vector<int>& elements = container.getE();
        for (int num : elements) {
            if (isPrime(num)) {
                primeE.push_back(num);
            }
        }
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number) const {
        if (number < 2) {
            return false;
        }
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    void MagicalContainer::PrimeIterator::sortPrimes() {
        std::sort(primeE.begin(), primeE.end());
    }


    MagicalContainer::PrimeIterator::Iterator MagicalContainer::PrimeIterator::begin()  {
        MagicalContainer::PrimeIterator::sortPrimes();
        return Iterator(primeE.begin());
    }

    MagicalContainer::PrimeIterator::Iterator MagicalContainer::PrimeIterator::end()  {
        return Iterator(primeE.end());
    }

    /// @brief 
    // PrimeIterator::Iterator 
    /// @return 
    int MagicalContainer::PrimeIterator::Iterator::operator*() {
        return *iteratePrime;
    }

    MagicalContainer::PrimeIterator::Iterator& MagicalContainer::PrimeIterator::Iterator::operator++() {
        ++iteratePrime;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::Iterator::operator==(const Iterator& other) const {
        return iteratePrime == other.iteratePrime;
    }

    bool MagicalContainer::PrimeIterator::Iterator::operator!=(const Iterator& other) const {
        return iteratePrime != other.iteratePrime;
    }

}