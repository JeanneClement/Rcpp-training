#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
double arma_logL(arma::mat X, arma::vec y, arma::vec beta, double sigma2) {
  
  int n = y.n_elem; // number of observations
  int p = beta.n_elem; // number of regression parameters 
  
  // Initialize the logLikelihood to zero
  double logL = 0;
  // Loop on observations
  for(int i = 0; i < n; i++) {
      // Reset to zero X.row(i)*beta
      double Xbeta_part = 0;
    // Loop on parameters 
    for(int j = 0; j < p; j++) {
      Xbeta_part += X(i,j)*beta(j);
    }
    // log(p(y_i | beta, sigma²))
    logL += R::dnorm(y[i], Xbeta_part, std::sqrt(sigma2), 1);
  }
  return logL;
}
