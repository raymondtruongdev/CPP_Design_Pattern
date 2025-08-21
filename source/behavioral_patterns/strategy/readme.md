# 🧬 Strategy Design Pattern

The Strategy is a behavioral design pattern that allows you to define a set of
algorithms and encapsulate them in independent classes so that they can be used interchangeably.

## Class Diagram

```mermaid
classDiagram
    class PaymentStrategy {
        <<interface>>
        +pay(int amount)*
    }

    class CreditCardPayment {
        -string card_number_
        +CreditCardPayment(string card_number)
        +pay(int amount)
    }

    class PaypalPayment {
        -string email_
        +PaypalPayment(string email)
        +pay(int amount)
    }

    class Item {
        -string item_id_
        -int price_
        +Item(string item_id, int price)
        +get_price() int
        +get_id() string
    }

    class ShoppingCart {
        -vector<unique_ptr<Item>> items
        +add_item(unique_ptr<Item> item)
        +remove_item(string id)
        +calculate_total() int
        +checkout(PaymentStrategy& payment_strategy)
    }

    PaymentStrategy <|.. CreditCardPayment
    PaymentStrategy <|.. PaypalPayment
    ShoppingCart --> Item : "use (items)"
    ShoppingCart --> PaymentStrategy: "uses (checkout)"

```