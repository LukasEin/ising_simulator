#include "lattice.h"
#include <random>
#include <iostream>
#include <cmath>

IsingLattice::IsingLattice(const size_t& x_dim_, const size_t& y_dim_) : x_dim(x_dim_), y_dim(y_dim_) {
	this->lattice.resize(this->x_dim);

	for (auto& x : this->lattice) {
		x.resize(this->y_dim);
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	for (auto& x : this->lattice) {
		for (auto& y : x) {
			if (dist(gen) < 0.5) { y = -1.0; }
			else { y = 1.0; }
		}
	}
}

void IsingLattice::sweep(const IsingLattice::value_type& T, const IsingLattice::value_type& J) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	IsingLattice::value_type temp = 0.0;

	for (size_t i = 0; i < this->x_dim; i++) {
		for (size_t j = 0; j < this->y_dim; j++) {
			temp = this->lattice[i][(j - 1) % this->y_dim] +
				this->lattice[i][(j + 1) % this->y_dim] +
				this->lattice[(i - 1) % this->x_dim][j] +
				this->lattice[(i + 1) % this->x_dim][j];
			temp *= 2 * this->lattice[i][j] * J;
			
			temp = exp(temp / T);
			temp = temp / (temp + 1);

			if (dist(gen) < temp) { lattice[i][j] *= -1.0; }
		}
	}
}

IsingLattice::value_type* IsingLattice::data() {
	IsingLattice::value_type* temp = new IsingLattice::value_type[this->x_dim * this->y_dim];
	for (size_t i = 0; i < this->x_dim; i++) {
		for (size_t j = 0; j < this->y_dim; j++) {
			temp[this->y_dim*i + j] = this->lattice[i][j];
		}
	}

	return temp;
}

void IsingLattice::show() {
	for (int i = 0; i < y_dim; i++) {
		std::cout << "-";
	}
	std::cout << "\n";
	for (auto& x : this->lattice) {
		for (auto& y : x) {
			if (y < 0) { std::cout << "0"; }
			else { std::cout << "1"; }
		}
		std::cout << "\n";
	}
	for (int i = 0; i < y_dim; i++) {
		std::cout << "-";
	}
	std::cout << "\n";
}