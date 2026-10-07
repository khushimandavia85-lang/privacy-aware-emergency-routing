# Algorithms Used

## 1. Priority Queue

The emergency response system uses a priority queue to determine
which emergency should be processed first.

Priority is based mainly on emergency severity.

If two emergencies have the same severity, waiting time is considered.

### Example

| Emergency | Severity | Waiting Time |
|-----------|----------|--------------|
| E101 | 5 | 10 min |
| E102 | 3 | 15 min |
| E103 | 5 | 5 min |

Processing order:

E101 → E103 → E102

---

## 2. Dijkstra's Algorithm

Dijkstra's algorithm is used to find the shortest path between
the ambulance base and an emergency location.

The road network is represented as a weighted graph.

Each edge represents a road and its weight represents distance.

Example:

Base → A = 4 km

Base → B = 2 km

B → C = 3 km

The algorithm determines the minimum-distance route.

---

## Current Prototype

The current 40% prototype implements:

- Emergency registration
- Priority-based processing
- Graph representation
- Shortest-path calculation
- Basic frontend visualization