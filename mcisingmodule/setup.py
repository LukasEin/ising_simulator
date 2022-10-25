from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "mcising",
        sorted(glob("./*.cpp")),
        ),
]

setup(
    name="mcising",
    version="1.0",
    description="C++ extension for Python that runs a Monte Carlo simulation of a 2D Ising lattice.",
    ext_modules=ext_modules,
)