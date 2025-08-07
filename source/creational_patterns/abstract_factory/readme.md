# 🧬 Abstract Factory Design Pattern
The Abstract Factory design pattern is a creational design pattern that 
provides an interface for creating families of related or dependent objects
without specifying their concrete classes. It is often referred to as a 
"factory of factories" because it provides a way to encapsulate a group of 
individual factories that share a common theme.

##  Class Diagram

```mermaid
classDiagram
    %% Abstract Product Interfaces
    class Chair {
        <<interface>>
        +make_chair()
    }

    class Shipment {
        <<interface>>
        +ship()
    }

    %% Concrete Chairs
    class HighEndChair {
        +make_chair()
    }

    class NormalChair {
        +make_chair()
    }

    %% Concrete Shipments
    class FastShipment {
        +ship()
    }

    class NormalShipment {
        +ship()
    }

    %% Abstract Factory
    class ChairFactory {
        <<interface>>
        +create_chair()
        +create_shipment()
    }

    %% Concrete Factories
    class HighEndChairFactory {
        +create_chair()
        +create_shipment()
    }

    class NormalChairFactory {
        +create_chair()
        +create_shipment()
    }

    %% Relationships

    Shipment <|.. NormalShipment
    Shipment <|.. FastShipment
    
    ChairFactory <|.. HighEndChairFactory
    ChairFactory <|.. NormalChairFactory

    HighEndChairFactory --> HighEndChair : creates
    HighEndChairFactory --> FastShipment : creates

    NormalChairFactory --> NormalChair : creates
    NormalChairFactory --> NormalShipment : creates

    Chair <|.. NormalChair
    Chair <|.. HighEndChair



```