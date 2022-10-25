#include "module.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;

void run_mc_sweeps(IsingLattice& l, const IsingLattice::value_type& T, const IsingLattice::value_type& J, const unsigned int& num_sweeps) {
	for (unsigned int i = 0; i < num_sweeps; i++) {
		l.sweep(T, J);
	}
}

PYBIND11_MODULE(mcising, m) {
	m.doc() = "Run a Monte Carlo Simulation of a 2D Ising Lattice.";

	m.def("run_sweeps", &run_mc_sweeps, "Runs a number of Monte Carlo sweeps over a chosen lattice",
		py::arg("lattice"), py::arg("temperature"), py::arg("interaction"), py::arg("num_sweeps"));

	py::class_<IsingLattice>(m, "IsingLattice", py::buffer_protocol())
		.def_buffer([](IsingLattice& m) -> py::buffer_info {
			return py::buffer_info(
				m.data(),
				sizeof(IsingLattice::value_type),
				py::format_descriptor<IsingLattice::value_type>::format(),
				2,
				{ m.rows(), m.cols() },
				{ sizeof(IsingLattice::value_type) * m.cols(),
				  sizeof(IsingLattice::value_type) }
			);
		})
		.def(py::init<const size_t, const size_t>(), py::arg("xsize"), py::arg("ysize"))
		.def("show", &IsingLattice::show)
		.def("sweep", &IsingLattice::sweep, py::arg("temperature"), py::arg("interaction"));
}