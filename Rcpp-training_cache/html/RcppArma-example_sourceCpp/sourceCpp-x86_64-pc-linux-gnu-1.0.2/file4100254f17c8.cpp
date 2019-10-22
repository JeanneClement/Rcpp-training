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
