// C++ program to demonstrate               
// the use of virtual functions
   
// object oriented programming is a programming paradigm there are four main principles of oops
// 1. Encapsulation
// 2. Inheritance
// 3. Polymorphism
// 4. Abstraction
// Encapsulation: Encapsulation is the bundling of data and methods that operate on that data within a single unit, typically a class. It restricts direct access to some components and can prevent the accidental modification of data. This is achieved through access specifiers like private, protected, and public.
// example:
class Encapsulated {
private:
    int secretData; // Private data member
public:
    void setSecretData(int data) {
        secretData = data; // Setter method to modify private data
    }
    int getSecretData() const {

        return secretData; // Getter method to access private data
    };
};


