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


#include <Rcpp.h>
// mat_select_lines
arma::mat mat_select_lines(arma::mat& X, arma::uvec& rowId);
RcppExport SEXP sourceCpp_5_mat_select_lines(SEXP XSEXP, SEXP rowIdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::uvec& >::type rowId(rowIdSEXP);
    rcpp_result_gen = Rcpp::wrap(mat_select_lines(X, rowId));
    return rcpp_result_gen;
END_RCPP
}
