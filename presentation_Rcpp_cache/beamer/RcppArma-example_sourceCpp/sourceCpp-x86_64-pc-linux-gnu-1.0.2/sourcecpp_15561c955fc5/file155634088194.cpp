#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
arma::mat arma_scale(const arma::mat& X) {
    int n = X.n_rows, k = X.n_cols;
    arma::rowvec col_means = arma::mean(X,0); // means 
    arma::rowvec col_sd  = arma::stddev(X,0); // standard deviations
    arma::mat X_scaled(n,k);
    for (int  p= 0; p < k; p++) {
    X_scaled.col(p) = (X.col(p)-col_means(p))/col_sd(p);
    }
    return X_scaled;
}


#include <Rcpp.h>
// arma_scale
arma::mat arma_scale(const arma::mat& X);
RcppExport SEXP sourceCpp_5_arma_scale(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    rcpp_result_gen = Rcpp::wrap(arma_scale(X));
    return rcpp_result_gen;
END_RCPP
}
