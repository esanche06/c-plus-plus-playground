#include <iostream>

using namespace std;

class Animal {
public:
  virtual void action() {
    cout << "The animal does something.\n";
  }
};

class Fish: public Animal {
public:
  void action() {
    cout << "Fishes swim.\n";
  }
};

class Bird: public Animal {
public:
  void action() {
    cout << "Birds fly.\n";
  }
};

void doAction(Animal *animal) {
  animal->action();
}

int main() {
  Animal *animalPtr;
  Animal newAnimal;
  Fish newFish;
  Bird newBird;

  animalPtr = &newAnimal;
  doAction(animalPtr);
  newAnimal.action();

  animalPtr = &newFish;
  doAction(animalPtr);
  newFish.action();

  animalPtr = &newBird;
  doAction(animalPtr);
  newBird.action();

  return 0;
}