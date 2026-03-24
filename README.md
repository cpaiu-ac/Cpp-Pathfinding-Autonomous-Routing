# Cpp-Pathfinding-Autonomous-Routing
# C++ Pathfinding Algorithms for Autonomous Routing

## 📌 About the Project
This repository contains raw C++ implementations of two fundamental pathfinding algorithms: Dijkstra and A* (A-Star). In the context of automotive software and autonomous driving, these algorithms are the backbone of GPS navigation, route optimization, and ADAS (Advanced Driver Assistance Systems) trajectory planning.

The project demonstrates a solid understanding of graph theory, matrix representation, and heuristic optimization.

## ⚙️ Core Features
* **Dijkstra's Algorithm (`dijkstra.cpp`):** * Computes the absolute shortest path from a source node to all other nodes in a weighted graph.
  * Reconstructs and prints the exact optimal path sequence and total travel cost.
* **A* Search Algorithm (`a_star.cpp`):** * Implements an optimized pathfinding approach using heuristics (`f(n) = g(n) + h(n)`).
  * Evaluates open and closed sets to find the most efficient route.
  * Features a real-world simulation mapping routes between major Romanian cities (e.g., Bucuresti -> Sibiu -> Oradea) using predefined distance weights and heuristic estimates.

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Concepts:** Graph Theory, Adjacency Matrices, Heuristic Functions, Optimization Algorithms, Route Planning.

## 📁 Repository Structure
* `dijkstra.cpp` - Implementation of the standard shortest-path algorithm.
* `a_star.cpp` - Implementation of the heuristic-based A* algorithm applied to a city-routing scenario.
