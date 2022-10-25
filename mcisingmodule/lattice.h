#pragma once
#include <vector>

class IsingLattice {
public:
	using value_type = double;
	using array_type = std::vector<std::vector<value_type>>;

	IsingLattice(const size_t&, const size_t&);

	void show();
	void sweep(const IsingLattice::value_type&, const IsingLattice::value_type&);
	value_type* data();
	const size_t rows() const { return x_dim; }
	const size_t cols() const { return y_dim; }

private:
	array_type lattice;
	const size_t x_dim = 0;
	const size_t y_dim = 0;
};