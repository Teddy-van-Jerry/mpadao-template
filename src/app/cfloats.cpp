// cfloats.cpp: compilation test to check arithmetic type usage in application environments
//
// Copyright (C) 2017-2023 Stillwater Supercomputing, Inc.
//
// This file is part of the mixed-precision iterative refinement project, which is released under an MIT Open Source license.
#include <iostream>
#include <vector>
#include <universal/number/cfloat/cfloat.hpp>

using Half = sw::universal::half;

Half cfloatPolynomial(const std::vector<int>& coef, const Half& x) {
	using namespace sw::universal;
	if (coef.size() < 2) {
		std::cerr << "Coefficient set is too small to represent a polynomial\n";
		return Half(0);
	}

	Half v = coef[0];
	for (size_t i = 1; i < coef.size(); ++i) {
		v += Half(coef[i]) * pow(x, Half(i));
	}
	return v;
}
