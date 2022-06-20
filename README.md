# module04
the module 04 in cpp piscine

## in this moduel we goint to learn about 3 topics :
- subtype polymorphisme
- abstract classes
- interfaces

### first what is polymorphism and what is the types of polymorphism ?
#### first thing first , what is the polymorphism means ?
the polymorphism means that an entity (function or object ) can behave diffirently int different scenarios.
#### types of polymorphism :
there are four types of polymorphism :

1. subtype polymorphism (known also as run time polymorphism).
2. parametric polymorphism (known also as parametric polymorphism).
3. ad-hoc polymorphism (known also as overloading).
4. coercion polymorphism (known also as casting).

we are going to talk about each of them separatly.

1. ## subtype polymorphism (run time)
the subtype polymorphism is when you try to derive a class using a pointe referance of the base class,
soo if we call for exemle a mumber function that has been inherited from the base class and overloader in the derived class , the base class inestance of the mumber function will be called, example bellow :

### example :
```

	#include <iostream>

	class Animal {
		public:
			Animal(){};
			~Animal()
			{
				std::cout << "Animal destructor has been called" << std::endl;
			}
			void makeSound() const {
				std::cout << "Animle make a noise" << std::endl;
			}
	};


	class Dog : public Animal{
		public:
			Dog(){};
			~Dog()
			{
				std::cout << "Dog destructor has been called" << std::endl;
			}
			void makeSound() const {
				std::cout << "Dog barks" << std::endl;
			}
	};

	int main() {
		Animal *scrappy = new Dog();
		scrappy->makeSound();

		return (0);
	}
```
the output will be :
 ```

	Animle make a noise
```

soo to salve this problem we use the key [virtual](https://www.educba.com/virtual-keyword-in-c-plus-plus/) before the declaration of the member funtion in the base class, to create a virtual membre function.
also we want to declare the destructor as virtual, becuase if we use a virtual membre function and we didn't use a virtual destructor the derived class constructor will not be called , that will lead to an undifined behavior.

### example :

```

	#include <iostream>

	class Animal {
		public:
			Animal(){};
			virtual ~Animal()
			{
				std::cout << "Animal destructor has been called" << std::endl;
			}
			virtual void makeSound() const {
				std::cout << "Animle make a noise" << std::endl;
			}
	};


	class Dog : public Animal{
		public:
			Dog(){};
			~Dog()
			{
				std::cout << "Dog destructor has been called" << std::endl;
			}
			void makeSound() const {
				std::cout << "Dog barks" << std::endl;
			}
	};

	int main() {
		Animal *scrappy = new Dog();
		scrappy->makeSound();

		delete scrappy;
		return (0);
	}
```
the output will be :
 ```
	Dog barks
	Dog destructor has been called
	Animal destructor has been called
```