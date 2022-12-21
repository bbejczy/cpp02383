#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(int avgNumber) {
    this->avgNumber = avgNumber;
    this->writeCountNumber = 0;
};


// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v) {
    this->data.push_back(v);
    this->writeCountNumber++;

    if (this->writeCountNumber > this->avgNumber) {
        this->data.erase(this->data.begin());
    }
};

unsigned int SensorBuffer::writeCount() {
    return this->writeCountNumber;
};

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read() {
    if (this->writeCountNumber == 0) {
        return 0;
    }else{
        return this->data.back();
    }
};

// Task 4(d).  Write a working implementation of readAvg()

double SensorBuffer::readAvg() {
    if (this->writeCountNumber == 0) {
        return 0;
    }else{
        double sum = 0;
        for (int i = 0; i < this->data.size(); i++) {
            sum += this->data[i];
        }
        return sum / this->data.size();
    }
};

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
