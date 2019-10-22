#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]

arma::mat arma_distmat(const arma::mat& x) { 
  
  int np = x.n_rows;
  arma::mat distmat; distmat.zeros(np, np);
  
  for (int i = 0; i < np; i++) {
    arma::vec p0 = x.row(i).t();
    for (int j = i + 1; j < np; j++) {
      arma::vec p1 = x.row(j).t();
      arma::vec diff = p0 - p1;
      double squared_diff = as_scalar(diff.t() * diff);
      distmat(j, i) = distmat(i, j) = sqrt(squared_diff);
    }
  }
  
  return distmat;
}