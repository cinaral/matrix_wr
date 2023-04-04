#include "matrix_rw.hpp"
#include <limits> /** std::numeric_limits */
#include <string>

using matrix_rw::Real;
using matrix_rw::Row_T;
using matrix_rw::Size;

constexpr Size m_col = 75;
constexpr Size n_row_default = 150;
constexpr Real error_threshold = std::numeric_limits<Real>::epsilon();

//* relative to the directory of the executable
const std::string test_name = "rw_test";
const std::string fpath = "../data/" + test_name + "-";
const std::string ref_fpath = "../../test/ref_data/" + test_name + "-";
const std::string ref_mat_fname = "ref_matrix.csv";
const std::string matrix_fname = "matrix.csv";

int
main()
{
	matrix_rw::Reader<m_col> read;
	matrix_rw::Writer<m_col> write;

	/** read the reference data */
	std::vector<Row_T<m_col>> ref_matrix;
	ref_matrix.reserve(n_row_default);
	read(ref_fpath + ref_mat_fname, ref_matrix); /** read from file */
	const Size n_row = ref_matrix.size();

	/** write the data back */
	write(fpath + matrix_fname, ref_matrix);

	/** read it again */
	std::vector<Row_T<m_col>> matrix;
	matrix.reserve(n_row);
	read(fpath + matrix_fname, matrix);

	/** verify */
	Real max_error = 0;

	for (Size i = 0; i < n_row; ++i) {
		for (Size j = 0; j < m_col; ++j) {
			const Real error = std::abs(matrix[i][j] - ref_matrix[i][j]);

			if (error > max_error) {
				max_error = error;
			}
		}
	}

	if (n_row > 0 && max_error < error_threshold) {
		return 0;
	} else {
		return 1;
	}
}