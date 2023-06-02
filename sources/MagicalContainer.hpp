#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
using namespace std;

namespace ariel {

    class MagicalContainer {
        private:
            vector<int> vec_elemnts;

        public:
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            vector<int> getE(); 

            class AscendingIterator {
                private:
                    MagicalContainer& container;
                    vector<int> sortE;

                public:
                    AscendingIterator(MagicalContainer& container);

                    class Iterator {
                        private:
                            vector<int>::iterator iterate;

                        public:
                            Iterator(vector<int>::iterator iter) : iterate(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };

            class SideCrossIterator {
                private:
                    const MagicalContainer& container;
                    vector<int> crossOrderE;

                public:
                    SideCrossIterator(MagicalContainer& container);

                    class Iterator {
                        private:
                            vector<int>::iterator iterateS;

                        public:
                            Iterator(vector<int>::iterator iter) : iterateS(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };

            class PrimeIterator {
                private:
                    MagicalContainer& container;
                    vector<int> primeE;

                public:
                    PrimeIterator(MagicalContainer& container);
                    void sortPrimes();
                    bool isPrime(int number) const;
                    
                    class Iterator {
                        private:
                            vector<int>::iterator iteratePrime;

                        public:
                            Iterator(vector<int>::iterator iter) : iteratePrime(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };
            
                 bool operator==(const MagicalContainer& other) const;
                 bool operator!=(const MagicalContainer& other) const;

    };

}

#endif 
