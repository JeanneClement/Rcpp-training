#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
Rcpp::List fastLm(const arma::mat& X, const arma::colvec& y) {
    int n = X.n_rows, k = X.n_cols;
        
    arma::colvec coef = arma::solve(X, y);    // fit model y ~ X
    arma::colvec res  = y - X*coef;           // residuals
    // std.errors of coefficients
    double s2 = std::inner_product(res.begin(), 
                                   res.end(), 
                                   res.begin(), 0.0)/(n - k);
                                                        
    arma::colvec std_err = arma::sqrt(s2 * 
      arma::diagvec(arma::pinv(arma::trans(X)*X)));
    return Rcpp::List::create(Rcpp::Named("coefficients") = coef,
                        Rcpp::Named("stderr")       = std_err,
                        Rcpp::Named("df.residual")  = n - k);
}


#include <Rcpp.h>
// fastLm
Rcpp::List fastLm(const arma::mat& X, const arma::colvec& y);
RcppExport SEXP sourceCpp_1_fastLm(SEXP XSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(fastLm(X, y));
    return rcpp_result_gen;
END_RCPP
}
