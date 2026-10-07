# Data Structures Used

## Emergency Array

An array stores registered emergency records.

Each emergency contains:

- Emergency ID
- Severity
- Location
- Waiting time
- Anonymous patient token
- Status

---

## Priority Queue

The priority queue stores waiting emergencies.

Higher-severity emergencies receive higher priority.

Waiting time is used as a secondary priority.

---

## Graph

The road network is represented using a weighted adjacency matrix.

Vertices represent:

- Ambulance Base
- Emergency Locations
- Hospital

Edges represent roads.

Edge weights represent distances.

---

## Future Data Structures

The following components are planned for later stages:

- Advanced graph structures
- Multiple ambulance management
- Dynamic routing structures
- Hospital capacity management
- Emergency history