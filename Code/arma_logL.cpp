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