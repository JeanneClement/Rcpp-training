#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat arma_scale(const arma::mat X) {
  
  // Define dimensions of the matrix 
  int n = X.n_rows, k = X.n_cols;
  
  // Initialize the matrix to store results
  arma::mat X_scaled(n,k);
  
  // means 
  arma::rowvec col_means = arma::mean(X,0); 
  // standard deviations
  arma::rowvec col_sd  = arma::stddev(X,0); 
  
  // Scale and center each column of the matrix 
  for (int  p= 0; p < k; p++) {
    X_scaled.col(p) = (X.col(p)-col_means(p))/col_sd(p);
  }
  
  return X_scaled;
}
