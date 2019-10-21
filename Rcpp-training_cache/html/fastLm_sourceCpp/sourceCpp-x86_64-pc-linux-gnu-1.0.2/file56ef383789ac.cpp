#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
Rcpp::List arma_fastLm(const arma::mat& X, const arma::colvec& y) {
    int n = X.n_rows;
    int p = X.n_cols;
        
    arma::colvec coef = arma::inv(X.t()*X)*X.t()*y;    // fit model y ~ X
    arma::colvec res  = y - X*coef;           // residuals
    // std.errors of coefficients
    double s2 = arma::sum(res.t()*res)/(n-p);
    arma::colvec std_err = arma::sqrt(s2*arma::diagvec(arma::inv(X.t()*X)));
    return Rcpp::List::create(Rcpp::Named("coefficients") = coef,
                        Rcpp::Named("stderr") = std_err,
                        Rcpp::Named("residuals")  = res,
                        Rcpp::Named("sigma2")  = s2,
                        Rcpp::Named("df.residual")  = n - p);
}
