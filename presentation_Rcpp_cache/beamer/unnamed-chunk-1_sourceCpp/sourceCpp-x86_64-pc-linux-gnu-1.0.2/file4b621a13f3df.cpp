#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
arma::mat mat_select_lines(arma::mat& X, arma::uvec& rowId) {
  int nrows = rowId.n_elem;
  int ncols = X.n_cols;
  arma::mat R(nrows, ncols);
  for(int i = 0; i < nrows; i++) {
    for(int j = 0; j < ncols; j++) {
      R(i, j) = X(rowId(i), j);
    }
  }
  return R;
}
