# 🧬 Observer Design Pattern
Observer is a behavioral design pattern that lets you define 
a subscription mechanism to notify multiple objects about any
events that happen to the object they’re observing.

##  Example

```mermaid
graph LR
    A1(JobSeeker1) -. attach .-> B((Employment
                                    Agency))
    B -- Notify jobPost --> A1
    
    A2(JobSeeker2) -. attach .-> B
    B -- Notify jobPost --> A2
    
    A3(JobSeeker3) -. attach .-> B
    B -- Notify jobPost --> A3

```

##  Diagram

```mermaid

classDiagram
    class JobObserver {
    <<interface>>
    +onJobPosted(job: string)
    }

    class EmploymentAgency {
        -observers: vector<JobObserver*>
        -notify(job: string)
        +attach(observer: JobObserver*)
        +detach(observer: JobObserver*)
        +addJob(job: string)
    }

    class JobSeeker {
        -name: string
        +JobSeeker(name: string)
        +onJobPosted(job: string)
    }

    JobObserver <|-- JobSeeker

```

