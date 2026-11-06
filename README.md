# 🎮 Treasure Hunt Game (C++ OOP Practice)

A simple **Object-Oriented Programming (OOP)** project in C++ that simulates a treasure hunt game.  
The game generates a board filled with random treasures and initializes players who can collect treasures into their bags.

---

## 📂 Project Structure
- **Treasure struct** → Represents a treasure with a `value` and `description`.
- **Player class** → Represents a player with:
  - A dynamic bag (`Treasure**`)
  - Bag capacity
  - Total points
  - Name
- **TreasureHunt class** → Represents the game board and players:
  - Dynamic 2D board (`Treasure***`)
  - Rows × Columns of treasures
  - Dynamic array of players
  - Methods to print the board

---

## ⚙️ Features
- Random treasure generation:
  - Each treasure has a random value (1–100).
  - Random description chosen from: `Gold coin`, `Diamond`, `Ruby`, `Silver`, `Emerald`.
- Dynamic memory allocation for:
  - Board (rows × cols)
  - Players (with bag capacity)
- Simple board printing function to visualize treasures.

---

## 🚀 How to Compile and Run

### Using g++ (Linux/Mac/WSL)
```bash
g++ game.cpp -o treasurehunt
./treasurehunt
