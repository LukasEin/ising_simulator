# 2D Ising Monte Carlo Simulator

This project contains a python extension written in C++ for the background Monte Carlo simulation in `./mcisingmodule`. The script `ising_simulator.py` starts a window that shows the simulated Ising lattice where one can observe the phase transition by adjusting the temperature of the system with the slider.

## Building the module on Windows with Visual Studio 2022
- Create an empty C++ project and add all the files from `./mcisingmodule`.
- Install the pybind11 library via `pip install pybind11` or `conda install pybind11` if you're using Anaconda.
- Follow the instructions [here](https://learn.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2022) under **Create the core C++ projects point 7.** to adjust the compiler information
- Run `python -m pybind11 --includes` or `py -m pybind11 --includes` to get the additional include files for pybind11 and add them to **C/C++ > General > Additional Include Directories**.
- Now you can build the code to generate the python extension module.

## Installing the extension
To install the extension and use it in your Python files run the command
```
pip install path/to/the/module
```
Even when using Anaconda this only works with the pip command. The path should be to the folder where the `pyproject.toml` and `setup.py` files are. Typically if no change was made to the project path of Visual Studio 2022 it should look like
```
C:\User\source\repos\module_name(\module_name)
```
The last part in brackets appears when not choosing the option **Place solution and project in the same directory**. 

Afterwards it should be possible to use the extension in your Python files.

## Running the simulation

To install all needed packages run 
```
conda env create -f env.yml
conda activate mcising
```
or only
```
conda activate mcising
```
if the environment is already installed.

The main code for the simulation is contained in the `window.py` file. It operates a window with a slider to adjust the phase transition parameter and updates the Ising lattice periodically. 

The `ising_simulator.py` files holds the parameters for the Ising Lattice and runs the window. Two modes of interaction can be chosen:
- -1 results in a ferromagnetic phase transition
- +1 results in an anti-ferromagnetic phase transition
