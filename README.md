# 🍝 Philosophers

Philosophers is a concurrency project from the 42 curriculum.  
The goal is to solve the classic Dining Philosophers problem using threads and synchronization techniques.

---

## 📖 About the Project

The Dining Philosophers problem is a classic exercise in computer science that demonstrates issues with concurrent programming.

Several philosophers sit around a table. Each philosopher alternates between eating, thinking, and sleeping.  
To eat, a philosopher needs two forks, but each fork is shared with a neighbor.

This project focuses on:

- Multithreading
- Mutexes and synchronization
- Race conditions
- Deadlock prevention
- Timing and precision

---

## ⚙️ Rules

- Each philosopher has a fork on their left and right
- A philosopher must take both forks to eat
- After eating, the philosopher sleeps, then thinks
- The simulation stops if a philosopher dies (does not eat in time) or if all Philosophers have eaten "number_of_times_each_philosopher_must_eat" times 

---

## 🧠 Concepts Learned

- Thread creation and management
- Protecting shared resources with mutexes
- Avoiding deadlocks
- Managing precise timing
- Writing safe concurrent code

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/Mert5558/Philosophers.git
cd Philosophers
```

Compile the project:

```bash
make
```

---

## 🚀 Usage

Run the program with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep (number_of_times_each_philosopher_must_eat)
```

Example:

```bash
./philo 5 800 200 200 (2)
```

---
