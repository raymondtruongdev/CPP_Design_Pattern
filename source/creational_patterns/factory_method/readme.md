# 🧬 Factory Method Design Pattern 

Factory Method is a creational design pattern that provides an interface
for creating objects in a superclass, but allows subclasses to alter the 
type of objects that will be created.

##  Class Diagram

```mermaid
classDiagram
    class Car {
        <<interface>>
        +make_car()
    }

    class SportsCar {
        +make_car()
    }

    class EconomyCar {
        +make_car()
    }

    Car <|.. SportsCar
    Car <|.. EconomyCar

    class CarStore {
        <<abstract>>
        +order_car()
        +create_car()
    }

    class SportsCarStore {
        +create_car()
    }

    class EconomyCarStore {
        +create_car()
    }

    CarStore <|-- SportsCarStore
    CarStore <|-- EconomyCarStore

```
