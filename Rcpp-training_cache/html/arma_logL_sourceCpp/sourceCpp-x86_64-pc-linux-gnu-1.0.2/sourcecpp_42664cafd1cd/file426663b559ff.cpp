#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
double arma_logL(arma::mat X, arma::vec y, arma::vec beta) {
  int n = y.n_elem;
  int p = X.n_cols;
  double logL = 0;
  for(int i = 0; i < n; i++) {
      double Xbeta_part = 0;
    for(int j = 0; j < p; j++) {
      Xbeta_part += X(i,j)*beta(j);
    }
    logL += R::dnorm(y[i], Xbeta_part, 1, 1);
  }
  return logL;
}


#include <Rcpp.h>
// arma_logL
double arma_logL(arma::mat X, arma::vec y, arma::vec beta);
RcppExport SEXP sourceCpp_1_arma_logL(SEXP XSEXP, SEXP ySEXP, SEXP betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::vec >::type beta(betaSEXP);
    rcpp_result_gen = Rcpp::wrap(arma_logL(X, y, beta));
    return rcpp_result_gen;
END_RCPP
}
