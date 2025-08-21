# 🧬  State Design Pattern
The State pattern is a behavioral design pattern that implements a state machine in an object-oriented way.
With the State pattern, each state is implemented as a derived class of a state interface, and state transitions are handled by invoking methods defined by the interface.

##  Class Diagram

```mermaid
classDiagram
    class CoffeeMachine {
        - unique_ptr~State~ state
        + CoffeeMachine(unique_ptr~State~ initialState)
        + setState(unique_ptr~State~ newState)
        + next()
        + printStatus()
    }

    class State {
        <<interface>>
        + next(CoffeeMachine& context)
        + printStatus() const
    }

    class IdleState {
        + next(CoffeeMachine& context)
        + printStatus() const
    }

    class HasCoinState {
        + next(CoffeeMachine& context)
        + printStatus() const
    }

    class SelectTypeState {
        + next(CoffeeMachine& context)
        + printStatus() const
    }

    class FinishState {
        + next(CoffeeMachine& context)
        + printStatus() const
    }

    CoffeeMachine --> State : has a
    State <|.. IdleState
    State <|.. HasCoinState
    State <|.. SelectTypeState
    State <|.. FinishState


```