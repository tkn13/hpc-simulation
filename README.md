# HPC POWER COMSUMTION SIMULATOR

This project utilizes [SimGrid](https://simgrid.org/ "SimGrid") to simulate power consumption on a High-Performance Computing (HPC) Beowulf cluster system.

It is part of a special problem for my graduate project in Computer Science at King Mongkut's Institute of Technology Ladkrabang (KMITL).

------------

## Installation
### Prerequisites
- C++ compiler (eg. [g++](https://gcc.gnu.org/ "g++"))
- [SimGrid](https://simgrid.org/ "SimGrid") installed
- [CMake](https://cmake.org/ "CMake") for build the project

#### Clone the Repository
```bash
git clone https://github.com/tkn13/hpc-simulation
cd hpc-simulation
```
#### Build the Simulator
```bash
mkdir build
cd build
cmake ..
make
```

## Usage
```bash
./hpc_power_simulator ../platfrom.xml
```
